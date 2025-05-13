def main():
    print(1234567)  # C에서는 \n을 사용하여 줄바꿈, python에서는 \n을 사용하지 않고 줄바꿈, 원소를 두개 넣었을 때 디폴트로 띄어쓰기
    print(1_234_567)    # 1'234'567
    print("Song Woo rim")
    print(3.141592)

    print("this is", "python", "class!")
    print(10, 20, 30, "hi", "hello", "world")
    print() # 줄바꿈

    print("this is", "python", "class!", sep="*", end="")
    print("this is", "python", "class!", sep="-")

if __name__ == "__main__":
    main()