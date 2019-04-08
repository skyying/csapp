
#include <stdio.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len)
{
  size_t i;
  for(i = 0; i<len; i++)
    printf(" %.2x", start[i]);
  printf("\n");
}

void show_int(int x)
{
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
  int ival= val;
  float fval = (float) ival;
  int *pval = &ival;
  show_int(ival);  // 21 43 65 87  
  show_float(fval); // 7a 35 f1 ce
  show_pointer(pval); // 68 78 cd eb fe 7f 00 00
}

int main(){
  int val = 0x87654321;
  byte_pointer valp = (byte_pointer) &val;
  show_bytes(valp, 1);  // 21  little edndian
  show_bytes(valp, 2);  // 43
  show_bytes(valp, 3);  // 65
}

