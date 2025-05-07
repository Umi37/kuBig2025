#include <stdio.h>

// ✅ 2차원 배열의 합을 구하는 함수 선언
int sumMatrix(int (*pM)[4], int n, int m);

int main(void)
{  
     // ✅ 1. 3x4 크기의 2차원 배열 선언
    int matrix[3][4]= {
        {1, 2, 3, 4},
        {11, 12, 13, 14},
        {21, 22, 23, 24}};

    // ✅ 2. sumMatrix() 함수 호출 및 배열 크기 계산
    int sum = sumMatrix(matrix, 
        (sizeof(matrix)/sizeof(int))/(sizeof(matrix[0])/sizeof(int)), // 행 개수 계산
        sizeof(matrix[0])/sizeof(int)); // 열 개수 계산

        // ✅ 3. 결과 출력
        printf( "sum of Matrix : %d\n", sum);
        return 0;
    
}

// ✅ 4. sumMatrix 함수 정의
// 📌 함수 목적: 2차원 배열의 모든 요소의 합을 반환

int sumMatrix(int (*pM)[4], int n, int m)
{
    int sum = 0;                        // ✅ 합계를 저장할 변수 초기화
    for (int i = 0; i < n; ++i)         // ✅ 행 반복
    {
        for (int j = 0; j < m; ++j)     // ✅ 열 반복
        {
            sum += pM[i][j];            // ✅ 각 요소 값을 sum에 더함
        } 
    }
    return sum;                         // ✅ 최종 합 반환
}
