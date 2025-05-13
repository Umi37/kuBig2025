def main():
    print("안녕하세요")
    print("안녕하세요"[0])
    print("안녕하세요"[1])
    print("안녕하세요"[2])
    print("안녕하세요"[3])
    print("안녕하세요"[4])
    # print("안녕하세요"[5])
    # print("안녕하세요"[6])

    say_hello = "안녕하세요"
    print(say_hello[0], end='')
    print(say_hello[1], end='')
    print(say_hello[2], end='')
    print(say_hello[3], end='')
    print(say_hello[4])

    for c in say_hello:
        print(c, end=' ')
    print()

    say_hello *= 3

    print(say_hello)
    print("say_hello[5:10] : ", say_hello[5:10])
    print("say_hello[-3:] : ", say_hello[-3:])
    print("say_hello[5:10:2] : ", say_hello[5:10:2])    # satrt:end:step
    print("say_hello[-1::-1] : " ,say_hello[-1::-1])    # 역순으로 출력
    print("say_hello의 길이 : ", len(say_hello))        # len() 함수 호출하면 __len__() special method 호출
    print("say_hello의 길이 : ", say_hello.__len__())   # __len__() special method

if __name__ == "__main__":
    main()