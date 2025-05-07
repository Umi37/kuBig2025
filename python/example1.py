# 구구단 출력 프로그램

def main():
    # 2단부터 9단까지 출력
    for i in range(2, 10):
        print()
        print(f"{i}단")
        for j in range(1, 10):
            print(f"{i} x {j} = {i * j}")

if __name__ == "__main__":
    main()