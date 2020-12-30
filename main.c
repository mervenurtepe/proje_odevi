#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

const char matrix_bigram_strings[10][3] ={"th","he","in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

const char languages[2][8]={"english", "german"};

//ingilizce dilinin frekans degerleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
//Almanca dilinin frekans degerleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];//bigram ve trigramlarin frekanslarinin tutuldugu matristir.
float distances [2]={0,0};//metnin ingilizce diline ya da almanca diline olan uzakligini belirler.


void filter_str(char str[]);//bu fonksiyon "a-z","A-Z",' ' ve '\0' disindaki char karakterlerini bosluk ile degistirir.
void calculate_frequencies_bi(char str[]);//bu fonksiyon her bir bigramin metinde kac kez tekrar ettigini tutar.
void calculate_frequencies_tri(char str[]);//bu fonksiyon her bir trigramin  metinde kac kez tekrar ettigini tutar.
void calculate_distances();//bu fonksiyon metnin ingilizce diline ya da almanca diline olan uzakligini hesaplar.

void detect_lang();//bu fonksiyon metnin hangi dilde yazildigina karar veren fonksiyondur.

int main()
{
    printf("metni giriniz: \n");
    char metin[2999+1]; //+1 degeri determinating karakteri ifade eder.
    gets(metin);
    printf("\n\n");
    filter_str(metin);
    printf("\n\n");
    calculate_frequencies_bi(metin);
    printf("\n\n");
    calculate_frequencies_tri(metin);
    printf("\n\n");
    calculate_distances();
    detect_lang();
    printf("\n\n");
	return 0;
}

void filter_str(char str[]) //metni gereksiz karakterlerden temizlememizi saglar.
{
  for(int i=0;i<strlen(str);i++)
  {
      if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]==32)||(str[i]=='\0'))
         str[i]=tolower(str[i]);//eger istenilen bir karakter gorurse onu kucuk harfe cevirerek diziyi degistirir.
      else
          str[i]=32; //32 degeri ' ' karakterinin ascii tablosundaki karsiligidir.
  }
  puts(str);
}

void calculate_frequencies_bi(char str[]) // her bir bi gramin kac kere gectigini bulur ve bunu frekans olarak tanimlar.
{
  int i=0,j=0,k=0,sayac=0;
  for(i;i<10;i++)//bu donguyle bigramlar aranýr.
  {
      for(j=0;j<strlen(str);j++)//bu donguyle metin her bir bigram icin bastan sona taranir.
      {
          if(str[j]==matrix_bigram_strings[i][k])//bu if sayesinde bigramin harfiyle metindeki harfin uyusup uyusamdigini kontrol eder.
          {
              k++;
              if(k==2)
              {
                  sayac++;
                  k=0;
              }
          }
          else
            k=0;
      }
      calculated_frequencies[i]=sayac;//ilk bigramdan itibaren son bigrama kadar olan tum bigramlarý tekrar sayilarinin atandigi dizidir.
      sayac=0;
  }
  for(i=0;i<10;i++)
      printf(" %.1f\n",calculated_frequencies[i]);

}

void calculate_frequencies_tri(char str[]) // her bir trigramin  kac kere gectigini bulur ve bunu frekans olarak tanimlar.
{
  int i=0,j=0,k=0,sayac=0;
  for(i;i<10;i++)//bu donguyle  trigramin  aranir.
  {
      for(j=0;j<strlen(str);j++)//bu donguyle metin her bir  trigramin   icin bastan sona taranir.
      {
          if(str[j]==matrix_trigram_strings[i][k])//bu if sayesinde  trigramin  harfiyle metindeki harfin uyusup uyusamdigini kontrol eder.
          {
              k++;
              if(k==3)
              {
                  sayac++;
                  k=0;
              }
          }
          else
            k=0;
      }
      calculated_frequencies[i+10]=sayac;//ilk  trigramin  itibaren son bigrama kadar olan tum bigramlarý tekrar sayilarinin atandigi dizidir.
      sayac=0;
  }
  for(i=0;i<10;i++)
      printf(" %.1f\n",calculated_frequencies[i+10]);

}

void calculate_distances() // oklit uzakligina gore hesaplamalar yapar.
{

    float toplam=0.0;
    printf("\n\n") ;
    for(int i=0;i<20;i++)//bu dongu ile dizinin elemanlari arasinda gecis yapilir.
            toplam += pow((calculated_frequencies[i]-frequency_eng[i]),2);

    distances[0]=sqrt(toplam);//"toplam" in karekokunu alir ve distances[0]'a atar.

    printf("\n ing uzaklik\n");

    printf("%f",distances[0]);

    toplam = 0.0;
    for(int i=0;i<20;i++)//bu dongu ile dizinin elemanlari arasinda gecis yapilir.
        toplam += pow((calculated_frequencies[i]-frequency_germ[i]),2);

    distances[1]=sqrt(toplam);

    printf("\n almanca uzaklik\n");

    printf("%f",distances[1]);

}
void detect_lang() // Bu fonksiyon metnin hangi dilde yazildigina karar verir.
{

    printf("\n\n");

     if(distances[0]<distances[1])//ingilizceye olan uzaklik almancaya olan uzakliktan  kucuk ise metnin dilin ingilizcedir.
        printf("metnin dili ingilizcedir.");
     else //almancaya  olan uzaklik ingilizceye  olan uzakliktan kucuk ise metnin dilin almancadir.
        printf("metnin dili almancadir.");


}

