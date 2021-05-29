/*
����һ��Ŀ������ target ��һ������ n��ÿ�ε�������Ҫ�� list = {1,2,3..., n} �������ȡһ�����֡�

��ʹ����������������Ŀ������ target ��
Push���� list �ж�ȡһ����Ԫ�أ� ���������������С�
Pop��ɾ�������е����һ��Ԫ�ء�

���Ŀ�����鹹����ɣ���ֹͣ��ȡ����Ԫ�ء�
��Ŀ���ݱ�֤Ŀ�������ϸ����������ֻ���� 1 �� n ֮������֡�
�뷵�ع���Ŀ���������õĲ������С�
��Ŀ���ݱ�֤����Ψһ�ġ�

ʾ�� 1��
���룺target = [1,3], n = 3
�����["Push","Push","Pop","Push"]
���ͣ�
��ȡ 1 ���Զ��������� -> [1]
��ȡ 2 ���Զ��������飬Ȼ��ɾ���� -> [1]
��ȡ 3 ���Զ��������� -> [1,3]

ʾ�� 2��
���룺target = [1,2,3], n = 3
�����["Push","Push","Push"]

ʾ�� 3��
���룺target = [1,2], n = 4
�����["Push","Push"]
���ͣ�ֻ��Ҫ��ȡǰ 2 �����־Ϳ���ֹͣ��

ʾ�� 4��
���룺target = [2,3,4], n = 4
�����["Push","Pop","Push","Push","Push"]

��ʾ��
1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target ���ϸ������
*/

//�ѵ����õ�Ŀ������target�з�������Ԫ��

/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
    let mystack = [], anstack = [];
    for(let i = 0; i < n; i++) {
        anstack.push("Push");
        mystack.push(i+1);
        if(mystack[mystack.length - 1] !== target[mystack.length - 1]){
            anstack.push("Pop");
            mystack.pop();
        }
        if(target.length === mystack.length) return anstack;
    }
    return anstack;
};
