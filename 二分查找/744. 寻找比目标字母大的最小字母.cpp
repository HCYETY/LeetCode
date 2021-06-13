/*
����һ���������ַ��б� letters ���б���ֻ����СдӢ����ĸ��
�����һ��Ŀ����ĸ target������Ѱ������һ�����б����Ŀ����ĸ�����С��ĸ��
�ڱȽ�ʱ����ĸ������ѭ�����ֵġ��ٸ����ӣ�
���Ŀ����ĸ target = 'z' �����ַ��б�Ϊ letters = ['a', 'b']����𰸷��� 'a'

ʾ����
����:
letters = ["c", "f", "j"]
target = "a"
���: "c"

����:
letters = ["c", "f", "j"]
target = "c"
���: "f"

����:
letters = ["c", "f", "j"]
target = "d"
���: "f"

����:
letters = ["c", "f", "j"]
target = "g"
���: "j"

����:
letters = ["c", "f", "j"]
target = "j"
���: "c"

����:
letters = ["c", "f", "j"]
target = "k"
���: "c"

��ʾ��
letters���ȷ�Χ��[2, 10000]�����ڡ�
letters ����Сд��ĸ��ɣ����ٰ���������ͬ����ĸ��
Ŀ����ĸtarget ��һ��Сд��ĸ��
*/


// ����ɨ�裺
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char c: letters)
            if (c > target) return c;
        return letters[0];
    }
};
// ���ֲ��ң�
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
		  int len = letters.size();
        int left = 0, right = len;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(letters[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return letters[left % len];
    }
};
// ��¼���ڵ���ĸ��
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int seen[27] = {0};
        for(char c: letters)
            seen[c - 'a'] = 1;
        while (true) {
            target++;
            if (target > 'z') target = 'a';
            if (seen[target - 'a'] == 1) return target;
        }
    }
};
