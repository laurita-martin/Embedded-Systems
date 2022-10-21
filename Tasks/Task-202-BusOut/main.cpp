#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

//Add other LEDs
#define TRAF_GRN2_PIN PB_0
#define TRAF_YEL2_PIN PB_7
#define TRAF_RED2_PIN PB_14
// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN, TRAF_GRN2_PIN, TRAF_YEL2_PIN, TRAF_RED2_PIN);

int main()
{
    while (true) {
        /*leds = 0;   //Binary 000
        wait_us(500000);
        leds = 7;   //Binary 111
        wait_us(500000);  */
        int x;
        for(x=0; x <= 63; x++)
        {
            leds = x;
            wait_us(500000);
        }  
    }
}


