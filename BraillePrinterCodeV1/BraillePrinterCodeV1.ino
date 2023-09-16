#include <ArxContainer.h>
String input;
 
void setup() {
    Serial.begin(9600); 
    delay(2000);  
 
    Serial.println("Type something!");
}

void loop() {
    if(Serial.available()){
      // Save the text before the carriage return to a string
      input = Serial.readStringUntil('\n');
      Serial.print("You typed: " );
      Serial.println(input);
      
      // Convert to text to an array of characters
      int WordLength = input.length() + 1;  
      char WordArray[WordLength]; 
      input.toCharArray(WordArray, WordLength); 
      
      arx::map<String, String> mp {
      {"a", "100000"}, 
      {"b", "110000"}
      };

      // Print each element of the character array OR
      // do something with the character array
      for(int i = 0; i < WordLength; i++)
      {
        // Compare the letter to the dictionary
        Serial.println("hello");
        for (const auto& m : mp)
        {
          if(m.first == WordArray[i]) {
            Serial.println("True");
          }
          Serial.println(mp["a"]);
          // Serial.print("{");
          // Serial.print(m.first); Serial.print(",");
          // Serial.print(m.second);
          // Serial.println("}");
        }
        
        Serial.println(WordArray[i]); 
      }
    }
    
}