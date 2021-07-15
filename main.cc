#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>

#include "byteVector.hh"
#include "oddEvenGenerator.hh"

#define NUM_RAGNE 256


void printVector(std::vector<int> _vector, int line_break_unit){

    for(int idx=1; idx<= _vector.size(); idx++){
        printf("%3d ", _vector[idx-1]);

        if(idx % line_break_unit ==0)
            printf(" --%2dth  \n", (idx)/line_break_unit);
    }

    printf("\n");

}

int main(int argc, char **argv){

    /*
    byteVector bv;
    std::vector<int> hMatrix;
    
    std::vector<int> best_hMatrix;

    std::vector<adjPair> best_statis_wAdj;
    std::vector<oriPair> best_statis_wOri;


    std::vector<int> adjMatrix = bv.returnAdj(hMatrix);
    std::vector<adjPair> statis_wAdj = bv.inspectAdj(hMatrix);
    std::vector<oriPair> statis_wOri = bv.inspectOri(hMatrix);

    bv.printStatus(statis_wAdj, statis_wOri);
    
    printf("\n-------------- hMatrix --------------\n");
    printVector(hMatrix, 8);
    printf("\n-------------- adjMatrix --------------\n");
    printVector(adjMatrix, 7);    
    */
    

    oddEvenGenerator *oeg = new oddEvenGenerator(0, 8);
    oeg->generateSubspace();

    std::vector<int> odd_space = oeg->returnOddspace();
    std::vector<int> even_space = oeg->returnEvenspace();

    int hMatrix[136] = {0,};

    
}


