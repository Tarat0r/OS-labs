#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

static void* (*real_malloc)(size_t)=NULL;
static void* (*real_free)(void*)=NULL;

unsigned long long rdtsc(void){
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ((unsigned long long)lo)|(((unsigned long long)hi)<<32);
}

static void mtrace_init(void)
{
   real_malloc = dlsym(RTLD_NEXT, "malloc");
   if (NULL == real_malloc) {
       fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
   }

    real_free = dlsym(RTLD_NEXT, "free");
     if (NULL == real_free) {
         fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
     }
}

void *malloc(size_t size)
{
    if(real_malloc==NULL) {
        mtrace_init();
    }
    unsigned long long t1,t2;

    void *p = NULL;
    t1 = rdtsc();
    p = real_malloc(size);
    t2 = rdtsc();
    fprintf(stderr, "malloc(%ld) = ", size);
    fprintf(stderr, "%p time=%lld\n", p, t2-t1);
    return p;
}

void free(void * p)
{
    if(real_free==NULL) {
        mtrace_init();
    }
    unsigned long long t1,t2;

    t1 = rdtsc();
    real_free(p);
    t2 = rdtsc();
    fprintf(stderr, "free(%p) time=%lld\n", p, t2-t1);

    //return p;
}
