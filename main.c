#include <stdio.h>
#include "importation.h"
#include "dicArbre.h"
#include "tree.h"
#define  MAX_LINE 1024


int main(){

    t_n_tree v_tree = fileImportation('r');
    t_n_tree n_tree = fileImportation('m');
    t_n_tree adj_tree = fileImportation('j');
    t_n_tree adv_tree = fileImportation('v');


    return 0;
}