/*
������������ arr ���ҳ�������С�� k ������
���磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��

ʾ�� 1��
���룺arr = [3,2,1], k = 2
�����[1,2] ���� [2,1]

ʾ�� 2��
���룺arr = [0,1,2,1], k = 1
�����[0]

���ƣ�
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/


// ֱ���ž�������
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = arr[i];
        }
        return res;
    }
};
// ��������ǰ k ��
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) { // �ų� 0 �����
            return res;
        }
        priority_queue<int> myquque;
        for(int i = 0; i < k; i++) {
            myquque.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++) {
            if(myquque.top() > arr[i]) {
                myquque.pop();
                myquque.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++) {
            res[i] = myquque.top();
            myquque.pop();
        }
        return res;
    }
};
