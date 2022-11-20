//
// Created by 31799 on 16/11/2022.
//
#include "adjFind.h"
#include <stdlib.h>
#include <string.h>
#include "nodeFind.h"

p_node_base adjFind(p_node_base base,p_n_node nNode,int val2){

    p_node_base n_base;
    while (val2 == 1){
        n_base = nodeFind(base,rand() % 26);

        for (int i = (rand() % ((n_base->ref->amount)-1))+1; i < n_base->ref->amount; i++) {

            if (strrchr(((n_base->ref->inds)[i])->ind, (nNode->ind->ind)[strlen(nNode->ind->ind) - 2])) {
                printf("%s ", (n_base->ref->refs)[i]->ref);
                val2 = 2;
                break;
            }
        }
    }
    return n_base;
}