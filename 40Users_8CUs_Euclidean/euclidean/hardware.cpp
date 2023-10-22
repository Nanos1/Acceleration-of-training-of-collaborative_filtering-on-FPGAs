#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "headers.h"
#include "Structs.h"
#include "sds_lib.h"
#include <hls_stream.h>

void pickUser(float* data, int _user0[ITEM_SIZE], int i, int k,int numItems){
        
//	#pragma HLS INLINE      
	pickUser: for(int h=0;h<ITEM_SIZE;h++){
	#pragma HLS PIPELINE 
                _user0[h] = data[i*numItems+k*ITEM_SIZE+h];
        }
}

void pickNextUser(float* data, stream_data_fifo &_data, int j, int k, int numItems){
 
//       #pragma HLS INLINE      
        pickNextUser: for(int h=0;h<ITEM_SIZE;h++){
        #pragma HLS PIPELINE 
                _data << data[j*numItems+k*ITEM_SIZE+h];
        }
}

void toplevelHW_learn(float* data, float* similarity, int numUsers, int numItems, int indx, int lmtindx){

	stream_data_fifo _data;
	#pragma HLS stream variable=_data depth=841
	
	int _user0[ITEM_SIZE], _user1[ITEM_SIZE], _user2[ITEM_SIZE], _user3[ITEM_SIZE], _user4[ITEM_SIZE], _user5[ITEM_SIZE], _user6[ITEM_SIZE], _user7[ITEM_SIZE], _user8[ITEM_SIZE], _user9[ITEM_SIZE], _user10[ITEM_SIZE], _user11[ITEM_SIZE], _user12[ITEM_SIZE], _user13[ITEM_SIZE], _user14[ITEM_SIZE], _user15[ITEM_SIZE], _user16[ITEM_SIZE], _user17[ITEM_SIZE], _user18[ITEM_SIZE], _user19[ITEM_SIZE], _user20[ITEM_SIZE], _user21[ITEM_SIZE], _user22[ITEM_SIZE], _user23[ITEM_SIZE], _user24[ITEM_SIZE], _user25[ITEM_SIZE], _user26[ITEM_SIZE], _user27[ITEM_SIZE], _user28[ITEM_SIZE], _user29[ITEM_SIZE], _user30[ITEM_SIZE], _user31[ITEM_SIZE], _user32[ITEM_SIZE], _user33[ITEM_SIZE], _user34[ITEM_SIZE], _user35[ITEM_SIZE], _user36[ITEM_SIZE], _user37[ITEM_SIZE], _user38[ITEM_SIZE], _user39[ITEM_SIZE];
        int _sim0[USER_SIZE], _sim1[USER_SIZE], _sim2[USER_SIZE], _sim3[USER_SIZE], _sim4[USER_SIZE], _sim5[USER_SIZE], _sim6[USER_SIZE], _sim7[USER_SIZE],  _sim8[USER_SIZE], _sim9[USER_SIZE], _sim10[USER_SIZE], _sim11[USER_SIZE], _sim12[USER_SIZE], _sim13[USER_SIZE], _sim14[USER_SIZE], _sim15[USER_SIZE], _sim16[USER_SIZE], _sim17[USER_SIZE],  _sim18[USER_SIZE], _sim19[USER_SIZE], _sim20[USER_SIZE], _sim21[USER_SIZE], _sim22[USER_SIZE], _sim23[USER_SIZE], _sim24[USER_SIZE], _sim25[USER_SIZE], _sim26[USER_SIZE], _sim27[USER_SIZE],  _sim28[USER_SIZE], _sim29[USER_SIZE], _sim30[USER_SIZE], _sim31[USER_SIZE], _sim32[USER_SIZE], _sim33[USER_SIZE], _sim34[USER_SIZE], _sim35[USER_SIZE], _sim36[USER_SIZE], _sim37[USER_SIZE],  _sim38[USER_SIZE], _sim39[USER_SIZE];
        int _sum0=0, _sum1=0, _sum2=0, _sum3=0, _sum4=0, _sum5=0, _sum6=0, _sum7=0, _sum8=0, _sum9=0, _sum10=0, _sum11=0, _sum12=0, _sum13=0, _sum14=0, _sum15=0, _sum16=0, _sum17=0, _sum18=0, _sum19=0, _sum20=0, _sum21=0, _sum22=0, _sum23=0, _sum24=0, _sum25=0, _sum26=0, _sum27=0, _sum28=0, _sum29=0, _sum30=0, _sum31=0, _sum32=0, _sum33=0, _sum34=0, _sum35=0, _sum36=0, _sum37=0, _sum38=0, _sum39=0;

	int Item_tiles = numItems/ITEM_SIZE, jjj0, isfull0=0, flg = Item_tiles-1, ii=indx;
	
        for(int i=indx;i<lmtindx-40;i+=40){
		ii+=40;
		for(int k=0;k<Item_tiles;k++){
			jjj0=i+1;
			pickUser(data, _user0, i, k, numItems);
                        pickUser(data, _user1, i+1, k, numItems);
                        pickUser(data, _user2, i+2, k, numItems);
                        pickUser(data, _user3, i+3, k, numItems);
                        pickUser(data, _user4, i+4, k, numItems);
                        pickUser(data, _user5, i+5, k, numItems);
                        pickUser(data, _user6, i+6, k, numItems);
                        pickUser(data, _user7, i+7, k, numItems);
                        pickUser(data, _user8, i+8, k, numItems);
                        pickUser(data, _user9, i+9, k, numItems);
                        pickUser(data, _user10, i+10, k, numItems);
                        pickUser(data, _user11, i+11, k, numItems);
                        pickUser(data, _user12, i+12, k, numItems);
                        pickUser(data, _user13, i+13, k, numItems);
                        pickUser(data, _user14, i+14, k, numItems);
                        pickUser(data, _user15, i+15, k, numItems);
                        pickUser(data, _user16, i+16, k, numItems);
                        pickUser(data, _user17, i+17, k, numItems);
                        pickUser(data, _user18, i+18, k, numItems);
                        pickUser(data, _user19, i+19, k, numItems);
                        pickUser(data, _user20, i+20, k, numItems);
                        pickUser(data, _user21, i+21, k, numItems);
                        pickUser(data, _user22, i+22, k, numItems);
                        pickUser(data, _user23, i+23, k, numItems);
                        pickUser(data, _user24, i+24, k, numItems);
                        pickUser(data, _user25, i+25, k, numItems);
                        pickUser(data, _user26, i+26, k, numItems);
                        pickUser(data, _user27, i+27, k, numItems);
                        pickUser(data, _user28, i+28, k, numItems);
                        pickUser(data, _user29, i+29, k, numItems);
                        pickUser(data, _user30, i+30, k, numItems);
                        pickUser(data, _user31, i+31, k, numItems);
                        pickUser(data, _user32, i+32, k, numItems);
                        pickUser(data, _user33, i+33, k, numItems);
                        pickUser(data, _user34, i+34, k, numItems);
                        pickUser(data, _user35, i+35, k, numItems);
                        pickUser(data, _user36, i+36, k, numItems);
                        pickUser(data, _user37, i+37, k, numItems);
                        pickUser(data, _user38, i+38, k, numItems);
                        pickUser(data, _user39, i+39, k, numItems);
			isfull0=0;
			for(int j=i+1;j<numUsers;j++){
                                if(isfull0==USER_SIZE){
                                        simisfull(similarity, _sim0, i, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim1, i+1, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim2, i+2, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim3, i+3, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim4, i+4, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim5, i+5, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim6, i+6, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim7, i+7, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim8, i+8, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim9, i+9, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim10, i+10, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim11, i+11, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim12, i+12, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim13, i+13, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim14, i+14, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim15, i+15, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim16, i+16, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim17, i+17, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim18, i+18, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim19, i+19, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim20, i+20, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim21, i+21, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim22, i+22, jjj0, numUsers, k, flg); 
                        		simisfull(similarity, _sim23, i+23, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim24, i+24, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim25, i+25, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim26, i+26, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim27, i+27, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim28, i+28, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim29, i+29, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim30, i+30, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim31, i+31, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim32, i+32, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim33, i+33, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim34, i+34, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim35, i+35, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim36, i+36, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim37, i+37, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim38, i+38, jjj0, numUsers, k, flg);
                        		simisfull(similarity, _sim39, i+39, jjj0, numUsers, k, flg);
                                        isfull0=0;
                                        jjj0+=USER_SIZE;
                                }
				pickNextUser(data, _data, j, k, numItems);
				compute_sim(_user0, _user1, _user2, _user3, _user4, _user5, _user6, _user7, _user8, _user9, _user10, _user11, _user12, _user13, _user14, _user15, _user16, _user17, _user18, _user19, _user20, _user21, _user22, _user23, _user24, _user25, _user26, _user27, _user28, _user29, _user30, _user31, _user32, _user33, _user34, _user35, _user36, _user37, _user38, _user39, _data, _sum0, _sum1, _sum2, _sum3, _sum4, _sum5, _sum6, _sum7, _sum8, _sum9, _sum10, _sum11, _sum12, _sum13, _sum14, _sum15, _sum16, _sum17, _sum18, _sum19, _sum20, _sum21, _sum22, _sum23, _sum24, _sum25, _sum26, _sum27, _sum28, _sum29, _sum30, _sum31, _sum32, _sum33, _sum34, _sum35, _sum36, _sum37, _sum38, _sum39);
				store(_sim0, _sim1, _sim2, _sim3, _sim4, _sim5, _sim6, _sim7, _sim8, _sim9, _sim10, _sim11, _sim12, _sim13, _sim14, _sim15, _sim16, _sim17, _sim18, _sim19, _sim20, _sim21, _sim22, _sim23, _sim24, _sim25, _sim26, _sim27, _sim28, _sim29, _sim30, _sim31, _sim32, _sim33, _sim34, _sim35, _sim36, _sim37, _sim38, _sim39, _sum0, _sum1, _sum2, _sum3, _sum4, _sum5, _sum6, _sum7, _sum8, _sum9, _sum10, _sum11, _sum12, _sum13, _sum14, _sum15, _sum16, _sum17, _sum18, _sum19, _sum20, _sum21, _sum22, _sum23, _sum24, _sum25, _sum26, _sum27, _sum28, _sum29, _sum30, _sum31, _sum32, _sum33, _sum34, _sum35, _sum36, _sum37, _sum38, _sum39, isfull0);
				isfull0++;
			}
			simisfull(similarity, _sim0, i, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim1, i+1, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim2, i+2, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim3, i+3, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim4, i+4, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim5, i+5, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim6, i+6, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim7, i+7, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim8, i+8, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim9, i+9, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim10, i+10, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim11, i+11, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim12, i+12, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim13, i+13, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim14, i+14, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim15, i+15, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim16, i+16, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim17, i+17, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim18, i+18, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim19, i+19, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim20, i+20, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim21, i+21, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim22, i+22, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim23, i+23, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim24, i+24, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim25, i+25, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim26, i+26, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim27, i+27, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim28, i+28, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim29, i+29, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim30, i+30, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim31, i+31, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim32, i+32, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim33, i+33, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim34, i+34, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim35, i+35, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim36, i+36, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim37, i+37, jjj0, numUsers, k, flg);
                        simisfull(similarity, _sim38, i+38, jjj0, numUsers, k, flg); 
                        simisfull(similarity, _sim39, i+39, jjj0, numUsers, k, flg);  
		}
	}

	_sum0=0;		
	for(int i=ii;i<lmtindx;i++){
                for(int k=0;k<Item_tiles;k++){
                        jjj0=i+1;
                        pickUser(data, _user0, i, k, numItems);
                        isfull0=0;
                        for(int j=i+1;j<numUsers;j++){
                                if(isfull0==USER_SIZE){
                                        simisfull(similarity, _sim0, i, jjj0, numUsers, k, flg);
                                        isfull0=0;
                                        jjj0+=USER_SIZE;
                                }
				pickNextUser(data, _data, j, k, numItems);
				compute_Remaining_sim(_user0, _data, _sum0);
				store_Remaining_sim(_sim0, _sum0, isfull0);
                                isfull0++;
			}
			simisfull(similarity, _sim0, i, jjj0, numUsers, k, flg);
                }
        }
}

void simisfull(float* similarity, int _sim[USER_SIZE], int i, int jjj, int numUsers, int k, int flg){
        
        int temp_sim; 
	float ttemp_sim;
	float temp_setUV;
        int jj=0;
  
     	while ((jj<USER_SIZE)&&(jjj<numUsers)){
		temp_sim = similarity[i*numUsers + jjj];
                temp_sim += _sim[jj]; // add the common similarirty
//		temp_sim += setUV[jj]*10000; // add the number of the commonly rated items seperately
//                ttemp_sim = (k==flg) ? (temp_sim!=0) ? 1/sqrt(temp_sim) : temp_sim : temp_sim; 
		ttemp_sim = temp_sim;
		if(k==flg){
			temp_setUV = temp_sim/10000;
			temp_sim = temp_sim%10000;
/*			if((temp_sim>0)&&(temp_setUV>1)){
				ttemp_sim = 1/sqrt(temp_sim);
			}
			else if((temp_sim==0)&&(temp_setUV>1)){
				ttemp_sim=1;
			}
			else{
				ttemp_sim = 0;
			}
*/
                        if(temp_setUV>1){ 
                                ttemp_sim = sqrt(temp_sim);
                        }
                        else{   
                                ttemp_sim = 0;
                        }

		}
                similarity[i*numUsers + jjj] = ttemp_sim;
//                similarity[jjj*numUsers + i] = ttemp_sim;
                _sim[jj]=0;
                jj++;
		jjj++;
        }
}

void store(int _sim0[USER_SIZE], int _sim1[USER_SIZE], int _sim2[USER_SIZE], int _sim3[USER_SIZE], int _sim4[USER_SIZE], int _sim5[USER_SIZE], int _sim6[USER_SIZE], int _sim7[USER_SIZE], int _sim8[USER_SIZE], int _sim9[USER_SIZE], int _sim10[USER_SIZE], int _sim11[USER_SIZE], int _sim12[USER_SIZE], int _sim13[USER_SIZE], int _sim14[USER_SIZE], int _sim15[USER_SIZE], int _sim16[USER_SIZE], int _sim17[USER_SIZE], int _sim18[USER_SIZE], int _sim19[USER_SIZE], int _sim20[USER_SIZE], int _sim21[USER_SIZE], int _sim22[USER_SIZE], int _sim23[USER_SIZE], int _sim24[USER_SIZE], int _sim25[USER_SIZE], int _sim26[USER_SIZE], int _sim27[USER_SIZE], int _sim28[USER_SIZE], int _sim29[USER_SIZE], int _sim30[USER_SIZE], int _sim31[USER_SIZE], int _sim32[USER_SIZE], int _sim33[USER_SIZE], int _sim34[USER_SIZE], int _sim35[USER_SIZE], int _sim36[USER_SIZE], int _sim37[USER_SIZE], int _sim38[USER_SIZE], int _sim39[USER_SIZE], int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39, int isfull){	
	_sim0[isfull]=_sum0;
        _sim1[isfull]=_sum1;
        _sim2[isfull]=_sum2;
        _sim3[isfull]=_sum3;
        _sim4[isfull]=_sum4;
        _sim5[isfull]=_sum5;
        _sim6[isfull]=_sum6;
        _sim7[isfull]=_sum7;
        _sim8[isfull]=_sum8;
        _sim9[isfull]=_sum9;
        _sim10[isfull]=_sum10;
        _sim11[isfull]=_sum11;
        _sim12[isfull]=_sum12;
        _sim13[isfull]=_sum13;
        _sim14[isfull]=_sum14;
        _sim15[isfull]=_sum15;
        _sim16[isfull]=_sum16;
        _sim17[isfull]=_sum17;
        _sim18[isfull]=_sum18;
        _sim19[isfull]=_sum19;
	_sim20[isfull]=_sum20;
        _sim21[isfull]=_sum21;
        _sim22[isfull]=_sum22;
        _sim23[isfull]=_sum23;
        _sim24[isfull]=_sum24;
        _sim25[isfull]=_sum25;
        _sim26[isfull]=_sum26;
        _sim27[isfull]=_sum27;
        _sim28[isfull]=_sum28;
        _sim29[isfull]=_sum29;
        _sim30[isfull]=_sum30;
        _sim31[isfull]=_sum31;
        _sim32[isfull]=_sum32;
        _sim33[isfull]=_sum33;
        _sim34[isfull]=_sum34;
        _sim35[isfull]=_sum35;
        _sim36[isfull]=_sum36;
        _sim37[isfull]=_sum37;
        _sim38[isfull]=_sum38;
        _sim39[isfull]=_sum39;
	_sum0=0;
        _sum1=0;
        _sum2=0;
        _sum3=0;
        _sum4=0;
        _sum5=0;
        _sum6=0;
        _sum7=0;
        _sum8=0;
        _sum9=0;
        _sum10=0;
        _sum11=0;
        _sum12=0;
        _sum13=0;
        _sum14=0;
        _sum15=0;
        _sum16=0;
        _sum17=0;
        _sum18=0;
        _sum19=0;
	_sum20=0;
        _sum21=0;
        _sum22=0;
        _sum23=0;
        _sum24=0;
        _sum25=0;
        _sum26=0;
        _sum27=0;
        _sum28=0;
        _sum29=0;
        _sum30=0;
        _sum31=0;
        _sum32=0;
        _sum33=0;
        _sum34=0;
        _sum35=0;
        _sum36=0;
        _sum37=0;
        _sum38=0;
        _sum39=0;	
}

void store_Remaining_sim(int _sim0[USER_SIZE], int &_sum0, int isfull){
        _sim0[isfull]=_sum0;
        _sum0=0;
}

void compute_Remaining_sim(int _user0[ITEM_SIZE], stream_data_fifo &_data, int &_sum0){
        int temp_user0;
        int temp_data;
        compute_Remaining: for(int i=0;i<ITEM_SIZE;i++){
        #pragma HLS PIPELINE    
//        #pragma HLS UNROLL factor=29
                temp_user0 = _user0[i];
                _data>>temp_data;
	        _sum0 += (temp_user0!=0) ? (temp_data!=0) ? (temp_user0 - temp_data)*(temp_user0 - temp_data) + 10000 : 0 : 0;
/*		if((temp_user0!=0) && (temp_data!=0)){
                        _sum0+=(temp_user0 - temp_data)*(temp_user0 - temp_data);
                        set_UV0++;
                }
*/
        }
}
void write_sim(float* similarity, float _sim[USER_SIZE], int numUsers, int i){
	float _sum;
	int j=0;
	similarity[i*numUsers+i]=0;
	
	for(int h=i+1;h<numUsers;h++){
		_sum=_sim[j]; 
        	_sum = (_sum!=0)? 1/sqrt(_sum):0;
        	similarity[i*numUsers+h]=_sum;
        	similarity[h*numUsers+i]=_sum;
        	_sim[j] = 0;
		j++;
	}
}

void compute_sim(int _user0[ITEM_SIZE], int _user1[ITEM_SIZE], int _user2[ITEM_SIZE], int _user3[ITEM_SIZE], int _user4[ITEM_SIZE], int _user5[ITEM_SIZE], int _user6[ITEM_SIZE], int _user7[ITEM_SIZE], int _user8[ITEM_SIZE], int _user9[ITEM_SIZE], int _user10[ITEM_SIZE], int _user11[ITEM_SIZE], int _user12[ITEM_SIZE], int _user13[ITEM_SIZE], int _user14[ITEM_SIZE], int _user15[ITEM_SIZE], int _user16[ITEM_SIZE], int _user17[ITEM_SIZE], int _user18[ITEM_SIZE], int _user19[ITEM_SIZE], int _user20[ITEM_SIZE], int _user21[ITEM_SIZE], int _user22[ITEM_SIZE], int _user23[ITEM_SIZE], int _user24[ITEM_SIZE], int _user25[ITEM_SIZE], int _user26[ITEM_SIZE], int _user27[ITEM_SIZE], int _user28[ITEM_SIZE], int _user29[ITEM_SIZE], int _user30[ITEM_SIZE], int _user31[ITEM_SIZE], int _user32[ITEM_SIZE], int _user33[ITEM_SIZE], int _user34[ITEM_SIZE], int _user35[ITEM_SIZE], int _user36[ITEM_SIZE], int _user37[ITEM_SIZE], int _user38[ITEM_SIZE], int _user39[ITEM_SIZE], stream_data_fifo &_data, int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39){
        int temp_user0, temp_user1, temp_user2, temp_user3, temp_user4, temp_user5, temp_user6, temp_user7, temp_user8, temp_user9, temp_user10, temp_user11, temp_user12, temp_user13, temp_user14, temp_user15, temp_user16, temp_user17, temp_user18, temp_user19,  temp_user20, temp_user21, temp_user22, temp_user23, temp_user24, temp_user25, temp_user26, temp_user27, temp_user28, temp_user29, temp_user30, temp_user31, temp_user32, temp_user33, temp_user34, temp_user35, temp_user36, temp_user37, temp_user38, temp_user39;
	int temp_data;

	compute_sim: for(int i=0;i<ITEM_SIZE;i++){	
	#pragma HLS PIPELINE    
//        #pragma HLS UNROLL factor=2
		temp_user0 = _user0[i];
                temp_user1 = _user1[i];
                temp_user2 = _user2[i];
                temp_user3 = _user3[i];
                temp_user4 = _user4[i];
                temp_user5 = _user5[i];
                temp_user6 = _user6[i];
                temp_user7 = _user7[i];
                temp_user8 = _user8[i];
                temp_user9 = _user9[i];
                temp_user10 = _user10[i];
                temp_user11 = _user11[i];
                temp_user12 = _user12[i];
                temp_user13 = _user13[i];
                temp_user14 = _user14[i];
                temp_user15 = _user15[i];
                temp_user16 = _user16[i];
                temp_user17 = _user17[i];
                temp_user18 = _user18[i];
                temp_user19 = _user19[i];
		temp_user20 = _user20[i];
                temp_user21 = _user21[i];
                temp_user22 = _user22[i];
                temp_user23 = _user23[i];
                temp_user24 = _user24[i];
                temp_user25 = _user25[i];
                temp_user26 = _user26[i];
                temp_user27 = _user27[i];
                temp_user28 = _user28[i];
                temp_user29 = _user29[i];
                temp_user30 = _user30[i];
                temp_user31 = _user31[i];
                temp_user32 = _user32[i];
                temp_user33 = _user33[i];
                temp_user34 = _user34[i];
                temp_user35 = _user35[i];
                temp_user36 = _user36[i];
                temp_user37 = _user37[i];
                temp_user38 = _user38[i];
                temp_user39 = _user39[i];
		_data >> temp_data;
		if((temp_user0!=0) && (temp_data!=0))
			_sum0+=(temp_user0 - temp_data)*(temp_user0 - temp_data)+10000;
                if((temp_user1!=0) && (temp_data!=0))
                        _sum1+=(temp_user1 - temp_data)*(temp_user1 - temp_data)+10000;
                if((temp_user2!=0) && (temp_data!=0))
                        _sum2+=(temp_user2 - temp_data)*(temp_user2 - temp_data)+10000;
                if((temp_user3!=0) && (temp_data!=0))
                        _sum3+=(temp_user3 - temp_data)*(temp_user3 - temp_data)+10000;
                if((temp_user4!=0) && (temp_data!=0))
                        _sum4+=(temp_user4 - temp_data)*(temp_user4 - temp_data)+10000;
                if((temp_user5!=0) && (temp_data!=0))
                        _sum5+=(temp_user5 - temp_data)*(temp_user5 - temp_data)+10000;
                if((temp_user6!=0) && (temp_data!=0))
                        _sum6+=(temp_user6 - temp_data)*(temp_user6 - temp_data)+10000;
                if((temp_user7!=0) && (temp_data!=0))
                        _sum7+=(temp_user7 - temp_data)*(temp_user7 - temp_data)+10000;
                if((temp_user8!=0) && (temp_data!=0))
                        _sum8+=(temp_user8 - temp_data)*(temp_user8 - temp_data)+10000;
                if((temp_user9!=0) && (temp_data!=0))
                        _sum9+=(temp_user9 - temp_data)*(temp_user9 - temp_data)+10000;
                if((temp_user10!=0) && (temp_data!=0))
                        _sum10+=(temp_user10 - temp_data)*(temp_user10 - temp_data)+10000;
                if((temp_user11!=0) && (temp_data!=0))
                        _sum11+=(temp_user11 - temp_data)*(temp_user11 - temp_data)+10000;
                if((temp_user12!=0) && (temp_data!=0))
                        _sum12+=(temp_user12 - temp_data)*(temp_user12 - temp_data)+10000;
                if((temp_user13!=0) && (temp_data!=0))
                        _sum13+=(temp_user13 - temp_data)*(temp_user13 - temp_data)+10000;
                if((temp_user14!=0) && (temp_data!=0))
                        _sum14+=(temp_user14 - temp_data)*(temp_user14 - temp_data)+10000;
                if((temp_user15!=0) && (temp_data!=0))
                        _sum15+=(temp_user15 - temp_data)*(temp_user15 - temp_data)+10000;
                if((temp_user16!=0) && (temp_data!=0))
                        _sum16+=(temp_user16 - temp_data)*(temp_user16 - temp_data)+10000;
                if((temp_user17!=0) && (temp_data!=0))
                        _sum17+=(temp_user17 - temp_data)*(temp_user17 - temp_data)+10000;
                if((temp_user18!=0) && (temp_data!=0))
                        _sum18+=(temp_user18 - temp_data)*(temp_user18 - temp_data)+10000;
                if((temp_user19!=0) && (temp_data!=0))
                        _sum19+=(temp_user19 - temp_data)*(temp_user19 - temp_data)+10000;
                if((temp_user20!=0) && (temp_data!=0))
                        _sum20+=(temp_user20 - temp_data)*(temp_user20 - temp_data)+10000;
                if((temp_user21!=0) && (temp_data!=0))
                        _sum21+=(temp_user21 - temp_data)*(temp_user21 - temp_data)+10000;
                if((temp_user22!=0) && (temp_data!=0))
                        _sum22+=(temp_user22 - temp_data)*(temp_user22 - temp_data)+10000;
                if((temp_user23!=0) && (temp_data!=0))
                        _sum23+=(temp_user23 - temp_data)*(temp_user23 - temp_data)+10000;
                if((temp_user24!=0) && (temp_data!=0))
                        _sum24+=(temp_user24 - temp_data)*(temp_user24 - temp_data)+10000;
                if((temp_user25!=0) && (temp_data!=0))
                        _sum25+=(temp_user25 - temp_data)*(temp_user25 - temp_data)+10000;
                if((temp_user26!=0) && (temp_data!=0))
                        _sum26+=(temp_user26 - temp_data)*(temp_user26 - temp_data)+10000;
                if((temp_user27!=0) && (temp_data!=0))
                        _sum27+=(temp_user27 - temp_data)*(temp_user27 - temp_data)+10000;
                if((temp_user28!=0) && (temp_data!=0))
                        _sum28+=(temp_user28 - temp_data)*(temp_user28 - temp_data)+10000;
                if((temp_user29!=0) && (temp_data!=0))
			_sum29+=(temp_user29 - temp_data)*(temp_user29 - temp_data)+10000;
                if((temp_user30!=0) && (temp_data!=0))
                        _sum30+=(temp_user30 - temp_data)*(temp_user30 - temp_data)+10000;
                if((temp_user31!=0) && (temp_data!=0))
                        _sum31+=(temp_user31 - temp_data)*(temp_user31 - temp_data)+10000;
                if((temp_user32!=0) && (temp_data!=0))
                        _sum32+=(temp_user32 - temp_data)*(temp_user32 - temp_data)+10000;
                if((temp_user33!=0) && (temp_data!=0))
                        _sum33+=(temp_user33 - temp_data)*(temp_user33 - temp_data)+10000;
                if((temp_user34!=0) && (temp_data!=0))
                        _sum34+=(temp_user34 - temp_data)*(temp_user34 - temp_data)+10000;
                if((temp_user35!=0) && (temp_data!=0))
                        _sum35+=(temp_user35 - temp_data)*(temp_user35 - temp_data)+10000;
                if((temp_user36!=0) && (temp_data!=0))
                        _sum36+=(temp_user36 - temp_data)*(temp_user36 - temp_data)+10000;
                if((temp_user37!=0) && (temp_data!=0))
                        _sum37+=(temp_user37 - temp_data)*(temp_user37 - temp_data)+10000;
                if((temp_user38!=0) && (temp_data!=0))
                        _sum38+=(temp_user38 - temp_data)*(temp_user38 - temp_data)+10000;
                if((temp_user39!=0) && (temp_data!=0))
                        _sum39+=(temp_user39 - temp_data)*(temp_user39 - temp_data)+10000;

/*		
                _sum0 += (temp_user0!=0) ? (temp_data!=0) ? (temp_user0 - temp_data)*(temp_user0 - temp_data) + 10000 : 0 : 0; 
                _sum1 += (temp_user1!=0) ? (temp_data!=0) ? (temp_user1 - temp_data)*(temp_user1 - temp_data) + 10000 : 0 : 0; 
                _sum2 += (temp_user2!=0) ? (temp_data!=0) ? (temp_user2 - temp_data)*(temp_user2 - temp_data) + 10000: 0 : 0; 
                _sum3 += (temp_user3!=0) ? (temp_data!=0) ? (temp_user3 - temp_data)*(temp_user3 - temp_data) + 10000: 0 : 0;
                _sum4 += (temp_user4!=0) ? (temp_data!=0) ? (temp_user4 - temp_data)*(temp_user4 - temp_data) + 10000: 0 : 0; 
                _sum5 += (temp_user5!=0) ? (temp_data!=0) ? (temp_user5 - temp_data)*(temp_user5 - temp_data) + 10000: 0 : 0; 
                _sum6 += (temp_user6!=0) ? (temp_data!=0) ? (temp_user6 - temp_data)*(temp_user6 - temp_data) + 10000: 0 : 0; 
                _sum7 += (temp_user7!=0) ? (temp_data!=0) ? (temp_user7 - temp_data)*(temp_user7 - temp_data) + 10000: 0 : 0;
                _sum8 += (temp_user8!=0) ? (temp_data!=0) ? (temp_user8 - temp_data)*(temp_user8 - temp_data) + 10000: 0 : 0; 
                _sum9 += (temp_user9!=0) ? (temp_data!=0) ? (temp_user9 - temp_data)*(temp_user9 - temp_data) + 10000: 0 : 0;
                _sum10 += (temp_user10!=0) ? (temp_data!=0) ? (temp_user10 - temp_data)*(temp_user10 - temp_data) + 10000: 0 : 0; 
                _sum11 += (temp_user11!=0) ? (temp_data!=0) ? (temp_user11 - temp_data)*(temp_user11 - temp_data) + 10000: 0 : 0; 
                _sum12 += (temp_user12!=0) ? (temp_data!=0) ? (temp_user12 - temp_data)*(temp_user12 - temp_data) + 10000: 0 : 0; 
                _sum13 += (temp_user13!=0) ? (temp_data!=0) ? (temp_user13 - temp_data)*(temp_user13 - temp_data) + 10000: 0 : 0;
                _sum14 += (temp_user14!=0) ? (temp_data!=0) ? (temp_user14 - temp_data)*(temp_user14 - temp_data) + 10000: 0 : 0; 
                _sum15 += (temp_user15!=0) ? (temp_data!=0) ? (temp_user15 - temp_data)*(temp_user15 - temp_data) + 10000: 0 : 0; 
                _sum16 += (temp_user16!=0) ? (temp_data!=0) ? (temp_user16 - temp_data)*(temp_user16 - temp_data) + 10000: 0 : 0; 
                _sum17 += (temp_user17!=0) ? (temp_data!=0) ? (temp_user17 - temp_data)*(temp_user17 - temp_data) + 10000: 0 : 0;
                _sum18 += (temp_user18!=0) ? (temp_data!=0) ? (temp_user18 - temp_data)*(temp_user18 - temp_data) + 10000: 0 : 0; 
                _sum19 += (temp_user19!=0) ? (temp_data!=0) ? (temp_user19 - temp_data)*(temp_user19 - temp_data) + 10000: 0 : 0; 
                _sum20 += (temp_user20!=0) ? (temp_data!=0) ? (temp_user20 - temp_data)*(temp_user20 - temp_data) + 10000: 0 : 0; 
                _sum21 += (temp_user21!=0) ? (temp_data!=0) ? (temp_user21 - temp_data)*(temp_user21 - temp_data) + 10000: 0 : 0; 
                _sum22 += (temp_user22!=0) ? (temp_data!=0) ? (temp_user22 - temp_data)*(temp_user22 - temp_data) + 10000: 0 : 0; 
                _sum23 += (temp_user23!=0) ? (temp_data!=0) ? (temp_user23 - temp_data)*(temp_user23 - temp_data) + 10000: 0 : 0;
                _sum24 += (temp_user24!=0) ? (temp_data!=0) ? (temp_user24 - temp_data)*(temp_user24 - temp_data) + 10000: 0 : 0; 
                _sum25 += (temp_user25!=0) ? (temp_data!=0) ? (temp_user25 - temp_data)*(temp_user25 - temp_data) + 10000: 0 : 0; 
                _sum26 += (temp_user26!=0) ? (temp_data!=0) ? (temp_user26 - temp_data)*(temp_user26 - temp_data) + 10000: 0 : 0; 
                _sum27 += (temp_user27!=0) ? (temp_data!=0) ? (temp_user27 - temp_data)*(temp_user27 - temp_data) + 10000: 0 : 0;
                _sum28 += (temp_user28!=0) ? (temp_data!=0) ? (temp_user28 - temp_data)*(temp_user28 - temp_data) + 10000: 0 : 0; 
                _sum29 += (temp_user29!=0) ? (temp_data!=0) ? (temp_user29 - temp_data)*(temp_user29 - temp_data) + 10000: 0 : 0;
                _sum30 += (temp_user30!=0) ? (temp_data!=0) ? (temp_user30 - temp_data)*(temp_user30 - temp_data) + 10000: 0 : 0; 
                _sum31 += (temp_user31!=0) ? (temp_data!=0) ? (temp_user31 - temp_data)*(temp_user31 - temp_data) + 10000: 0 : 0; 
                _sum32 += (temp_user32!=0) ? (temp_data!=0) ? (temp_user32 - temp_data)*(temp_user32 - temp_data) + 10000: 0 : 0; 
                _sum33 += (temp_user33!=0) ? (temp_data!=0) ? (temp_user33 - temp_data)*(temp_user33 - temp_data) + 10000: 0 : 0;
                _sum34 += (temp_user34!=0) ? (temp_data!=0) ? (temp_user34 - temp_data)*(temp_user34 - temp_data) + 10000: 0 : 0; 
                _sum35 += (temp_user35!=0) ? (temp_data!=0) ? (temp_user35 - temp_data)*(temp_user35 - temp_data) + 10000: 0 : 0; 
                _sum36 += (temp_user36!=0) ? (temp_data!=0) ? (temp_user36 - temp_data)*(temp_user36 - temp_data) + 10000: 0 : 0; 
                _sum37 += (temp_user37!=0) ? (temp_data!=0) ? (temp_user37 - temp_data)*(temp_user37 - temp_data) + 10000: 0 : 0;
                _sum38 += (temp_user38!=0) ? (temp_data!=0) ? (temp_user38 - temp_data)*(temp_user38 - temp_data) + 10000: 0 : 0; 
                _sum39 += (temp_user39!=0) ? (temp_data!=0) ? (temp_user39 - temp_data)*(temp_user39 - temp_data) + 10000: 0 : 0;   
*/
	}
}




