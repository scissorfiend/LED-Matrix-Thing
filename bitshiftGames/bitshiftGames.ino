


#define TIME_MSG_LEN  9 //length of time message
#define TIME_HEADER  'M' ;  // Header tag for serial time sync message

char inData[7]; // Allocate some space for the string
char inChar; // Where to store the character read
byte index = 0; // Index into array; where to store the character

const char timeHeader = TIME_HEADER; //TIMEHEADER!!

String allOff = String(0b00000000);
String allOn  = String(0b11111111);
String halfOn  = String(0b10101010);
//String arrayFun[4]  = { String(0b10101010), String(0b11111111), String(0b10101010), String(0b00000000) };
String playVal  ;
int ledPin = 13;
/*
union charMaps
{
  
 byte rowData[];
 byte colData[];
}
*/

byte rowData[4];
byte colData[4];

byte *charframe1Name[7] = {
} 
;




byte charAf1[7] = {
  B10000000,
  B00000000,
  B11000000,
  B00100000,
  B10010000,
  B00001000,
  B10000000 
};

byte charAf2[7] = {
  B01001000,
  B00000000,
  B00001000,
  B00000000,
  B01001000,
  B00000000,
  B01011000 
};

byte charAf3[7] = {
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00000000,
  B00000000 
};

byte charAf4[7] = {
  B00000000,
  B00000000,
  B11110000,
  B11110000,
  B11110000,
  B11110000,
  B11110000 
};






void setup() {
  Serial.begin(9600);
  Serial.print(F("Setup"));
  delay(100);
  pinMode(ledPin, OUTPUT); 
}





void loop() {
  while(!Serial.available()) {

    /*
    for(int i = 0; i < 4; i++) {
     
     digitalWrite(ledPin, HIGH);
     Serial.print(F("playVal : "));
     Serial.println(playVal.toInt(), DEC);
     //int valJar = playVal.toInt();
     //Serial.print(F("valJar : "));
     //Serial.println(valJar, BIN);
     playVal += arrayFun[i];
     playVal += String("*");
     Serial.print(F("allOn : "));
     Serial.println(allOn.toInt(), BIN);
     Serial.print(F("i : "));
     Serial.println(i);
     
     Serial.print(F("length : "));
     Serial.println(playVal.length());
     
     delay(500); 
     digitalWrite(ledPin, LOW);
     delay(500);
     }
     */
   
   
   
    Serial.println(F("LOOP"));
    calculateString(charAf1, 0 );
    calculateString(charAf2, 1 );
    calculateString(charAf3, 2 );
    calculateString(charAf4, 3 );
    //Serial.println(String(charCols));
    delay(10000);
  }
    if( Serial.available() >= 1)
    {
      Serial.print(F("Serial Recieved"));
      processSyncMessage();
    }
    
    delay(10000);

  }
  

byte calculateString(byte* charframe1Name, byte chardataElem){

  Serial.println(F("calc"));


  //check if row is used in frame bitmap
  for (int y = 0; y < 7; y++) 
  { 

    if (charframe1Name[y] > 1)
    {
      bitWrite(rowData[chardataElem], y, 1) ;///  write cathode patterns into rowData array as bytes
    }
    else
    {
      bitWrite(rowData[chardataElem], y, 0) ;
    }
  }

  //check which columns are used in frame bitmap by ORing all lines together
  for (int u = 0; u < 7; u++)
  {
    colData[chardataElem] |= charframe1Name[u];
  }



  Serial.print(F("Char Data Array Element Number: Binary - "));
  Serial.println(chardataElem);
  Serial.print(F("Row Data Array Element Value - "));
  Serial.print(rowData[chardataElem], BIN);
  Serial.print(F(" - Decimal - "));
  Serial.println(rowData[chardataElem], DEC);
  Serial.print(F("Column Data Array Element Value - "));
  Serial.print(colData[chardataElem], BIN);
  Serial.print(F(" - Decimal - "));
  Serial.println(colData[chardataElem], DEC);
  //compare rows among
  //}

 // calculate how many different cathode patterns are used 
   //write into
   for (int z = 0; z < 5; z++)
   {
   if (rowData[z+1] == rowData[z])
   {
   rowData[z] = rowData[z+1];
   }
   }
   
}







