//
// Created by 31799 on 15/11/2022.
//
#include "verbFind.h"
#include <stdlib.h>
#include <string.h>
#include "nodeFind.h"


void verbFind(p_node_base base,p_n_node nNode,int val1){

    while (val1 == 1){

        p_node_base n_base = nodeFind(base,rand() % 26);

        for (int i = rand() % (n_base->ref->amount); i < n_base->ref->amount; i++) {

            if (strchr(((n_base->ref->inds)[i])->ind, (nNode->ind->ind)[strlen(nNode->ind->ind)-2])) {
                if(strstr(((n_base->ref->inds)[i])->ind, "PPas")){
                    if(strstr(nNode->ind->ind,"SG")){
                        printf("a %s ",(n_base->ref->refs)[i]->ref);
                    }else if(strstr(nNode->ind->ind,"PL")){
                        printf("ont %s ",(n_base->ref->refs)[i]->ref);
                    }
                }else{
                    printf("%s ", (n_base->ref->refs)[i]->ref);
                }
                val1 = 2;
                break;
            }
        }
    }

}
