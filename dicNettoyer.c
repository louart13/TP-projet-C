//
// Created by 31799 on 20/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicNettoyer.h"

#define  MAX_LINE 1024

//Nottoyer d'abord le dictionnaire
//Parce qu'il y a des comme "a,b,c,d,e,f..." qui sont moins intéresstants pour construire une phrase
void dicNettoyer(){

    //Buffer
    char buf[MAX_LINE];
    FILE *fp , *in; // file pointer

    //Ouverture du fichier de lecture
    if((fp = fopen("C:\\Users\\31799\\Desktop\\dictionnaire.txt","r")) == NULL){

        perror("Fail to read");
        exit(1);
    }

    //Ouverture du fichier d'écriture
    if((in = fopen("C:\\Users\\31799\\Desktop\\dic.txt","a")) == NULL){

        perror("Fail to read");
        exit(1);
    }

    char *temp = malloc(strlen(buf)+1);

    while (!feof(fp)){

        memset(buf,0, sizeof (buf));
        fgets(buf,sizeof(buf) - 1, fp);
        strcpy_s(temp,strlen(buf)+1,buf);
        temp = strtok(temp,"\t"); //avoir la forme réflechie de chaque mot

        if(strlen(temp) > 1){ //si sa longeur est supérieure à 1, on le stocke

            fputs(buf,in);
        }
    }


    fclose(fp);
    fclose(in);
}