import enum

def main():
    print(a:=range(10)) # := 코끼리문. 대입과 동시에 값을 사용
    print(a.count(2))   # 0 부터 9 까지의 숫자 중 2 가 몇개 있는지
    print(a.step)       # step이란 range() 에서 몇개씩 건너뛰는지 
    print(a.index(1))   # 0 부터 9 까지의 숫자 중 1 의 위치는 몇번째 인지
    print(list(a))

    for i in range(10):
        print(f"{i+1} 번째 출력입니다.")

    list_a = ["song", 123, 3.3]
    
    for i, ele in enumerate(list_a):
        print(f"{i}번째 원소의 값은 {ele} 입니다.")

    num = [0, 1, 2]

    for ele, i in zip(list_a, num):
        print(f"{i}번째 원소의 값은 {ele} 입니다.")
        
if __name__ == "__main__":
    main()