/*
�������� �ǵ��� ���������� nums1 �� nums2 �������±�� �� 0 ��ʼ ������
�±�� (i, j) �� 0 <= i < nums1.length �� 0 <= j < nums2.length ��
������±��ͬʱ���� i <= j �� nums1[i] <= nums2[j] �����֮Ϊ ��Ч �±�ԣ����±�Ե� ���� Ϊ j - i ��
�������� ��Ч �±�� (i, j) �е� ������ �������������Ч�±�ԣ����� 0 ��

һ������ arr �����ÿ�� 1 <= i < arr.length ���� arr[i-1] >= arr[i] ��������ô��������һ�� �ǵ��� ���顣

ʾ�� 1��
���룺nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
�����2
���ͣ���Ч�±���� (0,0), (2,2), (2,3), (2,4), (3,3), (3,4) �� (4,4) ��
�������� 2 ����Ӧ�±�� (2,4) ��

ʾ�� 2��
���룺nums1 = [2,2,2], nums2 = [10,10,1]
�����1
���ͣ���Ч�±���� (0,0), (0,1) �� (1,1) ��
�������� 1 ����Ӧ�±�� (0,1) ��

ʾ�� 3��
���룺nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
�����2
���ͣ���Ч�±���� (2,2), (2,3), (2,4), (3,3) �� (3,4) ��
�������� 2 ����Ӧ�±�� (2,4) ��

ʾ�� 4��
���룺nums1 = [5,4], nums2 = [3,2]
�����0
���ͣ���������Ч�±�ԣ����Է��� 0 ��

��ʾ��
1 <= nums1.length <= 105
1 <= nums2.length <= 105
1 <= nums1[i], nums2[j] <= 105
nums1 �� nums2 ���� �ǵ��� ����
*/


// ˫ָ�뷨
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int res = 0;
        // ÿ��ѭ�� j ��Ҫ + 1
        for(int j = 0; j < n2; ++j) {
            // �����������
            // �������ǰnums1[i] <= nums2[j]����������֮һ��iԭ�ز���������nums2�����Ԫ�ػ᲻��ȵ�ǰ��nums1[i]���������ĳ��nums2[j]�ȵ�ǰ��nums1[i]С���ͽ���ѭ���ж�
            // �������ǰnums1[i] > nums2[j]������������������Ҫi++����������whileѭ����������max()�����Բ��õ��� i > j ������Ч�±�Եľ���Ϊ�����������ֻ�����ﲻ���Ż����� i>j ��ʱ�� res �ᱣ�ֲ��䡣ֱ��i <= j��ſ��ܻ�����µı仯��
            while (i < n1 && nums1[i] > nums2[j]){
                ++i;
            }
            if (i < n1){
                res = max(res, j - i);
            }
        }
        return res;
    }
};
// ���������ֽⷨ���
class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int L = 0;
        int R = 0;
        while (L < len1 && R < len2) {
            if (nums1[L] > nums2[R]) {
                L++;
            }
            R++;
        }
        return R - L - 1 >= 0 ? R - L - 1 : 0;
    }
}

// ���ֲ���
class Solution {
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int Max = 0;//������Ϊ0
    //��nums2������С�Ĵ��ڵ���nums1[i]��ֵ���±꣨�±���ڵ���i��
    for(int i = 0; i < n1; ++i) {
        int l = i;
        int r = n2 - 1; //����ұ�
        int ansi = -1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums2[mid] < nums1[i]) { //̫С,�Ҵ���
                r = mid - 1;
            }
            else { //mid���У������Ƿ��и�С��mid
                ansi = mid;
                l = mid + 1;
            }
        }
        if (ansi != -1)
            Max = max(Max, abs(i - ansi));
    }
    return Max;
}
};

