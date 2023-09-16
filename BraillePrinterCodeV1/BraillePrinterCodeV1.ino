#include <ArxContainer.h>
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
    arx::map<String, String> mp {
      {"a", "100000"}, 
      {"b", "110000"}
    };
  // range based access
  for (const auto& m : mp)
  {
      Serial.print("{");
      Serial.print(m.first); Serial.print(",");
      Serial.print(m.second);
      Serial.println("}");
  }
}