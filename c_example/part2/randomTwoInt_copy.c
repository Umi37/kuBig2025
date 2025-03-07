// 두 난수 ( 0 ~ 100)를 발생 시켜서 비교하기

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h> 

// int main(void)
// {
//     int a, b;
//     double rand1;
//     srand((unsigned int)time(NULL));
//     rand1 = rand() / (double)RAND_MAX * 100 ; // 0과 1사이의 플럿을 뽑아내서 쓴다????
//     printf(" 0 ~ 100 사이의 랜덤한 숫자 : %f", rand1) ;
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int a ;
//     int rand1 ;
//     rand1 = rand() ;

//     printf("랜덤숫자 : %d", rand1) ;

//     return 0 ;

// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(void)
{
    int a, b, i;
    double rand1, rand2;
    while (1)
    {
        i++;
        srand((unsigned int)time(NULL) + i );
        rand1 = rand() / (double)RAND_MAX * 10 ; 
        srand((unsigned int)time(NULL) + i + 10000);
        rand2 = rand() / (double)RAND_MAX * 10 ; 

        a = rand1 ;
        b = rand2 ;

        printf(" 0 ~ 100 사이의 랜덤한 숫자 : %f\n", rand1) ;
        printf(" 0 ~ 100 사이의 랜덤한 숫자 : %f\n", rand2) ;
        printf("%d > %d :%s\n", a, b, a > b ? "true" : "false");
        printf("%d < %d :%s\n", a, b, a < b ? "true" : "false");
        printf("%d == %d :%s\n", a, b, a == b ? "true" : "false");
        printf("%d != %d :%s\n", a, b, a != b ? "true" : "false");
    
    if(a=b);
    break;

    return 0;
    }

}