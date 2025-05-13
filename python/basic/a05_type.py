def main():
    abc = str() # str class 클래스로 객체 선언! 정식
    abc2 = "hi" # str class 파이썬의 약식
    print(type(abc))
    print(type(abc2)) # 파이썬에서 빌트인 class 에 대해서는 소문자로 시작
    abc = 4
    print(type(abc))
    abc = 3.14
    print(type(abc)) # float class
    abc = [1,2, "three"] # list class (STL 벡터와 유사, 훨씬 유연함, 벡터는 템플릿이라 타입 지정해야하지만 리스트는 아무거나 넣어도 됨)

    print(type(abc)) 


if __name__ == "__main__":
    main()