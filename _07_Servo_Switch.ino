#include <Servo.h>
#include <IRremote.h>

int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:

 irrecv.enableIRIn();
 myservo.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:

if (irrecv.decode(&results)) {

  if(results.value == 1 || results.value == 2049){

     myservo.write(-90); 
     delay(2000);
     myservo.write(90); 
  }

  /*if(results.value == 2 || results.value == 2050){
     
     myservo.write(-90); 
  
  }*/

  irrecv.resume(); 
}
return;

for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}
