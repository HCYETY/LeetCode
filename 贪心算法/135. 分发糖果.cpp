��ʦ��������Ƿַ��ǹ����� N?������վ����һ��ֱ�ߣ���ʦ�����ÿ�����ӵı��֣�Ԥ�ȸ��������֡�

����Ҫ��������Ҫ�󣬰�����ʦ����Щ���ӷַ��ǹ���

ÿ���������ٷ��䵽 1 ���ǹ���
���ָ��ߵĺ��ӱ�������������λ���ӻ�ø�����ǹ���
��ô������������ʦ������Ҫ׼�����ٿ��ǹ��أ�

���룺[1,0,2]
�����5
���ͣ�����Էֱ�����������ӷַ� 2��1��2 ���ǹ���

���룺[1,2,2]
�����4
���ͣ�����Էֱ�����������ӷַ� 1��2��1 ���ǹ���
     ����������ֻ�õ� 1 ���ǹ�������������������������


class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size<2) {
            return size;
        }
        vector<int> num(size,1);
        for(int i=1; i<size; i++) {
            if(ratings[i] > ratings[i-1]) {
                num[i] = num[i-1] + 1;
            }
        }
        for(int i=size-1; i>0; i--) {
            if(ratings[i]<ratings[i-1]) {
                num[i-1] = max(num[i-1], num[i]+1);
            }
        }
        return accumulate(num.begin(), num.end(), 0);
    }
};
