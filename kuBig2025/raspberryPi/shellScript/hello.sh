#!/bin/bash


name="Song Woorim"
export age=25

echo "Hello, world!, $name"
echo "date : " `date`

text="hello, world!"
echo ${hello:0:5}
echo ${text:7}

text="I like cats"
echo ${text/cats/dogs}

text="I like cats, I really like cats"
echo ${text//cats/dogs}
echo ${#text}

# 중요! unset env 환경 변수 초기화!
# unset 환경변수

# # read
# echo "이름을 입력하세요: "
# read name
# read -s -p "비밀번호를 입력하세요: " passward
# echo "입력한 이름 : $name"
# echo "패스워드 : $passward "
# export name=$name
# ./envTest

# 화면 출력 echo , printf
echo -n "이어지는 " ;
echo "문장"
echo -e "엔터가 들어가는\n 문장" # escape 문자 작동 옵션
echo "엔터가 들어가는\n 문장"
printf "이름: %s, 나이: %d\n" "홍길동" 25

# 중요!! argument 받기 $1, $2 / 인자 갯수: $# 모든 인자 : $@ $*
echo "첫 번째 인자: $1"
echo "두 번째 인자: $2"
echo "인자들의 갯수: $#"
echo "모든 인자: $@"

# 제어문 if then fi(endif)
read -p "나이를 넣으시오: " age # age 앞에 스페이스 안하면 정상 작동 안함
if [ $age -lt 18 ]; then #대괄호 쓸 때 앞 뒤로 스페이스
    echo "성인이 아닙니다."
elif [ $age -gt 70 ]; then
    echo "노인입니다."
elif [ $age -gt 20 ] && [ $age -lt 30 ]; then
    echo "20대 입니다."
else
    echo "성인입니다."
fi

# 연산자
# 같다 == : eq
# 같지 않다 != : ne
# 크다 > : gt
# 작다 < : lt
# 크거나 같다 >= : ge (greater then and equal 의 약자)
# 작거나 같다 <= : le

# 연산자 - 문자 (문자 연산의 같다는 다르게 표현)
# 같다 == : = #! 헷갈리지 않게 기억!
# 같지 않다 != : !=
# 길이가 0 len(문자열) : z
# 길이가 0 이 아님 len(문자열) : n

# read -p "입력값을 넣으세요" input                     -----  정상 기능 안됨됨
# if[ -z "$input" ]; then
#     echo "입력값이 없습니다."
# else
#     echo "$input"
# fi 

# 논리연산 && || !

# switch - case -> case

read -p "과일 입력: " fruit
case $fruit in
    "사과" | "딸기") echo "빨간 과일" ;;
    "바나나") echo "노란 과일" ;;
    *) echo "알 수 없음" ;;
esac 

