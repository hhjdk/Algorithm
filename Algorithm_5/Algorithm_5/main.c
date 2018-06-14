//
//  main.c
//  Algorithm_5
//
//  Created by sdx on 2018/5/31.
//  Copyright © 2018年 sdx. All rights reserved.
//  // 图的遍历

#include <stdio.h>

int book[101],sum,n,e[101][101];
void dfs (int cur);



// 城市地图， 深度优先遍历
int infinity = 999999999; // 无穷大
int minD = 999999999, bookD[101],nD,eD[101][101];// 假设99999999是正无穷

/**
 城市地图深度优先遍历

 @param cur 当前所在城市编号
 @param dis 当前已经走过的距离
 */
void dfsD(int cur,int dis);




/**
  最少转机，广度优先遍历
 */
struct note
{
    int x;  // 城市编号
    int s;  // 转机次数
};

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
#pragma mark -- 深度优先遍历 dfs
    /**
     深度优先遍历： 首先以一个从未被访问过的点作为起始顶点，沿当前顶点的边走到未访问过的顶点，
     当没有未访问过的点的时候  ，则回到上一个顶点，继续试探访问别的顶点，直到所有的点都被访问过。
     
     图数据如下  这里我们使用 二维数组存储图数据
     0 1 1 ∞ 1
     1 0 ∞ 1 ∞
     1 ∞ 0 ∞ 1
     ∞ 1 ∞ 0 ∞
     1 ∞ 1 ∞ 0
     
     上面的数组中的第 i 行 和第 j 列，表示的就是顶点 i 到顶点 j 是否有边
     1 表示右边 ∞ 表示没有边 这里将自己到自己（即i等于j）设为0
      这种方法被称为 “图的邻接矩阵存储法” 来存储图数据
     
     5 5
     
     0 1
     0 2
     0 4
     1 3
     2 4
     **/
    
    /**
    int i ,j ,m ,a ,b;
    printf("输入行和列：");
    scanf("%d %d",&n,&m);
    
    // 初始化二维矩阵
    for (i = 0; i < n; i ++) {
        for (j = 0; j < m; j ++) {
            if (i == j) {
                e[i][j] = 0;
            } else
            {
                e[i][j]  = 999999999; // 999999999 充当无穷大
            }
        }
    }
    
    // 读入顶点之间的边
    for (i = 0;i < m ; i ++) {
        printf("输入两个顶点编号 a 和 b:");
        scanf("%d %d",&a,&b);
        e[a][b] = 1;
        e[b][a] = 1; // 这里是无向图片，所以两个方向都要设置有边
    }
    
    
    // 从0号城市出发
    book[0] = 1; // 标记0号顶点已经已经访问
    dfs(0); // 从0号顶点开始遍历
    getchar();
     **/
    
    
#pragma mark -- 广度优先遍历 bfs
    
    /**
     广度优先遍历：首先以一个未访问的顶点作为起始点，访问所有相邻的顶点，然后对每个相邻的顶点，在访问他们相邻的未被访问的顶点，直到所有的顶点都被访问过。
     
     5 5
     
     0 1
     0 2
     0 4
     1 3
     2 4
     **/
    /**
    int iB , jB,nB,mB,aB,bB,curB,bookB[101] = {0},eB[101][101];
    int queB[10001],headB,tailB;
    printf("输入行和列：");
    scanf("%d %d",&nB,&mB);
    
    // 初始化二维矩阵
    for (iB = 0; iB < nB; iB ++) {
        for (jB = 0; jB < mB; jB ++) {
            if (iB == jB) {
                eB[iB][jB] = 0;
            }
            else
            {
                eB[iB][jB]  = 999999999; // 999999999 充当无穷大
            }
        }
    }
    // 读入顶点之间的边
    for (iB = 0;iB < mB ; iB ++) {
        printf("输入两个顶点编号 a 和 b:");
        scanf("%d %d",&aB,&bB);
        eB[aB][bB] = 1;
        eB[bB][aB] = 1; // 这里是无向图片，所以两个方向都要设置有边
    }
    
    // 队列初始化
    headB = 0;
    tailB = 0;
    
    // 从0号顶点出发，将0号顶点加入队列
    queB[tailB] = 0;
    tailB ++;
    bookB[0] = 1; // 标记0号顶点已经访问
    
    while (headB < tailB) {
        curB = queB[headB];// 当前真正访问的顶点编号
        for (iB = 0; iB < nB; iB ++) {  // 从0 到 n-1依次尝试
            // 判断从顶点curB到顶点iB 是否有边，并且是否访问过
            printf("eb[%d][%d] =%d  bookB[%d] =%d \n",curB,iB,eB[curB][iB],iB,bookB[iB]);
            if (eB[curB][iB] == 1 && bookB[iB] == 0) {
                
                queB[tailB] = iB;// 顶点iB加入队列
                tailB ++;
                bookB[iB] = 1;
                printf(" head =%d  tailB  === %d\n",headB,tailB);
            }
            
            // 如果tailB 大于nB-1，则表明所有的顶点都已经被访问过
            if (tailB > nB - 1 ) {
                break;
            }
        }
        headB ++ ; // 当前扩展结束后，继续下个扩展
        
        printf("bbb head =%d  tailB  === %d\n",headB,tailB);

    }

    for (iB = 0; iB < tailB; iB ++) {
        printf("当前编号为%d\n",queB[iB]);
    }
    getchar();
     
     **/
    
    
#pragma mark -- 城市地图，深度优先遍历
    /**
     A 和 B 在两个城市，a在1号城市， b在5号城市 从A到B百度地图如何找出最短路线
     下列是地图数据
     
     5 8
     
     1 2 2
     1 5 10
     2 3 3
     2 5 7
     3 1 4
     3 4 4
     4 5 5
     5 3 3
     
     第一行 代表5个城市， 8条公路
     
     下面的8行的数据是一样的，a b c 相关数据
     其中 a和b分别代表一个城市 c代表这两个城市的距离
     
     可以用下列矩阵存储这些地图数据
     
     
     0 2 ∞ ∞ 8
     ∞ 0 3 ∞ 7
     4 ∞ 0 4 ∞
     ∞ ∞ ∞ 0 5
     ∞ ∞ 3 ∞ 0
     
     **/
    // 数组定义和上面不一样是因为上面是从"1"号城市开始 从"0"号城市开始 ，所以需要 每一个城市编号都要 -1
   /***
    int eDD[8][3]= {
        {0,1,2},
        {0,4,10},
        {1,2,3},
        {1,4,7},
        {2,0,4},
        {2,3,4},
        {3,4,5},
        {4,2,3}
    };
    int iD,jD,mD,aD = 0,bD = 0,cD;
    printf("输入城市个数和道路个数：");
    scanf("%d%d",&nD,&mD);
    // 初始化二维矩阵 （城市地图） 城市 * 城市 = n * n
    for (iD = 0; iD < nD; iD ++) {
        for (jD = 0; jD < nD; jD++) {
            if (iD == jD) {
                eD[iD][jD] = 0;//如上地图，i==j 的时候地图为0
            }
            else
            {
                eD[iD][jD] = infinity; // 其他先初始化为无穷大
            }
        }
    }
    
    // 读入城市之间的道路 方法1
//    for (iD = 0; iD < mD; iD ++) {
//        printf("请输入城市a 城市b 和两个城市之间的距离c：");
//        scanf("%d %d %d",&aD,&bD,&cD);
//        eD[aD][bD] = cD; // 存储两个城市之间的距离
//    }
    // 方法2
    for (iD = 0; iD < mD; iD ++) {
        for (jD = 0; jD < 3; jD ++) {
            if (jD == 0) {
                aD = eDD[iD][0];
            }
            if (jD == 1) {
                bD = eDD[iD][1];
            }
            if (jD == 2) {
                eD[aD][bD] = eDD[iD][2];
                printf(" a=%d b = %d c ====%d\n",aD,bD,eDD[iD][2]);
            }
        }
    }
    
    // 从 0 号城市开始出发
    bookD[0] = 1; // 标记0号城市已经走过
    dfsD(0, 0);// 前面的是城市编号， 后面的已经走过的距离
    
    printf("打印来个点之间的最短距离: %d \n",minD);
    
    getchar();
    **/
    
#pragma mark -- 最少转机 广度优先遍历
    
    /**
      A 和 B 一起去旅游， 他们现在位于 0号城市，目标是4号城市，可是0号城市没有4号城市的直接航线，下列是一些航班的相关信息，如何使他们转机最少
     
     5 7 0 4
     0 1
     0 2
     1 2
     1 3
     2 3
     2 4
     3 4
     
     第一行表示有 5个城市， 7条航线 ，0 表示起点城市， 4 表示终点城市
     下面的7条数据是 表示 两个城市之间有航线
     
     广度优先遍历，需要一个队列来存储城市编号·
     */
    int eBB[7][2]= {
        {0,1},
        {0,2,},
        {1,2},
        {1,3},
        {2,3},
        {2,4},
        {3,4}
    };
    struct note queB[2501];
    int eB[51][51] ,bookB[51] = {0};
    int headB ,tailB;
    int iB,jB,nB,mB,aB = 0,bB = 0,curB,startB,endB,flagB = 0;
    
    printf("请输入城市个数，航线条数，开始城市编号，目标城市编号：");
    scanf("%d %d %d %d",&nB,&mB,&startB,&endB);
    
    // 初始化二维矩阵（邻接矩阵）
    for (iB = 0; iB < nB; iB ++) {
        for (jB = 0; jB < nB; jB ++) {
            if (iB == jB) {
                eB[iB][jB] = 0;
            }else{
                eB[iB][jB] = infinity; // 无穷大
            }
        }
    }
    
    // 初始化航线
    for (iB = 0; iB < mB; iB ++) {
        // 方法一
        //printf("请输入哪两个城市之间有航线：");
        //scanf(" %d %d",&aB,&bB);
        
        //方法二 这里的循环是预先的数据不必输入
        for (jB = 0; jB < 2; jB ++) {
            if (jB == 0) {
                aB = eBB[iB][0];
            }
            if (jB == 1) {
                bB = eBB[iB][1];
            }
        }
        printf("ab == %d bB == %d\n",aB,bB);
        // 因为是无向图 所以设置两个方向
        eB[aB][bB] = 1; // 还有求的是最小转机，所以两个城市之间设置为1
        eB[bB][aB] = 1;
    }
    
    // 队列初始化
    headB = 0;
    tailB = 0;
    
    // 从开始号城市出发，将开始城市编号加入队列
    queB[headB].x = startB;
    queB[headB].s = 0;
    tailB ++;
    
    bookB[startB] = 1;// 标记startB城市在队列中
    
    // 队列不为空的时候循环
    while (headB < tailB) {
        
        curB = queB[headB].x; // 得到当前城市的城市编号
        printf("----------------queB[%d].x-- %d\n",headB,curB);
        
        for (iB = 0; iB < nB; iB ++) { //从0号城市到nB - 1依次尝试
            // 判断curB城市到iB号城市是否有航线，并判断该城市是否已经加入队列
            printf("========================== eB[%d][%d]==%d\n",curB,iB,eB[curB][iB]);
            if (eB[curB][iB] != infinity && bookB[iB] == 0) {
                // 有航线，并且没有加入到队列
                queB[tailB].x = iB;
                queB[tailB].s = queB[headB].s + 1;
                printf("ib==%d s=======%d \n",iB,queB[tailB].s);
                tailB ++;
                bookB[iB] = 1;
            }
            // 如果达到目标城市，停止扩展，结束任务，退出循环
            if (queB[tailB].x == endB) {
                printf("endB ===%d \n",endB);
                flagB = 1;// 标记任务完成
                break;
            }
        }
        
        if (flagB == 1) {
            break;
        }
        headB ++;
        printf("head ++ = %d\n",headB);
    }
    // 打印队列末尾城市的转机次数
    // tail 是指向队尾的下一个位置，所以这里需要减一
    printf("到到4号城市的最少转机次数是 %d \n",queB[tailB - 1].s);
    
    
    return 0;
}

void dfs (int cur)
{
    int i;
    printf("当前所在的顶点编号是 %d \n",cur);
    sum ++;  // 每访问一个顶点，sum 就加一
    if (sum == n) {
        return; // 所有的顶点都已经访问直接退出
    }
    for (i = 0; i < n; i ++) { // 从0 到 n -1 号顶点依次尝试，看哪些顶点与当前顶点相连
        
        // 判断当前顶点是否有边，，并且判断是否被访问过
        if (e[cur][i] == 1 && book[i] == 0) {
            
            book[i] = 1;
            dfs(i);
        }
    }
    return;
    
}


void dfsD(int cur,int dis)
{
    int jD;
    
    // 如果当前走的路大于之前的最小路程，没有必要继续尝试了，直接返回
    if (dis > minD) {
        return;
    }
    printf("cur ==========%d\n",cur);
    if (cur == nD - 1) {// 判断是否到达目标城市
        if (dis < minD) {
            printf("更新最小值为：%d\n",dis);
            minD = dis; // 更新最小值
        } return;
    }
    
    for (jD = 0; jD < nD; jD++) {
        // 从 0号城市到 nD - 1 号城市依次尝试
        // 判断 cur 当前城市到 jD城市是否有路，并判断城市jD是否已经走过
        //printf("循环--------jD ==%d\n",jD);
        if (eD[cur][jD] != infinity && bookD[jD] == 0) {
            //printf("走过路-----------------------\n");
            bookD[jD] = 1; // 标记已经走过
            dfsD(jD, dis + eD[cur][jD]);// eD 数组用于存储城市之间的距离
            bookD[jD] = 0; // 重新探索之后，取消之前的标记
        }
    }
    return;
}
