//Lab Assignment 2 
//Currecny Exchange Chart
//CECS 130
//Christopher Bass

#include<stdio.h>
#include<conio.h>

int main()
{
    const float USDtoUSD=1;
    const float USDtoGBP=0.547525;
    const float USDtoCAD=1.0527;
    const float USDtoEUR=0.680967;
    const float USDtoAUD=1.16036;
    
    const float GBPtoGBP=1;
    const float GBPtoUSD=1.8264;
    const float GBPtoCAD=1.92265;
    const float GBPtoEUR=1.24371;
    const float GBPtoAUD=2.11928;
    
    const float CADtoCAD=1; 
    const float CADtoUSD=0.949938;
    const float CADtoGBP=0.520114;
    const float CADtoEUR=0.646876;
    const float CADtoAUD=1.10227;
    
    const float EURtoUSD=1.46849;
    const float EURtoGBP=0.80404;
    const float EURtoCAD=1.54588;
    const float EURtoEUR=1;
    const float EURtoAUD=1.70398;
    
    const float AUDtoUSD=0.861801;
    const float AUDtoGBP=0.471857;
    const float AUDtoCAD=0.907218;
    const float AUDtoEUR=0.586858;
    const float AUDtoAUD=1;
    
  float USD, AUD, CAD, EUR, GBP;

 
    printf("Enter an amount in US dollars:\n");
    scanf("%f", &USD);
 
 
  USD=USD*USDtoUSD;
  GBP=USD*USDtoGBP;
  CAD=USD*USDtoCAD;
  EUR=USD*USDtoEUR;
  AUD=USD*USDtoAUD;

  
  
  
  
  printf("______________________________________________\n");
  printf("   | USD    | GBP    | CAD   | EUR   | AUD   |\n");
  printf("----------------------------------------------\n");
  printf("USD| %.2f   | %.2f   | %.2f  | %.2f  | %.2f  |\n", USD, USD*GBPtoUSD, USD*CADtoUSD, USD*EURtoUSD, USD*AUDtoUSD);       
  printf("----------------------------------------------\n");
  printf("GBP| %.2f   | %.2f   | %.2f  | %.2f  | %.2f  |\n", GBP, USD*GBPtoGBP, USD*CADtoGBP, USD*EURtoGBP, USD*AUDtoGBP);      
  printf("----------------------------------------------\n");
  printf("CAD| %.2f   | %.2f   | %.2f  | %.2f  | %.2f  |\n", CAD, USD*GBPtoCAD, USD*CADtoCAD, USD*EURtoCAD, USD*AUDtoCAD);       
  printf("----------------------------------------------\n");
  printf("EUR| %.2f   | %.2f   | %.2f  | %.2f  | %.2f  |\n", EUR, USD*GBPtoEUR, USD*CADtoEUR, USD*EURtoEUR, USD*AUDtoEUR);       
  printf("----------------------------------------------\n");
  printf("AUD| %.2f   | %.2f  | %.2f  | %.2f  | %.2f  |\n", AUD, USD*GBPtoAUD, USD*CADtoAUD, USD*EURtoAUD, USD*AUDtoAUD);       
  printf("----------------------------------------------\n");
  
  getch();
    return 0;
    
}
