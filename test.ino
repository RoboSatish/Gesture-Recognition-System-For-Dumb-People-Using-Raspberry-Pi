 const int FLEX_PIN0 = A0;
 const int FLEX_PIN1 = A1;
 const int FLEX_PIN2 = A2;
 const int FLEX_PIN3 = A3;
 const int FLEX_PIN4 = A4;

// Pin connected to voltage divider output

// Measure the voltage at 5V and the actual resistance of your

// 47k resistor, and enter them below: 
const float VCC = 4.7;

// Measured voltage of Ardunio 5V line 
const float R_DIV = 47500.0;

// Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more

// accurately calculate bend degree. 
const float STRAIGHT_RESISTANCE = 37300.0;

// resistance when straight
const float BEND_RESISTANCE = 90000.0;

// resistance at 90 deg

void setup()

{ Serial.begin(9600);

pinMode(FLEX_PIN0, INPUT); 
pinMode(FLEX_PIN1, INPUT); 
pinMode(FLEX_PIN2, INPUT); 
pinMode(FLEX_PIN3, INPUT); 
pinMode(FLEX_PIN4, INPUT); 

pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop()

{ // Read the ADC, and calculate voltage and resistance from it

int flexADC0 = analogRead(FLEX_PIN0);
int flexADC1 = analogRead(FLEX_PIN1);
int flexADC2 = analogRead(FLEX_PIN2);
int flexADC3 = analogRead(FLEX_PIN3);
int flexADC4 = analogRead(FLEX_PIN4);

float flexV0 = flexADC0 * VCC / 1023.0;
float flexV1 = flexADC1 * VCC / 1023.0;
float flexV2 = flexADC2 * VCC / 1023.0;
float flexV3 = flexADC3 * VCC / 1023.0;
float flexV4 = flexADC4 * VCC / 1023.0;

float flexR0 = R_DIV * (VCC / flexV0 - 1.0);
float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
float flexR2 = R_DIV * (VCC / flexV2 - 1.0);
float flexR3 = R_DIV * (VCC / flexV3 - 1.0);
float flexR4 = R_DIV * (VCC / flexV4 - 1.0);

///Serial.println("Resistance: " + String(flexR) + " ohms");

// Use the calculated resistance to estimate the sensor's

// bend angle:

float angle0 = map(flexR0, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
float angle1 = map(flexR1, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
float angle2 = map(flexR2, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
float angle3 = map(flexR3, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
float angle4 = map(flexR4, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);

//Serial.println("Bend0: " + String(angle0) + " degrees");
//Serial.println("Bend1: " + String(angle1) + " degrees");
//Serial.println("Bend2: " + String(angle2) + " degrees");
//Serial.println("Bend3: " + String(angle3) + " degrees");
//Serial.println("Bend: " + String(angle4) + " degrees");
int a0=String(angle0).toInt();
int a1=String(angle1).toInt();
int a2=String(angle2).toInt();
int a3=String(angle3).toInt();
int a4=String(angle4).toInt();

int a00=-(a0);
int a11=-(a1);
int a22=-(a2);
int a33=-(a3);
int a44=-(a4);

//Serial.print(a11);

if(a00<60 && a11<58 && a22<60 && a33<60)
{
  Serial.print("Hi Megha");
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(10);
  
}
else if (a00<60 && a11<58 && a22<60)
{
// Serial.println(a0);
// Serial.println(a1);
  Serial.println("I want It");
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

else if(a22<60 && a33<60 && a44<60)
{
  Serial.println("Be Strong");
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}



else if(a22<58 && a44<58)
{
  Serial.println("We Rock");
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

else if(a00<60 && a11<58)
{
  
  Serial.println("ok");
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

else if(a33<60 && a44<60)
{
  
  Serial.println("Hi Anagha");
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}


else if(a11<58)
{
  //Serial.println(a1);
  Serial.println("Best of Luck");
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}
else if(a33<60 )
{
  Serial.println("I need it");
   digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}



else
{
   Serial.println("Try Again");
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
   delay(10);
}

Serial.println();

delay(500); }
