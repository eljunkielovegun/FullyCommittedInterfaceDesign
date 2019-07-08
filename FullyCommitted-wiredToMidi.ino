/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int Button1 = 9;
int Button2 = 12;
int Button3 = 11;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState1 = digitalRead(Button1);
 //Serial.println(buttonState1);
  
  if (buttonState1 == 0){
    Serial.println("100");
        } else{};

  int buttonState2 = digitalRead(Button2);
  if (buttonState2 == 0){
    Serial.println("200");
        }
 int buttonState3 = digitalRead(Button3);
  if (buttonState3 == 0){
    Serial.println("300");
        }

  
  
  // print out the state of the button:
  
  delay(1);        // delay in between reads for stability
}
