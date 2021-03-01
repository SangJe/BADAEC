#include "Johnson_Trotter.hh"

void Johnson_Trotter::runAlgorithm(std::vector<int>& array){
    int k;
    int max=0;
    std::vector<int> directions;

    for(const auto it : array){
        directions.push_back(0);
    }

    int min =100;
    std::vector<int> best_hMatrix;
    std::vector<adjPair> best_statis_wAdj;
    std::vector<oriPair> best_statis_wOri;

    while(checkMobiles(array, directions)){

        k = findLargest(array, directions);

        if(directions[k]==0){
            std::swap(array[k], array[k-1]);
            std::swap(directions[k], directions[k-1]);
            k -= 1;
        }else{
            std::swap(array[k], array[k+1]);
            std::swap(directions[k], directions[k+1]);
            k += 1;
        }

        for(int i=0; i < array.size(); ++i){
            if(array[i] > array[k]){
                if(directions[i]==0){
                    directions[i]=1;
                }else{
                    directions[i]=0;
                }
            }
        }
    }
}

bool Johnson_Trotter::checkMobiles(std::vector<int>& array, const std::vector<int>& directions){

    for(int i=0; i < array.size(); ++i){
        if(isMobile(i, array, directions))
            return true;
    }

    return false;
}

bool Johnson_Trotter::isMobile(int p, std::vector<int>& array, const std::vector<int>& directions){

    // first elemement with left-direction --> cannot move.
    if(p==0 && directions[p]==0){
        return false;
    }
    // last elements with right-direction --> cannot move.
    else if(p==array.size()-1 && directions[p]==1){
        return false;
    }
    else{

        if(directions[p]==0){
            if(array[p] > array[p-1])
                return true;
        } else {
            if(array[p] > array[p+1])
                return true;
        }
    }

    return false;
}

int Johnson_Trotter::findLargest(std::vector<int>& array, const std::vector<int>& directions){
    
    std::vector<int> mobile_numbers;

    for(int i=0; i<array.size(); ++i){
        if(isMobile(i, array, directions)){
            mobile_numbers.push_back(i);
        }
    }

    int Largest = mobile_numbers[0];

    for(int p=1; p < mobile_numbers.size(); ++p){

        if(array[mobile_numbers[p]] > array[Largest])
            Largest = mobile_numbers[p];
    }

    return Largest;
}