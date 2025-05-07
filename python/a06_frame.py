# 프레임이 자동으로 생성된다
import sys

frame = sys._getframe() # 모듈 전체의 루트 프레임
abc = int()
abc2 = list()

print("현재 프레임: ", frame)
print("코드 객체: ", frame.f_code)
print("로컬 변수: ", frame.f_locals)
print(frame.__dict__.items())
print(frame.__dict__[__name__])
# __file__ : 현재 파일의 경로
# __package__ : 현재 파일의 패키지
# __doc__ : 현재 파일의 docstring
# __spec__ : 현재 파일의 스펙
# ...
print(__dict__.items()) # 10 번 라인과 같은 결과
print("module_frame co name : ", frame.f_code.co_name) # 현재 프레임의 코드 객체의 이름

def main():
    a = 123
    b = [3, 4, 5]
    main_frame = sys._getframe()
    print("main_frame.f_code.co_name : ", main_frame.f_code.co_name) # 현재 프레임의 코드 객체의 이름
    print("main 프레임의 로컬 변수 : ", main_frame.f_locals)
    print("main 프레임의 전역 변수 : ", main_frame.f_globals)
if __name__ == "__main__":
    main()