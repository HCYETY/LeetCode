/*
��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�

ʾ�� 1:
����: [3,2,1,5,6,4] �� k = 2
���: 5

ʾ�� 2:
����: [3,2,3,1,2,4,5,5,6] �� k = 4
���: 4

˵��:
����Լ��� k ������Ч�ģ��� 1 �� k �� ����ĳ��ȡ�
*/

// ����
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> myqueue;
        for(int i : nums) {
            myqueue.push(i);
        }
        for(int i = 1; i < k; i++) {
            myqueue.pop();
        }
        return myqueue.top();
    }
};
// ��С��
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> myqueue;
        for(int i = 0; i < k; i++) {
            myqueue.push(nums[i]);
        }
        for(int j = k; j < nums.size(); j++) {
            if(nums[j] > myqueue.top()) {
                myqueue.pop();
                myqueue.push(nums[j]);
            }
        }
        return myqueue.top();
    }
};
