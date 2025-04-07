#!/bin/bash

# 반복문
# for 변수 in 리스트; do
#       # 반복할 코드
# done

for name in "Song" "Amy" "Charls"; do
    echo "이름: $name"
done

echo "0 부터 100 까지 숫자 프린트 ----- "
for int in {0..100}; do
    echo -n " $int "
done

# while () 문장1; 문장2; --> while [ condition ]; do 문장1 ; 문장2; done
# until 루프 --> until [ condition ]; do 문장1; 문장2; done
# break continue... 동일 
echo ""

# 함수!!  -> argument 없음. $1, $2, $3 소괄호 없음. 리턴 없음. > $?
function hello {
    lacal testInt=45
    echo "안녕하세요~! $1님"
    return 2
}

hello "송우림"
echo "반환된 값은 $? 입니다."
echo "$testInt"

# 변수의 선언 -> 모든 선언이 전역 변수

# 크론잡 crontab cron : 시간에 맞추어서 쉘 스크립트를 실행하는 기능. 유틸리티티

