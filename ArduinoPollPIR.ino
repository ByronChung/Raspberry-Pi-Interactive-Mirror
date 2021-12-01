/**
@brief Setup event loop for Arduino used to manage wired connections, I/O, and serial data writing for transfer to Raspberry Pi
Event loop polls Passive Infrared Sensor (PIR) data from Arduino digital output pin & sends it to serial output to Raspberry Pi
@author: Ashwin Singh
*/

//Pin Configuration for Arduino
int led = 13;                
int sensor = 3;             
int flag = LOW;            
int val = 0;                

//Set up types of pins for the LED & the sensor; additionally set serial data transmission rate
void setup() {
  pinMode(led, OUTPUT);      
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
}

//Begin sensor reading event loop
void loop(){
  //Read sensor value, if HIGH: turn LED on to indicate motion detected and set flag then wait 10 seconds before checking again
  //Print flag to serial to be processed by Raspberry Pi
  val = digitalRead(sensor);   
  if (val == HIGH) {           
    digitalWrite(led, HIGH);   
    flag = HIGH;
    Serial.println(flag);
    delay(10000);                 
  } 
  
  //Read sensor value, if LOW: turn LED off to indicate motion not detected and set flag then wait 5 seconds before checking again
  //In case where flag was HIGH, change it be LOW
  //Print flag to serial to be processed by Raspberry Pi
  else {
      digitalWrite(led, LOW); 
      delay(5000);             
      if (flag == HIGH){
        flag = LOW;       
        Serial.println(flag);
     }
  }
}
