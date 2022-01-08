#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
Servo servo[20] = {};

#include "hash_v3.h"

/* Initializing servo drive and OLED display */
void hash_v3::init_hash() {
  int servo_pins[20] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
  for (int i = 0; i < 20; i++) {
    servo[i].attach(servo_pins[i]);
  }
}

/* Initial position */
void hash_v3::initial_position() {
  int degree_array[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  for (int i = 0; i < 20; i++) {
    servo_position[i] = degree_array[i];
  }
  move_servo(2000, degree_array);
}
/* Moving each servo at given time interval */
void hash_v3::move_servo(int time, int  servo_target[]) {

  if (time > 10) {
    for (int i = 0; i < 20; i++) {
      increment[i] = ((servo_target[i]) - servo_position[i]) / (time / 10.0);
    }
    final_time =  millis() + time;

    for (int iteration = 1; millis() < final_time; iteration++) {
      partial_time = millis() + 10;

      for (int i = 0; i < 20; i++) {
        servo[i].write((int)(servo_position[i] + (iteration * increment[i])));
      }
      while (millis() < partial_time);
    }
  }
  else {
    for (int i = 0; i < 20; i++) {
      servo[i].write((int)servo_target[i]);
    }
  }
  for (int i = 0; i < 20; i++) {
    servo_position[i] = servo_target[i];
  }
}

/******************************************************************************************************/

void hash_v3::say_hi(int count, int speed) {

  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 90, 90, 150, 150, 150, 90, 90};
  move_servo(speed * 2, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 90, 60, 150, 150, 150, 90, 90};
    int degree_array3[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 90, 120, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array2);
    move_servo(speed, degree_array3);
  }
  int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 90, 90, 150, 150, 150, 90, 90};
  int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array4);
  move_servo(speed * 2, degree_array5);
}

/******************************************************************************************************/

void hash_v3::hands_up(int count, int speed) {

  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 30, 30, 0, 150, 150, 90, 90};
    move_servo(speed, degree_array2);
    delay(3000);
  }
  int degree_array3[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed , degree_array3);
}

/******************************************************************************************************/

void hash_v3::forward(int steps, int speed) {
  //  if (speed < 500) {
  //    speed = 500;
  //  }
  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  int degree_array2[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  int degree_array3[20] = {110, 150, 120, 65, 110, 90, 105, 30, 30, 150, 90, 90, 20, 30, 30, 120, 150, 150, 90, 90};
  int degree_array4[20] = {90, 150, 120, 65, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array1);
  move_servo(speed, degree_array2);
  move_servo(speed, degree_array3);
  move_servo(speed, degree_array4);
  for (int i = 1; i <= steps; i++) {
    int degree_array5[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int degree_array6[20] = {75, 150, 150, 30, 90, 90, 70, 30, 60, 120, 70, 90, 60, 30, 30, 160, 150, 150, 90, 90};
    int degree_array7[20] = {90, 150, 150, 30, 90, 90, 90, 30, 60, 120, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int degree_array8[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int degree_array9[20] = {110, 150, 120, 65, 110, 90, 105, 30, 30, 150, 90, 90, 20, 30, 30, 120, 150, 150, 90, 90};
    int degree_array10[20] = {90, 150, 120, 65, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array5);
    move_servo(speed, degree_array6);
    move_servo(speed, degree_array7);
    move_servo(speed, degree_array8);
    move_servo(speed, degree_array9);
    move_servo(speed, degree_array10);
  }
  int degree_array11[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array11);
}

/******************************************************************************************************************/

void hash_v3::turn_right(int steps, int speed) {
  //  if (speed < 500) {
  //    speed = 500;
  //  }
  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= steps; i++) {
    int pwm_array2[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array3[20] = {75, 150, 145, 30, 90, 80, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array4[20] = {90, 150, 145, 30, 90, 80, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array5[20] = {110, 150, 150, 30, 110, 80, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array6[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array7[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed, pwm_array3);
    move_servo(speed, pwm_array4);
    move_servo(speed, pwm_array5);
    move_servo(speed, pwm_array6);
    move_servo(speed, pwm_array7);
  }
  int pwm_array8[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array8);
}

/******************************************************************************************************/

void hash_v3::turn_left(int steps, int speed) {
  //  if (speed < 500) {
  //    speed = 500;
  //  }
  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= steps; i++) {
    int pwm_array2[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array3[20] = {110, 150, 150, 30, 110, 90, 105, 30, 35, 150, 90, 100, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 35, 150, 90, 100, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array5[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 100, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array6[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array7[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed, pwm_array3);
    move_servo(speed, pwm_array4);
    move_servo(speed, pwm_array5);
    move_servo(speed, pwm_array6);
    move_servo(speed, pwm_array7);
  }
  int pwm_array8[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array8);
}

/******************************************************************************************************/

void hash_v3::move_right(int steps, int speed) {
  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= steps; i++) {
    int pwm_array2[20] = {110, 150, 150, 30, 112, 90, 90, 30, 30, 150, 90, 90, 30, 60, 30, 120, 150, 150, 90, 90};
    int pwm_array3[20] = {70, 150, 150, 30, 70, 90, 70, 30, 30, 150, 70, 90, 30, 60, 30, 120, 150, 150, 90, 90};
    int pwm_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed, pwm_array3);
    move_servo(speed, pwm_array4);
  }
  int pwm_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array5);
}

/******************************************************************************************************/

void hash_v3::move_left(int steps, int speed) {
  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= steps; i++) {
    int pwm_array2[20] = {90, 150, 150, 30, 90, 90, 70, 30, 30, 150, 68, 90, 50, 30, 30, 150, 120, 150, 90, 90};
    int pwm_array3[20] = {110, 150, 150, 30, 110, 90, 110, 30, 30, 150, 110, 90, 50, 30, 30, 150, 120, 150, 90, 90};
    int pwm_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed, pwm_array3);
    move_servo(speed, pwm_array4);
  }
  int pwm_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array5);
}

/******************************************************************************************************/

void hash_v3::ball_kick_right(int count, int speed) {
  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= count; i++) {
    int pwm_array2[20] = {112, 150, 150, 30, 110, 90, 112, 30, 30, 150, 90, 90, 10, 30, 30, 90, 150, 150, 90, 90};
    int pwm_array3[20] = {112, 130, 140, 10, 110, 90, 112, 30, 30, 150, 90, 90, 10, 30, 30, 90, 150, 150, 90, 90};
    int pwm_array4[20] = {112, 150, 140, 60, 110, 90, 112, 30, 30, 150, 90, 90, 10, 30, 30, 90, 150, 150, 90, 90};
    int pwm_array5[20] = {112, 150, 150, 30, 110, 90, 112, 30, 30, 150, 90, 90, 10, 30, 30, 90, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed / 2, pwm_array3);
    move_servo(speed / 2, pwm_array4);
    move_servo(speed, pwm_array5);
  }
  int pwm_array6[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array6);
}

/******************************************************************************************************/

void hash_v3::ball_kick_left(int count, int speed) {
  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= count; i++) {
    int pwm_array2[20] = {70, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 90, 30, 30, 170, 150, 150, 90, 90};
    int pwm_array3[20] = {70, 150, 150, 30, 90, 90, 70, 50, 40, 170, 70, 90, 90, 30, 30, 170, 150, 150, 90, 90};
    int pwm_array4[20] = {70, 150, 150, 30, 90, 90, 70, 30, 40, 120, 70, 90, 90, 30, 30, 170, 150, 150, 90, 90};
    int pwm_array5[20] = {70, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 90, 30, 30, 170, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed / 2, pwm_array3);
    move_servo(speed / 2, pwm_array4);
    move_servo(speed, pwm_array5);
  }
  int pwm_array6[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array6);
}

/******************************************************************************************************/

void hash_v3::max_sit(int count, int speed) {
  for (int i = 1; i <= count; i++) {
    int degree_array1[20] = {90, 70, 60, 30, 90, 90, 90, 110, 120, 150, 90, 90, 30, 60, 30, 150, 120, 150, 90, 90};
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array1);
    delay(3000);
    move_servo(speed, degree_array2);
  }
}

/******************************************************************************************************/

void hash_v3::bow(int count, int speed) {
  for (int i = 1; i <= count; i++) {
    int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 50, 50, 30, 130, 130, 150, 90, 90};
    int degree_array2[20] = {90, 160, 150, 60, 90, 90, 90, 20, 30, 120, 90, 90, 50, 50, 30, 130, 130, 150, 90, 90};
    int degree_array3[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 50, 50, 30, 130, 130, 150, 90, 90};
    move_servo(speed / 2, degree_array1);
    move_servo(speed, degree_array2);
    delay(3000);
    move_servo(speed, degree_array3);
  }
  int pwm_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array4);
}

/******************************************************************************************************/

void hash_v3::right_bow(int count, int speed) {
  for (int i = 1; i <= count; i++) {
    int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 90, 30, 30, 180, 150, 150, 90, 90};
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 90, 30, 90, 180, 150, 120, 90, 90};
    int degree_array3[20] = {90, 160, 150, 60, 90, 90, 90, 20, 30, 120, 90, 90, 90, 30, 90, 180, 150, 120, 90, 90};
    int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 90, 30, 90, 180, 150, 120, 90, 90};
    int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 90, 30, 30, 180, 150, 150, 90, 90};
    move_servo(speed / 2, degree_array1);
    move_servo(speed / 2, degree_array2);
    move_servo(speed, degree_array3);
    delay(2000);
    move_servo(speed, degree_array4);
    move_servo(speed / 2, degree_array5);
  }
  int degree_array6[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array6);
}

/******************************************************************************************************/

void hash_v3::left_bow(int count, int speed) {
  for (int i = 1; i <= count; i++) {
    int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 0, 30, 30, 90, 150, 150, 90, 90};
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 0, 30, 60, 90, 150, 90, 90, 90};
    int degree_array3[20] = {90, 160, 150, 60, 90, 90, 90, 20, 30, 120, 90, 90, 0, 30, 60, 90, 150, 90, 90, 90};
    int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 0, 30, 60, 90, 150, 90, 90, 90};
    int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 0, 30, 30, 90, 150, 150, 90, 90};
    move_servo(speed / 2, degree_array1);
    move_servo(speed / 2, degree_array2);
    move_servo(speed, degree_array3);
    delay(2000);
    move_servo(speed, degree_array4);
    move_servo(speed / 2, degree_array5);
  }
  int degree_array6[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array6);
}

/******************************************************************************************************/

void hash_v3::ape_move(int count, int speed) {
  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 60, 60, 60, 120, 120, 90, 90};
  int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 60, 120, 60, 120, 120, 90, 90};
  move_servo(speed, degree_array1);
  move_servo(speed, degree_array2);
  for (int i = 1; i <= count; i++) {
    int degree_array3[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 60, 60, 60, 120, 60, 120, 90};
    int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 60, 120, 60, 120, 120, 60, 90};
    move_servo(speed / 2, degree_array3);
    move_servo(speed / 2, degree_array4);
  }
  int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 60, 60, 60, 120, 120, 90, 90};
  int degree_array6[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array5);
  move_servo(speed, degree_array6);
}

/******************************************************************************************************/

void hash_v3::push_up(int count, int speed) {
  int degree_array1[20] = {90, 70, 60, 30, 90, 90, 90, 110, 120, 150, 90, 90, 30, 60, 30, 150, 120, 150, 90, 90};
  int degree_array2[20] = {90, 70, 60, 30, 150, 90, 90, 110, 120, 150, 30, 90, 30, 60, 30, 150, 120, 150, 90, 90};
  int degree_array3[20] = {90, 70, 60, 30, 150, 90, 90, 110, 120, 150, 30, 90, 90, 30, 30, 90, 150, 150, 90, 90};
  int degree_array4[20] = {90, 70, 60, 0, 150, 90, 90, 110, 120, 180, 30, 90, 90, 30, 30, 90, 150, 150, 90, 90};
  int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 100, 30, 30, 80, 150, 150, 90, 90};
  move_servo(speed, degree_array1);
  move_servo(speed, degree_array2);
  move_servo(speed, degree_array3);
  move_servo(speed, degree_array4);
  move_servo(speed, degree_array5);
  for (int i = 1; i <= count; i++) {
    int degree_array6[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 100, 90, 90, 80, 90, 90, 90, 90};
    int degree_array7[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 100, 30, 30, 80, 150, 150, 90, 90};
    move_servo(speed, degree_array6);
    move_servo(speed, degree_array7);
  }
  int degree_array8[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 100, 90, 90, 80, 90, 90, 90, 90};
  int degree_array9[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 180, 180, 60, 0, 0, 90, 90};
  int degree_array10[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 180, 30, 60, 0, 150, 90, 90};
  int degree_array11[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 120, 100, 10, 60, 80, 170, 90, 90};
  int degree_array12[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 100, 10, 150, 80, 170, 90, 90};
  int degree_array13[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array8);
  move_servo(speed, degree_array9);
  move_servo(speed, degree_array10);
  move_servo(speed, degree_array11);
  move_servo(speed, degree_array12);
  move_servo(speed, degree_array13);
}

/******************************************************************************************************/

void hash_v3::clap(int count, int speed) {
  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 20, 30, 0, 160, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 20, 90, 0, 160, 90, 90, 90};
    int degree_array3[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 180, 20, 30, 0, 160, 150, 90, 90};
    move_servo(speed / 2, degree_array2);
    move_servo(speed / 2, degree_array3);
  }
  int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array4);
}

/******************************************************************************************************/

void hash_v3::right_leg_up(int count, int speed) {
  int degree_array1[20] = {110, 150, 150, 30, 110, 90, 114, 30, 30, 150, 90, 90, 30, 90, 30, 150, 90, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {110, 150, 150, 30, 110, 90, 114, 30, 30, 150, 90, 90, 30, 150, 30, 150, 30, 150, 90, 90};
    int degree_array3[20] = {110, 150, 150, 30, 110, 90, 114, 30, 30, 150, 90, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    move_servo(speed / 2, degree_array2);
    move_servo(speed / 2, degree_array3);
  }
  int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array4);
}

/******************************************************************************************************/

void hash_v3::left_leg_up(int count, int speed) {

  int degree_array1[20] = {70, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 90, 30, 150, 90, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {70, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 150, 30, 150, 30, 150, 90, 90};
    int degree_array3[20] = {70, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    move_servo(speed / 2, degree_array2);
    move_servo(speed / 2, degree_array3);
  }

  int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array4);
}

/******************************************************************************************************/

void hash_v3::hip_pose(int count, int speed) {
  for (int i = 1; i <= count; i++) {
    int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 90, 120, 150, 90, 60, 90, 90};
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array1);
    delay(3000);
    move_servo(speed, degree_array2);
  }
}

/******************************************************************************************************/

void hash_v3::right_leg_balance(int count, int speed) {
  for (int i = 1; i <= count; i++) {
    int degree_array1[20] = {70, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    int degree_array2[20] = {70, 150, 150, 30, 90, 90, 70, 110, 120, 150, 70, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    int degree_array3[20] = {70, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array1);
    delay(3000);
    move_servo(speed, degree_array2);
    move_servo(speed, degree_array3);
    move_servo(speed, degree_array4);
  }
}

/******************************************************************************************************/

void hash_v3::left_leg_balance(int count, int speed) {
  for (int i = 1; i <= count; i++) {
    int degree_array1[20] = {110, 150, 150, 30, 110, 90, 110, 30, 30, 150, 90, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    int degree_array2[20] = {90, 70, 60, 30, 110, 90, 110, 30, 30, 150, 90, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    int degree_array3[20] = {110, 150, 150, 30, 110, 90, 110, 30, 30, 150, 90, 90, 30, 90, 30, 150, 90, 150, 90, 90};
    int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array1);
    delay(3000);
    move_servo(speed, degree_array2);
    move_servo(speed, degree_array3);
    move_servo(speed, degree_array4);
  }
}

/******************************************************************************************************/

void hash_v3::flying_action(int count, int speed) {
  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 120, 30, 150, 60, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 150, 90, 150, 30, 90, 90, 90};
    int degree_array3[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 90, 0, 150, 90, 180, 90, 90};
    move_servo(speed / 2, degree_array2);
    move_servo(speed / 2, degree_array3);
  }
  int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 120, 30, 150, 60, 150, 90, 90};
  int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed / 2 , degree_array4);
  move_servo(speed, degree_array5);
}

/******************************************************************************************************/

void hash_v3::hand_sit_zigzak(int count, int speed) {

  int degree_array1[20] = {90, 100, 95, 30, 90, 90, 90, 80, 85, 150, 90, 90, 30, 120, 120, 150, 60, 60, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {90, 100, 95, 30, 90, 90, 90, 80, 85, 150, 90, 90, 30, 120, 90, 150, 60, 30, 120, 90};
    int degree_array3[20] = {90, 100, 95, 30, 90, 90, 90, 80, 85, 150, 90, 90, 30, 120, 150, 150, 60, 90, 60, 90};
    move_servo(speed / 2, degree_array2);
    move_servo(speed / 2, degree_array3);
  }
  int degree_array4[20] = {90, 100, 95, 30, 90, 90, 90, 80, 85, 150, 90, 90, 30, 120, 120, 150, 60, 60, 90, 90};
  int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed / 2 , degree_array4);
  move_servo(speed, degree_array5);
}

/******************************************************************************************************/

void hash_v3::side_shake(int count, int speed) {

  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {110, 150, 150, 30, 110, 90, 110, 30, 30, 150, 110, 90, 30, 60, 30, 150, 90, 150, 90, 90};
    int degree_array3[20] = {70, 150, 150, 30, 70, 90, 70, 30, 30, 150, 70, 90, 30, 90, 30, 150, 120, 150, 90, 90};
    move_servo(speed, degree_array2);
    move_servo(speed, degree_array3);
  }
  int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed , degree_array4);
}

/******************************************************************************************************/

void hash_v3::hip_shake(int count, int speed) {

  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {90, 150, 150, 30, 90, 60, 90, 30, 30, 150, 90, 60, 10, 30, 30, 130, 150, 150, 90, 90};
    int degree_array3[20] = {90, 150, 150, 30, 90, 120, 90, 30, 30, 150, 90, 120, 50, 30, 30, 170, 150, 150, 90, 90};
    move_servo(speed, degree_array2);
    move_servo(speed, degree_array3);
  }
  int degree_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed , degree_array4);
}

/******************************************************************************************************/

void hash_v3::bend_up(int count, int speed) {

  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array1);
  for (int i = 1; i <= count; i++) {
    int degree_array2[20] = {90, 180, 120, 130, 90, 90, 90, 0, 60, 50, 90, 90, 110, 30, 30, 70, 150, 150, 90, 90};
    int degree_array3[20] = {90, 180, 140, 130, 90, 90, 90, 0, 40, 50, 90, 90, 110, 30, 30, 70, 150, 150, 90, 90};
    int degree_array4[20] = {90, 180, 120, 130, 90, 90, 90, 0, 60, 50, 90, 90, 110, 30, 30, 70, 150, 150, 90, 90};
    int degree_array5[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array2);
    move_servo(speed, degree_array3);
    move_servo(speed, degree_array4);
    move_servo(speed, degree_array5);
  }
  int degree_array6[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed , degree_array6);
}

/******************************************************************************************************/
