| 题目                                 | 基本思想                                                                                                                                                                                                                                        | 分类                             |
|--------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------|
|[面积最大的全1子矩阵](http://ac.jobdu.com/problem.php?pid=1497) | 枚举右下角的位置，从右到左扫描，不断更新最大面积，复杂度O(N^3)，又加了一点剪枝，基本卡时限AC，通过枚举瓶颈边，可以实现O(N^2)的时间复杂度，类似于leetcode中求直方图最大面积的题目                                                                | 枚举                             |
|[项目安排](http://ac.jobdu.com/problem.php?pid=1499) | 一个非常类似的题目是要求完成尽可能多的项目数，可以采用贪心完成。添加报酬之后，对于每一个项目，要么不做，此时最优值就是前一个项目截止时间所对应的最优值；要么做该项目，最优值是该项目的报酬加上在这一项目开始时间的最优报酬，动态规划O(nlgn)可解 | 动态规划                         |
|[最大值最小化](http://ac.jobdu.com/problem.php?pid=1502) | 二分搜索，对于每一个可能的值，通过贪心策略进行验证即可                                                                                                                                                                                          | 二分；贪心                       |
|[寻找表达式](http://ac.jobdu.com/problem.php?pid=1498) | 暴力枚举每一种可能的情形，最后3^14的大数据挂了，于是耍流氓打表了……                                                                                                                                                                              | 枚举，递归                       |
|[狼抓兔子](http://www.lydsy.com/JudgeOnline/problem.php?id=1001) | 题目要求图的最小割，但数据范围过大，用通常的算法求最小割会超时+超内存；平面图的最小割问题可以转化为对偶图的最短路问题，通过重构图，用spfa算法求最短路即可。                                                                                     | spfa最短路；平面图最小割         |
|[轮状病毒](http://www.lydsy.com/JudgeOnline/problem.php?id=1002) | 至今未想清楚递推公式究竟是怎么来的。。。                                                                                                                                                                                                        | 大整数；递推；生成树计数         |
|[物流运输](http://www.lydsy.com/JudgeOnline/problem.php?id=1003) | 对于每一天，枚举前面第一个发生路线变化的节点，进行状态转移，dp(n)=dp(j)+cost(j+1,n)*(n-j)+K,最后需要减掉一个多余的K，cost数组可以通过最短路算法预先计算出来                                                                                     | 动态规划；最短路                 |
|[越狱](http://www.lydsy.com/JudgeOnline/problem.php?id=1008) | 快速幂加上简单的组合数学                                                                                                                                                                                                                        | 组合数学                         |
|[Cards](http://www.lydsy.com/JudgeOnline/problem.php?id=1004) | 利用Polya定理来进行计数，分别考虑每一个置换，对每一个置换而言，同一个置换组中的节点必须被染成相同的染色，由于题目中对颜色之和做了限制，还需要结合动态规划求解方案数；最后，在模域除以一个数，需要乘以该数的逆元。                               | 组合数学；动态规划；快速幂       |
|[二进制中1的个数](http://ac.jobdu.com/problem.php?pid=1513) | __builtin_popcount搞定                                                                                                                                                                                                                          | 水                               |
|[把数组排成最小数](http://ac.jobdu.com/problem.php?pid=1504) | 不能简单按照字典序，注意一个字符串为另一个字符串前缀的情形                                                                                                                                                                                      | 排序                             |
|[明明的烦恼](http://www.lydsy.com/JudgeOnline/problem.php?id=1005) | 生成树计数的问题，根据prufer编码（第一次听说这种东西……），有标记的生成树跟一个长度为n-2的序列是一一对应的，因此生成树计数就转化成了组合计数的问题，首先选出有度数限制的顶点，然后根据多项式系数求解。由于涉及高精度运算，python是比较好的选择   | 生成树计数；组合数学；高精度     |
|[水平可见直线](http://www.lydsy.com/JudgeOnline/problem.php?id=1007) | 注意分析一条直线在什么情况下会被掩盖，将直线按照斜率升序排列，用栈来维护，每遇到一条直线，就从栈中取出两条直线计算交点，如该直线在交点以上，则将原来的直线覆盖，反之则没有覆盖，同时还需注意两条直线斜率相同的情形。                            | 栈；排序；几何                   |
|[神奇的国度](http://www.lydsy.com/JudgeOnline/problem.php?id=1006) | graph coloring在一般情况下是NP问题，但对于弦图有多项式算法。于是，先找出弦图中的完美消除序列，在逆向进行标记染色。第一次做和弦图相关的题目，长见识……                                                                                            | 弦图；图颜色；最大势算法         |
|[玩具装箱](http://www.lydsy.com/JudgeOnline/problem.php?id=1010) | 朴素的动态规划复杂度为O(N^2)，会超时；注意到决策具有单调性，于是可以二分更新决策区间，用双端队列来进行维护。神题啊……折腾了一天……                                                                                                                | 动态规划；双端队列；二分         |
|[最大数](http://www.lydsy.com/JudgeOnline/problem.php?id=1012) | 维护一个单调下降的队列，每次查询采用二分查找                                                                                                                                                                                                    | 单调队列；二分                   |
|[GT考试](http://www.lydsy.com/JudgeOnline/problem.php?id=1009) | 定义状态f(i, j)为长度为i的字符串最后j个字符为模板的前j个字符，f(i+1, j)和f(i, j)之间可以构造一个固定的转移矩阵，不管i的取值是多少，于是可以利用矩阵的快速幂来进行求解                                                                           | 动态规划；矩阵快速幂；字符串计数 |
|[最长上升子序列](http://ac.jobdu.com/problem.php?pid=1533) | 最长上升子序列可以通过O(N^2)的动态规划算法求解，但事实上还有O(nlgn)的解法，可以借助于二分查找实现，不过用stl里面的set更方便                                                                                                                     | 动态规划                         |
|[Spheres](https://www.hackerrank.com/contests/infinitum-jun14/challenges/spheres) | 首先利用物理上的相对运动把加速度归约到一个球上（高中物理没白学啊……），然后列出时间t时的距离函数，通过对t求导最小化该函数得到两个球的最近距离，如果该距离小于两球的半径之和，则说明会碰撞，反之则不会发生碰撞。                                  | 几何；求最值                     |
|[星球大战](http://www.lydsy.com/JudgeOnline/problem.php?id=1015) | 逆向思考，于是原问题转化为不断向图中加边和顶点，快速求出连通分量数目的问题，并查集可解。同时，由于顶点的数目较多，采用前向星表示更为高效，计数排序可以实现边的线性时间排序。                                                                    | 并查集；图论；前向星             |
|[最小生成树计数](http://www.lydsy.com/JudgeOnline/problem.php?id=1016) | 要求对最小生成树的选边过程有一个比较深刻的了解，不同最小生成树的边权集合是相同的，只是对于特定长度的边，选哪些组合并不确定。用位运算枚举，根据乘法原理可解。                                                                                    | 最小生成树；并查集；位运算       |
|[球形空间产生器](http://www.lydsy.com/JudgeOnline/problem.php?id=1013) | 根据球心定义，可以列出n个独立的方程，其中的平方项相互抵消，变成了一个线性方程，高斯消元法求解。                                                                                                                                                 | 几何；高斯消元法                 |
|[How many integers can you find](http://acm.hdu.edu.cn/showproblem.php?pid=1796) | 原子集合定义：可以被第i个数整除的数的个数；利用容斥原理可解，枚举是借助于位运算比较方便，当然，深搜也是可以的。                                                                                                                                 | 容斥原理；位运算                 |
|[逃生](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?pid=1001&cid=525) | 赤裸裸的拓扑排序，但是要注意字典序的问题，因此需要按照编号从大到小枚举                                                                                                                                                                          | 拓扑排序                         |
|[DZY Loves Sequences](http://codeforces.com/problemset/problem/446/A) | 枚举将要被改变的那个数字的位置，把它之前的最长上升序列和之后的最长上升序列拼接起来即可，需要注意边界条件。                                                                                                                                      | 枚举                             |
|[DZY Loves Modification](http://codeforces.com/problemset/problem/446/B) | 通过简单证明可知，行和列之间的操作顺序是可以交换的，因此可以枚举有i个行操作，剩余的均为列操作，对于所有的行操作而言，显然要遵循贪心的选择过程，为了提高时间效率，可以用堆来进行维护。                                                           | 贪心；最大堆                     |
|[Jzzhu and Cities](http://codeforces.com/problemset/problem/449/B) | 单源最短路径的改编版本，在一个图中，为了维持到一个顶点的最短距离保持不变，事实上只需要n-1条边，对应于Dijkstra算法中每个顶点最后被更新的边；同时为了提高时间效率，同样需要维护堆，否则O(N^2)会超时                                               | 单源最短路径；堆                 |
|[Jzzhu and Chocolate](http://codeforces.com/problemset/problem/449/A) | 假设在列上切了i刀，不难列出相应的最小面积表达式，为了最大化最小面积，只需要取两个边界值即可                                                                                                                                                     | 贪心                             |
|[Jzzhu and Apples](http://codeforces.com/problemset/problem/449/C) | 枚举每一个素数，它只能是与其倍数构成pair，如果这样的数共有偶数个，可以全部匹配，如果是奇数个，则需要剔除一个，将其放到最后的一个公共空间里，因此剔除2*p最合适                                                                                   | 构造性算法                       |
|[K尾相等数](http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=212) | 两个幂次对1000取模的结果应该相同，一旦碰到重复的结果以后就会不断重复，因此不断增加幂指数直到出现环                                                                                                                                              | 数论                             |
|[InvariantSets](TopCoder SRM 628 div2 1000) | 注意到一个环中的点，要么全选，要么全不选，因此可以缩点将原图转化为一个森林，然后再对每棵树利用动态规划计数                                                                                                                                      | 图论；组合计数；组合数学         |
|[BishopMove](TopCoder SRM 628 div2 250) | 很经典的小题目，嗯……奇偶性不同则不可达，在同一条对角线上则一步可达，否则需要两步                                                                                                                                                                | 观察规律……                       |
|[BracketExpressions](TopCoder SRM 628 div2 500) | 题目的数据规模较小，可暴力枚举，对于每一种情况，用栈来验证是否符合格式要求                                                                                                                                                                      | 栈；枚举                         |
|[受欢迎的牛](http://www.lydsy.com/JudgeOnline/problem.php?id=1051) | 一个有向图可以分成若干个强连通分量，其中至少有一个强连通分量无出边，如果这样的SCC数目大于1，则无解，等于1时进行计数即可，SCC的求解可以通过两次dfs，第一次求定点的拓扑序，第二次dfs求每个scc对应的编号                                           | 图论；强连通分量                 |
|[猴子舞](http://soj.me/show_problem.php?pid=1297) | 抽象成数学问题，就是将N进行分解，并且得到的数的lcm最大，i分成j个圈作为状态，可以很自然看出动态规划的特点                                                                                                                                        | 数论；动态规划                   |
|[大众比萨](http://acm.sdibt.edu.cn/JudgeOnline/problem.php?id=1133) | 经典的NP问题：可满足性问题。只能通过暴力求解，借助于位运算可以提高检验的效率                                                                                                                                                                    | 枚举；位运算                     |
|[点在哪](http://acm.sdibt.edu.cn/JudgeOnline/problem.php?id=1404) | 水……鬼都会做                                                                                                                                                                                                                                    | 几何                             |
|[DivisorsPower](TopCoder SRM 628 div1 250) | 注意到枚举n是没有希望的，而且也没有任何单调性能够让算法加速。但是可以枚举指数项，对于确定的幂指数，n可以通过二分确定，然后再通过因式分解判断是否合法                                                                                            | 二分；枚举                       |
|[CircuitsConstruction](TopCoder SRM 628 div1 500) | 题目所给的其实就是波兰表达式，要想最大化结果，只需要最大化一个运算符所覆盖的项数，这可以通过树的分治完成                                                                                                                                        | 递归；树形动态规划               |
|[GravityBomb](TopCoder SRM 200 div2 500) | 统计一下每列的X字符数目，取最小值，并进行消除                                                                                                                                                                                                   | 水题                             |
|[WindowManager](TopCoder SRM 200 div2 900) | 模拟即可，但情况数目比较多，需要细心一点                                                                                                                                                                                                        | 水题                             |
|[FindPoint](https://www.hackerrank.com/challenges/find-point) | 对称点，不多说。。                                                                                                                                                                                                                              | 水题                             |
|[SherlockAndPlanes](https://www.hackerrank.com/challenges/sherlock-and-planes) | 判断四点是否共面，只需要看三个向量所构成的立体图形的体积是否为零，可通过一次叉积和一次点积完成                                                                                                                                                  | 几何                             |
|[Spheres](https://www.hackerrank.com/challenges/spheres) | 转化为相对运动，然后借助于叉积求出点到直线的最短距离，需要注意相对运动的方向是否是背离的方向，通过点积判断角度是否是钝角即可                                                                                                                    | 几何                             |
|[志愿者招募](http://www.lydsy.com/JudgeOnline/problem.php?id=1061) | 列出每一天所要满足的约束方程，相邻方程相减可以保证每个变量出现两次，于是把方程作为顶点，进行构图，求出最小费用最大流                                                                                                                            | 最小费用最大流；图论；神题       |
|[Windy数](http://www.lydsy.com/JudgeOnline/problem.php?id=1026) | 进行动态规划，但是边界情况比较多，需要仔细设计状态以及状态之间的转移                                                                                                                                                                            | 动态规划                         |
|[矩阵游戏](http://www.lydsy.com/JudgeOnline/problem.php?id=1059) | 首先观察到同一行或者同一列的元素是不可能同时对最终结果产生贡献的，并且如果两个点的横纵坐标都不相同，一定可以都对最终结果产生贡献。于是需要找到n个点，任意两个点的横纵坐标均不相同，“互斥”的特点刚好符合二分图的性质，匈牙利算法求解             | 二分图匹配；深度搜索；匈牙利算法 |
|[修车](http://www.lydsy.com/JudgeOnline/problem.php?id=1070) | 将每个技术人员节点分裂成n个，每个表示倒数第几个修车，构图，求最小费用流                                                                                                                                                                         | 最小费用流；图论                 |
|[Courses](http://poj.org/problem?id=1469) | 二分图匹配，不多说。。                                                                                                                                                                                                                          | 二分图匹配                       |
|[树的最小高度](http://ac.jobdu.com/problem.php?pid=1536) | 问题的本质是求解树的直径，第一次广搜可以得到边界上的点，第二次广搜的结束点得到另一个边界上的点，最小高度就是半径的一半                                                                                                                          | 图论；广搜                       |
|[重叠的最长子串](http://ac.jobdu.com/problem.php?pid=1535) | Rabin-Karp绝对是神算法啊，搞个hash线性时间就可以完成字符串匹配，以后碰到字符串匹配的题目就都用它了。                                                                                                                                            | 字符串匹配                       |
|[买卖股票](http://ac.jobdu.com/problem.php?pid=1537) | 动态规划，不多说。。。                                                                                                                                                                                                                          | 动态规划                         |
|[数组中第K小的数](http://ac.jobdu.com/problem.php?pid=1534) | 很聪明的二分查找，对目标数字K进行二分，每次线性时间可以统计出小于等于K的数字的个数，然后决定走左分支还是右分支                                                                                                                                  | 二分查找                         |
|[Find The Shortest Common Superstring](http://acm.hdu.edu.cn/showproblem.php?pid=1841) | 和九度上的题目如出一辙，换了一个KMP匹配的解法，关键在于明白KMP算法在匹配失败时，指向模式串的指针恰好对应于最长的前缀。                                                                                                                          | KMP                              |
|[建筑抢修](http://www.lydsy.com/JudgeOnline/problem.php?id=1029) | 按照截止时间进行排序，然后依次选择，如果不能选的话，想办法减小当前所用的时间，可用堆来高效实现                                                                                                                                                  | 贪心；最小堆                     |
|[Boredom](http://codeforces.com/problemset/problem/455/A) | 居然是用动态规划，一开始以为有多复杂，还是自己的状态定义有问题                                                                                                                                                                                  | 动态规划                         |
|[小约翰逊的游戏John](http://www.lydsy.com/JudgeOnline/problem.php?id=1022) | 普通Nim游戏的简单变形，取到最后一个算赢改成了算输。只需要对单个石子堆的情况进行特殊分析即可。                                                                                                                                                   | 博弈                             |
|[生日快乐](http://www.lydsy.com/JudgeOnline/problem.php?id=1024) | 和棋盘分割的问题比较相似，分别考虑横向和纵向的情形，递归求解。                                                                                                                                                                                  | 递归                             |
|[糖果传递](http://www.lydsy.com/JudgeOnline/problem.php?id=1045) | 纯数学问题，列出代价函数，规约为最小化一系列绝对值之和的问题，只需要取各个常数项的中位数。                                                                                                                                                      | 数学                             |
|[互不侵犯King](http://www.lydsy.com/JudgeOnline/problem.php?id=1087) | 暴力枚举显然要挂，需要以行为状态进行状态转移，用位操作来表示各个状态之间的相容性                                                                                                                                                                | 基于状态压缩的动态规划           |
|[扫雷Mine](http://www.lydsy.com/JudgeOnline/problem.php?id=1088) | 关键在于注意到，每个格子只影响到相邻的三行，因此可以以行为状态进行转移，另外还需要记录当前行和下一行的雷放置情况                                                                                                                                | 动态规划                         |
|[圆上的整点](http://www.lydsy.com/JudgeOnline/problem.php?id=1041) | 神题啊……需要对勾股数有比较好的理解                                                                                                                                                                                                              | 数学；几何                       |
|[硬币购物](http://www.lydsy.com/JudgeOnline/problem.php?id=1042) | 神题……先考虑没有数目限制情形下的方案，再根据数目上的限制采用容斥原理删除不符合要求的方案                                                                                                                                                        | 动态规划；容斥原理               |
|[鬼谷子的钱袋](http://www.lydsy.com/JudgeOnline/problem.php?id=1192) | 构造出最优的策略，也就是以2为倍数递增选数，直至剩余的钱数少于要选的金币数目                                                                                                                                                                     | 水题                             |
|[字符串加密cipher](http://www.lydsy.com/JudgeOnline/problem.php?id=1031) | 赤裸裸的后缀数组，求出所有字符串后缀的rank数组来，再花费线性时间便可以求得目标字符串                                                                                                                                                            | 字符串后缀数组                   |
|[理想的正方形](http://www.lydsy.com/JudgeOnline/problem.php?id=1047) | 和sliding window挺像的，利用决策单调性进行预计算，得到一个二维范围内的最值，然后再平方时间扫描得到结果                                                                                                                                          | 决策单调性                       |
|[蜥蜴](http://www.lydsy.com/JudgeOnline/problem.php?id=1066) | “每次跳跃都会使高度减一”具有流网络的特征，因此对矩阵构建一个流网络，每个顶点一分为二，求解流网络的最大流                                                                                                                                        | 网络流；图论                     |
|[排列perm](http://www.lydsy.com/JudgeOnline/problem.php?id=1072) | 看到字符串长度只有10，显然暴力枚举……                                                                                                                                                                                                            | 枚举                             |
|[移动玩具](http://www.lydsy.com/JudgeOnline/problem.php?id=1054) | 把棋盘压缩成一个16位的整数，进行广度优先搜索即可                                                                                                                                                                                                | 广搜                             |
|[反素数](http://www.lydsy.com/JudgeOnline/problem.php?id=1053) | 列出素数表来，对每个素数可取的个数进行递归搜索即可，注意边界上的结果更新以及恰当剪枝                                                                                                                                                            | 数论；递归                       |
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
