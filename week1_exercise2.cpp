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
        
        double OnTime = (anInput)*2000;
        
    double OffTime = 2000-OnTime; 
    
    
    if (OnTime > 0 && OnTime <= 1500) {
        output = 1;
        wait_ms(OnTime);
        
        output = 0;
        wait_ms(OffTime-500); //500 due to the 500ms wait time
    }
    /* I noticed that when OnTime > 1500 ms, the 500ms wait time would get in the way of the period,
       so I corrected that using the next conditional. It could probably be more optimized
       if I integrated it into the above conditional, but this seemed more simple to write out */
    else if (OnTime > 1500) { 
        output = 1;
        wait_ms(100); //The 100ms is arbitrary, I just needed to have the off time in the middle of the period so that it doesn't run into the 500ms at the end
        
        if (OffTime > 0) {output = 0;
        wait_ms (OffTime);
        }
        
        output = 1;
        wait_ms (OnTime-600-OffTime); //600 here due to 100 ms from earlier and the required 500ms between cycles
        
    }
    
    else {
        output = 0;
    }   
        // MAKE SURE THERE IS ALWAYS A WAIT ON THE SIM OR IT WILL CRASH
        wait_ms(500); 
    }
}
