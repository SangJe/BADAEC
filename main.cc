#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>

#include "byteVector.hh"
#include "oddEvenGenerator.hh"
#include "Johnson_Trotter.hh"

#define NUM_RAGNE 256


                /*   0    1    2    3    4    5    6    7    */
int parity[] = {	241, 167, 211, 215, 117,   5, 249,  87, // 1th
                     97,  29,  45,  83, 195, 223, 105, 217, // 2th
                     11, 171, 101, 219,  77, 161, 185, 147, // 3th
                    109,  73, 133,  17, 137, 227, 205, 113, // 4th
                    213, 193, 225, 153, 159, 251,  67,   7, // 5th
                    253, 197,  71, 145,  61, 189, 179,  85, // 6th
                     23, 207, 157,  25,  69,  21,  93,  47, // 7th
                     49,  59,  15, 121, 163, 139, 155, 111, // 8th
                     35,  79, 231,  37,  51, 103, 151, 125, // 9th
                    173, 247, 245, 143, 181,  63, 199, 135, // 10th
                      9, 187, 221, 255,  57, 115, 123, 141, // 11th
                    129,  27,   1,  19,  33, 191,  55, 243, // 12th
                     89, 177,  95, 229,  81,  31, 237, 127, // 13th
                    183, 107,   3,  91,  53, 235, 119,  75, // 14th
                     43, 201,  41, 233, 175, 131, 165,  65, // 15th
                    149, 203, 169,  99, 239, 209,  39,  13, // 16th
                     12,  13,  30,  39,  54,  66,  12, 166   // 17th  
                    };

int parity2[] = { 241,  167, 211, 215, 117,    5,  249,   87,    
                    97,   29,   45,   83, 195, 223, 105,  217,   
                    11,  171, 101,  219,  77,  161, 185,  147,  
                    109,   73, 133,   17, 137, 227,  205, 113,  
                    213,  193, 225, 153, 159, 251,   67,    7,  
                    253,  197,   71, 145,  61, 189,  179,  85,  
                    23,   207, 157,   25,  69,  21,    93,  47,  
                    49,     59,  15,  121, 163, 139, 155, 111,  
                    35,     79, 231,   37,   51, 103, 151, 125,  
                    173,   247, 245, 143,  181,  63, 199, 135,  
                        255, 57, 115, 187, 178, 254, 8, 134, 
                    129,    27,    1,   19,   33,  191,  55, 243, 
                    89,  177,  95,  229,   81,   31, 237, 127,
                    183,  107,    3,    91,   53, 235, 119,  75, 
                    43,   201,  41,  233,  175, 131, 165,  65,
                    149,  203, 169,   99,  239, 209,     12, 166,
                      0,    0,   0,    0,    0,   0,    0,   0   // idx: 128~135
                    };

int parity3[] = {15, 151, 139, 119, 31, 111, 47, 234,
                57, 99, 135, 91, 89, 175, 229, 243,
                67, 125, 181, 7, 53, 39, 207, 145,
                215, 161, 173, 109, 77, 247, 231, 97,
                23, 227, 159, 21, 223, 25, 63, 115,
                183, 29, 41, 117, 127, 171, 61, 176,
                219, 189, 195, 95, 221, 185, 233, 199,
                169, 237, 51, 123, 157, 167, 107, 211,
                35, 27, 193, 3, 143, 1, 239, 75,
                179, 83, 191, 93, 245, 149, 225, 79,
                177, 255, 241, 87, 205, 203, 147, 37,
                71, 19, 105, 59, 73, 11, 155, 55,
                249, 213, 131, 121, 113, 85, 209, 69,
                81, 103, 13, 9, 33, 129, 153, 65,
                201, 165, 187, 5, 133, 253, 45, 17,
                251, 101, 217, 43, 49, 163, 137, 98,
                34, 210, 98, 136, 206, 254, 110, 196
                };


int remainder2[] = {13, 30, 34, 39, 54, 66, 96, 102, 123, 141, 164, 208, 210, 212, 250};

void printVector(std::vector<int> _vector, int line_break_unit){

    for(int idx=1; idx<= _vector.size(); idx++){
        printf("%3d ", _vector[idx-1]);

        if(idx % line_break_unit ==0)
            printf(" --%2dth  \n", (idx)/line_break_unit);
    }

    printf("\n");

}

int main(int argc, char **argv){

    byteVector bv;
    std::vector<int> hMatrix;
    
    std::vector<int> best_hMatrix;

    std::vector<adjPair> best_statis_wAdj;
    std::vector<oriPair> best_statis_wOri;

    for(int i=0; i<136; i++){
        hMatrix.push_back(parity3[i]);
    }

    std::vector<int> adjMatrix = bv.returnAdj(hMatrix);
    std::vector<adjPair> statis_wAdj = bv.inspectAdj(hMatrix);
    std::vector<oriPair> statis_wOri = bv.inspectOri(hMatrix);

    bv.printStatus(statis_wAdj, statis_wOri);
    
    printf("\n-------------- hMatrix --------------\n");
    printVector(hMatrix, 8);
    printf("\n-------------- adjMatrix --------------\n");
    printVector(adjMatrix, 7);

}



/*
    int min=100;

    for(int a=0; a<15-7; a++){
        printf("curretn status is %d \n", a);
        for(int b=a+1; b<15-6; b++){
            for(int c=b+1; c<15-5; c++){
                for(int d=c+1; d<15-4; d++){
                    for(int e=d+1; e<15-3; e++){
                        for(int f=e+1; f<15-2; f++){
                            for(int g=f+1; g<15-1; g++){
                                for(int h=g+1; h<15; h++){
                                    
                                    hMatrix[128] = remainder2[a];
                                    hMatrix[129] = remainder2[b];
                                    hMatrix[130] = remainder2[c];
                                    hMatrix[131] = remainder2[d];
                                    hMatrix[132] = remainder2[e];
                                    hMatrix[133] = remainder2[f];
                                    hMatrix[134] = remainder2[g];
                                    hMatrix[135] = remainder2[h];

                                    std::vector<adjPair> statis_wAdj = bv.inspectAdj(hMatrix);
                                    std::vector<oriPair> statis_wOri = bv.inspectOri(hMatrix);

                                    if(min > statis_wOri.size() + statis_wAdj.size()){
                                        best_statis_wAdj = statis_wAdj;
                                        best_statis_wOri = statis_wOri;
                                        best_hMatrix = hMatrix;

                                        min = statis_wOri.size() + statis_wAdj.size();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

*/

/*

    if(argc < 2){
        printf("plase type the number of bits \n");
        exit(1);
    }

    int num_bits = atoi(argv[1]);

    oddEvenGenerator *oEV = new oddEvenGenerator(255, num_bits);
    Johnson_Trotter jt;

    oEV->generateSubspace();
    std::vector<int> odd_space = oEV->returnOddspace();
    std::sort(odd_space.begin(), odd_space.end());
    jt.runAlgorithm(odd_space);

*/


