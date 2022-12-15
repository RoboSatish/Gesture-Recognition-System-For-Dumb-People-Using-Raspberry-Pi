const int flexPin0 = A0; 
const int flexPin1 = A1; 
 const int flexPin2 = A2; 
 const int flexPin3 = A3; 
 const int flexPin4 = A4; 
   int flexValue00;
  int flexValue11;
const int ledPin = 7; 

void setup() 
{ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
} 

void loop() 
{ 
  int flexValue0=0;
  int flexValue1=0;
  int flexValue2=0;
  int flexValue3=0;
  int flexValue4=0;
  flexValue0 = analogRead(flexPin0);
  flexValue1 = analogRead(flexPin1);
  flexValue2 = analogRead(flexPin2);
  flexValue3 = analogRead(flexPin3);
  flexValue4 = analogRead(flexPin4);
  Serial.println("sensor: ");
  Serial.println(flexValue0);
  Serial.println(flexValue1);
  Serial.println(flexValue2);
  Serial.println(flexValue3);
  Serial.println(flexValue4);
  //Serial.println("END");



 
   if(flexValue0<=1011)
  {
    Serial.println("First");
    flexValue0=1023;
    flexValue1=1023;
  }
   else if(flexValue1<=1007)
  {
    Serial.println("Second");
    flexValue2=1023;
    flexValue3=1023;
  }
   else if(flexValue2<=1008)
  {
    Serial.println("Third");
  }
   else if(flexValue3<=1012)
  {
    Serial.println("Four");
  }

   else if(flexValue4<=1008)
  {
    Serial.println("Fifth");
  }

  else
  {
    Serial.println("Try Again...!");
  }


  delay(1000);
  Serial.flush();
} 
