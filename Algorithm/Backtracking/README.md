# Binary Search
정렬된 배열을 $O(logn)$의 시간복잡도로 탐색하는 알고리즘  
시간적으로 엄청 이점이 큰 알고리즘이다.  
시간초과가 난다면 이진탐색을 쓰는게 아닐까? 생각해도 될 정도로  
중요하다.  

# c++코드
```cpp
￼int bSearch(T arr[], T val, int first, int last)
{
    if (first > last) return -1;

    int mid = (first + last) / 2;
    if (val == arr[mid])
        return mid;
    else if (val < arr[mid])
        return bSearch(arr, val, first, mid - 1);
    else
        return bSearch(arr, val, mid + 1, last);
}
```

# STL
```cpp
#include <algorithm>
#include <vector>
vector<int> v = {1,3,2,5,4};
sort(v.begin(),v.end());
binary_search(v.begin(), v.end(), 3);
```

  