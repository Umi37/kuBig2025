# 웹 프레임워크!! back-end
# flask run -> 웹 공부를 하고 싶으면 검색
# jdango flask fastapi
# gradio(머신 러닝.. openUI stable difusion)
# streamlit (대시보드 깔끔하게 되어있다)
# Dash (데이터 시각화)
 
from flask import Flask

app = Flask(__name__)


@app.route('/')
def hello():
    return "<he>Hello World! I'm python Flask!!</h1>"

