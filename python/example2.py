# 섭씨 -> 화씨 변환 프로그램

def main():
    while True:
        # 섭씨 온도 입력
        celsius = input("섭씨 온도를 입력하세요: ")
        # 입력값이 숫자인지 확인
        try: 
            celsius = float(celsius)
            break # 성공적으로 변환되면 반복 종료
        except ValueError:
            print("유효하지 않은 입력입니다. 숫자를 입력하세요.: ")

    # 화씨 온도로 변환
    fahrenheit = (celsius * 9/5) + 32

    # 결과 출력
    print(f"{celsius}도 섭씨는 {fahrenheit}도 화씨입니다.")

if __name__ == "__main__":
    main()