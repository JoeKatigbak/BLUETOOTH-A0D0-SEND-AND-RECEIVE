/*Created by Joseph Locsin Katigbak, LX Robotics Engineer, 01/24/18
 * Simple BT function test
 * - as MCU ISBAT connect to Bluetooth.
 * - as MCU ISBAT send data to Mobile app through Bluetooth.
 * - as Mobile App ISBAT read from MCU through Bluetooth.
 * - as Mobile App ISBAT send to MCU data thru Bluetooth.
*/

String readString;            //necessary string function to timeout after string has been read.
int led = 13;                 //Declare digital pin
int pwm = A0;                 //Declare analog pin

void setup() {
  Serial.begin(9600);         //Begin Bluetooth Serial Comms.
  pinMode(led, OUTPUT);       //Set Led as Input
  pinMode(pwm, INPUT);        //Set Led as Output
}

void loop() {
  
  float val = analogRead(pwm);      //Read A0 value
  float volts = val/205;            //Equates directly to the amount of Voltage recieved by input
  Serial.println(volts);            //Prints value
  
  while(Serial.available()){      //Checks Serial Availability for bluetooth transmission  
    delay(50);
    char c=Serial.read();         //Reads the letters one by one
    readString+=c;                //Combines it into the readString function, function breaks after input string is acknowledged. It will loop and stack if you use a made string Ex: readStrin, string1.
  }
  if(readString.length()>0){      //Checks is their is data in transmission
    Serial.println(readString);   //Prints the received data
    
    if (readString =="on"){     
    digitalWrite(led, HIGH);      //If Bluetooth receives "on" from the readString function it will do its command turning the LED ON.
      delay(500);
    }
    if (readString =="off"){
    digitalWrite(led, LOW);       //If Bluetooth receives "off" from the readString function it will do its command turning the LED OFF.
      delay(500);
    }
    readString="";                //Clears the readString function allowing and accepting new data to come through.
  }
 
}
