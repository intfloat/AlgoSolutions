| 题目 | 基本思想 | 分类 |
|--------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------|
|[面积最大的全1子矩阵](http://ac.jobdu.com/problem.php?pid=1497) | 枚举右下角的位置，从右到左扫描，不断更新最大面积，复杂度O(N^3)，又加了一点剪枝，基本卡时限AC，通过枚举瓶颈边，可以实现O(N^2)的时间复杂度，类似于leetcode中求直方图最大面积的题目 | 枚举 |
|[项目安排](http://ac.jobdu.com/problem.php?pid=1499) | 一个非常类似的题目是要求完成尽可能多的项目数，可以采用贪心完成。添加报酬之后，对于每一个项目，要么不做，此时最优值就是前一个项目截止时间所对应的最优值；要么做该项目，最优值是该项目的报酬加上在这一项目开始时间的最优报酬，动态规划O(nlgn)可解 | 动态规划 |
|[最大值最小化](http://ac.jobdu.com/problem.php?pid=1502) | 二分搜索，对于每一个可能的值，通过贪心策略进行验证即可 | 二分；贪心 |
|[寻找表达式](http://ac.jobdu.com/problem.php?pid=1498) | 暴力枚举每一种可能的情形，最后3^14的大数据挂了，于是耍流氓打表了…… | 枚举，递归 |
|[狼抓兔子](http://www.lydsy.com/JudgeOnline/problem.php?id=1001) | 题目要求图的最小割，但数据范围过大，用通常的算法求最小割会超时+超内存；平面图的最小割问题可以转化为对偶图的最短路问题，通过重构图，用spfa算法求最短路即可。 | spfa最短路；平面图最小割 |
|[轮状病毒](http://www.lydsy.com/JudgeOnline/problem.php?id=1002) | 至今未想清楚递推公式究竟是怎么来的。。。| 大整数；递推；生成树计数 |
|[物流运输](http://www.lydsy.com/JudgeOnline/problem.php?id=1003) | 对于每一天，枚举前面第一个发生路线变化的节点，进行状态转移，dp(n)=dp(j)+cost(j+1,n)*(n-j)+K,最后需要减掉一个多余的K，cost数组可以通过最短路算法预先计算出来 | 动态规划；最短路 |
|[越狱](http://www.lydsy.com/JudgeOnline/problem.php?id=1008) | 快速幂加上简单的组合数学 | 组合数学 |
|[Cards](http://www.lydsy.com/JudgeOnline/problem.php?id=1004) | 利用Polya定理来进行计数，分别考虑每一个置换，对每一个置换而言，同一个置换组中的节点必须被染成相同的染色，由于题目中对颜色之和做了限制，还需要结合动态规划求解方案数；最后，在模域除以一个数，需要乘以该数的逆元。 | 组合数学；动态规划；快速幂 |
|[二进制中1的个数](http://ac.jobdu.com/problem.php?pid=1513) | __builtin_popcount搞定 | 水 |
|[把数组排成最小数](http://ac.jobdu.com/problem.php?pid=1504) | 不能简单按照字典序，注意一个字符串为另一个字符串前缀的情形 | 排序 |
|[明明的烦恼](http://www.lydsy.com/JudgeOnline/problem.php?id=1005) | 生成树计数的问题，根据prufer编码（第一次听说这种东西……），有标记的生成树跟一个长度为n-2的序列是一一对应的，因此生成树计数就转化成了组合计数的问题，首先选出有度数限制的顶点，然后根据多项式系数求解。由于涉及高精度运算，python是比较好的选择 | 生成树计数；组合数学；高精度 |
|[水平可见直线](http://www.lydsy.com/JudgeOnline/problem.php?id=1007) | 注意分析一条直线在什么情况下会被掩盖，将直线按照斜率升序排列，用栈来维护，每遇到一条直线，就从栈中取出两条直线计算交点，如该直线在交点以上，则将原来的直线覆盖，反之则没有覆盖，同时还需注意两条直线斜率相同的情形。 | 栈；排序；几何 |
|[神奇的国度](http://www.lydsy.com/JudgeOnline/problem.php?id=1006) | graph coloring在一般情况下是NP问题，但对于弦图有多项式算法。于是，先找出弦图中的完美消除序列，在逆向进行标记染色。第一次做和弦图相关的题目，长见识…… | 弦图；图染色；最大势算法 |
|[玩具装箱](http://www.lydsy.com/JudgeOnline/problem.php?id=1010) | 朴素的动态规划复杂度为O(N^2)，会超时；注意到决策具有单调性，于是可以二分更新决策区间，用双端队列来进行维护。神题啊……折腾了一天…… | 动态规划；双端队列；二分 |
|[最大数](http://www.lydsy.com/JudgeOnline/problem.php?id=1012) | 维护一个单调下降的队列，每次查询采用二分查找 | 单调队列；二分 |
|[GT考试](http://www.lydsy.com/JudgeOnline/problem.php?id=1009) | 定义状态f(i, j)为长度为i的字符串最后j个字符为模板的前j个字符，f(i+1, j)和f(i, j)之间可以构造一个固定的转移矩阵，不管i的取值是多少，于是可以利用矩阵的快速幂来进行求解 | 动态规划；矩阵快速幂；字符串计数 |
|[最长上升子序列](http://ac.jobdu.com/problem.php?pid=1533) | 最长上升子序列可以通过O(N^2)的动态规划算法求解，但事实上还有O(nlgn)的解法，可以借助于二分查找实现，不过用stl里面的set更方便 | 动态规划 |
|[Spheres](https://www.hackerrank.com/contests/infinitum-jun14/challenges/spheres) | 首先利用物理上的相对运动把加速度归约到一个球上（高中物理没白学啊……），然后列出时间t时的距离函数，通过对t求导最小化该函数得到两个球的最近距离，如果该距离小于两球的半径之和，则说明会碰撞，反之则不会发生碰撞。 | 几何；求最值 |
|[星球大战](http://www.lydsy.com/JudgeOnline/problem.php?id=1015) | 逆向思考，于是原问题转化为不断向图中加边和顶点，快速求出连通分量数目的问题，并查集可解。同时，由于顶点的数目较多，采用前向星表示更为高效，计数排序可以实现边的线性时间排序。 | 并查集；图论；前向星 |
|[最小生成树计数](http://www.lydsy.com/JudgeOnline/problem.php?id=1016) | 要求对最小生成树的选边过程有一个比较深刻的了解，不同最小生成树的边权集合是相同的，只是对于特定长度的边，选哪些组合并不确定。用位运算枚举，根据乘法原理可解。 | 最小生成树；并查集；位运算 |
|[球形空间产生器](http://www.lydsy.com/JudgeOnline/problem.php?id=1013) | 根据球心定义，可以列出n个独立的方程，其中的平方项相互抵消，变成了一个线性方程，高斯消元法求解。 | 几何；高斯消元法 |
|[How many integers can you find](http://acm.hdu.edu.cn/showproblem.php?pid=1796) | 原子集合定义：可以被第i个数整除的数的个数；利用容斥原理可解，枚举是借助于位运算比较方便，当然，深搜也是可以的。 | 容斥原理；位运算 |
|[逃生](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?pid=1001&cid=525) | CLJ坑了几百人。。注意不是求字典序最小的拓扑顺序！不是字典序最小！不是字典序最小！ | 图论 |
|[DZY Loves Sequences](http://codeforces.com/problemset/problem/446/A) | 枚举将要被改变的那个数字的位置，把它之前的最长上升序列和之后的最长上升序列拼接起来即可，需要注意边界条件。 | 枚举 |
|[DZY Loves Modification](http://codeforces.com/problemset/problem/446/B) | 通过简单证明可知，行和列之间的操作顺序是可以交换的，因此可以枚举有i个行操作，剩余的均为列操作，对于所有的行操作而言，显然要遵循贪心的选择过程，为了提高时间效率，可以用堆来进行维护。 | 贪心；最大堆 |
|[Jzzhu and Cities](http://codeforces.com/problemset/problem/449/B) | 单源最短路径的改编版本，在一个图中，为了维持到一个顶点的最短距离保持不变，事实上只需要n-1条边，对应于Dijkstra算法中每个顶点最后被更新的边；同时为了提高时间效率，同样需要维护堆，否则O(N^2)会超时 | 单源最短路径；堆 |
|[Jzzhu and Chocolate](http://codeforces.com/problemset/problem/449/A) | 假设在列上切了i刀，不难列出相应的最小面积表达式，为了最大化最小面积，只需要取两个边界值即可 | 贪心 |
|[Jzzhu and Apples](http://codeforces.com/problemset/problem/449/C) | 枚举每一个素数，它只能是与其倍数构成pair，如果这样的数共有偶数个，可以全部匹配，如果是奇数个，则需要剔除一个，将其放到最后的一个公共空间里，因此剔除2*p最合适 | 构造性算法 |
|[K尾相等数](http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=212) | 两个幂次对1000取模的结果应该相同，一旦碰到重复的结果以后就会不断重复，因此不断增加幂指数直到出现环 | 数论 |
|[InvariantSets](TopCoder SRM 628 div2 1000) | 注意到一个环中的点，要么全选，要么全不选，因此可以缩点将原图转化为一个森林，然后再对每棵树利用动态规划计数 | 图论；组合计数；组合数学 |
|[BishopMove](TopCoder SRM 628 div2 250) | 很经典的小题目，嗯……奇偶性不同则不可达，在同一条对角线上则一步可达，否则需要两步| 观察规律…… |
|[BracketExpressions](TopCoder SRM 628 div2 500) | 题目的数据规模较小，可暴力枚举，对于每一种情况，用栈来验证是否符合格式要求 | 栈；枚举 |
|[受欢迎的牛](http://www.lydsy.com/JudgeOnline/problem.php?id=1051) | 一个有向图可以分成若干个强连通分量，其中至少有一个强连通分量无出边，如果这样的SCC数目大于1，则无解，等于1时进行计数即可，SCC的求解可以通过两次dfs，第一次求定点的拓扑序，第二次dfs求每个scc对应的编号 | 图论；强连通分量 |
|[猴子舞](http://soj.me/show_problem.php?pid=1297) | 抽象成数学问题，就是将N进行分解，并且得到的数的lcm最大，i分成j个圈作为状态，可以很自然看出动态规划的特点 | 数论；动态规划 |
|[大众比萨](http://acm.sdibt.edu.cn/JudgeOnline/problem.php?id=1133) | 经典的NP问题：可满足性问题。只能通过暴力求解，借助于位运算可以提高检验的效率 | 枚举；位运算 |
|[点在哪](http://acm.sdibt.edu.cn/JudgeOnline/problem.php?id=1404) | 水……鬼都会做 | 几何 |
|[DivisorsPower](TopCoder SRM 628 div1 250) | 注意到枚举n是没有希望的，而且也没有任何单调性能够让算法加速。但是可以枚举指数项，对于确定的幂指数，n可以通过二分确定，然后再通过因式分解判断是否合法 | 二分；枚举 |
|[CircuitsConstruction](TopCoder SRM 628 div1 500) | 题目所给的其实就是波兰表达式，要想最大化结果，只需要最大化一个运算符所覆盖的项数，这可以通过树的分治完成 | 递归；树形动态规划 |
|[GravityBomb](TopCoder SRM 200 div2 500) | 统计一下每列的X字符数目，取最小值，并进行消除 | 水题 |
|[WindowManager](TopCoder SRM 200 div2 900) | 模拟即可，但情况数目比较多，需要细心一点| 水题 |
|[FindPoint](https://www.hackerrank.com/challenges/find-point) | 对称点，不多说。。 | 水题 |
|[SherlockAndPlanes](https://www.hackerrank.com/challenges/sherlock-and-planes) | 判断四点是否共面，只需要看三个向量所构成的立体图形的体积是否为零，可通过一次叉积和一次点积完成 | 几何 |
|[Spheres](https://www.hackerrank.com/challenges/spheres) | 转化为相对运动，然后借助于叉积求出点到直线的最短距离，需要注意相对运动的方向是否是背离的方向，通过点积判断角度是否是钝角即可 | 几何 |
|[志愿者招募](http://www.lydsy.com/JudgeOnline/problem.php?id=1061) | 列出每一天所要满足的约束方程，相邻方程相减可以保证每个变量出现两次，于是把方程作为顶点，进行构图，求出最小费用最大流 | 最小费用最大流；图论；神题 |
|[Windy数](http://www.lydsy.com/JudgeOnline/problem.php?id=1026) | 进行动态规划，但是边界情况比较多，需要仔细设计状态以及状态之间的转移 | 动态规划 |
|[矩阵游戏](http://www.lydsy.com/JudgeOnline/problem.php?id=1059) | 首先观察到同一行或者同一列的元素是不可能同时对最终结果产生贡献的，并且如果两个点的横纵坐标都不相同，一定可以都对最终结果产生贡献。于是需要找到n个点，任意两个点的横纵坐标均不相同，“互斥”的特点刚好符合二分图的性质，匈牙利算法求解 | 二分图匹配；深度搜索；匈牙利算法 |
|[修车](http://www.lydsy.com/JudgeOnline/problem.php?id=1070) | 将每个技术人员节点分裂成n个，每个表示倒数第几个修车，构图，求最小费用流 | 最小费用流；图论 |
|[Courses](http://poj.org/problem?id=1469) | 二分图匹配，不多说。。 | 二分图匹配 |
|[树的最小高度](http://ac.jobdu.com/problem.php?pid=1536) | 问题的本质是求解树的直径，第一次广搜可以得到边界上的点，第二次广搜的结束点得到另一个边界上的点，最小高度就是半径的一半 | 图论；广搜 |
|[重叠的最长子串](http://ac.jobdu.com/problem.php?pid=1535) | Rabin-Karp绝对是神算法啊，搞个hash线性时间就可以完成字符串匹配，以后碰到字符串匹配的题目就都用它了。| 字符串匹配 |
|[买卖股票](http://ac.jobdu.com/problem.php?pid=1537) | 动态规划，不多说。。。 | 动态规划 |
|[数组中第K小的数](http://ac.jobdu.com/problem.php?pid=1534) | 很聪明的二分查找，对目标数字K进行二分，每次线性时间可以统计出小于等于K的数字的个数，然后决定走左分支还是右分支| 二分查找 |
|[Find The Shortest Common Superstring](http://acm.hdu.edu.cn/showproblem.php?pid=1841) | 和九度上的题目如出一辙，换了一个KMP匹配的解法，关键在于明白KMP算法在匹配失败时，指向模式串的指针恰好对应于最长的前缀。 | KMP|
|[建筑抢修](http://www.lydsy.com/JudgeOnline/problem.php?id=1029) | 按照截止时间进行排序，然后依次选择，如果不能选的话，想办法减小当前所用的时间，可用堆来高效实现 | 贪心；最小堆 |
|[Boredom](http://codeforces.com/problemset/problem/455/A) | 居然是用动态规划，一开始以为有多复杂，还是自己的状态定义有问题 | 动态规划 |
|[小约翰逊的游戏John](http://www.lydsy.com/JudgeOnline/problem.php?id=1022) | 普通Nim游戏的简单变形，取到最后一个算赢改成了算输。只需要对单个石子堆的情况进行特殊分析即可。 | 博弈 |
|[生日快乐](http://www.lydsy.com/JudgeOnline/problem.php?id=1024) | 和棋盘分割的问题比较相似，分别考虑横向和纵向的情形，递归求解。 | 递归 |
|[糖果传递](http://www.lydsy.com/JudgeOnline/problem.php?id=1045) | 纯数学问题，列出代价函数，规约为最小化一系列绝对值之和的问题，只需要取各个常数项的中位数。| 数学 |
|[互不侵犯King](http://www.lydsy.com/JudgeOnline/problem.php?id=1087) | 暴力枚举显然要挂，需要以行为状态进行状态转移，用位操作来表示各个状态之间的相容性| 基于状态压缩的动态规划 |
|[扫雷Mine](http://www.lydsy.com/JudgeOnline/problem.php?id=1088) | 关键在于注意到，每个格子只影响到相邻的三行，因此可以以行为状态进行转移，另外还需要记录当前行和下一行的雷放置情况 | 动态规划 |
|[圆上的整点](http://www.lydsy.com/JudgeOnline/problem.php?id=1041) | 神题啊……需要对勾股数有比较好的理解 | 数学；几何 |
|[硬币购物](http://www.lydsy.com/JudgeOnline/problem.php?id=1042) | 神题……先考虑没有数目限制情形下的方案，再根据数目上的限制采用容斥原理删除不符合要求的方案 | 动态规划；容斥原理 |
|[鬼谷子的钱袋](http://www.lydsy.com/JudgeOnline/problem.php?id=1192) | 构造出最优的策略，也就是以2为倍数递增选数，直至剩余的钱数少于要选的金币数目 | 水题 |
|[字符串加密cipher](http://www.lydsy.com/JudgeOnline/problem.php?id=1031) | 赤裸裸的后缀数组，求出所有字符串后缀的rank数组来，再花费线性时间便可以求得目标字符串 | 字符串后缀数组 |
|[理想的正方形](http://www.lydsy.com/JudgeOnline/problem.php?id=1047) | 和sliding window挺像的，利用决策单调性进行预计算，得到一个二维范围内的最值，然后再平方时间扫描得到结果 | 决策单调性 |
|[蜥蜴](http://www.lydsy.com/JudgeOnline/problem.php?id=1066) | “每次跳跃都会使高度减一”具有流网络的特征，因此对矩阵构建一个流网络，每个顶点一分为二，求解流网络的最大流 | 网络流；图论 |
|[排列perm](http://www.lydsy.com/JudgeOnline/problem.php?id=1072) | 看到字符串长度只有10，显然暴力枚举…… | 枚举 |
|[移动玩具](http://www.lydsy.com/JudgeOnline/problem.php?id=1054) | 把棋盘压缩成一个16位的整数，进行广度优先搜索即可 | 广搜 |
|[反素数](http://www.lydsy.com/JudgeOnline/problem.php?id=1053) | 列出素数表来，对每个素数可取的个数进行递归搜索即可，注意边界上的结果更新以及恰当剪枝 | 数论；递归 |
|[2月29日](http://hihocoder.com/problemset/problem/1148) | 用容斥原理随便搞搞就行了。。 | 数学 |
|[回文字符序列](http://hihocoder.com/problemset/problem/1149) | 和公共子序列计数本质上是一样的，分最开头的字母是否相等两种情况，注意减掉重复计算的部分 | 动态规划；组合计数 |
|[基站选址](http://hihocoder.com/problemset/problem/1150) | 首先两个坐标是互相独立的，然后把优化目标写出来，发现最优解就在用户的质心处，扫描小范围内的整数点网格可解。有人搞模拟退火，什么鬼。。 | 优化 |
|[彩色的树](http://hihocoder.com/problemset/problem/1156) | 很感人的一道题。。。就是如何高效维护树中的信息，每个节点只维护子节点信息，就可以实现O(1)查询和O(1)更新了 | 树 |
|[攻城略地](http://hihocoder.com/problemset/problem/1160) | 每个连通分量，只需要选择权重最小的顶点，并且一个连通分量删掉不影响连通性的多余边不会影响最终结果；如果还不够，就把其余顶点排序，从小到大选。。 | 图论 连通分量 |
|[质数相关](http://hihocoder.com/problemset/problem/1158) | 二部图最大独立点集，我太渣了。。。建立二部图，做最大匹配，总数减掉最大匹配的一半就是答案 | 二部图； 独立点集 |
|[Girls and Boys](poj.org/problem?id=1466) | 还是二部图最大独立点集，嗯。。 | 二部图 |
|[扑克牌](http://hihocoder.com/problemset/problem/1159) | 组合dp，感人肺腑不能多说。。 | 组合计数；动态规划 |
|[Cutting Banner](http://codeforces.com/problemset/problem/538/A) | 表述不清，第一次被别人成功hack，超级不爽。。 | 暴力枚举 |
|[Quasi Binary](http://codeforces.com/problemset/problem/538/B) | 对每一个非零位进行贪心构造，直到变成0 | 贪心 |
|[Tourists Notes](http://codeforces.com/problemset/problem/538/C) | 水题不想多说。。 | 贪心 |
|[Weird Chess](http://codeforces.com/problemset/problem/538/D) | 看上去很难，其实就是根据约束条件不断删除候选解 | 构造算法 |
|[Demiurges Play Again](http://codeforces.com/problemset/problem/538/E) | 博弈论相关，当轮到对手时，要选择所有可能的路径最优解中的最差解；当轮到自己时，选择所有可能路径中最优解的最优解，大概就是这样，比较绕。。 | 博弈论 |
|[A Heap of Heaps](http://codeforces.com/contest/538/problem/F) | 枚举显然超时，关键点在于一个节点的父节点只可能有平方根量级个，区间和维护的时候不要挨个更新，只更新两端，最后累加。 | 数学 数据结构 |
|[Remmarguts Date](http://poj.org/problem?id=2449) | 第一次写K短路，弱菜。。和最短路的A Star算法类似，只是把第K次出优先队列的值作为结果 | 图论； A Star |
|[Combination Lock](http://codeforces.com/problemset/problem/540/A) | 水题不多说。。 | 水 |
|[School Marks](http://codeforces.com/problemset/problem/540/B) | 贪心构造，满足中位数要求就不断填充临界值，一旦满足就只放最低分 | 贪心 |
|[Ice Cave](http://codeforces.com/problemset/problem/540/C) | 很不错的小题目，我智商太低。。关键是从一个完整点出发，只要相邻的有一个完整点，就可以回到原点，边界情况比较多 | 广度搜索；考智商 |
|[Bad Luck Island](http://codeforces.com/problemset/problem/540/D) | 感觉跟AI里面的markov decision process很像啊。。根据前一步的概率分布去计算下一步的概率分布直到稳定状态 | 概率；动态规划 |
|[Infinite Inversions](http://codeforces.com/problemset/problem/540/E) | 归并排序可以用来高效计算逆序数，但是这里序列无限长，所以只能分别计算更改部分的逆序数，和未更改的逆序数，最后加起来 | 分治法 |
|[Ultra-QuickSort](http://poj.org/problem?id=2299) | 经典的计算逆序数，不过刚知道原来还可以用树状数组搞，离散化的基本思想 | 树状数组 |
|[Mushroom Monster](https://code.google.com/codejam/contest/4224486/dashboard#s=p0) | 题意不是很清楚，找极端临界情况就行了 | 贪心 |
|[Haircut](https://code.google.com/codejam/contest/4224486/dashboard#s=p1) | 明显的二分，但比赛的时候我死活没想出来对什么进行二分。。。二分找到最小的已经有N个人已经完成或正在理发的时刻，智商是硬伤。。 | 二分 |
|[Logging](https://code.google.com/codejam/contest/4224486/dashboard#s=p2) | 神题。。。利用了凸包的性质：肯定有经过这个点的一条直线，使得其他所有点都在这条直线一侧。可能的直线数目无限多，但可以离散化，扫描有限条，对于每条直线，利用类似于旋转卡壳的思想，可以线性时间完成一轮扫描 | 几何 |
|[Counter Culture](https://code.google.com/codejam/contest/8224486/dashboard#s=p0) | 我是彻底给google跪烂了。。。考智商找规律啊。。观察到位数少的无论怎么翻转都不能有更多位，因此必须先变到9999...999这种，左半部分可以通过右半部分逐次加1并翻转得到（但左边只有一个打头1是特殊情况！），而且这就是最优方案；另外还得处理右半部分全零的特殊情况。。。 | 无他，赤裸裸考智商 |
|[GCD](http://acm.hdu.edu.cn/showproblem.php?pid=5223) | 从全1开始构造，从大到小扫描公约数，如果现有元素的公约数已经超过，则无解，否则把整个区间变成最小公倍数 | 贪心构造； 数学 |
|[Movie](http://acm.hdu.edu.cn/showproblem.php?pid=5214) | 只要求找出三个区间来，因此线性扫描，找到结束时间最早和开始时间最晚的区间，再扫描一遍看是否有中间区间即可 | 贪心 |
|[Game](http://acm.hdu.edu.cn/showproblem.php?pid=5218) | 像是博弈论跟约瑟夫环问题，想了想是动态规划，什么鬼。。。按照长度递增顺序进行迭代就行了 | 动态规划 |
|[Exploration](http://acm.hdu.edu.cn/showproblem.php?pid=5222) | 很好的一道题啊。。。先用并查集考虑无向边，再利用拓扑排序考虑有向边 | 并查集；拓扑排序 |
|[Noisy Neighbors](https://code.google.com/codejam/contest/8224486/dashboard#s=p1) | 智商余额不足。。国际象棋那种交错排列是比较优的方案，如果有很多非空元素，则需要从4到3到2进行枚举，针对行列数的奇偶性来计算，小中取小，边界情况很多。。。 | 拼智商找规律😢 |
|[Hiking Deer](https://code.google.com/codejam/contest/8224486/dashboard#s=p2) | 神啊。。考虑目标到达终点的时间与其他人所转的圈数，只有第一圈和第二圈之间会减一，其他时候都是加一，因此枚举时间点。对于大数据，注意到H是最优解的上界，因此用优先队列只考察前2H个事件。 | 拼智商 |
|[Segment](http://acm.hdu.edu.cn/showproblem.php?pid=5216) | 灰常具有迷惑性。。排序之后不满足严格单调则无解，更关键在于：每种排列的最优值都是一样的，所以根本不需要求期望值。。 | 概率；排列 |
|[Writing Code](http://codeforces.com/problemset/problem/543/A) | 赤裸裸动态规划，状态转移要聪明一点，O(1)完成转移 | 动态规划 |
|[Set of Strings](http://codeforces.com/problemset/problem/544/A) | 判断不相同的字母个数是否不少于k就行了 | 贪心 |
|[Sea and Islands](http://codeforces.com/problemset/problem/544/B) | gcj题目的超级简化版。。按照国际象棋那种方式放置就好了 | 贪心构造 |
|[Destroying Roads](http://codeforces.com/problemset/problem/543/B) | 其实不难啊，比赛的时候居然看错题意了摔！删掉最多边显然要保留最短路，再考虑两条路径可能重合的情形，数据规模不大，枚举重合的起点和终点即可。 | 最短路；图论 |
|[Remembering Strings](http://codeforces.com/contest/543/problem/C) | 数位dp，但是状态转移方程很不好想，到现在也有点糊涂。。 | 动态规划 |
|[Road Improvement](http://codeforces.com/contest/543/problem/D) | 折腾了我好几个小时的神题啊。。本来天真以为乘法逆元加树的动态规划随便搞搞就行，结果还有整除性导致逆元不存在的情况。。。只好对因子做分解，从父节点一层层向子节点传递 | 动态规划；树；组合计数 |
|[运输货物](http://hihocoder.com/contest/msbop2015round3/problem/1) | 从叶结点向父节点一层层传递，总是选择最早的可能时间，于是形象讲就是一大堆区间不断上浮。。复杂度具体也不好说，反正AC了。。 | 树；贪心 |
|[Tom and Paper](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=580&pid=1001) | 枚举面积的因子就行了 | 数学 |
|[Tom and Permutation](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=580&pid=1002) | 对于字典序，只要有个前缀构成单调性，后面的就可以随便排列了，根据这个性质构造状态转移方程 | 动态规划 |
|[Less Money, More Problems](https://code.google.com/codejam/contest/4244486/dashboard#s=p2) | 越发对自己的智商表示怀疑了。。。已有面值构成1到x之间的所有数值之后，添加x+1是最优结果，更小的只会缩短延长的区间，非常简洁的解答 | 贪心 |
|[Brattleship](https://code.google.com/codejam/contest/4244486/dashboard#s=p0) | 考虑找到目标的最坏情况就行 | 贪心 |
|[Typewriter Monkey](https://code.google.com/codejam/contest/4244486/dashboard#s=p1) | 万万没想到。。利用期望值的独立性质可以大大简化计算过程，cf上也有动态规划的解法 | 概率；动态规划 |
|[迎春舞会之三人组舞](https://vijos.org/p/1061) | 突然发现了这道两年之前没有AC的题目。。。按照位置进行状态转移，每个人只可能与最邻近的结合在一起，同时还要保证有足够个数的高个子 | 动态规划 |
|[Xiao Mings Hope](http://acm.hdu.edu.cn/showproblem.php?pid=4349) | 很神奇的一道题目，一行代码得答案。。。求对2取模结果为1的组合数的个数，低位为1则有两种选择，低位为0则只有一种选择，因此只需统计1的数目 | 组合计数 |
|[Saving Beans](http://acm.hdu.edu.cn/showproblem.php?pid=3037) | 计算从n+m中选择m个的组合数，关键是要在模域中计算，于是就有了lucas定理，我孤陋寡闻，第一次听说。。。 | 组合计数 |
|[Tom and Matrix](http://acm.hdu.edu.cn/showproblem.php?pid=5226) | 组合数学太渣。。。每一列的和原来是有解析表达式的。。然后把每一列用lucas定理算出来相加就可以了 | 组合计数 |
|[Googol](http://usaco.org/index.php?page=viewproblem2&cpid=552) | 很好的交互题。。。关键点在于如果右子树的大小确定，则左子树的根的左右子树中必定有一个大小确定，于是可以将复杂度降到对数级别 | 树 |
|[Palindromic Paths](http://usaco.org/index.php?page=viewproblem2&cpid=553) | 一看就是动态规划，但是状态表示不好想。。弱渣。。从对角线向两侧，按照金字塔状一层层向外递推，每一步递推常数可完成，滚动数组降低存储空间要求 | 动态规划 计数 |
|[Trapped in the Haybales](http://usaco.org/index.php?page=viewproblem2&cpid=554) | 我智商太低。。。如果两侧墙高超过区间长度则必定无解，反之则需要继续检验 | 贪心 考智商 |
|[Moo Cryption](http://usaco.org/index.php?page=viewproblem2&cpid=545) | 水题不多说。。 | 枚举 |
|[Bessie Get Even](http://usaco.org/index.php?page=viewproblem2&cpid=546) | 大概是初中数学的水平。。偶数个变量不用管，乘积为奇数要求每个因子都得是奇数，随便搞搞就差不多了。。 | 数学 |
|[Bessie Goes Moo](http://usaco.org/index.php?page=viewproblem2&cpid=549) | 上面问题的一个推广，关键点在于两个数只需要考虑在模7域中的值就行了，复杂度7**7 | 数学 |
|[Trapped in Haybales Silver](http://usaco.org/index.php?page=viewproblem2&cpid=550) | 枚举每一个可能变化的位置，注意到指针总是朝一个方向移动，因此线性扫描适用 | 双指针 |
|[Bessie Birthday Buffet](http://usaco.org/index.php?page=viewproblem2&cpid=551) | 看上去难，其实超级简单。。从一个递增序列中选一个最优子序列，只不过状态转移的代价需要计算图的最短路径得出 | 动态规划 宽搜 |
|[ZCC loves staight flush](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=582&pid=1001) | 同花顺就那么多，枚举一下，千万不要天真地排序。。 | 枚举 |
|[ZCC loves string](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=582&pid=1002) | 博弈。。先手胜只有两种情形：两个初始字符串相同；字符串的长度相加为奇数。其余情形均为后手胜 | 博弈 |
|[ZCC loves hacking](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=582&pid=1003) | naive的动态规划n^2会挂，关键点在于和为n的序列长度肯定不会超过sqrt(n)量级，状态转移时，分最小数是否包含1两种情形来进行规约 | 动态规划 |
|[猜数字](http://hihocoder.com/problemset/problem/1169) | 我太弱了。。。其实就一个划分树，用线段树维护一下就行了 | 树 |
|[机器人](http://hihocoder.com/problemset/problem/1170) | 首先注意到如果颜色的相对大小确定了，那么归并求一下逆序数就行，但是所有的颜色排列是阶乘量级的，状态压缩就冒出来了。。 | 状态压缩 动态规划 |
|[城市和魔法塔](http://hihocoder.com/problemset/problem/1171) | 跪烂膝盖。。。没注意到魔法塔的代价是很小的，最小凸包能够保证每个内点都在一个三角形内，所以能用魔法塔包围的就尽量包围。。。然后需要求最小凸包，居然是floyd最短路啊。。三观都被毁了。。 | 计算几何 最短路 |
|[Toy Cars](http://codeforces.com/problemset/problem/545/A) | 水题不多说。。 | 水 |
|[Equidistant String](http://codeforces.com/problemset/problem/545/B) | 距离为偶数时可构造解，为奇数无解 | 构造 |
|[Woodcutters](http://codeforces.com/problemset/problem/545/C) | 如果能向左就向左，实在不行就向右，还不行就不管那棵树了 | 贪心 |
|[Queue](http://codeforces.com/problemset/problem/545/D) | 从小到大排序贪心 | 贪心|
|[Paths and Trees](http://codeforces.com/problemset/problem/545/E) | Dijkstra变形，每次选择边的时候选择保持最短路径的权重最小的边 | 图论 最短路径 |
|[Soldier and Bananas](http://codeforces.com/problemset/problem/546/A) | 水题不多说。。 | 小学数学？ |
|[Soldier and Badges](http://codeforces.com/problemset/problem/546/B) | 要从小到大贪心，反过来不对啊就这个被hack了超级不爽。。。 | 贪心 |
|[Soldier and Cards](http://codeforces.com/problemset/problem/546/C) | 模拟一下就行了，卡最大状态数 | 模拟 |
|[Soldier and Number Game](http://codeforces.com/problemset/problem/546/D) | 高效筛素数的变形，需要对平方、立方项等进行考虑 | 数论 |
|[Soldier and Travelling](http://codeforces.com/problemset/problem/546/E) | 我太渣了。。知道是流网络，也会写最大流算法，就是没想出来怎么建立流网络。。。把顶点复制一份，从左向右连边表示转移的数目，最后判断是否满流，并且根据反向边容量回推实际操作 | 最大流 |
|[大搬家](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=584&pid=1001) | 对于n的情形，考虑最后一个点，要么原地不动，要么选择前面n-1中的一个，变成规模为n-2的问题 | 动态规划 |
|[列变位法解密](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=584&pid=1002) | 默默算一下坐标映射就行了。。。 | 数学 |
|[IP聚合](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=584&pid=1003) | 随便搞搞就行了 | 水 |
|[放盘子](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=584&pid=1004) | 先手输只有一种情形，就是多边形半径小于圆的半径 | 博弈 几何 |
|[下棋](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=584&pid=1005) | 朴素的办法就是去广度搜索，不爆内存也得超时，关键点在于king的移动方式是很特别的，一圈一圈往外扩展，于是knight可以贪心，每一步都最小化横纵坐标绝对差值的最大值。注意1步可达是个边界情况 | 找规律 |
|[单调区间](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=584&pid=1006) | 按照位置、数字、单调性建立状态，状态之间进行概率转移 | 概率 动态规划 |
|[Shaking Hands](http://acm.hdu.edu.cn/showproblem.php?pid=5232) | 随便搞搞就行了。。。 | 图论 |
|[Gunner II](http://acm.hdu.edu.cn/showproblem.php?pid=5233) | 离散化，高效查找，随便搞 | 离散化 |
|[Happy Birthday](http://acm.hdu.edu.cn/showproblem.php?pid=5234) | 背包问题的简单变形，按照两个方向进行状态转移就行了 | 动态规划 |
|[Mike and Frog](http://codeforces.com/problemset/problem/547/A) | 比赛的时候折磨了我两个小时，还好提前10分钟AC。。。循环的结果是形状类似p的环，分情况讨论目标点是否在环上，对于在环上的情形，通过gcd判断是否有解，有解则可以枚举 | 数学 |
|[Mike and Feet](http://codeforces.com/problemset/problem/547/B) | 注意到答案是满足单调性的，因此可从小到大插入元素并进行下界更新 | 数据结构 |
|[Mike and Fax](http://codeforces.com/problemset/problem/548/A) | 随便搞搞就行。。。 | 字符串水题 |
|[Mike and Fun](http://codeforces.com/problemset/problem/548/B) | 每次只更新相应行，水。。 | 水 |
|[Mike and Foam](http://codeforces.com/contest/547/problem/C) | 很好的题目。。质数分解之后利用容斥原理进行计数的维护，注意1是一个边界情况 | 数论 容斥原理 |
|[Mike and Fish](http://codeforces.com/contest/547/problem/D) | 我智商太低。。。这他喵的居然是二分图的边染色。。如果所有点的度数均为偶数，则寻找欧拉回路染色，否则删掉奇数度数顶点的一条边，递归求解 | 二分图 欧拉路径 深度搜索 |
|[KQUERY](http://www.spoj.com/problems/KQUERY/en/) | 很好的题目啊。。。本来利用归并树可以得到O(nlgnlgn)的解，但是居然卡这个复杂度。。。必须是O(nlgn)才能行。。。查询的离线处理 + BIT来搞 | 树状数组 |
|[Sereja and Brackets](http://codeforces.com/contest/380/problem/C) | 线段树建模，父节点一方面继承左右子节点中的所有配对括号，另一方面还可以左右结合配对 | 线段树 |
|[超级赛亚ACMer](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=600&pid=1001) | 只要有办法达到最高数值就可以取胜，于是排序之后贪心。。一开始看错题目了。。。 | 贪心 |
|[连续数](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=600&pid=1002) | 需要O(1)判断一个区间是否连续，只需要看最大值和最小值的差，以及其中是否有重复元素，rmq预处理，每个请求线性时间搞定 | 区间查询 |
|[序列变换](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=600&pid=1003) | 又看错题了，我真是智商捉急。。二分，每次尽可能把元素往左边排以留出最大的间隙 | 二分 贪心 |
|[KPI](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=600&pid=1004) | 动态查询中位数，用个splay维护一下就好 | splay |
|[矩形面积](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=600&pid=1006) | 本质是求出最小覆盖矩形的面积，先求一下点集的凸包，然后再枚举每一条可能的底边就行了 | 计算几何 |
|[Pegman](https://code.google.com/codejam/contest/8234486/dashboard#s=p0) | 我太弱了，这个都想了一个半小时。。。只要保证从每个点出发，一直走能够碰到另外一个非空点就行了，无法保证这个条件就无解 | 图论？ 考智商 |
|[Kiddie Pool](https://code.google.com/codejam/contest/8234486/dashboard#s=p1) | 被精度折磨到死。。。进行二分，每次找最高温度和最低温度，判断体积和温度是否在相应区间内 | 二分 考智商 |
|[Bilingual](https://code.google.com/codejam/contest/8234486/dashboard#s=p2) | 神题啊。。到现在还不是特别理解为什么就能变成最大流模型去求解。。 | 网络流 组合优化 |
|[连接的管道](http://acm.hdu.edu.cn/showproblem.php?pid=5253) | 红果果最小生成树，居然卡Kruskal算法的内存，无聊。。逼着我用优先队列写prim | 最小生成树 |
|[棋盘占领](http://acm.hdu.edu.cn/showproblem.php?pid=5254) | 类似于spfa，一层层扩展 | 递推？ |
|[序列变换](http://acm.hdu.edu.cn/showproblem.php?pid=5256) | 很好的小题目。。第一场初赛的变形。。。严格递增可转化成非降序列，然后改变最少的元素等价于保留最多的元素，然后就是熟悉的最长非降子序列问题了 | 动态规划 考智商 |
|[魔法因子](http://acm.hdu.edu.cn/showproblem.php?pid=5255) | 被精度搞死。。千万不要除double啊。。列出等式，可知只需要枚举最高位、最低位、位数，然后验证中间部分是否是一个整数就行 | 数学 |
|[追星族](http://acm.hdu.edu.cn/showproblem.php?pid=5252) | 智商不够。。。对答案二分，然后从后往前扫描，确定两个正方形区域的交集，交集为空则失败，否则继续向前 | 几何 考智商？ |
|[Coversta](SRM 660 divsion 1 level 1) | 泪目啊。。数组下标写错了比赛爆0，我太弱了。。。枚举每一个可能的位置，注意只有该位置可达的那些点会成为公共点，然后去更新可能会受到影响的点收益，扫描取最大值，O(N * M * K * K)，说多了都是泪。。。 | 考智商？ |
|[Private Party](SRM 660 division 1 level 2) | 期望是线性的，鬼都知道。。要命的地方就在于有环，但是，只要确定第一个元素，就可以破环，变成线性链，用dp求出当前元素的贡献，膜拜的clj的代码。。。 | 概率 动态规划 |
|[Cycle Min](SRM division 2 level 1) | 卧槽。。为何这题都有那么多坑。。。字符a要跳过去，留意非a数目小于k时可能导致的死循环 | 字符串 |
|[Private D2 Party](SRM division 2 level 2) | 分两种情况讨论，线性链则可以全部加进去，有长度大于一的环则需要扔掉一个元素 | 数学？ |
|[Powerit](SRM division 2 level 3) | 我智商捉急。。朴素枚举超时，然后观察到真正需要计算的其实只有质数因子，合数通过分解就可以免去重复计算，让时间效率提升10倍 | 数论 |
|[Two Substrings](http://codeforces.com/problemset/problem/550/A) | 找到最左边和最右边的，判断是否重合 | 水 |
|[Preparing Olympiad](http://codeforces.com/problemset/problem/550/B) | 随便搞搞就好。。。 | 枚举 |
|[Divisibility By Eight](http://codeforces.com/problemset/problem/550/C) | 我大脑短路了20分钟。。。1000是被8整除的，于是只关心低三位就行了 | 小学数学？。。 |
|[Regular Bridge](http://codeforces.com/problemset/problem/550/D) | 我太弱了。。k是偶数的时候赤裸裸满足欧拉回路条件必然不会有桥啊，图论怎么学的。。奇数的时候需要拼凑构造，很巧妙，我这个智商没想出来。。 | 图论 构造算法 |
|[Brackets in Implication](http://codeforces.com/problemset/problem/550/E) | naive动态规划n * n肯定挂，注意到可以按照111...110来划分，最末尾是1肯定无解，奇数组两两配对必然有解。偶数组需要把前三组合并到第四组变成奇数组，只有两组是个特殊情况，需要特判，比赛要是延长20分钟就AC了。。 | 数理逻辑 考智商 |
|[和谐答案](http://ac.jobdu.com/problem.php?pid=1557) | 最长上升序列的变形，每个位置可以取多个值，为了防止同一位置覆盖，需要从大到小进行二分 | 最长上升序列变种？ |
|[数长方形](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=602&pid=1001) | 枚举每一对水平边和垂直边 | 简单几何 |
|[弹吉他](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=602&pid=1002) | 一开始看错题了。。以为顺序任意，果然脑子经常进水。。对各种可能的排列进行状态转移，取代价最小的可行解 | 动态规划 |
|[蜀道难](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=602&pid=1004) | 有很naive的O(n * n)解法，显然超时。。办法是统计每相邻两个点对解产生的影响，求partial sum，再用rmq去对每一个半圆查询 | 区间最值查询 |
|[行路难](http://acm.hdu.edu.cn/showproblem.php?pid=5260) | 很神奇的一题。。从终点逆向跑bellman ford，关键在于如何检测无限环的情况，需要迭代6 * n轮才行，我脑补出来了一种这个情况，智商低是硬伤。。。 | 图论 考智商 |
|[最强密码](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=602&pid=1005) | 每一串覆盖a-z的分一组，能分多少组，最短串就是组数+1，然后个数就是总数减掉长为k的子串的个数，自己yy出来了一个动态规划算法，居然还AC了，给自己跪。。。 | 字符串 动态规划 |
|[Face Detection](http://codeforces.com/contest/549/problem/A) | 随便搞搞就行了。。 | 水 |
|[Looksery Party](http://codeforces.com/contest/549/problem/B) | 我太笨了。。。如果全部非零，一个都不选就行了；只要有一个非0的，那么就选对应的元素，每次操作都能保证至少消耗数组中的一个元素，因此必然有可行解 | 贪心构造 考智商 |
|[The Game of Parity](http://codeforces.com/contest/549/problem/C) | 博弈的题目都要有一个最基本的观察才行，在这里，不管是谁最后一步，如果奇数和偶数都有则必胜。因此对手的操作应当是着力于消除所有的奇数块或者偶数块 | 博弈 |
|[Yura and Developers](http://codeforces.com/contest/549/problem/F) | 已经被各种高效操作闪瞎。。。关键在于高效计算余数相等的数对个数，在小的那一部分计算，避免O(n * n)的最坏复杂度 | 数据结构 |
|[Happy Line](http://codeforces.com/contest/549/problem/G) | 神啊。。。每个元素的变化只跟初始和最终位置相关，因此可以先加上i，升序排列再减去j，是完全等价的操作！！ | 考智商 |
|[Degenerate Matrix](http://codeforces.com/contest/549/problem/H) | 我太弱了。。。degenerate matrix几何上是在一条直线上，所以对答案二分，每次枚举八个顶点，查看是否存在相应的满足要求的直线，tourist 4分钟搞定，膜拜之情无法用言语表达。。。 | 几何 二分 数学 |
|[Haar Features](http://codeforces.com/contest/549/problem/D) | 亮瞎我的狗眼。。居然是贪心，注意到最右下角不符合要求的点必须单独进行一次操作，然后不断向前推进，我YY了2个小时才搞出来，太弱了。。。 | 贪心 |
|[Flowers](http://codeforces.com/problemset/problem/474/D) | 赤裸裸动态规划，没什么好说的。。 | 动态规划 |
|[Missing LCM](SRM 661 division 1 level 1) | 缺失一些数仍然能够保证最小公倍数不变，必然是缺失的数进行质因子分解之后，没有一个能够取得质因子指数的最大值 | 数论 |
|[Colorful Line Graphs Div2](SRM 661 division 2 level 3) | 一看就是动态规划，f(i, j)表示i位置取j颜色的总数，按照连边和不连边两种情形分别计算就行了 | 动态规划 |
|[Colorful Line Graphs](SRM 661 division 1 level 2) | 通过上面的动态规划可以找到规律，我智商捉急。。。于是写出了一个简单递推式，但是顺序计算仍然会超时，注意到M是比较小的，因此可以把下标按照M的倍数进行划分，用快速幂计算，余数单独考虑 | 找规律？ 组合计数 快速幂 |
|[Falling Sand](SRM 661 division 2 level 1) | 从最右下角到最左上角不断扫描就行 | 水水的模拟 |
|[Bridge Building Div2](SRM 661 division 2 level 2) | 数据范围小，于是可以枚举一发，对于每种配置跑一发floyd最短路算法，然后取最优值 | 位运算 最短路 |
|[Gukiz and Contest](http://codeforces.com/problemset/problem/551/A) | upper_bound随便搞。。 | 排序 |
|[ZgukistringZ](http://codeforces.com/problemset/problem/551/B) | 顺序是没有关系的，因此只要统计各个字母的数目，枚举第一个字符串的出现次数，对第二个贪心计算就行了 | 考智商？ |
|[Gukiz hates Boxes](http://codeforces.com/problemset/problem/551/C) | 注意到最末尾的盒子必须有人过去消除，而且二分性质是满足的，于是对于每一个候选解，去做贪心 | 二分查找 贪心 |
|[Gukiz and Binary Operations](http://codeforces.com/problemset/problem/551/D) | 异或操作中每个位是独立的，因此计数的话分别相乘就行。k的某一位为0，则不能有连续一；为1则至少有一个连续1，和前面情况互补。然后根据动态规划递推式构造转移矩阵，跑一发矩阵快速幂，我居然半小时就搞出来了。。。 | 组合计数 矩阵快速幂 动态规划 |
|[GukiZ and GukiZiana](http://codeforces.com/problemset/problem/551/E) | 很好的一个数据结构题。。。第一次接触sqrt decomposition的方法，很神奇，每次查找和更新都是sqrt(n)复杂度的 | 数据结构 |
|[ZYB loves Score](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=603&pid=1001) | 随便搞搞。。 | 水 |
|[ZYB loves Xor I](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=603&pid=1002) | 对于每一个位来说，可以按照取0还是取1进行划分，如果两个数的这一位不同，则lowbit就确定了，否则继续向前 | 分治 位运算 |
|[ZYB loves Xor II](http://acm.hdu.edu.cn/showproblem.php?pid=5270) | 神题。。。每一个位单独考虑，对2^(i + 1)取模排序，然后线性扫描计算统计量，排序采用归并排序可以提高执行效率，那个很显然的公式怎么想到的啊。。。 | 位运算 归并排序 计数 |
|[Chef And Memory Limit](http://www.codechef.com/JUNE15/problems/CBARG) | 我傻叉了。。一开始还naive以为选最大值就行了。。 | 水 |
|[Chef and Polygons](http://www.codechef.com/problems/CHPLGNS/) | 看错题了。。。任何两个polygon都是包含关系，因此一定就是类似于同心圆那种形状，按照最大的x坐标排序就行了，面积也行 | 几何 |
|[Steady Table](http://www.codechef.com/problems/STDYTAB/) | 红果果动态规划啦。。。需要记录下partial sum实现常数转移 | 动态规划 |
|[Vanya and Table](http://codeforces.com/problemset/problem/552/A) | 随便搞搞。。 | 水 |
|[Vanya and Books](http://codeforces.com/problemset/problem/552/B) | 从最低位到最高位不断进行累加就好了 | 数学 |
|[Vanya and Scales](http://codeforces.com/problemset/problem/552/C) | 挺好的小题目。。注意m如果能被w整除，则除以w不影响，不能整除的话必定是余数为1或者w-1，否则无解，然后不断重复这一过程就行了 | 数论 考智商？ |
|[Vanya and Triangles](http://codeforces.com/problemset/problem/552/D) | 只需要减掉三点共线的情形，为了加快统计，可以用哈希表对方向向量计数 | 几何 计数 |
|[Vanya and Brackets](http://codeforces.com/problemset/problem/552/E) | 一个关键点就在于：必定是在乘法的地方加括号，可以手算验证一下的。。于是枚举任何两个乘法位置，求出表达式的值，然后取最优解就行了 | 考智商？ |
|[Dylans loves numbers](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=604&pid=1001) | 随便搞搞。。。 | 位运算 |
|[Dylans loves sequences](http://acm.hdu.edu.cn/showproblem.php?pid=5273) | 其实有很简单的动态规划的。。我想复杂了，搞了一个划分树，每次去查询 | 动态规划 数据结构 |
|[Dylans loves trees](http://acm.hdu.edu.cn/showproblem.php?pid=5274) | 学到了很多，非常好的题目。。。用bit来维护区间异或和，关键点在于通过dfs记录下每个顶点的enter time和exit time，然后lca的话居然可以利用倍增的思想去求！！！弱渣第一次接触，非常简洁、高效、神奇 | 树状数组 LCA 异或 |
|[Kyoya and Photobooks](http://codeforces.com/problemset/problem/554/A) | set维护一下就行了。。 | 水 |
|[Ohana Cleanup](http://codeforces.com/problemset/problem/554/B) | 注意到，只要原始字符串相等，就一定能同时变成全1，否则不行，用map计数就ok了 | 脑筋急转弯？。。 |
|[Kyoya and Colored Balls](http://codeforces.com/problemset/problem/553/A) | 对于最后一个color的最后一个球，枚举在倒数第二中颜色最后一个球前面有多少个最后一种颜色，组合数 + 递归解决规模更小的子问题 | 组合计数 动态规划 |
|[Kyoya and Permutations](http://codeforces.com/contest/553/problem/B) | 哭死。。看错题意了。。基本观察：符合要求的置换只能在相邻两个数之间交换，所以用dp计数，从头到尾判断就行了 | 动态规划 置换群 |
|[Love Triangle](http://codeforces.com/contest/553/problem/C) | 关键点：love相连的两个顶点是可以合并的，合并之后必定是二分图才有解，对于每一个联通分量，只有一种赋值方法，独立的连通分量之间只要确定一个串，也唯一。因此就是2^(n - 1) | 深搜 组合计数 二分图判定 |
|[Nudist Beach](http://codeforces.com/contest/553/problem/D) | 其实也不是那么难。。对目标进行二分，每次用类似于spfa那种算法去做检验，最后剩余集合非空则可行，反之则不可行 | 图论 二分 贪心 |
|[Case of Matryoshkas](http://codeforces.com/contest/555/problem/A) | 卧槽！！！只是因为我没搞明白俄罗斯套娃是怎么回事WA了一路！！！其实超级简单的。。判断从1开始的连续数字，只有这个套娃可以不拆，其他都必须拆开 | 俄罗斯文化理解？😢 |
|[Case of Fugitive](http://codeforces.com/contest/555/problem/B) | 简单分析一下，就可以发现是用贪心。按照最大长度的升序排列，每次选择不小于最小长度的lower_bound，可行则删掉，不可行则无解，用multiset维护一下就好 | 贪心 数据结构 |
|[Case of Chocolate](http://codeforces.com/contest/555/problem/C) | 每次query相当于对区间做了一次更新，于是可以用离散化 + 线段树来搞，为了提高效率，每次update要进行lazy propagation，避免每次都更新到叶节点 | 线段树 离散化 |
|[Case of Zeros and Ones](http://codeforces.com/problemset/problem/556/A) | 最后肯定剩下全0或全1，简单计数。。 | 贪心？ |
|[Case of Fake Numbers](http://codeforces.com/problemset/problem/556/B) | 第一个数必须减a1，于是后面的都顺着操作，判断一发。。 | 水 |
|[Case of Top Secret](http://codeforces.com/contest/555/problem/D) | 很漂亮的一道题。。每次模拟时，如果都能减半就能在log量级完成，但如果不能够减半，则必定是不断在两个端点之间徘徊，直接取余就能够至少减半了 | 二分 考智商 |
|[Ilya and Diplomas](http://codeforces.com/problemset/problem/557/A) | 先满足所有下限，再尽可能满足最靠前的等级 | 贪心？ |
|[Pasha and Tea](http://codeforces.com/problemset/problem/557/B) | 三个下限去卡就好了 | 贪心？ |
|[Arthur and Table](http://codeforces.com/problemset/problem/557/C) | 枚举每一个可能的最大值，然后选择保证stable的其他最大代价的保留，数据范围小直接计数就好了 | 贪心？ |
|[Vitaly and Cycle](http://codeforces.com/problemset/problem/557/D) | 挺有意思的题目。。。如果不是二分图，一定有奇数长度环，否则对每个连通分量做二染色，分别考虑连通分量包含至少三个顶点、最多包含两个顶点、只包含一个顶点的情形 | 图论 组合计数 二分图染色 |
|[Ann and Half-Palindrome](http://codeforces.com/contest/557/problem/E) | 是我太渣。。动态规划判断half palindrome好说，然后求第k个，可以通过建立trie树，一遍dfs去计算左子树和右子树的节点数，非常简洁明了 | 动态规划 前缀树 |
|[Majority Element](https://leetcode.com/problems/majority-element-ii/) | 一般不会记录leetcode题目，但是这个还挺有意思的。。以前碰到过求绝对众数的问题，这里要求超过n / 3的数，记录两个candidate，当新来的跟目前两个都不一样时，counter自减，这样可以保证n / 3众数最后一定能保留下来，最后再线性扫描检验。更为重要的是，这个框架是具有普适性的，可以直接推广到n / m众数的情形，只需要保留m - 1个candidate就行了 | 考智商？。。 |
|[YJC tricks time](http://acm.hdu.edu.cn/showproblem.php?pid=5276) | 卧槽。。忘了检查超过180度的情况，第一次在BC被hack成功。。 | 小学数学？ |
|[YJC counts stars](http://acm.hdu.edu.cn/showproblem.php?pid=5276) | 平面图上的最大团问题，最优解不会超过4，所以分各种情况讨论就行了 | 图论 |
|[Cycle](http://acm.hdu.edu.cn/showproblem.php?pid=5215) | 可以用二分染色去判定是否存在奇数长度环，用双连通分量判定是否存在偶数长度环，后来发现了一个很感人的算法，把每个顶点分裂，用并查集，我智商不够。。 | 图论 |
|[How far away](http://acm.hdu.edu.cn/showproblem.php?pid=2586) | 红果果的lca问题，用rmq或者tarjan离线算法都行 | LCA |
|[Redundant Paths](http://poj.org/problem?id=3177) | 双连通图可以满足给定的约束，于是可以找出所有的双连通分量，缩成一个点，得到一棵树。对于树来说，需要添加(leaf + 1) / 2条边才能变成双连通图 | 双连通图 树 |
|[Minimum Cut](http://poj.org/problem?id=2914) | 我太弱了。。。第一次知道还有一个Stoer-Wagner算法来求无向图的最小割，每次求最大生成树，将最后一条边所连接的两个顶点合并，直至最后剩下两个顶点 | 无向图最小割 |
|[超级英雄hero](http://www.lydsy.com/JudgeOnline/problem.php?id=1191) | 红果果的二分图最大匹配，按照点的标号去匹配就好了 | 二分图匹配 |
|[生日礼物](http://www.lydsy.com/JudgeOnline/problem.php?id=1293) | 对于某个固定的终点，起点必须保证所有颜色都有并且恰好是所有颜色都有，所以用two pointers来维护就行了，O(N)复杂度 | 贪心 双指针 |
|[狡猾的商人](http://www.lydsy.com/JudgeOnline/problem.php?id=1202) | 每次插入一个新的区间，去考虑所有能够因为这个区间而改变的其它区间，检测到矛盾则为false | 考智商？？ |
|[宠物收养所](http://www.lydsy.com/JudgeOnline/problem.php?id=1208) | 官方写着用splay，其实用set维护一下就行了。。。 | 数据结构 |
|[打鼹鼠](http://www.lydsy.com/JudgeOnline/problem.php?id=1207) | 将所有事件按照时间排序，线性dp就行了，懒得说了。。 | 动态规划 |
|[Minimal Difference](SRM 662 div 1 level 1) | 挺神奇的一件事情。。我YY出来了一个贪心算法，不能够证明其正确性，但也举不出反例。。然后pass system test了。。cgy大神有一个[证明](http://codeforces.com/blog/entry/19151)，把数建模成图中的顶点，有合法解当且仅当存在哈密顿回路 | 贪心 |
|[Exact Tree](SRM 662 div 1 level 2) | 跪烂膝盖。。。dp的状态不好想。。 | 动态规划 |
|[Hex Speak](SRM 662 div 2 level 1) | 进制转换一下就行了。。 | 初中数学？ |
|[Exact Tree Easy](SRM 662 div 2 level 2) | 叶节点最多就是一层的情形，然后每次把一个节点挂到最后一个叶子下面都能让叶节点数减一 | 贪心 构造 |
|[Maximal Safety Level](SRM 662 div 2 level 3) | 只有一种情形需要考虑：原点在三角形内部。枚举原点和每条边上的中点就行了 | 几何 |
|[Senior's Array](http://acm.hdu.edu.cn/showproblem.php?pid=5280) | 枚举每一个位置，跑一下最大连续区间和就行了 | 枚举 |
|[Senior's Gun](http://acm.hdu.edu.cn/showproblem.php?pid=5281) | 最终的结果肯定是最大的若干个gun和最小的若干个monster，但不一定是消灭最多的monster！！ | 贪心 |
|[Senior's String](http://acm.hdu.edu.cn/showproblem.php?pid=5282) | 一眼就知道是dp，也想到状态表示了，死活没想出来状态如何转移。。。我太弱了。。。对于f(i, j)，分考虑第i个字符和不考虑i个字符两种情形讨论 | 动态规划 |
|[Senior's Fish](http://acm.hdu.edu.cn/showproblem.php?pid=5283) | 膜拜xyz11的代码。。。矩形的查询拆分，这个地球人都知道。。然后维护四个线段树，每次更新之后，将移出边界的点删掉，每次查询只需要看全区间中还有多少个在边界中的点，其实也不是那么难。。。 | 线段树 |
|[最大子矩阵](http://www.lydsy.com/JudgeOnline/problem.php?id=1084) | 注意到列数<=2，所以红果果的状态压缩动态规划，需要设计一下状态，我觉得自己写麻烦了。。。 | 状压动归 |
|[骑士精神](http://www.lydsy.com/JudgeOnline/problem.php?id=1085) | 典型的搜索问题，用A*搞搞就行。。注意棋盘状态编码的问题 | A*搜索 |
|[Lala Land and Apple Tree](http://codeforces.com/problemset/problem/558/A) | 分原点两侧苹果树数目相等和不相等两种情况就好了。。 | 小学数学？ |
|[Amr and Large Array](http://codeforces.com/problemset/problem/558/B) | 用哈希表去计数，然后线性扫描一发得到左右边界 | 简单计数 |
|[Amr and Chemistry](http://codeforces.com/problemset/problem/558/C) | 比赛的时候想了20分钟才有思路。。。intuition：如果一个数要保留n个1，那么一定是最左边的n个1，然后找出1 bit最少的数，枚举前缀 | 数论 考智商 |
|[Guess Your Way Out II](http://codeforces.com/problemset/problem/558/D) | 不敢相信room里面只有我一个人AC了。。其实不是很难吧，对于每一个ancestor，确定一组leaf，这些leaf肯定不是exit，然后贪心扫描这一大堆区间，看看有多少点没有被覆盖 | 树 贪心 |
|[A Simple Task](http://codeforces.com/problemset/problem/558/E) | 一看就是线段树 + lazy propagation，但是比赛期间没有想清楚怎么propagate，后来看到一种简洁高效的解法，用set去维护区间，每次操作顶多增加两个区间，我还是智商不够。。 | 数据结构 |
|[Who Is Winner](http://codeforces.com/gym/100712/problem/A) | 排排序就行了。。 | 水 |
|[Alternating Strings](http://codeforces.com/gym/100712/problem/D) | 考虑以某个位置i结束，前一个分裂点是j的状态，判断是否可行，然后转移就好了 | 动态规划 |
|[Alternating Strings II](http://codeforces.com/gym/100712/problem/L) | 和上面相同的题目，只是数据规模变大了。转移的时候，用线段树高效查询区间最小值 | 动态规划 线段树 |
|[Bahosian and Digits](http://codeforces.com/gym/100712/problem/I) | 从大到小枚举K，枚举第一个数，关键在于更新的时候要聪明一点，我用了树状数组，其实可以不用的。。。 | 树状数组 |
|[Bridges](http://codeforces.com/gym/100712/problem/H) | 找出所有双连通分量，然后缩点构造出一个新图。要想消除尽可能多的桥，就得在树里面找出最长的路径，两次bfs得到树的直径。但是不知道为什么，我的代码一直wrong answer，又看不了别人的代码，无解。。。 | 图论 |
|[A string problem](http://acm.hdu.edu.cn/showproblem.php?pid=5284) | WTF！！！本来能拿room No. 1，还有奖金的。。结果就因为用了cin而不是scanf导致TLE了，68块钱的教训！！！ | 字符串 |
|[wyh2000 and pupil](http://acm.hdu.edu.cn/showproblem.php?pid=5285) | 红果果二分图判定，但需要注意m = 0的特殊情况，貌似anta和kuangbin神牛都在这个点上挂了 | 图论 |
|[wyh2000 and sequence](http://acm.hdu.edu.cn/showproblem.php?pid=5286) | 目前仍然是TLE，时间常数搞不定，心太累已经弃疗。。。题目好诡异啊，用到了sqrt decomposition，还需要高效查询一个区间里某个数出现的次数 | 分块 数据结构 |
|[最大土地面积](http://www.lydsy.com/JudgeOnline/problem.php?id=1069) | 脑补一下就可以知道所求的四边形顶点全部都在凸包上，枚举每一对顶点，同时用旋转卡壳来提高扫描速度 | 凸包 旋转卡壳 |
|[压缩](http://www.lydsy.com/JudgeOnline/problem.php?id=1068) | 红果果的动态规划，保证O(N^3)搞定，状态都是我自己YY出来的，基本思想就是划分区间，并在区间之间进行转移 | 动态规划 |
|[余数之和sum](http://www.lydsy.com/JudgeOnline/problem.php?id=1257) | 之前在CF上做过很相似的题目，1 ~ sqrt(N)可以枚举，而sqrt(N) ~ N的商只有sqrt(N)个，因此后半部分去枚举商值 | 数论 |
|[Currency System in Geraldion](http://codeforces.com/problemset/problem/560/A) | 第一眼吓了我一跳，子集和不是NPC的么。。然后发现自己读错题目了，只要看看是否有1就行了 | 脑筋急转弯 |
|[Gerald is Into Art](http://codeforces.com/problemset/problem/560/B) | 贪心枚举每一种情形就行了 | 贪心 几何 |
|[Gerald Hexagon](http://codeforces.com/contest/559/problem/A) | 用余弦公式 + 海伦公式乱搞了一把。。 | 几何 数学 |
|[Equivalent String](http://codeforces.com/contest/559/problem/B) | 智商太低。。不过挺神奇的是，我YY出来的算法在第104组数据上跪了，而这是最后一组测试数据。。。膜拜了bmerry的代码，非常简洁，分治法。。 | 分治 |
|[Gerald and Giant Chess](http://codeforces.com/contest/559/problem/C) | 我太弱了。。很明显就是对black cell进行dp，但是没有想到转移方程，对第一个black cell进行转移啊不是最后一个。。智商硬伤 | 动态规划 计数 |
|[Souvenir](http://acm.hdu.edu.cn/showproblem.php?pid=5310) | 随便搞搞就好 | 贪心 |
|[Hidden String](http://acm.hdu.edu.cn/showproblem.php?pid=5311) | 注意对目标串枚举，否则就TLE | 枚举？ |
|[Sequence](http://acm.hdu.edu.cn/showproblem.php?pid=5312) | 坑爹的。。。我以为贪心是对的，结果被hack，[三角形数](http://baike.baidu.com/view/1047488.htm)是神马？。。从来没听说过 | 三角形数。。 |
|[Bipartite Graph](http://acm.hdu.edu.cn/showproblem.php?pid=5313) | 很奇怪啊。。对于每一个连通分量，都需要白黑染色，最终使得白色和黑色的数量差异最小，我记得这个问题不能贪心啊。。怎么只有贪心才能AC呢。。 | 二分图 贪心 计数 |
|[ABBADiv1](http://community.topcoder.com/stat?c=problem_statement&pm=13922&rd=16512) | 我太弱了。。。关键点在于逆向模拟的时候，只可能有O(N * N)个不同的状态 | 考智商 |
|[Chess Floor](http://community.topcoder.com/stat?c=problem_statement&pm=13917&rd=16512) | 枚举一发就行了。。 | 水 |
|[ABBA](http://community.topcoder.com/stat?c=problem_statement&pm=13918&rd=16512) | 很显然逆向 | 字符串 |
|[Chess Rolling](http://community.topcoder.com/stat?c=problem_statement&pm=13919&rd=16512) | 朴素想法是对所有permutation枚举，16!必然TLE，但是2^16比较小，一个自然的想法就是数位dp，只关注最终的集合以及胜者，状态数O(2^N * N) | 动态规划 |
|[Changing Change](http://community.topcoder.com/stat?c=problem_statement&pm=13847&rd=16512) | 膝盖跪烂。。删除操作可以通过生成函数表达，作为弱渣第一次碰到。。而且[神牛的解法](http://codeforces.com/blog/entry/19400)依赖一个组合计数的中间结论，我从来没见过的结论。。。 | 生成函数 组合计数 |
|[Clique in Divisibility Graph](http://codeforces.com/problemset/problem/566/F) | 很好的题。。按照整除性进行动态规划，求出最大团 | 数论 图论 |
|[Restructuring Company](http://codeforces.com/problemset/problem/566/D) | 我自己YY出来了一个类似并查集的数据结构，然后pass system test了。。关键点在于区间合并要高效，因此可以记录每个节点最右边具有相同根的节点，避免遍历 | 并查集 数据结构 |
|[Replicating Process](http://codeforces.com/contest/566/problem/B) | 太神奇了。。。能选就随便选一个的greedy algo居然是对的，而且最坏复杂度看上去是O(N * N)，总之好神啊。。 | 贪心 |
|[Matching Names](http://codeforces.com/contest/566/problem/A) | 膜拜Alioth大神的代码。。。将所有的字符串插入到trie中，然后在每个节点，选取通过该节点的group A和group B字符串的最小值。trie树的简洁表示以及dfs的过程第一次见，对神牛的膜拜之情难以言表。。。 | 贪心 前缀树 |
|[Balancing Art](http://poj.org/problem?id=1655) | 第一次听说“树的重心”，渣渣。。naive要N * N，只记录子节点总数，再利用所有子节点和为常数dfs便可以线性搞 | 图论 |
|[Untitled](http://acm.hdu.edu.cn/showproblem.php?pid=5339) | 太无聊了。。居然卡常数，用了一个builtin_popcount就TLE，不用就AC | 数论 |
|[星际竞速](http://www.lydsy.com/JudgeOnline/problem.php?id=1927) | 想了一下是费用流，但是没想出怎么建图，渣渣。。对于普通边，从出边向入边连；对于跳跃边，从源点向入边连 | 最小费用最大流 |
|[中位数图](http://www.lydsy.com/JudgeOnline/problem.php?id=1303) | 分别统计b左右两侧大于b和小于b的个数，然后简单组合计数就行了 | 计数 |
|[Mittens](http://codeforces.com/contest/370/problem/C) | 太神了。。一年之前木有AC，今天还旧帐。。很巧妙的构造算法，排下序再将整个数组rotate总长度的一半就行了，orzzzzz | 构造 考智商 |
|[仪仗队](http://www.lydsy.com/JudgeOnline/problem.php?id=2190) | 仔细想想就知道是求连续区间的欧拉函数之和，用筛法求一发就好了 | 数论 |
|[Poker Hand](http://usaco.org/index.php?page=viewproblem2&cpid=262) | 核心在于如何高效分治，其实用set维护就好，O(NlgN)复杂度 | 分治 |
|[Farm Painting](http://usaco.org/index.php?page=viewproblem2&cpid=263) | 将矩形的左右边界排序，跑一发line sweep算法就好 | 几何 |
|[The Cow Run](http://usaco.org/index.php?page=viewproblem2&cpid=264) | 红果果动态规划，usaco上的autograder似乎犯病了，test case 2离线测正确在线就挂了，不管了。。 | 动态规划 |
|[Lineland Mail](http://codeforces.com/problemset/problem/567/A) | 随便搞搞就行。。 | 水 |
|[Berland National Library](http://codeforces.com/problemset/problem/567/B) | key insight:当有一个从来没见过的id离开时，将当前最优值加一 | 水 |
|[Geometric Progression](http://codeforces.com/problemset/problem/567/C) | 单纯计数是不够的，需要额外用一个哈希表记录a和之前a / k出现的总次数 | 计数 |
|[One Dimensional Battle Sheep](http://codeforces.com/problemset/problem/567/D) | 显而易见的分治，但是naive算法时间效率不达标，注意到每次删掉一个点只可能影响现有的一个区间，用set维护O(lgN) | 分治 数据结构 |
|[President and Roads](http://codeforces.com/problemset/problem/567/E) | 很好的图论问题，我太弱比赛时没做出来。。先forward和backward来一发dijkstra求最短路，然后在关键边中找桥 | 图论 |
|[Mausoleum](http://codeforces.com/problemset/problem/567/F) | 我傻叉了。。。比赛的时候思路是对的，就是漏了一个判断条件。。。红果果动态规划，最小的数肯定是在最外围，每次转移判断是否有条件违背就好 | 动态规划 组合计数 |
|[Zipper](http://poj.org/problem?id=2192) | 有一个小陷阱。。从后往前匹配的线性算法可能得出错误答案，于是就来一发记忆化搜索好了 | 动态规划 |
|[Music](http://codeforces.com/contest/569/problem/A) | 稍微推导一下就能知道每一次restart之后的总长度，迭代直到达到目标值 | 数学 |
|[Inventory](http://codeforces.com/contest/569/problem/B) | 贪心来看，只要是与之前重复的都得rename | 贪心 |
|[Primes or Palindromes](http://codeforces.com/contest/569/problem/C) | 搞了接近一个小时。。肯定不会无解，关键在于预处理到多大，三百万似乎是足够的我也不知道怎么证明反正是提心吊胆地AC了 | 数论 |
|[Symmetric and Transitive](http://codeforces.com/contest/569/problem/D) | 膜拜Petr大爷，9分钟搞定。。观察到，只要是有数不会出现在集合中，就不可能构成等价关系，于是枚举个数，剩下的元素进行集合划分，百度了一下现成的算法。。。弱渣 | 动态规划 组合计数 |
|[Bear Plays Div2](http://community.topcoder.com/stat?c=problem_statement&pm=13939) | 赤裸裸动态规划，注意到和是一个常数，因此只需要保存两个数的值就行了 |  动态规划 |
|[Bear Sorts Div2](http://community.topcoder.com/stat?c=problem_statement&pm=13941) | 挺有意思的小题目，key insight:最终结果只跟LESS调用次数有关。于是按照新顺序模拟一发归并就好 | 概率 归并排序 |
|[Good Numbers](http://codeforces.com/problemset/gymProblem/203881/A) | 类似容斥原理，加加减减的，需要想清楚一点 | 数学 |
|[Hamro and Array](http://codeforces.com/problemset/gymProblem/203881/B) | 求一下前缀和，然后判断奇偶决定是否反转符合就好 | 水 |
|[Hamro and Tools](http://codeforces.com/problemset/gymProblem/203881/D) | 关键部分在于实现搞笑的集合合并操作，通过link list可以常数实现 | 数据结构 |
|[Forfeit](http://codeforces.com/problemset/gymProblem/203881/F) | key insight: n很大的时候是无解的！！对于n规模小的情形，用动态规划来搞就行了，要注意处理复杂度，控制在O(n * k) | 动态规划 组合计数 |
|[Hamro and Izocup](http://codeforces.com/problemset/gymProblem/203881/G) | 初中数学。。实现一下就行 | 几何 |
|[The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) | leetcode上的一题，还有点意思。凡是矩形交并的大概都是line sweep来搞，对每一个事件作出响应，可用multiset等平衡树来维护，注意最后还要去掉水平线段和重合的垂直线段 | 几何 数据结构 |
|[Replacement](http://codeforces.com/problemset/problem/570/D) | 需要统计点的总数目和联通块总数，我一开始傻×了，维护的信息不一致居然都没有发现。。。 | 考智商？ |
|[Tree Requests](http://codeforces.com/contest/570/problem/D) | 挺好的一道题，之前都没见过。。。通过对树进行dfs，然后每次借助于二分来找到所有深度为h的子节点，是一段连续区间，至于palindrome，只需要判断奇偶，通过异或运算来维护 | 图论 数据结构 |
|[Pig and Palindromes](http://codeforces.com/problemset/problem/570/E) | 其实和USACO 2015 Open的是差不多的，通过动态规划来计数 | 动态规划 组合计数 |
|[Special Vertex](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/J) | 一开始又傻×了，以为像是树链剖分那样。。其实是点分治，每次找出树的重心，从而可以做到每次将数据规模减半 | 点分治 数据结构 |
|[Hamro and TheVampireDiaries](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/C) | 这题太鬼畜了。。考虑n能否被3整除的两种情况，写出和的表达式来，对开头的几个元素赋初始值就好了。 | 数学 |
|[Its not so bad](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/L) | 在新的路径长度定义下，不再满足dijkstra算法所要求的最优子结构，但是贪心考察每一位，每次通过广度搜索来判断是否能够到达终点 | 图论 |
|[LCM Query](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/E) | 膝盖跪烂。。。60以内的lcm会超出long long范围，但是质因子不超过32个，所以可以用int来压缩表示，比较大小的时候用bitmask去掉重复的，就不会溢出了。。因为算符优先级搞错了，调了两个小时。。。累感不爱。。 | 数学 |
|[A Bug Life](http://www.spoj.com/problems/BUGLIFE/) | 上一次写2-SAT还是13年coursera上的算法课，我真是太渣。。都给忘了，补上个模板。 | 2-SAT |
|[New Language](http://codeforces.com/contest/568/problem/C) | 代码能力太弱了。。。这个代码写了长长的一坨且各种bug。。。基本思想就是按照长度贪心，每次贪心的时候通过2-SAT来判定是否有解 | 2-SAT 贪心 |
|[Tree](http://www.lydsy.com/JudgeOnline/problem.php?id=1468) | 最经典的点分治题目，第一次写。。struggle了好几个小时，真弱。。 | 点分治 |
|[聪聪可可](http://www.lydsy.com/JudgeOnline/problem.php?id=2152) | 红果果点分治啦。。注意点对是考虑顺序的，权重可按照对3的余数分成三个等价类 | 点分治 |
|[Guni](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/M) | 两个不同的区间查询，维护两个rmq就行了，每个查询logN得到结果，同时logN可实现在末尾的更新 | 数据结构 |
|[Cheque](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/O) | 暴力上最短路肯定超时，注意到k的值很小，就用动态规划好了。。。复杂度也不好分析，反正AC了。。另外，题目的数据范围似乎有误，反正改大数组之后才消除了runtime error | 动态规划 图论 |
|[Mina](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/Q) | 动态规划求一下最坏情形解就好了，然后按照二分的过程来查询 | 动态规划 二分 |
|[Makegraph](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/R) | 膜拜W4yneb0t大神！真的是给人一种Aha moment的感觉，二分我也想到了，也想到了应该判断是否在换上有轻边，但死活没想到怎么高效判断。。检查一下最小生成树和最大生成树的权重是否相同就可以了！！ | 图论 生成森林 |
|[Godzilla and Pretty XOR](http://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/S) | 跪拜adamant大爷！！看题解都想了好长时间。。。只保存一组相互独立的基，然后对于insert操作，判断它是否能由现有的基构造出来，不能的话则将其插入，并更新位。 | 数学 |
|[不重复数字](http://www.lydsy.com/JudgeOnline/problem.php?id=2761) | 只是闲的无聊。。 | 水 |
|[Bags of Apples](https://www.hackerrank.com/contests/101hack28/challenges/bags-of-apples) | 枚举各种case似乎也是可以的，但还是动态规划简洁优美。。要注意判断解不可行的情况 | 动态规划 |
|[Binary String](https://www.hackerrank.com/contests/101hack28/challenges/binary-string) | 注意所有的字符是可以按照mod k来分成k组的，然后从小到大贪心，能够在当前位置放1一定得放1才能保证字典序最大 | 贪心 |
|[Squares and Points](https://www.hackerrank.com/contests/101hack28/challenges/squares-1) | 分成矩形进入、矩形离开、碰到点三种事件，跑一发line sweep算法，每次碰到点的时候，统计区间内的矩形数，可用树状数组维护。比赛时3 / 24挂了，后来发现是傻×地把排序比较函数写漏了一种情况，智商啊。。。 | 几何 数据结构 |
|[Bus Company](https://www.hackerrank.com/contests/101hack28/challenges/bus-company) | 一看题，不是动态规划就是费用流。。。建图能力实在是渣渣。。 | 最小费用最大流 |
|[Grid Maze](https://www.hackerrank.com/contests/101hack28/challenges/grid-maze) | 很好的图论题。。key insight: 对于最短路径，肯定是有一个T型的交叉点，虽然对于其他点可能会重复累加路径长度，但不会影响最短路径的。。。太神了。。 | 图论 |
|[Googol String](https://code.google.com/codejam/contest/4284486/dashboard) | 第一眼懵了几分钟，其实就是一个分治，判断是落在左半区间还是右半区间就好了 | 分治 |
|[gCube](https://code.google.com/codejam/contest/4284486/dashboard#s=p1) | 小数据暴力二分就行，大数据二分的一个问题是乘法会溢出，我可能是有点紧张，比赛的时候居然没注意到。。。溢出的一个解决办法就是取对数，精度不好说，但是事实证明可以AC | 二分 |
|[gCampus](https://code.google.com/codejam/contest/4284486/dashboard#s=p2) | 求一发all pair shortest path，然后枚举边和点对，判断是否是最短路上的边就好了 | 图论 |
|[gSnake](https://code.google.com/codejam/contest/4284486/dashboard#s=p3) | 坑爹模拟题。。。关键在于如何高效模拟贪吃蛇的行为，身体可以用deque来维护，每次只需要更新头部和尾部，然后食物可以用set判断是否被吃掉了 | 模拟 数据结构 |
|[Chef And XOR Number](https://www.codechef.com/COOK61/problems/XORNUBER) | 注意到只有末尾一连串1，其余位置没有1才有可能有解，1是一个corner case | 数学 |
|[Godzilla and Ugly Number](http://codeforces.com/problemset/gymProblem/203881/V) | 把等号变成不等号，对于小于关系，枚举第一个数字是0目标是1的位，对于大于关系也是类似 | 数学 |
|[严格n元树](http://www.lydsy.com/JudgeOnline/problem.php?id=1089) | 每次选择节点动态规划计数就好，用python就省去实现大数乘法了。。 | 动态规划 组合计数 |
|[Lengthening Sticks](http://codeforces.com/problemset/problem/571/A) | 推了一个小时不等式无果。。。但如果从对立面计数就简单到爆，智商啊。。。 | 组合计数 考智商 |
|[Minimization](http://codeforces.com/contest/571/problem/B) | 首先分组，然后注意到序列的划分不能交叉，剩下的就是红果果动态规划了。我这个傻×。。。一开始想了一个错误的状态表示都没发现。。 | 动态规划 |
|[Aditya and Classes](https://www.hackerrank.com/contests/codex-15-0/challenges/aditya-and-classes) | 傻逼题 | 贪心 |
|[Ravi and His Math Teacher](https://www.hackerrank.com/contests/codex-15-0/challenges/rearrange-the-arrangement) | 从左到右找到第一组连续的1，注意更新之后可能会产生新的连续1 | 贪心 |
|[Here lies the Difference](https://www.hackerrank.com/contests/codex-15-0/challenges/here-lies-the-difference) | 解决了我很长时间来的一个疑惑：给定一个数组，找出一个最小的数A，不能由数组中元素的任意子集求和得到。背包是可以，但复杂度高，原来还有线性算法的！！维护一个0到up的区间就好了 | 数学 |
|[Little Ronny and Prime Numbers](https://www.hackerrank.com/contests/codex-15-0/challenges/little-ronny-and-prime-numbers) | 晒素数，然后双指针线性扫描就好了 | 数学 双指针 |
|[Placement Treat](https://www.hackerrank.com/contests/codex-15-0/challenges/placement-treat-1) | 转化成两个子问题，分别用背包求解 | 动态规划 |
|[2048 1](https://www.hackerrank.com/contests/codex-15-0/challenges/2048-1) | 不会玩2048导致没看懂题目。。其实就是一个简单的背包 | 动态规划 |
|[Design the Simple Tree](https://www.hackerrank.com/contests/codex-15-0/challenges/design-the-simple-tree) | 傻逼题 | 构造 |
|[The Delicious Mess Food](https://www.hackerrank.com/contests/codex-15-0/challenges/the-delicious-mess-food) | 傻逼题 | 三维宽搜 |
|[Monkey Choice of Numbers](https://www.hackerearth.com/code-monk-bit-manipulation/algorithm/monks-choice-of-numbers-1/) | 傻逼题 | 数学 |
|[Monkey and His Friends](https://www.hackerearth.com/code-monk-bit-manipulation/algorithm/monk-and-his-friend/) | 傻逼题 | 数学 |
|[Monkey in Magical Land](https://www.hackerearth.com/code-monk-bit-manipulation/algorithm/monk-in-the-magical-land/) | 按位枚举 | 数学 |
|[When Integers Got Upset](https://www.hackerearth.com/code-monk-bit-manipulation/algorithm/when-the-integers-got-upset/) | 朴素枚举会超时，进行数位动态规划就行了 | 动态规划 |
|[Jesse Numbers](https://www.hackerrank.com/contests/sprint-debug/challenges/jesses-numbers) | 蛮机智的一个小结论，通过平方根可以常数时间判断一个数的因子个数的奇偶性 | 数学 |
|[Helping Jesse](https://www.hackerrank.com/contests/sprint-debug/challenges/helping-jesse) | 对于每个数字，维护一个单调上升的序列，每次碰到连续的数字则通过对序列两端的操作更新 | 数据结构 |
|[Jesse and Star Graphs](https://www.hackerrank.com/contests/sprint-debug/challenges/jesse-and-star-graphs) | 将每个顶点分裂成两个，根据题目约束建立流图，求一发最大流就是结果 | 最大流 |
|[Combination Lock](http://hihocoder.com/contest/hiho61/problem/1) | 红果果的线段树，代码又臭又长。。关键要正确实现lazy propagation的逻辑 | 线段树 |
|[不等式](http://hihocoder.com/contest/challenge14/problem/1) | 太坑爹了。。。X和C都不一定是整数啊。。文字游戏有意思么。。 | 阅读理解 |
|[赛车](http://hihocoder.com/contest/challenge14/problem/2) | 不能形成环就要求新路径不能指向自己的父节点，枚举被指向的顶点，顺带记录非该子树的最长路径，dfs两遍就好 | 图论 |
