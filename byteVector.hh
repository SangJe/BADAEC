#ifndef __BYTE_VECTOR_HH__
#define __BYTE_VECTOR_HH__

#include "eccCode.hh"

typedef struct adjPair{
    int first;
    int second;
    int common_val;

    int first_th, first_first, first_seocnd;
    int second_th, second_first, second_second;
}adjPair;

typedef struct oriPair{
    int pPart;
    int adjPart;
    int common_val;

    int first_th, first_first, first_second;
}oriPair;

class byteVector:eccCode
{
private:

public:
    byteVector();

    void gradescent();
    void copyToAdj();
    std::vector<adjPair> inspectAdj(std::vector<int>& _array);
    std::vector<oriPair> inspectOri(std::vector<int>& _array);
    std::vector<int> returnAdj(std::vector<int>& _array);
    
    void printStatus(std::vector<adjPair> statis_wAdj,std::vector<oriPair> statis_wOri);

};

#endif