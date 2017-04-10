/*
This is the program that controls my Electric Vehicle (wood wheel version timings).
It uses pins 7 and 9-12 for input by grounding out.
*/
// Time in milliseconds the motor runs per length
int time90  = 4810;   // 9 meter time
int time120 = 6320;   // 12 meter time
int brakedelay = 550;

// Button declarations, button90Pin is button for 9.0 meters
int motorfwminus = 2;
int motorfwplus = 3;
int motorbkplus = 4;
int motorbkminus = 5;
int button1Pin  = 8;
int button2Pin  = 9;
int button4Pin  = 10;
int button8Pin  = 11;
int button16Pin = 12;
int button32Pin = 13;
int startbuttonPin = 7;
int pinnum;

void setup(){
   pinMode(motorfwminus, OUTPUT);
   pinMode(motorfwplus, OUTPUT);
   pinMode(motorbkplus, OUTPUT);
   pinMode(motorbkminus, OUTPUT);
   digitalWrite(motorfwminus,HIGH);
   digitalWrite(motorfwplus,HIGH);
   digitalWrite(motorbkplus,HIGH);
   digitalWrite(motorbkminus,HIGH);
   // Define button pins as input and activate the internal pull-up resistor
   pinMode(button1Pin, INPUT_PULLUP);
   pinMode(button2Pin, INPUT_PULLUP);
   pinMode(button4Pin, INPUT_PULLUP);
   pinMode(button8Pin, INPUT_PULLUP);
   pinMode(button16Pin, INPUT_PULLUP);
   pinMode(startbuttonPin,INPUT_PULLUP);
   
   Serial.begin(9600);
}

void loop(){
   // Read the value of the input. It can either be 1 or 0
   int button1Value = digitalRead(button1Pin);
   delay(1);
   int button2Value = digitalRead(button2Pin);
   delay(1);
   int button4Value = digitalRead(button4Pin);
   delay(1);
   int button8Value = digitalRead(button8Pin);
   delay(1);
   int button16Value = digitalRead(button16Pin);
   delay(1);
   int button32Value = digitalRead(button32Pin);
   delay(1);
   int startbuttonValue = digitalRead(startbuttonPin);
   
   int pinnum = 0;
   if (button1Value == LOW)  {pinnum = pinnum + 1;}
   if (button2Value == LOW)  {pinnum = pinnum + 2;}
   if (button4Value == LOW)  {pinnum = pinnum + 4;}
   if (button8Value == LOW)  {pinnum = pinnum + 8;}
   if (button16Value == LOW) {pinnum = pinnum + 16;}
   if (button32Value == LOW) {pinnum = pinnum + 32;}
   int runtime = map(pinnum,0,60,time90,time120);

   if (startbuttonValue == LOW) {
    Serial.print("Running for ");
    Serial.print(runtime);
    Serial.println(" milliseconds");
    Serial.print("Input value: ");
    Serial.println(pinnum);
    runFunction(runtime, brakedelay);
   };
  delay(10);

}   // End of loop

   int runFunction(int runtime, int brakedelay){
      // If button pushed, turn motor on
      digitalWrite(motorfwminus,LOW);
      digitalWrite(motorfwplus, LOW);
      Serial.println("Motor started");
      delay(runtime);
      digitalWrite(motorfwminus,HIGH);
      digitalWrite(motorfwplus,HIGH);
      int button120Value = HIGH;
      Serial.println(" Motor stopped");
      digitalWrite(motorbkplus,LOW);
      digitalWrite(motorbkminus,LOW);
      delay(brakedelay);
      digitalWrite(motorbkplus,HIGH);
      digitalWrite(motorbkminus,HIGH);
   }
   
