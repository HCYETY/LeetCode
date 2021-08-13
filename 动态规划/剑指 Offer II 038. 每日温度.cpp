/*
�����ÿ�� ���� �б� temperatures ����������һ���б�Ҫ�����Ӧλ�õ����Ϊ��Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ���������
�����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档

ʾ�� 1:
����: temperatures = [73,74,75,71,69,72,76,73]
���: [1,1,4,2,1,1,0,0]

ʾ�� 2:
����: temperatures = [30,40,50,60]
���: [1,1,1,0]

ʾ�� 3:
����: temperatures = [30,60,90]
���: [1,1,0]

��ʾ��
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector <int> res(len, 0);
        stack <int> stk;
		  // ������Ҫ�������ĩλ�ÿ�ʼ�������Ա�ջ��ά��
        for (int i = len - 1; i >= 0; i --) {
	        	// ά��һ�����µĸ����µĵ���ջ
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()])
                stk.pop();
				// �õ� ����������Ԫ���뵱ǰԪ�صľ���
            if (!stk.empty())
                res[i] = stk.top() - i;
				// ʼ�ս�Ԫ���±�ѹ��ջ
            stk.push(i);
        }
        return res;
    }
};
