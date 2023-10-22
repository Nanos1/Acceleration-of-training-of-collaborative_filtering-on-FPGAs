#ifndef HEADERS_H
#define HEADERS_H
#include<stdio.h>
#include<stdlib.h>
#include "Structs.h"
#include <hls_stream.h>

#define __SDSOC__

#ifdef __SDCOC__
#include "sds_lib.h"
#endif

#define knn_max 20
#define USER_SIZE 230  //if no CUs471 else input of acc : lmtindx-indx
#define ITEM_SIZE 841  // 841
#define USOF 40
//ReadData.c
int fileExists(char* fileName);
int findNumberofEntries(FILE*);
void getDataFile(FILE*, char*, entryData*);
void stupid_get_data(entryData*);
//functions.c
int hw_sw_sol(float* similarity_software, float* similarity, int numUsers);
void up_triang(float* similarity, int numUsers);
void sim_knn_calc(float* similarity, int*  knn, float* sim_knn, int numUsers);
void knn_calc(float* similarity, float* similarity1, int* knn, int numUsers);
void readtabledata(entryData*, float* data, int, int, int);
int compareUsers(const void*, const void*);
int compareItems(const void*, const void*);
//debug.c
int checkdataset(entryData*, entryData*, int);
void debug1(entryData*, entryData*, int);
void debug2(int, int);
void debug3(float* data, int, int);
void debug4(int* knn,int,int);
//software.cpp
void learn_software(float* data, float* similarity_software, int numUsers, int numItems);
void write_sim(float* similarity_software, int set_of_U[USOF], int set_of_V[USOF], int set_of_UV[USOF], int common[USOF], int i, int j, int numUsers);
void clear(int set_of_U[USOF], int set_of_V[USOF], int set_of_UV[USOF], int common[USOF]);
void calc_sim(float* data, int set_of_U[USOF], int set_of_V[USOF], int set_of_UV[USOF], int common[USOF], int i, int j, int k, int numItems);
//hardware.cpp ~LEARNING PHASE
typedef int DTYPE;
typedef hls::stream<DTYPE> stream_data_fifo;

#pragma SDS data zero_copy(data[0:numUsers*numItems],similarity[0:numUsers*numUsers], setN[0:numUsers*numUsers], U[0:numUsers*numUsers], V[0:numUsers*numUsers])
void toplevelHW_learn(float* data, float* similarity, int* setN , int* U, int* V, int numUsers, int numItems, int indx, int lmtindx);
void pickUser(float* data, int _user0[ITEM_SIZE], int i, int k,int numItems);
void pickNextUser(float* data, stream_data_fifo &_data, int j, int k, int numItems);
void simisfull(float* similarity, int* setN, int* U, int* V, int _sim[USER_SIZE], int _set[USER_SIZE], int _sumU[USER_SIZE], int _sumV[USER_SIZE], int i, int jjj, int numUsers, int k, int flg);
//void storeUV(int _sumU0[USER_SIZE], int _sumU1[USER_SIZE], int _sumU2[USER_SIZE], int _sumU3[USER_SIZE], int _sumU4[USER_SIZE], int _sumU5[USER_SIZE], int _sumU6[USER_SIZE], int _sumU7[USER_SIZE], int _sumU8[USER_SIZE], int _sumU9[USER_SIZE], int _sumU10[USER_SIZE], int _sumU11[USER_SIZE], int _sumU12[USER_SIZE], int _sumU13[USER_SIZE], int _sumU14[USER_SIZE], int _sumU15[USER_SIZE], int _sumU16[USER_SIZE], int _sumU17[USER_SIZE], int _sumU18[USER_SIZE], int _sumU19[USER_SIZE], int _sumU20[USER_SIZE], int _sumU21[USER_SIZE], int _sumU22[USER_SIZE], int _sumU23[USER_SIZE], int _sumU24[USER_SIZE], int _sumU25[USER_SIZE], int _sumU26[USER_SIZE], int _sumU27[USER_SIZE], int _sumU28[USER_SIZE], int _sumU29[USER_SIZE], int _sumU30[USER_SIZE], int _sumU31[USER_SIZE], int _sumU32[USER_SIZE], int _sumU33[USER_SIZE], int _sumU34[USER_SIZE], int _sumU35[USER_SIZE], int _sumU36[USER_SIZE], int _sumU37[USER_SIZE], int _sumU38[USER_SIZE], int _sumU39[USER_SIZE], int &sumU0, int &sumU1, int &sumU2, int &sumU3, int &sumU4, int &sumU5, int &sumU6, int &sumU7, int &sumU8, int &sumU9, int &sumU10, int &sumU11, int &sumU12, int &sumU13, int &sumU14, int &sumU15, int &sumU16, int &sumU17, int &sumU18, int &sumU19, int &sumU20, int &sumU21, int &sumU22, int &sumU23, int &sumU24, int &sumU25, int &sumU26, int &sumU27, int &sumU28, int &sumU29, int &sumU30, int &sumU31, int &sumU32, int &sumU33, int &sumU34, int &sumU35, int &sumU36, int &sumU37, int &sumU38, int &sumU39, int _sumV0[USER_SIZE], int _sumV1[USER_SIZE], int _sumV2[USER_SIZE], int _sumV3[USER_SIZE], int _sumV4[USER_SIZE], int _sumV5[USER_SIZE], int _sumV6[USER_SIZE], int _sumV7[USER_SIZE], int _sumV8[USER_SIZE], int _sumV9[USER_SIZE], int _sumV10[USER_SIZE], int _sumV11[USER_SIZE], int _sumV12[USER_SIZE], int _sumV13[USER_SIZE], int _sumV14[USER_SIZE], int _sumV15[USER_SIZE], int _sumV16[USER_SIZE], int _sumV17[USER_SIZE], int _sumV18[USER_SIZE], int _sumV19[USER_SIZE], int _sumV20[USER_SIZE], int _sumV21[USER_SIZE], int _sumV22[USER_SIZE], int _sumV23[USER_SIZE], int _sumV24[USER_SIZE], int _sumV25[USER_SIZE], int _sumV26[USER_SIZE], int _sumV27[USER_SIZE], int _sumV28[USER_SIZE], int _sumV29[USER_SIZE], int _sumV30[USER_SIZE], int _sumV31[USER_SIZE], int _sumV32[USER_SIZE], int _sumV33[USER_SIZE], int _sumV34[USER_SIZE], int _sumV35[USER_SIZE], int _sumV36[USER_SIZE], int _sumV37[USER_SIZE], int _sumV38[USER_SIZE], int _sumV39[USER_SIZE], int &sumV0, int &sumV1, int &sumV2, int &sumV3, int &sumV4, int &sumV5, int &sumV6, int &sumV7, int &sumV8, int &sumV9, int &sumV10, int &sumV11, int &sumV12, int &sumV13, int &sumV14, int &sumV15, int &sumV16, int &sumV17, int &sumV18, int &sumV19, int &sumV20, int &sumV21, int &sumV22, int &sumV23, int &sumV24, int &sumV25, int &sumV26, int &sumV27, int &sumV28, int &sumV29, int &sumV30, int &sumV31, int &sumV32, int &sumV33, int &sumV34, int &sumV35, int &sumV36, int &sumV37, int &sumV38, int &sumV39, int isfull);

//void store(int _sim0[USER_SIZE], int _sim1[USER_SIZE], int _sim2[USER_SIZE], int _sim3[USER_SIZE], int _sim4[USER_SIZE], int _sim5[USER_SIZE], int _sim6[USER_SIZE], int _sim7[USER_SIZE], int _sim8[USER_SIZE], int _sim9[USER_SIZE], int _sim10[USER_SIZE], int _sim11[USER_SIZE], int _sim12[USER_SIZE], int _sim13[USER_SIZE], int _sim14[USER_SIZE], int _sim15[USER_SIZE], int _sim16[USER_SIZE], int _sim17[USER_SIZE], int _sim18[USER_SIZE], int _sim19[USER_SIZE], int _sim20[USER_SIZE], int _sim21[USER_SIZE], int _sim22[USER_SIZE], int _sim23[USER_SIZE], int _sim24[USER_SIZE], int _sim25[USER_SIZE], int _sim26[USER_SIZE], int _sim27[USER_SIZE], int _sim28[USER_SIZE], int _sim29[USER_SIZE], int _sim30[USER_SIZE], int _sim31[USER_SIZE], int _sim32[USER_SIZE], int _sim33[USER_SIZE], int _sim34[USER_SIZE], int _sim35[USER_SIZE], int _sim36[USER_SIZE], int _sim37[USER_SIZE], int _sim38[USER_SIZE], int _sim39[USER_SIZE], int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39, int _setN0[USER_SIZE], int _setN1[USER_SIZE], int _setN2[USER_SIZE], int _setN3[USER_SIZE], int _setN4[USER_SIZE], int _setN5[USER_SIZE], int _setN6[USER_SIZE], int _setN7[USER_SIZE], int _setN8[USER_SIZE], int _setN9[USER_SIZE], int _setN10[USER_SIZE], int _setN11[USER_SIZE], int _setN12[USER_SIZE], int _setN13[USER_SIZE], int _setN14[USER_SIZE], int _setN15[USER_SIZE], int _setN16[USER_SIZE], int _setN17[USER_SIZE], int _setN18[USER_SIZE], int _setN19[USER_SIZE], int _setN20[USER_SIZE], int _setN21[USER_SIZE], int _setN22[USER_SIZE], int _setN23[USER_SIZE], int _setN24[USER_SIZE], int _setN25[USER_SIZE], int _setN26[USER_SIZE], int _setN27[USER_SIZE], int _setN28[USER_SIZE], int _setN29[USER_SIZE], int _setN30[USER_SIZE], int _setN31[USER_SIZE], int _setN32[USER_SIZE], int _setN33[USER_SIZE], int _setN34[USER_SIZE], int _setN35[USER_SIZE], int _setN36[USER_SIZE], int _setN37[USER_SIZE], int _setN38[USER_SIZE], int _setN39[USER_SIZE], int &setN0, int &setN1, int &setN2, int &setN3, int &setN4, int &setN5, int &setN6, int &setN7, int &setN8, int &setN9, int &setN10, int &setN11, int &setN12, int &setN13, int &setN14, int &setN15, int &setN16, int &setN17, int &setN18, int &setN19, int &setN20, int &setN21, int &setN22, int &setN23, int &setN24, int &setN25, int &setN26, int &setN27, int &setN28, int &setN29, int &setN30, int &setN31, int &setN32, int &setN33, int &setN34, int &setN35, int &setN36, int &setN37, int &setN38, int &setN39, int isfull);
void store(int _sim0[USER_SIZE], int _sim1[USER_SIZE], int _sim2[USER_SIZE], int _sim3[USER_SIZE], int _sim4[USER_SIZE], int _sim5[USER_SIZE], int _sim6[USER_SIZE], int _sim7[USER_SIZE], int _sim8[USER_SIZE], int _sim9[USER_SIZE], int _sim10[USER_SIZE], int _sim11[USER_SIZE], int _sim12[USER_SIZE], int _sim13[USER_SIZE], int _sim14[USER_SIZE], int _sim15[USER_SIZE], int _sim16[USER_SIZE], int _sim17[USER_SIZE], int _sim18[USER_SIZE], int _sim19[USER_SIZE], int _sim20[USER_SIZE], int _sim21[USER_SIZE], int _sim22[USER_SIZE], int _sim23[USER_SIZE], int _sim24[USER_SIZE], int _sim25[USER_SIZE], int _sim26[USER_SIZE], int _sim27[USER_SIZE], int _sim28[USER_SIZE], int _sim29[USER_SIZE], int _sim30[USER_SIZE], int _sim31[USER_SIZE], int _sim32[USER_SIZE], int _sim33[USER_SIZE], int _sim34[USER_SIZE], int _sim35[USER_SIZE], int _sim36[USER_SIZE], int _sim37[USER_SIZE], int _sim38[USER_SIZE], int _sim39[USER_SIZE], int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39, int _setN0[USER_SIZE], int _setN1[USER_SIZE], int _setN2[USER_SIZE], int _setN3[USER_SIZE], int _setN4[USER_SIZE], int _setN5[USER_SIZE], int _setN6[USER_SIZE], int _setN7[USER_SIZE], int _setN8[USER_SIZE], int _setN9[USER_SIZE], int _setN10[USER_SIZE], int _setN11[USER_SIZE], int _setN12[USER_SIZE], int _setN13[USER_SIZE], int _setN14[USER_SIZE], int _setN15[USER_SIZE], int _setN16[USER_SIZE], int _setN17[USER_SIZE], int _setN18[USER_SIZE], int _setN19[USER_SIZE], int _setN20[USER_SIZE], int _setN21[USER_SIZE], int _setN22[USER_SIZE], int _setN23[USER_SIZE], int _setN24[USER_SIZE], int _setN25[USER_SIZE], int _setN26[USER_SIZE], int _setN27[USER_SIZE], int _setN28[USER_SIZE], int _setN29[USER_SIZE], int _setN30[USER_SIZE], int _setN31[USER_SIZE], int _setN32[USER_SIZE], int _setN33[USER_SIZE], int _setN34[USER_SIZE], int _setN35[USER_SIZE], int _setN36[USER_SIZE], int _setN37[USER_SIZE], int _setN38[USER_SIZE], int _setN39[USER_SIZE], int &setN0, int &setN1, int &setN2, int &setN3, int &setN4, int &setN5, int &setN6, int &setN7, int &setN8, int &setN9, int &setN10, int &setN11, int &setN12, int &setN13, int &setN14, int &setN15, int &setN16, int &setN17, int &setN18, int &setN19, int &setN20, int &setN21, int &setN22, int &setN23, int &setN24, int &setN25, int &setN26, int &setN27, int &setN28, int &setN29, int &setN30, int &setN31, int &setN32, int &setN33, int &setN34, int &setN35, int &setN36, int &setN37, int &setN38, int &setN39, int _sumU0[USER_SIZE], int _sumU1[USER_SIZE], int _sumU2[USER_SIZE], int _sumU3[USER_SIZE], int _sumU4[USER_SIZE], int _sumU5[USER_SIZE], int _sumU6[USER_SIZE], int _sumU7[USER_SIZE], int _sumU8[USER_SIZE], int _sumU9[USER_SIZE], int _sumU10[USER_SIZE], int _sumU11[USER_SIZE], int _sumU12[USER_SIZE], int _sumU13[USER_SIZE], int _sumU14[USER_SIZE], int _sumU15[USER_SIZE], int _sumU16[USER_SIZE], int _sumU17[USER_SIZE], int _sumU18[USER_SIZE], int _sumU19[USER_SIZE], int _sumU20[USER_SIZE], int _sumU21[USER_SIZE], int _sumU22[USER_SIZE], int _sumU23[USER_SIZE], int _sumU24[USER_SIZE], int _sumU25[USER_SIZE], int _sumU26[USER_SIZE], int _sumU27[USER_SIZE], int _sumU28[USER_SIZE], int _sumU29[USER_SIZE], int _sumU30[USER_SIZE], int _sumU31[USER_SIZE], int _sumU32[USER_SIZE], int _sumU33[USER_SIZE], int _sumU34[USER_SIZE], int _sumU35[USER_SIZE], int _sumU36[USER_SIZE], int _sumU37[USER_SIZE], int _sumU38[USER_SIZE], int _sumU39[USER_SIZE], int &sumU0, int &sumU1, int &sumU2, int &sumU3, int &sumU4, int &sumU5, int &sumU6, int &sumU7, int &sumU8, int &sumU9, int &sumU10, int &sumU11, int &sumU12, int &sumU13, int &sumU14, int &sumU15, int &sumU16, int &sumU17, int &sumU18, int &sumU19, int &sumU20, int &sumU21, int &sumU22, int &sumU23, int &sumU24, int &sumU25, int &sumU26, int &sumU27, int &sumU28, int &sumU29, int &sumU30, int &sumU31, int &sumU32, int &sumU33, int &sumU34, int &sumU35, int &sumU36, int &sumU37, int &sumU38, int &sumU39, int _sumV0[USER_SIZE], int _sumV1[USER_SIZE], int _sumV2[USER_SIZE], int _sumV3[USER_SIZE], int _sumV4[USER_SIZE], int _sumV5[USER_SIZE], int _sumV6[USER_SIZE], int _sumV7[USER_SIZE], int _sumV8[USER_SIZE], int _sumV9[USER_SIZE], int _sumV10[USER_SIZE], int _sumV11[USER_SIZE], int _sumV12[USER_SIZE], int _sumV13[USER_SIZE], int _sumV14[USER_SIZE], int _sumV15[USER_SIZE], int _sumV16[USER_SIZE], int _sumV17[USER_SIZE], int _sumV18[USER_SIZE], int _sumV19[USER_SIZE], int _sumV20[USER_SIZE], int _sumV21[USER_SIZE], int _sumV22[USER_SIZE], int _sumV23[USER_SIZE], int _sumV24[USER_SIZE], int _sumV25[USER_SIZE], int _sumV26[USER_SIZE], int _sumV27[USER_SIZE], int _sumV28[USER_SIZE], int _sumV29[USER_SIZE], int _sumV30[USER_SIZE], int _sumV31[USER_SIZE], int _sumV32[USER_SIZE], int _sumV33[USER_SIZE], int _sumV34[USER_SIZE], int _sumV35[USER_SIZE], int _sumV36[USER_SIZE], int _sumV37[USER_SIZE], int _sumV38[USER_SIZE], int _sumV39[USER_SIZE], int &sumV0, int &sumV1, int &sumV2, int &sumV3, int &sumV4, int &sumV5, int &sumV6, int &sumV7, int &sumV8, int &sumV9, int &sumV10, int &sumV11, int &sumV12, int &sumV13, int &sumV14, int &sumV15, int &sumV16, int &sumV17, int &sumV18, int &sumV19, int &sumV20, int &sumV21, int &sumV22, int &sumV23, int &sumV24, int &sumV25, int &sumV26, int &sumV27, int &sumV28, int &sumV29, int &sumV30, int &sumV31, int &sumV32, int &sumV33, int &sumV34, int &sumV35, int &sumV36, int &sumV37, int &sumV38, int &sumV39, int isfull);
void store_Remaining_sim(int _sim0[USER_SIZE], int &_sum0, int _setN0[USER_SIZE], int &setN0, int _sumU0[USER_SIZE], int &sumU0, int _sumV0[USER_SIZE], int &sumV0, int isfull);
void compute_Remaining_sim(int _user0[ITEM_SIZE], stream_data_fifo &_data, int &_sum0, int &sumU0, int &sumV0, int &setN0);
void compute_sim(int _user0[ITEM_SIZE], int _user1[ITEM_SIZE], int _user2[ITEM_SIZE], int _user3[ITEM_SIZE], int _user4[ITEM_SIZE], int _user5[ITEM_SIZE], int _user6[ITEM_SIZE], int _user7[ITEM_SIZE], int _user8[ITEM_SIZE], int _user9[ITEM_SIZE], int _user10[ITEM_SIZE], int _user11[ITEM_SIZE], int _user12[ITEM_SIZE], int _user13[ITEM_SIZE], int _user14[ITEM_SIZE], int _user15[ITEM_SIZE], int _user16[ITEM_SIZE], int _user17[ITEM_SIZE], int _user18[ITEM_SIZE], int _user19[ITEM_SIZE], int _user20[ITEM_SIZE], int _user21[ITEM_SIZE], int _user22[ITEM_SIZE], int _user23[ITEM_SIZE], int _user24[ITEM_SIZE], int _user25[ITEM_SIZE], int _user26[ITEM_SIZE], int _user27[ITEM_SIZE], int _user28[ITEM_SIZE], int _user29[ITEM_SIZE], int _user30[ITEM_SIZE], int _user31[ITEM_SIZE], int _user32[ITEM_SIZE], int _user33[ITEM_SIZE], int _user34[ITEM_SIZE], int _user35[ITEM_SIZE], int _user36[ITEM_SIZE], int _user37[ITEM_SIZE], int _user38[ITEM_SIZE], int _user39[ITEM_SIZE], stream_data_fifo &_data, int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39, int &sumU0, int &sumU1, int &sumU2, int &sumU3, int &sumU4, int &sumU5, int &sumU6, int &sumU7, int &sumU8, int &sumU9, int &sumU10, int &sumU11, int &sumU12, int &sumU13, int &sumU14, int &sumU15, int &sumU16, int &sumU17, int &sumU18, int &sumU19, int &sumU20, int &sumU21, int &sumU22, int &sumU23, int &sumU24, int &sumU25, int &sumU26, int &sumU27, int &sumU28, int &sumU29, int &sumU30, int &sumU31, int &sumU32, int &sumU33, int &sumU34, int &sumU35, int &sumU36, int &sumU37, int &sumU38, int &sumU39, int &sumV0, int &sumV1, int &sumV2, int &sumV3, int &sumV4, int &sumV5, int &sumV6, int &sumV7, int &sumV8, int &sumV9, int &sumV10, int &sumV11, int &sumV12, int &sumV13, int &sumV14, int &sumV15, int &sumV16, int &sumV17, int &sumV18, int &sumV19, int &sumV20, int &sumV21, int &sumV22, int &sumV23, int &sumV24, int &sumV25, int &sumV26, int &sumV27, int &sumV28, int &sumV29, int &sumV30, int &sumV31, int &sumV32, int &sumV33, int &sumV34, int &sumV35, int &sumV36, int &sumV37, int &sumV38, int &sumV39, int &setN0, int &setN1, int &setN2, int &setN3, int &setN4, int &setN5, int &setN6, int &setN7, int &setN8, int &setN9, int &setN10, int &setN11, int &setN12, int &setN13, int &setN14, int &setN15, int &setN16, int &setN17, int &setN18, int &setN19,int &setN20, int &setN21, int &setN22, int &setN23, int &setN24, int &setN25, int &setN26, int &setN27, int &setN28, int &setN29,int &setN30, int &setN31, int &setN32, int &setN33, int &setN34, int &setN35, int &setN36, int &setN37, int &setN38, int &setN39);
#endif