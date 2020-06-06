#include "../nnlib2/nn_lvq.h"
#include "../nnlib2/nn_bp.h"
#include "../nnlib2/nnlib2_misc.h"  // for winner_takes_all()
//--------------------------------------------------------------------------------
using namespace nnlib2;
using namespace nnlib2::lvq;            // SOMs and LVQs are here
//--------------------------------------------------------------------------------

int main()
{
    // TEXTOUT << "Hello, this is " << NN_VERSION << "\n";

    // some data
    const int	    som_data_input_size = 8;
    const int		som_data_input_dim  = 3;
    const int		som_data_output_dim = 10;

    DATA inputdata[som_data_input_size][som_data_input_dim];

    inputdata[0][0] = inputdata[0][1] = inputdata[0][2] = -0.5;
    inputdata[1][0] = inputdata[1][1] = inputdata[1][2] =  0.3;
    inputdata[2][0] = inputdata[2][1] = inputdata[2][2] = -0.4;
    inputdata[3][0] = inputdata[3][1] = inputdata[3][2] =  0.3;
    inputdata[4][0] = inputdata[4][1] = inputdata[4][2] = -0.5;
    inputdata[5][0] = inputdata[5][1] = -0.5; inputdata[5][2] = 0.9;   // <--- note
    inputdata[6][0] = inputdata[6][1] = inputdata[6][2] = -0.5;
    inputdata[7][0] = inputdata[7][1] = inputdata[7][2] =  0.3;

    // create_the_som

    const int som_neigborhood_size = 1;
    som_nn som (som_neigborhood_size);
    som.setup(som_data_input_dim, som_data_output_dim);

    // use_the_som, train (unsupervised)

    const int training_iterations = 500;

    for (int i = 1; i < training_iterations; i++)
        for (int r = 0; r < som_data_input_size; r++)
            som.encode_u(inputdata[r], 3, i);

    // ... then recall data

    DATA outputdata[som_data_output_dim];
    for (int r = 0; r < som_data_input_size; r++)
    {
        som.recall(inputdata[r], som_data_input_dim, outputdata, som_data_output_dim);
        
        int c = winner_takes_all(outputdata, som_data_output_dim);
        TEXTOUT << "item " << r << " recalled, labeled " << c << "\n";
    }


    return(1);
}

//--------------------------------------------------------------------------------

