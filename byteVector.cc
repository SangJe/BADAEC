#include "byteVector.hh"

byteVector::byteVector(){


}

std::vector<int> byteVector::returnAdj(std::vector<int>& _array){

    std::vector<int> adjMatrix;

    for(int idx=1; idx<_array.size(); idx++){
        
        // Don't consider byte-border adjacent error
        if(idx%8 != 0){
            adjMatrix.push_back(_array[idx-1] ^ _array[idx]);
        }
    }

    return adjMatrix;
}

/**
 *  @brief 
 * 
 *  @param _array: to be cheked. 
 *
 *  @return the adjacent matrix of _array.
 * 
 */
std::vector<adjPair> byteVector::inspectAdj(std::vector<int>& _array){

    std::vector<int> adjMatrix = returnAdj(_array);
    std::vector<adjPair> statis_wAdj;

    int idxArr[119] = {0, };
    int count = adjMatrix.size();
    assert(count<=119);

    for(int i = 0; i< count-1; i++)
    {       
        for(int j = i+1; j<count; j++){

            if(idxArr[i]==0 & adjMatrix[i]==adjMatrix[j]){
                adjPair p_adj;
                p_adj.first=i;
                p_adj.second=j;
                p_adj.common_val = adjMatrix[i];

                p_adj.first_th = i/7 + 1;
                p_adj.first_first = (i%7);
                p_adj.first_seocnd = p_adj.first_first + 1;

                p_adj.second_th = j/7 + 1;
                p_adj.second_first = (j%7);
                p_adj.second_second = p_adj.second_first + 1;

                statis_wAdj.push_back(p_adj);
                idxArr[j] = 1;
            }
            
        } 
    }

    return statis_wAdj;
}


std::vector<oriPair> byteVector::inspectOri(std::vector<int>& _array){

    std::vector<int> adjMatrix = returnAdj(_array);
    std::vector<oriPair> statis_wOri;

    int count = adjMatrix.size();
    assert(count <= 119);

    for(int i=0; i < _array.size(); i++){
        for(int j=0; j < count; j++){
            if(_array[i] == adjMatrix[j]){
                oriPair ori_adj;
                ori_adj.pPart = i;
                ori_adj.adjPart = j;
                ori_adj.common_val = _array[i];

                ori_adj.first_th = j/7 + 1;
                ori_adj.first_first = (j%7);
                ori_adj.first_second = ori_adj.first_first + 1;

                statis_wOri.push_back(ori_adj);
            }
        }
    }
    
    return statis_wOri;
}

void byteVector::printStatus(std::vector<adjPair> statis_wAdj,std::vector<oriPair> statis_wOri){
    int cnt=0;
    printf("----------------------------------- self-inspecting in adjMatrix --------------------------------\n");
    for(int i=0; i<statis_wAdj.size(); i++){
        printf("The %dth col(%dth, %d, %d) & %dth col(%d, %d, %d) value is %d\n"
                , statis_wAdj[i].first, statis_wAdj[i].first_th, statis_wAdj[i].first_first, statis_wAdj[i].first_seocnd
                , statis_wAdj[i].second, statis_wAdj[i].second_th, statis_wAdj[i].second_first, statis_wAdj[i].second_second
                , statis_wAdj[i].common_val);
        cnt ++;
    }
    printf("total same column-pair is %d \n\n\n", cnt);

    cnt=0;
    printf("----------------------------------- original hMatrix with adjMatrix ------------------------------\n");
    for(int i=0; i<statis_wOri.size(); i++){
        printf("The hMatrix %dth col(%dth, %d) is same with adj %dth col(%d, %d, %d) value is %d \n"
                , statis_wOri[i].pPart, statis_wOri[i].pPart/8+1, statis_wOri[i].pPart%8
                , statis_wOri[i].adjPart, statis_wOri[i].first_th, statis_wOri[i].first_first, statis_wOri[i].first_second
                , statis_wOri[i].common_val);
        cnt ++;
    }
    printf("total same column-pair is %d \n", cnt);
}