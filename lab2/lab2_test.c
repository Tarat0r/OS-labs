#include <stdio.h>
#include <sys/mman.h>

int main(int argc, char const *argv[]) {
  int size = 1024*1024*1024;
  void * p = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
  printf("%p\n", p);
  char buf[16];
  gets(buf);

  for (int i = 0; i < size; i+=4096) {
    ((char*)p)[i]=1;
  }
  printf("FINISHED");
  gets(buf);

  return 0;
}
