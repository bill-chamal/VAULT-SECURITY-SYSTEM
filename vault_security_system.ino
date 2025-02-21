// C++ code
//
//
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, INPUT);
  
  Serial.begin(9600);
  
  int vin_tmp_0 = analogRead(A1);
  int l = analogRead(A0);
}

void setAlarmLight(){
  digitalWrite(3, HIGH);
  delay(100);
}
void setAlarmTmp(){
  digitalWrite(4, HIGH);
  delay(100);
}

void setOffAlarm(){
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);
}

int status = HIGH; // close = HIGH

bool light_detected = false;
bool tmp_detected = false;


void loop()
{

  int vin_tmp_0;
  int l;
  
  while(digitalRead(2) == status){
    delay(200); 
	// close leds
    setOffAlarm();
    // read tmp
    vin_tmp_0 = analogRead(A1);
    // map d to C
    int tmp0 = map(vin_tmp_0, 20, 358, -40, 125);
    // read light diode
    l = analogRead(A0);
    // check alarm
    if (tmp0 >= 20)
    	tmp_detected = true;
    
    if (l > 180)
    	light_detected = true;
    
    //Serial.println(analogRead(A0));
    
  }
  
  if(light_detected)
    setAlarmLight();
  
  if (tmp_detected)
    setAlarmTmp();
  
    
  light_detected = false;
  tmp_detected = false;
  
  delay(700);
}