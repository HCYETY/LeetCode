/*
ѧУ����������ṩԲ�κͷ��ε������Σ��ֱ������� 0 �� 1 ��ʾ������ѧ��վ��һ�������ÿ��ѧ��Ҫôϲ��Բ�ε�Ҫôϲ�����εġ�
�����������ε�������ѧ����������ͬ�����������ζ�����һ�� ջ �ÿһ�֣�
- ���������ǰ���ѧ�� ϲ�� ջ���������Σ���ô�� ������ ���뿪���С�
- ��������ѧ���� ������������� ���ص����е�β����
- ������̻�һֱ����������������ѧ������ϲ��ջ����������Ϊֹ��
���������������� students �� sandwiches ������ sandwiches[i] ��ջ����� i �������ε����ͣ�i = 0 ��ջ�Ķ������� students[j] �ǳ�ʼ������� j ��ѧ���������ε�ϲ�ã�j = 0 �Ƕ��е��ʼλ�ã���
���㷵���޷�����͵�ѧ��������

ʾ�� 1��
���룺students = [1,1,0,0], sandwiches = [0,1,0,1]
�����0
���ͣ�
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [1,0,0,1]��
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [0,0,1,1]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = [0,1,1]��������ջΪ sandwiches = [1,0,1]��
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [1,1,0]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = [1,0]��������ջΪ sandwiches = [0,1]��
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [0,1]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = [1]��������ջΪ sandwiches = [1]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = []��������ջΪ sandwiches = []��
��������ѧ�����������γԡ�

ʾ�� 2��
���룺students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
�����3

��ʾ��
1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] Ҫô�� 0 ��Ҫô�� 1 ��
students[i] Ҫô�� 0 ��Ҫô�� 1 ��
*/


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> Qstudent;
        stack <int> Ssandwiches;
        for(int num : students) Qstudent.push(num);  //��students���´��������
        reverse(sandwiches.begin(), sandwiches.end());
        for(int num:sandwiches) Ssandwiches.push(num); //��sandwiches���´���ջ��

        int cunt = 0;//��¼ѧ������û���쵽�����εĴ���
        while(1) {
            if(Qstudent.front() == Ssandwiches.top()) {
                Qstudent.pop();
                Ssandwiches.pop();
                // ֻҪ��һ��ѧ�������� Ssandwiches ջ���������Σ������¼���
                cunt = 0;
            } else {
                Qstudent.push(Qstudent.front());
                Qstudent.pop();
                cunt += 1;
            }
            // ��cunt����ʣ���ѧ������������һ�ܣ�����˵��ʣ�µ�ѧ�����ٿ����쵽������
            if(cunt >= Qstudent.size() || Qstudent.size()==0)
                break;
        }
        return Qstudent.size();
    }
};
