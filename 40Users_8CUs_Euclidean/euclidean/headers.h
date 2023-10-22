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
void calculate_sum(float* data, float euclidean_sum[40], int set_UV[40], int i, int j, int k, int numItems);
void calculate_sim(float* similarity_software, float euclidean_sum[40], int set_UV[40], int i, int j, int numUsers);
void clear(int set_UV[40]);
void clearsum(float euclidean_sum[40]);
//hardware.cpp ~LEARNING PHASE
typedef int DTYPE;
typedef hls::stream<DTYPE> stream_data_fifo;

#pragma SDS data zero_copy(data[0:numUsers*numItems],similarity[0:numUsers*numUsers])
void toplevelHW_learn(float* data, float* similarity, int numUsers, int numItems, int indx , int lmtindx);
void pickNextUser(float* data, stream_data_fifo &_data, int j, int k,int numItems);
void pickUser(float* data, int _user0[ITEM_SIZE], int i, int k,int numItems);
void simisfull(float* similarity, int _sim[USER_SIZE], int i, int jjj, int numUsers, int k, int flg);
void write_sim(float* similarity, int _sim[USER_SIZE], int numUsers, int i);
void compute_sim(int _user0[ITEM_SIZE], int _user1[ITEM_SIZE], int _user2[ITEM_SIZE], int _user3[ITEM_SIZE], int _user4[ITEM_SIZE], int _user5[ITEM_SIZE], int _user6[ITEM_SIZE], int _user7[ITEM_SIZE], int _user8[ITEM_SIZE], int _user9[ITEM_SIZE], int _user10[ITEM_SIZE], int _user11[ITEM_SIZE], int _user12[ITEM_SIZE], int _user13[ITEM_SIZE], int _user14[ITEM_SIZE], int _user15[ITEM_SIZE], int _user16[ITEM_SIZE], int _user17[ITEM_SIZE], int _user18[ITEM_SIZE], int _user19[ITEM_SIZE], int _user20[ITEM_SIZE], int _user21[ITEM_SIZE], int _user22[ITEM_SIZE], int _user23[ITEM_SIZE], int _user24[ITEM_SIZE], int _user25[ITEM_SIZE], int _user26[ITEM_SIZE], int _user27[ITEM_SIZE], int _user28[ITEM_SIZE], int _user29[ITEM_SIZE], int _user30[ITEM_SIZE], int _user31[ITEM_SIZE], int _user32[ITEM_SIZE], int _user33[ITEM_SIZE], int _user34[ITEM_SIZE], int _user35[ITEM_SIZE], int _user36[ITEM_SIZE], int _user37[ITEM_SIZE], int _user38[ITEM_SIZE], int _user39[ITEM_SIZE], stream_data_fifo &_data, int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39);
void store_Remaining_sim(int _sim0[USER_SIZE], int &_sum0, int isfull);
void compute_Remaining_sim(int _user0[ITEM_SIZE], stream_data_fifo &_data, int &_sum0);
void store(int _sim0[USER_SIZE], int _sim1[USER_SIZE], int _sim2[USER_SIZE], int _sim3[USER_SIZE], int _sim4[USER_SIZE], int _sim5[USER_SIZE], int _sim6[USER_SIZE], int _sim7[USER_SIZE], int _sim8[USER_SIZE], int _sim9[USER_SIZE], int _sim10[USER_SIZE], int _sim11[USER_SIZE], int _sim12[USER_SIZE], int _sim13[USER_SIZE], int _sim14[USER_SIZE], int _sim15[USER_SIZE], int _sim16[USER_SIZE], int _sim17[USER_SIZE], int _sim18[USER_SIZE], int _sim19[USER_SIZE], int _sim20[USER_SIZE], int _sim21[USER_SIZE], int _sim22[USER_SIZE], int _sim23[USER_SIZE], int _sim24[USER_SIZE], int _sim25[USER_SIZE], int _sim26[USER_SIZE], int _sim27[USER_SIZE], int _sim28[USER_SIZE], int _sim29[USER_SIZE], int _sim30[USER_SIZE], int _sim31[USER_SIZE], int _sim32[USER_SIZE], int _sim33[USER_SIZE], int _sim34[USER_SIZE], int _sim35[USER_SIZE], int _sim36[USER_SIZE], int _sim37[USER_SIZE], int _sim38[USER_SIZE], int _sim39[USER_SIZE], int &_sum0, int &_sum1, int &_sum2, int &_sum3, int &_sum4, int &_sum5, int &_sum6, int &_sum7, int &_sum8, int &_sum9, int &_sum10, int &_sum11, int &_sum12, int &_sum13, int &_sum14, int &_sum15, int &_sum16, int &_sum17, int &_sum18, int &_sum19, int &_sum20, int &_sum21, int &_sum22, int &_sum23, int &_sum24, int &_sum25, int &_sum26, int &_sum27, int &_sum28, int &_sum29, int &_sum30, int &_sum31, int &_sum32, int &_sum33, int &_sum34, int &_sum35, int &_sum36, int &_sum37, int &_sum38, int &_sum39, int isfull);
/*
//hardware.c ~PREDICTING PHASE
#pragma SDS data zero_copy(data[0:numUsers*numItems],final_data[0:numUsers*numItems],knn[0:numUsers*knn_max],sim_knn[0:numUsers*knn_max])
void toplevelHW_predict(float* data, float* final_data, int* knn, float* sim_knn, int numUsers,int numItems);

void pickUser(float* data, float _user[ITEM_SIZE],int numItems, int user,int dataIndx);
void read_Knn_Data(float* data, int* knn, float _data[knn_max*ITEM_SIZE], int numUsers, int numItems, int u, int dataIndx);
void pickUserSim(float* sim_knn, float _sim[knn_max], int u);
void write_predictions(float* final_data, float _user[ITEM_SIZE], int numItems, int u, int &final_dataIndx);
void compute_predictions(float _data[knn_max*ITEM_SIZE], float _user[ITEM_SIZE], float _sim[knn_max], int numItems);
*/
#endif
