/*
�������� û���ظ�Ԫ�� ������ nums1 �� nums2 ������nums1 �� nums2 ���Ӽ���
�����ҳ� nums1 ��ÿ��Ԫ���� nums2 �е���һ��������ֵ��
nums1 ������ x ����һ������Ԫ����ָ x �� nums2 �ж�Ӧλ�õ��ұߵĵ�һ���� x ���Ԫ�ء���������ڣ���Ӧλ����� -1 ��

ʾ�� 1:
����: nums1 = [4,1,2], nums2 = [1,3,4,2].
���: [-1,3,-1]
����:
    ���� num1 �е����� 4 �����޷��ڵڶ����������ҵ���һ����������֣������� -1 ��
    ���� num1 �е����� 1 ���ڶ�������������1�ұߵ���һ���ϴ������� 3 ��
    ���� num1 �е����� 2 ���ڶ���������û����һ����������֣������� -1 ��

ʾ�� 2:
����: nums1 = [2,4], nums2 = [1,2,3,4].
���: [3,-1]
����:
    ���� num1 �е����� 2 ���ڶ��������е���һ���ϴ������� 3 ��
    ���� num1 �е����� 4 ���ڶ���������û����һ����������֣������� -1 ��

��ʾ��
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
nums1��nums2���������� ������ͬ
nums1 �е���������ͬ�������� nums2 ��

���ף���������һ��ʱ�临�Ӷ�Ϊ O(nums1.length + nums2.length) �Ľ��������
*/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        stack<int> mystack;
        for(int i = nums2.size(); i >= 0; i--) {
            while(!mystack.empty() && nums2[i] >= mystack.top()) {
                mystack.pop();
            }
            mystack.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++) {
            ans[i] = mystack.empty() ? -1 : mystack.top();
        }
        return ans;
    }
};
