#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int main(){
char buf1[16];
int size = 2*1024*1024;

while(1) {
char * buf = (char*)VirtualAlloc(0,size,MEM_COMMIT | MEM_RESERVE,PAGE_READWRITE | PAGE_NOCACHE);

printf("%s",buf);


if (buf == NULL){
    auto code = GetLastError();
    wprintf(L"VirtualAlloc() failed with error 0x%x\n", code);
    return code;
}


}
return 0;

}
