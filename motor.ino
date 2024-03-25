#include <LDS.h>
LDS lidar; 

#define MIN_DISTANCE_TO_TURN 30 // Khoảng cách tối thiểu để quyết định rẽ trái hoặc rẽ phải
#define MAX_ANGLE_TO_TURN 45    // Góc tối đa để quyết định rẽ trái hoặc rẽ phải

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int  motor2pin2 = 5;

void setup() {
  Serial.begin(9600);
  lidar.begin();

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,  OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9,  OUTPUT); 
  pinMode(10, OUTPUT);

  
}

void loop() {
    float distance;
    int angle;

    lidar.getDistanceAngle(distance, angle);

    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.print("Angle: ");
    Serial.println(angle);
 
    if (distance <= MIN_DISTANCE_TO_TURN && abs(angle) <= MAX_ANGLE_TO_TURN) {
      if (angle < 0) {
        turnLeft(); 
      } else {
        turnRight(); 
      }
    } else {
      moveForward(); 
    }
  }
}



void moveForward() {
  analogWrite(9, 150); 
  analogWrite(10, 150); 

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void turnLeft() {
  analogWrite(9, 100); 
  analogWrite(10, 100); 
  //(Optional)
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void turnRight() {
  analogWrite(9, 100); 
  analogWrite(10, 100); 
  
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}