//
// Created by 31799 on 15/11/2022.
//
#include "verbFind.h"
#include <stdlib.h>
#include <string.h>
#include "nodeFind.h"

//en fonction de la forme réflechie du nom, chercher une forme pour verb
p_node_base verbFind(p_node_base base,p_n_node nNode,int val1){

    p_node_base n_base;
    while (val1 == 1){ //val1 pour contrôler si on a bien trouvé une forme correspondante dans le noead

        n_base = nodeFind(base,rand() % 26); // trouver un noead dans l'arbre pour verb

        for (int i = (rand() % ((n_base->ref->amount)-1))+1; i < n_base->ref->amount; i++) { //Parcourir toutes les formes

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
                val1 = 2; //après trouver une forme coresspondante dans le noead, sinon on rentre dans la boucle pour trouver un nouveau noead.
                break;
            }
        }
    }

    return n_base;
}
