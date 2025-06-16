# 🏠 House Price Prediction

이 프로젝트는 Ames Housing 데이터를 기반으로, 다양한 머신러닝 모델을 활용하여 주택 가격을 예측하는 것을 목표로 합니다.  
수치형/범주형 데이터를 정교하게 분류하고, 트리 기반 모델과 선형 회귀 기반 모델에 맞는 전처리 전략을 각각 설계하여 비교 실험을 수행합니다.

---

## 🧭 Workflow Overview

1. 컬럼 탐색 및 구조 분석
2. 결측치 탐색 및 처리 전략 수립
3. 수치형/범주형/순서형 변수 분류
4. 인코딩 전략 설계 및 분기 처리 (A/B 파일 생성)
5. 정규화 적용 (선형 회귀용 데이터에만)
6. 히트맵을 통한 SalePrice와 변수 간 상관 분석
7. 모델별 실험 (트리 기반 vs 선형 회귀 기반)
8. 모델 성능 비교 및 주요 변수 중요도 시각화

---

## 📁 Project Structure

```
house-price-prediction/
├── data/
│   ├── raw/                 # 원본 데이터 (train.csv, test.csv 등)
│   ├── processed/           # 전처리 완료된 A/B 버전 데이터
│   └── description/         # 컬럼 설명, md 파일 등
│
├── eda/
│   ├── 01_column_analysis.ipynb       # 컬럼 탐색 및 분류
│   ├── 02_missing_values.ipynb        # 결측치 탐색 및 처리전략 수립
│   ├── 03_encoding_strategy.ipynb     # 범주형 인코딩 전략 수립
│   ├── 04_heatmap_analysis.ipynb      # 히트맵 등 시각화 분석
│   └── eda_utils.py                   # EDA 보조 함수 (그래프, 로딩 등)
│
├── preprocessing/
│   ├── process_for_tree.py            # A 파일 생성: 순서형 인코딩
│   ├── process_for_linear.py          # B 파일 생성: 원핫 인코딩 + 정규화
│   └── preprocessing_utils.py         # 인코딩, 정규화 함수 등 공통 모듈
│
├── models/
│   ├── train_tree_models.ipynb        # RandomForest, XGBoost 등 트리 기반 모델 실험
│   ├── train_linear_models.ipynb      # 선형회귀, 라쏘, 릿지 등 실험
│   └── model_utils.py                 # 공통 학습 함수, 평가 함수 등
│
├── results/
│   ├── model_comparison.csv           # 모델별 성능 비교
│   └── feature_importance/            # 중요 변수 시각화 저장
│
├── reports/
│   ├── findings.md                    # 주요 인사이트 요약
│   └── workflow.md                    # 설계 문서, 실험 과정 기록
│
├── requirements.txt
└── README.md
```

---

## 📦 Requirements

```bash
pip install -r requirements.txt
```

필요한 주요 라이브러리:
- pandas
- numpy
- matplotlib
- seaborn
- scikit-learn
- xgboost

---

## 🧪 모델 성능 평가 지표

- RMSE (Root Mean Squared Error)
- MAE (Mean Absolute Error)
- R² Score (선택적)

---

## ✍️ Author

- Umi37 
- Designed & built with structured experimentation mindset.

---

## 📌 참고

이 프로젝트는 캐글의 [House Prices - Advanced Regression Techniques](https://www.kaggle.com/competitions/house-prices-advanced-regression-techniques) 데이터를 기반으로 제작되었습니다.
