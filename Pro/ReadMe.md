***A Syntactically Correct Sentence (well-formed formula or wff) in Propositional Logic***
```
~(P->Q)&((Q&P)->Q)
```
Analysis (output of the language processor: ***ACCEPTED***)
```
 Truth table for ~(P->Q)&((Q&P)->Q)


    P     Q   (P->Q)   ~((P->Q))   (Q&P)   ((Q&P)->Q)      ~(P->Q)&((Q&P)->Q)
 
----------------------------------------------------------------------------------------------
    F     F       T          F      F           T                       F 

    F     T       T          F      F           T                       F 

    T     F       F          T      F           T                       T 

    T     T       T          F      T           T                       F 

The wff ~(P->Q)&((Q&P)->Q) is...

Invalid
Consistent
```
----
***A Syntactically Incorrect Sentence (ill-formed formula) in Propositional Logic***
```
(P&Q
```
Analysis (output of the language processor: ***REJECTED***)
```
Error class: syntax error

Error : error in line 1 caused by '(' [unmatched left paranthesis or it has invalid placement]

Error string: (P&Q
```
