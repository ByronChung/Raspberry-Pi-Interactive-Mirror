int led = 13;                // the pin that the LED is atteched to
int sensor = 3;              // the pin that the sensor is atteched to
int flag = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    flag = HIGH;
    //Serial.println("Motion detected");
    Serial.println(flag);
    delay(10000);                // delay 100 milliseconds 
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(5000);             // delay 200 milliseconds 
      
      if (flag == HIGH){
        flag = LOW;       // update variable state to LOW
        Serial.println(flag);
        //Serial.println("Motion stopped! Motion FLAG reset");
    }
  }
}
