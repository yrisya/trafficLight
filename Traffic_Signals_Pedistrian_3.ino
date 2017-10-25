/*
  Traffic_Signals_2
  This program operates six LEDs (two red, two yellow and two green) in a sequence simulating
  traffic lights at an intersection.  The main loop of the program goes through one cycle of
  the control with Signal 1 starting as green with Signal 2 starting as red - Signal 1 stays green
  for 5 seconds, then turns yellow for one second then turns red.  Then after a delay of 1/2 second,
  Signal 2 switches to green turning its red LED off.  Then Signal 2 stays green for 5 seconds,
  turns yellow for one second, and then after 1/2 second Signal 1 switches to green and Signal 2
  switches to red.

  In addition, the program also has provision to opperate two bottons as requests from pedestrians
  to switch the lights so that they can cross the road after cross traffic has been stopped.  This
  uses two blue LEDs to serve as indicators that the request has been made and to flash during the 
  time that the GREED light in the pedestrian direction is ON to indicate that the pedestrians can
  safely cross during that time.
  
  This main loop sequence then repeats continuously.
  
  This program was written by James M. Florence for the course EE1100 at UT Dallas.
  
*/

// The six controlling pins for the LEDs are specified

#define R1 3
#define Y1 4
#define G1 5
#define PED1 6
#define R2 7
#define Y2 8
#define G2 9
#define PED2 10
#define PED1_Button 12
#define PED2_Button 11

int PED1_Push = 0;
int PED2_Push = 0;
int PED1_ON = 0;
int PED2_ON = 0;
int count = 0;
  
// the setup routine runs once when you press reset:
void setup() {                
  // The six LED pins are all initialized as outputs.
  pinMode(R1, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(PED1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(PED2, OUTPUT);
  
  pinMode(PED1_Button, INPUT_PULLUP);
  pinMode(PED2_Button, INPUT_PULLUP);
  
// The initial state of the traffic signals is written to the LEDs  
  digitalWrite(R1, LOW);
  digitalWrite(Y1, LOW);
  digitalWrite(G1, HIGH);
  digitalWrite(PED1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(Y2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(PED2, LOW);
  PED1_Push = digitalRead(PED1_Button);
  PED2_Push = digitalRead(PED2_Button);  
}

// The main loop operating the traffic signals runs continously.
void loop() {
  
    // Make sure the Signal 1 is green    
    digitalWrite(G1, HIGH);
    // Signal 1 stays green for 5 seconds
    count = 0;
    while (count < 5000) {
      delay(1);
    PED2_Push = digitalRead(PED2_Button);
    if (PED2_Push == LOW) {
      digitalWrite(PED2, HIGH);
      count = 5000;
      PED2_ON = 1;
    }
    if (PED1_ON == 1) {
      if (count > 0 && count < 450) {digitalWrite(PED1, HIGH); }
      if (count > 450 && count < 900) {digitalWrite(PED1, LOW); }
      if (count > 900 && count < 1350) {digitalWrite(PED1, HIGH); }
      if (count > 1350 && count < 1800) {digitalWrite(PED1, LOW); }
      if (count > 1800 && count < 2250) {digitalWrite(PED1, HIGH); }
      if (count > 2250 && count < 2700) {digitalWrite(PED1, LOW); }
      if (count > 2700 && count < 3150) {digitalWrite(PED1, HIGH); }
      if (count > 3150 && count < 3600) {digitalWrite(PED1, LOW); }
      if (count > 3600 && count < 4050) {digitalWrite(PED1, HIGH); }
      if (count > 4050 && count < 4500) {digitalWrite(PED1, LOW); }
      if (count > 4500 && count < 5000) {digitalWrite(PED1, HIGH); }
      if (count == 5000) {digitalWrite(PED1, LOW); }
    } 
    count++;

    }

    PED1_ON = 0;
    
//    delay(5000);
    // Signal 1 switches to yellow for 1 second
    digitalWrite(G1, LOW);
    digitalWrite(PED1, LOW);
    digitalWrite(Y1, HIGH);
    delay(1000);
    // Signal 1 then switches to red
    digitalWrite(Y1, LOW);
    digitalWrite(R1, HIGH);
    // After a 1/2 second delay, Signal 2 switches from red to green
    delay(500);
    digitalWrite(R2, LOW);
    digitalWrite(G2, HIGH);

    // Signal 2 stays green for 5 seconds
        count = 0;
    while (count < 5000) {
      delay(1);
    PED1_Push = digitalRead(PED1_Button);
    if (PED1_Push == LOW) {
      digitalWrite(PED1, HIGH);
      count = 5000;
      PED1_ON = 1;
    }
    if (PED2_ON == 1) {
      if (count > 0 && count < 450) {digitalWrite(PED2, HIGH); }
      if (count > 450 && count < 900) {digitalWrite(PED2, LOW); }
      if (count > 900 && count < 1350) {digitalWrite(PED2, HIGH); }
      if (count > 1350 && count < 1800) {digitalWrite(PED2, LOW); }
      if (count > 1800 && count < 2250) {digitalWrite(PED2, HIGH); }
      if (count > 2250 && count < 2700) {digitalWrite(PED2, LOW); }
      if (count > 2700 && count < 3150) {digitalWrite(PED2, HIGH); }
      if (count > 3150 && count < 3600) {digitalWrite(PED2, LOW); }
      if (count > 3600 && count < 4050) {digitalWrite(PED2, HIGH); }
      if (count > 4050 && count < 4500) {digitalWrite(PED2, LOW); }
      if (count > 4500 && count < 5000) {digitalWrite(PED2, HIGH); }
      if (count == 5000) {digitalWrite(PED2, LOW); }
    } 
    
    count++;

    }

    PED2_ON = 0;
    
//    delay(5000);
    // Then Signal 2 switches to yellow for 1 second
    digitalWrite(G2, LOW);
    digitalWrite(PED2, LOW);
    digitalWrite(Y2, HIGH);
    delay(1000);
    // Then Signal 2 switches to red
    digitalWrite(Y2, LOW);
    digitalWrite(R2, HIGH);
    // After a delay of 1/2 second Signal 1 is switched to green
    delay(500);
    digitalWrite(R1, LOW);
    digitalWrite(G1, HIGH);
  
}
