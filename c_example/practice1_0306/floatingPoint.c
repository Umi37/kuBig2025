#include <stdio.h>

int main(void)
{
    printf("-----------교재실습-----------\n");
    printf("%.1lf\n", 1e6);
    printf("%.7lf\n", 3.14e-5);
    printf("%le\n", 0.0000314);
    printf("%.2le\n", 0.0000314);
    printf("-----------------------------\n");
    
    double num = 3.14L ;

    printf("%lf\n",num) ;
    printf("%le\n",num) ;
    printf("%.1lf\n",num) ;
    printf("%.2lf\n",num) ;
    printf("%.7lf\n",num) ;
    printf("%.14lf\n",num) ;

    return 0;
}