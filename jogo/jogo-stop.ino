/*
 * Descrição: Gerador de letras para o jogo Stop.
 * Autor: Eros Vitor Bornatowski
 * Data: 11/08/2022
 */
 
#define PIN_SEG_B 2
#define PIN_SEG_A 3
#define PIN_SEG_F 4
#define PIN_SEG_G 5
#define PIN_SEG_C 8
#define PIN_SEG_D 9
#define PIN_SEG_E 10

#define PIN_BUTTON 12

#define ON 1
#define OFF 0

int letterSelected;
int lettersUsed[26];
int indexLastLetterUsed=0;
int prevStateButton = LOW;
int curStateButton = LOW;

void setup()
{
  pinMode(PIN_SEG_B, OUTPUT);
  pinMode(PIN_SEG_A, OUTPUT);
  pinMode(PIN_SEG_F, OUTPUT);
  pinMode(PIN_SEG_G, OUTPUT);
  pinMode(PIN_SEG_C, OUTPUT);
  pinMode(PIN_SEG_D, OUTPUT);
  pinMode(PIN_SEG_E, OUTPUT);
  
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}
 
void loop()
{
  prevStateButton = curStateButton;
  
  curStateButton = digitalRead(PIN_BUTTON);

  if (curStateButton == HIGH && prevStateButton == LOW) {
    letterSelected = generateValidLetter();
    lettersUsed[indexLastLetterUsed++] = letterSelected;
    clearDisplay();
    showLetter(letterSelected);
  }
}

int generateValidLetter() {
  int letter;
  do {
    letter = generateLetter();
  } while (!unusedLetter(letter));
  return letter;
}

int generateLetter() {
  bool invalidLetter = false;
  int letter;
  do {
    letter = random(1, 26);
    switch (letter) {
      case 11:  // K
      case 13:  // M
      case 14:  // N
      case 17:  // Q
      case 18:  // R
      case 20:  // T
      case 22:  // V
      case 23:  // W
      case 24:  // X
      case 25:  // Y
      case 26:  // Z
        invalidLetter = true;
        break;
      default:
        invalidLetter = false;
        break;
    }
  } while (invalidLetter);
  return letter;
}

bool unusedLetter(int letter) {
  bool unusedLetter = true;
  for (int i=0; i < indexLastLetterUsed; i++) {
    if (lettersUsed[i] == letter) {
      unusedLetter = false;
      break;  
    }
  }
  return unusedLetter;
}

void clearDisplay() {
  digitalWrite(PIN_SEG_E, OFF);
  digitalWrite(PIN_SEG_D, OFF);
  digitalWrite(PIN_SEG_C, OFF);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, OFF);
  digitalWrite(PIN_SEG_F, OFF);
  digitalWrite(PIN_SEG_G, OFF);
}

void showLetter(int number) {
  switch (number) {
    case 1: showLetterA(); break;
    case 2: showLetterB(); break;
    case 3: showLetterC(); break;
    case 4: showLetterD(); break;
    case 5: showLetterE(); break;
    case 6: showLetterF(); break;
    case 7: showLetterG(); break;
    case 8: showLetterH(); break;
    case 9: showLetterI(); break;
    case 10: showLetterJ(); break;
    case 12: showLetterL(); break;    
    case 15: showLetterO(); break;    
    case 16: showLetterP(); break;    
    case 19: showLetterS(); break;
    case 21: showLetterU(); break;
  }
}

void showLetterA() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, OFF);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON);  
}

void showLetterB() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON);  
}

void showLetterC() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, OFF);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, OFF);  
}

void showLetterD() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, OFF);
}

void showLetterE() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, OFF);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON);  
}

void showLetterF() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, OFF);
  digitalWrite(PIN_SEG_C, OFF);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON);  
}

void showLetterG() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON); 
}

void showLetterH() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, OFF);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, OFF);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON);  
}

void showLetterI() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, OFF);
  digitalWrite(PIN_SEG_C, OFF);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, OFF);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, OFF);  
}

void showLetterJ() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, OFF);
  digitalWrite(PIN_SEG_F, OFF);
  digitalWrite(PIN_SEG_G, OFF);  
}

void showLetterL() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, OFF);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, OFF);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, OFF);  
}

void showLetterO() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, OFF);  
}

void showLetterP() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, OFF);
  digitalWrite(PIN_SEG_C, OFF);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON);  
}

void showLetterS() {
  digitalWrite(PIN_SEG_E, OFF);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, OFF);
  digitalWrite(PIN_SEG_A, ON);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, ON);  
}

void showLetterU() {
  digitalWrite(PIN_SEG_E, ON);
  digitalWrite(PIN_SEG_D, ON);
  digitalWrite(PIN_SEG_C, ON);
  digitalWrite(PIN_SEG_B, ON);
  digitalWrite(PIN_SEG_A, OFF);
  digitalWrite(PIN_SEG_F, ON);
  digitalWrite(PIN_SEG_G, OFF);  
}
