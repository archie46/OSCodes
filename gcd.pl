gcd(X,0,Z) :- Z is X,!.
gcd(0,X,Z) :- Z is X,!.
gcd(X,Y,Z) :- R is X mod Y,
              gcd(Y,R,Z).
