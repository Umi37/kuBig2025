class DataArgument:
    def __init__(self):
        self.a = 10


def return_func(a):
    print("함수 실행중...")
    if isinstance(a, list):
        a[0] += 1
    elif isinstance(a, DataArgument):
        a.a += 1
    else :
        a = a + 1 # code 안에서 a 값 변경
    b = 3.14
    c = "Song Woorim"
    return a, b, c


def main():
    a = 10
    re = return_func(a) 
    print(re)
    print("maind의 a: {a}")
    a, *b = return_func(a) # * means 'packing' & 'unpacking'
    print(type(a), type(b))
    print(a, b)
    
    # 변수를 함수의 인자로 레퍼런스 처럼 넘기고 싶을 때
    a = [10] 
    re = return_func(a) # 값의 복사가 기본이지만, deep copy가 되지는 않는다. 
    print(re)
    print(a) # main 의 local 변수이지만 변한 상황

    # class 의 내부 변수는 변화하는가?
    data = DataArgument()
    print(data.a)
    re = return_func(data) # 값의 복사가 일어나는데, deep은 아니어서 주소가 넘어간다.
    print(re, re[0].a) # type : ignore
    print(data.a) # 10, 11



if __name__ == "__main__":
    main()