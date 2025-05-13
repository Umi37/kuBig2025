import math # 모듈명 명시 해야함
# from math import * # 귀찮으면 이렇게 함
# pip install numpy
# sudo python3 -m pip install numpy

from math import pi, tau, e, sin # 단위로 쓸 수 있음

def main():
    # pi = 10
    print(pi, e, tau)
    print(math.sin(30/180 * pi)) # sin 30도 -> 라디안 (거의 대부분 프로그램이 degree 기준이 아니라 라디안 기준)


if __name__ == "__main__":
    main()