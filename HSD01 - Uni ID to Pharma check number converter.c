#include <stdio.h>

int main (void) {
  /*Meine Matrikelnummer als Pharmazentralnummer PZN, Joshua Mößmer 789749*/


  
  /* Pruef ist die prüfzahl */
  int pruef, zsum1, zsum2, zsum3, zsum4, zsum5, zsum6, summe,mod11;
  char nummer1, nummer2, nummer3, nummer4, nummer5, nummer6;
  
  /*abfrage jeder zahl x1 -> x6*/
  nummer1 = getchar();
  nummer2 = getchar();
  nummer3 = getchar();
  nummer4 = getchar();
  nummer5 = getchar();
  nummer6 = getchar();
  /*Algorithmus zur berechnung der prüfzahl*/
  
  
  zsum1 = (nummer1-'0')*2;
  zsum2 = (nummer2-'0')*3;
  zsum3 = (nummer3-'0')*4;
  zsum4 = (nummer4-'0')*5;
  zsum5 = (nummer5-'0')*6;
  zsum6 = (nummer6-'0')*7;
  
  summe = (zsum1+zsum2+zsum3+zsum4+zsum5+zsum6);
  mod11 = summe%11;
  pruef = mod11%10;
  
  /*printfunktion für die anzeige*/
  printf("\nJOS-%c%c%c%c%c%c%i",nummer1, nummer2, nummer3, nummer4, nummer5, nummer6, pruef);
  
  return 0;
}
