
#include "hash_v3.h"

hash_v3 hashv3;
int degree[20];
int index = 0;
String content = "";
char character;
int eyeLED = 46;

void setup() {
  Serial.begin(115200);
  Serial.println("GPIO test!");
  pinMode(eyeLED, OUTPUT);

  hashv3.init_hash();
  eye_led();
  hashv3.initial_position();
  delay(5000);
  hashv3.say_hi(2, 1000);
  hashv3.hands_up(1, 3000);
  hashv3.forward(20, 500);
  hashv3.turn_right(5, 500);
  hashv3.turn_left(5, 500);
  hashv3.move_right(5, 800);
  hashv3.move_left(5, 800);
  hashv3.ball_kick_right(1, 1000);
  hashv3.ball_kick_left(1, 1000);
  hashv3.max_sit(1, 2000);
  hashv3.bow(1, 2000);
  hashv3.right_bow(1, 2000);
  hashv3.left_bow(1, 2000);
  hashv3.ape_move(3, 2000);
  hashv3.clap(3, 2000);
  hashv3.right_leg_up(3, 2000);
  hashv3.left_leg_up(3, 2000);
  hashv3.hip_pose(1, 2000);
  hashv3.right_leg_balance(1, 3000);
  hashv3.left_leg_balance(1, 3000);
  hashv3.flying_action(3, 2000);
  hashv3.hand_sit_zigzak(3, 2000);
  hashv3.side_shake(3, 1200);
  hashv3.hip_shake(3, 1200);
  hashv3.bend_up(1, 2000);
  hashv3.push_up(3, 3000);

}

void loop() {

}

void eye_led() {
  digitalWrite(eyeLED, HIGH);
}

void blink_eye() {
  digitalWrite(eyeLED, LOW);
  delay(250);
  digitalWrite(eyeLED, HIGH);
  delay(5000);
}

void serialEvent() {
  //Sample serial input: "90,150,150,30,90,90,90,30,30,150,90,90,30,30,30,150,150,150,90,90,"
  String degree;
  degree = Serial.readString();
  //Serial.println(degree);
  executeAngle(degree);
}

void executeAngle(String degree) {
  int angle_array[20], r = 0, t = 0;
  //Serial.println(degree);
  for (int i = 0; i < degree.length(); i++)
  {
    if (degree.charAt(i) == ',')
    {
      angle_array[t] = degree.substring(r, i).toInt();
      r = (i + 1);
      t++;
    }
  }
  for (int i = 0; i < 20; i++) {
    Serial.print(angle_array[i]);
    Serial.print("|");
  }
  Serial.println("");
  hashv3.move_servo(2000, angle_array);
}
