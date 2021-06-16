/*
���һ���㷨���ҳ���������С��k������������˳�򷵻���k�������ɡ�

ʾ����
���룺 arr = [1,3,5,7,2,4,6,8], k = 4
����� [1,2,3,4]

��ʾ��
0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))
*/


class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) { // �ų� 0 �����
            return res;
        }
        priority_queue<int> myqueue;
        for(int i = 0; i < k; i++) {
            myqueue.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++) {
            if(arr[i] < myqueue.top()) {
                myqueue.pop();
                myqueue.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++) {
            res[i] = myqueue.top();
            myqueue.pop();
        }
        return res;
    }
};
