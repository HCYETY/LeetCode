/*
���һ���ҵ��������е� k ��Ԫ�ص��ࣨclass����ע���������ĵ� k ��Ԫ�أ����ǵ� k ����ͬ��Ԫ�ء�

��ʵ�� KthLargest �ࣺ
KthLargest(int k, int[] nums) ʹ������ k �������� nums ��ʼ������
int add(int val) �� val ���������� nums �󣬷��ص�ǰ�������е� k ���Ԫ�ء�

ʾ����
���룺
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
�����
[null, 4, 5, 5, 8, 8]
���ͣ�
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

��ʾ��
1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
������ add ���� 104 ��
��Ŀ���ݱ�֤���ڲ��ҵ� k ��Ԫ��ʱ�������������� k ��Ԫ��
*/


class KthLargest {
public:
// priority_queue ģ���� 3 ������������������Ĭ�ϵĲ�����
// ��һ�������Ǵ洢��������ͣ��ڶ��������Ǵ洢Ԫ�صĵײ������������������Ǻ���������������һ����������Ԫ��˳��Ķ��ԡ�
// ���ģ�������ǣ�template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue

//	������������ less<T> ��һ��Ĭ�ϵ�������ԣ�������ͷ�ļ� function �У�����������������Ԫ�ػ����ڶ���ǰ�档
//fonction �ж�����  greater<T>��������Ϊģ������һ��������Ԫ��������СԪ�ػ����ڶ���ǰ�档��Ȼ�����ָ��ģ����һ���������ͱ����ṩ���������ģ�����Ͳ�����
	 priority_queue<int, vector<int>, greater<int>> myqueue;
    int _k;

    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(int i : nums) {
            add(i);
        }
    }

    int add(int val) {
        myqueue.push(val);
        if(myqueue.size() > _k) {
            myqueue.pop();
        }
        return myqueue.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
