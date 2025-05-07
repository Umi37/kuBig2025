# 섭씨 -> 화씨 변환 프로그램

def main():
    # 섭씨 온도 입력
    celsius = float(input("섭씨 온도를 입력하세요: "))

    # 화씨 온도로 변환
    fahrenheit = (celsius * 9/5) + 32

    # 결과 출력
    print(f"{celsius}도 섭씨는 {fahrenheit}도 화씨입니다.")

if __name__ == "__main__":
    main()