/*
δ֪ �������� arr �� n ���Ǹ�������ɡ�
��������Ϊ����Ϊ n - 1 ����һ���������� encoded ������ encoded[i] = arr[i] XOR arr[i + 1] ��
���磬arr = [1,0,2,1] �������õ� encoded = [1,2,3] ��

������������� encoded ��ԭ���� arr �ĵ�һ��Ԫ�� first��arr[0]����
����뷵��ԭ���� arr ������֤���𰸴��ڲ�����Ψһ�ġ�

ʾ�� 1��
���룺encoded = [1,2,3], first = 1
�����[1,0,2,1]
���ͣ��� arr = [1,0,2,1] ����ô first = 1 �� encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]

ʾ�� 2��
���룺encoded = [6,2,7,3], first = 4
�����[4,2,0,7,4]

��ʾ��
2 <= n <= 104
encoded.length == n - 1
0 <= encoded[i] <= 105
0 <= first <= 105
*/


class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> arr(n);
        arr[0] = first;
        for(int i = 1; i < n; i++) {
         	// �������Ľ�����;
            arr[i] = arr[i-1] ^ encoded[i-1];
        }
        return arr;
    }
};
