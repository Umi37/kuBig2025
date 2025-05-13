# if elif else 사용해서 현재 시각 오전 오후 표시
# 계절을 표시 하는 프로그램
# datdtime 모듈을 사용해서 현재 시각을 구하고
# input()으로 받아서 나타나게(시간:월 두개를 받아서 파싱해서 처리하게) -> "now" -> now() 함수를 불러와서 표시. 

import datetime

def main():
    user_input = input("시간과 월을 입력하세요 (예: 14 5 또는 'now'): ")

    if user_input.strip().lower() == "now":
        now = datetime.datetime.now()
        hour = now.hour
        month = now.month

        # 또는 자연어 스타일
        print(f"오늘은 {now.year}년 {now.month}월 {now.day}일 {now.hour}시 {now.minute}분입니다.")
    else:
        hour_str, month_str = user_input.split()
        hour = int(hour_str)
        month = int(month_str)

    # ✅ 오전/오후 판별
    if hour < 12:
        print("오전입니다.")
    else:
        print("오후입니다.")

    # ✅ 계절 판별
    if month in [3, 4, 5]:
        print("지금은 봄입니다.")
    elif month in [6, 7, 8]:
        print("지금은 여름입니다.")
    elif month in [9, 10, 11]:
        print("지금은 가을입니다.")
    else:
        print("지금은 겨울입니다.")

if __name__ == "__main__":
    main()
