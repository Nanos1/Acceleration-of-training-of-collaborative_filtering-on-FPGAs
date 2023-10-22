#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "headers.h"
#include "Structs.h"

int hw_sw_sol(float* similarity_software, float* similarity, int numUsers){
		int flag=1;
		int m=0;
		float sim_sw,sim_hw;
		for(int i=0;i<numUsers;i++){
			for(int j=0;j<numUsers;j++){
				sim_sw=similarity_software[i*numUsers+j];
				sim_hw=similarity[i*numUsers+j];
				sim_sw = sim_sw*10000;
				sim_hw = sim_hw*10000;
				if(abs(sim_hw-sim_sw)>1){
					flag=0;
					m++;
					printf("\n%f",similarity[i*numUsers+j]);
					printf("\n%f",similarity_software[i*numUsers+j]);
					printf("\nUser i: %d",i);
					printf("\nUser j: %d",j);
				}
			}
		}
		printf("\nNumber of mistakes is : %d",m);
return flag;
}

void up_triang(float* similarity, int numUsers){
	for(int i=0;i<numUsers;i++){
		similarity[i*numUsers+i]=1;
		for(int j=i+1;j<numUsers;j++){
			similarity[j*numUsers+i]=similarity[i*numUsers+j];
		}
	}
}

void sim_knn_calc(float* similarity, int* knn, float* sim_knn,int numUsers){              
	for(int i=0;i<numUsers*knn_max;i++){
		sim_knn[i]=0;	
 	}

       	for(int i=0;i<numUsers; i++){
        	for(int j=0;j<knn_max;j++){
                        sim_knn[i*knn_max + j] = similarity[i*numUsers + knn[i*knn_max + j]];
                }
        }
}

void knn_calc(float* similarity, float* similarity1, int* knn,int numUsers){
        float sim;

	for(int i=0;i<numUsers*knn_max;i++){
		knn[i]=0;
	}

        for(int i=0;i<numUsers;i++){
                for(int j=0;j<numUsers;j++){
                        similarity1[i*numUsers + j] = similarity[i*numUsers + j];
                }
        }

	for(int i=0;i<numUsers;i++){
    	        for(int k=0;k<knn_max;k++){
			sim=0;
			for(int j=0;j<numUsers;j++){
				if(similarity1[i*numUsers + j]>sim){
                	                sim = similarity1[i*numUsers + j];
                	                knn[i*knn_max + k] = j;
            	                }
        	        }
                similarity1[i*numUsers + knn[i*knn_max + k]] = 0;
    	        }
	}
}
				
//Used to create the TABLE data
void readtabledata(entryData* Du, float* data, int nData, int numUsers, int numItems){	
	int temprow,tempcol;
	float temp;

	for(int i=0;i<numUsers;i++){
		for(int j=0;j<numItems;j++){
			data[i * numItems + j] = 0;
		}	
	}

	for(int i=0;i<nData;i++){
//		temprow = Du[i].rowUser;
//		tempcol = Du[i].colItem;
	        temprow = Du[i].colItem;
                tempcol = Du[i].rowUser;

		temp = Du[i].rating;
		data[temprow * numItems + tempcol] = temp;
	}
}	
		
//Used for quicksort
int compareUsers(const void* a, const void* b){
	entryData *entryDataa = (entryData*)a;
	entryData *entryDatab = (entryData*)b;
	return(entryDataa->rowUser - entryDatab->rowUser);
}

//Used for quicksort
int compareItems(const void* a, const void* b){
        entryData *entryDataa = (entryData*)a;
        entryData *entryDatab = (entryData*)b;
        return(entryDataa->colItem - entryDatab->colItem);
}

	
