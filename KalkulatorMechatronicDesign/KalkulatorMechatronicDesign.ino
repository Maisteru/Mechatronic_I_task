String odczyt_serial = "",pierwsza,druga;
boolean koniec_odczytu = false;
char test;
int dlugosc,dzialanie,pozycja_znaku;
long int a,b;
float wynik;

void setup() {
Serial.begin(9600);
Serial.println("---------------------------------------------");
Serial.println("Kalkulator Mechatronic Design");
Serial.println("Kalkulator wykonuje działania + - * /");
Serial.println("Kalkulator przyjmure działanie typu 12+34 ");
Serial.println("Wprowadź działanie");
}

void loop() {

  if (Serial.available() > 0) 
        {
          while (Serial.available())
          {

                char znak = (char)Serial.read();
                odczyt_serial += znak;
                if(znak == '\n')
                {
                  koniec_odczytu = true;
                }
          }
          if(koniec_odczytu == true)
          {

            Serial.print("otrzymalem: ");
            Serial.println(odczyt_serial);
            koniec_odczytu = false;

            dlugosc = odczyt_serial.length();

            for (int i=0; i<=dlugosc; i++)
            {
             if (odczyt_serial[i]=='+'){
              dzialanie=1;                          //dodawanie
              pozycja_znaku=i;
             }
              if (odczyt_serial[i]=='-'){
              dzialanie=2;                          //odejmowanie
              pozycja_znaku=i;
             }
             if (odczyt_serial[i]=='*'){
              dzialanie=3;                          //mnożenie
              pozycja_znaku=i;
             }
             if (odczyt_serial[i]=='/'){
              dzialanie=4;                          //dzielenie
              pozycja_znaku=i;
             }
             pierwsza=odczyt_serial.substring(0,pozycja_znaku);
             druga=odczyt_serial.substring(pozycja_znaku+1,dlugosc);
            }

            a=pierwsza.toInt();
            b=druga.toInt();

            switch (dzialanie){
              case 1:
              wynik=a+b;
              break;
              case 2:
              wynik=a-b;
              break;
              case 3:
              wynik=a*b;
              break;
              case 4:
              {
                if(b==0){
                  Serial.println("Nie można dzielić przez 0");
                }else{
                  wynik=a/b;
                }   
              }
              break;
              default:
              Serial.println("niepoprawnie wprowadzone dane");
              break;
            }
            Serial.print("Wynik =");
            Serial.println(wynik);

            odczyt_serial = "";
            a=0;
            b=0;
            wynik=0;
            pozycja_znaku=0;
            Serial.println();
            Serial.println("---------------------------------------------");
            Serial.println("Kalkulator Mechatronic Design");
            Serial.println("Kalkulator wykonuje działania + - * /");
            Serial.println("Kalkulator przyjmure działanie typu 12+34 ");
            Serial.println("Wprowadź działanie");
          }
      }      
          
}
