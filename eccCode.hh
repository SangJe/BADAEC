#ifndef __ECC_CODE_HH__
#define __ECC_CODE_HH__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>



class eccCode
{
private:
    /* data */
public:
    eccCode(){};

    void printMatrix(int *matrix, int num_elements, int line_break_unit);
    void printVector(std::vector<int> _vector, int line_break_unit);
};

#endif 