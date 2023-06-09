#include <msp430.h>
int main(void)
{
        WDTCTL = WDTPW + WDTHOLD;   // stop watchdog timer
        P1DIR = BIT0;  //set P1.0 as OUTPUT port
        P6DIR = BIT6;
        P2DIR = BIT0;  //set P2.0 as OUTPUT, P2.1,.....,P2.7 will be automatically INPUTs
        //P2REN = BIT2;  //internal resistor (inside the chip) will be enabled,
        //P1REN = BIT1;
        //P2OUT = BIT2;  //this line of code define the connectivity of the internal resistor.
        //P2OUT = BIT1;
        while(1)
            {
              if ((P2IN & BIT2))// == BIT2) //P2IN depends on the input logic state (keep changing depends on whether you are pressing the button).
              {                          //If you press the button, then P4IN = 0. By default, P4IN will be 1.
                  __delay_cycles(220000); //P4.1 will be always 1 because it is internally connected to the pull-up resistor.
                  P1OUT ^= BIT0;
              }
              if ((P2IN & BIT1))// == BIT1) //P2IN depends on the input logic state (keep changing depends on whether you are pressing the button).
                            {                          //If you press the button, then P4IN = 0. By default, P4IN will be 1.
                                __delay_cycles(220000); //P4.1 will be always 1 because it is internally connected to the pull-up resistor.
                                P6OUT ^= BIT6;
                            }
            }
    return 0;
}
