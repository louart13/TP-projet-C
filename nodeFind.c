//
// Created by 31799 on 13/11/2022.
//
#include "nodeFind.h"
#include <stdlib.h>


p_node_base nodeFind (p_node_base base,int seed){

    int s = rand() % 26;

    if(base->ref->amount != 0 && s != 0){

        s--;
    }
    if(base->ref->amount != 0 && s == 0){

        return base;
    }
    p_node_base temp = NULL;
    if(base->son[seed] != NULL){

        temp = nodeFind(base->son[seed],rand() % 26);
        if(temp != NULL){
            return temp;
        }
    }else if(base->son[seed] == NULL){

        temp = nodeFind(base,rand() % 26);
    }

    return temp;
}