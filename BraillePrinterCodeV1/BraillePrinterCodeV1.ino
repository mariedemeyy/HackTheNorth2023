String input;
 
void setup() {
    Serial.begin(9600); 
    delay(2000);  
 
    Serial.println("Type something!");
}
 
void loop() {
    if(Serial.available()){
        input = Serial.readStringUntil('\n');
          Serial.print("You typed: " );
          Serial.println(input);
      
      int WordLength = input.length() + 1;  
      char WordArray[WordLength]; 

      input.toCharArray(WordArray, WordLength); 

      for(int i = 0; i < WordLength; i++)
      {
        Serial.println(WordArray[i]); 
      }
    
    }
}