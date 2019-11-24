int trigPin = 10; // grey
int echoPin = 11; // purple
long duration,cm,inches=0;
int buzzer = 6;
int led = 5;
int blueLED=4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(blueLED,OUTPUT);
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);

}

void loop() {
  cm=0;

  //set up the ultrasonic
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  digitalWrite(blueLED,HIGH);
  
  duration = pulseIn(echoPin,HIGH);

  cm = (duration/2) / 29.1;

  Serial.print(cm);
  Serial.print(" cm \n");
  delay(50);

  if(cm<=100 && cm>=80){
      digitalWrite(blueLED,LOW);
      analogWrite(buzzer,50);
      digitalWrite(led,HIGH);
      delay(300);

      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(300);
    }else if(cm<=80 && cm>=60){
      digitalWrite(blueLED,LOW);
      analogWrite(buzzer,100);
      digitalWrite(led,HIGH);
      delay(300);

      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(300);
    }else if(cm<=60 && cm>=40){
      digitalWrite(blueLED,LOW);
      analogWrite(buzzer,150);
      digitalWrite(led,HIGH);
      delay(300);

      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(300);
    }else if(cm<=40 && cm>=20){
      digitalWrite(blueLED,LOW);
      analogWrite(buzzer,200);
      digitalWrite(led,HIGH);
      delay(300);

      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(300);
    }else if(cm<=20 && cm>=0){
      digitalWrite(blueLED,LOW);      
      analogWrite(buzzer,255);
      digitalWrite(led,HIGH);
      delay(300);

      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(300);
    }else{
      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      cm=0;  
    }
    
    


}
