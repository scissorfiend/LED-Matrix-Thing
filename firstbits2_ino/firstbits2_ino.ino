//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595s
int dataPin = 11;//cathodes


int ledPin = 13;

byte frameOne[3] ;
byte frameTwo[3] ;
byte frameThree[3] ;
byte frameFour[3] ;

//byte 1: cathodes(7s)
//byte 2: anodes(5s) Disp 4 and extra
//byte 3: anodes(5s) Disp 2, 3 and 4
//byte 4: anodes(5s) Disp 1 and 2

String frame1String = String(0b00000000000000000000000000000000);
String frame2String = String(0b00000000000000000000000000000000);

String frame3String = String(0b00000000000000000000000000000000);
String frame4String = String(0b00000000000000000000000000000000);

String frame5String = String(0b00000000000000000000000000000000);
String frame6String = String(0b00000000000000000000000000000000);

String frame17tring = String(0b00000000000000000000000000000000);
String frame28tring = String(0b00000000000000000000000000000000);



int sensorPin = A7;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor


void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(dataPin, OUTPUT);


  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  while(!Serial.available())
  {
    digitalWrite(ledPin, LOW);

    for (int i=0 ; i < 8 ; i++){
      digitalWrite(ledPin, LOW);
      sensorValue = analogRead(sensorPin);




      //frame 1
      digitalWrite(latchPin, LOW);
      // shift out the bits for frame one:
      shiftOut(dataPin, clockPin, LSBFIRST,  frameOne[1]);  //byte 1: cathodes(7s)
      shiftOut(dataPin, clockPin, LSBFIRST,  frameOne[2]); //byte 2: anodes(5s) Disp 4 and extra
      shiftOut(dataPin, clockPin, LSBFIRST,  frameOne[3]);  //byte 3: anodes(5s) Disp 2, 3 and 4
      shiftOut(dataPin, clockPin, LSBFIRST,  frameOne[4]);  //byte 4: anodes(5s) Disp 1 and 2

      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);

      // pause before showing next frame:
      delay(1);
      
      //frame 2
      digitalWrite(latchPin, LOW);
      // shift out the bits for frame two:
      shiftOut(dataPin, clockPin, LSBFIRST,  frameTwo[1]);  //byte 1: cathodes(7s)
      shiftOut(dataPin, clockPin, LSBFIRST,  frameTwo[2]); //byte 2: anodes(5s) Disp 4 and extra
      shiftOut(dataPin, clockPin, LSBFIRST,  frameTwo[3]); //byte 3: anodes(5s) Disp 2, 3 and 4
      shiftOut(dataPin, clockPin, LSBFIRST,  frameTwo[4]); //byte 4: anodes(5s) Disp 1 and 2

      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);
      delay(1);
      
      //frame 3
      digitalWrite(latchPin, LOW);
      // shift out the bits for frame two:
      shiftOut(dataPin, clockPin, LSBFIRST,  frameThree[1]);  //byte 1: cathodes(7s)
      shiftOut(dataPin, clockPin, LSBFIRST,  frameThree[2]); //byte 2: anodes(5s) Disp 4 and extra
      shiftOut(dataPin, clockPin, LSBFIRST,  frameThree[3]); //byte 3: anodes(5s) Disp 2, 3 and 4
      shiftOut(dataPin, clockPin, LSBFIRST,  frameThree[4]); //byte 4: anodes(5s) Disp 1 and 2

      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);  
      delay(1);
      
      //frame 4
      digitalWrite(latchPin, LOW);
      // shift out the bits for frame two:
      shiftOut(dataPin, clockPin, LSBFIRST,  frameFour[1]);  //byte 1: cathodes(7s)
      shiftOut(dataPin, clockPin, LSBFIRST,  frameFour[2]); //byte 2: anodes(5s) Disp 4 and extra
      shiftOut(dataPin, clockPin, LSBFIRST,  frameFour[3]); //byte 3: anodes(5s) Disp 2, 3 and 4
      shiftOut(dataPin, clockPin, LSBFIRST,  frameFour[4]); //byte 4: anodes(5s) Disp 1 and 2

      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);  
      delay(1);
    }

  }

}




void updateFrames (byte dispNo, byte textChar[]) {
  for(int i = 0; i < 5; i++)
  {
//    frameOne[i] = (frame1String );
 //   frameTwo[i] = (frame2String);
 //   frameThree[i] = (frame3String);
  }

}




byte calculateString(byte* charframe1Name){
byte colData[7];
  for (byte x; x > 8; x++ )
  {

    for (int y = 0; y < 8; y++) {
      bitWrite(colData[x],y, bitRead(charframe1Name[x], y)) ;
    }
  }
}








