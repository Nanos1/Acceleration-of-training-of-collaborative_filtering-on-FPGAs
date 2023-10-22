#include "pwr_monitor.h"
#include <iostream>

void writeData(int fdi2c, unsigned char address, unsigned char reg, int value){
    int status;

    if (ioctl(fdi2c, I2C_SLAVE_FORCE, address) < 0){
        printf("ERROR: Unable to set I2C slave address 0x%02X\n", address);
        exit(1);
    }

    status = i2c_smbus_write_byte_data(fdi2c, CMD_PAGE, address);
    if (status < 0) {
        printf("ERROR: Unable to write page address to I2C slave at 0x%02X: %d\n", address, status);
        exit(1);
    }

    value = (value >> 8) | ((value & 0xff) << 8); /** turn the byte around */
    status = i2c_smbus_write_word_data(fdi2c, reg, value);
    if (status < 0) {
        printf("ERROR: Unable to write value to I2C reg at 0x%02X: %d\n", reg, status);
        exit(1);
    }
}

int readData(int fdi2c, unsigned char address, unsigned char reg){
    int status;
    int value;

    if (ioctl(fdi2c, I2C_SLAVE_FORCE, address) < 0){
        printf("ERROR: Unable to set I2C slave address 0x%02X\n", address);
        exit(1);
    }

    status = i2c_smbus_write_byte_data(fdi2c, CMD_PAGE, address);
    if (status < 0) {
        printf("ERROR: Unable to write page address to I2C slave at 0x%02X: %d\n", address, status);
        exit(1);
    }

    value = i2c_smbus_read_word_data(fdi2c, reg);
    value = (value >> 8) | ((value & 0xff) << 8); /** turn the byte around */
    return value;
}

double readBusVoltage(int fdi2c, unsigned char address){
    int raw_value;
    double voltage;

    raw_value = readData(fdi2c, address, REG_BUS_V);

    voltage = (float)raw_value * 0.00125;
    return voltage;
}

double readCurrent(int fdi2c, unsigned char address){
    int raw_value;
    double current;

    raw_value = readData(fdi2c, address, REG_CURRENT);
    // in case it's negative
    if ((raw_value & 0x8000) != 0){
        raw_value |= 0xffff0000;
    }

    current = (float)raw_value;
    return current;
}

double readPower(int fdi2c, unsigned char address){
    int raw_value;
    double power;

    raw_value = readData(fdi2c, address, REG_POWER);

    power = (float)raw_value * 0.025;
    return power;
}

void initCalibRail(int fdi2c, struct voltage_rail rail[], int j){
    // Current_LSB is 1mA/bit
    // R_shunt = 5 mili ohm
    int cal = 1024;
    int i;

    for (i = 0; i < j; i++){
        writeData(fdi2c,rail[i].device,REG_CAL,cal); 
    }
}