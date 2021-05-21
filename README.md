# 算法集合圈
## 十大排序
### 选择排序
- 核心思想：在未排序的序列中选出最小的元素和序列的首尾元素交换，接下来在剩下的未排序序列中再选出最小元素与序列的第二位元素交换，以此类推，最后形成从小到大的已排序序列。
- 最好：O(n²)
- 最坏：O(n²)
- 平均：O(n²)
```
void selection_sort(int num[]) {
    int n = num.size();
    <!-- 依次处理区间[0, n-1], [1, n-1], ...... -->
    for(int i = 0; i < n - 1; i++) {
        <!-- 在区间[i, n-1]内选出最小元素，交换到区间头部 -->
        int min_index = i;
        <!-- 1.在区间[i, n-1]内选出最小元素的位置min_index -->
        for(int j = i + 1; j < n; j++)
            if(num[j] < num[min_index])
                min_index = j;
        <!-- 2.把最小元素交换到区间头部 -->
        int temp = num[i];
        num[i] = num[min_index];
        num[min_index] = temp;
    }
}
```
### 插入排序
1. 简单插入排序
    - 核心思想：将待排序的一组序列分为已排好序的 和 未排序的两个部分；初始状态时，已排序序列仅包含第一个元素，未排序序列中的元素为除去第一个以外len-1个元素；此后将未排序序列中的元素逐一插入到已排序的序列中，
    - 最好：O(n)，原数组已经是升序的。
    - 最坏：O(n²)
    - 平均：O(n²)
```
void insert_sort(int num[]) {
    int n = num.size();
<!-- 依次处理第2， 3， ..., len个元素 -->
    for(int insert_index = 1; insert_index < n; insert_index++) {
<!-- 把num[p]插入到左边p个元素内 -->
<!-- 1.移走num[p]，用tmp记住它 -->
        int temp = num[insert_index];
<!-- 2.从右向左的，把区间[0, p-1]内大于tmp的元素右移一格 -->
        int i = insert_index;
        while(i > 0 && num[i-1] > temp) {
            num[i] = num[i-1];
            i--;
        }
<!-- 3.把tmp填入空出来的位置 -->
        num[i] = temp;
    }
}
```
2. 希尔排序
    - 核心思想：将待排序的一组元素按一定间隔分为若干个序列，分别进行插入排序。开始时设置的“间隔”较大，在每轮排序中将间隔逐步减小，直到“间隔”为1，也就是最后一步是进行简单插入排序。
    - 最好：O(n * logn)，步长不断二分。
    - 最坏：O(n * logn)
    - 平均：O(n * logn)
```
void shell_sort(int num[]) {
    int n = num.size();
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
- 核心思想：对元素个数为len的待排序序列进行排序时，共进行len-1次循环。在第k次循环中，对从第1到底len-k个元素从前往后进行比较，每次比较相邻的两个元素，若前一个元素大于后一个元素，则两者互换位置，否则保持位置不变。这样一次循环下来，就把第k大的元素移动到第len-k个位置上，称为第k趟的冒泡。
- 最好：O(n)，只需要冒泡一次数组就有序了。
- 最坏：O(n²)
- 平均：O(n²)
```
void bubble_sort(int num[]) {
    int n = num.size();
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
### 快速排序
- 核心思想：选择一个元素作为基数（通常是第一个元素），把比基数小的元素放到它左边，比基数大的元素放到它右边（相当于二分），再不断递归基数左右两边的序列。
- 最好：O(n * logn)，所有数均匀分布在基数的两边，此时的递归就是不断地二分左右序列。
- 最坏：O(n²) ，所有数都分布在基数的一边，此时划分左右序列就相当于是插入排序。
- 平均：O(n * logn)
1. 双边循环法
- 实现思想：采用左右双指针，第一次循环从right指针开始，让指针所指向的元素和基准元素作比较，如果大于或等于pivot，则指针向左移动；如果小于pivot，则right指针停止移动，切换到left指针。轮到left指针行动，让指针所指向的元素和基准元素作比较，如果小于或等于pivot。则指针向右移动；如果大于pivot。则left指针停止移动。这时让left和right指针所指向的元素进行交换。然后进入第2次循环，重新切换到right指针......
```
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
void partition(int num[], int start_index, end_index) {
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
            left++:
        
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
```
2. 单边循环法
- 实现思想：首先选定基准元素pivot。同时设置一个mark指针指向数列起始位置（这个mark指针代表小于基准元素的区域边界）。接下来，从基准元素的下一个位置开始遍历数组，如果遍历到的元素大于基准元素，就继续往后遍历；如果遍历到的元素小于基准元素，则需要做两件事：①把mark指针右移1位（因为小于pivot的区域边界增大二楼1）；②让最新遍历到的元素和mark指针所在位置的元素交换位置（因为最新遍历的元素归属于小于pivot的区域）。
- 递归实现：
```
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
- 非递归实现：
```
void quick_sort(int num[], int start_index, end_index) {
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