#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN1(10); //It sets CS to pin 10

void setup() {
  Serial.begin(115200);

// CAN speed and frequency
  if (CAN1.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("Successfull conncetion!");
  else
    Serial.println("Connection failed!");

  CAN1.setMode(MCP_NORMAL);  // Change to normal mode to allow messages to be transmitted
}

byte data[10] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA};

void loop() {
// send data:  ID = 0x100, Standard CAN Frame, Data length = 10 bytes, 'data' = array of data bytes to send
  byte sndStat = CAN1.sendMsgBuf(0x100, 0, 10, data);

  if(sndStat == CAN_OK){
    Serial.println("Message is delivered");
  } else {
    Serial.println("Message isn't delivered");
  }
  delay(200);

}