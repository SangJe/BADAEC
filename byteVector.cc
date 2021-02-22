#include "byteVector.hh"

void byteVector::gradescent(){
    
}

void byteVector::printAdj(){
    int cnt=0;
    for(int i=0; i<redunAdj.size(); i++){
        printf("The %dth column is same with %dth column \n", redunAdj[i].first, redunAdj[i].second);
        cnt ++;
    }
    printf("total same column is %d \n", cnt);
}

void byteVector::inspectAdj(){

    int idxArr[119] = {0, };
    int count = adjMatrix.size();

    for(int i = 0; i< count-1; i++)
    {       
        for(int j = i+1; j<count; j++){

            if(idxArr[i]==0 & adjMatrix[i]==adjMatrix[j]){
                adjPair p_adj;
                p_adj.first=i;
                p_adj.second=j;
                redunAdj.push_back(p_adj);
                idxArr[j] = 1;
            }
            
        } 
    }
}

void byteVector::copyToAdj(){

    for(int idx=0; idx<135; idx++){
        
        // Don't consider byte-border adjacent error
        if(idx%8 != 0 || idx==0){
            adjMatrix.push_back(pMatrix[idx] ^ pMatrix[idx+1]);
        }
    }
}

