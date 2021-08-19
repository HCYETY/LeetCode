/*
����һ������ prices �����ĵ�?i ��Ԫ��?prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�

��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������

��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��


ʾ�� 1��
���룺[7,1,5,3,6,4]
�����5
���ͣ��ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
     ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�ͬʱ���㲻��������ǰ������Ʊ��

ʾ�� 2��
���룺prices = [7,6,4,3,1]
�����0
���ͣ������������, û�н������, �����������Ϊ 0��
*/


// һ�α���
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf;
        // ��ͬ��int minprice = int(1e9);
        
        int maxprofit = 0;
        for(int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }
        return maxprofit;
    }
};
// ��̬�滮
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // �߽�����
        int minprice = prices[0];
        vector<int> dp (n, 0);

        for (int i = 1; i < n; i++){
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[n - 1];
    }
};
// ��̬�滮�Ż�
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // �߽�����
        int minprice = prices[0],  profit = 0;

        for (int i = 1; i < n; i++){
            minprice = min(minprice, prices[i]);
            profit = max(profit, prices[i]-minprice);
        }
        return profit;
    }
};
