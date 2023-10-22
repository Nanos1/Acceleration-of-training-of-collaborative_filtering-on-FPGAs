#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "headers.h"
#include "Structs.h"
#include "sds_lib.h"
#include <math.h>

void clearSetUV(int set_UV[40]){
	for(int i=0;i<40;i++){
		set_UV[i]=0;
	}
}

void clearsum(int euclidean_sum[40]){
        for(int i=0;i<40;i++){
                euclidean_sum[i]=0;
        }
}

void calculate_sum(float* data, int euclidean_sum[40], int set_UV[40], int i, int j, int k, int numItems){
	int ii=i%40;
	if((data[i*numItems+k]!=0)&&(data[j*numItems+k]!=0)){
        	euclidean_sum[ii]+=(data[i*numItems+k]-data[j*numItems+k])*(data[i*numItems+k]-data[j*numItems+k]);
        	set_UV[ii]++;
        }	
}

void calculate_sim(float* similarity_software, int euclidean_sum[40], int set_UV[40], int i, int j, int numUsers){
	int ii=i%40;
	if(set_UV[ii]>1){ 
		similarity_software[i*numUsers+j] = sqrt(euclidean_sum[ii]);
	}
//	else if((euclidean_sum[ii]==0)&&(set_UV[ii]>1)){
//		similarity_software[i*numUsers+j]=1;
	
	else{
		similarity_software[i*numUsers+j]=0;
	}

}
void learn_software(float* data, float* similarity_software, int numUsers, int numItems){
	int euclidean_numerator;
//	float euclidean_sum0, euclidean_sum1, euclidean_sum2, euclidean_sum3, euclidean_sum4, euclidean_sum5, euclidean_sum6, euclidean_sum7, euclidean_sum8, euclidean_sum9, euclidean_sum10, euclidean_sum11, euclidean_sum12, euclidean_sum13, euclidean_sum14, euclidean_sum15, euclidean_sum16, euclidean_sum17, euclidean_sum18, euclidean_sum19, euclidean_sum20, euclidean_sum21, euclidean_sum22, euclidean_sum23, euclidean_sum24, euclidean_sum25, euclidean_sum26, euclidean_sum27, euclidean_sum28, euclidean_sum29, euclidean_sum30, euclidean_sum31, euclidean_sum32, euclidean_sum33, euclidean_sum34, euclidean_sum35, euclidean_sum36, euclidean_sum37, euclidean_sum38, euclidean_sum39;
//	int set_UV0, set_UV1, set_UV2, set_UV3, set_UV4, set_UV5, set_UV6, set_UV7, set_UV8, set_UV9, set_UV10, set_UV11, set_UV12, set_UV13, set_UV14, set_UV15, set_UV16, set_UV17, set_UV18, set_UV19, set_UV20, set_UV21, set_UV22, set_UV23, set_UV24, set_UV25, set_UV26, set_UV27, set_UV28, set_UV29, set_UV30, set_UV31, set_UV32, set_UV33, set_UV34, set_UV35, set_UV36, set_UV37, set_UV38, set_UV39;
	int ii=0;
	int set_UV[40];
	int euclidean_sum[40];
	for(int i=0;i<numUsers;i++){
		for(int j=0;j<numUsers;j++){
			similarity_software[i*numUsers+j]=1;
		}
	}
	
	for(int i=0;i<numUsers-40;i+=40){
		ii+=40;
		for(int j=i+1;j<numUsers;j++){
	              	clearSetUV(set_UV);
			clearsum(euclidean_sum);
			for(int k=0;k<numItems;k++){
				calculate_sum(data, euclidean_sum, set_UV, i, j, k, numItems);
				calculate_sum(data, euclidean_sum, set_UV, i+1, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+2, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+3, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+4, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+5, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+6, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+7, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+8, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+9, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+10, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+11, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+12, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+13, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+14, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+15, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+16, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+17, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+18, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+19, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+20, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+21, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+22, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+23, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+24, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+25, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+26, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+27, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+28, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+29, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+30, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+31, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+32, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+33, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+34, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+35, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+36, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+37, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+38, j, k, numItems);
                                calculate_sum(data, euclidean_sum, set_UV, i+39, j, k, numItems);
			}
			calculate_sim(similarity_software, euclidean_sum, set_UV, i, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+1, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+2, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+3, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+4, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+5, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+6, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+7, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+8, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+9, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+10, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+11, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+12, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+13, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+14, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+15, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+16, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+17, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+18, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+19, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+20, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+21, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+22, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+23, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+24, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+25, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+26, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+27, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+28, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+29, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+30, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+31, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+32, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+33, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+34, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+35, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+36, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+37, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+38, j, numUsers);
			calculate_sim(similarity_software, euclidean_sum, set_UV, i+39, j, numUsers);

		}
	}

	int sum=0;
	int setUV=0;
	for(int i=ii;i<numUsers-1;i++){
                for(int j=i+1;j<numUsers;j++){
			sum=0;
			setUV=0;
                        for(int k=0;k<numItems;k++){
 				if((data[i*numItems+k]!=0)&&(data[j*numItems+k]!=0)){
                                        sum+=(data[i*numItems+k]-data[j*numItems+k])*(data[i*numItems+k]-data[j*numItems+k]);                               
                        		setUV++;
				}
			}
                        if(setUV>1){
//                                similarity_software[i*numUsers+j] = 1/sqrt(sum);
				similarity_software[i*numUsers+j] = sqrt(sum);
			}
			else{
				similarity_software[i*numUsers+j] = 0;
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


