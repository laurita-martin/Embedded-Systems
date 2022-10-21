#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASK1 0b0000000001001100  //0x004C

#define TRAF_GRN12_PIN PB_0
#define TRAF_YEL2_PIN  PB_7
#define TRAF_RED2_PIN  PB_14
#define LEDMASK2 0b0100000010000001  //0x4081
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut leds1(PortC, LEDMASK1);
PortOut leds2(PortB, LEDMASK2);

int main()
{ //all LEDs off when the code enters main
    while (true) {
        leds1 = 0;   //Binary 000
        leds2 = 0;
        //wait_us(500000);
        //leds1 = 0xFF;   //Binary 11111111
        //leds2 = 0x4081; //0x4081 All the 3 LEDs ON
        wait_us(500000); 
        leds1 = leds1^LEDMASK1; // XOR with the MASK so the 1s are still 1s
        leds2 = leds2^LEDMASK2;
        wait_us(500000); 

    }
}




