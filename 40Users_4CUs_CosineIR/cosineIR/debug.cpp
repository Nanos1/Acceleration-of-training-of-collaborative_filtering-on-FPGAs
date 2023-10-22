#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#include "Structs.h"

//-----Debugging------------------------
/* 
        functions to check the code and debug
*/
//--------------------------------------

int checkdataset(entryData* Du, entryData* Di, int nData){
	int i,k;
	printf("\nChecking Users \n");
	k = 0;
	for(i=0;i<nData;i++){
		if(Du[i].rowUser == k){
			continue;
		}
		else{
			k++;
			if(Du[i].rowUser!=k){
				printf("Dataset Error 'Incompatible User IDs'\n");
				return -1;
			}	
		}
	}
	
	printf("Checking Items\n");
	k = 0;
	for(i=0;i<nData;i++){
		if(Di[i].colItem == k){
			continue;
		}
		else{
			k++;
			if(Di[i].colItem!=k){
                                printf("Dataset Error 'Incompatible Item IDs'\n");
                                return -1;
                        }
		}
	}
	
	printf("\nDataset OK\n");
	return 1;
}

void debug1(entryData* Du, entryData* Di, int nData){
	int i;
	printf("\nUSER|ITEM|RATING\n");
	for(i=0;i<nData;i++){
		printf("%d|%d|%g \n",Du[i].rowUser,Du[i].colItem,Du[i].rating);
	}
	printf("\n");
	
        for(i=0;i<nData;i++){
                printf("%d|%d|%g \n",Di[i].rowUser,Di[i].colItem,Di[i].rating);
        }
    	printf("\n");
	printf("\nTotal data = %d \n",nData);
}

void debug2(int numUsers, int numItems){
	printf("\nTotal Users = %d \n",numUsers);
	printf("\nTotal Items = %d \n",numItems);
}
void debug3(float* data,int loop1, int loop2){
	int i,j;
	printf("\n");
	for(i=0;i<loop1;i++){
		for(j=0;j<loop2;j++){
			printf("|%f|",data[i*loop2+j]);
		}
		printf("\n");
	}
}
void debug4(int* knn,int loop1,int loop2){
	int i,j;
	printf("\n");
	for(i=0;i<loop1;i++){
		for(j=0;j<loop2;j++){
			printf("|%d|",knn[i*loop2 + j]);
		}
		printf("\n");
	}
}
