# Divide And Conquer
문제를 더 작은 단위의 문제들로 분할 한 후에  
간단한 문제들의 결과를 합쳐서 최종 문제를 해결하는 방식의  
알고리즘을 의미한다.  

# 예시
- Merge Sort
- Quick Sort

# 코드예시

```
function F(x):
  if F(x)가 간단 then:
    return F(x)를 계산한 값
  else:
    x 를 x1, x2로 분할
    F(x1)과 F(x2)를 호출
    return F(x1), F(x2)로 F(x)를 구한 값
```
  