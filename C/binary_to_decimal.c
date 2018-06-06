#include <stdio.h>

int power(int e, int x);
int binaryToDecimal(int b[]);
int main() {
  int b[] = {1,0,0,1,2};
  binaryToDecimal(b);
  return 0;
}

int binaryToDecimal(int b[]) {
  int d = 0;
  int base;
  int i = 0;
  int result = 0;
  //may be out of bounds but then it will return a value other than 0 or 1 -> ok
  while ((b[d] == 0) || (b[d] == 1)) {
    printf("%d",b[d]);
    d++;
  }
  base = d;
  for (i=0;i<d;i++) {
    result += (b[i] * power(2,base));
    base--;
  }
  printf("\nresult: %d\n",result);
  return result;
}

int power(int e, int x) {
  if (x == 0) {
    return 1;
  } else if (x==1) {
    return e;
  } else {
    return e*power(e,x-1);
  }
}
