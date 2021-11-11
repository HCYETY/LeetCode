/*
����һ���������� asteroids����ʾ��ͬһ�е����ǡ�
���������е�ÿһ��Ԫ�أ������ֵ��ʾ���ǵĴ�С��������ʾ���ǵ��ƶ���������ʾ�����ƶ�������ʾ�����ƶ�����ÿһ����������ͬ���ٶ��ƶ���
�ҳ���ײ��ʣ�µ��������ǡ�
��ײ�������������໥��ײ����С�����ǻᱬը������������Ǵ�С��ͬ�����������Ƕ��ᱬը�������ƶ�������ͬ�����ǣ���Զ���ᷢ����ײ��


ʾ�� 1��
���룺asteroids = [5,10,-5]
�����[5,10]
���ͣ�10 �� -5 ��ײ��ֻʣ�� 10 �� 5 �� 10 ��Զ���ᷢ����ײ��

ʾ�� 2��
���룺asteroids = [8,-8]
�����[]
���ͣ�8 �� -8 ��ײ�����߶�������ը��

ʾ�� 3��
���룺asteroids = [10,2,-5]
�����[10]
���ͣ�2 �� -5 ������ײ��ʣ�� -5 ��10 �� -5 ������ײ��ʣ�� 10 ��

ʾ�� 4��
���룺asteroids = [-2,-1,1,2]
�����[-2,-1,1,2]
���ͣ�-2 �� -1 �����ƶ����� 1 �� 2 �����ƶ��������ƶ�������ͬ�����ǲ��ᷢ����ײ����������û�����Ƿ�����ײ��

��ʾ��
2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans; // ��װ��ջ��ֻ��push_back������pop_back()����
        int n = asteroids.size();
        for(int i = 0; i < n; ++i){
            if(ans.empty() || asteroids[i] > 0) ans.push_back(asteroids[i]);
            else{
                while(ans.size() && ans.back() > 0 && ans.back() < -asteroids[i])
                    ans.pop_back(); // ������ײ��������������ֵ��С��ɾ���������
                if(ans.empty() || ans.back() < 0) ans.push_back(asteroids[i]);
                else if(ans.back() == -asteroids[i]) ans.pop_back(); // ���߶�ɾ��
            }
        }
        return ans;
    }
};
