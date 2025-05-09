def main():
    dict_a = dict()
    dict_b = {1: 1, 2: 2, 3: 2} # 정의 할 때 set 과 헷갈리지 않게 주의
    # dect_b = {1, 2, 3} -> set class
    print(type(dict_a), type(dict_b))

    a = "d"
    dict_c = {"a": 100, "b": 200, "c": 300, a: 400} 
    # dict_c = {"a": 100, "b": 200, "c": 300, a: 400} # name 에러
    print(dict_c["a"])
    dict_c["d"]  = 500 # 데이터가 덮어 씌워진다.
    print(dict_c["d"])
    dict_c["e"] = 600 # 데이터가 추가된다.
    print(dict_c)
    # print(dict_c["f"]) # KeyError: 'f'
    print(dict_c.get("f")) # Key를 새로 생성하는 것이 아닌, 안전한 접근을 하는 방법
    # print(dict_c["f"]) # 위에 코드 실행하고 해도 KeyError 는 발생된다.

if __name__ == "__main__":
    main()