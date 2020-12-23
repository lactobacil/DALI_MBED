
#include "mbed.h"
#define t_onebit 834/2

Timer time;
DigitalIn switchInput(p10); //// Declare Digital Input of 

volatile int bypass
volatile int deltapeak
volatile int dalitimeout = 20000
volatile int T_DALI = 416 // One single bit is 416us or 0,000416 s

int dali_rx(void) {
    /////Backwardframe read
    while (1) { //// Add conditions where dali_rx will quit the process
        int switchstate;
        int prev_state;
        int arrLength;
        int initbit;
        int startbit;
        int arrSize = 20;
        int timeArrayHigh[arrSize];
        int timeArrayLow[arrSize];
        int n_time[40];
        int arrData[20];
        int arr
        int nth_time;           ////Check for order bits, this is quite important. 

        int i;
        uint32_t = t.read_us();
        switchstate = switchInput;
        //////////////////////////////Dali Packet Check Start to Confirm Readiness (First State)
        /// while (initbit == 1)
        while (startbit == 0) {
            if (initbit == 0) {
                if (switchstate == 0) {
                    time.start();
                    prev_state = switchstate;

                    if (prev_state != switchstate) {
                        uint32_t lowtime = time.read_us();
                        if (time.read_us() == T_DALI) {
                            initbit = 1;
                            time.stop();
                        }

                    }
                }
            }
            else if (initbit == 1) {
                if (switchstate == 1) {
                    time.start();
                    if (time.read_us() > T_DALI) {
                        startbit = 1;
                        time.stop();
                    }
                }
            }
        }
        ///////////////////////////Dali Backward Frame Decode (Second State)
        while ((dalitime.read_us() < dalitimeout) and (i < arrSize)) { ///// Not Quite sure with the conditions above, make sure that this is right 
            for (i = 0; i < arrSize - 1; i++) {

                prev_state = 0;                                 ////Clear Prev State From Previous Memory
                if (switchstate == 1) {                         ////Detect High. When State Changes, Capture Time.
                    time.start();
                    prev_state = switchstate;
                    if (switchstate != prev_state) {
                        timeArray[i] = time.read_us() * 10;       ////TimeRead For Data Accuracy With Multiplier as indicator
                                                                  //Worried if multiplication might take longer 
                        time.stop();
                    }
                }
                else {                                          ////Detect Low. when state changes, capture Time. 
                    time.start();
                    prev_state = switchstate;
                    if (switchstate != prev_state) {
                        timeArray[i] = time.read_us();
                        time.stop();

                    }
                }
            }
        }
        ////////////////////////////Decode TimeArray to Hex Code (Final State)
        int k;
        for (k = 0; k < arrSize - 1; k++) {
            if (timeArray[k] > T_DALI * 10) {         //Add Coefficient *10 to differentiate ones and zeros
                arrData[k] = 1;
                if (timeArray[k] > T_DALI * 20) {
                    arrData[k + 1] = 1;
                    k++;
                }
            }
            else if (timeArray[k] > T_DALI) {
                arrData[k] = 0;
                if (timeArray[k] > T_DALI * 2) {
                    arrData[k + 1] = 0;
                    k++;
                }

            }
        } 
        int j;                                          ///Add info on 
        for (j = 0; j < arrSize - 1; j++) {
            if (arrData[j] == 1 && arrData[j + 1] == 0) {
                arrBit[j] = 1;
            }
            else if (arrData[j] == 0 && arrData[j + 1] == 1) {
                arrBit[j] = 0;
            }
            finish_packet = 1;                          /// Declare Packet Finished
        }
    }
}


int bit_to_hex(void) {
    int k = 0;
    for (k = 0; k < Len_arrData;  )
        

    

