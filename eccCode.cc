#include "eccCode.hh"

void eccCode::printMatrix(int *matrix, int num_elements, int line_break_unit){

    for(int idx=1; idx<= num_elements; idx++){
        printf("%3d ", matrix[idx-1]);

        if(idx % line_break_unit ==0)
            printf("\n");
    }

    printf("\n");
}

void eccCode::printVector(std::vector<int> _vector, int line_break_unit){

    for(int idx=1; idx<= _vector.size(); idx++){
        printf("%3d ", _vector[idx-1]);

        if(idx % line_break_unit ==0)
            printf("\n");
    }

    printf("\n");

}