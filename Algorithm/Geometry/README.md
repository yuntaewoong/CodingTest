# Geometry
기하학 문제. 도형들의 정보가 주어지고 어떤 정보를 출력하라는 문제들.  
그래픽스랑 연관성이 깊음(사이각이라던가 CW,CCW라던가)

## 내적  
두 벡터의 스칼라곱  
두 직선의 사이각을 알아낼때 사용  
stl에서의 내적  
```cpp
std::vector<int> a{0, 1, 2};
std::vector<int> b{5, 4, 2};
int dotProduct = std::inner_product(a.begin(), a.end(), b.begin(), 0);
```

## 외적
두 벡터의 벡터곱  
두 직선의 위치관계(CW,CCW), 두 직선과 수직한 벡터를 구할때 사용  
c++표준에 2개 벡터의 외적을 구하는 함수는 정의되어있지 않다.  

이유는 아마 내적과 달리 외적은 벡터의 원소가 늘어날때마다  
구현이 달라져서가 아닐까?(사실 잘모름)  

cpp구현
```cpp
void crossProduct(int vect_A[], int vect_B[], int cross_P[]) 
{
    cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1];
    cross_P[1] = vect_A[2] * vect_B[0] - vect_A[0] * vect_B[2];
    cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0];
}
```
 


  