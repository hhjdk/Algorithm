//
//  main.c
//  Algorithm_6
//
//  Created by sdx on 2018/6/8.
//  Copyright © 2018年 sdx. All rights reserved.
//  最短路径

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
#pragma mark -- 多源最短路径 Floyd-warshall
    
    /**
     小明想去一些城市旅游，有些城市之间有公路，有些城市之间没有公路，为了节省时间，小明想要算出任意两个城市之间的最短路程
     
     地图是这样的， 有4个城市，8条公路 还有每一条公路的长度，这些公路都是单向的 这些我们都用一个4*4的矩阵来存储，二维数组e来存储
     
     0 2 6  4
     ∞ 0 3  ∞
     7 ∞ 0  1
     5 ∞ 12 0
     
     其中上面的数字代表城市之间公路的距离，∞是没有公路，0 是当前城市到当前城市
     列如
     第一行的 2 代表 0号城市到1号城市之间的距离为 2
     第一行的 4 代表 0号城市到3号城市之间的距离为 4
     第三行的 7 代表 2号城市到0号城市之间的距离是 7
     
     上一节用的深度或广度优先搜索可以得到最短路径
     现在用其他的方法来实现 Floyd-warshall
     
     可以想一下， 如果要让任意两点 （列如 i dao j）之间的距离变短，只能引入第三个点 k 并通过
     i -> k -> j 来缩短两点之间的最短路径
     有的时候甚至可以 两个或多个点来减少距离
     
     例如 上面地图 3号到2号城市 3->2 e[3][2] = 12 ,变成 3 -> 0 ->2 路程将变成11（e[3][0] + e[0][2] = 5 + 6 = 11）
     
     
     
     **/
    
    /***
    int eFW[8][3] =
    {
        {0,1,2},
        {0,2,6},
        {0,3,4},
        {1,2,3},
        {2,0,7},
        {2,3,1},
        {3,0,5},
        {3,2,12}
    }; // 数组 {a,b,c} a b 分别表示一个城市 c表示两个城市的距离
    int e[10][10],k,i,j,n,m,t1 = 0,t2 = 0,t3;
    int inf = 99999999; // 表示无穷大 infinity
    printf("输入城市个数，公路条数:");
    scanf("%d %d",&n,&m); // 4个城市 8条公路
    
    // 初始化二维数组
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j ++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = inf;
            }
        }
    }
    
    // 读入公路
    for (i = 0; i < m; i ++) {
        //printf("输入三个参数 两个城市编号 和他们之间的距离：");
        //scanf("%d %d %d",&t1,&t2,&t3);
        for (j =0; j < 3; j ++) {
            if (j == 0) {
                t1 = eFW[i][0];
            }
            if (j == 1) {
                t2 = eFW[i][1];
            }
            if (j == 2) {
                t3 = eFW[i][2];
                e[t1][t2] = t3;
            }
        }
    }
    
    // Floyd-warshall 核心算法语句  时间复杂度略高O(n3)
    // 下列方法需要注意的是∞无穷大的表示 我们这里的无穷大是 99999999  ，这里两个相加任然小于 2147483647，但是实际最好算一下，例如有100条公路，每条公路不超过100公里，则我们这边无穷大设置 > 100^2 列如 10001即可
    //
    for (k = 0; k < n; k ++) {
        for (i = 0; i < n; i ++) {
            for (j = 0; j < n; j ++) {
                if (e[i][k] < inf&& e[k][j] < inf && e[i][j] > e[i][k] + e[k][j]) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }
    printf("最终结果如下地图：\n");
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j ++) {
            printf(" %5d",e[i][j]);
        }
        printf("\n");
    }
    getchar();
     **/
    
#pragma mark -- 单源最短路径 Dijkstra 通过边实现松弛
    
    /**
     0号顶点 到 1、2、3、4、5号顶点的最短路径 ，这边也使用二维数组e来存储顶点之间距离的关系
     
     0 1 12 ∞ ∞  ∞
     ∞ 0 9  3 ∞  ∞
     ∞ ∞ 0  ∞ 5  ∞
     ∞ ∞ 4  0 13 15
     ∞ ∞ ∞  ∞ 0  4
     ∞ ∞ ∞  ∞ ∞  ∞
     
     Dijkstra 算法的核心思想是：每次找到离源点最近的一个顶点，然后以该顶点为中心进行进行扩展，最终得到源点到其他点的最短路径，基本步骤如下：
     
     1、将所有的顶点分为两部分 已知最短路径的顶点集合P和未知最短路径顶点Q，最开始，已知最短路径集合中只有源点一个顶点，这里用一个book数组来记录哪些点在集合P里面 book[i] 为1表示表示这个顶点在集合P里面，book[i] 为0表示这个顶点在集合Q中
     2、设置源点s到自己最短路径为0 即为dis[s] = 0, 若存在源点能直接到达的顶点i，则把dis[i]设为e[s][i].同时把其他源点不能直接达到的点的最短路径设置为∞
     3、在集合Q里面选用一个里源点s最近的顶点u（即dis[u] 最小），加入到集合p，并考察所有以点u为起点的边，对每一条边做松弛处理，列如一条存在从u到v的边，那么可以通过u->v 添加到尾部来拓展一条从s到v的路径，这条路径的长度是dis[u]+ e[u][v]来处理 ，如果这个值小于dis[v],我们可以用新的值来替代dis[v]
     4、重复第3步，直到Q集合为空，算法结束。最终dis数组中的值就是源点到所有点的最短路径
     
     **/
    /***
    int eDD[9][3]= {
        {0,1,1},
        {0,2,12},
        {1,2,9},
        {1,3,3},
        {2,4,5},
        {3,2,4},
        {3,4,13},
        {3,5,15},
        {4,5,4}
    };  // {a,b,c} 表示 顶点a 到顶点b的距离是c
    int eD[10][10],disD[10],bookD[10],iD,jD,nD,mD,t1D = 0,t2D = 0,t3D,uD = 0,vD,minD; // Dijkstra
    int inf = 99999999; //infinity;
    
    printf("读入顶点个数nD和边数mD:");
    scanf("%d %d",&nD,&mD);  // 6个点 9条边
    
    // 初始化二维数组
    for (iD = 0; iD < nD; iD ++) {
        for (jD = 0; jD < nD; jD ++) {
            if (iD == jD) {
                eD[iD][jD] = 0;
            } else {
                eD[iD][jD] = inf;
            }
        }
    }
    
    // 初始化边，也就是顶点之间的连线
    for (iD = 0; iD < mD; iD ++) {
        //printf("输入三个参数 两个顶点编号 和他们之间的距离：");
        //scanf("%d %d %d",&t1,&t2,&t3);
        for (jD =0; jD < 3; jD ++) {
            if (jD == 0) {
                t1D = eDD[iD][0];
            }
            if (jD == 1) {
                t2D = eDD[iD][1];
            }
            if (jD == 2) {
                t3D = eDD[iD][2];
                eD[t1D][t2D] = t3D;
            }
        }
    }
    
    // 初始化disD 数组，这里是0号顶点到其余各顶点的初始路程
    for (iD = 0; iD < nD; iD ++) {
        disD[iD] = eD[0][iD];
    }
    
    // bookD 数组初始化
    for (iD = 0; iD < nD; iD ++) {
        bookD[iD] = 0;
    }
    bookD[iD] = 1;
    
    
    // Dijkstra 算法核心 时间复杂度 O(n2)
    for (iD = 0; iD < nD - 1; iD ++) {
        
        // 找到离一号顶点最近的顶点
        minD = inf;
        for (jD = 0; jD < nD; jD ++) {
            // 判断在位置集合Q里面，并且距离比当前最短距离还短的点的编号
            if (bookD[jD] == 0 && disD[jD] < minD) {
                
                minD = disD[jD];
                uD = jD;
            }
        }
        
        bookD[uD] = 1;// 标记为已知最短距离集合P里面
        for (vD = 0; vD < nD; vD ++) {
            if (eD[uD][vD] < inf) {
                if (eD[uD][vD] + disD[uD] < disD[vD] ) {
                    disD[vD] = eD[uD][vD] + disD[uD];
                }
            }
        }
    }
    
    printf("输出最终结果如下\n"); // 0  1  8  4  13  17
    for (iD = 0; iD < nD; iD ++) {
        printf("%d  ",disD[iD]);
    }
    getchar();
    **/
    
#pragma mark -- 邻接表(Adjacency list)存储图
    
    /**
     上面的代码时间复杂度是 O(N^2),可以使用“堆”来进行优化 使得它的时间复杂度降低成 O(logN),
     根据 顶点 N 和边M的关系，可以分为 稀疏图 和 稠密图
     
     稀疏图 ：M 远小于 N^2
     稠密图 ：M 和 N^2比相对较大的
     
     使用“邻接表” 来代替“邻接矩阵”，时间复杂度变成 O(M+N)logN,
     在最坏的情况下 M = N^2 ,该算法 O(M+N)logN 的时间复杂度就"大于" O(N^2) ,但是大多数情况下不会又这么多边 也就是 M 没有这么大，所以
     O(M+N)logN 还是比 O(N^2) 小的
     
     如果是稀疏图  使用邻接表来代替邻接矩阵是一个很好的选择
     */
    
    // 图数据
    

    int ajlist[5][3] =
    {
        {0,3,9},
        {3,2,8},
        {0,1,4},
        {1,3,6},
        {0,2,7}
    };
    // 数组实现邻接表
    int nAj,mAj,iAj,jAj,kAj;
    // u v w 的数组要根据实际情况来设置，要比m(边)的最大值要大1
    int uAj[6],vAj[6],wAj[6];
    
    // first 和 next 数组大小要根据实际情况来设置，要比n(顶点)的最大值大1
    int firstAj[5] ,nextAj[5];
    printf("输入顶点n 和边m：");
    scanf("%d %d",&nAj,&mAj); // 4 5
    
    // 初始化firstAj数组的值都是-1，表示没有边  （用邻接表存储顶点和边）
    for (iAj = 0;iAj < nAj ; iAj ++) {
        firstAj[iAj] = -1;
    }
    for (iAj = 0; iAj < mAj; iAj ++) {
        //printf("输入三个参数 两个顶点编号 和他们之间的距离：");
        //scanf("%d %d %d",&t1,&t2,&t3);
        for ( jAj=0; jAj < 3; jAj ++) {
            if (jAj == 0) {
                uAj[iAj] = ajlist[iAj][0];//  存储顶点编号
            }
            if (jAj == 1) {
                vAj[iAj] = ajlist[iAj][1];//  存储顶点编号
            }
            if (jAj == 2) {
                wAj[iAj] = ajlist[iAj][2];//  存储前面两个顶点之间的边的长度
            }
        }
        // 关键句
        nextAj[iAj] = firstAj[uAj[iAj]];  // nextAj[iAj]用于存储 编号为iAj的 下一条边的编号
        firstAj[uAj[iAj]] = iAj;          // firstAj[uAj[i]] 用于存储 顶点编号为 uAj[iAj]的 第一条边(顶点可能有多条边)的编号
    }
    
    // 遍历顶点的边
    for (iAj = 0; iAj < nAj; iAj ++) {
        kAj  = firstAj[iAj];
        while (kAj != -1) {
            printf("%d %d %d\n",uAj[kAj],vAj[kAj],wAj[kAj]);
            kAj = nextAj[kAj];
        }
    }

    getchar();

    
    

    
    
    
    
    
    return 0;
}
