#include "AutoBPF.h"


/**
 * @brief Configures the Arduino pins used to control the bandpass filter circuit 
 * 
 * @param pin_s0  Audiono pin connected to the input s0
 * @param pin_s1  Audiono pin connected to the input s1
 */
void AutoBPF::setup(uint8_t pin_s0, uint8_t pin_s1) {
    this->s0 = pin_s0;
    this->s1 = pin_s1;
    pinMode(this->s0, OUTPUT);
    pinMode(this->s1, OUTPUT);
}

/**
 * @brief Sets the bandpass filter
 * @details Selects the BPF
 * 
 * @param filter the valid values are 0,1,2 and 3.
 */
void AutoBPF::setFilter(uint8_t filter) {
    if (filter < 4) {
        digitalWrite(this->s0, (filter & 1));  // Sets the S0 HIGH or LOW
        digitalWrite(this->s1, (filter & 2));     // Sets the S1 HIGH or LOW
    }
}

/**
 * @brief Returns the current bandpass filter
 * @details return a number between 0 and 3 corresponding the filter selected
 * @return uint8_t return 0, 1, 2 or 3
 */
uint8_t AutoBPF::getCurrentFilter() {
    return ((this->s1 << 1) & this->s0);
}
