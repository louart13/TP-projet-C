//
// Created by 31799 on 13/11/2022.
//
#include "wordFind.h"
#include <stdlib.h>


p_node_base wordFind (p_node_base base,int seed){


    if(base->ref->amount != 0){

        return base;
    }
    p_node_base temp = NULL;
    if(base->son[seed] != NULL){

        temp = wordFind(base->son[seed],rand() % 25);
        if(temp != NULL){
            return temp;
        }
    }else if(base->son[seed] == NULL){

        temp = wordFind(base,rand() % 25);
    }

    return temp;
}