#define UP PORTA.B0
#define DWN PORTA.B1
//----------------------------------------------
char Ledkod[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}, sayi=0;

void main()
{
 CMCON=7; // PORTA dijital
 TRISA=3; // Pin 0 ve Pin 1 giri� di�erleri ��k��
 TRISB=0; // PORTB ��k��
 PORTB=LedKod[0]; // PORTB'ye 0'�n 7 segment kodunu g�nder

 while(1) // sonsuz d�ng�
 {
 if(!UP)
 {
 Delay_ms(100); // buton ark� i�in 100 ms bekle
 sayi=sayi+1;
 if(sayi>9){ sayi=9;    }
 PORTB=Ledkod[sayi];
 while(!UP);
  }
  if(!DWN)
 {
 Delay_ms(100); // buton ark� i�in 100 ms bekle
 sayi--;
 if(sayi==255){ sayi=0;}
 PORTB=Ledkod[sayi];
 while(!DWN);

 }
 }
}