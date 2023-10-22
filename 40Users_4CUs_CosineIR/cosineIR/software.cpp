#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "headers.h"
#include "Structs.h"
//#include "sds_lib.h"
#include <math.h>

void clear(int set_of_U[USOF], int set_of_V[USOF], int set_of_UV[USOF], int common[USOF]){
	for(int i=0;i<USOF;i++){
		set_of_U[i]=0;
		set_of_V[i]=0;
		set_of_UV[i]=0;
		common[i]=0;
	}
}

void calc_sim(float* data, int set_of_U[USOF], int set_of_V[USOF], int set_of_UV[USOF], int common[USOF], int i, int j, int k, int numItems){
	int ii=i%USOF;
	if((data[i*numItems + k]!=0)&&(data[j*numItems + k]!=0)){
        	set_of_UV[ii]+=(data[i*numItems + k])*(data[j*numItems + k]);
                set_of_U[ii]+=(data[i*numItems + k])*(data[i*numItems + k]);
                set_of_V[ii]+=(data[j*numItems + k])*(data[j*numItems + k]);
                common[ii]++;
        }
}
 
void write_sim(float* similarity_software, int set_of_U[USOF], int set_of_V[USOF], int set_of_UV[USOF], int common[USOF], int i, int j, int numUsers){
	int ii=i%USOF;
	if(common[ii]>1){
        	similarity_software[i*numUsers+j]=(set_of_UV[ii])/sqrt(set_of_U[ii]*set_of_V[ii]);
        }
        else{
        	similarity_software[i*numUsers+j]=0;
        }
}
void learn_software(float* data, float* similarity_software, int numUsers, int numItems){
	int ii=0;
	int set_of_U[USOF], set_of_V[USOF], set_of_UV[USOF], common[USOF];

	for(int i=0;i<numUsers;i++){
		for(int j=0;j<numUsers;j++){
			similarity_software[i*numUsers+j]=1;
		}
	}

	for(int i=0;i<numUsers-USOF;i+=USOF){
		ii+=USOF;
		for(int j=i+1;j<numUsers;j++){
			clear(set_of_U, set_of_V, set_of_UV, common);
			for(int k=0;k<numItems;k++){
				calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i, j, k, numItems);
				calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+1, j, k, numItems);
				calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+2, j, k, numItems);
				calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+3, j, k, numItems);
				calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+4, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+5, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+6, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+7, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+8, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+9, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+10, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+11, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+12, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+13, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+14, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+15, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+16, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+17, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+18, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+19, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+20, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+21, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+22, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+23, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+24, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+25, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+26, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+27, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+28, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+29, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+30, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+31, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+32, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+33, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+34, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+35, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+36, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+37, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+38, j, k, numItems);
                                calc_sim(data, set_of_U, set_of_V, set_of_UV, common, i+39, j, k, numItems);
			}
			write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i, j, numUsers);
			write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+1, j, numUsers);
			write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+2, j, numUsers);
			write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+3, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+4, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+5, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+6, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+7, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+8, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+9, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+10, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+11, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+12, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+13, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+14, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+15, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+16, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+17, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+18, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+19, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+20, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+21, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+22, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+23, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+24, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+25, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+26, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+27, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+28, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+29, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+30, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+31, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+32, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+33, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+34, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+35, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+36, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+37, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+38, j, numUsers);
                        write_sim(similarity_software, set_of_U, set_of_V, set_of_UV, common, i+39, j, numUsers);
		}
	}
	int U, V, UV, comm;
        for(int i=ii;i<numUsers;i++){
                for(int j=i+1;j<numUsers;j++){
                        U=0;
                        V=0;
                        UV=0;
                        comm=0;
                        for(int k=0;k<numItems;k++){
                                if((data[i*numItems + k]!=0)&&(data[j*numItems + k]!=0)){
                                        UV+=(data[i*numItems + k])*(data[j*numItems + k]);
                                        U+=(data[i*numItems + k])*(data[i*numItems + k]);
                                        V+=(data[j*numItems + k])*(data[j*numItems + k]);
                                        comm++;
                                }
                        }
                        if (comm>1){
                                similarity_software[i*numUsers+j]=(UV)/sqrt(U*V);
                        }
                        else{
                                similarity_software[i*numUsers+j]=0;
                        }
                }
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


