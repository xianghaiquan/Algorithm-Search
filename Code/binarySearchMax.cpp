/*一个都为正整数的数组，前面为升序，后面为降序，求最大值*/
#include<iostream>
#include<vector>

using namespace std;

//-----------------------------------直接遍历最大值---------------------------------
int searchMax(vector<int> v) {
    int n = v.size();
    int max = v[0] > v[n - 1] ? v[0] : v[n - 1];  // 记录数组中第一个与最后一个值中的最大值
    int maxV = 0;  // 记录数组中其他值中的最大值
    for (int i = 1; i < n-1; i++) {   // 遍历除数组中除第一个与最后一个值中的最大值
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            maxV = v[i];
        }
    }
    return maxV > max ? maxV : max;
}


//-----------------------------------二分查找最大值---------------------------------

int binarySearchMax(vector<int> v) {
    // 数组中元素小于两个
    int n = v.size();
    if (n <= 2) {
        return v[0] > v[n - 1] ? v[0] : v[n - 1];
    }

    // 数组中元素大于两个
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (mid == 0) {  // 第一个值为最大值
            return v[0];
        }
        if (mid == n - 1) {
            return v[n - 1];  // 最后一个元素为最大值
        }
        if (v[mid] > v[mid - 1] && v[mid]>v[mid + 1]) {  // 当前值为最大值
            return v[mid];
        }
        else if (v[mid] > v[mid - 1] && v[mid] < v[mid + 1]) {  // 最大值在当前值的右边
            left = mid + 1;
        }
        else if (v[mid] < v[mid - 1] && v[mid] > v[mid + 1]) {  // 最大值在当前值的左边
            right = mid - 1;
        }
    }
}

//---------------------------------------测试--------------------------------------

#if 1
int main() {
	vector<int> vec{1, 3, 6, 10, 16, 19, 17, 15, 13, 7, 5};
    //int max = searchMax(vec);
    int max = binarySearchMax(vec);
	cout << max << endl;
	return 0;
}
#endif