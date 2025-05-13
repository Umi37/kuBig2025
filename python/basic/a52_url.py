# # 웹 스크래핑 -> beatifulsoup
# from urllib import request

# def main():
#     target = request.urlopen("https://namu.wiki/w/Python")
#     print(target.read())


# if __name__ == "__main__":
#     main()


from urllib import request

def main():
    url = "https://namu.wiki/w/Python"
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
                      "(KHTML, like Gecko) Chrome/112.0.0.0 Safari/537.36"
    }

    req = request.Request(url, headers=headers)
    response = request.urlopen(req)
    content = response.read()

    print(content.decode("utf-8"))  # 바이트 -> 문자열

if __name__ == "__main__":
    main()
