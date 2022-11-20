//
// Created by 31799 on 11/11/2022.
//
#include <malloc.h>
#include <string.h>
#include "dicArbre.h"
#define MAX 26
#define IND_MAX 100

//creation de la strcuture pour stocker chaque indicateur
p_ind_node  createIndNode(char *ind){

    p_ind_node ide = malloc(sizeof (t_ind_node));
    ide->ind = malloc(strlen(ind)+1);
    strcpy_s(ide->ind,strlen(ind)+1,ind);

    return ide;
}
//creation de la strcuture pour stocker chaque forme réflechie
p_ref_node  createRefNode(char *ref){

    p_ref_node rde = malloc(sizeof (t_ref_node));
    rde->ref = malloc(strlen(ref)+1);
    strcpy_s(rde->ref,strlen(ref)+1,ref);
    return rde;
}

//creation de la strcuture pour stocker touts les formes réflechies et tous les indicateurs repectivement, et le nombre de forme
p_form_node createFormNode(){
    p_form_node fnd = malloc(sizeof (t_form_node));
    fnd->amount = 0;
    for(int i = 0; i < IND_MAX;i++){
        fnd->inds[i] = NULL;
        fnd->refs[i] = NULL;

    }
    return fnd;
}

//creation de noead pour l'arbre N-aire
p_node_base createBaseNode(char val){

    p_node_base pnb = malloc(sizeof (t_node_base));
    pnb->cte = val;
    for(int i = 0; i <MAX;i++){
        pnb->son[i] = NULL;
    }
    pnb->ref = createFormNode();
    return pnb;

}

//creation d'un arbre vide
t_n_tree createEmptyTree(){
    t_n_tree tree;
    tree.root = NULL;
    return tree;
}

//Initialisation de l'arbre
t_n_tree createTree(char val){

    t_n_tree tree = createEmptyTree();
    tree.root = createBaseNode(val);
    return tree;
}

//insertion des nodes dans l'arbre
void insertNode(p_node_base pnb,char *ref,char *base,char *ind,int position){

    //dans le cas, l'insertion de mot n'est pas arrivée à la fin du mot
    if(position != strlen(base)-1){
        if(pnb->cte == '\0'){  //si le noead est vide
            pnb->cte = base[position];

            for(int i = 0; i < MAX;i++){
                if ((pnb->son)[i] == NULL) { //si le sous-arbre de ce noead est NULL
                    (pnb->son)[i] = createBaseNode('\0');
                    insertNode((pnb->son)[i], ref, base, ind, position + 1); //continuer à inserer le prochain caractère
                    break;
                } else if (base[position + 1] == ((pnb->son)[i])->cte) { //si le caractère existe
                    insertNode((pnb->son)[i], ref, base, ind, position + 1);//entrer dans le prochain noead
                    break;
                }
            }
        }else if(pnb->cte == base[position]){ //si le caractère existe
            for(int i = 0; i < MAX;i++){
                if ((pnb->son)[i] == NULL) { //voir le prochain noead s'il y a le même caractère
                    (pnb->son)[i] = createBaseNode('\0');
                    insertNode((pnb->son)[i], ref, base, ind, position + 1);
                    break;
                } else if (base[position + 1] == ((pnb->son)[i])->cte) {
                    insertNode((pnb->son)[i], ref, base, ind, position + 1);
                    break;
                }
            }
        }
    }else if(position == strlen(base)-1){ //La fin du mot
        if(pnb->cte == '\0'){

            pnb->cte = base[position]; // s'il n'y pas de caractère existant pour le dernier caractère du mot
        }

        if(pnb->ref->amount == 0){  // dans le cas, il n'y a pas encore de forme réflechie stockée

            (pnb->ref->inds)[pnb->ref->amount] = createIndNode("base");
            (pnb->ref->refs)[pnb->ref->amount] = createRefNode(base);
            pnb->ref->amount++;
            (pnb->ref->inds)[pnb->ref->amount] = createIndNode(ind);
            (pnb->ref->refs)[pnb->ref->amount] = createRefNode(ref);
            pnb->ref->amount++;
        }else{

            (pnb->ref->inds)[pnb->ref->amount] = createIndNode(ind);
            (pnb->ref->refs)[pnb->ref->amount] = createRefNode(ref);
            pnb->ref->amount++;
        }

        return;
    }

}


