/*
����һ��ѭ�����飨���һ��Ԫ�ص���һ��Ԫ��������ĵ�һ��Ԫ�أ������ÿ��Ԫ�ص���һ������Ԫ�ء����� x ����һ�������Ԫ���ǰ��������˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ��������������һ�������������������ڣ������ -1��

ʾ�� 1:
����: [1,2,1]
���: [2,-1,2]
����: ��һ�� 1 ����һ����������� 2��
���� 2 �Ҳ�����һ�����������
�ڶ��� 1 ����һ����������Ҫѭ�����������Ҳ�� 2��
ע��: ��������ĳ��Ȳ��ᳬ�� 10000��
*/


//ģ������������Ч����һ����ͨ�� % �������ģ������������û�����Ч
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans(len);
        stack<int>mystack;
        // ��װ������鳤�ȷ�����
        for(int i = 2 * len - 1; i >= 0; i--) {
            while(!mystack.empty() && mystack.top() <= nums[i%len]) {
                mystack.pop();
            }
            ans[i%len] = mystack.empty() ? -1 : mystack.top();
            mystack.push(nums[i%len]);
        }
        return ans;
    }
};
