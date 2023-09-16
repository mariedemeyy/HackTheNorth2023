#include <ArxContainer.h>
String input;

arx::map<String, String> mp {
  {"a", "100000"},
  {"b", "110000"},
  {"c", "100100"},
  {"d", "100110"},
  {"e", "100010"},
  {"f", "110100"},
  {"g", "110110"},
  {"h", "110010"},
  {"i", "010100"},
  {"j", "010110"},
  {"k", "101000"},
  {"l", "111000"},
  {"m", "101100"},
  {"n", "101110"},
  {"o", "101000"},
  {"p", "111100"},
  {"q", "111110"},
  {"r", "111010"},
  {"s", "011100"},
  {"t", "011110"},
  {"u", "101001"},
  {"v", "111001"},
  {"w", "010111"},
  {"x", "101101"},
  {"y", "101111"},
  {"z", "101011"}
};

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
      

      // Print each element of the character array OR
      // do something with the character array
      for(int i = 0; i < WordLength - 1; i++)
      {
        // Get the Braille code for the letter in the array

        Serial.print("letter: ");
        Serial.println(WordArray[i]); 
        Serial.print("braille code: ");
        Serial.println(String(WordArray[i])); 
        Serial.println(mp[String(WordArray[i])]);

        // Serial.println("hello");
        // for (const auto& m : mp)
        // {
        //   if(m.first == WordArray[i]) {
        //     Serial.println("True");
        //   }
        //   Serial.println(mp["a"]);
        //   // Serial.print("{");
        //   // Serial.print(m.first); Serial.print(",");
        //   // Serial.print(m.second);
        //   // Serial.println("}");
        // }
        
      }
    }
    
}