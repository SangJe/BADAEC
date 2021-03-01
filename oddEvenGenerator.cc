#include "oddEvenGenerator.hh"


oddEvenGenerator::oddEvenGenerator(int _standard_vec, int _num_bits){

    assert(_num_bits <=10);

    this->standard_vec = _standard_vec;
    this->num_bits = _num_bits;
    this->num_vec = pow(2, _num_bits)-1;
}


void oddEvenGenerator::generateSubspace(){


    for(int j=1; j<=num_vec; j++){
        if(isOdd(this->standard_vec, j)){
            odd_space.push_back(j);
        }else{
            even_space.push_back(j);
        }
    }

}


bool oddEvenGenerator::isOdd(int stand_vec, int compar_vec){

    std::bitset<10> stand_bit (stand_vec);
    std::bitset<10> compar_bit (compar_vec);

    int result = 0;
    for(int i=0; i<num_bits; i++){
        result ^= (stand_bit[i]*compar_bit[i]);
    }

    if(result==1)
        return true;
    else
        return false;
}

void oddEvenGenerator::printSpace(){

    printf("\n\n-------- The Odd space --------\n");
    printVector(odd_space, 8);
    
    printf("\n\n-------- The Even space --------\n");
    printVector(even_space, 8);
}