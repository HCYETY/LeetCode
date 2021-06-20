/*
ʵ�� strStr() ������
���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�ã��±�� 0 ��ʼ������������ڣ��򷵻�  -1 ��

˵����
�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣
���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ��
���� C ���Ե� strstr() �Լ� Java �� indexOf() ���������

ʾ�� 1��
���룺haystack = "hello", needle = "ll"
�����2

ʾ�� 2��
���룺haystack = "aaaaa", needle = "bba"
�����-1

ʾ�� 3��
���룺haystack = "", needle = ""
�����0

ʾ�� 4��
���룺haystack = "mississippi", needle = "issip"
�����4

��ʾ��
0 <= haystack.length, needle.length <= 5 * 104
haystack �� needle ����СдӢ���ַ����
*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int ha = 0, ne = 0;
        int len_en = needle.size(), len_ha = haystack.size();
        if(len_en == 0) return 0;
        while(ne < len_en && ha < len_ha) {
            if(needle[ne] == haystack[ha]) {
                ne++;
                ha++;
            } else {
                ha = ha - ne + 1;
                ne = 0;
            }
        }
        if(ne == len_en) return ha - ne;
        else return -1;
    }
};
