/*
�����ַ���J ����ʯͷ�б�ʯ�����ͣ����ַ��� S������ӵ�е�ʯͷ��
S ��ÿ���ַ�������һ����ӵ�е�ʯͷ�����ͣ�����֪����ӵ�е�ʯͷ���ж����Ǳ�ʯ��
J �е���ĸ���ظ���J �� S�е������ַ�������ĸ����ĸ���ִ�Сд�����"a"��"A"�ǲ�ͬ���͵�ʯͷ��

ʾ�� 1:
����: J = "aA", S = "aAAbbbb"
���: 3

ʾ�� 2:
����: J = "z", S = "ZZ"
���: 0

ע��:
 S �� J ��ຬ��50����ĸ��
 J �е��ַ����ظ���
*/


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_set<char> jewelsSet;
        for (int i = 0; i < jewels.length(); i++) {
            jewelsSet.insert(jewels[i]);
        }
        for (int i = 0; i < stones.length(); i++) {
            if (jewelsSet.count(stones[i])) {
                count++;
            }
        }
        return count;
    }
};
