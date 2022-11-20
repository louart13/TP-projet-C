//
// Created by 31799 on 14/11/2022.
//
#include "dicArbre.h"
#ifndef PROJETC_TOSENTENCE_H
#define PROJETC_TOSENTENCE_H
typedef struct n_node{
    p_ref_node ref;
    p_ind_node ind;
}t_n_node,*p_n_node;

p_n_node initNode();
//Trouver une forme réflechie aléatoirement pour un nom
p_n_node toSentence1(p_node_base);
#endif //PROJETC_TOSENTENCE_H
