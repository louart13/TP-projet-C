#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "importation.h"
#include "dicArbre.h"
#include "nodeFind.h"
#include "toSentence.h"
#include "verbFind.h"
#include "adjFind.h"
#include "dicNettoyer.h"


#define  MAX_LINE 1024


int main(){

    //Obtenir l'heure locale pour changer la facteur aléatoire
    srand((unsigned)time(NULL));

    //Une valeur entrée pour choisir le modéle de phrase
    int custm_insert;

    //Creation d'arbre
    t_n_tree v_tree = createEmptyTree();
    v_tree = fileImportation('V');    //construction de l'arbre des verbes

    t_n_tree n_tree = createEmptyTree();
    n_tree = fileImportation('N');    //construction de l'arbre des noms

    t_n_tree adj_tree = createEmptyTree();
    adj_tree = fileImportation('A');   //construction de l'arbre des adjectifs

    t_n_tree adv_tree = createEmptyTree();
    adv_tree = fileImportation('A');   //construction de l'arbre des adverbes



    int val1 = 1;
    int val2 = 1;




    while (1){

        //Trouver un nom de manière aléatoire
        p_node_base n_base1 = nodeFind(n_tree.root,(rand() % 26));
        p_node_base n_base2 = nodeFind(n_tree.root,rand() % 10);

        printf("Tapez 1 pour le modèle n°1 : nom – adjectif – verbe – nom \n");
        printf("Tapez 2 pour le modèle n°2 : nom – ‘qui’ – verbe – verbe – nom – adjectif \n");
        printf("Tapez 0 pour quitter\n");
        printf("Choisissez un modèle de phrase: \n");
        scanf("%d",&custm_insert);

        if(custm_insert == 0){
            break;
        }
        else if(custm_insert == 1){

            printf("--> ");
            p_n_node nNode = toSentence1(n_base1); //Trouver la forme réflechie du nom

            p_node_base  adj_base = adjFind(adj_tree.root,nNode,val2); //Trouver un adjectif conjugué de manière aléatoire
            val2 = 1;

            p_node_base verb_base = verbFind(v_tree.root,nNode,val1); //Trouver un verb conjugué de manière aléatoire
            val1 = 1;

            toSentence1(n_base2);

            printf("\n");
            //Imprimer les mots de base
            printf("    (Base: %s %s %s %s) \n\n",(n_base1->ref->refs)[0]->ref,(adj_base->ref->refs)[0]->ref,(verb_base->ref->refs)[0]->ref,(n_base2->ref->refs)[0]->ref);

        }else if(custm_insert == 2){

            printf("--> ");

            p_n_node nNode = toSentence1(n_base1);

            printf("qui ");

            p_node_base verb_base1 = verbFind(v_tree.root,nNode,val1);
            val1 = 1;

            p_node_base verb_base2 = verbFind(v_tree.root,nNode,val1);
            val1 = 1;
            p_n_node nNode1= toSentence1(n_base2);
            p_node_base adj_base = adjFind(adj_tree.root,nNode1,val2);
            val2 = 1;
            printf("\n");

            printf("    (Base: %s qui %s %s %s %s) \n\n",(n_base1->ref->refs)[0]->ref,(verb_base1->ref->refs)[0]->ref,(verb_base2->ref->refs)[0]->ref,(n_base2->ref->refs)[0]->ref,(adj_base->ref->refs)[0]->ref);

        }

    }



    return 0;
}