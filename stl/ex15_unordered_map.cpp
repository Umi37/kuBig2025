// 표준 입력을 받아서 (영어문장) - this is a apple 
// unordered_map을 사용하여 단어 별 등장 횟수를 출력하는 프로그램

#include <iostream>
#include <sstream> // stream 으로 들어온 것을 string 으로 변환
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string clean_word(const string& word)
{
    string cleaned;
    for (char ch: word){
        if (isalpha(ch) || isdigit(ch))
            cleaned += tolower(ch); // 대소문자가 섞여있는 문자를 전부 소문자로 변환
    }
    return cleaned;
}

int main()
{
    string line;
    getline(cin, line); // 표준 입력을 받아서

    unordered_map<string, int> word_count; // 단어와 등장 횟수를 저장하는 해시맵
    istringstream iss(line); // 입력 스트림을 단어 단위로 나누기 위해 사용
    string word;

    while (iss >> word) // 단어 단위로 나누기
    {
        string cleaned = clean_word(word); // 단어 정리
        if (!cleaned.empty())  // 단어가 비어있지 않으면
        {
            word_count[cleaned]++; // word_count[key] = value; 단어 등장 횟수 증가
        }   
    }
    for (const auto& [key, value] : word_count) { // key, value 쌍으로 출력
        cout << key << ": " << value << endl;
    } // 단어와 등장 횟수 출력

    return 0;
} // 프로그램 종료
