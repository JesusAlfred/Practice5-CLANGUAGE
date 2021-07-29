#include <asArduino.h>

void vfnPinMode(unsigned char ubpPort, unsigned char ubPin, unsigned char ubMode){
    unsigned int*uwpHelper, *uwpPCR, *uwpPDDR;
    unsigned int uwOffset = (ubpPort - 'A');
    unsigned int uwcClock = CLOCKM;
    unsigned int uwBitHelper = 1;
    uwpHelper = IM_SCGC5;

    *uwpHelper = *uwpHelper | uwcClock<<uwOffset;//enciende el reloj del bloque
    uwpPCR = PCR + (0x1000 * uwOffset) + (ubPin*4);    //se asigna la direccion de memoria inicial para modificar el MUX de cada pin, inicia en pin0
    *uwpPCR = GPIO;

    uwpPDDR = PDDR + (64*uwOffset);
    uwBitHelper = uwBitHelper<<ubPin;
    if(ubMode){
        *uwpPDDR = *uwpPDDR | uwBitHelper;
    }else{
        *uwpPDDR = *uwpPDDR & ~uwBitHelper;
    }
    return;
}



void vfnDigitalWrite(unsigned char ubpPort, unsigned char ubPin, unsigned char ubData){
    unsigned int uwOffset = (ubpPort - 'A');
    unsigned int *uwpPDOR;
    unsigned int uwBitHelper = 1;
    uwpPDOR = PDOR + (64*uwOffset);
    uwBitHelper = uwBitHelper<<ubPin;
    if(ubData){
        *uwpPDOR = *uwpPDOR | uwBitHelper;
    }else{
        *uwpPDOR = *uwpPDOR & ~uwBitHelper;
    }
    return;
}
