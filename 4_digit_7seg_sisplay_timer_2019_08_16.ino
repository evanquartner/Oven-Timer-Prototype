/*Hardware setup: put 4 digit 7 segment display on breadboard and set so that the digits are displayed toward you 
 *(ie the decimal points are on the bottom of the display). Arduino pin connections on bottom of 4 digit 7-segment 
 *display from left to right: arduino pin 6, 5, 13, 4, 8, 12. Arduino pin connections on top of 4 digit 7-segment 
 *display from left to right: arduino pin 9, 2, 7, 10, 11, 3. 
 *Additionally, ground of arduino is connected to negative row on breadboard. 2 buttons are put on breadboard, each 
 *connected to negative row and digital pin. These buttons are for starting the timer and increasing the time on the
 *timer during the setup. Lastly, a passive buzzer (motherboard can be seen from bottom) is connected to a ground pin 
 *and a digital pin on the arduino.
 */
#define NOTE_C5 523


const int aPin = 2;
const int bPin = 3;
const int cPin = 4;
const int dPin = 5;
const int ePin = 6;
const int fPin = 7;
const int gPin = 8;
const int decimalPin = 13;
const int minuteTens = 9;
const int minuteOnes = 10;
const int secondTens = 11;
const int secondOnes = 12;

const int buttonPin1 = 1;
//const int buzzerPin0 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(decimalPin, OUTPUT);
  pinMode(minuteTens, OUTPUT);
  pinMode(minuteOnes, OUTPUT);
  pinMode(secondTens, OUTPUT);
  pinMode(secondOnes, OUTPUT);
  
  pinMode(buttonPin1, INPUT);

  digitalWrite(A0, INPUT_PULLUP);
  digitalWrite(buttonPin1, INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:

timer(0, 0, 0, 0);
}




void displayDigit(int num) {
  if (num == 0) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, HIGH);
    digitalWrite(ePin, HIGH);
    digitalWrite(fPin, HIGH);
    digitalWrite(gPin, LOW);
  } else if (num == 8) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, HIGH);
    digitalWrite(ePin, HIGH);
    digitalWrite(fPin, HIGH);
    digitalWrite(gPin, HIGH);
  } else if (num == 9) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, LOW);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, HIGH);
    digitalWrite(gPin, HIGH);
  } else if (num == 4) {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, LOW);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, HIGH);
    digitalWrite(gPin, HIGH);
  } else if (num == 5) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, LOW);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, HIGH);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, HIGH);
    digitalWrite(gPin, HIGH);
  } else if (num == 6) {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, LOW);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, HIGH);
    digitalWrite(ePin, HIGH);
    digitalWrite(fPin, HIGH);
    digitalWrite(gPin, HIGH);
  } else if (num == 3) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, HIGH);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, LOW);
    digitalWrite(gPin, HIGH);
  } else if (num == 1) {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, LOW);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, LOW);
    digitalWrite(gPin, LOW);
  } else if (num == 2) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, LOW);
    digitalWrite(dPin, HIGH);
    digitalWrite(ePin, HIGH);
    digitalWrite(fPin, LOW);
    digitalWrite(gPin, HIGH);
  } else if (num == 7) {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, HIGH);
    digitalWrite(cPin, HIGH);
    digitalWrite(dPin, LOW);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, LOW);
    digitalWrite(gPin, LOW);
  } else if (num == -1) {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, LOW);
    digitalWrite(cPin, LOW);
    digitalWrite(dPin, HIGH);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, LOW);
    digitalWrite(gPin, LOW);

    //Displays nothing
  } else if (num == 999) {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, LOW);
    digitalWrite(cPin, LOW);
    digitalWrite(dPin, LOW);
    digitalWrite(ePin, LOW);
    digitalWrite(fPin, LOW);
    digitalWrite(gPin, LOW);

    //Case where num equals anything else
  } else {
    displayDigit(-1);
  }
}

void blankDisplay() {
  digitalWrite(minuteTens, HIGH);
  digitalWrite(minuteOnes, HIGH);
  digitalWrite(secondTens, HIGH);
  digitalWrite(secondOnes, HIGH);
  digitalWrite(decimalPin, LOW);
} 
void minuteTensOn() {
  digitalWrite(minuteTens, LOW);
  digitalWrite(minuteOnes, HIGH);
  digitalWrite(secondTens, HIGH);
  digitalWrite(secondOnes, HIGH);
  digitalWrite(decimalPin, LOW);
}
void minuteOnesOn() {
  digitalWrite(minuteTens, HIGH);
  digitalWrite(minuteOnes, LOW);
  digitalWrite(secondTens, HIGH);
  digitalWrite(secondOnes, HIGH);

  digitalWrite(decimalPin, HIGH);
}
void secondTensOn() {
  digitalWrite(minuteTens, HIGH);
  digitalWrite(minuteOnes, HIGH);
  digitalWrite(secondTens, LOW);
  digitalWrite(secondOnes, HIGH);
  digitalWrite(decimalPin, LOW);
}
void secondOnesOn() {
  digitalWrite(minuteTens, HIGH);
  digitalWrite(minuteOnes, HIGH);
  digitalWrite(secondTens, HIGH);
  digitalWrite(secondOnes, LOW);
  digitalWrite(decimalPin, LOW);
}

void timerDisplay(int minuteTens, int minuteOnes, int secondTens, int secondOnes) {
  int milisecondCounter = 0;
  while (milisecondCounter < 972) {
    long timePassedAtStart = micros();
    minuteTensOn();
    displayDigit(minuteTens);
    delay(3);
    milisecondCounter += 3;
    minuteOnesOn();
    displayDigit(minuteOnes);
    delay(3);
    milisecondCounter += 3;
    secondTensOn();
    displayDigit(secondTens);
    delay(3);
    milisecondCounter += 3;
    secondOnesOn();
    displayDigit(secondOnes);
    delay(3);
    milisecondCounter += 3;
    /*if (milisecondCounter == 999) {
      delay(1);
      milisecondCounter ++;
    }*/
  }
}



void timerEnd(int seconds) {
  for (int i = 0; i < seconds; i ++) {
    blankDisplay();
    tone(A5, NOTE_C5); //A5 is buzzerpin
    delay(1000);
    noTone(A5);
    timerDisplay(0,0,0,0);
  }
}
void timerCountdown(int mTens, int mOnes, int sTens, int sOnes) {
  long timeAtStart = micros();
  int delayTime = 0;
  while (sOnes > 0 || sTens >  0 || mOnes > 0 || mTens > 0) {
    //Serial.println(micros());
    //delayTime =(1000000 - (micros() - timeAtStart));
    
    //Serial.println(delayTime);
    //delayMicroseconds(100*delayTime);
    timerDisplay(mTens, mOnes, sTens, sOnes);
    //Serial.println(micros());
    Serial.println("tick"); 
    timeAtStart = micros();
    if (mTens > 0 && mOnes == 0 && sTens == 0 && sOnes == 0) {
      mTens --;
      mOnes = 9;
      sTens = 5;
      sOnes = 10;
    } else if (mOnes > 0 && sTens == 0 && sOnes == 0) {
      mOnes --;
      sTens = 5; 
      sOnes = 10;
    } else if (sTens > 0 && sOnes == 0) {
      sTens --;
      sOnes = 10;
    }
    sOnes --;
  }
  timerEnd(3);
}

void timer(int mTens, int mOnes, int sTens, int sOnes) {
  boolean timerSetup = true;
  while (timerSetup) {
    minuteTensOn();
    displayDigit(mTens);
    delay(3);
    minuteOnesOn();
    displayDigit(mOnes);
    delay(3);
    secondTensOn();
    displayDigit(sTens);
    delay(3);
    secondOnesOn();
    displayDigit(sOnes);
    delay(3);
    if (digitalRead(A0) == LOW) {
      delay(100);
      sOnes ++;
      
      if (sOnes == 10) {
        sOnes = 0;
        sTens ++;
        if (sTens == 6) {
          sTens = 0;
          mOnes ++;
          if (mOnes == 10) {
            mOnes = 0;
            mTens ++;
            if (mTens == 10) {
            sOnes == 0;
            sTens = 0;
            mOnes = 0;
            mTens = 0;
            }
          }
        }
      }
    }
    if (digitalRead(buttonPin1) == LOW) {
      timerCountdown(mTens, mOnes, sTens, sOnes);
      timer(0,0,0,0);
    }
  } 
}
