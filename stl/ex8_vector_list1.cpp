#include <iostream>
#include <vector>
#include <ctime> // 왜 time.h를 쓰지 않고 ctime을 쓸까?
#include <unistd.h>

using namespace std;

void test_function(vector<int> students);
    
int main()
{
    vector<int> students;
    int student;
    FILE *fp = fopen("/home/woo/kuBig2025/stl/student.txt", "r");

    while (fread(&student,2,1, fp))
        students.push_back(student); 
    for (auto v : students)
        cout << v << endl;
    fclose(fp);

    auto count = students.size();
    
    // vector 의 연산 시간!!
    double begin = clock();
    test_function(students);
    double end = clock();

    cout << "벡터를 연산하는 시간은" << count << "데이터 사이즈" << endl;
    cout << "지워진 데이터의 숫자는" << count - students.size() << endl;
    cout << (end - begin) / CLOCKS_PER_SEC << "초" << endl; // CLOCK_PER_SEC : 1틱이 1초는 아니니까, 연산해줄수 있는 디파인되어있는 상수 이용
    return 0;

}

void test_function(vector<int> students)
{
    vector<int>::iterator it = students.begin();
    while( it != students.end())
    {
        if ( *it < 60){
            it = students.erase(it); // erase는 iterator를 재정의하여 뒷쪽으로 리턴해준다. 범위 for문 안에서도 잘 동작할 수 있게 됨.
        } else {
            ++it;
        }
    }
}