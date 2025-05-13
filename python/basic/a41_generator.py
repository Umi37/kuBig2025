# 제너레이터 함수 정의
def number_generator():
    print("제너레이터 시작됨")
    for i in range(1, 6):
        print(f"{i} 생성 중 (yield 직전)")
        yield i
        print(f"{i} 반환 후 (yield 다음 줄 실행)")

def main():
    gen = number_generator()  # 제너레이터 객체 생성

    print("제너레이터에서 하나씩 꺼내기:")
    for number in gen:
        print(f"메인에서 받은 값: {number}")

if __name__ == "__main__":
    main()



# def test():
#     print("test 함수가 호출되었습니다.")
#     yield "test"


# def main():
#     print("A")
#     test()  # return object 만들고 실행은 따로

#     print("B")
#     test()
#     print(test())

# if __name__ == "__main__":
#     main()