def count_word_in_file():
    # 1. 파일 경로 입력
    file_path = input("읽을 파일의 절대경로를 입력하세요: ").strip()

    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            text = file.read()
    except FileNotFoundError:
        print("파일을 찾을 수 없습니다. 경로를 다시 확인해주세요.")
        return
    except Exception as e:
        print(f"파일을 여는 중 에러가 발생했습니다: {e}")
        return

    # 2. 찾고 싶은 단어 입력
    target_word = input("찾고 싶은 단어를 입력하세요: ").strip()

    # 3. 단어 수 카운트 (대소문자 구분 없이 처리)
    count = text.lower().count(target_word.lower())

    # 4. 결과 출력
    print(f"🔍 '{target_word}' 단어는 총 {count}번 등장합니다.")

def main():
    count_word_in_file()

if __name__ == "__main__":
    main()
