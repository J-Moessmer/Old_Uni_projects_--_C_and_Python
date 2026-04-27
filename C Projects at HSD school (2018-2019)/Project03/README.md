# HSD 03 - Cafeteria Programm | C

This is a basic programm to search a Weekly Menu of a cafeteria based on the date and then calculate the price depending if the costumer is student, teacher or guest.

#### Flowchart
```mermaid
flowchart TD
    A[Initialize Structs with Menu Items] --> B[Read Matriculation Number]
    B --> C[Read Customer Role 'S', 'B', 'G']
    C --> D{Valid Role?}
    D -- Yes --> E[Nested Loop: Find Main Dish without 'S' Allergen]
    E --> F[Loop: Find 'GreenCorner' Item]
    F --> G[Extract Prices from Struct based on Role]
    G --> H[Calculate Total Price]
    H --> I[Print Order & Price]
    D -- No --> J[Print Error]
```

#### Code Snippet
```c
  /*Suchschleife: find valid main dish*/
  for (aussen=0; aussen<11; aussen++){
      for (innen=0;innen<10; innen++){
          if ((jahr_best[9].tageskarte[aussen].hauptgericht==1)&&(jahr_best[9].tageskarte[aussen].kennzeichnung[innen]!= 'S')){
              g_gericht = jahr_best[9].tageskarte[aussen];
          }
      }
  }

  /*preisberechnung*/
  if (pruefung == 'S') preiswahl = 0;
  if (pruefung == 'B') preiswahl = 1;
  if (pruefung == 'G') preiswahl = 2;
```
