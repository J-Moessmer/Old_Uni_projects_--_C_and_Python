#include <stdio.h>


/*DIN5008-Normaldatum aus
zahl für tag [zweistelling], Monat [Ausgesvhrieben], jahr [vierstellig] */
typedef struct{
    int tag;
    char monat[10];
    int jahr;
} DIN5008_TTMonatJJJJ;

/*Namen der wochentage */
const char Wochentage [][15] =
{
    "" /* Nr.0*/, "Montag" /*Nr.1*/, "Diesntag" /*Nr.2*/, "Mittwoch" /*Nr.3*/,
    "Donnerstag" /*Nr.4*/, "Freitag" /*Nr.5*/,"Samstag" /*Nr.6*/ "Sonntag" /*Nr.7*/
};

/*Angebotskategorien des Mensa-Speiseplans*/
const char Angebot[][50] =
{
    "void" /*Nr.0 markiert eine leere Mensa-essen datenstruktur*/, 
    "Essen I" /*Nr.1*/, "Essen II" /*Nr.2*/, "Eintopf" /*Nr.3*/, 
    "Pizza" /*Nr.5*/, "Dessertauswahl" /*Nr.6*/, "Aktionsstand" /*Nr.7*/, 
    "Grill" /*Nr.8*/, "Gratin"/*Nr.9*/,"Zur Pizza" /*Nr.10*/, 
    "GreenCorner" /*Nr.11*/, "Sontiges" /*Nr.12*/
};

/*Struktur für ein Mensa-Gericht*/
typedef struct {
    int angebot_nr; /*Nummer der Angebotskategorie*/
    int hauptgericht; /* 1= haptgericht / 0= kein HG*/
    char bezeichnung[100]; /*bezeichnung des Gerichts, z.B Obstbecher
    * Kennzeichnung ist eine zeichenkette mit einem oer mehreren Buchstaben.
    * Gibt es KEINE kennzeichnung dann ist die kette leer ""*/
    char kennzeichnung[10]; /*Z.B. "FA" für Fleichlos mit Alkohol
    * max 20 angaben (Zahlen) für zusatzstoffe. 0 bedeuted keine angabe */
    int zusatzstoffe_und_alergene[20]; /*alle nicht belegten Elemente müssen 0 sein!*/
    char glutenhaltiges_getreide; /* 0 wenn nicht vorhanden, 'a', 'b', 'c' etc. sonst*/
    char schalenfruechte; /* 0 wenn nicht vorhanden, 'a', 'b', 'c' etc. sonst */
    int centpreis[3]; /* Preise in Euro-Cent:
    * Centpreis [0] = studentenpreis
    * Centpreis [1] = bedienstetenpreis
    * Centpreis[2] = Gästepreis*/

} Mensa_Gericht;

/* zusammenfassung strukturen*/
typedef struct {

    DIN5008_TTMonatJJJJ tagesdatum;
    int w_tage;
    Mensa_Gericht tageskarte[11];
} Tagesbestellung;

/*Hier enden die Typdefinitionen und die globalen Datenstrukturen
*-----------------------------------------------------------------*/

int main (void) {


    /*speiseplan*/


    Mensa_Gericht Cabbage_leaves =
    { 1, /*Angebotskategorie*/
      1, /*hauptgericht 1 = ja / 0 = nein*/
      "Savoy cabbage leaves stuffed with minced meat", /*Name Gericht*/
      "SR", /*Inhaltkennzeichnung*/
      {23, 14, 20}, /*Alergene + inhaltsstoffe*/
      'a', /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {130, 350, 350} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht Italian_vegetable =
    { 2, /*Angebotskategorie*/
      1, /*hauptgericht 1 = ja / 0 = nein*/
      "Italian vegetable risotto", /*Name Gericht*/
      "F", /*Inhaltkennzeichnung*/
      {19, 22, 15}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {130, 350, 350} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht Vegetable_stew =
    { 3, /*Angebotskategorie*/
      1, /*hauptgericht 1 = ja / 0 = nein*/
      "Vegetable stew + Wheat roll", /*Name Gericht*/
      "V", /*Inhaltkennzeichnung*/
      {22,20}, /*Alergene + inhaltsstoffe*/
      'a', /*Glutenhaltiges getreide*/
      /* c fehlt und kann nicht eingetragen werden wegen strukturlimit*/
      0, /*Schalenfrüchte*/
      {120, 270, 270} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht closed_grill =
    { 8, /*Angebotskategorie*/
      0, /*hauptgericht 1 = ja / 0 = nein*/
      "Counter Closed", /*Name Gericht*/
      "", /*Inhaltkennzeichnung*/
      {0}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {0, 0, 0} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht pizza =
    { 5, /*Angebotskategorie*/
      1, /*hauptgericht 1 = ja / 0 = nein*/
      "Margherita pizza - select further ingredients yourself", /*Name Gericht*/
      "", /*Inhaltkennzeichnung*/
      {2,3,19,22,15,20}, /*Alergene + inhaltsstoffe*/
      'a', /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {305, 345, 345} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht Pizza_ss_Pineapple =
    { 10, /*Angebotskategorie*/
      0, /*hauptgericht 1 = ja / 0 = nein*/
      "Pizza side selection I Pineapple", /*Name Gericht*/
      "", /*Inhaltkennzeichnung*/
      {0}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {60, 70, 70} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht Pizza_ss_Leaf_spinach =
    { 10, /*Angebotskategorie*/
      0, /*hauptgericht 1 = ja / 0 = nein*/
      "Pizza side selection I Leaf spinach", /*Name Gericht*/
      "", /*Inhaltkennzeichnung*/
      {0}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {60, 70, 70} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht Pizza_ss_Cooked_ham =
    { 10, /*Angebotskategorie*/
      0, /*hauptgericht 1 = ja / 0 = nein*/
      "Pizza side selection I Cooked ham", /*Name Gericht*/
      "S", /*Inhaltkennzeichnung*/
      {2,12,21,14}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {130, 160, 160} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht GreenCorner =
    { 11, /*Angebotskategorie*/
      0, /*hauptgericht 1 = ja / 0 = nein*/
      "The healthy alternative - Price per 100g", /*Name Gericht*/
      "Z", /*Inhaltkennzeichnung*/
      {0}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {70, 80, 80} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht side_dishes =
    { 12, /*Angebotskategorie*/
      0, /*hauptgericht 1 = ja / 0 = nein*/
      "Various side dishes choices", /*Name Gericht*/
      "Z", /*Inhaltkennzeichnung*/
      {0}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {60, 80, 80} /*preis: Stud, Arbeit, Gast*/
    };

    Mensa_Gericht dessert_choice =
    { 6, /*Angebotskategorie*/
      0, /*hauptgericht 1 = ja / 0 = nein*/
      "Various dessert choices", /*Name Gericht*/
      "Z", /*Inhaltkennzeichnung*/
      {0}, /*Alergene + inhaltsstoffe*/
      0, /*Glutenhaltiges getreide*/
      0, /*Schalenfrüchte*/
      {60, 80, 80} /*preis: Stud, Arbeit, Gast*/
    };


    /*variablendefinition     einzelvariablen*/
    char pruefung;
    int innen, aussen, matnummer, preis, preiswahl, g_gericht_preis, greenstuff_preis;
    Mensa_Gericht g_gericht, greenstuff;


    /*Tagesbestellung bestelltag;
    Tagesbestellung jahr_best[365];
    test*/


    scanf(" %i", &matnummer);
    printf("Suchen im Mensa-Speiseplan, Joshua Moeßmer %i 
", matnummer);

    Tagesbestellung jahr_best[365];
    Tagesbestellung bestelltag = {{10,"january",2019},4, {Cabbage_leaves,Italian_vegetable,Vegetable_stew,closed_grill,pizza, Pizza_ss_Pineapple,
    Pizza_ss_Leaf_spinach,Pizza_ss_Cooked_ham,GreenCorner,side_dishes,dessert_choice}};
    jahr_best[9] = bestelltag;



    /*pruefung eingabe + suche*/
    scanf(" %c", &pruefung);
    if ((pruefung == 'S')        (pruefung== 'G')        (pruefung== 'B')){

        /*Suchschleife
        *funktionsweise wie "altes zaehlwerk", innere schleife [innen] zaehlt voll damit aussere [aussen] um einen wert steigt*/
        for (aussen=0; aussen<11; aussen++){
            for (innen=0;innen<10; innen++){
                if ((jahr_best[9].tageskarte[aussen].hauptgericht==1)&&(jahr_best[9].tageskarte[aussen].kennzeichnung[innen]!= 'S')){
                    g_gericht = jahr_best[9].tageskarte[aussen];
                }
            }
        }

        for (aussen=0;aussen<11; aussen++){
            if (jahr_best[9].tageskarte[aussen].angebot_nr==11){
                greenstuff = jahr_best[9].tageskarte[aussen];
            }
        }

        /*preisberechnung*/

        if (pruefung == 'S')
            preiswahl = 0;
        if (pruefung == 'B')
            preiswahl = 1;
        if (pruefung == 'G')
            preiswahl = 2;

        g_gericht_preis = g_gericht.centpreis[preiswahl];
        greenstuff_preis = greenstuff.centpreis[preiswahl];
        preis = ((greenstuff_preis*250/100)+g_gericht_preis)/100;

        printf("Meine Bestellung am %s: %i.%s %i 
 ist: %s 
 mit 
 %s 
 Kostet %i Euro",Wochentage[jahr_best[9].w_tage], jahr_best[9].tagesdatum.tag, jahr_best[9].tagesdatum.monat, jahr_best[9].tagesdatum.jahr, g_gericht.bezeichnung, greenstuff.bezeichnung, preis);


    }
    else{
        printf("!!!FEHLER!!!");
    }






    return 0;
}
