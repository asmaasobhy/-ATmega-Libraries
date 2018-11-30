//author: ASMAA SOBHY
#ifndef I2C_INT_H
#define I2C_INT_H 

void I2C_init(void);
void I2C_start(void);
void I2C_write(unsigned char DATA);
unsigned char I2C_read(void);
void I2C_stop(void);

#endif