/**
 * @file    Practica5Arduino.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#include "asArduino.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {
    vfnPinMode('B', 18, 1);
    vfnPinMode('B', 19, 1);
    vfnPinMode('D', 1, 1);

    while(1){
    	vfnDigitalWrite('B', 18, 1);
    	vfnDigitalWrite('B', 19, 1);
    	vfnDigitalWrite('D', 1, 1);
    	vfnDigitalWrite('B', 18, 0);
    	vfnDigitalWrite('B', 19, 0);
    	vfnDigitalWrite('D', 1, 0);
    }
    //vfnDigitalWrite('B', 18, 1);
    //vfnDigitalWrite('B', 18, 0);
    //vfnDigitalWrite('B', 18, 1);
    return 0 ;
}
