#include "mbed.h"
// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

#define TRAF_GRN2_PIN PC_9
#define TRAF_YEL2_PIN PC_8
#define TRAF_RED2_PIN PC_7

#define TRAF_WHITE_PIN PF_10

#define BTN1_PIN PG_0 
#define BTN2_PIN PG_1
#define BTN3_PIN PG_2 // No pull down
#define BTN4_PIN PG_3 // No pull down

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

DigitalInOut ledRed2(TRAF_RED2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull ,1);  //set initially as OFF
DigitalInOut ledYel2(TRAF_YEL2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull ,1);
DigitalInOut ledGrn2(TRAF_GRN2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull ,1);

int main()
{
    while (true) {
        if (SW2 == 1) {
            ledRed = 1;
        } else {
            ledRed = 0;
        }
        if (SW3.read() == 1) {
            ledYel = 1;
        } else {
            ledYel = 0;
        }
        if(SW4 == 1){  //SW4 pressed
            ledGrn2 = 0;  //LED ON
        } else{
            ledGrn2 = 1;  //LED OFF
        }
        if(SW5 == 1){
            ledYel2 = 0;
        } else{
            ledYel2 = 1;
        }
    }
}  

//  Explain why the parameter PullDown is needed for SW4 and SW5
// In order to keep the given input LOW as there's nothing connecting the unused pins to ground

