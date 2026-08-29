# 算法基础指南

## 一、算法概述

### 1.1 什么是算法

算法是解决特定问题的一系列步骤，具有以下特性：
- **有穷性**: 执行有限步骤后终止
- **确定性**: 每一步都有明确的定义
- **可行性**: 每一步都可以执行
- **输入**: 有零个或多个输入
- **输出**: 有一个或多个输出

### 1.2 时间复杂度

衡量算法运行时间随输入规模增长的变化：

| 复杂度 | 名称 | 示例 |
|--------|------|------|
| O(1) | 常数时间 | 数组访问 |
| O(log n) | 对数时间 | 二分查找 |
| O(n) | 线性时间 | 遍历数组 |
| O(n log n) | 线性对数时间 | 快速排序、归并排序 |
| O(n²) | 平方时间 | 冒泡排序、选择排序 |
| O(2ⁿ) | 指数时间 | 递归斐波那契 |

### 1.3 空间复杂度

衡量算法所需内存空间：
- O(1): 常数空间
- O(n): 线性空间
- O(n²): 平方空间

## 二、排序算法

### 2.1 冒泡排序

**原理**: 重复遍历数组，比较相邻元素，交换顺序错误的元素。

**时间复杂度**: O(n²)

**优点**: 简单易实现，稳定排序

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

### 2.2 选择排序

**原理**: 每次从未排序部分选出最小元素，放到已排序部分的末尾。

**时间复杂度**: O(n²)

**优点**: 交换次数少

```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
```

### 2.3 插入排序

**原理**: 每次将一个元素插入到已排序部分的正确位置。

**时间复杂度**: O(n²)，但在小规模数据或近乎有序数据上效率较高。

```c
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
```

### 2.4 快速排序

**原理**: 选择基准元素，将数组分成两部分，左边小于基准，右边大于基准，递归排序。

**时间复杂度**: 平均O(n log n)，最坏O(n²)

**优点**: 实际性能好，应用广泛

```c
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
```

## 三、查找算法

### 3.1 顺序查找

**原理**: 逐个检查数组元素，直到找到目标。

**时间复杂度**: O(n)

```c
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
```

### 3.2 二分查找

**原理**: 在有序数组中，每次比较中间元素，缩小查找范围。

**时间复杂度**: O(log n)

```c
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
```

## 四、深度优先搜索（DFS）

### 4.1 什么是DFS

深度优先搜索是一种图遍历算法，从起点出发，尽可能深地访问每个分支，直到无法继续再回溯。

**特点**:
- 使用栈（Stack）或递归实现
- 探索到最深处再回溯
- 适合解决连通性、路径问题

### 4.2 递归实现

```c
void dfs(int node, int visited[], int graph[][MAX_N], int n) {
    visited[node] = 1;
    printf("%d ", node);
    
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, visited, graph, n);
        }
    }
}
```

### 4.3 非递归实现（栈）

```c
void dfsIterative(int start, int graph[][MAX_N], int n) {
    int visited[MAX_N] = {0};
    int stack[MAX_N], top = -1;
    
    stack[++top] = start;
    visited[start] = 1;
    
    while (top >= 0) {
        int node = stack[top--];
        printf("%d ", node);
        
        for (int i = n-1; i >= 0; i--) {
            if (graph[node][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}
```

### 4.4 DFS应用场景

- 图的连通性检测
- 拓扑排序
- 迷宫求解
- 树的遍历（前序、中序、后序）
- 寻找路径

## 五、广度优先搜索（BFS）

### 5.1 什么是BFS

广度优先搜索是一种图遍历算法，从起点出发，逐层访问所有相邻节点。

**特点**:
- 使用队列（Queue）实现
- 按层次顺序访问
- 适合解决最短路径问题（无权图）

### 5.2 队列实现

```c
void bfs(int start, int graph[][MAX_N], int n) {
    int visited[MAX_N] = {0};
    int queue[MAX_N], front = 0, rear = 0;
    
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
```

### 5.3 BFS应用场景

- 无权图最短路径
- 图的连通性检测
- 层序遍历（树）
- 迷宫最短路径
- 社交网络好友推荐

### 5.4 DFS vs BFS

| 特性 | DFS | BFS |
|------|-----|-----|
| 数据结构 | 栈 | 队列 |
| 遍历方式 | 深度优先 | 广度优先 |
| 空间复杂度 | O(h) | O(n) |
| 最短路径 | 不保证 | 保证（无权图） |
| 适用场景 | 连通性、路径搜索 | 最短路径、层序遍历 |

## 六、图的表示

### 6.1 邻接矩阵

```c
int graph[MAX_N][MAX_N]; // graph[i][j] = 1表示i和j相连
```

### 6.2 邻接表

```c
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node *adj[MAX_N]; // adj[i]指向与i相连的节点链表
```

## 七、树的遍历

### 7.1 二叉树结构

```c
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
```

### 7.2 前序遍历（根-左-右）

```c
void preorder(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
```

### 7.3 中序遍历（左-根-右）

```c
void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
```

### 7.4 后序遍历（左-右-根）

```c
void postorder(TreeNode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
```

### 7.5 层序遍历（BFS）

```c
void levelOrder(TreeNode *root) {
    if (root == NULL) return;
    
    TreeNode *queue[MAX_N];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode *node = queue[front++];
        printf("%d ", node->data);
        
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}
```

## 八、常用算法模板

### 8.1 递归模板

```c
int recursive(int n) {
    if (n <= 1) return base_case;
    return recursive(n-1) + ...;
}
```

### 8.2 回溯模板

```c
void backtrack(int state[], int step) {
    if (step == target) {
        记录结果;
        return;
    }
    
    for (每个可选选项) {
        选择当前选项;
        backtrack(state, step+1);
        撤销选择;
    }
}
```

### 8.3 动态规划模板

```c
int dp[MAX_N];

int solve(int n) {
    dp[0] = base_case_0;
    dp[1] = base_case_1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]; // 根据具体问题
    }
    
    return dp[n];
}
```

## 九、算法学习建议

1. **从基础开始**: 先掌握排序和查找算法
2. **理解原理**: 不要死记硬背，理解算法的思想
3. **动手实现**: 自己写代码，不要只看
4. **分析复杂度**: 学会分析时间和空间复杂度
5. **多做练习**: 在LeetCode等平台刷题
6. **模拟过程**: 手动模拟算法执行过程
7. **对比学习**: 对比不同算法的优缺点

## 十、推荐练习题

### 排序类
1. 实现冒泡排序、选择排序、插入排序
2. 实现快速排序、归并排序
3. 排序稳定性分析

### 查找类
1. 实现二分查找
2. 二分查找变种（第一个等于、最后一个等于、大于等于等）

### DFS/BFS类
1. 图的遍历（DFS和BFS）
2. 二叉树的四种遍历
3. 迷宫求解
4. 岛屿数量（连通性问题）
5. 最短路径问题