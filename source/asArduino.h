#include <math.h>

#define CLOCKM 0x200
#define GPIO 0x100
#define PDDR 0x400FF014
#define PDOR 0x400FF000

#define PCR 0x40049000



#define IM_SCGC5 0x40048038

void vfnPinMode(unsigned char ubpPort, unsigned char ubPin, unsigned char ubMode);


void vfnDigitalWrite(unsigned char ubpPort, unsigned char ubPin, unsigned char ubData);
