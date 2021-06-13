/*
��������Ϸ�Ĺ������£�
ÿ����Ϸ���Ҷ���� 1 �� n ���ѡ��һ�����֡� �����ѡ�������ĸ����֡�
�����´��ˣ��һ�����㣬��²�����ֱ���ѡ���������Ǵ��˻���С�ˡ�

�����ͨ������һ��Ԥ�ȶ���õĽӿ� int guess(int num) ����ȡ�²���������ֵһ���� 3 �ֿ��ܵ������-1��1 �� 0����
-1����ѡ�������ֱ���µ�����С pick < num
1����ѡ�������ֱ���µ����ִ� pick > num
0����ѡ�������ֺ���µ�����һ������ϲ����¶��ˣ�pick == num
������ѡ�������֡�

ʾ�� 1��
���룺n = 10, pick = 6
�����6

ʾ�� 2��
���룺n = 1, pick = 1
�����1

ʾ�� 3��
���룺n = 2, pick = 1
�����1                           ��

ʾ�� 4��
���룺n = 2, pick = 2
�����2

��ʾ��
1 <= n <= 231 - 1
1 <= pick <= n
*/


/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(guess(mid) <= 0) {
                right = mid;
            } else if(guess(mid) == 1) {
                left = mid + 1;
            }
        }
        return left;
    }
};
