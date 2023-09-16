#include <ArxContainer.h>
String input;


// horse heart error there earth

arx::map<char, String> mp {
  {'a', "100000"},
  {'b', "110000"},
  {'c', "100100"},
  {'d', "100110"},
  {'e', "100010"},
  {'f', "110100"},
  {'g', "110110"},
  {'h', "110010"},
  {'i', "010100"}
  // {'j', "010110"},
  // {'k', "101000"},
  // {'l', "111000"},
  // {'m', "101100"},
  // {'n', "101110"},
  // {'o', "101000"},
  // {'p', "111100"},
  // {'q', "111110"},
  // {'r', "111010"},
  // {'s', "011100"},
  // {'t', "011110"},
  // {'u', "101001"},
  // {'v', "111001"},
  // {'w', "010111"},
  // {'x', "101101"},
  // {'y', "101111"},
  // {'z', "101011"}
};

void setup() {
    Serial.begin(9600); 
 
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

      // HARDCODE FOR 5 LETTER WORDS ONLY
      char topRow[10]; 
      char middleRow[10];
      char bottomRow[10];
      int leftCol;
      int rightCol;
      

      // ISSUE WITH HOW IT PRINTS
      // TRYING WITH ABE
      // IT NEEDS TO PRINT E B A 
      for(int i = WordLength - 1; i >= 0; i--)
      {
        // Get the Braille code for the letter in the array
        Serial.print("letter: ");
        Serial.println(WordArray[i]); 

        String brailleCode = mp[WordArray[i]];
        Serial.print("try with char: ");
        Serial.println(brailleCode);
       
        for(int j = 0; j < WordLength - 1; j++) {
        
          leftCol = j * 2;
          rightCol = (j * 2) + 1;

          // Get 0 and 3 for topRow
          topRow[leftCol] = brailleCode.charAt(3);
          topRow[rightCol] = brailleCode.charAt(0);

          // Get 1 and 4 for middleRow
          middleRow[leftCol] = brailleCode.charAt(4);
          middleRow[rightCol] = brailleCode.charAt(1);

          // Get 2 and 5 for bottomRow
          bottomRow[leftCol] = brailleCode.charAt(5);
          bottomRow[rightCol] = brailleCode.charAt(2);

        }
      }
      // MOTOR STUFF, USE THE ARRAYS
      Serial.println("topRow");
      for(int i = 0; i < 10; i++) {
        Serial.print(topRow[i]);
      }
      Serial.println("middleRow");
      for(int i = 0; i < 10; i++) {
        Serial.print(middleRow[i]);
      }
      Serial.println("bottomRow");
      for(int i = 0; i < 10; i++) {
        Serial.print(bottomRow[i]);
      }
    }
    
}