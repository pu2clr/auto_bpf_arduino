/**
 *  This sketch is useful to check the circuit, test the AutoBPF library and guide the user. 
 *  See the Bandpass filter circuit on https://github.com/pu2clr/auto_bpf_arduino
 *  
 *  Author: Ricardo Lima Caratti
 */
#include "AutoBPF.h"

AutoBPF bpf;   // Declare the Auto bandpass filter class.

void setup()
{
    bpf.setup(4, 5);    // Selects Arduino pins 4 and 5 to control select the desired filter
    bpf.setFilter(0);   // Setects the first filter (BPF).
    delay(10000);       // 10s
    bpf.setFilter(3);   // Selects the last filter (BPF).
}

void loop()
{
    // Loop    
}
