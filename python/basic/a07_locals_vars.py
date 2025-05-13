b = [1,2,3, 'four']

def main():
    a = 123
    print("local 변수: ", locals()) # 현재 프레임의 로컬 변수
    print("vars 변수(b): ", vars(main)) # 현재 프레임의 로컬 변수
    print("globals 변수: ", globals()) # 현재 프레임의 전역 변수

if __name__ == "__main__":
    main()