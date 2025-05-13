def main():
    pi = 3.141592

    # type casting
    int_pi = int(pi)
    print(type(int_pi), int_pi)  # <class 'int'>
    str_pi = str(pi)
    print(type(str_pi), str_pi)
    # pi = 'three'
    # int_pi = int(pi)  # ValueError: invalid literal for int() with base 10: 'three'

    print("pi + 2 = ", pi + 2)  # 5.141592
    print("pi - 2 = ", pi - 2)  # 1.141592
    print("pi * 2 = ", pi * 2)  # 6.283184
    print("pi / 2 = ", pi / 2)  # 1.570796
    print("pi // 2 = ", pi // 2)  # 1.0
    print("pi % 2 = ", pi % 2)  # 1.141592
    print("pi ** 2 = ", pi ** 2)  # 9.869604401089358


if __name__ == "__main__":
    main()