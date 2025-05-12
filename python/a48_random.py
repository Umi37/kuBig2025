import random

def main():
    for _ in range(10):
        print("random() : ", random.random()) # 0~1 사이 float # 균등
    print("uniform(10,20) : ", random.uniform(10, 20)) # 정규분포
    print("randint() : ", random.randint(4, 15)) # 균등
    print("range(200) : ", random.randrange(200))
    print("choice : ", random.choice([1,2,3,4,5])) # type : ignore
    print("choices : ", random.choices([1,2,3,4,5], k = 5)) # 중복 가능
    li = [1,2,3,4,5]
    random.shuffle(li)
    print("shuffle : ", li)
    print("sample : ", random.sample([1,2,3,4,5], k=5)) # 중복 안됨
if __name__ == "__main__":
    main()