int seat1 = A0;
int seat2 = A1;
int seatSensor1 = 2;
int seatSensor2 = 3;
int led1 = 8;
int led2 = 9;
int thresholdValue = 400;

void setup() {
    pinMode(seat1, INPUT);
    pinMode(seat2, INPUT);
    pinMode(seatSensor1, INPUT);
    pinMode(seatSensor2, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.print(analogRead(seat1));
    Serial.print("\t");
    Serial.println(analogRead(seat2));
    Serial.print(digitalRead(seatSensor1));
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    
    if (!digitalRead(seatSensor1) && analogRead(seat1) > thresholdValue) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
    }
    
    if (!digitalRead(seatSensor2) && analogRead(seat2) > thresholdValue) {
        digitalWrite(led2, HIGH);
        digitalWrite(led1, LOW);
    }
    
    if (!digitalRead(seatSensor1) && analogRead(seat1) < thresholdValue && analogRead(seat2) > thresholdValue) {
        digitalWrite(led2, HIGH);
        digitalWrite(led1, LOW);
    }
    
    if (!digitalRead(seatSensor2) && analogRead(seat2) < thresholdValue && analogRead(seat1) > thresholdValue) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
    }
}

