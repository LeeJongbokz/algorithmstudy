# Banksalad.py

- 주어진 요구사항을 만족하기 위한 함수들을 구현한 파일입니다. 


(1) calculate
- stock_symbol의 입력에 따라 buy_date와 sell_date를 반환하는 함수입니다. 
  내부에 3개의 함수(get_paneldata, get_lowandhighprices, get_buyandselldate)를 갖고 있습니다. 
  
(2) get_paneldata
- API Layer의 함수이며, stock_symbol에 따른 API 데이터를 반환합니다. 
  이 때, 'The third-party data source should be easily interchangeable'라는 조건에 따라 
  data.Datareader 함수를 사용하면서 data source를 쉽게 바꿀 수 있게 하였습니다. 
  
 
(3) get_lowandhighprices
- Data Layer의 함수이며, API 데이터와 지정된 날짜 범위(최근 180일) 내에서
  low_prices(최소 가격 리스트), high_prices(최대 가격 리스트), avaiable_dates(주식이 개장한 날)을 각각 반환합니다. 

(4) get_buyandselldate
- Business Layer의 함수이며, 최소 가격과 최대 가격을 기준으로 
  그 차이가 제일 클 때의 buy_date(주식 구입 날짜)와 sell_date(주식 판매 날짜)를 반환합니다.  
   
   
   
# test_banksalad.py

- Banksalad.py에 구현한 함수들을 테스트하기 위한 테스트 코드를 구현한 파일입니다. 


(1) test_get_paneldata
- pandas._testing 프레임워크를 사용해, panel_data가 올바르게 반환되는지 테스트하였습니다. 

(2) test_get_lowandhighprices
- unittest 프레임워크를 사용해, low_prices(최소 가격 리스트), high_prices(최대 가격 리스트), available_dates(주식이 개장한 날 리스트)
  가 올바르게 반환되는지 테스트하였습니다.
  
(3) test_get_buyandselldate
- unittest 프레임워크를 사용해, buy_date(구입 날짜)와 sell_date(판매 날짜)가 올바르게 반환되는지 테스트하였습니다. 
  이 때, 특히 'profit calculation is thoroughly tested' 라는 조건에 따라 
  stock_symbol이 MSFT, GOOG, AAPL, NVDA, TSLA일 때 올바른 값을 반환하는지 테스트하였습니다. 
  
(4) test_calculate
- unittest 프레임워크를 사용해, buy_date(구입 날짜)와 sell_date(판매 날짜)가 올바르게 반환되는지 테스트하였습니다. 


  
  
  
