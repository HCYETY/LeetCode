#include <bits/stdc++.h>
using namespace std;

int len;  // 数组长度
int arr[10000];

// 打印数组
void print(int arr[]) {
	cout<<setw(30)<<"打印数组:";
	for(int i=0; i<len; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

// 使用随机数生成数组
void createArray(int arr[]) {
	cout<<"请输入要生成的数组的长度"<<endl;
	cin>>len;
	int a, b;
	cout<<"请输入要生成的数的最小值"<<endl;
	cin>>a;
	cout<<"请输入要生成的数的最大值"<<endl;
	cin>>b;
	if(a > b) {
		cout<<"输入的最小值和最大值不合法，已自动纠正"<<endl;
		swap(a, b);
	}
	int index = 0;
	int n = len;
	while(n--) {
		arr[index++] = (rand() % (b - a + 1)) + a;
	}
	print(arr);
}

// 交换两个数
void swap(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}

// 冒泡排序一版
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
//冒泡优化第二版
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
//冒泡优化之鸡尾酒排序
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

// 交换排序
void swap_sort(int arr[]) {
	for(int i=0; i<len; i++)
		for(int j=i+1; j<len; j++)
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

//选择排序
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

// 插入排序
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

// 快速排序
//单边循环法
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
//双边循环法
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

// 归并排序
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

// 计数排序
void count_sort(int arr[])
{
    int len = sizeof(arr)/sizeof(int);
	int max = arr[0], min = arr[0];
	for(int i = 0; i < len; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
		if(arr[i] < min) {
			min = arr[i];
		}
	}

	int bucket[max-min+1];
	memset(bucket, 0, sizeof(bucket));
	for(int i = 0; i < len; i++) {
		bucket[arr[i]-min]++;
	}

    int index = 0;
	for(int i = 0; i < max - min + 1; i++) {
		for(int j = 0; j < bucket[i]; j++) {
			arr[index++] = min + i;
		}
	}
}

// 桶排序
void bucket_sort(int arr[]) {
    int len = sizeof(arr)/sizeof(int);
    int max = arr[0], min = arr[0];
    for(int i = 0; i < len; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    // 设置5个桶，计算每个桶存放的数值范围，至少为1
    int num = 5;
    int range = (max - min) / num;
    if(range < 1)  range = 1;
    // 创建二维数组，第一维表示第几个桶，第二维表示该桶里存放的数
    int bucket[num][100];
    // 表示每个桶里元素的个数
    int bucketSum[num];
    memset(bucketSum, 0, sizeof(bucketSum));

    for(int i = 0; i < len; i++) {
        // 计算元素应该分布在哪个桶
        int index = (arr[i] - min) / range;
        // 防止index越界，例如当[5,1,1,2,0,0]时index会出现5
        if(index >= num)  index = num - 1;

        // 插入排序，将元素有序插入到桶中
        int j = bucketSum[index] - 1;
        while(j >= 0 && arr[i] < bucket[index][j]) {
            bucket[index][j+1] = bucket[index][j];
            j--;
        }
        bucket[index][j+1] = arr[i];
        bucketSum[index]++;
    }

    // 修改回原数组
    int t = 0;
    for(int i = 0; i < num; i++) {
        for(int j=0; j<bucketSum[i]; j++) {
            arr[t++] = bucket[i][j];
        }
    }
}

// 基数排序
void radixSort(int arr[]) {
  int _max = (*max_element(arr, arr+len));
  // 计算最大值的位数
  int maxDigits = 0;
  while(_max) {
    maxDigits++;
    _max /= 10;
  }
  // 标记每个桶中存放的元素个数
  int bucketSum[10];
  memset(bucketSum, 0, sizeof(bucketSum));
  int div = 1;
  // 第一维表示位数即0-9，第二维表示里面存放的值
  int res[10][1000];
  while(maxDigits--) {
    int digit;
    // 根据数组元素的位数将其放到相应的桶里
    for(int i=0; i<len; i++) {
      digit = arr[i] / div % 10;
      res[digit][bucketSum[digit]++] = arr[i];
    }
    // 把0-9桶里的数放回原数组后再进行下一个位数的计算
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

// 堆排序

// 调整最大堆，使index的值大于左右节点
void adjustHeap(int arr[], int index, int size) {
  // 交换后可能会破坏堆结构，需要循环使得每一个父节点都大于左右结点
  while(true) {
    // 左节点
    int left = index * 2 + 1;
    // 右节点
    int right = index * 2 + 2;
    int _max = index;
    if(left < size && arr[_max] < arr[left])   _max = left;
    if(right < size && arr[_max] < arr[right]) _max = right;
    // 如果左右结点大于当前的结点则交换，并再循环一遍判断交换后的左右结点位置是否破坏了堆结构（比左右结点小了）
    if(_max != index) {
      swap(arr[_max], arr[index]);
      index = _max;
    }
    else {
      break;
    }
  }
}
// 建立最大堆
void buildHeap(int arr[]) {
  // 注意这里的头节点是从0开始的，所以最后一个非叶子结点是 parseInt(nums.length/2)-1。
  int start = floor(len / 2) -1;
  // 从最后一个非叶子结点开始调整，直至堆顶。
  for(int i=start; i>=0; i--) {
    adjustHeap(arr, i, len);
  }
}
void heapSort(int arr[]) {
  buildHeap(arr);
  // 循环n-1次，每次循环后交换堆顶元素和堆底元素并重新调整堆结构
  for(int i=len-1; i>0; i--) {
    swap(arr[0], arr[i]);
    adjustHeap(arr, 0, i);
  }
}

// 希尔排序
void shell_sort(int arr[]) {
    int len = sizeof(arr) / sizeof(int);
    int gap = len / 2;
    while(gap) {
        for(int i = gap; i < len; i++) {
            for(int j = i - gap; j >= 0; j -= gap) {
                if(arr[j] > arr[j+gap]) {
                    int tmp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j+gap] = tmp;
                } else {
                    break;
                }
            }
        }
        gap = gap / 2;
    }
}

int main() {
  while(1) {
    createArray(arr);
    cout<<endl;

    cout<<"冒泡排序第一版"<<endl;
    bubble_sort1(arr);
    print(arr);
    
    cout<<"冒泡排序第二版"<<endl;
    bubble_sort2(arr);
    print(arr);

	 cout<<"冒泡优化之鸡尾酒排序"<<endl;
    cocktail_sort(arr);
    print(arr);

	 cout<<"交换排序"<<endl;
    swap_sort(arr);
    print(arr);

    cout<<"选择排序"<<endl;
    selection_sort(arr);
    print(arr);

    cout<<"插入排序"<<endl;
    insert_sort(arr);
    print(arr);

    cout<<"快速排序之单边循环法"<<endl;
    quick_sort1(arr, 0, len-1);
    print(arr);
    
    cout<<"快速排序之双边循环法"<<endl;
    quick_sort2(arr, 0, len-1);
    print(arr);

    cout<<"归并排序"<<endl;
    merge_sort(arr, 0, len-1);
    print(arr);

	 cout<<"计数排序"<<endl;
    count_sort(arr);
    print(arr);
    
    cout<<"桶排序"<<endl;
    bucket_sort(arr);
    print(arr);

    cout<<"基数排序"<<endl;
    radixSort(arr);
    print(arr);

    cout<<"堆排序"<<endl;
    heapSort(arr);
    print(arr);

    cout<<"希尔排序"<<endl;
    shell_sort(arr);
    print(arr);
  }
}
