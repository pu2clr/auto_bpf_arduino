
#include "mcp23008.h"


char sBuffer[80];

MCP mcp;



void setup() {

  Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
  while (!Serial); // Waiting for Serial Monitor

  mcp.setup(0x20);
  mcp.turnGpioOn(1);
  mcp.turnGpioOn(5);

  showGpios();
  delay(2000);

  mcp.turnGpioOff(5);

  showGpios();

}

void showGpios() {
  Serial.println("\n*************\n");
  sprintf(sBuffer,"\nGPIOS: %d - %d\n", mcp.getGPIOS(), mcp.getRegister(REG_GPIO)) ;
  Serial.print(sBuffer);
  Serial.println(mcp.getGPIOS(),BIN);
  Serial.println(mcp.getRegister(REG_GPIO),BIN);
}

void loop() {

  mcp.turnGpioOn(1);
  mcp.turnGpioOn(5);
  mcp.turnGpioOn(7);
  showGpios();
  delay(2000);
  mcp.turnGpioOff(5);
  delay(1000);
  mcp.turnGpioOff(1);
  delay(1000);
  mcp.turnGpioOff(7);
  showGpios();
  delay(1000);
  mcp.turnGpioOn(1);
  delay(500);
  mcp.turnGpioOn(5);
  delay(500);
  mcp.turnGpioOn(7); 
  showGpios();
  delay(1000);
  mcp.turnGpioOff(1);
  mcp.turnGpioOff(5);
  mcp.turnGpioOff(7);
  showGpios();
  delay(2000); 
}
