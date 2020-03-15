#include "../nnlib2/nn_bp.h"
#include <iostream>
#include <fstream>

//--------------------------------------------------------------------------------
using namespace nnlib2;
using namespace nnlib2::bp;
//--------------------------------------------------------------------------------

int main()
{
    // TEXTOUT << "Hello, this is " << NN_VERSION << "\n";

    // some data
    const int	    data_input_size = 8;
    const int		data_input_dim  = 4;
    
    DATA inputdata[data_input_size][data_input_dim];

    inputdata[0][0] = inputdata[0][1] = inputdata[0][2] = inputdata[0][3] = -0.5;
    inputdata[1][0] = inputdata[1][1] = inputdata[1][2] = inputdata[1][3] = 0.3;
    inputdata[2][0] = inputdata[2][1] = inputdata[2][2] = inputdata[2][3] = -0.4;
    inputdata[3][0] = inputdata[3][1] = inputdata[3][2] = inputdata[3][3] ==  0.3;
    inputdata[4][0] = inputdata[4][1] = inputdata[4][2] = inputdata[4][3] == -0.5;
    inputdata[5][0] = inputdata[5][1] = -0.5; inputdata[5][2] = inputdata[5][3] = 0.9;   // <--- note
    inputdata[6][0] = inputdata[6][1] = inputdata[6][2] = inputdata[6][3] = -0.5;
    inputdata[7][0] = inputdata[7][1] = inputdata[7][2] = inputdata[7][3] =  0.3;

    // create_the_bp

    bp_nn the_bp;

    std::ifstream infile;
    infile.open("BP_TEST.txt");
    if (!infile) { error(NN_IOFILE_ERR, "File BP_TEST.txt cannot be opened"); return false; }
    the_bp.from_stream(infile);
    infile.close();
    TEXTOUT << "BP NN loaded from file BP_TEST.txt \n";
    
    // use_the_bp

    int data_output_dim = the_bp.output_dimension();
    DATA * outputdata = new DATA[data_output_dim];
    for (int r = 0; r < data_input_size; r++)
    {
        the_bp.recall(inputdata[r], data_input_dim, outputdata, data_output_dim);
        TEXTOUT << "item " << r << " BP recalled : ";
        for (int c = 0; c < data_output_dim; c++)
            TEXTOUT << outputdata[c] << "   ";
        TEXTOUT << "\n";
    }

    delete outputdata;
}

//--------------------------------------------------------------------------------

