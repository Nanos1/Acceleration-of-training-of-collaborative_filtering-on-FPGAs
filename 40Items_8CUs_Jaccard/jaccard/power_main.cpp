#include "pwr_monitor.h"
#include <iostream>
#include <fstream>

int start;
pthread_mutex_t mutex;

int stop;
pthread_t  thread_ID;
void      *exit_status;

// Full Power Domain
struct voltage_rail zcu102_fp_rails[]={
    {
          "vccpsintfp     ",
          0x40,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "mgtravcc       ",
          0x44,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "mgtravtt       ",
          0x45,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vcco_psddr_504 ",
          0x46,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vccpsddrpll    ",
          0x4b,
          0,
          0, 
          LOG_RAIL_TRUE
    },
};
// Low Power Domain
struct voltage_rail zcu102_lp_rails[]={
    {
          "vccpsintlp     ",
          0x41,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vccpsaux       ",
          0x42,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vccpspll       ",
          0x43,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vccops         ",
          0x47,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vccops3        ",
          0x4a,
          0,
          0, 
          LOG_RAIL_TRUE
    },
};
// Prog Logic Domain
struct voltage_rail zcu102_pl_rails[]={
    {
          "vccint         ",
          0x40,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vccbram        ",
          0x41,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vccaux         ",
          0x42,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vcc1v2         ",
          0x43,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vcc3v3         ",
          0x44,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "vadj_fmc       ",
          0x45,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "mgtavcc        ",
          0x46,
          0,
          0, 
          LOG_RAIL_TRUE
    },
    {
          "mgtavtt        ",
          0x47,
          0,
          0, 
          LOG_RAIL_TRUE
    },
};

int fdi2c;
int fdi2c_pl;
std::ofstream logfile;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void *zcu102_read_samples_ps(void *argv) {
  int start_flag = 0;
  int stop_flag = 0;

  int i, h;
  int loop_fp, loop_lp;
  double totalPower;
  double power;
  double fp_power, lp_power;
  double voltage;
  double current;

  double maxpower = 0.0f;

  //opening log file
  std::string logfilename = *reinterpret_cast<std::string*>(argv);
  logfile.open(logfilename);

  //opening device for read and write
  fdi2c = open(I2C_CHANNEL, O_RDWR);
  if(fdi2c < 0)
      std::cout << "Cannot open the device\n";

  loop_fp = sizeof(zcu102_fp_rails)/sizeof(struct voltage_rail);
  loop_lp = sizeof(zcu102_lp_rails)/sizeof(struct voltage_rail);

  // Initialization
  initCalibRail(fdi2c, zcu102_fp_rails, loop_fp); // init full power rails
  initCalibRail(fdi2c, zcu102_lp_rails, loop_lp); // init low power rails
  
  h = 0;
  logfile << "+---------------------------------------------------------------------------------+\n";
  logfile << "|                                       Power Monitor                             |\n";
  logfile << "|RAIL                           |   Voltage(V)    |   Current(mA) |    Power(mW)  |\n";
  logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
          
  while(1) {
      start_flag = 1;
      pthread_mutex_lock(&mutex);
      if(start == 0)
          start_flag = 0;
      pthread_mutex_unlock(&mutex);
      if(start_flag == 0) 
          continue;
      ///////////////////////////////
      totalPower = 0.0f;
      fp_power = 0.0f;
      lp_power = 0.0f;
      power = 0.0f;

      logfile << "+---------------------------------------------------------------------------------+\n";
      logfile << "|                               Full Power Domain                                 |\n";
      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";

      for(i = 0; i < loop_fp; i++) {
          voltage = readBusVoltage(fdi2c, zcu102_fp_rails[i].device);
          current = readCurrent(fdi2c, zcu102_fp_rails[i].device);
          power = voltage * current; 
          fp_power += power;
          totalPower += power;
          
          logfile << zcu102_fp_rails[i].name <<  " \t\t| " << voltage << " V\t\t" << current << " mA\t\t" << power << " mW\n";
      }

      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
      logfile << "TOTAL FULL POWER           " << fp_power << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";
      logfile << "|                                 Low Power Domain                                |\n";
      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";

      for(i = 0; i < loop_lp; i++) {
          voltage = readBusVoltage(fdi2c, zcu102_lp_rails[i].device);
          current = readCurrent(fdi2c, zcu102_lp_rails[i].device);
          power = voltage * current;
          lp_power += power;
          totalPower += power;

          logfile << zcu102_lp_rails[i].name <<  " \t\t| " << voltage << " V\t\t" << current << " mA\t\t" << power << " mW\n";
      }

      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
      logfile << "TOTAL LOW POWER            " << lp_power << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";

      if (maxpower < totalPower)
          maxpower = totalPower;

      logfile << "TOTAL POWER " << totalPower << " mW\t\t\t MAX POWER  " << maxpower << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";
      /////////////////////////////

      h++;
      stop_flag = 0;
      pthread_mutex_lock(&mutex);
      if (stop == 1)
          stop_flag = 1;
      pthread_mutex_unlock(&mutex);
      if(stop_flag==1)
          break;
  }

  return 0;
}

void *zcu102_read_samples_pl(void *argv) {
  int start_flag = 0;
  int stop_flag = 0;

  int i, h;
  int loop_pl;
  double totalPower;
  double power;
  double pl_power;
  double voltage;
  double current;

  double maxpower = 0.0f;

  //opening log file
  std::string logfilename = *reinterpret_cast<std::string*>(argv);
  logfile.open(logfilename);

  //opening device for read and write
  fdi2c_pl = open(I2C_CHANNEL_PL, O_RDWR);
  if(fdi2c_pl < 0)
      std::cout << "Cannot open the PL device\n";

  loop_pl = sizeof(zcu102_pl_rails)/sizeof(struct voltage_rail);

  // Initialization
  initCalibRail(fdi2c_pl, zcu102_pl_rails, loop_pl); // init logic power rails
  
  h = 0;
  logfile << "+---------------------------------------------------------------------------------+\n";
  logfile << "|                                       Power Monitor                             |\n";
  logfile << "|RAIL                           |   Voltage(V)    |   Current(mA) |    Power(mW)  |\n";
  logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
          
  while(1) {
      start_flag = 1;
      pthread_mutex_lock(&mutex);
      if(start == 0)
          start_flag = 0;
      pthread_mutex_unlock(&mutex);
      if(start_flag == 0) 
          continue;
      ///////////////////////////////
      totalPower = 0.0f;
      pl_power = 0.0f;
      power = 0.0f;

      logfile << "+-------------------------------------------------+-------------------------------+\n";
      logfile << "|                             Prog Logic Power Domain                             |\n";
      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";

      for(i = 0; i < loop_pl; i++) {
          voltage = readBusVoltage(fdi2c_pl, zcu102_pl_rails[i].device);
          current = readCurrent(fdi2c_pl, zcu102_pl_rails[i].device);
          power = voltage * current; 
          pl_power += power;
          totalPower += power;
          logfile << zcu102_pl_rails[i].name <<  " \t\t| " << voltage << " V\t\t" << current << " mA\t\t" << power << " mW\n";
      }

      if (maxpower < totalPower)
          maxpower = totalPower;

      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
      logfile << "TOTAL PROG LOGIC POWER " << totalPower << " mW\t\t\t MAX POWER  " << maxpower << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";

      h++;
      ///////////////////////////////
      stop_flag = 0;
      pthread_mutex_lock(&mutex);
      if (stop == 1)
          stop_flag = 1;
      pthread_mutex_unlock(&mutex);
      if(stop_flag==1)
          break;
  }

  return 0;
}

void *zcu102_read_samples_ps_and_pl(void *argv) {
  int start_flag = 0;
  int stop_flag = 0;

  int i, h;
  int loop_fp, loop_lp, loop_pl;
  double totalPower;
  double power;
  double fp_power, lp_power, pl_power;
  double voltage;
  double current;

  double maxpower = 0.0f;

  //opening log file
  std::string logfilename = *reinterpret_cast<std::string*>(argv);
  logfile.open(logfilename);

  //opening device for read and write
  fdi2c = open(I2C_CHANNEL, O_RDWR);
  if(fdi2c < 0)
      std::cout << "Cannot open the device\n";
  fdi2c_pl = open(I2C_CHANNEL_PL, O_RDWR);
  if(fdi2c_pl < 0)
      std::cout << "Cannot open the PL device\n";

  loop_fp = sizeof(zcu102_fp_rails)/sizeof(struct voltage_rail);
  loop_lp = sizeof(zcu102_lp_rails)/sizeof(struct voltage_rail);
  loop_pl = sizeof(zcu102_pl_rails)/sizeof(struct voltage_rail);

  // Initialization
  initCalibRail(fdi2c, zcu102_fp_rails, loop_fp); // init full power rails
  initCalibRail(fdi2c, zcu102_lp_rails, loop_lp); // init low power rails
  initCalibRail(fdi2c_pl, zcu102_pl_rails, loop_pl); // init logic power rails
  
  h = 0;
  logfile << "+---------------------------------------------------------------------------------+\n";
  logfile << "|                                       Power Monitor                             |\n";
  logfile << "|RAIL                           |   Voltage(V)    |   Current(mA) |    Power(mW)  |\n";
  logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
          
  while(1) {
      start_flag = 1;
      pthread_mutex_lock(&mutex);
      if(start == 0)
          start_flag = 0;
      pthread_mutex_unlock(&mutex);
      if(start_flag == 0) 
          continue;
      ///////////////////////////////
      totalPower = 0.0f;
      fp_power = 0.0f;
      lp_power = 0.0f;
      pl_power = 0.0f;
      power = 0.0f;

      logfile << "+---------------------------------------------------------------------------------+\n";
      logfile << "|                               Full Power Domain                                 |\n";
      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";

      for(i = 0; i < loop_fp; i++) {
          voltage = readBusVoltage(fdi2c, zcu102_fp_rails[i].device);
          current = readCurrent(fdi2c, zcu102_fp_rails[i].device);
          power = voltage * current; 
          fp_power += power;
          totalPower += power;
          
          logfile << zcu102_fp_rails[i].name <<  " \t\t| " << voltage << " V\t\t" << current << " mA\t\t" << power << " mW\n";
      }

      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
      logfile << "TOTAL FULL POWER           " << fp_power << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";
      logfile << "|                                 Low Power Domain                                |\n";
      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";

      for(i = 0; i < loop_lp; i++) {
          voltage = readBusVoltage(fdi2c, zcu102_lp_rails[i].device);
          current = readCurrent(fdi2c, zcu102_lp_rails[i].device);
          power = voltage * current;
          lp_power += power;
          totalPower += power;

          logfile << zcu102_lp_rails[i].name <<  " \t\t| " << voltage << " V\t\t" << current << " mA\t\t" << power << " mW\n";
      }

      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
      logfile << "TOTAL LOW POWER            " << lp_power << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";
      logfile << "|                             Prog Logic Power Domain                             |\n";
      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";

      for(i = 0; i < loop_pl; i++) {
          voltage = readBusVoltage(fdi2c_pl, zcu102_pl_rails[i].device);
          current = readCurrent(fdi2c_pl, zcu102_pl_rails[i].device);
          power = voltage * current; 
          pl_power += power;
          totalPower += power;
          logfile << zcu102_pl_rails[i].name <<  " \t\t| " << voltage << " V\t\t" << current << " mA\t\t" << power << " mW\n";
      }

      logfile << "+-------------------------------+-----------------+---------------+---------------+\n";
      logfile << "TOTAL PROG LOGIC POWER " << pl_power << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";


      if (maxpower < totalPower)
          maxpower = totalPower;

      logfile << "TOTAL POWER " << totalPower << " mW\t\t\t MAX POWER  " << maxpower << " mW\n";
      logfile << "+-------------------------------------------------+-------------------------------+\n";
      /////////////////////////////

      h++;
      stop_flag = 0;
      pthread_mutex_lock(&mutex);
      if (stop == 1)
          stop_flag = 1;
      pthread_mutex_unlock(&mutex);
      if(stop_flag==1)
          break;
  }

  return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
void *zcu102_read_sample_pthread(const std::string& logfilename, int ps_or_pl) {
  pthread_mutex_init(&mutex, NULL);  
	pthread_mutex_lock(&mutex);
	stop = 0;
	start = 0;
	pthread_mutex_unlock(&mutex);

	cpu_set_t cpu_set2;
	CPU_SET(1, &cpu_set2);
  if(ps_or_pl == 0)
    pthread_create(&thread_ID, NULL, zcu102_read_samples_ps,(void*)&logfilename);
  else if(ps_or_pl == 1)
    pthread_create(&thread_ID, NULL, zcu102_read_samples_pl,(void*)&logfilename);
  else
    pthread_create(&thread_ID, NULL, zcu102_read_samples_ps_and_pl,(void*)&logfilename);
	sched_setaffinity(thread_ID, sizeof(cpu_set_t), &cpu_set2);
}

void zcu102_read_sample_start() {
	pthread_mutex_lock(&mutex);
	start = 1;
	stop  = 0;
	pthread_mutex_unlock(&mutex);
}
/////////////////////////////////////////////////////////////////////////////////////
void power_monitoring_start(const std::string& logfilename, int ps_or_pl){
	zcu102_read_sample_pthread(logfilename, ps_or_pl);
	zcu102_read_sample_start();  
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void zcu102_close_thread(){
	pthread_mutex_lock(&mutex);
	stop = 1;
  start = 0;
  pthread_mutex_unlock(&mutex);
	pthread_join(thread_ID, &exit_status);
  pthread_detach(thread_ID);
}

void zcu102_close_files(int ps_or_pl){
    logfile.close();
    if(ps_or_pl == 0)
      close(fdi2c);
    else if(ps_or_pl == 1)
      close(fdi2c_pl);
    else{
      close(fdi2c);
      close(fdi2c_pl);
    }

}
/////////////////////////////////////////////////////////////////////////////////////
void power_monitoring_stop(int ps_or_pl){
    zcu102_close_thread();
    zcu102_close_files(ps_or_pl);
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
