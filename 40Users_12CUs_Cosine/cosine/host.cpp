#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "headers.h"
#include "Structs.h"
#include <math.h>
#ifdef __SDSOC__
#include "sds_lib.h"
#endif

int main(int argc, char*argv[]){

#ifdef __SDSOC__
	unsigned long long int total_time_stamp;
	unsigned long long int total_no_read_stamp;
	unsigned long long int total_no_read;
  	unsigned long long int total_time;
	unsigned long long int finish_stamp;
	
	unsigned long long int total_accLearn_StartStamp;
	unsigned long long int total_accLearn_FinishStamp;
    	unsigned long long int total_accLearn;

    	unsigned long long int total_accPredict_StartStamp;
	unsigned long long int total_accPredict_FinishStamp;
    	unsigned long long int total_accPredict;

	unsigned long long int total_SoftwareLearn;
	unsigned long long int total_SoftwareLearn_StartStamp;
	unsigned long long int total_SoftwareLearn_FinishStamp;

	unsigned long long int total_SoftwarePredict;
	unsigned long long int total_SoftwarePredict_StartStamp;
	unsigned long long int total_SoftwarePredict_FinishStamp;

	float speedup;
	float speedup_per;
	float total_hw;
	float total_sw;

	total_time_stamp = sds_clock_counter();
#endif 

	char* 	fileName;
	char* 	delimiter;
	int 	nData,numItems=1,numUsers=1; 
	FILE* 	file;
	int 	debug;
	int itemsToRec;
	int loop_knn = knn_max;
	int flag;
	entryData* Du;
	entryData* Di;

	//-----Read Command line arguements-----
	fileName   = argv[1];
	delimiter  = argv[2];
	debug	   = atoi(argv[3]);
//	debug	   = atoi(argv[1]);
//	itemsToRec = atoi(argv[4]); 
	//-------------------------------------- 
	
	//-----Read Data From File--------------
	if(fileExists(fileName)){
		file = fopen(fileName,"r");
		
		if(file == NULL)
			return -1;
		
		nData = findNumberofEntries(file); // number of Entries
		fclose(file);
		
		Du = (entryData*)malloc(nData*sizeof(entryData));
		file = fopen(fileName,"r");
		
		if(file == NULL)
                	return -1;
		getDataFile(file,delimiter,Du);
		fclose(file);
	}
	else
		return -2;

#ifdef __SDSOC__
	total_no_read_stamp = sds_clock_counter();
#endif

//--------------------------------------
	Di = (entryData*)malloc(nData*sizeof(entryData));

	for(int i=0;i<nData;i++){
		Di[i] = Du[i];
	}
		
	qsort(Du,nData,sizeof(entryData),compareUsers);
	qsort(Di,nData,sizeof(entryData),compareItems);	
	
	//-----Debug----------------------------
	if(!checkdataset(Du,Di,nData))
		return -4;
	
	if(debug)
 		debug1(Du,Di,nData);
	
	for(int i=1;i<nData;i++){
		if(Du[i].rowUser!=Du[i-1].rowUser)
			numUsers++;
		if(Di[i].colItem!=Di[i-1].colItem)
			numItems++;
	}

	if(debug)
		debug2(numUsers,numItems);

	size_t data_matrix_size_bytes 	 	= sizeof(int) * numUsers * numItems;
	size_t sim_matrix_size_bytes  	 	= sizeof(int) * numUsers * numUsers;
	size_t simm_matrix_size_bytes 	 	= sizeof(int) * numUsers;
	size_t knn_matrix_size_bytes  	 	= sizeof(int) * numUsers * knn_max;
	size_t sim_knn_matrix_size_bytes 	= sizeof(int) * numUsers * knn_max;

	//START LEARNING------------------------
	printf("\nallocating data buffer\n");
	printf("allocating similarity buffer\n");
	printf("allocating knn buffer\n");
	printf("allocating recommender buffer\n");
	
	//ALLOCATE HARDWARE BUFFERS------------------------
	float	*data         	= (float*)sds_alloc(data_matrix_size_bytes);
	float   *similarity   	= (float*)sds_alloc(sim_matrix_size_bytes);
	float   *similarity1   	= (float*)sds_alloc(sim_matrix_size_bytes);
	int	*knn		= (int*)sds_alloc(knn_matrix_size_bytes);
	float 	*sim_knn	= (float*)sds_alloc(sim_knn_matrix_size_bytes);
//	float   *final_data     = (float*)sds_alloc(data_matrix_size_bytes);
	int   *setN                     = (int*)sds_alloc(simm_matrix_size_bytes);
	//ALLOCATE SOFTWARE BUFFERS------------------------
	float *similarity_software	= (float*)malloc(sim_matrix_size_bytes);	
    	float *similarity1_software    	= (float*)malloc(sim_matrix_size_bytes);
    	int   *knn_software            	= (int*)malloc(knn_matrix_size_bytes);
    	float *sim_knn_software        	= (float*)malloc(sim_knn_matrix_size_bytes);

	readtabledata(Du,data,nData,numUsers,numItems);
	free(Du);
	free(Di);

	if(debug){
		printf("\nthe initial data\n");		
		debug3(data,numUsers,numItems);
	}

	printf("\ncalculating similarities");		
	printf("\ncalculating K-nearest neighboors");
	printf("\ncalculating the predictions");	
	printf("\ncalculating the recommendations\n");

	for(int i=0;i<numUsers*numUsers;i++){
		similarity[i]=0;
	}

	//STARTING POINTS------------------------
	int indx1=0;
	int indx2=numUsers*1/4;
	int indx3=numUsers*2/4;
	int indx4=numUsers*3/4;

	//ENDING POINTS------------------------
	int lmtindx1=indx2+1; //236
	int lmtindx2=indx3;
	int lmtindx3=indx4;
	int lmtindx4=numUsers;

	//HARDWARE LEARN FUNCTION------------------------
#ifdef __SDSOC__
        total_accLearn_StartStamp = sds_clock_counter();
#endif
        #pragma SDS resource(1)
        #pragma SDS async(1);
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 0, 81);

        #pragma SDS resource(2)
        #pragma SDS async(2)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 81, 162);

        #pragma SDS resource(3)
        #pragma SDS async(3)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 162, 207);

        #pragma SDS resource(4)
        #pragma SDS async(4)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 207, 288);

        #pragma SDS resource(5)
        #pragma SDS async(5)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 288, 369);

        #pragma SDS resource(6)
        #pragma SDS async(6)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 369, 450);

        #pragma SDS resource(7)
        #pragma SDS async(7)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 450, 531);

        #pragma SDS resource(8)
        #pragma SDS async(8)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 531, 612);

        #pragma SDS resource(9)
        #pragma SDS async(9)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 612, 693);

        #pragma SDS resource(10)
        #pragma SDS async(10)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 693, 774);

        #pragma SDS resource(11)
        #pragma SDS async(11)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 774, 855);

        #pragma SDS resource(12)
        #pragma SDS async(12)
        toplevelHW_learn(data, similarity, setN, numUsers, numItems, 855, 943);

	#pragma SDS wait(1)
    	#pragma SDS wait(2)
        #pragma SDS wait(3)
        #pragma SDS wait(4)
        #pragma SDS wait(5)
        #pragma SDS wait(6)
        #pragma SDS wait(7)
        #pragma SDS wait(8)
        #pragma SDS wait(9)
        #pragma SDS wait(10)
        #pragma SDS wait(11)
        #pragma SDS wait(12)

#ifdef __SDSOC__
   	total_accLearn_FinishStamp = sds_clock_counter();
	total_accLearn = total_accLearn_FinishStamp - total_accLearn_StartStamp;
#endif
	up_triang(similarity, numUsers);
	
	//SOFTWARE LEARN FUNCTION------------------------
	total_SoftwareLearn_StartStamp = sds_clock_counter();
	learn_software(data, similarity_software, numUsers, numItems);
	total_SoftwareLearn_FinishStamp = sds_clock_counter();
	total_SoftwareLearn = total_SoftwareLearn_FinishStamp - total_SoftwareLearn_StartStamp;
	
	up_triang(similarity_software, numUsers);	
	
	if(debug){
		printf("\nhardware similarities\n");
		debug3(similarity, numUsers, numUsers);
		printf("\nsoftware similarities\n");
		debug3(similarity_software, numUsers, numUsers);
	}
	
	//CALCULATE KNN FOR HARDWARE SIMILARITIES------------------------
	knn_calc(similarity,similarity1, knn, numUsers);
	sds_free(similarity1);

	if(debug){
		printf("\nhardware knn users\n");
		debug4(knn,numUsers,loop_knn);	//loop_knn = knn_max
	}	
	
	//CALCULATE SIMILARITIES  OF KNN FOR HARDWARE------------------------
	sim_knn_calc(similarity, knn, sim_knn, numUsers);
	
	if(debug){
		printf("\nhardware similarities of knn users\n");
		debug3(sim_knn, numUsers, loop_knn);
	}

	//CALCULATE KNN FOR SOFTWARE SIMILARITIES------------------------
	knn_calc(similarity_software,similarity1_software, knn_software, numUsers);
	free(similarity1_software);
	
    	if(debug){
		printf("\nsoftware knn users\n");
        	debug4(knn_software,numUsers,loop_knn);  //loop_knn = knn_max
	}

	//CALCULATE SIMILARITIES  OF KNN FOR SOFTWARE------------------------
    	sim_knn_calc(similarity_software, knn_software, sim_knn_software, numUsers);

    	if(debug){
		printf("\nsoftware similarities of knn users\n");
        	debug3(sim_knn_software,numUsers, loop_knn);
	}

/*
#ifdef __SDSOC__
        total_no_accPredict_StartStamp = sds_clock_counter();
#endif

	toplevelHW_predict(data, final_data, knn, sim_knn, numUsers, numItems);

#ifdef __SDSOC__
        total_no_accPredict_FinishStamp = sds_clock_counter();
        total_no_accPredict = total_no_accPredict_FinishStamp - total_no_accPredict_StartStamp;
#endif
*/
/*
	if(debug){
		printf("\nthe final data\n");		
		debug3(final_data, numUsers, numItems);
	}
*/

	flag = hw_sw_sol(similarity_software, similarity, numUsers);
	if(flag)
		printf("\nHardware results & Software results are the same\n");
	 
#ifdef __SDSOC__
	finish_stamp 	= sds_clock_counter();
	total_time      = finish_stamp - total_time_stamp;
	total_no_read   = total_no_read_stamp - total_time_stamp;
	total_hw	= total_accLearn;
	total_sw	= total_SoftwareLearn;
	speedup 	= total_sw/total_hw;
	speedup_per	= (total_sw - total_hw)/total_hw*100;
	printf("\n-----------------\n");
	printf("Total cycles = %lld\n",total_time);
	printf("total time no read = %lld\n",total_no_read);
	printf("Average number of CPU cycles running in hardware = %lld\n",total_accLearn);
//  printf("total time accelerator Predict = %lld\n",total_no_accPredict);
	printf("Average number of CPU cycles running in software = %lld\n",total_SoftwareLearn);
	printf("Speed up = %lf\n",speedup);
	printf("Percentage improvement = %lf%\n",speedup_per); 
	printf("-----------------\n");
#endif

	//free sds_alloc------------------------
	sds_free(data);
//	sds_free(final_data);
	sds_free(similarity);
	sds_free(knn);
	sds_free(sim_knn);
	
	//free malloc------------------------
	//free(final_data_software);
    	free(similarity_software);
    	free(knn_software);
    	free(sim_knn_software);
}
