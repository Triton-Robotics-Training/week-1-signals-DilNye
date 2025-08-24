//STARTER 
//THIS EXERCISE IS TO BE DONE IN THE ARM MBED SIMULATOR
//http://195.130.59.221/
//IF YOU HAVE ISSUES WITH THE SIMULATOR, CONTACT EMBEDDED LEAD
#include "mbed.h"
AnalogIn anInput(p15);

DigitalOut output(LED1);

int main() {
    while (1) {
        printf("Week 1 Exercise 2");
        
        if (anInput > 0) {
            output = 1;
        
            double OnTime = (anInput/3.3)*2000;
        
            double OffTime = 2000-OnTime;
        
    
            wait_ms(OnTime);
        
            output = 0;
        
            wait_ms(OffTime);
        
        }
        else {
            output = 0;
        }
        
        // MAKE SURE THERE IS ALWAYS A WAIT ON THE SIM OR IT WILL CRASH
        wait_ms(500); 
    }
}
