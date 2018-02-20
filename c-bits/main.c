#include <stdio.h>
#include <stdlib.h>

extern int our_code_starts_here() asm("our_code_starts_here");

void print(int val){
  if (val == 0xFFFFFFFF)
    printf("true\n");
  else if (val == 0x7FFFFFFF)
    printf("false\n");
  else // should be a number!
    printf("%d\n", val >> 1);  // shift right to remove tag bit.
}

int main(int argc, char** argv) {
  int result = our_code_starts_here();
  print(result);
  return 0;
}
