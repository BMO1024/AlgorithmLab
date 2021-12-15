### 概论

1. **算法的五个特征：输入，输出，确定性，能行性，有穷性**

2. 空间复杂度：

   ①$S(p)=c+S_p$，$c$为常量（实例无关），$S_p$为可变部分，一般只考虑后者

   ②对递归算法还需分析递归调用的深度和实例特征的关系

3. **时间复杂度：**

   ①**操作计数**

   ②**最好、最坏和平均情形时间复杂度**

   ③**步计数**：s/e, Frequency, Total Steps

4. **渐近分析：**

   $O$：$\lim _{n\to \infty}|\frac{f(n)}{g(n)}|=c,0\leq c<\infty\iff f(n)=O[g(n)]$

   $\Omega$：$\lim _{n\to \infty}|\frac{f(n)}{g(n)}|=c,0<c\leq\infty\iff f(n)=\Omega [g(n)]$

   $\Theta$：$\lim _{n\to \infty}|\frac{f(n)}{g(n)}|=c,0<c<\infty\iff f(n)=\Theta [g(n)]$

### 解递归方程

1. 伪代码

2. **递归树**（迭代展开）

3. **替代法**

4. **Master方法**：$T(n)=aT(\frac n b)+f(n)$

   ①$f(n)=O(n^{\log _ba-\varepsilon})(\varepsilon>0)\implies  T(n)=\Theta(n^{\log _ba})$

   ②$f(n)=\Theta(n^{\log _ba}\lg^kn)(k\geq 0)\implies  T(n)=\Theta(n^{\log _ba}\lg^{k+1}n)$

   ③$f(n)=\Omega(n^{\log _ba+\varepsilon})(\varepsilon>0),af(\frac nb)\leq cf(n)(0<c<1)\implies  T(n)=\Theta(f(n))$

### 分治算法

1. **基本思想：**

   ①分：将问题分成多个子问题

   ②治：递归地解决每个子问题

   ③合：将子问题的解合并成原问题的解

2. **找伪币问题**：$T(n)=\Theta(\lg n)$

3. 计算$a^n$：$a^n=\begin{cases}a^{\frac n2}a^{\frac n2},&\text{if $n$ is odd} \\            a^{\frac {n-1}2}a^{\frac {n-1}2}a, & \text{if $n$ is even} \\    \end{cases},T(n)=\Theta(\lg n)$

4. 求Fibonacci数：$\begin{bmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{bmatrix}=\begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}^n,T(n)=\Theta(\lg n)$ 

5. **金块问题（最大-最小问题）**：$T(n)=\frac{3n}2-2  $

6. 大整数乘法：$XY=2^nAC+2^{\frac n2}((A-B)(D-C)+AC+BD)+BD=2^nAC+2^{\frac n2}((A+B)(C+D)-AC-BD)+BD,T(n)=\Theta(n^{\lg 3})$

7. 矩阵乘法：Strassen‘s矩阵乘法，$T(n)=\Theta(n^{\lg 7})$

8. 超大规模集成电路版图设计

9. 残缺棋盘覆盖问题：$n=4^k,T(n)=\Theta(n)$

10. 归并排序：最坏复杂度$\Theta(n\lg n)$，平均复杂度$\Theta(n\lg n)$

11. **快速排序**：最坏复杂度$\Theta(n^2)$，平均复杂度$\Theta(n\lg n)$

12. **选择问题**：

    ①最坏复杂度$\Theta(n^2)$，最好复杂度$\Theta(n)$

    ②算法改进：支点选取“中间的中间”，时间复杂度$\Theta(n)$

13. 最近点对问题：$T(n)=\Theta(\lg n)$

14. 循环赛日程安排

15. **逆序数问题（补充）**：$T(n)=\Theta(\lg n)$

### 贪心算法

1. 贪心选择性质和最优子结构性质

2. 主要特点：不回溯，局部优化，最大增量，需要正确性证明（数学归纳法和交换论证）

3. 找零问题

4. 活动安排问题：以活动完成时间的非减序排列，每次总是选择具有最早完成时间的相容活动加入集合A中。时间复杂度为$\Theta(n\lg n)$。

5. 机器调度：以任务起始时间的非减序排列，若有“旧”机器可用，则将任务分配给它，否则分配给一台“新”机器。使用最小堆储存“旧”机器的最早可用时间。时间复杂度为$\Theta(n\lg n)$。

6. 货箱装船问题：从剩下的货箱中选择重量最小的货箱

7. **0/1背包问题：k-优化算法**

8. 哈夫曼编码问题：$T(n)=\Theta(\lg n)$

9. 拓扑排序：每次任取一入度为0的顶点放入拓扑序列中，时间复杂度为$\Theta(n^2)$（使用邻接矩阵）或$\Theta(n+e)$（使用邻接表）

10. 最短路径问题（正确性证明）：

    ①**Dijkstra's算法**：非负权，单源复杂度$O(e+n\lg n)$，多源复杂度$O(ne+n^2\lg n)$

    对于无权图，可以用FIFO队列代替优先级队列，时间复杂度降为$O(e+n)$

    ②Bellman-Ford算法：带负权，单源复杂度$O(ne)$，多源复杂度$O(n^2e)$或$O(n^4)$

11. 最小生成树（正确性证明）：

    ①Kruskal's算法：每次选择权值最小且与以前选择的边不构成环路的边，复杂度$O(n+e\lg e)$

    ②Prim's算法：每次连接着已选择的边的某一个节点且权值最小的边，复杂度$O(e+n\lg n)$

12. 二分覆盖问题：贪心算法为启发式，不保证找到最优解

    二维数组存储：邻接矩阵$O(|A|^2+n^2)$，邻接表$O(|A|^2+n+e)$

    最大堆存储：邻接矩阵$O(n^2)$，邻接表$O(n+e)$

13. **连续背包问题**：按价值密度递减顺序装入物品，正确性证明

14. 渴婴问题（补充）：与连续背包问题相似

13. **任务执行问题（补充）**：从剩下的任务中选择时间最少的任务，正确性证明

### 动态规划算法

1. 优化原理

2. 多段图最短路径问题：$c(i)=min_{j\in A(i)}\{c(j)+cost(i,j)\},c(n)=0$

3. **0/1背包问题**：

   ①递归实现：初始条件
   $$
   \begin{equation}
       f(n,y)=
      \begin{cases}
      p_n&y\geq w_n\\
      0&0\leq y<w_n
      \end{cases}
     \end{equation}
   $$
   状态转移方程
   $$
   \begin{equation}
       f(i,y)=
      \begin{cases}
      max\{f(i+1,y),f(i+1,y-w_i)+p_i\}&y\geq w_i\\
      f(i+1,y)&0\leq y<w_i
      \end{cases}
     \end{equation}
   $$
   时间复杂度$T(n)=O(2^n)$

   ②迭代实现：空间复杂度$\Theta(nc)$，求解的时间复杂度$\Theta(2^n)$，回溯的时间复杂度为$\Theta(n)$

   ③**元组法实现**

4. 旅行商问题：$g(i,S)=min_{j\in S}\{c_{i,j}+g(j,S-\{j\})\},g(i,\empty)=c_{i,1}$，时间复杂度$\Theta(n^22^n)$

5. **矩阵乘法链**：

   $c(i,i)=0$

   $c(i,i+1)=r_ir_{i+1}r_{i+2},kay(i,i+1)=i$

   $c(i,j)=min_{i\leq k<j}\{c(i,k)+c(k+1,j)+r_ir_{k+1}r_{j+1}\}$，$kay(i,j)$为达到最小值时的$k$

   迭代计算空间复杂度$O(q^2)$，时间复杂度$\Theta(q^3)$

6. 所有顶点对最短路径问题：$c(i,j,k)=min\{c(i, j, k-1), c(i, k, k-1)+c(k, j, k-1)\}$ 

   递归计算时间复杂度$\Theta(n^23^n)$，迭代计算时间复杂度$\Theta(n^3)$

7. 不交叉网的子集：

   初始条件
   $$
   \begin{equation}
       size(1,j)=
      \begin{cases}
      0&j<C_1\\
      1&j\geq C_1
      \end{cases}
     \end{equation}
   $$
   状态转移方程
   $$
   \begin{equation}
       size(i,j)=
      \begin{cases}
      max\{size(i-1,j),size(i-1,C_i-1)+1\}&j\geq C_i\\
      size(i-1,j)&j<C_i
      \end{cases}
     \end{equation}
   $$
   迭代计算时间复杂度$O(n^2)$

8. **最长公共子序列问题**：
   $$
   \begin{equation}
       c(i,j)=
      \begin{cases}
      0&\text{i=0 or j=0}\\
      c(i-1,j-1)+1&x[i]=y[j]\\
      max\{c(i-1,j),c(i,j-1)\}&\text{otherwise}
      \end{cases}
     \end{equation}
   $$

9. **子集和数问题（补充）**

10. 编辑距离问题（补充）

11. **装配线调度问题（补充）**

12. 项目安排问题（补充）

13. **0/1/2背包问题（补充）**

### 回溯算法

1. 解空间树
2. 状态空间树：活结点，死结点，E-结点
3. 限界函数
4. n-皇后问题
5. **子集和数问题**
6. **0/1背包问题**
7. 旅行商问题
8. **货箱装船问题**
9. 最大完备子图问题
10. 顶点覆盖问题（补充）
11. 机器设计问题（补充）

### 分支限界算法

1. 活结点表：FIFO，LIFO，优先级队列
2. LC分支限界算法
3. **0/1背包问题**
4. **带截止期的作业调度问题**
5. 旅行商问题
6. **货箱装船问题**
7. 顶点覆盖问题（补充）
8. 机器设计问题（补充）

### NP-完全问题

1. 易解问题，难解问题，不可解问题
2. 问题难解的因素：决策问题与优化问题，输入实例的长度，非确定性算法
3. **P类问题，NP类问题，多项式规约，NP-hard问题，NPC问题**