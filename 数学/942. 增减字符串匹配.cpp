/*
����ֻ�� "I"�����󣩻� "D"����С�����ַ��� S ���� N = S.length��
���� [0, 1, ..., N] ���������� A ʹ�ö������� i = 0, ..., N-1�����У�

��� S[i] == "I"����ô A[i] < A[i+1]
��� S[i] == "D"����ô A[i] > A[i+1]

ʾ�� 1��
���룺"IDID"
�����[0,4,1,3,2]

ʾ�� 2��
���룺"III"
�����[0,1,2,3]

ʾ�� 3��
���룺"DDI"
�����[3,2,0,1]

��ʾ��
1 <= S.length <= 10000
S ֻ�����ַ� "I" �� "D"��
*/

/*˼·��
������I��ʱ���Ͱ�deque�����е���Сֵѹ��ans���飬Ȼ���Ƴ���Сֵ������һ���϶����Ա�֤A[i] < A[i+1]
������D��ʱ���Ͱ�deque�����е����ֵѹ��ans���飬Ȼ���Ƴ����ֵ������һ���϶����Ա�֤A[i] > A[i+1]
����ÿ�α���s�ַ�������������ó�������ʣ���������ֵ����Сֵ��
ע�⣺ÿ���õ����ֵ����Сֵ��Ҫ�ǵý���ֵ�Ƴ������´α���ʱ�ſ����õ�ʣ���������/Сֵ��
*/
class Solution {
public:
    vector<int> diStringMatch(string s) {
        deque<int> myqueue;
        vector<int> ans;
        for(int i = 0; i <= s.size(); i++) {
            myqueue.push_back(i);
        }
        for(int ch : s) {
            if(ch == 'I') {
                ans.push_back(myqueue.front());
                myqueue.pop_front();
            } else if(ch == 'D') {
                ans.push_back(myqueue.back());
                myqueue.pop_back();
            }
        }
        if(!myqueue.empty()){
            ans.push_back(myqueue.front());
            myqueue.pop_back();
        }
        return ans;
    }
};
