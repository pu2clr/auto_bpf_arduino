
/**
   Bandpass filter circuit tester.

   This sketch uses the Arduino IDE serial monitor to check the switches.
   You can select the bandpass filter by using the keyboard and typing 0, 1, 2 or 3.

   By Ricardo Lima Caratti, Jul 2020.
*/

#define S0_PIN   4 // FST3253 or SN74CBT3253D S0 pin
#define S1_PIN   5 // FST3253 or SN74CBT3253D S1 pin

void setup()
{
  Serial.begin(9600);
  while (!Serial) {};

  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);

  // Select the BPF 0
  digitalWrite(S0_PIN, LOW);
  digitalWrite(S1_PIN, LOW);

  showHelp();

}

void showHelp() {
  Serial.print("\n******************************");
  Serial.print("\nBandpass filter controller\n");
  Serial.print("\nType 0, 1, 2 or 3 to select the bandpass filter");
}

void loop()
{
  uint8_t bpf;
  if (Serial.available() > 0) {
    char key = Serial.read();
    if (key >= '0' && key <= '3' ) {
      bpf = key - '0';                            // Converts char digit number to integer value.
      Serial.print("\nYou selected the BPF ");
      Serial.print(bpf);
      digitalWrite(S0_PIN, (bpf & 1));            // Sets the S0 HIGH or LOW
      digitalWrite(S1_PIN, (bpf & 2));            // Sets the S1 HIGH or LOW
      Serial.print("\n\nCheck the system (Circuit)...\n\n");
      delay(5000);
      showHelp();
    }
  }
}
