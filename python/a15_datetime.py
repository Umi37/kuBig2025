import datetime
import test_package

class Myclass:
    def __str__(self):
        return "test My class"


# 1. PATH나 PYTHONPATH 환경 변수에 등록된 경로에 있는 .py 파일을 import할 수 있다. PATH PYTHONPATH 에 있는 ~.py  파일들 대상 불러온다.
# 2. __init__.py 파일이 있는 디렉토리는 패키지로 간주되어 import할 수 있다.
# 3. .so 파일(리눅스의 공유 라이브러리)은 동적으로 로드 가능한 모듈로 인식되며, CPython용 C 확장 모듈처럼 import할 수 있다. -> GIL 우회
#    .so 파일을 임포트(dynamic loading)하면, 해당 모듈이 메모리에 로드되고, 그 모듈의 모든 함수와 변수를 사용할 수 있다.
#    .so 파일은 C로 작성된 확장 모듈로, Python과 C 간의 상호작용을 가능하게 한다.
#    .so 파일을 임포트(dynamic loading) <- C모듈 만들기(Cpython) -> GIL 우회
#    .(pyi(stub)) .so) --> github. -> 실행속도가 빠르다. || 병렬처리
#    GIL global Interpreter lock -> PVM

def main():
    ptime = datetime.datetime.now() # 현재 날짜와 시간
    print(ptime) # __str__ 오버로딩이 되어 나타난다.

    myclass = Myclass()
    print(myclass)

    print(ptime.month)
    print(f"{ptime.year}년 {ptime.month}월 {ptime.day}일")
    
if __name__ == "__main__":
    main()

