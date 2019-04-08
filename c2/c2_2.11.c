#include <stdio.h>
#include <string.h>

// use exclusive or to swap 2 element
// base on two rules below
// a ^ a = 0
// a ^ (a ^ b) = (a ^ a) ^ b = b
void inplace_swap(int *x, int *y){
                 // assume *x = a, *y = b
  *y = *x ^ *y;  // step 1, *y = a ^ b
  *x = *x ^ *y;  // step 2, *x = a ^ a ^ b = b
  *y = *x ^ *y;  // step 3, *y = a ^ b ^ b = a
}

// pass the pointer of the array
void reverse_array(int *a[], int cnt)
{
  int first, last;
  for(first = 0, last = cnt - 1; first < last; first++, last--)
  { 
    inplace_swap(a[first], a[last]);
  }
  int i;
  for (i = 0; i < cnt; i++)
  {
    printf("value: %i, address: %p\n", *a[i], a[i]);
  }
}

int main(){
  int *a[3];
  int i;
  int a1 = 1;
  int a2 = 2;
  int a3 = 3;
  a[0] = &a1;
  a[1] = &a2;
  a[2] = &a3;
  for (i = 0; i < 3; i++) {
    printf("value: %i, address: %p\n", *a[i], a[i]);
  }
  reverse_array(a, 3);
}

