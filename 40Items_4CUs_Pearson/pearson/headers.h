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
#define ITEM_SIZE 943//1510  // 841
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
void initialize_data(float* data, float* similarity, float* U, float* V, int* setN, int numUsers, int numItems);
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
void write_sim(float* similarity_software, int set_of_U[USOF], float set_of_V[USOF], float set_of_UV[USOF], int common[USOF], int i, int j, int numUsers);
void clear(float set_of_U[USOF], float set_of_V[USOF], float set_of_UV[USOF], int common[USOF]);
void calc_sim(float* data, float set_of_U[USOF], float set_of_V[USOF], float set_of_UV[USOF], int common[USOF], int i, int j, int k, int numItems);
//hardware.cpp ~LEARNING PHASE
typedef float DTYPE;
typedef hls::stream<DTYPE> stream_data_fifo;

#pragma SDS data zero_copy(data[0:numUsers*numItems],similarity[0:numUsers*numUsers], setN[0:numUsers*numUsers], U[0:numUsers*numUsers], V[0:numUsers*numUsers])
void toplevelHW_learn(float* data, float* similarity, int* setN , float* U, float* V, int numUsers, int numItems, int indx, int lmtindx);
void pickUser(float* data, float _user0[ITEM_SIZE], int i, int k,int numItems);
void pickNextUser(float* data, stream_data_fifo &_data, int j, int k, int numItems);
void simisfull(float* similarity, int* setN, float* U, float* V, float _sim[USER_SIZE], int _set[USER_SIZE], float _sumU[USER_SIZE], float _sumV[USER_SIZE], int i, int jjj, int numUsers, int k, int flg);

void store(float _sim0[USER_SIZE], float _sim1[USER_SIZE], float _sim2[USER_SIZE], float _sim3[USER_SIZE], float _sim4[USER_SIZE], float _sim5[USER_SIZE], float _sim6[USER_SIZE], float _sim7[USER_SIZE], float _sim8[USER_SIZE], float _sim9[USER_SIZE], float _sim10[USER_SIZE], float _sim11[USER_SIZE], float _sim12[USER_SIZE], float _sim13[USER_SIZE], float _sim14[USER_SIZE], float _sim15[USER_SIZE], float _sim16[USER_SIZE], float _sim17[USER_SIZE], float _sim18[USER_SIZE], float _sim19[USER_SIZE], float _sim20[USER_SIZE], float _sim21[USER_SIZE], float _sim22[USER_SIZE], float _sim23[USER_SIZE], float _sim24[USER_SIZE], float _sim25[USER_SIZE], float _sim26[USER_SIZE], float _sim27[USER_SIZE], float _sim28[USER_SIZE], float _sim29[USER_SIZE], float _sim30[USER_SIZE], float _sim31[USER_SIZE], float _sim32[USER_SIZE], float _sim33[USER_SIZE], float _sim34[USER_SIZE], float _sim35[USER_SIZE], float _sim36[USER_SIZE], float _sim37[USER_SIZE], float _sim38[USER_SIZE], float _sim39[USER_SIZE], float &_sum0, float &_sum1, float &_sum2, float &_sum3, float &_sum4, float &_sum5, float &_sum6, float &_sum7, float &_sum8, float &_sum9, float &_sum10, float &_sum11, float &_sum12, float &_sum13, float &_sum14, float &_sum15, float &_sum16, float &_sum17, float &_sum18, float &_sum19, float &_sum20, float &_sum21, float &_sum22, float &_sum23, float &_sum24, float &_sum25, float &_sum26, float &_sum27, float &_sum28, float &_sum29, float &_sum30, float &_sum31, float &_sum32, float &_sum33, float &_sum34, float &_sum35, float &_sum36, float &_sum37, float &_sum38, float &_sum39, int _setN0[USER_SIZE], int _setN1[USER_SIZE], int _setN2[USER_SIZE], int _setN3[USER_SIZE], int _setN4[USER_SIZE], int _setN5[USER_SIZE], int _setN6[USER_SIZE], int _setN7[USER_SIZE], int _setN8[USER_SIZE], int _setN9[USER_SIZE], int _setN10[USER_SIZE], int _setN11[USER_SIZE], int _setN12[USER_SIZE], int _setN13[USER_SIZE], int _setN14[USER_SIZE], int _setN15[USER_SIZE], int _setN16[USER_SIZE], int _setN17[USER_SIZE], int _setN18[USER_SIZE], int _setN19[USER_SIZE], int _setN20[USER_SIZE], int _setN21[USER_SIZE], int _setN22[USER_SIZE], int _setN23[USER_SIZE], int _setN24[USER_SIZE], int _setN25[USER_SIZE], int _setN26[USER_SIZE], int _setN27[USER_SIZE], int _setN28[USER_SIZE], int _setN29[USER_SIZE], int _setN30[USER_SIZE], int _setN31[USER_SIZE], int _setN32[USER_SIZE], int _setN33[USER_SIZE], int _setN34[USER_SIZE], int _setN35[USER_SIZE], int _setN36[USER_SIZE], int _setN37[USER_SIZE], int _setN38[USER_SIZE], int _setN39[USER_SIZE], int &setN0, int &setN1, int &setN2, int &setN3, int &setN4, int &setN5, int &setN6, int &setN7, int &setN8, int &setN9, int &setN10, int &setN11, int &setN12, int &setN13, int &setN14, int &setN15, int &setN16, int &setN17, int &setN18, int &setN19, int &setN20, int &setN21, int &setN22, int &setN23, int &setN24, int &setN25, int &setN26, int &setN27, int &setN28, int &setN29, int &setN30, int &setN31, int &setN32, int &setN33, int &setN34, int &setN35, int &setN36, int &setN37, int &setN38, int &setN39, float _sumU0[USER_SIZE], float _sumU1[USER_SIZE], float _sumU2[USER_SIZE], float _sumU3[USER_SIZE], float _sumU4[USER_SIZE], float _sumU5[USER_SIZE], float _sumU6[USER_SIZE], float _sumU7[USER_SIZE], float _sumU8[USER_SIZE], float _sumU9[USER_SIZE], float _sumU10[USER_SIZE], float _sumU11[USER_SIZE], float _sumU12[USER_SIZE], float _sumU13[USER_SIZE], float _sumU14[USER_SIZE], float _sumU15[USER_SIZE], float _sumU16[USER_SIZE], float _sumU17[USER_SIZE], float _sumU18[USER_SIZE], float _sumU19[USER_SIZE], float _sumU20[USER_SIZE], float _sumU21[USER_SIZE], float _sumU22[USER_SIZE], float _sumU23[USER_SIZE], float _sumU24[USER_SIZE], float _sumU25[USER_SIZE], float _sumU26[USER_SIZE], float _sumU27[USER_SIZE], float _sumU28[USER_SIZE], float _sumU29[USER_SIZE], float _sumU30[USER_SIZE], float _sumU31[USER_SIZE], float _sumU32[USER_SIZE], float _sumU33[USER_SIZE], float _sumU34[USER_SIZE], float _sumU35[USER_SIZE], float _sumU36[USER_SIZE], float _sumU37[USER_SIZE], float _sumU38[USER_SIZE], float _sumU39[USER_SIZE], float &sumU0, float &sumU1, float &sumU2, float &sumU3, float &sumU4, float &sumU5, float &sumU6, float &sumU7, float &sumU8, float &sumU9, float &sumU10, float &sumU11, float &sumU12, float &sumU13, float &sumU14, float &sumU15, float &sumU16, float &sumU17, float &sumU18, float &sumU19, float &sumU20, float &sumU21, float &sumU22, float &sumU23, float &sumU24, float &sumU25, float &sumU26, float &sumU27, float &sumU28, float &sumU29, float &sumU30, float &sumU31, float &sumU32, float &sumU33, float &sumU34, float &sumU35, float &sumU36, float &sumU37, float &sumU38, float &sumU39, float _sumV0[USER_SIZE], float _sumV1[USER_SIZE], float _sumV2[USER_SIZE], float _sumV3[USER_SIZE], float _sumV4[USER_SIZE], float _sumV5[USER_SIZE], float _sumV6[USER_SIZE], float _sumV7[USER_SIZE], float _sumV8[USER_SIZE], float _sumV9[USER_SIZE], float _sumV10[USER_SIZE], float _sumV11[USER_SIZE], float _sumV12[USER_SIZE], float _sumV13[USER_SIZE], float _sumV14[USER_SIZE], float _sumV15[USER_SIZE], float _sumV16[USER_SIZE], float _sumV17[USER_SIZE], float _sumV18[USER_SIZE], float _sumV19[USER_SIZE], float _sumV20[USER_SIZE], float _sumV21[USER_SIZE], float _sumV22[USER_SIZE], float _sumV23[USER_SIZE], float _sumV24[USER_SIZE], float _sumV25[USER_SIZE], float _sumV26[USER_SIZE], float _sumV27[USER_SIZE], float _sumV28[USER_SIZE], float _sumV29[USER_SIZE], float _sumV30[USER_SIZE], float _sumV31[USER_SIZE], float _sumV32[USER_SIZE], float _sumV33[USER_SIZE], float _sumV34[USER_SIZE], float _sumV35[USER_SIZE], float _sumV36[USER_SIZE], float _sumV37[USER_SIZE], float _sumV38[USER_SIZE], float _sumV39[USER_SIZE], float &sumV0, float &sumV1, float &sumV2, float &sumV3, float &sumV4, float &sumV5, float &sumV6, float &sumV7, float &sumV8, float &sumV9, float &sumV10, float &sumV11, float &sumV12, float &sumV13, float &sumV14, float &sumV15, float &sumV16, float &sumV17, float &sumV18, float &sumV19, float &sumV20, float &sumV21, float &sumV22, float &sumV23, float &sumV24, float &sumV25, float &sumV26, float &sumV27, float &sumV28, float &sumV29, float &sumV30, float &sumV31, float &sumV32, float &sumV33, float &sumV34, float &sumV35, float &sumV36, float &sumV37, float &sumV38, float &sumV39, int isfull);

void store_Remaining_sim(float _sim0[USER_SIZE], float &_sum0, int _setN0[USER_SIZE], int &setN0, float _sumU0[USER_SIZE], float &sumU0, float _sumV0[USER_SIZE], float &sumV0, int isfull);

void compute_Remaining_sim(float _user0[ITEM_SIZE], stream_data_fifo &_data, float &_sum0, float &sumU0, float &sumV0, int &setN0);

void compute_sim(float _user0[ITEM_SIZE], float _user1[ITEM_SIZE], float _user2[ITEM_SIZE], float _user3[ITEM_SIZE], float _user4[ITEM_SIZE], float _user5[ITEM_SIZE], float _user6[ITEM_SIZE], float _user7[ITEM_SIZE], float _user8[ITEM_SIZE], float _user9[ITEM_SIZE], float _user10[ITEM_SIZE], float _user11[ITEM_SIZE], float _user12[ITEM_SIZE], float _user13[ITEM_SIZE], float _user14[ITEM_SIZE], float _user15[ITEM_SIZE], float _user16[ITEM_SIZE], float _user17[ITEM_SIZE], float _user18[ITEM_SIZE], float _user19[ITEM_SIZE], float _user20[ITEM_SIZE], float _user21[ITEM_SIZE], float _user22[ITEM_SIZE], float _user23[ITEM_SIZE], float _user24[ITEM_SIZE], float _user25[ITEM_SIZE], float _user26[ITEM_SIZE], float _user27[ITEM_SIZE], float _user28[ITEM_SIZE], float _user29[ITEM_SIZE], float _user30[ITEM_SIZE], float _user31[ITEM_SIZE], float _user32[ITEM_SIZE], float _user33[ITEM_SIZE], float _user34[ITEM_SIZE], float _user35[ITEM_SIZE], float _user36[ITEM_SIZE], float _user37[ITEM_SIZE], float _user38[ITEM_SIZE], float _user39[ITEM_SIZE], stream_data_fifo &_data, float &_sum0, float &_sum1, float &_sum2, float &_sum3, float &_sum4, float &_sum5, float &_sum6, float &_sum7, float &_sum8, float &_sum9, float &_sum10, float &_sum11, float &_sum12, float &_sum13, float &_sum14, float &_sum15, float &_sum16, float &_sum17, float &_sum18, float &_sum19, float &_sum20, float &_sum21, float &_sum22, float &_sum23, float &_sum24, float &_sum25, float &_sum26, float &_sum27, float &_sum28, float &_sum29, float &_sum30, float &_sum31, float &_sum32, float &_sum33, float &_sum34, float &_sum35, float &_sum36, float &_sum37, float &_sum38, float &_sum39, float &sumU0, float &sumU1, float &sumU2, float &sumU3, float &sumU4, float &sumU5, float &sumU6, float &sumU7, float &sumU8, float &sumU9, float &sumU10, float &sumU11, float &sumU12, float &sumU13, float &sumU14, float &sumU15, float &sumU16, float &sumU17, float &sumU18, float &sumU19, float &sumU20, float &sumU21, float &sumU22, float &sumU23, float &sumU24, float &sumU25, float &sumU26, float &sumU27, float &sumU28, float &sumU29, float &sumU30, float &sumU31, float &sumU32, float &sumU33, float &sumU34, float &sumU35, float &sumU36, float &sumU37, float &sumU38, float &sumU39, float &sumV0, float &sumV1, float &sumV2, float &sumV3, float &sumV4, float &sumV5, float &sumV6, float &sumV7, float &sumV8, float &sumV9, float &sumV10, float &sumV11, float &sumV12, float &sumV13, float &sumV14, float &sumV15, float &sumV16, float &sumV17, float &sumV18, float &sumV19, float &sumV20, float &sumV21, float &sumV22, float &sumV23, float &sumV24, float &sumV25, float &sumV26, float &sumV27, float &sumV28, float &sumV29, float &sumV30, float &sumV31, float &sumV32, float &sumV33, float &sumV34, float &sumV35, float &sumV36, float &sumV37, float &sumV38, float &sumV39, int &setN0, int &setN1, int &setN2, int &setN3, int &setN4, int &setN5, int &setN6, int &setN7, int &setN8, int &setN9, int &setN10, int &setN11, int &setN12, int &setN13, int &setN14, int &setN15, int &setN16, int &setN17, int &setN18, int &setN19,int &setN20, int &setN21, int &setN22, int &setN23, int &setN24, int &setN25, int &setN26, int &setN27, int &setN28, int &setN29,int &setN30, int &setN31, int &setN32, int &setN33, int &setN34, int &setN35, int &setN36, int &setN37, int &setN38, int &setN39);
#endif