#include "uop_msb.h"
#include <cstdint>
using namespace uop_msb;

// Hardware Definitions
#define TRAF_RED1_PIN PC_2

// Inputs
DigitalIn SW_BLUE(USER_BUTTON);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);

// Timer(modified version from Timer)
TimerCompat tmr1;
//TimerCompat tmr2;
int main()
{
    //Time how long it takes to perform a printf
    tmr1.start();
    printf("Hello World! How old are you\n");
    tmr1.stop();

    //Print out how long it took
    unsigned long long dur = tmr1.read_ms();
    printf("The time taken was %llu milliseconds\n", dur);    

    //Now to use a timer to implement a delay
    //tmr2.start();
    uint8_t ButtonState;
    ButtonState = SW_BLUE;

    ledRed = 0;
    int led;
    while (true) {
        //Wait for switch event 
        
        while (SW_BLUE == ButtonState)
        {
            ButtonState = SW_BLUE;            
        }
        //Save the button state;
        ButtonState = SW_BLUE;
        //Start a timer as the button has been updated
        tmr1.start();

        while(tmr1.elapsed_time() < 20ms)
        {
            //Wait for the debounce time to finish 
        }
        //Check the button state has not changed, if so, update LED

        if(ButtonState == SW_BLUE)
        {
            tmr1.stop();
            tmr1.reset();
            led = ledRed ^ 1;
            ledRed = led;
        }

        //Wait for button change event 
        while (SW_BLUE == ButtonState)
        {
            ButtonState = SW_BLUE;            
        }
        ButtonState = SW_BLUE;
        wait_us(2000);


     

        //Turn on LED
        //ledRed = 1;

        //Wait for 500ms
        //tmr1.reset();
       /* while (tmr1.elapsed_time() < 500ms)
        {

        } //How about this for C++ magic :)

        //wait_us(500000);
        //Task 207 Part 2
        while(SW_BLUE == 1)
        {

        }
        ledRed = 1;
        wait_us(500000);
        //Turn off LED
        ledRed = 0;
      */
    }
}



