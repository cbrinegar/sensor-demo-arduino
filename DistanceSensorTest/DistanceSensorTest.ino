//
//  DistanceSensorTest
//
//  This demonstration uses an ultrasonic distance sensor to drive the
//  tone played from a speaker.  Different tones can be played by placing
//  ones hand at different distances from the sensor.
//
//  Cornelius Brinegar
//  2018
//

// This code is written for the Arduino 101 board.  Some modifications are
// required for other boards.
#include "CurieTimerOne.h"

const int trigPin = 5;
const int echoPin = 7;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, INPUT );
  Serial.begin( 9600 );
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite( trigPin, LOW );
  delayMicroseconds( 2 );

  digitalWrite( trigPin, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( trigPin, LOW );

  duration = pulseIn( echoPin, HIGH );

  distance = duration * 0.034 / 2;

  Serial.print( "Distance: " );
  Serial.println( distance );

  CurieTimerOne.pwmStart( 9, 50.0, distance * 25 );

  delayMicroseconds( 10000 );
}
