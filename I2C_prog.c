//author: ASMAA SOBHY
#include "I2C_types.h"
#include "I2C_priv.h"
#include "I2C_cfg.h"

void I2C_init(void){
	TWSR&=~(1<<TWPS0);
	TWSR&=~(1<<TWPS1);
	TWCR|=(1<<TWEN);
}

void I2C_start(void){
	TWCR|=((1<<TWSTA)|(1<<TWINT));
	while(!(TWCR&=(1<<TWINT)));
}

void I2C_write(unsigned char DATA){
	TWDR=DATA;
	TWCR|=((1<<TWINT)|(1<<TWEN));
	while(!(TWCR&=(1<<TWINT)));
}

unsigned char I2C_read(void){
	TWCR|=((1<<TWINT)|(1<<TWEN)|(1<<TWEA));
	while(!(TWCR&=(1<<TWINT)));
	return TWDR;
}

void I2C_stop(void){
	TWCR|=((1<<TWINT)|(1<<TWINT)|(1<<TWSTO));
}