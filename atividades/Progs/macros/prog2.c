// Fazem o compilador permite deixar chamadas que já 
// aconteceram e ignora-las caso ja tiverem sido chamadas

#define DEBUG 1 // O nome da macro nao importa
#if DEBUG
printf("Value of i: %d\n", i);
printf("Value of j: %d\n", j);
#endif

/* #if directive will test the value of DEBUG. 
Since its value isn’t zero, the preprocessor will
leave the two calls of printf in the program (the
#if and #endif lines will disappear, though).
If we change the value of DEBUG to zero and recompile
the program, the preprocessor will remove all four lines 
from the program*/