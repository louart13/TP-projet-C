//
// Created by 31799 on 11/11/2022.
//
#include <stdio.h>
#define MAX 26
#define IND_MAX 100
#ifndef PROJETC_DICARBRE_H
#define PROJETC_DICARBRE_H

//forme reflechi
typedef struct ref_node{
    const char *ref;
}t_ref_node, *p_ref_node;


//indicateur
typedef struct  ind_node{
    const char *ind;
}t_ind_node, *p_ind_node;

//tableux pour stocker les différents type de  forme reflechi
typedef struct form_node{
    int amount; //nombre de forme reflechi
    p_ref_node refs[IND_MAX]; //stocker toutes les formes reflechies
    p_ind_node inds[IND_MAX]; //tous les indices

}t_form_node, *p_form_node;


//le noead pour l'arbre n-aire
typedef struct node_base {

    //L'initial
    char cte;

    struct node_base* son[MAX]; //26 sous-arbres

    //Pointeur pour les formes reflechis
    p_form_node ref;

}t_node_base, *p_node_base;

//Arbre N-aire
typedef struct n_tree{
    p_node_base root;
}t_n_tree,*p_n_tree;

p_ind_node  createIndNode(char *);
p_ref_node  createRefNode(char *);
p_node_base createBaseNode(char val);
t_n_tree createEmptyTree();
t_n_tree createTree(char val);
void insertNode(p_node_base,char *,char *,char *,int );  // constrction de l'arbre par catégorie


#endif //PROJETC_DICARBRE_H
