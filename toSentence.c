//
// Created by 31799 on 14/11/2022.
//

#include <stdlib.h>
#include <string.h>
#include "toSentence.h"


p_n_node initNode(){

    p_n_node nNode = malloc(sizeof (t_n_node));
    nNode->ref = NULL;
    nNode->ind = NULL;

    return nNode;
}

p_n_node toSentence1(p_node_base n_base1){

    p_n_node nNode = initNode();

    int n_seed1 = (rand() % ((n_base1->ref->amount)-1))+1;
    nNode->ref = (n_base1->ref->refs)[n_seed1];
    nNode->ind = (n_base1->ref->inds)[n_seed1];

    if(strstr(nNode->ind->ind,"Nom:Mas+SG")){
        if((nNode->ref->ref)[0] == 'a' || (nNode->ref->ref)[0] == 'e' || (nNode->ref->ref)[0] == 'h' || (nNode->ref->ref)[0] == 'o' || (nNode->ref->ref)[0] == 'u' || (nNode->ref->ref)[0] == 'i'){
            printf("l'%s ",nNode->ref->ref);
        }else{
            printf("le %s ",nNode->ref->ref);
        }
    }else if (strstr(nNode->ind->ind,"Nom:Fem+SG")){
        if((nNode->ref->ref)[0] == 'a' || (nNode->ref->ref)[0] == 'e' || (nNode->ref->ref)[0] == 'h' || (nNode->ref->ref)[0] == 'o' || (nNode->ref->ref)[0] == 'u' || (nNode->ref->ref)[0] == 'i'){
            printf("l'%s ",nNode->ref->ref);
        }else{
            printf("la %s ",nNode->ref->ref);
        }
    }else{
        printf("les %s ", nNode->ref->ref);
    }
    return nNode;
}
