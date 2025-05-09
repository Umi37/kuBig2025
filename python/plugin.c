// gcc -fPIC -shared -o libplugin.so plugin.c
// position independance code
// file , objdump, strings, readelf
// objdump -x libplugin.so
// file libplugin.so 
#include <stdio.h>

void hello()
{
    printf("안녕하세요! 저는 플러그인 입니다.\n");
}