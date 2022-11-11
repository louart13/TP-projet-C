//
// Created by 31799 on 10/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAX_LINE 1024


void fileImportation(){

    //Buffer
    char buf[MAX_LINE];
    FILE *fp; // file pointer


    char ref[MAX_LINE];
    char base[MAX_LINE];
    char ind[MAX_LINE];


    if((fp = fopen("C:\\Users\\31799\\Desktop\\dic.txt","r")) == NULL){

        perror("Fail to read");
        exit(1);
    }


    while (!feof(fp)){


        memset(buf,0, sizeof (buf));
        fgets(buf,sizeof(buf) - 1, fp);
        char *temp = strtok(buf,"\t");

        while(temp){


            printf("%s\n",temp);
            temp = strtok(NULL,"\t");

        }

    }

    fclose(fp);
    return;
}
