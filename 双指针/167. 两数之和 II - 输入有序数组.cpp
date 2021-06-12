/*
����һ���Ѱ��� �������� ���������� numbers ��������������ҳ��������������֮�͵���Ŀ���� target ��
����Ӧ���Գ���Ϊ 2 �������������ʽ���������������±�ֵ��
numbers ���±� �� 1 ��ʼ���� �����Դ�����Ӧ������ 1 <= answer[0] < answer[1] <= numbers.length ��
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�

ʾ�� 1��
���룺numbers = [2,7,11,15], target = 9
�����[1,2]
���ͣ�2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��

ʾ�� 2��
���룺numbers = [2,3,4], target = 6
�����[1,3]

ʾ�� 3��
���룺numbers = [-1,0], target = -1
�����[1,2]

��ʾ��
2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers �� ����˳�� ����
-1000 <= target <= 1000
������һ����Ч��
*/


// ����һ����β˫ָ��
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left <= right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) return {left + 1, right + 1};
            else if(sum > target) right--;
            else left++;
        }
        return {};
    }
};
// �����������ֲ���
// ���������ҵ���������ʹ�����ǵĺ͵���Ŀ��ֵ���������ȹ̶���һ������Ȼ��Ѱ�ҵڶ�������
// �ڶ���������Ŀ��ֵ��ȥ��һ�����Ĳ����������������ʣ�����ͨ�����ֲ��ҵķ���Ѱ�ҵڶ�������
// Ϊ�˱����ظ�Ѱ�ң���Ѱ�ҵڶ�����ʱ��ֻ�ڵ�һ�������Ҳ�Ѱ�ҡ�
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};
