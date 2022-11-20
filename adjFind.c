//
// Created by 31799 on 16/11/2022.
//
#include "adjFind.h"
#include <stdlib.h>
#include <string.h>
#include "nodeFind.h"

//en fonction de la forme réflechie du nom, chercher une forme pour adjectif
p_node_base adjFind(p_node_base base,p_n_node nNode,int val2){

    p_node_base n_base;
    while (val2 == 1){ //val2 pour contrôler si on a bien trouvé une forme correspondante dans le noead
        n_base = nodeFind(base,rand() % 26); // trouver un noead dans l'arbre pour verb

        for (int i = (rand() % ((n_base->ref->amount)-1))+1; i < n_base->ref->amount; i++) { //Parcourir toutes les formes

            if (strrchr(((n_base->ref->inds)[i])->ind, (nNode->ind->ind)[strlen(nNode->ind->ind) - 2])) {
                printf("%s ", (n_base->ref->refs)[i]->ref);
                val2 = 2; //après trouver une forme coresspondante dans le noead, sinon on rentre dans la boucle pour trouver un nouveau noead.
                break;
            }
        }
    }
    return n_base;
}