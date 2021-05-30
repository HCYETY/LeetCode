/*
�����ÿ�� ���� �б���������һ���б���Ӧλ�õ����Ϊ��Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ��������������������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
���磬����һ���б� temperatures = [73, 74, 75, 71, 69, 72, 76, 73]��������Ӧ���� [1, 1, 4, 2, 1, 1, 0, 0]��

��ʾ������ �б��ȵķ�Χ�� [1, 30000]��ÿ�����µ�ֵ�ľ�Ϊ���϶ȣ������� [30, 100] ��Χ�ڵ�������
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mystack;  // �����Ԫ��������������Ԫ��
        vector<int> ans(temperatures.size());
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            while(!mystack.empty() && temperatures[mystack.top()] <= temperatures[i]) {
                mystack.pop();
            }
            ans[i] = mystack.empty() ? 0 : (mystack.top()-i);   // �õ��������
            mystack.push(i);  // ����������������Ԫ��
        }
        return ans;
    }
};
