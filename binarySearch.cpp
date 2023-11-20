#include<iostream>
#include<vector>

using namespace std;

//---------------------------------------二分查找--------------------------------------

int binarySearch(vector<int> v, int key) {
	int n = v.size();
	int left = 0, right = n - 1;
	while (left <= right) {  // 此处取"="，如当数组中仅有一个元素时
		int mid = (right - left) / 2 + left;
		if (v[mid] == key) {
			return mid;
		}
		else if (v[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;  // 查找失败，返回-1
}

//---------------------------------------测试--------------------------------------

#if 1
int main() {
	vector<int> vec{ 7, 10, 13, 16, 19, 29, 32, 33 ,37, 41, 43};
	int key = 13;
	int index = binarySearch(vec, key);
	cout << index << endl;
	return 0;
}
#endif