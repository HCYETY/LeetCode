# 算法集合圈
## 计数质数
### 常规枚举
暴力算法
```c++
int countPrimes(int n) {
    int count = 0;
    for(int i = 2; i < n; i++) {
        bool sign = true;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                sign = false;
                break;
            }
        }
        if(sign)
            count++; ;
    }
    return count;
}
```
暴力算法优化  
细究暴力计算的方法，我们可以发现，假如一个数为 9 ，那么其二分之一（4.5）后的数都可以不用进行计算，因为肯定是有余的 。事实上情况会比这更好一些：对正整数 n ，如果用 2 到 √n 之间(包含边界)的所有整数去除，均无法整除，则 n 为质数。   
并且，我们可以发现，一切非 2 偶数一定不可能为质数。所以，我们可以在此处进行另一步的优化。
```c++
int countPrimes(int n) {
    if(n < 3)
        return 0;;
    //从3开始验算，所以初始值为1（2为质数）。
    int count = 1;
    for(int i = 3; i < n; i++) {
        // 当某个数为 2 的 n 次方时（n为自然数），其 & (n - 1) 所得值将等价于取余运算所得值
        // 如果 x = 2^n ，则 x & (n - 1) == x % n
        if((i & 1) == 0)   // 等价于 if(i % 2 == 0)
            continue;
        bool sign = true;
        //用 j * j <= i 代替 j <= √i 会更好。
        //因为我们已经排除了所有偶数，所以每次循环加二将规避偶数会减少循环次数
        for(int j = 3; j * j <= i; j += 2) {
            if(i % j == 0) {
                sign = false;
                break;
            }
        }
        if(sign)
            count++;
    }
    return count;
}
```
### 厄拉多塞筛法，简称埃氏筛
**基本思路：将2~n中所有质数的倍数都删掉，剩余的数据就是质数。**   
对 1 到 64 的质数的筛选过程：从 2 开始遍历，把 2 的倍数都标记为 false（表示不是素数），再从 2 的下一位素数 3 （未被标记为false的元素）开始也同样标记其倍数。以此类推，最后仍为 true 的则为素数。
- ①新建一个大小为 64 的数组，初始值标记为true。
- ②从 2 开始遍历。如果布尔值为false，说明不为质数；如果为true，则为质数，计算质数数量的值+1。
- ③如果 xx 是质数，那么大于 xx 的 xx 的倍数 2x，3x，… 一定不是质数，那么将当前值的所有倍数标记为false。继续循环找下一个质数（即布尔值为true的元素），继续标记非质数...
```c++
int countPrimes(int n) {
    int count = 0;
    //初始默认所有数为质数
    vector<bool> sign(n, true);
    for (int i = 2; i < n; i++) {
        if (sign[i]) {
            count++;
            for (int j = i + i; j < n; j += i) {
                //排除不是质数的数
                sign[j] = false;
            }
        }
    }
    return count;
}
```
> 可进一步了解：[质数](https://blog.csdn.net/weixin_42638946/article/details/115703334)
---
## KMP算法
> 先理解什么是KMP，可参考 -> [阮一峰的网络日志：字符串匹配的KMP算法](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)   
> 想知道原理是怎么回事，可参考 -> [Matrix67：KMP算法详解](http://www.matrix67.com/blog/archives/115)   
> 如果还有疑惑，（有足够的耐心），可浏览 - > [从头到尾彻底理解KMP](https://blog.csdn.net/v_july_v/article/details/7041827)
## BM算法
既然知道了什么是KMP算法，那接下来的BM算法肯定是不能放过的了
> 可参考 -> [阮一峰的网络日志：字符串匹配的 Boyer-Moore 算法](http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html)   
> 代码实现 -> [Boyer-Moore 算法](https://ethsonliu.com/2019/11/boyer-moore.html)
## Sunday算法
是对BM算法的进一步小幅优化。   
**给定一个字符串soString为 "sundaynb searching" ，待比较的字符串nowString为 "search" 。**   
**开始时，两个字符串左对齐，发现第二个字符不匹配，于是直接找到 n ，即 soString 中下标为 6 的字符，也就是 soString 中参与匹配的最末位字符的下一位字符。**   
**然后发现 nowString 中并不存在 n ，于是 nowString 直接越过字符 n ，与 b 对齐准备开始下一次匹配**   
**结果第一个字符就不匹配，继续看 soString 参与匹配的最末位字符的下一位字符，为 c ，（这时候重点来了）从右往左找（目的是为了找到最右出现的字符），发现nowString 中有 c ，（那么问题来了：我们已经看出可将 nowString 后移 2 位，即 c 与 c 对齐即可匹配成功，但计算机该怎么知道移动多少位呢）答案是应该移动【nowSting中最右的 c 到 nowString 末尾的距离 + 1】 = 【nowString的长度 - nowString中最右边的 c 的下标】**   
**一移，对齐，哦吼，发现全部匹配上了，nice**
- 平均：O(n)
- 最差：O(n∗m) eg.主串：baaaabaaaabaaaabaaaa 模式串：aaaaa，每次匹配失败时，只让模式串向后移动一位再进行匹配
代码实现：（理解）
```c++
int maxNum = 1005;
int res[maxNum];
int Sunday(string soString, string nowString) {
    int len_so = soString.size();
    int len_now = nowString.size();

    // 默认值，移动 len_now+1 位
    for(int i = 0; i < maxNum; i++) {
        res[i] = len_now + 1;
    }

    // nowString中每个字母出现的最后的下标
    // 所对应的soString参与匹配的最末位字符的下一位字符移动到该位，所需要的移动位数
    for(int i = 0; i < len_now; i++) {
        res[nowString[i]] = len_now - i;
    }

    // nowString开始位置在oString的哪里
    int s = 0;
    // nowString已经匹配到的位置
    int j;
    while(s <= len_so - len_now) {
        j = 0;
        while(soString[s + j] == nowString[j]) {
            j++;
            // 匹配成功
            if(j >= len_now) {
                return s;
            }
        }
        // 找到soString中当前跟nowString匹配的最末字符的下一个字符
        // 在nowString中出现最后的位置
        // 所需要从(nowString末尾+1)移动到该位置的步数
        s += res[soString[s + len_now]];
    }
    return -1;
}
```
> 可参考：[字符串匹配——Sunday算法](https://blog.csdn.net/q547550831/article/details/51860017)
> [练习：LeetCode 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)（重做一遍）
---
## 栈
### 单调队列
**单调栈用途不太广泛，只处理一种典型的问题，叫做 Next Greater Element**

Next Greater Number 的原始问题：给你一个数组，返回一个等长的数组，对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1。

例子：给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。
```c++
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size()); // 存放答案的数组
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) { // 倒着往栈里放
        while (!s.empty() && s.top() <= nums[i]) { // 判定个子高矮
            s.pop(); // 矮个起开，反正也被挡着了。。。
        }
        ans[i] = s.empty() ? -1 : s.top(); // 这个元素身后的第一个高个
        s.push(nums[i]); // 进队，接受之后的身高判定吧！
    }
    return ans;
}
```
> 学习资料转载自@labuladong的LeetCode题解：[单调栈解决 Next Greater Number 一类问题](https://leetcode-cn.com/problems/next-greater-element-i/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/)

- [练习：LeetCode 496. 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)
---
## 十大排序
### 交换排序
**最基本的排序方法，采用双重循环，每一次符合判断条件后都要进行交换**
- 最好：O(n²)
- 最坏：O(n²)
- 平均：O(n²)
```c++
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
```c++
void selection_sort(int num[]) {
    int len = sizeof(num) / sizeof(int);

    // 依次处理区间[0, len-1], [1, len-1], ...... 
    for(int i = 0; i < len - 1; i++) {
        // 在区间[i, len-1]内选出最小元素，交换到区间头部 
        int min_index = i;
        // 1.在区间[i, len-1]内选出最小元素的位置min_index 
        for(int j = i + 1; j < len; j++)
            if(num[j] < num[min_index])
                min_index = j;
        // 2.把最小元素交换到区间头部 
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
```c++
void insert_sort(int num[]) {
    int n = sizeof(num) / sizeof(int);

    // 依次处理第2， 3， ..., len个元素
    for(int i = 1; i < n; i++) {
        // 把num[i]插入到左边i个元素内
        // 1.移走num[i]，用tmp记住它
        int tmp = num[i];
        // 2.从右向左的，把区间[0, i-1]内大于tmp的元素右移一格 
        int j = i;
        while(j > 0 && num[j-1] > tmp) {
            num[j] = num[j-1];
            j--;
        }
        // 3.把tmp填入空出来的位置
        num[j] = tmp;
    }
}
```
2. 希尔排序

**将待排序的一组元素按一定间隔分为若干个序列，分别进行插入排序。开始时设置的“间隔”较大，在每轮排序中将间隔逐步减小，直到“间隔”为1，也就是最后一步是进行简单插入排序。**

    - 最好：O(n * logn)，步长不断二分。
    - 最坏：O(n * logn)
    - 平均：O(n * logn)
> 参考学习资料：[图解排序算法(二)之希尔排序](https://www.cnblogs.com/chengxiao/p/6104371.html)
```c++
void shell_sort(int arr[]) {
    int len = sizeof(arr) / sizeof(int);
    // 初始步数 
    int gap = len / 2;

    // 逐渐缩小步数 
    while(gap) {
        从第gap个元素开始遍历 -->
        for(int i = gap; i < len; i++) {
            // 逐步其和前面其他的组成员进行比较和交换 
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
```
### 冒泡排序
**对元素个数为len的待排序序列进行排序时，共进行 len-1 次循环。在第k次循环中，对从第 1 到第 len-k 个元素从前往后进行比较，每次比较相邻的两个元素，若前一个元素大于后一个元素，则两者互换位置，否则保持位置不变。这样一次循环下来，就把第 k 大的元素移动到第 len-k 个位置上，称为第k趟的冒泡。**
- 最好：O(n)，只需要冒泡一次数组就有序了。
- 最坏：O(n²)
- 平均：O(n²)
1. 冒泡优化第一版
```c++
void bubble_sort(int num[]) {
    int n = sizeof(num) / sizeof(int);
    // 依次处理区间[0, n-1], [0, n-2], [0, len-3], ... 
    for(int p = n - 1; p > 0; p--) {
        bool flag = false;
        // 每一轮循环，把区间[0, p]内最大的元素交换到区间尾部
        // 1.从左向右地，比较相邻的两个元素，如果大的在前，则交换
        for(int i = 0; i < p; i++) {
            if(num[i] > num[i+1]) {
                int temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
                flag = true;
            }
        }
        // 2.如果全程无交换，则跳出循环
        if(flag == false)
            break;
    }
}
```
2. 冒泡优化第二版
```c++
void bubble_sort(int num[]) {
    int len = sizeof(num) / sizeof(int);
    // 记录最后一次交换的位置
    int lastExchange_index = 0;
    // 无序数列的边界，每次比较字需要比到这里为止 
    int sortBorder = len - 1;
    
    for(int i = 0; i < len - 1; i++) {
        // 有序标记，每一轮的初始值都是true 
        bool flag = false;

        for(int j = 0; j < sortBorder; j++) {
            int tmp = 0;
            if(num[j] > num[j+1]) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;

                // 因为有元素进行交换，所以不是有序的，标记为false 
                flag = true;
                // 更新为最后一次交换元素的位置 
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

**鸡尾酒排序是冒泡排序的一种改进和变型 ，又称“双向冒泡排序”，鸡尾酒排序是从低到高然后从高到低来回排序（选出最大和最小项），比冒泡排序的效率稍微好一点，原因是冒泡排序只从一个方向进行比对(由低到高)，每次循环只移动一个项目。**

- 使用场景：大部分元素已经有序的情况
- 优点：能够在特定条件下，减少排序的回合数
- 缺点：代码量比冒泡多了一倍
- 最好：O(n)，顺序排列时
- 最差：O(n²)，逆序排序时
- 平均：O(n²)，当原始序列杂乱无序时
> 参考学习资料：[排序算法之鸡尾酒排序](https://blog.csdn.net/zhizhengguan/article/details/106906563)   
> [排序算法系列之鸡尾酒排序](https://blog.csdn.net/hlc246/article/details/81064951)   
> [（8）鸡尾酒排序 (Cocktail Sort/Shaker Sort)](https://www.w3cschool.cn/wqcota/ts3klozt.html)
```c++
void cocktail_sort(int arr[]) {
    int tmp = 0;
    for(int i = 0; i < arr.size() / 2; i++) {
        //  有序标记，每一轮的初始值都是true 
        bool isSorted = true;
        //  奇数轮，从左向右比较和交换 
        for(int j = i; j < arr.size() - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;

                // <!-- 有元素交换，所以不是有序的，标记为false 
                isSorted = false;
            }
        }

        //  将isSorted重新标记为true 
        isSorted = true;
        //  偶数轮，从右向左比较和交换 
        for(int j = arr.size() - i - 1; j > i; j--) {
            if(arr[j] < arr[j-1]) {
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;

                // <有元素交换，所以不是有序的，标记为false 
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

**采用左右双指针，第一次循环从right指针开始，让指针所指向的元素和基准元素作比较 -> 如果大于或等于pivot，则指针向左移动；如果小于pivot，则right指针停止移动，切换到left指针。**   
**轮到left指针行动，让指针所指向的元素和基准元素作比较 -> 如果小于或等于pivot，则指针向右移动；如果大于pivot。则left指针停止移动。**   
**这时让left和right指针所指向的元素进行交换。然后进入第2次循环，重新切换到right指针......**
```c++
int partition(int num[], int start_index, int end_index) {
    // 取第1个位置（也可以选择随机位置）的元素作为基准元素 
    int pivot = num[start_index];
    int left = start_index;
    int right = end_index;

    while(left != right) {
        // 控制right指针进行比较并左移 
        while(left < right && num[right] > pivot)
            right--;
        
        // 控制left指针进行比较并右移 
        while(left < right && num[right] <= pivot)
            left++;
        
        // 交换left和right指针所指向的元素 
        if(left < right) {
            int temp = num[left];
            num[left] = num[right];
            num[right] = temp;
        }
    }

    // pivot和指针重合点进行交换 
    num[start_index] = num[left];
    num[left] = pivot;

    return left;
}
void quick_sort(int num[], int start_index, int end_index) {
    // 递归结束条件：start_index大于或等于end_index时
    if(start_index >= end_index) {
        return;
    }

    // 得到基准元素位置
    int pivot_index = partition(num, start_index, end_index);

    // 根据基准元素，分成两部分进行递归排序
    quick_sort(num, start_index, pivot_index - 1);
    quick_sort(num, pivot_index + 1, end_index);
}
```
2. 单边循环法

**首先选定基准元素pivot。同时设置一个mark指针指向数列起始位置（这个mark指针代表小于基准元素的区域边界）。**   
**接下来，从基准元素的下一个位置开始遍历数组，如果遍历到的元素大于基准元素，就继续往后遍历；如果遍历到的元素小于基准元素，则需要做两件事：**
- **①把mark指针右移1位（因为小于pivot的区域边界增大二楼1）；**   
- **②让最新遍历到的元素和mark指针所在位置的元素交换位置（因为最新遍历的元素归属于小于pivot的区域）。**

递归实现：
```c++
int partition(int num[], int start_index, int end_index) {
    // 取第1个位置（也可以选择随机位置）的元素作为基准元素 
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
    // 递归结束条件：start_index大于或等于end_index时 
    if(start_index >= end_index) {
        return;
    }

    // 得到基准元素位置 
    int pivot_index = partition(num, start_index, end_index);

    // 根据基准元素，分成两部分进行递归排序 
    quick_sort(num, start_index, pivot_index - 1);
    quick_sort(num, pivot_index + 1, end_index);
}
```
- 非递归实现：(待完善)
```c++
void quick_sort(int num[], int start_index, int end_index) {
    // 用一个集合栈来代替递归的函数栈
    Stack<>
}
void partition(int num[], int start_index, int end_index) {
    //  取第1个位置（也可以选择随机位置）的元素作为基准元素
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
### 快速选择（待完善）
其实快速选择法就是一种基于快速排序的选择方法，是一个典型的分治算法   
**我们知道快排的划分函数每次执行完后都能将数组分成两个部分，小于等于分界值 pivot 的元素的都会被放到数组的左边，大于的都会被放到数组的右边，然后返回分界值的下标。与快速排序不同的是，快速排序会根据分界值的下标递归处理划分的两侧，而这里我们只处理划分的一边。**
- 分解： 将数组 a[left⋯right] 「划分」成两个子数组 a[left⋯q−1]、a[q+1⋯right]，使得 a[left⋯q−1] 中的每个元素小于等于 a[q]，且 a[q] 小于等于 a[q+1⋯right] 中的每个元素。其中，计算下标 q 也是「划分」过程的一部分。
- 解决： 通过递归调用快速排序，对子数组 a[left⋯q−1] 和 a[q+1⋯right] 进行排序。
- 合并： 因为子数组都是原址排序的，所以不需要进行合并操作，a[left⋯right] 已经有序。
- 上文中提到的 「划分」 过程是：从子数组 a[left⋯right] 中选择任意一个元素 x 作为主元，调整子数组的元素使得左边的元素都小于等于它，右边的元素都大于等于它， x 的最终位置就是 q。
```c++
int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
```
> [面试题 17.14. 最小K个数](https://leetcode-cn.com/problems/smallest-k-lcci/)（用快选重做一遍）   
> [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)（用快选重做一遍）   
> [LeetCode习题传送](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/partitionfen-er-zhi-zhi-you-xian-dui-lie-java-dai-/)
### 归并排序
**将大小为n的序列看成n个长度为1的子序列，接下来将相邻子序列两两进行归并操作，形成n/2（+1）个长度为2（或1）的有序子序列；然后再继续进行相邻子序列两两归并操作，循环直到剩下1个长度为n的序列。**
- 最好：O(n * logn)
- 最坏：O(n * logn)
- 平均：O(n * logn)
```c++
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
### 堆排序（待完善）
堆的应用：
- 求TopK的问题：给一个无序的数组，长度为N，  请输出最小 （或最大）的K个数。
> [拜托，面试别再问我TopK了！！！](https://mp.weixin.qq.com/s/FFsvWXiaZK96PtUg-mmtEw)
- 求中位数问题

堆排序的思路：   
**将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆。如此反复执行，便能得到一个有序序列了。**
- ①构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。   
- ②将堆顶元素与末尾元素进行交换，使末尾元素最大。然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。如此反复进行交换、重建、交换。
```c++
void swap(int arr[], int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
void adjustHeap(int arr[], int i, int length) {
    int tmp = arr[i]; // 先取出当前元素i
    // 从 i 结点的左子结点开始，也就是 2i+1 处开始
    for(int k = i * 2 + 1; k < length; k = k * 2 + 1){
        // 如果左子结点小于右子结点，k 指向右子结点
        if(k + 1 < length && arr[k] < arr[k+1]){
            k++;
        }
        // 如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
        if(arr[k] > tmp){
            arr[i] = arr[k];
            i = k;
        } else {
            break;
        }
    }
    arr[i] = tmp;//将temp值放到最终的位置
}
void heap_sort(int arr[]) {
    // 1.构建大顶堆
    // 从最后一个非叶子结点开始，从下至上，从右至左调整结构
    for(int i = arr.size() / 2 - 1; i >= 0; i--){
        adjustHeap(arr, i, arr.size());
    }
    // 2.交换堆顶元素与末尾元素 + 调整堆结构
    for(int j = arr.size() - 1; j > 0; j--){
        swap(arr, 0, j); // 将堆顶元素与末尾元素进行交换
        adjustHeap(arr, 0, j); // 重新对堆进行调整
    }
}
```
> [数据结构与算法：学习堆相关算法](https://blog.csdn.net/xiaolinnulidushu/article/details/104629479)   
> [图解排序算法(三)之堆排序](https://www.cnblogs.com/chengxiao/p/6129630.html)
### 计数排序
**①新建一个数组，长度为无序数组的 最大值-最小值+1 ，全部值为0；**   
**②以无序数组的最小值作为一个偏移量，用来计算整数在计数数组中的下标：遍历无序数组，得到每一个元素，减去偏移量后得到一个值，在计数数组中对应该值的下标的元素+1；**   
**③遍历完无序数组后，计数数组中每一个下标位置+偏移量的值代表无序数列中对应整数出现的次数；**   
**④有了这个统计结果后，排序就很简单了。直接遍历计数数组，输出该数组元素的下标值（这里已经将无序数组的元素从小到大排序好了，因为下标正是从小到大的），元素的值是几，就输出几次（无序数组中有重复的元素就可以随之输出）。**
- 最好：O(n + k)，k是最大值和最小值的差
- 平均：O(n + k)
- 最坏：O(n + k)
```c++
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
**①创建桶，并确定每一个桶的区间范围【（最大值 - 最小值） / 桶的数量 】；**   
**②遍历原始数列，计算每个元素应该放在哪个桶，将元素插入排序到对应桶内；③遍历所有的桶，输出所有元素。**
- 最好：O(n)，每个数都在分布在一个桶里，这样就可以省略将数插入排序到桶里的时间(类似于计数排序以空间换时间)。
- 最坏：O(n²)，所有的数都分布在一个桶里
- 平均：O(n + k)，k表示桶的个数
```c++
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
### 基数排序（待完善）
**①找出无序数组的最大值，求出位数x，这就决定要分x次桶。（如果是数字，就分10个桶；如果是大小写字母，就分52个桶）。**   
**②先按最低位数找元素，并放进对应桶（该位数是n，就放进n号桶），全部元素进对应桶之后，按小桶先出、大桶后出；然后按下一个位数找位数，进桶...**   
**③分x次桶之后，全部元素出桶，就已经按从小到大排序好了。**
```c++
void radix_sort(int arr[]) {
    //  int max = *max_element(arr, arr.end()); 
    int max_index = 0;
    while(max_index) {
        max_index++;
        max /= 10;
    }
}
```