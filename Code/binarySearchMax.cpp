/*һ����Ϊ�����������飬ǰ��Ϊ���򣬺���Ϊ���������ֵ*/
#include<iostream>
#include<vector>

using namespace std;

//-----------------------------------ֱ�ӱ������ֵ---------------------------------
int searchMax(vector<int> v) {
    int n = v.size();
    int max = v[0] > v[n - 1] ? v[0] : v[n - 1];  // ��¼�����е�һ�������һ��ֵ�е����ֵ
    int maxV = 0;  // ��¼����������ֵ�е����ֵ
    for (int i = 1; i < n-1; i++) {   // �����������г���һ�������һ��ֵ�е����ֵ
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            maxV = v[i];
        }
    }
    return maxV > max ? maxV : max;
}


//-----------------------------------���ֲ������ֵ---------------------------------

int binarySearchMax(vector<int> v) {
    // ������Ԫ��С������
    int n = v.size();
    if (n <= 2) {
        return v[0] > v[n - 1] ? v[0] : v[n - 1];
    }

    // ������Ԫ�ش�������
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (mid == 0) {  // ��һ��ֵΪ���ֵ
            return v[0];
        }
        if (mid == n - 1) {
            return v[n - 1];  // ���һ��Ԫ��Ϊ���ֵ
        }
        if (v[mid] > v[mid - 1] && v[mid]>v[mid + 1]) {  // ��ǰֵΪ���ֵ
            return v[mid];
        }
        else if (v[mid] > v[mid - 1] && v[mid] < v[mid + 1]) {  // ���ֵ�ڵ�ǰֵ���ұ�
            left = mid + 1;
        }
        else if (v[mid] < v[mid - 1] && v[mid] > v[mid + 1]) {  // ���ֵ�ڵ�ǰֵ�����
            right = mid - 1;
        }
    }
}

//---------------------------------------����--------------------------------------

#if 1
int main() {
	vector<int> vec{1, 3, 6, 10, 16, 19, 17, 15, 13, 7, 5};
    //int max = searchMax(vec);
    int max = binarySearchMax(vec);
	cout << max << endl;
	return 0;
}
#endif