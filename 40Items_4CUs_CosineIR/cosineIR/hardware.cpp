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

void toplevelHW_learn(float* data, float* similarity, int* setN , int* U, int* V, int numUsers, int numItems, int indx, int lmtindx){

	stream_data_fifo _data;
	#pragma HLS stream variable=_data depth=1853
	
	int _user0[ITEM_SIZE], _user1[ITEM_SIZE], _user2[ITEM_SIZE], _user3[ITEM_SIZE], _user4[ITEM_SIZE], _user5[ITEM_SIZE], _user6[ITEM_SIZE], _user7[ITEM_SIZE], _user8[ITEM_SIZE], _user9[ITEM_SIZE], _user10[ITEM_SIZE], _user11[ITEM_SIZE], _user12[ITEM_SIZE], _user13[ITEM_SIZE], _user14[ITEM_SIZE], _user15[ITEM_SIZE], _user16[ITEM_SIZE], _user17[ITEM_SIZE], _user18[ITEM_SIZE], _user19[ITEM_SIZE], _user20[ITEM_SIZE], _user21[ITEM_SIZE], _user22[ITEM_SIZE], _user23[ITEM_SIZE], _user24[ITEM_SIZE], _user25[ITEM_SIZE], _user26[ITEM_SIZE], _user27[ITEM_SIZE], _user28[ITEM_SIZE], _user29[ITEM_SIZE], _user30[ITEM_SIZE], _user31[ITEM_SIZE], _user32[ITEM_SIZE], _user33[ITEM_SIZE], _user34[ITEM_SIZE], _user35[ITEM_SIZE], _user36[ITEM_SIZE], _user37[ITEM_SIZE], _user38[ITEM_SIZE], _user39[ITEM_SIZE];

        int _sim0[USER_SIZE], _sim1[USER_SIZE], _sim2[USER_SIZE], _sim3[USER_SIZE], _sim4[USER_SIZE], _sim5[USER_SIZE], _sim6[USER_SIZE], _sim7[USER_SIZE], _sim8[USER_SIZE], _sim9[USER_SIZE], _sim10[USER_SIZE], _sim11[USER_SIZE], _sim12[USER_SIZE], _sim13[USER_SIZE], _sim14[USER_SIZE], _sim15[USER_SIZE], _sim16[USER_SIZE], _sim17[USER_SIZE], _sim18[USER_SIZE], _sim19[USER_SIZE], _sim20[USER_SIZE], _sim21[USER_SIZE], _sim22[USER_SIZE], _sim23[USER_SIZE], _sim24[USER_SIZE], _sim25[USER_SIZE], _sim26[USER_SIZE], _sim27[USER_SIZE], _sim28[USER_SIZE], _sim29[USER_SIZE], _sim30[USER_SIZE], _sim31[USER_SIZE], _sim32[USER_SIZE], _sim33[USER_SIZE], _sim34[USER_SIZE], _sim35[USER_SIZE], _sim36[USER_SIZE], _sim37[USER_SIZE], _sim38[USER_SIZE], _sim39[USER_SIZE];
	int _sum0=0, _sum1=0, _sum2=0, _sum3=0, _sum4=0, _sum5=0, _sum6=0, _sum7=0, _sum8=0, _sum9=0, _sum10=0, _sum11=0, _sum12=0, _sum13=0, _sum14=0, _sum15=0, _sum16=0, _sum17=0, _sum18=0, _sum19=0, _sum20=0, _sum21=0, _sum22=0, _sum23=0, _sum24=0, _sum25=0, _sum26=0, _sum27=0, _sum28=0, _sum29=0, _sum30=0, _sum31=0, _sum32=0, _sum33=0, _sum34=0, _sum35=0, _sum36=0, _sum37=0, _sum38=0, _sum39=0;
	int _sumU0[USER_SIZE], _sumU1[USER_SIZE], _sumU2[USER_SIZE], _sumU3[USER_SIZE], _sumU4[USER_SIZE], _sumU5[USER_SIZE], _sumU6[USER_SIZE], _sumU7[USER_SIZE], _sumU8[USER_SIZE], _sumU9[USER_SIZE], _sumU10[USER_SIZE], _sumU11[USER_SIZE], _sumU12[USER_SIZE], _sumU13[USER_SIZE], _sumU14[USER_SIZE], _sumU15[USER_SIZE], _sumU16[USER_SIZE], _sumU17[USER_SIZE], _sumU18[USER_SIZE], _sumU19[USER_SIZE], _sumU20[USER_SIZE], _sumU21[USER_SIZE], _sumU22[USER_SIZE], _sumU23[USER_SIZE], _sumU24[USER_SIZE], _sumU25[USER_SIZE], _sumU26[USER_SIZE], _sumU27[USER_SIZE], _sumU28[USER_SIZE], _sumU29[USER_SIZE], _sumU30[USER_SIZE], _sumU31[USER_SIZE], _sumU32[USER_SIZE], _sumU33[USER_SIZE], _sumU34[USER_SIZE], _sumU35[USER_SIZE], _sumU36[USER_SIZE], _sumU37[USER_SIZE], _sumU38[USER_SIZE], _sumU39[USER_SIZE];
	int sumU0=0, sumU1=0, sumU2=0, sumU3=0, sumU4=0, sumU5=0, sumU6=0, sumU7=0, sumU8=0, sumU9=0, sumU10=0, sumU11=0, sumU12=0, sumU13=0, sumU14=0, sumU15=0, sumU16=0, sumU17=0, sumU18=0, sumU19=0, sumU20=0, sumU21=0, sumU22=0, sumU23=0, sumU24=0, sumU25=0, sumU26=0, sumU27=0, sumU28=0, sumU29=0, sumU30=0, sumU31=0, sumU32=0, sumU33=0, sumU34=0, sumU35=0, sumU36=0, sumU37=0, sumU38=0, sumU39=0;
	int _sumV0[USER_SIZE], _sumV1[USER_SIZE], _sumV2[USER_SIZE], _sumV3[USER_SIZE], _sumV4[USER_SIZE], _sumV5[USER_SIZE], _sumV6[USER_SIZE], _sumV7[USER_SIZE], _sumV8[USER_SIZE], _sumV9[USER_SIZE], _sumV10[USER_SIZE], _sumV11[USER_SIZE], _sumV12[USER_SIZE], _sumV13[USER_SIZE], _sumV14[USER_SIZE], _sumV15[USER_SIZE], _sumV16[USER_SIZE], _sumV17[USER_SIZE], _sumV18[USER_SIZE], _sumV19[USER_SIZE], _sumV20[USER_SIZE], _sumV21[USER_SIZE], _sumV22[USER_SIZE], _sumV23[USER_SIZE], _sumV24[USER_SIZE], _sumV25[USER_SIZE], _sumV26[USER_SIZE], _sumV27[USER_SIZE], _sumV28[USER_SIZE], _sumV29[USER_SIZE], _sumV30[USER_SIZE], _sumV31[USER_SIZE], _sumV32[USER_SIZE], _sumV33[USER_SIZE], _sumV34[USER_SIZE], _sumV35[USER_SIZE], _sumV36[USER_SIZE], _sumV37[USER_SIZE], _sumV38[USER_SIZE], _sumV39[USER_SIZE];
	int sumV0=0, sumV1=0, sumV2=0, sumV3=0, sumV4=0, sumV5=0, sumV6=0, sumV7=0, sumV8=0, sumV9=0, sumV10=0, sumV11=0, sumV12=0, sumV13=0, sumV14=0, sumV15=0, sumV16=0, sumV17=0, sumV18=0, sumV19=0, sumV20=0, sumV21=0, sumV22=0, sumV23=0, sumV24=0, sumV25=0, sumV26=0, sumV27=0, sumV28=0, sumV29=0, sumV30=0, sumV31=0, sumV32=0, sumV33=0, sumV34=0, sumV35=0, sumV36=0, sumV37=0, sumV38=0, sumV39=0;
	int _setN0[USER_SIZE], _setN1[USER_SIZE], _setN2[USER_SIZE], _setN3[USER_SIZE], _setN4[USER_SIZE], _setN5[USER_SIZE], _setN6[USER_SIZE], _setN7[USER_SIZE], _setN8[USER_SIZE], _setN9[USER_SIZE], _setN10[USER_SIZE], _setN11[USER_SIZE], _setN12[USER_SIZE], _setN13[USER_SIZE], _setN14[USER_SIZE], _setN15[USER_SIZE], _setN16[USER_SIZE], _setN17[USER_SIZE], _setN18[USER_SIZE], _setN19[USER_SIZE], _setN20[USER_SIZE], _setN21[USER_SIZE], _setN22[USER_SIZE], _setN23[USER_SIZE], _setN24[USER_SIZE], _setN25[USER_SIZE], _setN26[USER_SIZE], _setN27[USER_SIZE], _setN28[USER_SIZE], _setN29[USER_SIZE], _setN30[USER_SIZE], _setN31[USER_SIZE], _setN32[USER_SIZE], _setN33[USER_SIZE], _setN34[USER_SIZE], _setN35[USER_SIZE], _setN36[USER_SIZE], _setN37[USER_SIZE], _setN38[USER_SIZE], _setN39[USER_SIZE];
	int setN0=0, setN1=0, setN2=0, setN3=0, setN4=0, setN5=0, setN6=0, setN7=0, setN8=0, setN9=0, setN10=0, setN11=0, setN12=0, setN13=0, setN14=0, setN15=0, setN16=0, setN17=0, setN18=0, setN19=0, setN20=0, setN21=0, setN22=0, setN23=0, setN24=0, setN25=0, setN26=0, setN27=0, setN28=0, setN29=0, setN30=0, setN31=0, setN32=0, setN33=0, setN34=0, setN35=0, setN36=0, setN37=0, setN38=0, setN39=0;

	int Item_tiles = numItems/ITEM_SIZE, jjj0, isfull0=0, flg = Item_tiles-1, ii=indx;
	
        for(int i=indx;i<lmtindx-40;i+=40){
		ii+=40;
		for(int k=0;k<Item_tiles;k++){
			jjj0=i+1;
                        isfull0=0;
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
			for(int j=i+1;j<numUsers;j++){
                                if(isfull0==USER_SIZE){
                                        simisfull(similarity, setN, U, V, _sim0, _setN0, _sumU0, _sumV0, i, jjj0, numUsers, k, flg);
					simisfull(similarity, setN, U, V, _sim1, _setN1, _sumU1, _sumV1, i+1, jjj0, numUsers, k, flg);
					simisfull(similarity, setN, U, V, _sim2, _setN2, _sumU2, _sumV2, i+2, jjj0, numUsers, k, flg);
					simisfull(similarity, setN, U, V, _sim3, _setN3, _sumU3, _sumV3, i+3, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim4, _setN4, _sumU4, _sumV4, i+4, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim5, _setN5, _sumU5, _sumV5, i+5, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim6, _setN6, _sumU6, _sumV6, i+6, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim7, _setN7, _sumU7, _sumV7, i+7, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim8, _setN8, _sumU8, _sumV8, i+8, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim9, _setN9, _sumU9, _sumV9, i+9, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim10, _setN10, _sumU10, _sumV10, i+10, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim11, _setN11, _sumU11, _sumV11, i+11, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim12, _setN12, _sumU12, _sumV12, i+12, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim13, _setN13, _sumU13, _sumV13, i+13, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim14, _setN14, _sumU14, _sumV14, i+14, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim15, _setN15, _sumU15, _sumV15, i+15, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim16, _setN16, _sumU16, _sumV16, i+16, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim17, _setN17, _sumU17, _sumV17, i+17, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim18, _setN18, _sumU18, _sumV18, i+18, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim19, _setN19, _sumU19, _sumV19, i+19, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim20, _setN20, _sumU20, _sumV20, i+20, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim21, _setN21, _sumU21, _sumV21, i+21, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim22, _setN22, _sumU22, _sumV22, i+22, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim23, _setN23, _sumU23, _sumV23, i+23, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim24, _setN24, _sumU24, _sumV24, i+24, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim25, _setN25, _sumU25, _sumV25, i+25, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim26, _setN26, _sumU26, _sumV26, i+26, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim27, _setN27, _sumU27, _sumV27, i+27, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim28, _setN28, _sumU28, _sumV28, i+28, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim29, _setN29, _sumU29, _sumV29, i+29, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim30, _setN30, _sumU30, _sumV30, i+30, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim31, _setN31, _sumU31, _sumV31, i+31, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim32, _setN32, _sumU32, _sumV32, i+32, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim33, _setN33, _sumU33, _sumV33, i+33, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim34, _setN34, _sumU34, _sumV34, i+34, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim35, _setN35, _sumU35, _sumV35, i+35, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim36, _setN36, _sumU36, _sumV36, i+36, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim37, _setN37, _sumU37, _sumV37, i+37, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim38, _setN38, _sumU38, _sumV38, i+38, jjj0, numUsers, k, flg);
                                        simisfull(similarity, setN, U, V, _sim39, _setN39, _sumU39, _sumV39, i+39, jjj0, numUsers, k, flg);
                                        isfull0=0;
                                        jjj0+=USER_SIZE;
                                }
				pickNextUser(data, _data, j, k, numItems);
				compute_sim(_user0, _user1, _user2, _user3, _user4, _user5, _user6, _user7, _user8, _user9, _user10, _user11, _user12, _user13, _user14, _user15, _user16, _user17, _user18, _user19, _user20, _user21, _user22, _user23, _user24, _user25, _user26, _user27, _user28, _user29, _user30, _user31, _user32, _user33, _user34, _user35, _user36, _user37, _user38, _user39, _data, _sum0, _sum1, _sum2, _sum3, _sum4, _sum5, _sum6, _sum7, _sum8, _sum9, _sum10, _sum11, _sum12, _sum13, _sum14, _sum15, _sum16, _sum17, _sum18, _sum19, _sum20, _sum21, _sum22, _sum23, _sum24, _sum25, _sum26, _sum27, _sum28, _sum29, _sum30, _sum31, _sum32, _sum33, _sum34, _sum35, _sum36, _sum37, _sum38, _sum39, sumU0, sumU1, sumU2, sumU3, sumU4, sumU5, sumU6, sumU7, sumU8, sumU9, sumU10, sumU11, sumU12, sumU13, sumU14, sumU15, sumU16, sumU17, sumU18, sumU19, sumU20, sumU21, sumU22, sumU23, sumU24, sumU25, sumU26, sumU27, sumU28, sumU29, sumU30, sumU31, sumU32, sumU33, sumU34, sumU35, sumU36, sumU37, sumU38, sumU39, sumV0, sumV1, sumV2, sumV3, sumV4, sumV5, sumV6, sumV7, sumV8, sumV9, sumV10, sumV11, sumV12, sumV13, sumV14, sumV15, sumV16, sumV17, sumV18, sumV19, sumV20, sumV21, sumV22, sumV23, sumV24, sumV25, sumV26, sumV27, sumV28, sumV29, sumV30, sumV31, sumV32, sumV33, sumV34, sumV35, sumV36, sumV37, sumV38, sumV39, setN0, setN1, setN2, setN3, setN4, setN5, setN6, setN7, setN8, setN9, setN10, setN11, setN12, setN13, setN14, setN15, setN16, setN17, setN18, setN19, setN20, setN21, setN22, setN23, setN24, setN25, setN26, setN27, setN28, setN29, setN30, setN31, setN32, setN33, setN34, setN35, setN36, setN37, setN38, setN39);

				store(_sim0, _sim1, _sim2, _sim3, _sim4, _sim5, _sim6, _sim7, _sim8, _sim9, _sim10, _sim11, _sim12, _sim13, _sim14, _sim15, _sim16, _sim17, _sim18, _sim19, _sim20, _sim21, _sim22, _sim23, _sim24, _sim25, _sim26, _sim27, _sim28, _sim29, _sim30, _sim31, _sim32, _sim33, _sim34, _sim35, _sim36, _sim37, _sim38, _sim39, _sum0, _sum1, _sum2, _sum3, _sum4, _sum5, _sum6, _sum7, _sum8, _sum9, _sum10, _sum11, _sum12, _sum13, _sum14, _sum15, _sum16, _sum17, _sum18, _sum19, _sum20, _sum21, _sum22, _sum23, _sum24, _sum25, _sum26, _sum27, _sum28, _sum29, _sum30, _sum31, _sum32, _sum33, _sum34, _sum35, _sum36, _sum37, _sum38, _sum39, _setN0, _setN1, _setN2, _setN3, _setN4, _setN5, _setN6, _setN7, _setN8, _setN9, _setN10, _setN11, _setN12, _setN13, _setN14, _setN15, _setN16, _setN17, _setN18, _setN19, _setN20, _setN21, _setN22, _setN23, _setN24, _setN25, _setN26, _setN27, _setN28, _setN29, _setN30, _setN31, _setN32, _setN33, _setN34, _setN35, _setN36, _setN37, _setN38, _setN39, setN0, setN1, setN2, setN3, setN4, setN5, setN6, setN7, setN8, setN9, setN10, setN11, setN12, setN13, setN14, setN15, setN16, setN17, setN18, setN19, setN20, setN21, setN22, setN23, setN24, setN25, setN26, setN27, setN28, setN29, setN30, setN31, setN32, setN33, setN34, setN35, setN36, setN37, setN38, setN39, _sumU0, _sumU1, _sumU2, _sumU3, _sumU4, _sumU5, _sumU6, _sumU7, _sumU8, _sumU9, _sumU10, _sumU11, _sumU12, _sumU13, _sumU14, _sumU15, _sumU16, _sumU17, _sumU18, _sumU19, _sumU20, _sumU21, _sumU22, _sumU23, _sumU24, _sumU25, _sumU26, _sumU27, _sumU28, _sumU29, _sumU30, _sumU31, _sumU32, _sumU33, _sumU34, _sumU35, _sumU36, _sumU37, _sumU38, _sumU39, sumU0, sumU1, sumU2, sumU3, sumU4, sumU5, sumU6, sumU7, sumU8, sumU9, sumU10, sumU11, sumU12, sumU13, sumU14, sumU15, sumU16, sumU17, sumU18, sumU19, sumU20, sumU21, sumU22, sumU23, sumU24, sumU25, sumU26, sumU27, sumU28, sumU29, sumU30, sumU31, sumU32, sumU33, sumU34, sumU35, sumU36, sumU37, sumU38, sumU39, _sumV0, _sumV1, _sumV2, _sumV3, _sumV4, _sumV5, _sumV6, _sumV7, _sumV8, _sumV9, _sumV10, _sumV11, _sumV12, _sumV13, _sumV14, _sumV15, _sumV16, _sumV17, _sumV18, _sumV19, _sumV20, _sumV21, _sumV22, _sumV23, _sumV24, _sumV25, _sumV26, _sumV27, _sumV28, _sumV29, _sumV30, _sumV31, _sumV32, _sumV33, _sumV34, _sumV35, _sumV36, _sumV37, _sumV38, _sumV39, sumV0, sumV1, sumV2, sumV3, sumV4, sumV5, sumV6, sumV7, sumV8, sumV9, sumV10, sumV11, sumV12, sumV13, sumV14, sumV15, sumV16, sumV17, sumV18, sumV19, sumV20, sumV21, sumV22, sumV23, sumV24, sumV25, sumV26, sumV27, sumV28, sumV29, sumV30, sumV31, sumV32, sumV33, sumV34, sumV35, sumV36, sumV37, sumV38, sumV39, isfull0);
//				storeUV(_sumU0, _sumU1, _sumU2, _sumU3, _sumU4, _sumU5, _sumU6, _sumU7, _sumU8, _sumU9, _sumU10, _sumU11, _sumU12, _sumU13, _sumU14, _sumU15, _sumU16, _sumU17, _sumU18, _sumU19, _sumU20, _sumU21, _sumU22, _sumU23, _sumU24, _sumU25, _sumU26, _sumU27, _sumU28, _sumU29, _sumU30, _sumU31, _sumU32, _sumU33, _sumU34, _sumU35, _sumU36, _sumU37, _sumU38, _sumU39, sumU0, sumU1, sumU2, sumU3, sumU4, sumU5, sumU6, sumU7, sumU8, sumU9, sumU10, sumU11, sumU12, sumU13, sumU14, sumU15, sumU16, sumU17, sumU18, sumU19, sumU20, sumU21, sumU22, sumU23, sumU24, sumU25, sumU26, sumU27, sumU28, sumU29, sumU30, sumU31, sumU32, sumU33, sumU34, sumU35, sumU36, sumU37, sumU38, sumU39, _sumV0, _sumV1, _sumV2, _sumV3, _sumV4, _sumV5, _sumV6, _sumV7, _sumV8, _sumV9, _sumV10, _sumV11, _sumV12, _sumV13, _sumV14, _sumV15, _sumV16, _sumV17, _sumV18, _sumV19, _sumV20, _sumV21, _sumV22, _sumV23, _sumV24, _sumV25, _sumV26, _sumV27, _sumV28, _sumV29, _sumV30, _sumV31, _sumV32, _sumV33, _sumV34, _sumV35, _sumV36, _sumV37, _sumV38, _sumV39, sumV0, sumV1, sumV2, sumV3, sumV4, sumV5, sumV6, sumV7, sumV8, sumV9, sumV10, sumV11, sumV12, sumV13, sumV14, sumV15, sumV16, sumV17, sumV18, sumV19, sumV20, sumV21, sumV22, sumV23, sumV24, sumV25, sumV26, sumV27, sumV28, sumV29, sumV30, sumV31, sumV32, sumV33, sumV34, sumV35, sumV36, sumV37, sumV38, sumV39, isfull0);
				isfull0++;				
			}
			simisfull(similarity, setN, U, V, _sim0, _setN0, _sumU0, _sumV0, i, jjj0, numUsers, k, flg);
			simisfull(similarity, setN, U, V, _sim1, _setN1, _sumU1, _sumV1, i+1, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim2, _setN2, _sumU2, _sumV2, i+2, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim3, _setN3, _sumU3, _sumV3, i+3, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim4, _setN4, _sumU4, _sumV4, i+4, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim5, _setN5, _sumU5, _sumV5, i+5, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim6, _setN6, _sumU6, _sumV6, i+6, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim7, _setN7, _sumU7, _sumV7, i+7, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim8, _setN8, _sumU8, _sumV8, i+8, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim9, _setN9, _sumU9, _sumV9, i+9, jjj0, numUsers, k, flg);	
                        simisfull(similarity, setN, U, V, _sim10, _setN10, _sumU10, _sumV10, i+10, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim11, _setN11, _sumU11, _sumV11, i+11, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim12, _setN12, _sumU12, _sumV12, i+12, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim13, _setN13, _sumU13, _sumV13, i+13, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim14, _setN14, _sumU14, _sumV14, i+14, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim15, _setN15, _sumU15, _sumV15, i+15, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim16, _setN16, _sumU16, _sumV16, i+16, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim17, _setN17, _sumU17, _sumV17, i+17, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim18, _setN18, _sumU18, _sumV18, i+18, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim19, _setN19, _sumU19, _sumV19, i+19, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim20, _setN20, _sumU20, _sumV20, i+20, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim21, _setN21, _sumU21, _sumV21, i+21, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim22, _setN22, _sumU22, _sumV22, i+22, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim23, _setN23, _sumU23, _sumV23, i+23, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim24, _setN24, _sumU24, _sumV24, i+24, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim25, _setN25, _sumU25, _sumV25, i+25, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim26, _setN26, _sumU26, _sumV26, i+26, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim27, _setN27, _sumU27, _sumV27, i+27, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim28, _setN28, _sumU28, _sumV28, i+28, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim29, _setN29, _sumU29, _sumV29, i+29, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim30, _setN30, _sumU30, _sumV30, i+30, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim31, _setN31, _sumU31, _sumV31, i+31, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim32, _setN32, _sumU32, _sumV32, i+32, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim33, _setN33, _sumU33, _sumV33, i+33, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim34, _setN34, _sumU34, _sumV34, i+34, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim35, _setN35, _sumU35, _sumV35, i+35, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim36, _setN36, _sumU36, _sumV36, i+36, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim37, _setN37, _sumU37, _sumV37, i+37, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim38, _setN38, _sumU38, _sumV38, i+38, jjj0, numUsers, k, flg);
                        simisfull(similarity, setN, U, V, _sim39, _setN39, _sumU39, _sumV39, i+39, jjj0, numUsers, k, flg);
		}
	}
	_sum0=0;
	sumU0=0;
	sumV0=0;
	setN0=0;
	for(int i=ii;i<lmtindx;i++){
                for(int k=0;k<Item_tiles;k++){
                        jjj0=i+1;
                        isfull0=0;
                        pickUser(data, _user0, i, k, numItems);
                        for(int j=i+1;j<numUsers;j++){
                                if(isfull0==USER_SIZE){
                                        simisfull(similarity, setN, U, V, _sim0, _setN0, _sumU0, _sumV0, i, jjj0, numUsers, k, flg);
                                        isfull0=0;
                                        jjj0+=USER_SIZE;
                                }
                                pickNextUser(data, _data, j, k, numItems);
                                compute_Remaining_sim(_user0, _data, _sum0, sumU0, sumV0, setN0);
                                store_Remaining_sim(_sim0, _sum0, _setN0, setN0, _sumU0, sumU0, _sumV0, sumV0 ,isfull0);
                                isfull0++;

                        }
                        simisfull(similarity, setN, U, V, _sim0, _setN0, _sumU0, _sumV0, i, jjj0, numUsers, k, flg);
                }
        }	
}

void simisfull(float* similarity, int* setN, int* U, int* V, int _sim[USER_SIZE], int _set[USER_SIZE], int _sumU[USER_SIZE], int _sumV[USER_SIZE], int i, int jjj, int numUsers, int k, int flg){ 
       
	int temp_sim; 
	float ttemp_sim;
	int temp_setUV;
	int temp_numerator;
	int temp_denominator0, temp_denominator1;
        int jj=0;
	int temp_setN;
  	int tempU,tempV;
     	while ((jj<USER_SIZE)&&(jjj<numUsers)){
		//sum (product)
		temp_sim = similarity[i*numUsers + jjj];
                temp_sim += _sim[jj]; 
		ttemp_sim = temp_sim;
		//setN (common items)
		temp_setN = setN[i*numUsers+jjj];
		temp_setN += _set[jj];

		//U product
		tempU = U[i*numUsers+jjj];
		tempU += _sumU[jj];

		//V product
		tempV = V[i*numUsers+jjj];
		tempV += _sumV[jj];

		if(k==flg){
			temp_setUV = temp_setN;  
			if(temp_setUV>1){
				temp_numerator = temp_sim;
				temp_denominator0 = tempU;
				temp_denominator1 = tempV;
				ttemp_sim = temp_numerator/sqrt(temp_denominator0*temp_denominator1);
			}
			else{
				ttemp_sim = 0;
			}
		}
		
                similarity[i*numUsers + jjj] = ttemp_sim;
		U[i*numUsers+jjj] = tempU;
		V[i*numUsers+jjj] = tempV;
		setN[i*numUsers + jjj] = temp_setN;

                _sim[jj]=0;
		_set[jj]=0;
		_sumU[jj]=0;
		_sumV[jj]=0;
                jj++;
		jjj++;
        }
}
/*
void storeUV(int _sumU0[USER_SIZE], int _sumU1[USER_SIZE], int _sumU2[USER_SIZE], int _sumU3[USER_SIZE], int _sumU4[USER_SIZE], int _sumU5[USER_SIZE], int _sumU6[USER_SIZE], int _sumU7[USER_SIZE], int _sumU8[USER_SIZE], int _sumU9[USER_SIZE], int _sumU10[USER_SIZE], int _sumU11[USER_SIZE], int _sumU12[USER_SIZE], int _sumU13[USER_SIZE], int _sumU14[USER_SIZE], int _sumU15[USER_SIZE], int _sumU16[USER_SIZE], int _sumU17[USER_SIZE], int _sumU18[USER_SIZE], int _sumU19[USER_SIZE], int _sumU20[USER_SIZE], int _sumU21[USER_SIZE], int _sumU22[USER_SIZE], int _sumU23[USER_SIZE], int _sumU24[USER_SIZE], int _sumU25[USER_SIZE], int _sumU26[USER_SIZE], int _sumU27[USER_SIZE], int _sumU28[USER_SIZE], int _sumU29[USER_SIZE], int _sumU30[USER_SIZE], int _sumU31[USER_SIZE], int _sumU32[USER_SIZE], int _sumU33[USER_SIZE], int _sumU34[USER_SIZE], int _sumU35[USER_SIZE], int _sumU36[USER_SIZE], int _sumU37[USER_SIZE], int _sumU38[USER_SIZE], int _sumU39[USER_SIZE], int &sumU0, int &sumU1, int &sumU2, int &sumU3, int &sumU4, int &sumU5, int &sumU6, int &sumU7, int &sumU8, int &sumU9, int &sumU10, int &sumU11, int &sumU12, int &sumU13, int &sumU14, int &sumU15, int &sumU16, int &sumU17, int &sumU18, int &sumU19, int &sumU20, int &sumU21, int &sumU22, int &sumU23, int &sumU24, int &sumU25, int &sumU26, int &sumU27, int &sumU28, int &sumU29, int &sumU30, int &sumU31, int &sumU32, int &sumU33, int &sumU34, int &sumU35, int &sumU36, int &sumU37, int &sumU38, int &sumU39, int _sumV0[USER_SIZE], int _sumV1[USER_SIZE], int _sumV2[USER_SIZE], int _sumV3[USER_SIZE], int _sumV4[USER_SIZE], int _sumV5[USER_SIZE], int _sumV6[USER_SIZE], int _sumV7[USER_SIZE], int _sumV8[USER_SIZE], int _sumV9[USER_SIZE], int _sumV10[USER_SIZE], int _sumV11[USER_SIZE], int _sumV12[USER_SIZE], int _sumV13[USER_SIZE], int _sumV14[USER_SIZE], int _sumV15[USER_SIZE], int _sumV16[USER_SIZE], int _sumV17[USER_SIZE], int _sumV18[USER_SIZE], int _sumV19[USER_SIZE], int _sumV20[USER_SIZE], int _sumV21[USER_SIZE], int _sumV22[USER_SIZE], int _sumV23[USER_SIZE], int _sumV24[USER_SIZE], int _sumV25[USER_SIZE], int _sumV26[USER_SIZE], int _sumV27[USER_SIZE], int _sumV28[USER_SIZE], int _sumV29[USER_SIZE], int _sumV30[USER_SIZE], int _sumV31[USER_SIZE], int _sumV32[USER_SIZE], int _sumV33[USER_SIZE], int _sumV34[USER_SIZE], int _sumV35[USER_SIZE], int _sumV36[USER_SIZE], int _sumV37[USER_SIZE], int _sumV38[USER_SIZE], int _sumV39[USER_SIZE], int &sumV0, int &sumV1, int &sumV2, int &sumV3, int &sumV4, int &sumV5, int &sumV6, int &sumV7, int &sumV8, int &sumV9, int &sumV10, int &sumV11, int &sumV12, int &sumV13, int &sumV14, int &sumV15, int &sumV16, int &sumV17, int &sumV18, int &sumV19, int &sumV20, int &sumV21, int &sumV22, int &sumV23, int &sumV24, int &sumV25, int &sumV26, int &sumV27, int &sumV28, int &sumV29, int &sumV30, int &sumV31, int &sumV32, int &sumV33, int &sumV34, int &sumV35, int &sumV36, int &sumV37, int &sumV38, int &sumV39, int isfull){

// store ixi
        _sumU0[isfull]=sumU0;
        _sumU1[isfull]=sumU1;
        _sumU2[isfull]=sumU2;
        _sumU3[isfull]=sumU3;
        _sumU4[isfull]=sumU4;
        _sumU5[isfull]=sumU5;
        _sumU6[isfull]=sumU6;
        _sumU7[isfull]=sumU7;
        _sumU8[isfull]=sumU8;
        _sumU9[isfull]=sumU9;
        _sumU10[isfull]=sumU10;
        _sumU11[isfull]=sumU11;
        _sumU12[isfull]=sumU12;
        _sumU13[isfull]=sumU13;
        _sumU14[isfull]=sumU14;
        _sumU15[isfull]=sumU15;
        _sumU16[isfull]=sumU16;
        _sumU17[isfull]=sumU17;
        _sumU18[isfull]=sumU18;
        _sumU19[isfull]=sumU19;
        _sumU20[isfull]=sumU20;
        _sumU21[isfull]=sumU21;
        _sumU22[isfull]=sumU22;
        _sumU23[isfull]=sumU23;
        _sumU24[isfull]=sumU24;
        _sumU25[isfull]=sumU25;
        _sumU26[isfull]=sumU26;
        _sumU27[isfull]=sumU27;
        _sumU28[isfull]=sumU28;
        _sumU29[isfull]=sumU29;
        _sumU30[isfull]=sumU30;
        _sumU31[isfull]=sumU31;
        _sumU32[isfull]=sumU32;
        _sumU33[isfull]=sumU33;
        _sumU34[isfull]=sumU34;
        _sumU35[isfull]=sumU35;
        _sumU36[isfull]=sumU36;
        _sumU37[isfull]=sumU37;
        _sumU38[isfull]=sumU38;
        _sumU39[isfull]=sumU39;
        sumU0=0;
        sumU1=0;
        sumU2=0;
        sumU3=0;
        sumU4=0;
        sumU5=0;
        sumU6=0;
        sumU7=0;
        sumU8=0;
        sumU9=0;
        sumU10=0;
        sumU11=0;
        sumU12=0;
        sumU13=0;
        sumU14=0;
        sumU15=0;
        sumU16=0;
        sumU17=0;
        sumU18=0;
        sumU19=0;
        sumU20=0;
        sumU21=0;
        sumU22=0;
        sumU23=0;
        sumU24=0;
        sumU25=0;
        sumU26=0;
        sumU27=0;
        sumU28=0;
        sumU29=0;
        sumU30=0;
        sumU31=0;
        sumU32=0;
        sumU33=0;
        sumU34=0;
        sumU35=0;
        sumU36=0;
        sumU37=0;
        sumU38=0;
        sumU39=0;
//store jxj
        _sumV0[isfull]=sumV0;
        _sumV1[isfull]=sumV1;
        _sumV2[isfull]=sumV2;
        _sumV3[isfull]=sumV3;
        _sumV4[isfull]=sumV4;
        _sumV5[isfull]=sumV5;
        _sumV6[isfull]=sumV6;
        _sumV7[isfull]=sumV7;
        _sumV8[isfull]=sumV8;
        _sumV9[isfull]=sumV9;
        _sumV10[isfull]=sumV10;
        _sumV11[isfull]=sumV11;
        _sumV12[isfull]=sumV12;
        _sumV13[isfull]=sumV13;
        _sumV14[isfull]=sumV14;
        _sumV15[isfull]=sumV15;
        _sumV16[isfull]=sumV16;
        _sumV17[isfull]=sumV17;
        _sumV18[isfull]=sumV18;
        _sumV19[isfull]=sumV19;
        _sumV20[isfull]=sumV20;
        _sumV21[isfull]=sumV21;
        _sumV22[isfull]=sumV22;
        _sumV23[isfull]=sumV23;
        _sumV24[isfull]=sumV24;
        _sumV25[isfull]=sumV25;
        _sumV26[isfull]=sumV26;
        _sumV27[isfull]=sumV27;
        _sumV28[isfull]=sumV28;
        _sumV29[isfull]=sumV29;
        _sumV30[isfull]=sumV30;
        _sumV31[isfull]=sumV31;
        _sumV32[isfull]=sumV32;
        _sumV33[isfull]=sumV33;
        _sumV34[isfull]=sumV34;
        _sumV35[isfull]=sumV35;
        _sumV36[isfull]=sumV36;
        _sumV37[isfull]=sumV37;
        _sumV38[isfull]=sumV38;
        _sumV39[isfull]=sumV39;
        sumV0=0;
        sumV1=0;
        sumV2=0;
        sumV3=0;
        sumV4=0;
        sumV5=0;
        sumV6=0;
        sumV7=0;
        sumV8=0;
        sumV9=0;
        sumV10=0;
        sumV11=0;
        sumV12=0;
        sumV13=0;
        sumV14=0;
        sumV15=0;
        sumV16=0;
        sumV17=0;
        sumV18=0;
        sumV19=0;
        sumV20=0;
        sumV21=0;
        sumV22=0;
        sumV23=0;
        sumV24=0;
        sumV25=0;
        sumV26=0;
        sumV27=0;
        sumV28=0;
        sumV29=0;
        sumV30=0;
        sumV31=0;
        sumV32=0;
        sumV33=0;
        sumV34=0;
        sumV35=0;
        sumV36=0;
        sumV37=0;
        sumV38=0;
        sumV39=0;
}
*/
void store(int _sim0[USER_SIZE], int _sim1[USER_SIZE], int _sim2[USER_SIZE], int _sim3[USER_SIZE], int _sim4[USER_SIZE], int _sim5[USER_SIZE], int _sim6[USER_SIZE], int _sim7[USER_SIZE], int _sim8[USER_SIZE], int _sim9[USER_SIZE], int _sim10[USER_SIZE], int _sim11[USER_SIZE], int _sim12[USER_SIZE], int _sim13[USER_SIZE], int _sim14[USER_SIZE], int _sim15[USER_SIZE], int _sim16[USER_SIZE], int _sim17[USER_SIZE], int _sim18[USER_SIZE], int _sim19[USER_SIZE], int _sim20[USER_SIZE], int _sim21[USER_SIZE], int _sim22[USER_SIZE], int _sim23[USER_SIZE], int _sim24[USER_SIZE], int _sim25[USER_SIZE], int _sim26[USER_SIZE], int _sim27[USER_SIZE], int _sim28[USER_SIZE], int _sim29[USER_SIZE], int _sim30[USER_SIZE], int _sim31[USER_SIZE], int _sim32[USER_SIZE], int _sim33[USER_SIZE], int _sim34[USER_SIZE], int _sim35[USER_SIZE], int _sim36[USER_SIZE], int _sim37[USER_SIZE], int _sim38[USER_SIZE], int _sim39[USER_SIZE], int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39, int _setN0[USER_SIZE], int _setN1[USER_SIZE], int _setN2[USER_SIZE], int _setN3[USER_SIZE], int _setN4[USER_SIZE], int _setN5[USER_SIZE], int _setN6[USER_SIZE], int _setN7[USER_SIZE], int _setN8[USER_SIZE], int _setN9[USER_SIZE], int _setN10[USER_SIZE], int _setN11[USER_SIZE], int _setN12[USER_SIZE], int _setN13[USER_SIZE], int _setN14[USER_SIZE], int _setN15[USER_SIZE], int _setN16[USER_SIZE], int _setN17[USER_SIZE], int _setN18[USER_SIZE], int _setN19[USER_SIZE], int _setN20[USER_SIZE], int _setN21[USER_SIZE], int _setN22[USER_SIZE], int _setN23[USER_SIZE], int _setN24[USER_SIZE], int _setN25[USER_SIZE], int _setN26[USER_SIZE], int _setN27[USER_SIZE], int _setN28[USER_SIZE], int _setN29[USER_SIZE], int _setN30[USER_SIZE], int _setN31[USER_SIZE], int _setN32[USER_SIZE], int _setN33[USER_SIZE], int _setN34[USER_SIZE], int _setN35[USER_SIZE], int _setN36[USER_SIZE], int _setN37[USER_SIZE], int _setN38[USER_SIZE], int _setN39[USER_SIZE], int &setN0, int &setN1, int &setN2, int &setN3, int &setN4, int &setN5, int &setN6, int &setN7, int &setN8, int &setN9, int &setN10, int &setN11, int &setN12, int &setN13, int &setN14, int &setN15, int &setN16, int &setN17, int &setN18, int &setN19, int &setN20, int &setN21, int &setN22, int &setN23, int &setN24, int &setN25, int &setN26, int &setN27, int &setN28, int &setN29, int &setN30, int &setN31, int &setN32, int &setN33, int &setN34, int &setN35, int &setN36, int &setN37, int &setN38, int &setN39, int _sumU0[USER_SIZE], int _sumU1[USER_SIZE], int _sumU2[USER_SIZE], int _sumU3[USER_SIZE], int _sumU4[USER_SIZE], int _sumU5[USER_SIZE], int _sumU6[USER_SIZE], int _sumU7[USER_SIZE], int _sumU8[USER_SIZE], int _sumU9[USER_SIZE], int _sumU10[USER_SIZE], int _sumU11[USER_SIZE], int _sumU12[USER_SIZE], int _sumU13[USER_SIZE], int _sumU14[USER_SIZE], int _sumU15[USER_SIZE], int _sumU16[USER_SIZE], int _sumU17[USER_SIZE], int _sumU18[USER_SIZE], int _sumU19[USER_SIZE], int _sumU20[USER_SIZE], int _sumU21[USER_SIZE], int _sumU22[USER_SIZE], int _sumU23[USER_SIZE], int _sumU24[USER_SIZE], int _sumU25[USER_SIZE], int _sumU26[USER_SIZE], int _sumU27[USER_SIZE], int _sumU28[USER_SIZE], int _sumU29[USER_SIZE], int _sumU30[USER_SIZE], int _sumU31[USER_SIZE], int _sumU32[USER_SIZE], int _sumU33[USER_SIZE], int _sumU34[USER_SIZE], int _sumU35[USER_SIZE], int _sumU36[USER_SIZE], int _sumU37[USER_SIZE], int _sumU38[USER_SIZE], int _sumU39[USER_SIZE], int &sumU0, int &sumU1, int &sumU2, int &sumU3, int &sumU4, int &sumU5, int &sumU6, int &sumU7, int &sumU8, int &sumU9, int &sumU10, int &sumU11, int &sumU12, int &sumU13, int &sumU14, int &sumU15, int &sumU16, int &sumU17, int &sumU18, int &sumU19, int &sumU20, int &sumU21, int &sumU22, int &sumU23, int &sumU24, int &sumU25, int &sumU26, int &sumU27, int &sumU28, int &sumU29, int &sumU30, int &sumU31, int &sumU32, int &sumU33, int &sumU34, int &sumU35, int &sumU36, int &sumU37, int &sumU38, int &sumU39, int _sumV0[USER_SIZE], int _sumV1[USER_SIZE], int _sumV2[USER_SIZE], int _sumV3[USER_SIZE], int _sumV4[USER_SIZE], int _sumV5[USER_SIZE], int _sumV6[USER_SIZE], int _sumV7[USER_SIZE], int _sumV8[USER_SIZE], int _sumV9[USER_SIZE], int _sumV10[USER_SIZE], int _sumV11[USER_SIZE], int _sumV12[USER_SIZE], int _sumV13[USER_SIZE], int _sumV14[USER_SIZE], int _sumV15[USER_SIZE], int _sumV16[USER_SIZE], int _sumV17[USER_SIZE], int _sumV18[USER_SIZE], int _sumV19[USER_SIZE], int _sumV20[USER_SIZE], int _sumV21[USER_SIZE], int _sumV22[USER_SIZE], int _sumV23[USER_SIZE], int _sumV24[USER_SIZE], int _sumV25[USER_SIZE], int _sumV26[USER_SIZE], int _sumV27[USER_SIZE], int _sumV28[USER_SIZE], int _sumV29[USER_SIZE], int _sumV30[USER_SIZE], int _sumV31[USER_SIZE], int _sumV32[USER_SIZE], int _sumV33[USER_SIZE], int _sumV34[USER_SIZE], int _sumV35[USER_SIZE], int _sumV36[USER_SIZE], int _sumV37[USER_SIZE], int _sumV38[USER_SIZE], int _sumV39[USER_SIZE], int &sumV0, int &sumV1, int &sumV2, int &sumV3, int &sumV4, int &sumV5, int &sumV6, int &sumV7, int &sumV8, int &sumV9, int &sumV10, int &sumV11, int &sumV12, int &sumV13, int &sumV14, int &sumV15, int &sumV16, int &sumV17, int &sumV18, int &sumV19, int &sumV20, int &sumV21, int &sumV22, int &sumV23, int &sumV24, int &sumV25, int &sumV26, int &sumV27, int &sumV28, int &sumV29, int &sumV30, int &sumV31, int &sumV32, int &sumV33, int &sumV34, int &sumV35, int &sumV36, int &sumV37, int &sumV38, int &sumV39, int isfull){ 
	//store ixj
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

	//store # of common items
	_setN0[isfull]=setN0;
        _setN1[isfull]=setN1;
        _setN2[isfull]=setN2;
        _setN3[isfull]=setN3;
        _setN4[isfull]=setN4;
        _setN5[isfull]=setN5;
        _setN6[isfull]=setN6;
        _setN7[isfull]=setN7;
        _setN8[isfull]=setN8;
        _setN9[isfull]=setN9;
        _setN10[isfull]=setN10;
        _setN11[isfull]=setN11;
        _setN12[isfull]=setN12;
        _setN13[isfull]=setN13;
        _setN14[isfull]=setN14;
        _setN15[isfull]=setN15;
        _setN16[isfull]=setN16;
        _setN17[isfull]=setN17;
        _setN18[isfull]=setN18;
        _setN19[isfull]=setN19;
        _setN20[isfull]=setN20;
        _setN21[isfull]=setN21;
        _setN22[isfull]=setN22;
        _setN23[isfull]=setN23;
        _setN24[isfull]=setN24;
        _setN25[isfull]=setN25;
        _setN26[isfull]=setN26;
        _setN27[isfull]=setN27;
        _setN28[isfull]=setN28;
        _setN29[isfull]=setN29;
        _setN30[isfull]=setN30;
        _setN31[isfull]=setN31;
        _setN32[isfull]=setN32;
        _setN33[isfull]=setN33;
        _setN34[isfull]=setN34;
        _setN35[isfull]=setN35;
        _setN36[isfull]=setN36;
        _setN37[isfull]=setN37;
        _setN38[isfull]=setN38;
        _setN39[isfull]=setN39;
	setN0=0;
        setN1=0;
        setN2=0;
        setN3=0;
        setN4=0;
        setN5=0;
        setN6=0;
        setN7=0;
        setN8=0;
        setN9=0;	
        setN10=0;
        setN11=0;
        setN12=0;
        setN13=0;
        setN14=0;
        setN15=0;
        setN16=0;
        setN17=0;
        setN18=0;
        setN19=0;
        setN20=0;
        setN21=0;
        setN22=0;
        setN23=0;
        setN24=0;
        setN25=0;
        setN26=0;
        setN27=0;
        setN28=0;
        setN29=0;
        setN30=0;
        setN31=0;
        setN32=0;
        setN33=0;
        setN34=0;
        setN35=0;
        setN36=0;
        setN37=0;
        setN38=0;
        setN39=0;
// store ixi
        _sumU0[isfull]=sumU0;
        _sumU1[isfull]=sumU1;
        _sumU2[isfull]=sumU2;
        _sumU3[isfull]=sumU3;
        _sumU4[isfull]=sumU4;
        _sumU5[isfull]=sumU5;
        _sumU6[isfull]=sumU6;
        _sumU7[isfull]=sumU7;
        _sumU8[isfull]=sumU8;
        _sumU9[isfull]=sumU9;
        _sumU10[isfull]=sumU10;
        _sumU11[isfull]=sumU11;
        _sumU12[isfull]=sumU12;
        _sumU13[isfull]=sumU13;
        _sumU14[isfull]=sumU14;
        _sumU15[isfull]=sumU15;
        _sumU16[isfull]=sumU16;
        _sumU17[isfull]=sumU17;
        _sumU18[isfull]=sumU18;
        _sumU19[isfull]=sumU19;
        _sumU20[isfull]=sumU20;
        _sumU21[isfull]=sumU21;
        _sumU22[isfull]=sumU22;
        _sumU23[isfull]=sumU23;
        _sumU24[isfull]=sumU24;
        _sumU25[isfull]=sumU25;
        _sumU26[isfull]=sumU26;
        _sumU27[isfull]=sumU27;
        _sumU28[isfull]=sumU28;
        _sumU29[isfull]=sumU29;
        _sumU30[isfull]=sumU30;
        _sumU31[isfull]=sumU31;
        _sumU32[isfull]=sumU32;
        _sumU33[isfull]=sumU33;
        _sumU34[isfull]=sumU34;
        _sumU35[isfull]=sumU35;
        _sumU36[isfull]=sumU36;
        _sumU37[isfull]=sumU37;
        _sumU38[isfull]=sumU38;
        _sumU39[isfull]=sumU39;
        sumU0=0;
        sumU1=0;
        sumU2=0;
        sumU3=0;
        sumU4=0;
        sumU5=0;
        sumU6=0;
        sumU7=0;
        sumU8=0;
        sumU9=0;
        sumU10=0;
        sumU11=0;
        sumU12=0;
        sumU13=0;
        sumU14=0;
        sumU15=0;
        sumU16=0;
        sumU17=0;
        sumU18=0;
        sumU19=0;
        sumU20=0;
        sumU21=0;
        sumU22=0;
        sumU23=0;
        sumU24=0;
        sumU25=0;
        sumU26=0;
        sumU27=0;
        sumU28=0;
        sumU29=0;
        sumU30=0;
        sumU31=0;
        sumU32=0;
        sumU33=0;
        sumU34=0;
        sumU35=0;
        sumU36=0;
        sumU37=0;
        sumU38=0;
        sumU39=0;

//store jxj
        _sumV0[isfull]=sumV0;
        _sumV1[isfull]=sumV1;
        _sumV2[isfull]=sumV2;
        _sumV3[isfull]=sumV3;
        _sumV4[isfull]=sumV4;
        _sumV5[isfull]=sumV5;
        _sumV6[isfull]=sumV6;
        _sumV7[isfull]=sumV7;
        _sumV8[isfull]=sumV8;
        _sumV9[isfull]=sumV9;
        _sumV10[isfull]=sumV10;
        _sumV11[isfull]=sumV11;
        _sumV12[isfull]=sumV12;
        _sumV13[isfull]=sumV13;
        _sumV14[isfull]=sumV14;
        _sumV15[isfull]=sumV15;
        _sumV16[isfull]=sumV16;
        _sumV17[isfull]=sumV17;
        _sumV18[isfull]=sumV18;
        _sumV19[isfull]=sumV19;
        _sumV20[isfull]=sumV20;
        _sumV21[isfull]=sumV21;
        _sumV22[isfull]=sumV22;
        _sumV23[isfull]=sumV23;
        _sumV24[isfull]=sumV24;
        _sumV25[isfull]=sumV25;
        _sumV26[isfull]=sumV26;
        _sumV27[isfull]=sumV27;
        _sumV28[isfull]=sumV28;
        _sumV29[isfull]=sumV29;
        _sumV30[isfull]=sumV30;
        _sumV31[isfull]=sumV31;
        _sumV32[isfull]=sumV32;
        _sumV33[isfull]=sumV33;
        _sumV34[isfull]=sumV34;
        _sumV35[isfull]=sumV35;
        _sumV36[isfull]=sumV36;
        _sumV37[isfull]=sumV37;
        _sumV38[isfull]=sumV38;
        _sumV39[isfull]=sumV39;
        sumV0=0;
        sumV1=0;
        sumV2=0;
        sumV3=0;
        sumV4=0;
        sumV5=0;
        sumV6=0;
        sumV7=0;
        sumV8=0;
        sumV9=0;
        sumV10=0;
        sumV11=0;
        sumV12=0;
        sumV13=0;
        sumV14=0;
        sumV15=0;
        sumV16=0;
        sumV17=0;
        sumV18=0;
        sumV19=0;
        sumV20=0;
        sumV21=0;
        sumV22=0;
        sumV23=0;
        sumV24=0;
        sumV25=0;
        sumV26=0;
        sumV27=0;
        sumV28=0;
        sumV29=0;
        sumV30=0;
        sumV31=0;
        sumV32=0;
        sumV33=0;
        sumV34=0;
        sumV35=0;
        sumV36=0;
        sumV37=0;
        sumV38=0;
        sumV39=0;
}

void store_Remaining_sim(int _sim0[USER_SIZE], int &_sum0, int _setN0[USER_SIZE], int &setN0, int _sumU0[USER_SIZE], int &sumU0, int _sumV0[USER_SIZE], int &sumV0, int isfull){    

        _sim0[isfull]=_sum0;
        _sum0=0;

        _sumU0[isfull]=sumU0;
        sumU0=0;

        _sumV0[isfull]=sumV0;
        sumV0=0;

        _setN0[isfull]=setN0;
        setN0=0;
}
void compute_Remaining_sim(int _user0[ITEM_SIZE], stream_data_fifo &_data, int &_sum0, int &sumU0, int &sumV0, int &setN0){
        int temp_user0;
        int temp_data;

        compute_Remaining_sim: for(int i=0;i<ITEM_SIZE;i++){
        #pragma HLS PIPELINE
//        #pragma HLS UNROLL factor=2
                temp_user0 = _user0[i];
                _data>>temp_data;
                if((temp_user0!=0)&&(temp_data!=0)){
                        _sum0+= temp_user0*temp_data;
                        sumU0+=temp_user0*temp_user0;
                        sumV0+=temp_data*temp_data;
                        setN0++;
                }
        }
}

void compute_sim(int _user0[ITEM_SIZE], int _user1[ITEM_SIZE], int _user2[ITEM_SIZE], int _user3[ITEM_SIZE], int _user4[ITEM_SIZE], int _user5[ITEM_SIZE], int _user6[ITEM_SIZE], int _user7[ITEM_SIZE], int _user8[ITEM_SIZE], int _user9[ITEM_SIZE], int _user10[ITEM_SIZE], int _user11[ITEM_SIZE], int _user12[ITEM_SIZE], int _user13[ITEM_SIZE], int _user14[ITEM_SIZE], int _user15[ITEM_SIZE], int _user16[ITEM_SIZE], int _user17[ITEM_SIZE], int _user18[ITEM_SIZE], int _user19[ITEM_SIZE], int _user20[ITEM_SIZE], int _user21[ITEM_SIZE], int _user22[ITEM_SIZE], int _user23[ITEM_SIZE], int _user24[ITEM_SIZE], int _user25[ITEM_SIZE], int _user26[ITEM_SIZE], int _user27[ITEM_SIZE], int _user28[ITEM_SIZE], int _user29[ITEM_SIZE], int _user30[ITEM_SIZE], int _user31[ITEM_SIZE], int _user32[ITEM_SIZE], int _user33[ITEM_SIZE], int _user34[ITEM_SIZE], int _user35[ITEM_SIZE], int _user36[ITEM_SIZE], int _user37[ITEM_SIZE], int _user38[ITEM_SIZE], int _user39[ITEM_SIZE], stream_data_fifo &_data, int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39, int &sumU0, int &sumU1, int &sumU2, int &sumU3, int &sumU4, int &sumU5, int &sumU6, int &sumU7, int &sumU8, int &sumU9, int &sumU10, int &sumU11, int &sumU12, int &sumU13, int &sumU14, int &sumU15, int &sumU16, int &sumU17, int &sumU18, int &sumU19, int &sumU20, int &sumU21, int &sumU22, int &sumU23, int &sumU24, int &sumU25, int &sumU26, int &sumU27, int &sumU28, int &sumU29, int &sumU30, int &sumU31, int &sumU32, int &sumU33, int &sumU34, int &sumU35, int &sumU36, int &sumU37, int &sumU38, int &sumU39, int &sumV0, int &sumV1, int &sumV2, int &sumV3, int &sumV4, int &sumV5, int &sumV6, int &sumV7, int &sumV8, int &sumV9, int &sumV10, int &sumV11, int &sumV12, int &sumV13, int &sumV14, int &sumV15, int &sumV16, int &sumV17, int &sumV18, int &sumV19, int &sumV20, int &sumV21, int &sumV22, int &sumV23, int &sumV24, int &sumV25, int &sumV26, int &sumV27, int &sumV28, int &sumV29, int &sumV30, int &sumV31, int &sumV32, int &sumV33, int &sumV34, int &sumV35, int &sumV36, int &sumV37, int &sumV38, int &sumV39, int &setN0, int &setN1, int &setN2, int &setN3, int &setN4, int &setN5, int &setN6, int &setN7, int &setN8, int &setN9, int &setN10, int &setN11, int &setN12, int &setN13, int &setN14, int &setN15, int &setN16, int &setN17, int &setN18, int &setN19,int &setN20, int &setN21, int &setN22, int &setN23, int &setN24, int &setN25, int &setN26, int &setN27, int &setN28, int &setN29,int &setN30, int &setN31, int &setN32, int &setN33, int &setN34, int &setN35, int &setN36, int &setN37, int &setN38, int &setN39){
        int temp_user0, temp_user1, temp_user2, temp_user3, temp_user4, temp_user5, temp_user6, temp_user7, temp_user8, temp_user9, temp_user10, temp_user11, temp_user12, temp_user13, temp_user14, temp_user15, temp_user16, temp_user17, temp_user18, temp_user19, temp_user20, temp_user21, temp_user22, temp_user23, temp_user24, temp_user25, temp_user26, temp_user27, temp_user28, temp_user29, temp_user30, temp_user31, temp_user32, temp_user33, temp_user34, temp_user35, temp_user36, temp_user37, temp_user38, temp_user39;
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
		_data>>temp_data;
		if((temp_user0!=0)&&(temp_data!=0)){
			_sum0+= temp_user0*temp_data;
			sumU0+=temp_user0*temp_user0;
			sumV0+=temp_data*temp_data;
			setN0++;
		}
		if((temp_user1!=0)&&(temp_data!=0)){
                        _sum1+= temp_user1*temp_data;
                        sumU1+=temp_user1*temp_user1;
                        sumV1+=temp_data*temp_data;
                        setN1++;
                }
                if((temp_user2!=0)&&(temp_data!=0)){
                        _sum2+= temp_user2*temp_data;
                        sumU2+=temp_user2*temp_user2;
                        sumV2+=temp_data*temp_data;
                        setN2++;
                }
                if((temp_user3!=0)&&(temp_data!=0)){
                        _sum3+= temp_user3*temp_data;
                        sumU3+=temp_user3*temp_user3;
                        sumV3+=temp_data*temp_data;
                        setN3++;
                }
                if((temp_user4!=0)&&(temp_data!=0)){
                        _sum4+= temp_user4*temp_data;
                        sumU4+=temp_user4*temp_user4;
                        sumV4+=temp_data*temp_data;
                        setN4++;
                }
                if((temp_user5!=0)&&(temp_data!=0)){
                        _sum5+= temp_user5*temp_data;
                        sumU5+=temp_user5*temp_user5;
                        sumV5+=temp_data*temp_data;
                        setN5++;
                }
                if((temp_user6!=0)&&(temp_data!=0)){
                        _sum6+= temp_user6*temp_data;
                        sumU6+=temp_user6*temp_user6;
                        sumV6+=temp_data*temp_data;
                        setN6++;
                }
                if((temp_user7!=0)&&(temp_data!=0)){
                        _sum7+= temp_user7*temp_data;
                        sumU7+=temp_user7*temp_user7;
                        sumV7+=temp_data*temp_data;
                        setN7++;
                }
                if((temp_user8!=0)&&(temp_data!=0)){
                        _sum8+= temp_user8*temp_data;
                        sumU8+=temp_user8*temp_user8;
                        sumV8+=temp_data*temp_data;
                        setN8++;
                }
                if((temp_user9!=0)&&(temp_data!=0)){
                        _sum9+= temp_user9*temp_data;
                        sumU9+=temp_user9*temp_user9;
                        sumV9+=temp_data*temp_data;
                        setN9++;
                }
		if((temp_user10!=0)&&(temp_data!=0)){
                        _sum10+= temp_user10*temp_data;
                        sumU10+=temp_user10*temp_user10;
                        sumV10+=temp_data*temp_data;
                        setN10++;
                }
                if((temp_user11!=0)&&(temp_data!=0)){
                        _sum11+= temp_user11*temp_data;
                        sumU11+=temp_user11*temp_user11;
                        sumV11+=temp_data*temp_data;
                        setN11++;
                }
                if((temp_user12!=0)&&(temp_data!=0)){
                        _sum12+= temp_user12*temp_data;
                        sumU12+=temp_user12*temp_user12;
                        sumV12+=temp_data*temp_data;
                        setN12++;
                }
                if((temp_user13!=0)&&(temp_data!=0)){
                        _sum13+= temp_user13*temp_data;
                        sumU13+=temp_user13*temp_user13;
                        sumV13+=temp_data*temp_data;
                        setN13++;
                }
                if((temp_user14!=0)&&(temp_data!=0)){
                        _sum14+= temp_user14*temp_data;
                        sumU14+=temp_user14*temp_user14;
                        sumV14+=temp_data*temp_data;
                        setN14++;
                }
                if((temp_user15!=0)&&(temp_data!=0)){
                        _sum15+= temp_user15*temp_data;
                        sumU15+=temp_user15*temp_user15;
                        sumV15+=temp_data*temp_data;
                        setN15++;
                }
                if((temp_user16!=0)&&(temp_data!=0)){
                        _sum16+= temp_user16*temp_data;
                        sumU16+=temp_user16*temp_user16;
                        sumV16+=temp_data*temp_data;
                        setN16++;
                }
                if((temp_user17!=0)&&(temp_data!=0)){
                        _sum17+= temp_user17*temp_data;
                        sumU17+=temp_user17*temp_user17;
                        sumV17+=temp_data*temp_data;
                        setN17++;
                }
                if((temp_user18!=0)&&(temp_data!=0)){
                        _sum18+= temp_user18*temp_data;
                        sumU18+=temp_user18*temp_user18;
                        sumV18+=temp_data*temp_data;
                        setN18++;
                }
                if((temp_user19!=0)&&(temp_data!=0)){
                        _sum19+= temp_user19*temp_data;
                        sumU19+=temp_user19*temp_user19;
                        sumV19+=temp_data*temp_data;
                        setN19++;
                }
	
		if((temp_user20!=0)&&(temp_data!=0)){
                        _sum20+= temp_user20*temp_data;
                        sumU20+=temp_user20*temp_user20;
                        sumV20+=temp_data*temp_data;
                        setN20++;
                }
                if((temp_user21!=0)&&(temp_data!=0)){
                        _sum21+= temp_user21*temp_data;
                        sumU21+=temp_user21*temp_user21;
                        sumV21+=temp_data*temp_data;
                        setN21++;
                }
                if((temp_user22!=0)&&(temp_data!=0)){
                        _sum22+= temp_user22*temp_data;
                        sumU22+=temp_user22*temp_user22;
                        sumV22+=temp_data*temp_data;
                        setN22++;
                }
                if((temp_user23!=0)&&(temp_data!=0)){
                        _sum23+= temp_user23*temp_data;
                        sumU23+=temp_user23*temp_user23;
                        sumV23+=temp_data*temp_data;
                        setN23++;
                }
                if((temp_user24!=0)&&(temp_data!=0)){
                        _sum24+= temp_user24*temp_data;
                        sumU24+=temp_user24*temp_user24;
                        sumV24+=temp_data*temp_data;
                        setN24++;
                }
                if((temp_user25!=0)&&(temp_data!=0)){
                        _sum25+= temp_user25*temp_data;
                        sumU25+=temp_user25*temp_user25;
                        sumV25+=temp_data*temp_data;
                        setN25++;
                }
                if((temp_user26!=0)&&(temp_data!=0)){
                        _sum26+= temp_user26*temp_data;
                        sumU26+=temp_user26*temp_user26;
                        sumV26+=temp_data*temp_data;
                        setN26++;
                }
                if((temp_user27!=0)&&(temp_data!=0)){
                        _sum27+= temp_user27*temp_data;
                        sumU27+=temp_user27*temp_user27;
                        sumV27+=temp_data*temp_data;
                        setN27++;
                }
                if((temp_user28!=0)&&(temp_data!=0)){
                        _sum28+= temp_user28*temp_data;
                        sumU28+=temp_user28*temp_user28;
                        sumV28+=temp_data*temp_data;
                        setN28++;
                }
                if((temp_user29!=0)&&(temp_data!=0)){
                        _sum29+= temp_user29*temp_data;
                        sumU29+=temp_user29*temp_user29;
                        sumV29+=temp_data*temp_data;
                        setN29++;
                }
                if((temp_user30!=0)&&(temp_data!=0)){
                        _sum30+= temp_user30*temp_data;
                        sumU30+=temp_user30*temp_user30;
                        sumV30+=temp_data*temp_data;
                        setN30++;
                }
		if((temp_user31!=0)&&(temp_data!=0)){
                        _sum31+= temp_user31*temp_data;
                        sumU31+=temp_user31*temp_user31;
                        sumV31+=temp_data*temp_data;
                        setN31++;
                }
                if((temp_user32!=0)&&(temp_data!=0)){
                        _sum32+= temp_user32*temp_data;
                        sumU32+=temp_user32*temp_user32;
                        sumV32+=temp_data*temp_data;
                        setN32++;
                }
                if((temp_user33!=0)&&(temp_data!=0)){
                        _sum33+= temp_user33*temp_data;
                        sumU33+=temp_user33*temp_user33;
                        sumV33+=temp_data*temp_data;
                        setN33++;
                }
                if((temp_user34!=0)&&(temp_data!=0)){
                        _sum34+= temp_user34*temp_data;
                        sumU34+=temp_user34*temp_user34;
                        sumV34+=temp_data*temp_data;
                        setN34++;
                }
                if((temp_user35!=0)&&(temp_data!=0)){
                        _sum35+= temp_user35*temp_data;
                        sumU35+=temp_user35*temp_user35;
                        sumV35+=temp_data*temp_data;
                        setN35++;
                }
                if((temp_user36!=0)&&(temp_data!=0)){
                        _sum36+= temp_user36*temp_data;
                        sumU36+=temp_user36*temp_user36;
                        sumV36+=temp_data*temp_data;
                        setN36++;
                }
                if((temp_user37!=0)&&(temp_data!=0)){
                        _sum37+= temp_user37*temp_data;
                        sumU37+=temp_user37*temp_user37;
                        sumV37+=temp_data*temp_data;
                        setN37++;
                }
                if((temp_user38!=0)&&(temp_data!=0)){
                        _sum38+= temp_user38*temp_data;
                        sumU38+=temp_user38*temp_user38;
                        sumV38+=temp_data*temp_data;
                        setN38++;
                }
                if((temp_user39!=0)&&(temp_data!=0)){
                        _sum39+= temp_user39*temp_data;
                        sumU39+=temp_user39*temp_user39;
                        sumV39+=temp_data*temp_data;
                        setN39++;
                }

	}
}




