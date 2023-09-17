#include <ArxContainer.h>
#include <TinyStepper_28BYJ_48.h>
String input;

// TODO: MOTOR0
// const int MOTOR0_IN1_PIN = 1;
// const int MOTOR0_IN2_PIN = 2;
// const int MOTOR0_IN3_PIN = 3;
// const int MOTOR0_IN4_PIN = 4;

const int MOTOR1_IN1_PIN = 5;
const int MOTOR1_IN2_PIN = 6;
const int MOTOR1_IN3_PIN = 7;
const int MOTOR1_IN4_PIN = 8;

const int MOTOR2_IN1_PIN = 9;
const int MOTOR2_IN2_PIN = 10;
const int MOTOR2_IN3_PIN = 11;
const int MOTOR2_IN4_PIN = 12;

const int STEPS_PER_REVOLUTION = 2048;

// Create the stepper motor object
// TinyStepper_28BYJ_48 stepper0;
TinyStepper_28BYJ_48 stepper1;
TinyStepper_28BYJ_48 stepper2;

// Map with a selection of letters available.
// Letters that are commonly used in the English language where
// selected. Words such as horse, heart, error, there, earth can
// be constructed from these letters. 
arx::map<char, String> mp {
  {'a', "100000"},
  // {'b', "110000"},
  // {'c', "100100"},
  // {'d', "100110"},
  {'e', "100010"},
  // {'f', "110100"},
  // {'g', "110110"},
  {'h', "110010"},
  // {'i', "010100"},
  // {'j', "010110"},
  // {'k', "101000"},
  // {'l', "111000"},
  // {'m', "101100"},
  // {'n', "101110"},
  {'o', "101000"},
  // {'p', "111100"},
  // {'q', "111110"},
  {'r', "111010"},
  {'s', "011100"},
  {'t', "011110"}
  // {'u', "101001"},
  // {'v', "111001"},
  // {'w', "010111"},
  // {'x', "101101"},
  // {'y', "101111"},
  // {'z', "101011"}
};

void setup() {
    Serial.begin(9600); 
    Serial.println("");
    
    // Setup motor
    // stepper0.connectToPins(MOTOR0_IN1_PIN, MOTOR0_IN2_PIN, MOTOR0_IN3_PIN, MOTOR0_IN4_PIN);
    stepper1.connectToPins(MOTOR1_IN1_PIN, MOTOR1_IN2_PIN, MOTOR1_IN3_PIN, MOTOR1_IN4_PIN);
    stepper2.connectToPins(MOTOR2_IN1_PIN, MOTOR2_IN2_PIN, MOTOR2_IN3_PIN, MOTOR2_IN4_PIN);

    delay(1000);
    Serial.println("Enter a 5 letter word in lower case to print.");
}

void loop() {
    if(Serial.available()){
      // SAVE THE TEXT BEFORE A CARRIAGE RETURN
      input = Serial.readStringUntil('\n');
      Serial.print("You typed: " );
      Serial.println(input);
      
      // CONVERT TEXT TO AN ARRAY OF CHARACTERS
      int WordLength = input.length() + 1;  
      char WordArray[WordLength]; 
      input.toCharArray(WordArray, WordLength); 
      
      // HARDCODE FOR 5 LETTER WORDS ONLY
      char topRow[10]; 
      char middleRow[10];
      char bottomRow[10];
      int leftCol = 0;
      int rightCol = 1;
      int incrementor = 2;

      Serial.println(sizeof(WordArray));
      Serial.println(WordLength);
      Serial.println("debug word");
      for(int i = 0; i < WordLength - 1; i++) {
        Serial.print(WordArray[i]);
      }
      Serial.println("");
      // ISSUE WITH HOW IT PRINTS
      // TRYING WITH ABE
      // IT NEEDS TO PRINT E B A 
      for(int i = WordLength - 2; i >= 0; i--)
      {
        // Get the Braille code for the letter in the array
        Serial.println(leftCol);
        Serial.println(rightCol);
        Serial.print("letter: ");
        Serial.println(WordArray[i]); 

        String brailleCode = mp[WordArray[i]];
        Serial.print("try with char: ");
        Serial.println(brailleCode);

        topRow[leftCol] = brailleCode.charAt(3);
        topRow[rightCol] = brailleCode.charAt(0);
        
        middleRow[leftCol] = brailleCode.charAt(4);
        middleRow[rightCol] = brailleCode.charAt(1);

        bottomRow[leftCol] = brailleCode.charAt(5);
        bottomRow[rightCol] = brailleCode.charAt(2);
        
        leftCol += incrementor;
        rightCol += incrementor;
        // for(int j = 0; j < WordLength*2; j += incrementor) {
        //   Serial.println(j);
        //   leftCol = j;
        //   rightCol = j + 1;

        //   // Get 0 and 3 for topRow
        //   topRow[leftCol] = brailleCode.charAt(3);
        //   topRow[rightCol] = brailleCode.charAt(0);

        //   // Get 1 and 4 for middleRow
        //   middleRow[leftCol] = brailleCode.charAt(4);
        //   middleRow[rightCol] = brailleCode.charAt(1);

        //   // Get 2 and 5 for bottomRow
        //   bottomRow[leftCol] = brailleCode.charAt(5);
        //   bottomRow[rightCol] = brailleCode.charAt(2);

        // }
      }
      // MOTOR STUFF, USE THE ARRAYS
      Serial.println("topRow");
      for(int i = 0; i < 10; i++) {
        Serial.print(topRow[i]);
      }

      Serial.println("");
      Serial.println("middleRow");
      for(int i = 0; i < 10; i++) {
        Serial.print(middleRow[i]);
      }

      Serial.println("");
      Serial.println("bottomRow");
      for(int i = 0; i < 10; i++) {
        Serial.print(bottomRow[i]);
      }

      Serial.println("");
      for(int i = 0; i < 10; i++) {
        if(topRow[i] == '1') {
          Serial.print('.');
        } else {
          Serial.print(' ');
        }
      }
      Serial.println("");
      for(int i = 0; i < 10; i++) {
        if(middleRow[i] == '1') {
          Serial.print('.');
        } else {
          Serial.print(' ');
        }
      }
      Serial.println("");
      for(int i = 0; i < 10; i++) {
        if(bottomRow[i] == '1') {
          Serial.print('.');
        } else {
          Serial.print(' ');
        }
      }
      // WORK OUT MOVEMENT PATTERNS

      
      // MOTOR0
      // stepper0.setSpeedInStepsPerSecond(256);
      // stepper0.setAccelerationInStepsPerSecondPerSecond(512);
      // stepper0.moveRelativeInSteps(2048);
      // delay(1000);
      // stepper0.moveRelativeInSteps(-2048);
      // delay(1000);

      // MOTOR1
      stepper1.setSpeedInStepsPerSecond(256);
      stepper1.setAccelerationInStepsPerSecondPerSecond(512);
      stepper1.moveRelativeInSteps(2048);
      delay(1000);
      stepper1.moveRelativeInSteps(-2048);
      delay(1000);

      // MOTOR2
      stepper2.setSpeedInStepsPerSecond(256);
      stepper2.setAccelerationInStepsPerSecondPerSecond(512);
      stepper2.moveRelativeInSteps(2048);
      delay(1000);
      stepper2.moveRelativeInSteps(-2048);
      delay(1000);

      // stepper1.setSpeedInStepsPerSecond(500);
      // stepper1.setAccelerationInStepsPerSecondPerSecond(1000);
      // stepper1.moveRelativeInSteps(2048 * 5);
      // delay(2000);
    } 
}