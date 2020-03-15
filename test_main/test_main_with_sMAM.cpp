#include "../nnlib2/nnlib2.h"
#include "../nnlib2/nnlib2.h"
#include "../nnlib2/nn.h"
#include "../nnlib2/layer.h"
#include "../nnlib2/connection_set.h"
#include "math.h"

using namespace std;
using namespace nnlib2;

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// sMAM as presented in paper...
// For clarity, it inherits nn not NN_PARENT_CLASS, and was named sMAM
// (simple MAM) not to be confused with the MAM defined in nnlib2
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// this is useless and added just to show how modifying PEs can be done:...

class sMAM_pe : public pe
{
	DATA threshold_function(DATA value) { return sin(value); }
};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// define what sMAM connections (synapses) do:
// note: desired_output is "input" to destination (output) layer

class sMAM_connection : public connection
{
public:
	void encode() { weight() = weight() + source_pe().output * destin_pe().input; }
	void recall() { destin_pe().receive_input_value(weight() * source_pe().output); }
};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// define sMAM components (layers containing aforementioned generic pes and connections_sets of sMAM_connections)

typedef Layer<sMAM_pe> sMAM_layer;
typedef Connection_Set<sMAM_connection> sMAM_connection_set;

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// define the actual sMAM nn class here:
// Dynamic allocation version (using nn topology). This is better-fit for
// implementing more complex, dynamically-defined and/or multi-layer
// (especially feed-FW/BW) NN models. sMAM is not the best example...
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// note: optionally a common error flag is used so runtime errors in individual
// components are reported to the entire neural net.
// also add (register) the components to topology. These will be deleted when NN is deleted.

class sMAM_nn : public nn
{
public:

	sMAM_nn(int input_length, int output_length)
		:nn("MAM Neural Network")
	{
		topology.append(new sMAM_layer("Input layer", input_length, my_error_flag()));
		topology.append(new sMAM_connection_set);
		topology.append(new sMAM_layer("Output layer", output_length, my_error_flag()));

		// setup connections for all layer+connection_set+layer sequences
		// by default fully connects them w/ weight 0 (more options are available)
	
		connect_consequent_layers();
		set_ready();			// indicate NN is ready to encode/decode
	}
};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main() 
	{
	DATA input[4][3] =
	{
  	{  1,  1, -1 }, 		// row 0
  	{ -1, -1, -1 }, 		// row 1
  	{  1, -1,  1 }, 		// row 2
  	{  1,  1,  1 }, 		// row 3
 	};

	DATA output[4][2] =
	{
  	{ 0, 1 }, 		// encode type 1 for row 0
  	{ 1, 0 }, 		// encode type 0 for row 1
  	{ 0, 1 }, 		// encode type 1 for row 2
  	{ 0, 1 }, 		// encode type 1 for row 3
 	};

	// cout << "Hello, this is a test of "<< NN_VERSION << endl;

	sMAM_nn theMAM(3,2);

	// uncomment to show MAM:
	// theMAM.to_stream(TEXTOUT);

	// now encode input-output pairs to MAM...

	for(int i=0;i<4;i++) 
		theMAM.encode_s(input[i],3,output[i],2);

	// uncomment to show MAM:
	// theMAM.to_stream(TEXTOUT);

	// now recall input from MAM...

	double nn_output_buffer[2];

	for(int i=0;i<4;i++)
		{
	    theMAM.recall(input[i],3, nn_output_buffer,2);
		TEXTOUT << "for input #" << i << " sMAM output is decoded to " << which_max(nn_output_buffer,2) << "\n";
		}

	return 0;
	}
