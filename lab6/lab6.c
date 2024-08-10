#include <stdio.h>
#include <stdlib.h>

unsigned long long rdtsc(void){
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ((unsigned long long)lo)|(((unsigned long long)hi)<<32);
}

int main() {
  // char *buf;
  // buf = (char*)malloc(16);
  // printf("%p\n", buf);
  // return 0;

  unsigned long long int t1, t2;
  unsigned long long mid=0;
for (size_t i = 0; i < 1000000; i++) {
  t1=rdtsc();
  t2=rdtsc();
  mid += t2-t1;
}
mid /= 1000000;
  //printf("Empty: %llu\n", mid);

  size_t size = 16;
  char * refs[10];
  for (size_t i = 0; i < 10; i++) {
    char * a = malloc(size);
    refs[i] = a;
  }
  for (size_t i = 0; i < 10; i++) {
    free(refs[10-i-1]);
  }
  for (size_t i = 0; i < 10; i++) {
    t1 = rdtsc();
    char * a = malloc(size);
    t2=rdtsc();
    printf("%ld,%llu\n",i,t2-t1-mid);
  }


}
