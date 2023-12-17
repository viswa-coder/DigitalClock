#define DISP_LATCH 4 // The 3 pins that control the display
#define DISP_CLK 7
#define DISP_DATA 8
#define BUZZER 3 // The speaker enable

const byte numMap[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0X00, 0X10}; // Covert number to segment bits required
const byte digitMap[] = {0xF1, 0xF2, 0xF4, 0xF8}; // Convert digit number to shift bits
int count =2202;
long timer;

void dispNum(int digitNum, int Value) {
  digitalWrite(DISP_LATCH, LOW);
 
  if (digitNum == 0 || digitNum==2 || digitNum==3) {

     shiftOut(DISP_DATA, DISP_CLK, MSBFIRST, numMap[Value] |0x80);
    // Turn on the dot for the second display
    shiftOut(DISP_DATA, DISP_CLK, MSBFIRST, digitMap[digitNum]);
  } else {
     shiftOut(DISP_DATA, DISP_CLK, MSBFIRST, numMap[Value]);
    shiftOut(DISP_DATA, DISP_CLK, MSBFIRST, digitMap[digitNum]);
  }
  digitalWrite(DISP_LATCH, HIGH);
}

void setup() {

  pinMode(DISP_LATCH , OUTPUT);
  pinMode(DISP_CLK , OUTPUT);
  pinMode(DISP_DATA , OUTPUT);
    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER,HIGH);

  timer = millis() +30* 1000;
}


void loop() {
  // Separate out the individual digits

  int dig1 = count / 1000;
  int dig2 = (count - (1000 * dig1)) / 100;
  int dig3 = ( (count - (1000 * dig1))- (100 *(dig2))) /10;
  int dig4 = count%10;

  // Display the digits
   dispNum(0 , dig1);
  dispNum(1 , dig2);
  dispNum(2 , dig3);
  dispNum(3 , dig4);
  // Check to see if 1 second has passed. If so, set the timer to a second later and increment the count.
  if (2*timer < millis()) {
    if(count%100<60){
    count += 1;
    timer = timer + 30*1000;}
    else{
      count=count+40;
       timer = timer + 30*1000;
    }
  }

  if(count>2359){
    digitalWrite(BUZZER,LOW);
     delay(5000);
    digitalWrite(BUZZER,HIGH);
    count=0;
  }
  /*if(count>5959){
     digitalWrite(BUZZER,LOW);
     delay(5000);
    digitalWrite(BUZZER,HIGH);
    count=0;

  }*/
}