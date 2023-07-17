#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_solution(int n) {
  // seed the random number generator with the current time
  srand(time(0));
  // randomly select a number between 1 and n and return it as the solution
  return rand() % n + 1;
}

int main() {
  int n = 10;  // the range of possible solutions is 1 to n
  printf("Solution: %d\n", find_solution(n));
  return 0;
}
