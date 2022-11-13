#include <stdio.h>
#include "importation.h"
#include "dicArbre.h"
#include "wordFind.h"
#include <time.h>
#include <stdlib.h>
#define  MAX_LINE 1024


int main(){

    //Obtenir l'heure locale pour changer la facteur aléatoire
    srand((unsigned)time(NULL));
    int seed = rand() % 2;

    t_n_tree v_tree = fileImportation('r');

    p_node_base base = wordFind(v_tree.root,seed);
    if(base != NULL){
        printf("%s",((base->ref->refs)[0])->ref);
    }
    return 0;
}