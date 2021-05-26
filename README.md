# 算法集合圈
## 十大排序
### 交换排序
**最基本的排序方法，采用双重循环，每一次符合判断条件后都要进行交换**
- 最好：O(n2)
- 最坏：O(n2)
- 平均：O(n2)
```
void swap_sort(int arr[]) {
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
```
### 选择排序
**在未排序的序列中选出最小的元素和序列的首位元素交换，接下来在剩下的未排序序列中再选出最小元素与序列的第二位元素交换，以此类推，最后形成从小到大的已排序序列。**
- 与交换排序不同的是，选择排序不会一直交换，而是第二次for循环到选出最小元素后才会进行交换
- 最好：O(n²)
- 最坏：O(n²)
- 平均：O(n²)
```
void selection_sort(int num[]) {
    int len = sizeof(num) / sizeof(int);

    <!-- 依次处理区间[0, len-1], [1, len-1], ...... -->
    for(int i = 0; i < len - 1; i++) {

        <!-- 在区间[i, len-1]内选出最小元素，交换到区间头部 -->
        int min_index = i;

        <!-- 1.在区间[i, len-1]内选出最小元素的位置min_index -->
        for(int j = i + 1; j < len; j++)
            if(num[j] < num[min_index])
                min_index = j;

        <!-- 2.把最小元素交换到区间头部 -->
        int tmp = num[i];
        num[i] = num[min_index];
        num[min_index] = tmp;
    }
}
```
### 插入排序
1. 简单插入排序

**将待排序的一组序列分为已排好序的 和 未排序的两个部分；初始状态时，已排序序列仅包含第一个元素，未排序序列中的元素为除去第一个以外len-1个元素；此后将未排序序列中的元素逐一插入到已排序的序列中**

    - 最好：O(n)，原数组已经是升序的。
    - 最坏：O(n²)
    - 平均：O(n²)
```
void insert_sort(int num[]) {
    int n = sizeof(num) / sizeof(int);

    <!-- 依次处理第2， 3， ..., len个元素 -->
    for(int i = 1; i < n; i++) {
        <!-- 把num[i]插入到左边i个元素内 -->

        <!-- 1.移走num[i]，用tmp记住它 -->
        int tmp = num[i];
        
        <!-- 2.从右向左的，把区间[0, i-1]内大于tmp的元素右移一格 -->
        int j = i;
        while(j > 0 && num[j-1] > tmp) {
            num[j--] = num[j-1];
        }

        <!-- 3.把tmp填入空出来的位置 -->
        num[j] = tmp;
    }
}
```
2. 希尔排序

**将待排序的一组元素按一定间隔分为若干个序列，分别进行插入排序。开始时设置的“间隔”较大，在每轮排序中将间隔逐步减小，直到“间隔”为1，也就是最后一步是进行简单插入排序。**

    - 最好：O(n * logn)，步长不断二分。
    - 最坏：O(n * logn)
    - 平均：O(n * logn)
```
void shell_sort(int num[]) {
    int n = sizeof(num) / sizeof(int);

    <!-- 初始步数 -->
    int gap = len / 2;

    <!-- 逐渐缩小步数 -->
    while(gap) {

        <!-- 从第gap个元素开始遍历 -->
        for(int i = gap; i < len; i++) {

            <!-- 逐步其和前面其他的组成员进行比较和交换 -->
            for(int j = i - gap; j >= 0; j -= gap) {
                if(nums[j] > nums[j+gap]) {
                    [nums[j], nums[j+gap]] = [nums[j+gap], nums[j]];
                } else {
                    break;
                }
            }
        }
        gap = parseInt(gap / 2);
    }
}
```
### 冒泡排序
**对元素个数为len的待排序序列进行排序时，共进行 len-1 次循环。在第k次循环中，对从第 1 到第 len-k 个元素从前往后进行比较，每次比较相邻的两个元素，若前一个元素大于后一个元素，则两者互换位置，否则保持位置不变。这样一次循环下来，就把第 k 大的元素移动到第 len-k 个位置上，称为第k趟的冒泡。**
- 最好：O(n)，只需要冒泡一次数组就有序了。
- 最坏：O(n²)
- 平均：O(n²)
1. 冒泡优化第一版
```
void bubble_sort(int num[]) {
    int n = sizeof(num) / sizeof(int);

    <!-- 依次处理区间[0, n-1], [0, n-2], [0, len-3], ... -->
    for(int p = n - 1; p > 0; p--) {
        bool flag = false;
        <!-- 每一轮循环，把区间[0, p]内最大的元素交换到区间尾部 -->

        <!-- 1.从左向右地，比较相邻的两个元素，如果大的在前，则交换 -->
        for(int i = 0; i < p; i++) {
            if(num[i] > num[i+1]) {
                int temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
                flag = true;
            }
        }

        <!-- 2.如果全程无交换，则跳出循环 -->
        if(flag == false)
            break;
    }
}
```
2. 冒泡优化第二版
```
void bubble_sort(int num[]) {
    int len = sizeof(num) / sizeof(int);

    <!-- 记录最后一次交换的位置 -->
    int lastExchange_index = 0;
    <!-- 无序数列的边界，每次比较字需要比到这里为止 -->
    int sortBorder = len - 1;
    
    for(int i = 0; i < len - 1; i++) {
        <!-- 有序标记，每一轮的初始值都是true -->
        bool flag = false;

        for(int j = 0; j < sortBorder; j++) {
            int tmp = 0;
            if(num[j] > num[j+1]) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;

                <!-- 因为有元素进行交换，所以不是有序的，标记为false -->
                flag = true;
                <!-- 更新为最后一次交换元素的位置 -->
                lastExchange_index = j;
            }
        }

        sortBorder = lastExchange_index;
        if(flag == false)
            break;
    }
}
```
3.冒泡优化之鸡尾酒排序
- 使用场景：大部分元素已经有序的情况
- 优点：能够在特定条件下，减少排序的回合数
- 缺点：代码量比冒泡多了一倍
```
void cocktail_sort(int arr[]) {
    int tmp = 0;
    for(int i = 0; i < arr.size() / 2; i++) {

        <!-- 有序标记，每一轮的初始值都是true -->
        bool isSorted = true;
        <!-- 奇数轮，从左向右比较和交换 -->
        for(int j = i; j < arr.size() - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;

                <!-- 有元素交换，所以不是有序的，标记为false -->
                isSorted = false;
            }
        }

        <!-- 将isSorted重新标记为true -->
        isSorted = true;
        <!-- 偶数轮，从右向左比较和交换 -->
        for(int j = arr.size() - i - 1; j > i; j--) {
            if(arr[j] < arr[j-1]) {
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;

                <!-- 有元素交换，所以不是有序的，标记为false -->
                isSorted = false;
            }
        }

        if(isSorted)
            break;
    }
}
```
### 快速排序
**选择一个元素作为基数（通常是第一个元素），把比基数小的元素放到它左边，比基数大的元素放到它右边（相当于二分），再不断递归基数左右两边的序列。**
- 最好：O(n * logn)，所有数均匀分布在基数的两边，此时的递归就是不断地二分左右序列。
- 最坏：O(n²) ，所有数都分布在基数的一边，此时划分左右序列就相当于是插入排序。
- 平均：O(n * logn)
1. 双边循环法

**采用左右双指针，第一次循环从right指针开始，让指针所指向的元素和基准元素作比较，如果大于或等于pivot，则指针向左移动；如果小于pivot，则right指针停止移动，切换到left指针。轮到left指针行动，让指针所指向的元素和基准元素作比较，如果小于或等于pivot。则指针向右移动；如果大于pivot。则left指针停止移动。这时让left和right指针所指向的元素进行交换。然后进入第2次循环，重新切换到right指针......**
```
int partition(int num[], int start_index, int end_index) {
    <!-- 取第1个位置（也可以选择随机位置）的元素作为基准元素 -->
    int pivot = num[start_index];
    int left = start_index;
    int right = end_index;

    while(left != right) {
        <!-- 控制right指针进行比较并左移 -->
        while(left < right && num[right] > pivot)
            right--;
        
        <!-- 控制left指针进行比较并右移 -->
        while(left < right && num[right] <= pivot)
            left++;
        
        <!-- 交换left和right指针所指向的元素 -->
        if(left < right) {
            int temp = num[left];
            num[left] = num[right];
            num[right] = temp;
        }
    }

    <!-- pivot和指针重合点进行交换 -->
    num[start_index] = num[left];
    num[left] = pivot;

    return left;
}
void quick_sort(int num[], int start_index, int end_index) {
    <!-- 递归结束条件：start_index大于或等于end_index时 -->
    if(start_index >= end_index) {
        return;
    }

    <!-- 得到基准元素位置 -->
    int pivot_index = partition(num, start_index, end_index);

    <!-- 根据基准元素，分成两部分进行递归排序 -->
    quick_sort(num, start_index, pivot_index - 1);
    quick_sort(num, pivot_index + 1, end_index);
}
```
2. 单边循环法

**首先选定基准元素pivot。同时设置一个mark指针指向数列起始位置（这个mark指针代表小于基准元素的区域边界）。接下来，从基准元素的下一个位置开始遍历数组，如果遍历到的元素大于基准元素，就继续往后遍历；如果遍历到的元素小于基准元素，则需要做两件事：①把mark指针右移1位（因为小于pivot的区域边界增大二楼1）；②让最新遍历到的元素和mark指针所在位置的元素交换位置（因为最新遍历的元素归属于小于pivot的区域）。**
- 递归实现：
```
int partition(int num[], int start_index, int end_index) {
    <!-- 取第1个位置（也可以选择随机位置）的元素作为基准元素 -->
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
void quick_sort(int num[], int start_index, int end_index) {
    <!-- 递归结束条件：start_index大于或等于end_index时 -->
    if(start_index >= end_index) {
        return;
    }

    <!-- 得到基准元素位置 -->
    int pivot_index = partition(num, start_index, end_index);

    <!-- 根据基准元素，分成两部分进行递归排序 -->
    quick_sort(num, start_index, pivot_index - 1);
    quick_sort(num, pivot_index + 1, end_index);
}
```
- 非递归实现：(待完善)
```
void quick_sort(int num[], int start_index, int end_index) {
    <!-- 用一个集合栈来代替递归的函数栈 -->
    Stack<>
}
void partition(int num[], int start_index, int end_index) {
    <!-- 取第1个位置（也可以选择随机位置）的元素作为基准元素 -->
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
```
### 归并排序
**将大小为n的序列看成n个长度为1的子序列，接下来将相邻子序列两两进行归并操作，形成n/2（+1）个长度为2（或1）的有序子序列；然后再继续进行相邻子序列两两归并操作，循环直到剩下1个长度为n的序列。**
- 最好：O(n * logn)
- 最坏：O(n * logn)
- 平均：O(n * logn)
```
void merge_sort(int num[], int left, int right) {
    while(left >= right)  return;

    // 比起(left+right)/2，更推荐下面这种写法，可以避免数溢出
    int mid = (right - left) / 2 + left;
    
    // 递归将数组分为两个序列
    merge_sort(num, left, mid);
    merge_sort(num, mid+1, right);

    // 有序合并两个数组
    {
        <!-- 新建一个额外的数组来存储归并后的序列 -->
        int temp[1000];

        int index = 0;
        int i = left, j = mid + 1;
        while(i <= mid && j <= right) {
            if(num[i] < num[j]) {
                temp[index++] = num[i++];
            } else {
                temp[index++] = num[j++];
            }
        }
        while(i <= mid)  temp[index++] = num[i++];
        while(j <= right)  temp[index++] = num[j++];

        // 将有序合并后的数组修改回原数组
        for(int i=0; i<index; i++) {
            num[left + i] = temp[i];
        }
    }
}
```
### 堆排序
- ①把无序数组构建成二叉堆。需要从小到大排序，则构建成最大堆；需要从大到小，则构建成最小堆。②循环删除堆顶元素，替换到二叉堆的末尾，调整堆产生新的堆顶。
```

```
### 计数排序
**①新建一个数组，长度为无序数组的 最大值-最小值+1 ，全部值为0；②以无序数组的最小值作为一个偏移量，用来计算整数在计数数组中的下标：遍历无序数组，得到每一个元素，减去偏移量后得到一个值，在计数数组中对应该值的下标的元素+1；③遍历完无序数组后，计数数组中每一个下标位置+偏移量的值代表无序数列中对应整数出现的次数；④有了这个统计结果后，排序就很简单了。直接遍历计数数组，输出该数组元素的下标值（这里已经将无序数组的元素从小到大排序好了，因为下标正是从小到大的），元素的值是几，就输出几次（无序数组中有重复的元素就可以随之输出）。**
- 最好：O(n + k)，k是最大值和最小值的差
- 平均：O(n + k)
- 最坏：O(n + k)
```
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
```
### 桶排序(over)
**①创建桶，并确定每一个桶的区间范围【（最大值 - 最小值） / 桶的数量 】；②遍历原始数列，计算每个元素应该放在哪个桶，将元素插入排序到对应桶内；③遍历所有的桶，输出所有元素。**
```
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
        for(int j = 0; j < bucketSum[i]; j++) {
            arr[t++] = bucket[i][j];
        }
    }
}
```
### 基数排序
- 