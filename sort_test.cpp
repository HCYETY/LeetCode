#include <bits/stdc++.h>
using namespace std;

int len;  // ���鳤��
int arr[10000];

// ��ӡ����
void print(int arr[]) {
	cout<<setw(30)<<"��ӡ����:";
	for(int i=0; i<len; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

// ʹ���������������
void createArray(int arr[]) {
	cout<<"������Ҫ���ɵ�����ĳ���"<<endl;
	cin>>len;
	int a, b;
	cout<<"������Ҫ���ɵ�������Сֵ"<<endl;
	cin>>a;
	cout<<"������Ҫ���ɵ��������ֵ"<<endl;
	cin>>b;
	if(a > b) {
		cout<<"�������Сֵ�����ֵ���Ϸ������Զ�����"<<endl;
		swap(a, b);
	}
	int index = 0;
	int n = len;
	while(n--) {
		arr[index++] = (rand() % (b - a + 1)) + a;
	}
	print(arr);
}

// ����������
void swap(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}

// ð������һ��
void bubble_sort1(int num[]) {
	for(int p = len - 1; p > 0; p--) {
		bool flag = false;
		for(int i = 0; i < p; i++) {
			if(num[i] > num[i+1]) {
				int temp = num[i];
				num[i] = num[i+1];
				num[i+1] = temp;
				flag = true;
			}
		}
		if(flag == false)
			break;
	}
}
//ð���Ż��ڶ���
void bubble_sort2(int num[]) {
    int lastExchange_index = 0;
    int sortBorder = len - 1;

    for(int i = 0; i < len - 1; i++) {
        bool flag = false;

        for(int j = 0; j < sortBorder; j++) {
            int tmp = 0;
            if(num[j] > num[j+1]) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;

                flag = true;
                lastExchange_index = j;
            }
        }

        sortBorder = lastExchange_index;
        if(flag == false)
            break;
    }
}
//ð���Ż�֮��β������
void cocktail_sort(int arr[]) {
    int tmp = 0;
    for(int i = 0; i < len / 2; i++) {

        bool isSorted = true;
        for(int j = i; j < len - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;

                isSorted = false;
            }
        }

        isSorted = true;
        for(int j = len - i - 1; j > i; j--) {
            if(arr[j] < arr[j-1]) {
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                isSorted = false;
            }
        }

        if(isSorted)
            break;
    }
}

// ��������
void swap_sort(int arr[]) {
	for(int i=0; i<len; i++)
		for(int j=i+1; j<len; j++)
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

//ѡ������
void selection_sort(int num[]) {
	for(int i = 0; i < len - 1; i++) {
		int min_index = i;

		for(int j = i + 1; j < len; j++)
			if(num[j] < num[min_index])
				min_index = j;

		int tmp = num[i];
		num[i] = num[min_index];
		num[min_index] = tmp;
	}
}

// ��������
void insert_sort(int arr[]) {
	for(int i = 1; i < len; i++) {
		int tmp = arr[i];

		int j = i;
		while(j > 0 && arr[j-1] > tmp) {
			arr[j--] = arr[j-1];
		}

		arr[j] = tmp;
	}
}

// ��������
//����ѭ����
int partition1(int num[], int start_index, int end_index) {
    int pivot = num[start_index];
    int mark = start_index;

    for(int i = start_index + 1; i <= end_index; i++) {
        if(num[i] < pivot) {
            mark++;
            int temp = num[mark];
            num[mark] = num[i];
            num[i] = temp;
        }
    }

    num[start_index] = num[mark];
    num[mark] = pivot;
    return mark;
}
void quick_sort1(int num[], int start_index, int end_index) {
    if(start_index >= end_index) {
        return;
    }
    int pivot_index = partition1(num, start_index, end_index);
    quick_sort1(num, start_index, pivot_index - 1);
    quick_sort1(num, pivot_index + 1, end_index);
}
//˫��ѭ����
int partition2(int num[], int start_index, int end_index) {
    int pivot = num[start_index];
    int left = start_index;
    int right = end_index;

    while(left != right) {
        while(left < right && num[right] > pivot)
            right--;

        while(left < right && num[right] <= pivot)
            left++;
            
        if(left < right) {
            int temp = num[left];
            num[left] = num[right];
            num[right] = temp;
        }
    }
    num[start_index] = num[left];
    num[left] = pivot;

    return left;
}
void quick_sort2(int num[], int start_index, int end_index) {
    if(start_index >= end_index) {
        return;
    }
    int pivot_index = partition2(num, start_index, end_index);
    quick_sort2(num, start_index, pivot_index - 1);
    quick_sort2(num, pivot_index + 1, end_index);
}

// �鲢����
void merge_sort(int arr[], int left, int right) {
	while(left >= right)  return;
	int mid = (right - left) / 2 + left;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);
	{
		int i = left, j = mid + 1;
		int temp[1000];
		int index = 0;
		while(i <= mid && j <= right) {
			if(arr[i] < arr[j]) {
				temp[index++] = arr[i++];
			} else {
				temp[index++] = arr[j++];
			}
		}
		while(i <= mid)  temp[index++] = arr[i++];
		while(j <= right)  temp[index++] = arr[j++];

		for(int i=0; i<index; i++) {
			arr[left + i] = temp[i];
		}
	}
}

// Ͱ����
void bucketSort(int arr[]) {
  // Ͱ�ĸ���
  int num = 5;
  int _max = (*max_element(arr, arr+len));
  int _min = (*min_element(arr, arr+len));
  // ����ÿ��Ͱ��ŵ���ֵ��Χ������Ϊ1��
  int range = (_max - _min) / num;
  if(range < 1)  range = 1;
  // ������ά���飬��һά��ʾ�ڼ���Ͱ���ڶ�ά��ʾ��Ͱ���ŵ���
  int res[100][1000];
  // ��ʾÿ��Ͱ��Ԫ�صĸ�������Ϊc++����ֱ�ӻ�ȡ��int����ĳ���...
  int bucketSum[num];
  memset(bucketSum, 0, sizeof(bucketSum));
  for(int i=0; i<len; i++) {
    // ����Ԫ��Ӧ�÷ֲ����ĸ�Ͱ
    int index = floor((arr[i] - _min) / range);
    // ��ֹindexԽ�磬���統[5,1,1,2,0,0]ʱindex�����5
    if(index >= num)  index = num - 1;
    // �������򣬽�Ԫ��������뵽Ͱ��
    int j = bucketSum[index] - 1;
    while(j >= 0 && arr[i] < res[index][j]) {
      res[index][j+1] = res[index][j];
      j--;
    }
    res[index][j+1] = arr[i];
    bucketSum[index]++;
  }
  // �޸Ļ�ԭ����
  int t = 0;
  for(int i=0; i<num; i++) {
    for(int j=0; j<bucketSum[i]; j++) {
      arr[t++] = res[i][j];
    }
  }
}

// ��������
void radixSort(int arr[]) {
  int _max = (*max_element(arr, arr+len));
  // �������ֵ��λ��
  int maxDigits = 0;
  while(_max) {
    maxDigits++;
    _max /= 10;
  }
  // ���ÿ��Ͱ�д�ŵ�Ԫ�ظ���
  int bucketSum[10];
  memset(bucketSum, 0, sizeof(bucketSum));
  int div = 1;
  // ��һά��ʾλ����0-9���ڶ�ά��ʾ�����ŵ�ֵ
  int res[10][1000];
  while(maxDigits--) {
    int digit;
    // ��������Ԫ�ص�λ������ŵ���Ӧ��Ͱ��
    for(int i=0; i<len; i++) {
      digit = arr[i] / div % 10;
      res[digit][bucketSum[digit]++] = arr[i];
    }
    // ��0-9Ͱ������Ż�ԭ������ٽ�����һ��λ���ļ���
    int index = 0;
    for(int i=0; i<=9; i++) {
      for(int t=0; t<bucketSum[i]; t++) {
        arr[index++] = res[i][t];
      }
    }
    memset(bucketSum, 0, sizeof(bucketSum));
    div *= 10;
  }
}

// ��������
void countingSort(int arr[]) {
  int res[10000];
  memset(res, 0, sizeof(res));
  int _max = (*max_element(arr, arr+len));
  int _min = (*min_element(arr, arr+len));
  for(int i=0; i<len; i++) {
    res[arr[i]]++;
  }
  int index = 0;
  for(int i=_min; i<=_max; i++) {
    while(res[i] > 0) {
      arr[index++] = i;
      res[i]--;
    }
  }
}

// ���������Ż�
void countingSort1(int arr[]) {
  int res[10000];
  memset(res, 0, sizeof(res));
  int _max = (*max_element(arr, arr+len));
  int _min = (*min_element(arr, arr+len));
  // ������Сֵ���෴������С���鷶Χ
  int add = -_min;
  for(int i=0; i<len; i++) {
    int temp = arr[i];
    temp += add;
    res[temp]++;
  }
  int index = 0;
  for(int i=_min; i<=_max; i++) {
    int temp = res[i+add];
    while(temp > 0) {
      arr[index++] = i;
      temp--;
    }
  }
}

// ������

// �������ѣ�ʹindex��ֵ�������ҽڵ�
void adjustHeap(int arr[], int index, int size) {
  // ��������ܻ��ƻ��ѽṹ����Ҫѭ��ʹ��ÿһ�����ڵ㶼�������ҽ��
  while(true) {
    // ��ڵ�
    int left = index * 2 + 1;
    // �ҽڵ�
    int right = index * 2 + 2;
    int _max = index;
    if(left < size && arr[_max] < arr[left])   _max = left;
    if(right < size && arr[_max] < arr[right]) _max = right;
    // ������ҽ����ڵ�ǰ�Ľ���򽻻�������ѭ��һ���жϽ���������ҽ��λ���Ƿ��ƻ��˶ѽṹ�������ҽ��С�ˣ�
    if(_max != index) {
      swap(arr[_max], arr[index]);
      index = _max;
    }
    else {
      break;
    }
  }
}
// ��������
void buildHeap(int arr[]) {
  // ע�������ͷ�ڵ��Ǵ�0��ʼ�ģ��������һ����Ҷ�ӽ���� parseInt(nums.length/2)-1��
  int start = floor(len / 2) -1;
  // �����һ����Ҷ�ӽ�㿪ʼ������ֱ���Ѷ���
  for(int i=start; i>=0; i--) {
    adjustHeap(arr, i, len);
  }
}
void heapSort(int arr[]) {
  buildHeap(arr);
  // ѭ��n-1�Σ�ÿ��ѭ���󽻻��Ѷ�Ԫ�غͶѵ�Ԫ�ز����µ����ѽṹ
  for(int i=len-1; i>0; i--) {
    swap(arr[0], arr[i]);
    adjustHeap(arr, 0, i);
  }
}

// ϣ������
void shellSort(int arr[]) {
  // ��ʼ����
  int gap = floor(len / 2);
  while(gap) {
    // �ӵ�gap��Ԫ�ؿ�ʼ����
    for(int i=gap; i<len; i++) {
      // �����ǰ�����������Ա���бȽϺͽ���
      for(int j=i-gap; j>=0; j-=gap) {
        if(arr[j] > arr[j+gap]) {
          swap(arr[j], arr[j+gap]);
        }
        else {
          break;
        }
      }
    }
    gap = floor(gap / 2);
  }
}

int main() {
  while(1) {
    createArray(arr);
    cout<<endl;

    cout<<"ð�������һ��"<<endl;
    bubble_sort1(arr);
    print(arr);
    
    cout<<"ð������ڶ���"<<endl;
    bubble_sort2(arr);
    print(arr);

	 cout<<"ð���Ż�֮��β������"<<endl;
    cocktail_sort(arr);
    print(arr);

	 cout<<"��������"<<endl;
    swap_sort(arr);
    print(arr);

    cout<<"ѡ������"<<endl;
    selection_sort(arr);
    print(arr);

    cout<<"��������"<<endl;
    insert_sort(arr);
    print(arr);

    cout<<"��������֮����ѭ����"<<endl;
    quick_sort1(arr, 0, len-1);
    print(arr);
    
    cout<<"��������֮˫��ѭ����"<<endl;
    quick_sort2(arr, 0, len-1);
    print(arr);

    cout<<"�鲢����"<<endl;
    merge_sort(arr, 0, len-1);
    print(arr);

    cout<<"Ͱ����"<<endl;
    bucketSort(arr);
    print(arr);

    cout<<"��������"<<endl;
    radixSort(arr);
    print(arr);

    cout<<"��������"<<endl;
    countingSort(arr);
    print(arr);

    cout<<"������"<<endl;
    heapSort(arr);
    print(arr);

    cout<<"ϣ������"<<endl;
    shellSort(arr);
    print(arr);
  }
}
