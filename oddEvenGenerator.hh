#include <math.h>
#include <bitset>
#include <cassert>

#include "eccCode.hh"

class oddEvenGenerator:eccCode
{
private:
    int r;
    int standard_vec, num_vec, num_bits;

    std::vector<int> odd_space;
    std::vector<int> even_space; 

public:
    oddEvenGenerator(int _standard_vec, int num_bits);

    bool isOdd(int stand_vec, int compar_vec);
    void generateSubspace();
    void printSpace();

    std::vector<int> returnOddspace(){ return odd_space; };
    std::vector<int> returnEvenspace(){ return even_space; };
    
};


