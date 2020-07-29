#include <stdio.h>
#include <stdlib.h>

#define N 1000000000

extern void registerme ( );
extern void startgame ( int );
extern int valquery ( int );
extern int sgnquery ( int );
extern int delquery ( int );
extern int sumquery ( int );
extern void checksoln ( int, int );

void playgame0(){
  int i;startgame(0);
  for (i = 0; i < N; ++i)
  {
    if(valquery(i)!=i)
      break;
  }
  checksoln(i,valquery(i));
  //i
}

int main(){
  registerme();
  playgame0();
  // playgame1();
  // playgame2();
  // playgame3();
  return 0;
}