import os


def main():
    print("os.name: ", os.name)
    print("os.getcwd: ",os.getcwd()) # 워크스페이스의 폴더
    print("os.listdir: ", os.listdir())

    # os.mkdir("test_dir")
    # input()
    # os.rmdir("test_dir")

    # os.mkdir("test_dir")
    # os.chdir(os.getcwd() + "/test_dir")
    # print(os.getcwd())

    print(os.system("ls -al"))

if __name__ == "__main__":
    main()
