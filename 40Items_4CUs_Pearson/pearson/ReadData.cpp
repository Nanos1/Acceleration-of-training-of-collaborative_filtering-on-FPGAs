#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Structs.h"
#include "headers.h"

int fileExists(char* fileName){
	if(access(fileName,F_OK)!=-1){
		return 1;
	}
	else{
		printf("Dataset-File does not exist\n");
		return 0;
	}	
}
// function to find the number of Ratings
int findNumberofEntries(FILE* file){
	char    *line  = NULL;
	size_t  len    = 0;
	ssize_t read;
	int     k      = 0;
	printf("Reading Dataset\n");
	while(1){
		read=getline(&line,&len,file);
		if(read==-1)break;
		else if(line[0]=='#'||line[0]=='\0'||!strcmp(line,"")||!strcmp(line," ")||line[0]=='\n'){
			continue;
		}
		k++;
	}
	printf("Dataset Entries are: %d\n",k);
	free(line);
	return k;
}

void getDataFile(FILE *file, char* delimiter, entryData* D){
	char    *line = NULL;
	size_t  len   = 0;
	ssize_t read;
	int     k     = 0;
	printf("Reading Dataset\n");
	while(1){
                read=getline(&line,&len,file);
                if(read==-1)break;
                else if(line[0]=='#'||line[0]=='\0'||!strcmp(line,"")||!strcmp(line," ")||line[0]=='\n'){
                        continue;
                }
		D[k].rowUser = atoi(strtok(line,delimiter));
		D[k].colItem = atoi(strtok(NULL,delimiter));
		D[k].rating  = atof(strtok(NULL,delimiter));
		k++;
	}
	free(line);
}	
