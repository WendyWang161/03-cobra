#include <stdio.h>
#include <stdlib.h>

extern int our_code_starts_here() asm("our_code_starts_here");

int print(int val){
  if (val == 0xFFFFFFFF)
    printf("true\n");
  else if (val == 0x7FFFFFFF)
    printf("false\n");
  else // should be a number!
    printf("%d\n", val >> 1);  // shift right to remove tag bit.
  return val;
}


void error(int code){
   if (code == 0) {
     fprintf(stderr, "Error: expected a number");
   }
   else if (code == 1) {
     fprintf(stderr, "Error: arithmetic overflow");
   }
   else if (code == 2) {
     fprintf(stderr, "Error: expected a boolean");
   } 
   exit(1);
}

int main(int argc, char** argv) {
  int result = our_code_starts_here();
  //printf("Result is %d\n", result);
  print(result);
  return 0;
}
