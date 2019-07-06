/*
  WiFi UDP Send

This uses a WiFi shield on the Adafruit Feather MO WINC1500

It ddoes not see 5G netowrks

 Circuit:
 * WiFi shield attached



 */


#include <SPI.h>
#include <WiFi101.h>
#include <WiFiUdp.h>

int status = WL_IDLE_STATUS;
#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "Fios-FZRG4";        // your network SSID (name)
char pass[] = "vat8789word05fancy";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

unsigned int localPort = 53001;      // local port to listen on

char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back
char TestCue[]="/go";

WiFiUDP Udp;


int button1 = 13; // these are where the buttons are connected 
int button2 = 12; // to the adafruit board

void setup() {

  pinMode(button1, INPUT_PULLUP); // need to tie input to high
  pinMode(button2, INPUT_PULLUP); // removes need for a resistor
  
// must designate which specific pins talk to the wifi module
  WiFi.setPins(8,7,4,2); 
  
//Initialize serial and wait for port to open:
//We are using serial to verify that the chip is connecting to wifi
  Serial.begin(9600);
 //*********UNCOMMENT WHEN TESTING AND CONNECTED TO COMPUTER
 //*********COMMENT OUT WEN USING REMOTE
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
   //delay(500);
  }

  // attempt to connect to WiFi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWiFiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(localPort);
}

void loop() {

    ///delay(10000);
//
int buttonState1 = digitalRead(button1); // READ THE BUTTON


  if(buttonState1 == 0){
 // verify that the button was pressed
     Serial.println("I am an operator with my pocket calculator");
   
//*************SENDING MESSAGE CODE********************************   
// THIS IS WHERE THE IP AND PORT ARE SET **** SHOULD NOT NEED TO CHANGE PORT
// GET THE IP FROM THE NETWORK SETTINGS IN QLAB
    Udp.beginPacket("192.168.1.152",53535);
//*************CHANGE HERE TO SET CUE NUMBER**************
    Udp.write("/cue/6/start"); //<--- cue number, needs this format
//********************************************************
    Udp.endPacket(); 
      };


int buttonState2 = digitalRead(button2); // READ THE OTHER BUTTON
  if(buttonState2 == 0){
 // verify that the button was pressed
     Serial.println("I am an operator with my pocket calculator 2");
   
//*************SENDING MESSAGE CODE********************************   
// THIS IS WHERE THE IP AND PORT ARE SET **** SHOULD NOT NEED TO CHANGE PORT
// GET THE IP FROM THE NETWORK SETTINGS IN QLAB
    Udp.beginPacket("192.168.1.152",53535);
//*************CHANGE HERE TO SET CUE NUMBER**************
    Udp.write("/cue/4/start"); //<--- cue number, needs this format
//********************************************************
    Udp.endPacket(); 
      };
  
  
}


void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
