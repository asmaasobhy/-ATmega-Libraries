//author: ASMAA SOBHY
#ifndef I2C_PRIV_H
#define I2C_PRIV_H

#define TWBR *((volatile u8*))
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

#define TWCR *((volatile u8*))
#define TWIE  0
#define TWEN  2
#define TWWC  3
#define TWSTO 4
#define TWSTA 5
#define TWEA  6
#define TWINT 7

#define TWSR *((volatile u8*))
#define TWPS0 0
#define TWPS1 1
#define TWS3  3
#define TWS4  4
#define TWS5  5
#define TWS6  6
#define TWS7  7

#define TWBR ((CPU_F/SCL_F)-16)/(2*)

#define TWAR *((volatile u8*))

#define TWDR *((volatile u8*))

#endif