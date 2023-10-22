#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "headers.h"
#include "Structs.h"
#include "sds_lib.h"
#include <math.h>

void clearSetUV(float set_of_U[USOF],float set_of_UV[USOF], float &set_of_V){
	for(int i=0;i<USOF;i++){
		set_of_U[i]=0;
		set_of_UV[i]=0;
	}
	set_of_V=0;
}
void calc_set(float* data, float set_of_U[USOF], float set_of_UV[USOF], int i, int j, int k, int numItems){
	int ii=i%USOF;
	if(data[i*numItems + k]!=0)
        	set_of_U[ii]++;
        if((data[i*numItems + k]!=0)&&(data[j*numItems + k]!=0))
                set_of_UV[ii]++;	
}
void learn_software(float* data, float* similarity_software, int numUsers, int numItems){
	int ii=0;
	float set_of_U[USOF], set_of_UV[USOF], set_of_V=0;
	for(int i=0;i<numUsers;i++){
		for(int j=0;j<numUsers;j++){
			similarity_software[i*numUsers+j]=1;
		}
	}
	
	for(int i=0;i<numUsers-USOF;i+=USOF){
		ii+=USOF;
		for(int j=i+1;j<numUsers;j++){
			clearSetUV(set_of_U, set_of_UV, set_of_V);
			for(int k=0;k<numItems;k++){
            			if(data[j*numItems + k]!=0)
                			set_of_V++;
				calc_set(data, set_of_U, set_of_UV, i, j, k, numItems);
				calc_set(data, set_of_U, set_of_UV, i+1, j, k, numItems);
				calc_set(data, set_of_U, set_of_UV, i+2, j, k, numItems);
				calc_set(data, set_of_U, set_of_UV, i+3, j, k, numItems);
				calc_set(data, set_of_U, set_of_UV, i+4, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+5, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+6, j, k, numItems);
				calc_set(data, set_of_U, set_of_UV, i+7, j, k, numItems);
				calc_set(data, set_of_U, set_of_UV, i+8, j, k, numItems);
				calc_set(data, set_of_U, set_of_UV, i+9, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+10, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+11, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+12, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+13, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+14, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+15, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+16, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+17, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+18, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+19, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+20, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+21, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+22, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+23, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+24, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+25, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+26, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+27, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+28, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+29, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+30, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+31, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+32, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+33, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+34, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+35, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+36, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+37, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+38, j, k, numItems);
                                calc_set(data, set_of_U, set_of_UV, i+39, j, k, numItems);
			}
			calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i, j, numUsers);
			calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+1, j, numUsers);
			calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+2, j, numUsers);
			calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+3, j, numUsers);
			calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+4, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+5, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+6, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+7, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+8, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+9, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+10, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+11, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+12, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+13, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+14, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+15, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+16, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+17, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+18, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+19, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+20, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+21, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+22, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+23, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+24, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+25, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+26, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+27, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+28, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+29, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+30, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+31, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+32, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+33, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+34, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+35, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+36, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+37, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+38, j, numUsers);
                        calc_sim(similarity_software, set_of_U, set_of_UV, set_of_V, i+39, j, numUsers);
		}
	}
	float setU, setV, setUV;
        for(int i=ii;i<numUsers;i++){
                for(int j=i+1;j<numUsers;j++){
                        setU=0;
                        setV=0;
                        setUV=0;
                        for(int k=0;k<numItems;k++){
                                if(data[i*numItems + k]!=0)
                                        setU++;
                                if(data[j*numItems + k]!=0)
                                        setV++;
                                if((data[i*numItems + k]!=0)&&(data[j*numItems + k]!=0))
                                        setUV++;
                        }
                        if (setUV>1){
                                similarity_software[i*numUsers+j]=(setUV)/sqrt(setU*setV);
                        }
                        else{
                                similarity_software[i*numUsers+j]=0;
                        }
                }
        }
}
void calc_sim(float* similarity_software, float set_of_U[USOF], float set_of_UV[USOF], float set_of_V, int i, int j, int numUsers){
	int ii=i%USOF;
	if (set_of_UV[ii]>1){
        	similarity_software[i*numUsers+j]=(set_of_UV[ii])/sqrt(set_of_U[ii]*set_of_V);
        }
        else{
        	similarity_software[i*numUsers+j]=0;
        }

}

void predict_software(float* data, float* final_data_software,float* similarity_software, int* knn_software, int numUsers,int numItems){
	float numerator,denominator;

	for(int i=0;i<numUsers;i++){
		for(int j=0;j<numItems;j++){
			final_data_software[i*numItems+j]=data[i*numItems+j];
		}
	}

	for(int i=0;i<numUsers;i++){
		for(int j=0;j<numItems;j++){
			numerator = 0;
			denominator = 0;
			if(data[i*numItems+j]==0){    // if the item has not been rated
				for(int k=0;k<knn_max;k++){		//for all the k-neighbors the user/item has check if they have rated the item/ have been rated by the user
					if(data[knn_software[i*knn_max+k]*numItems+j]!=0){	//if similar neighbor has rated/been rated
						numerator+=data[knn_software[i*knn_max+k]*numItems+j] * similarity_software[i*numUsers + knn_software[i*knn_max + k]];
						denominator+=similarity_software[i*numUsers + knn_software[i*knn_max + k]];
					}
				}
				if(denominator!=0)
					final_data_software[i*numItems+j]=numerator/denominator;			
			}
		}
	}
}


