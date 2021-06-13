/*
���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣
����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�
�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��
�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���ʵ
��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����

ʾ��:
���� n = 5������ version = 4 �ǵ�һ������İ汾��

���� isBadVersion(3) -> false
���� isBadVersion(5)?-> true
���� isBadVersion(4)?-> true

���ԣ�4 �ǵ�һ������İ汾��
*/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
