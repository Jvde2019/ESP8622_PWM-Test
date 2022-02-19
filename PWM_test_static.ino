
const int ledPin = 2;

int i, j, resolution = 0;
char str[14];

int PWMArray[5];
int twodimensional[13][6] = {{4, 0, 4, 8, 12, 16}, {5, 0, 8, 16, 24, 32}, {6, 0, 16, 32, 48, 64}, {7, 0, 32, 64, 98, 128}, \
  {8, 0, 64, 128, 192, 256}, {9, 0, 128, 256, 394, 512}, {10, 0, 256, 512, 768, 1024}, {11, 0, 512, 1024, 768, 2048}, \
  {12, 0, 1024, 2048, 768, 4096}, {13, 0, 2048, 4096, 768, 8192}, {14, 0, 4096, 8192, 768, 16348}, \
  {15, 0, 8192, 16348, 768, 32768}, {16, 0, 16348, 512, 768, 65536}
};

void setup() {
  // put your setup code here, to run once:
  //pinMode(0, OUTPUT);
  //pinMode(2, OUTPUT);
  Serial.begin(115200);
  // PWM Frequenz [Hz] 1000 default
  analogWriteFreq(1000);
  // PWM Resolution 4096
  //analogWriteRange(1024);
  // PWM bits
  analogWriteResolution(resolution);
}

void PWM_test() {
  for (j = 0; j < 14 ; j = j + 1) {
    // Static Test
    Serial.print("j is ");
    Serial.println(j);
    resolution = twodimensional[j][0];
    analogWriteResolution(resolution);
    //    str = "Resolution is";
    Serial.print("Resolution is ");
    Serial.println(resolution);
    for (i = 0; i < 5; i = i + 1) {
      PWMArray[i] = twodimensional[j][i + 1];
    }
    Serial.println("1 % PWM");
    Serial.println(PWMArray[4]);
    analogWrite(ledPin, PWMArray[4]);
    delay(5000);
    Serial.println("25 % PWM");
    Serial.println(PWMArray[3]);
    analogWrite(ledPin, PWMArray[3] );
    delay(5000);
    Serial.println("50 % PWM");
    Serial.println(PWMArray[2]);
    analogWrite(ledPin, PWMArray[2] );
    delay(5000);
    Serial.println("75 % PWM");
    Serial.println(PWMArray[1]);
    analogWrite(ledPin, PWMArray[1] );
    delay(5000);
    Serial.println("100 % PWM");
    Serial.println(PWMArray[0]);
    analogWrite(ledPin, PWMArray[0] );
    delay(5000);
    // Dynamic Test
    Serial.print("Dynamic test with ");
    Serial.print(PWMArray[4]);
    Serial.println(" Steps");

    // increase the LED brightness
    for (int dutyCycle = PWMArray[4]; dutyCycle > 0; dutyCycle--) {
      // changing the LED brightness with PWM
      analogWrite(ledPin, dutyCycle);
      delay(1);
    }
    // decrease the LED brightness
    for (int dutyCycle = 0; dutyCycle < PWMArray[4]; dutyCycle++) {
      // changing the LED brightness with PWM
      analogWrite(ledPin, dutyCycle);
      delay(1);
    }
    delay(500);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  PWM_test();
}
