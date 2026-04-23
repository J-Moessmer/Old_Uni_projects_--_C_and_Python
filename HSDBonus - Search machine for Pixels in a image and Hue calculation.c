#include <zusatzaufgabe.h>
#define NUMCYCLES 1
#include <ifi_stdio.h>
#include <ifi_colormeter.h>
/*---------------------------------------------------------------------------------------*/
/* The function eps_open_colorimage8() opens an eps file and tries to find the begin of */
/* an embedded colorimage having 8 bits per channel. If successful, the function returns */
/* the width of the image (number of RGB pixels per image row). Otherwise 0 is returned. */
/* If an color image is found, the widht and the height of the image is written into the */
/* variables pointed to by img_width and img_height respectively. */
/* After a successful call to eps_open_colorimage8() the next character read from that */
/* stream will be the first character belonging to the image pixel values. */
int eps_open_colorimage8(FILE *stream, /* pointer to input stream, eg stdin */
                         int *img_width, /* pointer to int variable for image width */
                         int *img_height /* pointer to int variable for image height */
                        );
void setup() {
  // damit wird eine Verbindung zwischen dem Arduin//
  // und dem PC hergestellt (Serielle Schnittstelle)
  // mit 9600 Baud)

  ifi_stdio_init(9600);
printf("\n\nArduino erfolgreich gestartet!\n\n");
printf("Zusatzaufgabe - J M - 789749 \n \n ");  
    // Initialisierung des Farbmessgerätes

  colormeter_init();
}
void loop() {
  int width, height, i, j;
  int r, g, b; /*farbwerte rgb*/ 
  int cmax, cmin, delta, hue, skinhue, zaehl;
  float tmp;
  char lcdtext[17];
  unsigned char rgb_image[3][5][3];
  i = eps_open_colorimage8(stdin, /* pointer to input stream, eg stdin */
                           &width, /* pointer to int variable for image width */
                           &height /* pointer to int variable for image height */
                          );
  
  /*-------------------- Pruefung auf dimensionen --------------------*/
  if (i != 0)
  { //pruefung auf bild Dimensionen (5x3 pixel)
    if (width==5 && height==3)
      printf("Bild in Ordnung mit %ix%i Pixeln \n",width, height);
    else
    {
      printf("Bild nicht in Ordnung \n Richtige groesse: 5x3 \n momentane groesse: %ix%i", width, height);
      return;
    }
    /*-------------------- Suchschleifen und speichern der pixel -------------------*/
    
    
    for (i=0; i< height; i++)
      for (j=0; j< width; j++)
      {
        scanf("%2x%2x%2x", &r, &g, &b);
        
        rgb_image[i][j][0] = r;
        rgb_image[i][j][1] = g;
        rgb_image[i][j][2] = b;
      }
    //pixel koordinaten in rgb_image[i][j][x]
    //   0 1 2 3 4 [j]
    // 0 x x x x x
    // 1 x x x x x
    // 2 x x x x x
    // [i]
    
    //--------------------Ausgabe der RGB werte für pixel 789749--------------------//
    //789749 =
    //    - I II III IV [j]
    // -  3 4 5  6   7
    // I  2 x x  x   8
    // II 1 x x  x   9
    // [i]
    // 
    // 7 rgb_image[0][4]
    // 8 rgb_image[1][4]
    // 9 rgb_image[2][4]
    // 7 rgb_image[0][4]
    // 4 rgb_image[0][1]
    // 9 rgb_image[2][4]
 
    colormeter_rgbled(rgb_image[0][4] [0], rgb_image[0][4] [1], rgb_image[0][4] [2]); //7
    colormeter_analoganzeige(rgb_image[0][4] [0], rgb_image[0][4] [1], rgb_image[0][4] [2]);
    delay((7+8+9+7+4+9)*100);
    colormeter_rgbled(rgb_image[1][4] [0], rgb_image[1][4] [1], rgb_image[1][4] [2]); //8
    colormeter_analoganzeige(rgb_image[1][4] [0], rgb_image[1][4] [1], rgb_image[1][4] [2]);
    delay((7+8+9+7+4+9)*100);
    colormeter_rgbled(rgb_image[2][4] [0], rgb_image[2][4] [1], rgb_image[2][4] [2]); //9
    colormeter_analoganzeige(rgb_image[2][4] [0], rgb_image[2][4] [1], rgb_image[2][4] [2]);
    delay((7+8+9+7+4+9)*100);
    colormeter_rgbled(rgb_image[0][4] [0], rgb_image[0][4] [1], rgb_image[0][4] [2]); //7
    colormeter_analoganzeige(rgb_image[0][4] [0], rgb_image[0][4] [1], rgb_image[0][4] [2]);
    delay((7+8+9+7+4+9)*100);
    colormeter_rgbled(rgb_image[0][1] [0], rgb_image[0][1] [1], rgb_image[0][1] [2]); //4
    colormeter_analoganzeige(rgb_image[0][1] [0], rgb_image[0][1] [1], rgb_image[0][1] [2]);
    delay((7+8+9+7+4+9)*100);
    colormeter_rgbled(rgb_image[2][4] [0], rgb_image[2][4] [1], rgb_image[2][4] [2]); //9
    colormeter_analoganzeige(rgb_image[2][4] [0], rgb_image[2][4] [1], rgb_image[2][4] [2]);
    delay((7+8+9+7+4+9)*100);
    
    
    
    
    //-------------------- haertewert berechnung --------------------//
    skinhue=0;
    zaehl=0;
    
    for (i=0; i< height; i++)
      for (j=0; j< width; j++)
      {
        
        r = rgb_image[i][j][0];
        g = rgb_image[i][j][1];
        b = rgb_image[i][j][2];
        
        cmin = r < g ? r : g; //minimale farbwert berechnung rgb
        cmin = cmin < b ? cmin : b;
        
        cmax = r > g ? r : g; //maximale farbwert berechnung rgb
        cmax = cmax > b ? cmax : b;
        
        delta = cmax - cmin; //unterschied cmin <-> cmax
        
        if (delta == 0) { // <=> r=g=b <=> Grauton --> h undefiniert
          hue = -1;

        }
        else
        {
          if ( r == cmax ) {
            tmp = ( (float)g - b ) / delta; // zwischen Gelb und Magenta
          } else if ( g == cmax ) {
            tmp = 2 + ( (float)b - r ) / delta; // zwischen Cyan und Gelb
          } else {
            tmp = 4 + ( (float)r - g ) / delta; // zwischen Magenta und Cyan
          }
          tmp *= 60; // Winkel in Grad
          if (tmp < 0 ) {
            tmp += 360;
          } 
          hue=tmp;
          //hue = haertewert momentaner pixel
          
          
          
          if ((hue <=36 )&&(hue >=6)){
            skinhue += hue;
            zaehl++;
          }
            
          
          
        }
        
        
        
      }
    skinhue=skinhue/zaehl; //Mittelwert aller Hautfarben
    //printf("test skinhue = %i", skinhue);
    
    
    
    //-------------------- Ausgabe auf LCD display --------------------//
    
    sprintf(lcdtext,"%3i",skinhue); //umwandung integer in char fuer die anzeige
    
    
    colormeter_printlcd(0, 0, "Haertewert Haut: ");
    colormeter_printlcd(6, 1,lcdtext);
  

  }
  
  
}
