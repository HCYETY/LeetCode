/*
�������һ������ n ����λԤԼ��ϵͳ����λ��Ŵ� 1 �� n ��
����ʵ�� SeatManager �ࣺ
- SeatManager(int n) ��ʼ��һ�� SeatManager ����������� 1 �� n ��ŵ� n ����λ��������λ��ʼ���ǿ�ԤԼ�ġ�
- int reserve() ���ؿ���ԤԼ��λ�� ��С��� ������λ��Ϊ����ԤԼ��
- void unreserve(int seatNumber) ��������� seatNumber ��Ӧ����λ��ɿ���ԤԼ��

ʾ�� 1��
���룺
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
�����
[null, 1, 2, null, 2, 3, 4, 5, null]
���ͣ�
SeatManager seatManager = new SeatManager(5); // ��ʼ�� SeatManager ���� 5 ����λ��
seatManager.reserve();    // ������λ������ԤԼ�����Է�����С��ŵ���λ��Ҳ���� 1 ��
seatManager.reserve();    // ����ԤԼ����λΪ [2,3,4,5] ��������С��ŵ���λ��Ҳ���� 2 ��
seatManager.unreserve(2); // ����λ 2 ��Ϊ����ԤԼ�����ڿ�ԤԼ����λΪ [2,3,4,5] ��
seatManager.reserve();    // ����ԤԼ����λΪ [2,3,4,5] ��������С��ŵ���λ��Ҳ���� 2 ��
seatManager.reserve();    // ����ԤԼ����λΪ [3,4,5] ��������С��ŵ���λ��Ҳ���� 3 ��
seatManager.reserve();    // ����ԤԼ����λΪ [4,5] ��������С��ŵ���λ��Ҳ���� 4 ��
seatManager.reserve();    // Ψһ����ԤԼ������λ 5 �����Է��� 5 ��
seatManager.unreserve(5); // ����λ 5 ��Ϊ����ԤԼ�����ڿ�ԤԼ����λΪ [5] ��

��ʾ��
1 <= n <= 105
1 <= seatNumber <= n
ÿһ�ζ� reserve �ĵ��ã���Ŀ��֤���ٴ���һ������ԤԼ����λ��
ÿһ�ζ� unreserve �ĵ��ã���Ŀ��֤ seatNumber �ڵ��ú���ǰ���Ǳ�ԤԼ״̬��
�� reserve �� unreserve �ĵ��� �ܹ� ������ 105 �Ρ�
*/


class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>>myqueue;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++) {
            myqueue.push(i);
        }
    }

    int reserve() {
        int x = myqueue.top();
        myqueue.pop();
        return x;
    }

    void unreserve(int seatNumber) {
        myqueue.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
