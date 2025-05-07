import keyword

def main():
    print(keyword.kwlist)

# 이 파일이 실행이 될 때만 main() 함수가 실행되도록 하는 코드!
# import 하면 main() 함수가 실행되지 않도록 하는 코드!
if __name__ == "__main__":
    main()

