/*一个都为正整数的数组，前面为升序，后面为降序，求最大值*/
#include<iostream>
#include<vector>

using namespace std;

//-----------------------------------直接遍历value的索引---------------------------------
int searchLastIndex(vector<int> v, int value) {
    int n = v.size();
    int lastIndex = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == value) {
            lastIndex = i;
        }
    }
    return lastIndex;
}


//-----------------------------------二分查找value的索引---------------------------------

int binarySearchLastIndex(vector<int> v, int value) {
    // 数组中元素小于两个
    int n = v.size(), lastIndex = -1;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == value) {
            lastIndex = mid;
            left = mid + 1;
        }
        else if (v[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return lastIndex;
}

//---------------------------------------测试--------------------------------------

#if 1
int main() {
    vector<int> vec{ 1, 1, 2, 3, 3, 3, 4, 5 };
    int value = 3;
    //int lastIndex = searchLastIndex(vec, value);
    int lastIndex = binarySearchLastIndex(vec, value);
    cout << lastIndex << endl;
    return 0;
}
#endif