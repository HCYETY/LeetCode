/*
���������������飬�뽻��һ����ֵ��ÿ��������ȡһ����ֵ����ʹ��������������Ԫ�صĺ���ȡ�
����һ�����飬��һ��Ԫ���ǵ�һ��������Ҫ������Ԫ�أ��ڶ���Ԫ���ǵڶ���������Ҫ������Ԫ�ء����ж���𰸣���������һ�����ɡ�����������������ֵ�����ؿ����顣

����: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
���: [1, 3]

����: array1 = [1, 2, 3], array2 = [4, 5, 6]
���: []

��ʾ��
1 <= array1.length, array2.length <= 100000
*/


class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        set <int> s;
        int sum1=0, sum2=0;
        for(int i=0; i<array1.size(); i++) {
            sum1 += array1[i];
        }
        for(int i=0; i<array2.size(); i++) {
            sum2 += array2[i];
            s.insert(array2[i]);
        }
        if(abs(sum1-sum2) % 2 == 1)  //absȡ����ֵ
            return {};  //����ֱ�ӷ��ؿ�����
        int avg = abs(sum1 - sum2) / 2;
        for(int i=0; i<array1.size(); i++) {
            // for(j=0; j<array2.size(); j++) {
            //     if(array2[j] + array1[i] == flag )
            //         break;
            if(s.find(array1[i]+avg)!=s.end())      //�ҵ��˾ͷ���������������
                return {array1[i],array1[i]+avg}; //������array[i]+n����array2����Ҫ�����������룡
        }
        return {};  //û�ҵ����ؿ�����
    }
};
