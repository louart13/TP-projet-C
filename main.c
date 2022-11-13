#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "importation.h"
#include "dicArbre.h"
#include "wordFind.h"
#define  MAX_LINE 1024


int main(){

    //Obtenir l'heure locale pour changer la facteur aléatoire
    srand((unsigned)time(NULL));
    int seed = rand() % 25;

    t_n_tree v_tree = fileImportation('r');
    t_n_tree n_tree = fileImportation('m');
    t_n_tree adj_tree = fileImportation('j');
    t_n_tree adv_tree = fileImportation('v');

    p_node_base v_base = wordFind(v_tree.root,seed);
    p_node_base n_base = wordFind(n_tree.root,seed);
    p_node_base adj_base = wordFind(adj_tree.root,seed);
    p_node_base adv_base = wordFind(adv_tree.root,seed);


    return 0;
}