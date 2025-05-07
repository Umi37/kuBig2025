#include <arpa/inet.h>
#include <stdio.h>

void print_addr(unsigned long conv_addr)
{
    if(conv_addr==INADDR_NONE)
        printf("Error occured!\n");
    else
        printf("네트워크의 인트 addr: %#lx \n", conv_addr);
}

int main()
{
    const char *addr1 = "127.212.124.78";
    const char *addr2 = "127.212.124.256"; // 256 error

    unsigned long conv_addr = inet_addr(addr1);
    print_addr(conv_addr);  // 0x4e7cd47f 

    conv_addr = inet_addr(addr2);
    print_addr(conv_addr);

    return 0;
    
}