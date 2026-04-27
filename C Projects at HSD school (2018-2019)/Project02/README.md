# HSD 02 - Calculator for natural Logarithm | C

A basic programm to calculate the natural Logarithm ln(x) using an iterative series approximation.

#### Flowchart
```mermaid
flowchart TD
    A[Read Number of Iterations 'n'] --> B{i <= n?}
    B -- Yes --> C[Read Float 'x']
    C --> D{x > 0?}
    D -- Yes --> E[Calculate Argument Series 'addende']
    D -- No --> F[Print Error]
    E --> G[Iterate and Accumulate Result]
    G --> H[Print Output]
    H --> B
    B -- No --> I[End]
```

#### Code Snippet
```c
  while((sumcount<789749%10000)&&((addende>=1.0/789749)||(addende<=-1.0/789749))){
    ergebnis=ergebnis+addende;
    sumcount=sumcount+1;
    minus=minus*(-1);
    potenz=potenz*reiargument;
    addende=minus*potenz/sumcount;
  }
```
