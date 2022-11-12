//
// Created by 31799 on 11/11/2022.
//
#include <malloc.h>
#include <string.h>
#include "dicArbre.h"
#define MAX 26
#define IND_MAX 10

p_ind_node  createIndNode(char *ind){

    p_ind_node ide = malloc(sizeof (t_ind_node));
    ide->ind = malloc(sizeof(strlen(ind)));
    strcpy(ide->ind,ind);

    return ide;
}

p_ref_node  createRefNode(char *ref){

    p_ref_node rde = malloc(sizeof (t_ref_node));
    rde->ref = malloc(sizeof(strlen(ref)));
    strcpy(rde->ref,ref);
    return rde;
}

p_form_node createFormNode(){
    p_form_node fnd = malloc(sizeof (t_form_node));
    fnd->amount = 0;
    for(int i = 0; i < IND_MAX;i++){
        fnd->inds[i] = NULL;
        fnd->refs[i] = NULL;

    }
    return fnd;
}

p_node_base createBaseNode(char val){

    p_node_base pnb = malloc(sizeof (t_node_base));
    pnb->cte = val;
    for(int i = 0; i <MAX;i++){
        pnb->son[i] = NULL;
    }
    pnb->ref = createFormNode();
    return pnb;

}

t_n_tree createEmptyTree(){
    t_n_tree tree;
    tree.root = NULL;
    return tree;
}


t_n_tree createTree(char val){

    t_n_tree tree = createEmptyTree();
    tree.root = createBaseNode(val);
    return tree;
}

//insertion des nodes dans l'arbre
void insertNode(p_node_base pnb,char *ref,char *base,char *ind,int position){


    if(position != strlen(base)-1){
        if(pnb->cte == '\0'){
            pnb->cte = base[position];

            for(int i = 0; i < MAX;i++){
                if ((pnb->son)[i] == NULL) {
                    (pnb->son)[i] = createBaseNode('\0');
                    insertNode((pnb->son)[i], ref, base, ind, position + 1);
                    break;
                } else if (base[position + 1] == ((pnb->son)[i])->cte) {
                    insertNode((pnb->son)[i], ref, base, ind, position + 1);
                    break;
                }
            }
        }else if(pnb->cte == base[position]){
            for(int i = 0; i < MAX;i++){
                if ((pnb->son)[i] == NULL) {
                    (pnb->son)[i] = createBaseNode('\0');
                    insertNode((pnb->son)[i], ref, base, ind, position + 1);
                    break;
                } else if (base[position + 1] == ((pnb->son)[i])->cte) {
                    insertNode((pnb->son)[i], ref, base, ind, position + 1);
                    break;
                }
            }
        }
    }else if(position == strlen(base)-1){
        if(pnb->cte == '\0'){

            pnb->cte = base[position];
        }

        (pnb->ref->inds)[pnb->ref->amount] = createIndNode(ind);
        (pnb->ref->refs)[pnb->ref->amount] = createRefNode(ref);
        pnb->ref->amount++;
        return;
    }

}


