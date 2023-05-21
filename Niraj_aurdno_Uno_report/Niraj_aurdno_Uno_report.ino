
//Niraj Chaudhary
//2332917

// Includes the Servo library
#include <Servo.h>. 

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;//trigPin is set to 10, representing the pin used for transmitting the trigger signal.
const int echoPin = 11;//echoPin is set to 11, representing the pin used for receiving the echo signal.

// Variables for the duration and the distance
long duration; 
int distance;

Servo myServo; // Creates a servo object for controlling the servo motor


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);//The serial communication is initialized with a baud rate of 9600 using Serial.begin(9600).
  myServo.attach(12); // Defines on which pin is the servo motor attached
}


void loop() { //The loop() function is the main body of the code and is executed repeatedly.
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }

  
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30); //A delay of 30 milliseconds is added to allow the servo motor to move to the desired position smoothly.
  distance = calculateDistance(); //The calculateDistance() function is called to measure the distance using the ultrasonic sensor.
  Serial.print(i); //The angle i and the calculated distance are printed to the serial monitor.
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);//it sets the trigPin to HIGH for 10 microseconds to transmit the ultrasonic signal.
  digitalWrite(trigPin, LOW);//After that, it sets the trigPin back to LOW.
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2; //The duration is then converted to distance using the formula duration * 0.034 / 2.
  return distance;
}
