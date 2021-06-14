/*
��һ��ʯͷ��ÿ��ʯͷ������������������ÿһ�غϣ�����ѡ������ ���ص� ʯͷ��Ȼ������һ����顣
����ʯͷ�������ֱ�Ϊ x �� y���� x <= y��
��ô����Ŀ��ܽ�����£�
��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y-x��
������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ�����������û��ʯͷʣ�£��ͷ��� 0��

ʾ����
���룺[2,7,4,1,8,1]
�����1
���ͣ�
��ѡ�� 7 �� 8���õ� 1����������ת��Ϊ [2,4,1,1,1]��
��ѡ�� 2 �� 4���õ� 2����������ת��Ϊ [2,1,1,1]��
������ 2 �� 1���õ� 1����������ת��Ϊ [1,1,1]��
���ѡ�� 1 �� 1���õ� 0����������ת��Ϊ [1]����������ʣ���ǿ�ʯͷ��������

��ʾ��
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> myquque;
        for(int i : stones)
            myquque.push(i);
        while(myquque.size() > 1) {
            int a = myquque.top();
            myquque.pop();
            int b = myquque.top();
            myquque.pop();
            if(a > b) {
                myquque.push(a - b);
            }
        }
        return myquque.empty() ? 0 : myquque.top();
    }
};
