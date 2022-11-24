#include <stdio.h>

int main(){
    printf("%d\n", __LINE__);
    printf("%s\n", __TIME__);
    #line 100 "kontol.exe" 
    printf("%d\n", __LINE__);
    printf("%s\n", __FILE__);
    printf("%s\n", __DATE__);
}