def main():
    a = 'burgerking'
    b = 'BERGERKING'
    c = 'BurgerKing'
    print(a.upper()) # 대문자 변환 (원본 데이터를 변경하지 않음)
    print(a) 
    print(b.lower()) # 소문자 변환 (원본 데이터를 변경하지 않음)
    print(c.lower())
    c = "       burger       "
    print(c+"end")
    print(c.strip()+'end') # 양쪽 공백 제거
    print(c.lstrip() +'end')
    print(c.rstrip() +'end')

    d = "this is a python class in ict, our class is the best of IT classes"
    print(d.find("a"))
    print(d[d.find("a")])
    print(d.rfind("a"))

    idx = int()
    while d.find("a", idx) != -1:
        idx = d.find("a", idx)
        print(idx, end=' ')
        idx += 1

    f = "TrainA10".isalnum()
    print(f)

    f = "Train_A10".isalnum()
    print(f)

    f = "10a".isdecimal()
    print(f)

    f = "10ff".isspace()
    print(f)

    g = d.split()
    print(g)

    print("안녕" in "안녕하세요")
    print("요요" in "안녕하세요")
        
if __name__ == "__main__":
    main()