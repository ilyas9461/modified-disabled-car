#include <24FJ64GA002.h>
#DEVICE ADC=10

#FUSES WRT                      //Program Memory Write Protected
#FUSES NOJTAG                   //JTAG disabled
#FUSES OSCIO                    //OSC2 is general purpose output
//#FUSES CKSFSM                 //Clock Switching is enabled, fail Safe clock monitor is enabled
#FUSES PR                       //Primary Oscillator
//#FUSES HS

#fuses NOWDT,NOPROTECT,NOPR,PR,FRC
//#fuses NOWDT,NOPROTECT,PR

#use delay(internal=8Mhz , clock=8Mhz)
//#use delay(crystal=20Mhz,clock=20000000)

//#pin_select IC1  =  PIN_B1
#pin_select U1TX = PIN_B2 //PC ile 
#pin_select U1RX = PIN_B3

#pin_select U2TX = PIN_B10//BL ile 
#pin_select U2RX = PIN_B11

#pin_select OC1=PIN_B5
#pin_select OC2=PIN_B6
#pin_select OC3=PIN_B7
#pin_select OC4=PIN_B8
#pin_select OC5=PIN_B9

//#use rs232(baud=9600,parity=N,bits=8,UART1,STREAM=pc,ERRORS,DISABLE_INTS,TIMEOUT=1000)
//#use rs232(baud=57600,parity=N,bits=8,UART1,STREAM=pc,ERRORS,DISABLE_INTS,TIMEOUT=1000)
#use rs232(baud=9600,parity=N,bits=8,UART1,STREAM=pc)
//#use rs232(baud=9600,parity=N,bits=8,UART2,STREAM=bluetooth)
