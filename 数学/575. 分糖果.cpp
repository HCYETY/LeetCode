/*
����һ��ż�����ȵ����飬���в�ͬ�����ִ����Ų�ͬ������ǹ���ÿһ�����ִ���һ���ǹ���
����Ҫ����Щ�ǹ�ƽ���ָ�һ���ܵܺ�һ�����á��������ÿ��Ի�õ�����ǹ�����������

ʾ�� 1:
����: candies = [1,1,2,2,3,3]
���: 3
����: һ��������������ǹ���ÿһ�ֶ���������
     ���ŷ��䷽�������û��[1,2,3],�ܵ�Ҳ���[1,2,3]������ʹ���û���ǹ�����������ࡣ
     
ʾ�� 2 :
����: candies = [1,1,2,3]
���: 2
����: ���û���ǹ�[2,3],�ܻܵ���ǹ�[1,1]�����������ֲ�ͬ���ǹ����ܵ�ֻ��һ�֡�����ʹ�����ÿ��Ի�õ��ǹ���������ࡣ

ע��:
����ĳ���Ϊ[2, 10,000]������ȷ��Ϊż����
���������ֵĴ�С�ڷ�Χ[-100,000, 100,000]�ڡ�
*/

//��ջ��
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        vector<int> ans;
        ans.push_back(candyType[0]);
        for(int i = 1; i < candyType.size(); i++) {
            if(candyType[i] != candyType[i-1]) {
                ans.push_back(candyType[i]);
            }
        }
			// �������⣬�ܵܺ�����һ�˷�һ����ǹ�����ô����ȫ���ǹ������඼��һ�����������Ҳֻ�ܵõ�һ�벻һ�����ǹ���
        if(ans.size() >= candyType.size() / 2) {
            return candyType.size() / 2;
        } else {
            return ans.size();
        }
    }
};
//������ջ����������ռ����Ƿ�������Ż�
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int count = 1;
        for(int i = 1; i < candyType.size(); i++) {
            if(count >= candyType.size() / 2) {
                return candyType.size() / 2;
            }
            if(candyType[i] != candyType[i-1]) {
                count++;
            }
        }
        return count;
    }
};
