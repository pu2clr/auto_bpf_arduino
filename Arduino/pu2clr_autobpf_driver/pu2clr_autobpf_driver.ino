/**
 *  This sketch is useful to check the circuit, to test the AutoBPF library and to guide the user. 
 *  See the Bandpass filter circuit on https://github.com/pu2clr/auto_bpf_arduino
 *  
 *  Author: Ricardo Lima Caratti
 */
#include "AutoBPF.h"    // Bandpass filter library

AutoBPF bpf;            // Declare the Auto bandpass filter class.

void setup()
{
    Serial.begin(9600);

    showHelp();

    bpf.setup(14, 15);    // Selects Arduino pins 4 and 5 to control select the desired filter
    bpf.setFilter(0);   // Setects the first filter (BPF).
    delay(10000);       // 10s
}

void showHelp() {
    Serial.print("\n************************************");
    Serial.print("\nBandpass filter controller\n");
    Serial.print("\nType 0, 1, 2 or 3 to select the bandpass filter");
}

void loop()
{
    int aux;
    if (Serial.available() > 0) {
        char key = Serial.read();
        if (key >= '0' && key <= '3') {
            aux = key - '0';                            // Converts char digit number to integer value.

            Serial.print("\nYou have just selected the BPF ");
            Serial.print(aux);

            bpf.setFilter(aux);                         // Switching to the given PBF
            
            Serial.print("\nThe current BPF is ");      // Get the current BPF from driver
            Serial.print(bpf.getCurrentFilter());

            Serial.print("\nS0 is ");      // Get the current BPF from driver
            Serial.print(bpf.getS0());
            
            Serial.print("\nS1 is ");      // Get the current BPF from driver
            Serial.print(bpf.getS1());

            Serial.print("\n\nNow you can check the system (Circuit)...\n\n");
            delay(500);
            showHelp();
        }
    }
}
