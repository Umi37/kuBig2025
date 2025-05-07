#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    // 짝수만 필터링하여 벡터에 저장
    vector<int> evens; 
    copy_if (nums.begin(), nums.end(), back_inserter(evens), [](int x) 
            { return x % 2 == 0; }); // nums 벡터에서 짝수만 evens 벡터에 복사 (람다 사용)

    // 제곱해서 저장
    vector<int> squares(evens.size()); // size()로 초기화
    transform(evens.begin(), evens.end(), squares.begin(), [](int x) 
            { return x * x; }); // evens 벡터의 각 요소를 제곱하여 squares 벡터에 저장
    
    // 결과 출력
    cout << "짝수의 제곱 결과: ";
    for (const auto & v: squares)
    {
        cout << v << " "; // 제곱된 짝수 출력
    }
    cout << endl;
    return 0; 

}