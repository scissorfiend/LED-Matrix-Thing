long processSyncMessage() 
{
  Serial.print(F("processing!"));
  char timeHeader = TIME_HEADER;

  /*
  const char osc_test = 'O';
   const char reload_header = 'R';
   const char stop_osc = 'S';
   const char set_alarm = 'A';
   const char exit_debug = 'X';
   const char read_alarm = 'L';
   const char scan_test = 'T';
   const char motor_test = 'M';
   const char magnet_test = 'G';
   */
  // if time sync available from serial port, update time and return true
  if (Serial.available() ==  TIME_MSG_LEN )        // time message consists of header & 8 ASCII digits
  {
    char c = Serial.read() ;

    Serial.print(F("Recieved Header - "));
    Serial.println(c);  

    if ( c == timeHeader ) 
    {  
      Serial.println(F("Recieved Correct String Header")); 


      for (int i=0; i < TIME_MSG_LEN -1; i++)
      {  


        inChar = Serial.read(); // Read a character
        inData[i] = inChar; // Store it
        
        Serial.print(F("i - "));
        Serial.println(i);
        
        index++; // Increment where to write next
        //inData[i] = '\0'; // Null terminate the string
        Serial.print(F("Element Data - "));
        Serial.println(inData[i]);

      }



      delay(100);
    }  
    Serial.flush();
  }

else {
  Serial.println(F("Incorrect MSG Length"));
  Serial.end();
  Serial.begin(9600);
}
}

