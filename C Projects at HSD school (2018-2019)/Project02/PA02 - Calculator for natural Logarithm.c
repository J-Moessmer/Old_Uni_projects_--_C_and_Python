
/*Eingabe von Gleitkommazahlen und Berechnung ihres natürlichen Logarithmus | Joshua Mößmer 789749*/


#include <stdio.h>

int main (void) {
  
  /*definition variablen*/
  double input, addende, reiargument, ergebnis, potenz;
  int teste, iterator, sumcount,minus, anzahl;
  
  /* addende = letzer summant der summ
  * reiargument = reienargument
  * iterator = zaehler i der for-schleife
  * anzahl = anzsahl der einzulesenden werte
  * ergebnis = output
  */
  
  /*eingabe test zahl <-> buchstabe für eingabeschritte*/
  teste = scanf("%i", &anzahl);
  if (teste==0)
    printf("!!!FEHLER - BITTE ZAHL EINGEBEN!!!\n");
    
    /*eingabe test [+/-] zahl*/
  else{
    if(anzahl<=0){
      printf("!!!FEHLER - BITTE POSITIVE ZAHL EINGEBEN!!!\n");
    }
    else{
      /*äusser schleife wiederholung*/
      for(iterator=1; iterator<=anzahl;iterator=iterator+1 ){
        teste=scanf("%lf", &input);
        
        /*eingabe test zahl <-> buchstabe für berechnung*/
        if (teste==0)
          printf("!!!FEHLER - BITTE ZAHL EINGEBEN!!!\n");
          
        else{
          if(input<=0){
            printf("!!!FEHLER - BITTE POSITIVE ZAHL EINGEBEN!!!\n");
          }
          else{
            /*berechnung*/
            
            if ((input-1<=1)&&(input-1)>=-1){
              reiargument=input-1;
            }
            else {
              reiargument=(1-input)/input;
            }
            
            /*definition + zurücksertzung der werte für berechnung*/
            ergebnis=0;
            minus=1;
            sumcount=1;
            potenz=reiargument;
            addende=potenz;
            
            /* || = oder
            * && = Und
            *
            * berechnung
            */
            while((sumcount<789749%10000)&&((addende>=1.0/789749)||(addende<=-1.0/789749))){
              ergebnis=ergebnis+addende;
              sumcount=sumcount+1;
              minus=minus*(-1);
              potenz=potenz*reiargument;
              addende=minus*potenz/sumcount;
            }
            
            /* (1 + ) = (1 + [...])*/
            if ((input-1>1)||(input-1)<-1){
              ergebnis=-ergebnis;
            }
            /*output*/
            printf("ln = %lf , %lf iteration %i \n", input, ergebnis, sumcount);
          }
        }
      }
    }
  }
  return 0;
}
