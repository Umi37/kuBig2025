def main():
    dict_a = dict()
    list_a = ["사라질까??", "음..."]
    dict_b = {1: 1, 2: 2, 3: list_a} # 정의 할 때 set 과 헷갈리지 않게 주의
    # dect_b = {1, 2, 3} -> set class
    print(type(dict_a), type(dict_b))

    a = "d"
    dict_c = {"a": 100, "b": 200, "c": 300, a: 400}
    # for i in dict_c:
    #     print(i , dict_c[i], end = " ")
    # print()

    for k, v in dict_c.items():
        print(k, v, end= ", ")
    print()

    dict_b.update(dict_c) # 메소드에서 내부 데이터가 변하는 상황
    print(dict_b)
   
    del dict_b[3]
    print(dict_b)
    print(list_a) # 아직 살아있음

    del list_a
    # print(list_a) # 사라짐

    print("dict_b : ", dict_b)
    print(dict_b.pop(2)) # 제거와 동시에 쓰일 때!
    print("dict_b : ", dict_b)

if __name__ == "__main__":
    main()