#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char length = 0;
unsigned char rxBuf[16];
char message_String[256];                        // Array to store serial string

#define CAN2_INT 2                              // Set INT to pin 2
MCP_CAN CAN2(10);                               // Set CS to pin 10


void setup()
{
  Serial.begin(115200);
  
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s
  if(CAN2.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("Successful connection!");
  else
    Serial.println("Failed connection!");
  
  CAN2.setMode(MCP_NORMAL);                     // Selection of normal mode for MCP2515

  pinMode(CAN2_INT, INPUT);                     // Pin 10 - input pin
}

void loop()
{
  if(!digitalRead(CAN2_INT))
  {
    CAN2.readMsgBuf(&rxId, &length, rxBuf);      // Data read
    
    if((rxId & 0x80000000) == 0x80000000)     // Determine if ID is standard or extended
      sprintf(message_String, "Extended ID: 0x%.8lX, Data length: %1d  Data:", (rxId & 0x1FFFFFFF), length);
    else
      sprintf(message_String, "Standard ID: 0x%.3lX, Data length: %1d  Data:", rxId, length);
  
    Serial.print(message_String);
  
    if((rxId & 0x40000000) == 0x40000000){    // Determine if message is a remote request frame.
      sprintf(message_String, " REMOTE REQUEST FRAME");
      Serial.print(message_String);
    } else {
      for(byte i = 0; i<length; i++){
        sprintf(message_String, " 0x%.2X", rxBuf[i]);
        Serial.print(message_String);
      }
    }
    Serial.println();
  }
}