//
// Created by 31799 on 10/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "importation.h"

#define  MAX_LINE 1024  // Taille pour le buffer qui stocke l'importation du dictionnaire

//importation du dictionnaire et le rappel de la fonction pour créer l'arbre n-aire
t_n_tree fileImportation(char target){

    //Buffer
    char buf[MAX_LINE];
    FILE *fp; // file pointer


    const char *ref;  //stocker la forme réflechie
    const char *base; //stocker le mot de base
    const char *ind;  //stocker l'indicateur
    t_n_tree tree = createTree('\0');


    //Ouverture du fichier
    if((fp = fopen("C:\\Users\\31799\\Desktop\\dic.txt","r")) == NULL){

        perror("Fail to read");
        exit(1);
    }


    while (!feof(fp)){
        int count = 3;

        memset(buf,0, sizeof (buf));
        fgets(buf,sizeof(buf) - 1, fp); //importer le dictionnaire dans le buffer ligne par ligne
        char *temp = strtok(buf,"\t");

        //separer les 3 mot qui sont dans une même ligne
        while ((temp)){
            if(count == 3){
                ref = temp;
                count--;
            } else if (count == 2){
                base = temp;
                count--;
            }else if(count == 1){
                ind = temp;
            }
            temp = strtok(NULL,"\t");

        }
        // créer l'arbre n-aires par catégorie
        if(ind[0] == target) {

            if(ind[2] == 'j'){
                for (int i = 0; i < MAX; i++) {
                    if (((tree.root)->son)[i] == NULL) {
                        ((tree.root)->son)[i] = createBaseNode('\0');
                        insertNode(((tree.root)->son)[i], ref, base, ind, 0);
                        break;
                    } else if (base[0] == ((tree.root->son)[i])->cte) {
                        insertNode(((tree.root)->son)[i], ref, base, ind, 0);
                        break;
                    }
                }
            }else if(ind[2] == 'v'){
                for (int i = 0; i < MAX; i++) {
                    if (((tree.root)->son)[i] == NULL) {
                        ((tree.root)->son)[i] = createBaseNode('\0');
                        insertNode(((tree.root)->son)[i], ref, base, ind, 0);
                        break;
                    } else if (base[0] == ((tree.root->son)[i])->cte) {
                        insertNode(((tree.root)->son)[i], ref, base, ind, 0);
                        break;
                    }
                }
            }else{
                for (int i = 0; i < MAX; i++) {
                    if (((tree.root)->son)[i] == NULL) {
                        ((tree.root)->son)[i] = createBaseNode('\0');
                        insertNode(((tree.root)->son)[i], ref, base, ind, 0);
                        break;
                    } else if (base[0] == ((tree.root->son)[i])->cte) {
                        insertNode(((tree.root)->son)[i], ref, base, ind, 0);
                        break;
                    }
                }
            }

        }
    }
    fclose(fp);

    return tree;
}