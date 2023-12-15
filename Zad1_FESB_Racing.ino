unsigned long MyTime1 = 0;
unsigned long MyTime2 = 0;

unsigned long ProsloVrijeme1 = 0;
unsigned long ProsloVrijeme2 = 0;
unsigned long ProsloVrijeme3 = 0;
unsigned long ProsloVrijeme4 = 0;
unsigned long Kasnjenje = 500;

unsigned long Vrijeme1 = 2000; //2 sekunde
unsigned long Vrijeme2 = 3000; //3 sekunde
unsigned long Vrijeme3 = 500;  //0,5 sekundi

unsigned long LED1_Stanje = LOW;
unsigned long LED2_Stanje = LOW;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2, OUTPUT); //LED-ica s intervalom od 2 sekunde
pinMode(8, OUTPUT); //LED-ica s intervalom od 3 sekunde
}

void loop() {
  // put your main code here, to run repeatedly:

  //Brojači vremena
  MyTime1 = millis();
  MyTime2 = millis();

  //Brojanje do uključivanja prve LED-ice
  if (MyTime1 - ProsloVrijeme1 >= Vrijeme1)
  {
    if (LED1_Stanje == LOW){
    LED1_Stanje = HIGH;
    ProsloVrijeme1=MyTime1 + Kasnjenje;
    }
    digitalWrite(8, LED1_Stanje);
  }
  
  
  
  //Gašenje prve LED-ice
  if (MyTime1 - ProsloVrijeme2 >= Vrijeme3)
  {
    ProsloVrijeme2 = MyTime1;

    if (LED1_Stanje == HIGH)
    {
      LED1_Stanje = LOW;
    }
    if (LED1_Stanje == LOW)
    {
      digitalWrite(8, LED1_Stanje);
    }
  }

  //Brojanje do uključivanja druge LED-ice
  if(MyTime2 - ProsloVrijeme3 >= Vrijeme2)
  {
    if (LED2_Stanje == LOW)
    {
      LED2_Stanje = HIGH;
      ProsloVrijeme3 = MyTime2 + Kasnjenje;
    }
    digitalWrite(2, LED2_Stanje);
  }
  
  
  //Gašenje druge LED-ice
  if (MyTime2 - ProsloVrijeme4 >= Vrijeme3)
  {
    ProsloVrijeme4 = MyTime2;

    if (LED2_Stanje == HIGH)
    {
      LED2_Stanje = LOW;
    }
    if (LED2_Stanje == LOW)
    {
      digitalWrite(2, LED2_Stanje);
    }
  }
}
