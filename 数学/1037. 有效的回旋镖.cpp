/*
�����ڶ���Ϊһ�������㣬��Щ�������ͬ�Ҳ���һ��ֱ���ϡ�
����ƽ������������ɵ��б��ж���Щ���Ƿ���Թ��ɻ����ڡ�

ʾ�� 1��
���룺[[1,1],[2,3],[3,2]]
�����true

ʾ�� 2��
���룺[[1,1],[2,2],[3,3]]
�����false

��ʾ��
points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/


// ˼·��
// �ж������Ƿ�ֱͬ�ߣ�ֱ��˼·�����ж�б�ʣ�б����ͬ�����㹲�ߡ�
// ��������ֱ�Ϊa(x1, y1), b(x2, y2), c(x3,y3)��������֮�����������ߣ���
// a��b�����б��Ϊ slope1 = (y2 - y1) / (x2 - x1)
// a��c�����б��Ϊ slope2 = (y3 - y1) / (x3 - x1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
		// ������Ϊ���жϷ�ĸΪ 0 ���������ʧ����
	      // int k1 = 0, k2 = 0, k3 = 0;
	      // if(points[0][0] == 0) k1 = 1;
	      // else k1 = points[0][1] / points[0][0];
	      
	      // if(points[1][0] == 0) k2 = 1;
	      // else k2 = points[1][1] / points[1][0];
	      
	      // if(points[2][0] == 0) k3 = 1;
	      // else k3 = points[2][1] / points[2][0];
	      
	      // if(k1 == k2 && k1 == k2 && k2 == k3) return false;
	      // return true;
		//	��ȷ���������������
			// �� slope1 == slope2 ���Ϳ��Խ��н������
			// ���ｫ������˵Ľ����������
         int k1 = (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]);
         int k2 = (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]);
         return k1 != k2;
    }
};
