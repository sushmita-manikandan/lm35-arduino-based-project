float temp;
int tempPin = 0;
float m=0,t=0;
int time=5000;
//void predict(int temp);
//void disp();
void setup()
{
  Serial.begin(9600);
}

void loop()
{  
  /*temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  delay(1000);*/
  if(time>0)
  {
  //predict(temp);
        temp = analogRead(tempPin);
        temp = temp * 0.48828125;
        Serial.print("TEMPRATURE = ");
        Serial.print(temp);
        Serial.print("*C");
        Serial.println();
        delay(1000);
        if(temp>25)
	{
		m=m+1;	
	}
	else if(temp>=23 && temp<=25)
	{
		t=t+1;
	}
  }
  else if(time==0)
  {
  //disp();
        float percent;
        /*Serial.print(m);
        Serial.println();
        Serial.print(t);
        Serial.println();*/
        Serial.print("Prediction");
	Serial.println();
	percent=((m/(m+t))*100);
	Serial.print("Malaria:");
	Serial.print(percent);
	Serial.println();
	percent=((t/(m+t))*100);
	Serial.print("Typhoid:");
	Serial.print(percent);
	Serial.println();
  }
  else if(time<0)
  {
    time=6000;
    m=0;
    t=0;
  }
  time=time-1000;
  
}
