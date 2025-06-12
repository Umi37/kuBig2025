import pandas as pd

# 1. 원본 test.csv 로드 (Orange에서 썼던 test.csv 위치로 조정 필요)
test_df = pd.read_csv("/home/woo/kuBig2025/orange33/house-prices-advanced-regression-techniques/test.csv")  # ← 여기에 정확한 경로 지정

# 2. Orange에서 예측한 결과 로드
pred_df = pd.read_csv("/home/woo/kuBig2025/orange33/house-prices-advanced-regression-techniques/final_submission_clean.csv", skiprows=2)
pred_df = pred_df.loc[:, ~pred_df.columns.str.contains("Unnamed")]
pred_df.columns = ["Id", "SalePrice"]

# 3. test.csv의 Id 기준으로 정렬 및 병합 보정
final_df = test_df[["Id"]].merge(pred_df, on="Id", how="left")

# 4. 누락된 SalePrice 채우기 확인
print(final_df.isnull().sum())

# 5. 저장
final_df.to_csv("/home/woo/kuBig2025/orange33/house-prices-advanced-regression-techniques/final_submission_correct.csv", index=False)
