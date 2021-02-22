#include <stdio.h>
#include <cassert>
#include <vector>

typedef struct adjPair{
    int first;
    int second;
};

class byteVector
{
private:

    std::vector<int> adjMatrix;
    std::vector<adjPair> redunAdj;

    int* pMatrix;

public:
    byteVector(int *pMatrix){ this->pMatrix = pMatrix;}

    void gradescent();
    void copyToAdj();
    void inspectAdj();
    void printAdj();
};
