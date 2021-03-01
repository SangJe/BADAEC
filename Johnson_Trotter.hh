/**
 *  Referenced from 
 *       minusi.tistory.com/entry/순열-알고리즘-Permutation-Algorithm
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


#include "byteVector.hh"


class Johnson_Trotter:eccCode
{
private:
    
public:
    Johnson_Trotter(){};

    void runAlgorithm(std::vector<int>& array);

    bool checkMobiles(std::vector<int>& array, const std::vector<int>& directions);
    bool isMobile(int p, std::vector<int>& array, const std::vector<int>& directions);

    int findLargest(std::vector<int>& array, const std::vector<int>& directions);
    
    byteVector bv;
};
