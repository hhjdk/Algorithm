//
//  main.c
//  Algorithm_4
//
//  Created by sdx on 2018/5/26.
//  Copyright © 2018年 sdx. All rights reserved.
//  万能的搜索

#include <stdio.h>
#include <time.h>
int a[10], book[10], n , total = 0;// C语言全局变量在没有赋值的时候，默认为0
int n3 ,m3 ,p3 ,q3,min3 = 99999999;
int a3[51][51], book3[51][51];
void dfs(int step); // 深度优先搜索
void dfsTwo(int step); // 深度优先搜索
void dfsThree(int x,int y, int step);
void dfsFour(int x,int y); // 深度优先搜索 解决炸弹人问题
char a4[20][21];
int book4[20][20],max4,mx4,my4,n4,m4;
int getNum4(int i, int j);

// 广度优化搜索
struct note
{
    int x; // 横坐标
    int y; // 纵坐标
    int f; // 父亲在队列的的编号 ，需要输出路径才需要使用
    int s; // 步数
};


// 广度优先搜索 炸弹人
struct noteB2
{
    int x;
    int y;
};
char aB2[20][21]; // 用来存储炸弹人地图
int getNum(int i, int j);

char* getDateTime(void);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
#pragma mark -- 深度优先搜索
    /***
     // 相关测试
    int a ,b ,c ,d ,e = 0 ;
    
    for (a = 0; a < 10; a ++) { // O(10^4)
        for (b = 0; b < 10; b ++) {
            for (c = 0; c < 10; c ++) {
                for (d = 0; d < 10; d ++) {
                    e = a;
                    if (a < b &&
                        b < c &&
                        c > d &&
                        d > e &&
                        e == a) {
                        printf("%d%d%d%d%d \n",a,b,c,d,e);
                    }
                }
            }
        }
    }
     
     **/
#pragma mark -- 深度题一
    /**
     题一、
     输入一个数n，输出1-n的全排列
     ，换一种说法 ，有n张扑克牌，放入n个箱子里面有多少种方法
     */
    /***
    printf("输入一个1 - 9的整数:");
    scanf("%d",&n);
    dfs(1); // 首先在一号盒子里面
    getchar();
     
     **/
    
#pragma mark -- 深度题二
    /**
     题二、有九张（1-9）的扑克牌，放入九个盒子里面，使得 _ _ _ + _ _ _ = _ _ _ 成立，
     现在优化一下之前的方法，之前使用枚举算法，时间复杂度太高
     */
    
    /**
    char * time = getDateTime();
    printf("时间 ====%s \n",time);
    dfsTwo(1); // 首先在第一个盒子里面
    printf("总共有%d种方法",total/2);
    printf("时间 ====%s \n",time);
    getchar();
     
     */
#pragma mark -- 深度题三
    /**
     题三、深度优先算法 最短路径
     
     看下列地图，可以的到点a 到点b的最短距离
     0 表示空地， 1 表示障碍物 其中 a 和 b 也是在空地里面 ，求a（0，0） 到 b（3，2） 的最短距离
     5行 4列
     0010
     0000
     0010
     0100
     0001
     **/
    
    /***
    int i , j , startX ,startY;
    
    // 读入n 和 m  n为行 m为列
    printf("请输入 行 和列:");
    scanf("%d %d",&n3, &m3);
    
    // 读入迷宫
    for (i = 0; i < n3; i ++ ) {
        printf("输入迷宫:\n");
        for (j = 0; j < m3; j ++) {
            scanf("%d",&a3[i][j]);
        }
    }

    // 读入 起点 和终点
    printf("输入起点坐标");
    scanf("%d%d",&startX,&startY);  // 设置起点坐标为 （startX,startY）
    printf("输入终点坐标");
    scanf("%d%d",&p3,&q3); // 设置终点坐标为 （p,q）
    
    
    // 从起点开始搜索
    book3[startX][startY] = 1; // 标记起点已经在路径上，防止再重复行走
    dfsThree(startX, startY, 0); // 第一个参数 为起点x ，第二个为起点y ，第三个为初始化步数0
    
    printf("输出最短步数 ，%d\n",min3);
    getchar();
     ***/
    
    
#pragma mark --  广度优化搜索 (Breadth First Search)BFS
    
    /**
     用广度优化搜索，解决上一个问题
     */
    /***
    struct note queB[2501]; // 因为地图大小不会超过 50 * 50 所以 队列扩展也不会超过2500个
    int aB[51][51], bookB[51][51];
    // 定义一个表示方向的数组
    int nextB [4][2] = {
        {0,1},      // 向右走
        {1,0},      // 向下走
        {0,-1},     // 向左走
        {-1,0}      // 向上走
    };
    int headB ,tailB;
    int iB,jB,kB,nB,mB,startX,startY,pB,qB,txB,tyB,flagB;
    
    printf("请输入行和列：");
    scanf("%d %d",&nB,&mB);
    for (iB = 0; iB < nB; iB ++) {
        printf("输入当前行地图");
        for (jB = 0; jB < mB; jB++) {
            scanf("%d",&aB[iB][jB]);
        }
    }
    
    printf("输入开始坐标startX，startY 结束坐标 pB qB");
    scanf("%d %d %d %d",&startX,&startY,&pB,&qB);
    
    // 队列初始化
    headB = 0;
    tailB = 0;
    
    // 往队列里面插入迷宫入口坐标
    queB[tailB].x = startX;
    queB[tailB].y = startY;
    queB[tailB].f = 0;
    queB[tailB].s = 0;
    tailB ++;
    bookB[startX][startY] = 1;
    
    
    flagB = 0;// 标记是否达到目标点，0表示没有达到，1表示已经达到了目标点
    // 当队列部位空得时候循环
    while (headB < tailB) {
        
        // 枚举4个方向
        for (kB = 0; kB< 4; kB ++) {
            
            // 计算下一个点的坐标
            txB = queB[headB].x + nextB[kB][0];
            tyB = queB[headB].y + nextB[kB][1];
            
            // 判断是否越界
            if (txB < 0 || txB > nB || tyB < 0 || tyB > mB ) {
                continue;
            }
            
            // 判断是否是障碍物，或者是已经走过的路
            if (aB[txB][tyB] == 0 && bookB[txB][tyB] == 0) {
                // 不是障碍物，并且没有走过的路
                // 标记已经走过的点，广度搜索和深度搜索不同，只需要走过一次不需要bookB数组还原
                bookB[txB][tyB] = 0;
                // 并且把这个点插入到队列里面
                queB[tailB].x = txB;
                queB[tailB].y = tyB;
                queB[tailB].f = headB;  // 打印路径需要，因为点事从head里面扩展出来的
                queB[tailB].s = queB[headB].s + 1;// 步数是父亲步数的 + 1
                tailB ++;
            }
            
            // 如果到达目标点，停止扩展，任务结束，退出循环
            if (txB == pB && tyB == qB) {
                flagB = 1;
                break;
            }
        }
        
        if (flagB == 1) {
            break;
        }
        headB ++; // 当一个点扩展结束之后，需要下一个点开始扩展
    }
    
    // 打印队列中末尾最后的一个点的步数
    // 注意 tail 是指向队尾 的下一个位置，这里需要减一
    //    for (iB = 0; iB < tailB; iB ++) {
    //        printf("%d ",queB[iB].f);
    //    }
    printf("\n最短的步数是：%d\n",queB[tailB - 1].s);
     
     ***/
#pragma mark -- 深度、解决之前炸弹人问题
    /***
    int i4,startX4,startY4;
    // 读入行和列，n表示有多少行，m表示有多少列 (startXB2, startYB2) 表示初始(行,列)坐标
    printf("读入行和列，开始坐标:");
    scanf("%d %d %d %d",&n4,&m4,&startX4,&startY4);
    
    // 读入n行字符串
    for (i4 = 0; i4 < n4; i4 ++) {
        printf("输入%d行地图:",i4);
        scanf("%s",a4[i4]);
    }
    

    
    // 从小人为值开始尝试
    book4[startX4][startY4] = 1;
    max4 = getNum4(startX4, startY4);
    mx4 = startX4;
    my4 = startY4;
    dfsFour(startX4, startY4);
    
    // 输出最大杀敌数，并且他的x 和y
    printf("\n将炸弹放置在(%d,%d),可以杀最多的敌人%d个\n",mx4,my4,max4);
    getchar();

    */
    
#pragma mark -- 广度、解决之前炸弹人问题
    
    
    
    /***
     具体地图模型如下
     13 * 13  3 3
     
     #############
     #GG.GGG#GGG.#
     ###.#G#G#G#G#
     #.......#..G#
     #G#.###.#G#G#
     #GG.GGG.#.GG#
     #G#.#G#.#.#.#
     ##G...G.....#
     #G#.#G###.#G#
     #...G#GGG.GG#
     #G#.#G#G#.#G#
     #GG.GGG#G.GG#
     #############
     
     具体消灭如下所示
     
     (x - 1, y)
     (x, y - 1) (x   ,  y) (x, y + 1)
     (x + 1, y)
     */

    struct noteB2 queB2[401]; // 假设地图宽高不超过 20 * 20 ，队列扩展不会超过 400
    int headB2 ,tailB2;
    int bookB2[20][20] = {0}; //定义一个标记数组，并且全部初始化为0
    int iB2,kB2,sumB2,maxB2 = 0,mxB2,myB2,nB2,mB2,startXB2,startYB2,txB2,tyB2;
    
    // 定义一个表示走的方向数组
    int nextB2 [4][2] = {
        {0,1},      // 向右走
        {1,0},      // 向下走
        {0,-1},     // 向左走
        {-1,0}      // 向上走
    };
    
    // 读入行和列，n表示有多少行，m表示有多少列 (startXB2, startYB2) 表示初始(行,列)坐标
    printf("读入行和列，开始坐标:");
    scanf("%d %d %d %d",&nB2,&mB2,&startXB2,&startYB2);
    
    // 读入n行字符串
    for (iB2 = 0; iB2 < nB2; iB2 ++) {
        printf("输入%d行地图:",iB2);
        scanf("%s",aB2[iB2]);
    }
    
    
    // 队列初始化
    headB2 = 0;
    tailB2 = 0;
    
    // 往队列里面插入小人的初始坐标
    queB2[tailB2].x = startXB2;
    queB2[tailB2].y = startYB2;
    tailB2 ++;
    bookB2[startXB2][startYB2] = 0;
    maxB2 = getNum(startXB2, startYB2);
    mxB2  = startXB2;
    myB2  = startYB2;
    
    // 当队列不为空的时候循环
    while (headB2 < tailB2) {
        // 枚举四个方向
        for (kB2 = 0; kB2 < 4; kB2 ++) {
            // 得到下一步尝试要走的坐标
            txB2 = queB2[headB2].x + nextB2[kB2][0];
            tyB2 = queB2[headB2].y + nextB2[kB2][1];
            
            // 判断是否越界
            if (txB2 < 0 || txB2 > nB2 || tyB2 < 0 || tyB2 > mB2) {
                continue;
            }
            
            if (aB2[txB2][tyB2] == '.' && bookB2[txB2][tyB2] == 0) {
                // 是平地并且是没有走过的路
                // 每一个点只入队一次，标记改点
                bookB2[txB2][tyB2] = 1;
                
                // 插入新的扩展点到队列里面
                queB2[tailB2].x = txB2;
                queB2[tailB2].y = tyB2;
                tailB2 ++;
                
                // 统计改扩展点可以消灭的敌人数
                sumB2 = getNum(txB2, tyB2);
                if (sumB2 > maxB2) {
                    maxB2 = sumB2;//记录最大杀敌
                    mxB2 = txB2; // 记录最大杀敌的x
                    myB2 = tyB2; // 记录最大杀敌的y
                }
            }
        }
        headB2 ++; // 继续下一个扩展
    }
    
    // 输出最大杀敌数，并且他的x 和y
    printf("\n将炸弹放置在(%d,%d),可以杀最多的敌人%d个\n",mxB2,myB2,maxB2);
    getchar();

    
    
    
    return 0;
}

void dfs (int step) // step 代表盒子的下标
{
    int i;
    if (step == n + 1) {  // 如果在n +1 个盒子里面，说明前面n个已经放好了扑克牌
        
        // 输出一个排列（1-n的扑克牌编号）
        for (i = 1; i <= n; i ++) {
            printf("%d",a[i]);
        }
        printf("\n");
        return;  // 返回之前的一步
    }
    
    // 接下来按照1、2、3、4... n  的顺序一一尝试
    for (i = 1;i <= n ;i ++ ) {
        // 判断扑克牌是否在手上
        if (book[i] == 0) {  // book[i] = 0 代表扑克牌在手上
            // 开始尝试使用扑克牌
            a[step] = i;  // 将i号扑克牌放入step箱子里面
            book[i] = 1; // 将book[i] 设置为1
            
            // 第step 个盒子已经放好扑克牌，接下来需要走到下个盒子里面
            dfs(step + 1); // 使用递归
            book[i] = 0; // 需要将刚才尝试的扑克牌收回，才可以继续操作
        }
    }
    return;
    
    
}

void dfsTwo(int step) // 深度优先搜索
{
    int i = 0;
    if (step ==10) { // 如果是第十个个盒子，说明之前的九个盒子里面都是有扑克牌的
        // 判断是否满足等式  _ _ _ + _ _ _ = _ _ _
        
        if ((100*a[1] + 10*a[2] + a[3])+(100*a[4] + 10*a[5] + a[6])==(100*a[7] + 10*a[8] + a[9]) ) {
            // 如果满足条件， 解加一，并打印这个解
            total ++;
            printf("%d%d%d+%d%d%d=%d%d%d \n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        return;
    }
    // 如果不是第十个盒子，哪应该放那张牌
    // 按照 1 - 9 的顺序尝试
    for (i = 1; i < 10; i ++) {
        
        // 判断扑克牌是否在手中
        if (book[i] == 0) {
            
            // 开始使用手中的扑克牌
            a[step] = i;
            book[i] = 1;
            
            // 第step个盒子已经放好了扑克牌，走到下面一个盒子里面
            dfsTwo(step + 1);
            book[i] = 0; // 收回手中的牌，才可以继续操作
        }
    }
}

// 得到 A点 到b点的最少步数
void dfsThree(int x,int y, int step) // 深度优先搜索
{
    int next [4][2] = {
        {0,1},      // 向右走
        {1,0},      // 向下走
        {0,-1},     // 向左走
        {-1,0}      // 向上走
    };
    int tx = 0, ty = 0,k;
    // 判断是否达到b点位置
    printf("x ==%d y ==%d  p3=== %d q3====%d \n",x,y,p3,q3);
    if (x == p3 && y == q3) {
       
        // 更新最小步数
        if (step < min3) {
             printf("输出最短步数 ，%d\n",min3);
            min3 = step;
        }
        return;
    }
    
    // 枚举四种走法
    for (k = 0; k < 4; k ++) {
        // 计算下一个点的坐标
        tx = x + next[k][0];  // x = 0 , y = 1 是因为是二维数组 [4][2] {0,1} 其中下标为0 为x 下标为1的为y。 k 数组是为长度为4
        ty = y + next[k][1];
        
        
        // 判断是否越界
        if ( tx < 0 || tx > n3 || ty < 0 || ty > m3) {
            continue;
        }
        // 判断改点是否是障碍物或者是已经走过的点
        if (a3[tx][ty] == 0 && book3[tx][ty] == 0) { // 0 为空地 1 表示障碍物
            // 不是障碍物 或者已经走过的点继续
            book3[tx][ty] = 1; //标记这个点已经走过
            dfsThree(tx, ty, step + 1);
            book3[tx][ty] = 0;
        }
    }
    return;
}

// 得到 A点 到b点的最少步数
void dfsFour(int x,int y) // 深度优先搜索
{
    int next4 [4][2] = {
        {0,1},      // 向右走
        {1,0},      // 向下走
        {0,-1},     // 向左走
        {-1,0}      // 向上走
    };
    int tx4 = 0, ty4 = 0,k4,sum4;

    // 计算当前这个点可以消灭的敌人总数
    sum4 = getNum4(x, y);
    
    if (sum4 > max4) {
       // 如果当前的点统计出能够消灭的敌人大于max，做相关更新
        max4 = sum4;
        mx4 = x;
        my4 = y;
        
    }
    // 枚举四种走法
    for (k4 = 0; k4 < 4; k4 ++) {
        // 计算下一个点的坐标
        tx4 = x + next4[k4][0];  // x = 0 , y = 1 是因为是二维数组 [4][2] {0,1} 其中下标为0 为x 下标为1的为y。 k 数组是为长度为4
        ty4 = y + next4[k4][1];

        
        
        // 判断是否越界
        if ( tx4 < 0 || tx4 > n4 - 1 || ty4 < 0 || ty4 > m4 - 1) {
            continue;
        }
        // 判断改点是否是障碍物或者是已经走过的点
        if (a4[tx4][ty4] == '.' && book4[tx4][ty4] == 0) { // 0 为空地 1 表示障碍物
            // 不是障碍物 或者已经走过的点继续
            book4[tx4][ty4] = 1; //标记这个点已经走过
            dfsFour(tx4, ty4);
        }
    }
    
    return;
}

// 根据坐标得到可以炸死的敌人
int getNum(int i, int j)
{
    int sumB2,xB2,yB2;
    sumB2 = 0; // sum用来计数（可以消灭的敌人数量），需要初始化为0
    // 将坐标i j 赋值给 xB2  yB2 这两个变量，以便zhih上下左右四个方向统计可以消灭的敌人
    
    // 向上统计可以消灭的敌人
    xB2 = i; yB2 = j;
    while (aB2[xB2][yB2] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (aB2[xB2][yB2] == 'G') {
            // 如果是敌人开始计数
            sumB2 ++;
        }
        xB2 -- ; // 继续向上统计
    }
    // 向下统计可以消灭的敌人
    xB2 = i; yB2 = j;
    while (aB2[xB2][yB2] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (aB2[xB2][yB2] == 'G') {
            // 如果是敌人开始计数
            sumB2 ++;
        }
        xB2 ++ ; // 继续向下统计
    }
    // 向左统计可以消灭的敌人
    xB2 = i; yB2 = j;
    while (aB2[xB2][yB2] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (aB2[xB2][yB2] == 'G') {
            // 如果是敌人开始计数
            sumB2 ++;
        }
        yB2 -- ; // 继续向左统计
    }
    // 向右统计可以消灭的敌人
    xB2 = i; yB2 = j;
    while (aB2[xB2][yB2] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (aB2[xB2][yB2] == 'G') {
            // 如果是敌人开始计数
            sumB2 ++;
        }
        yB2 ++ ; // 继续向右统计
    }
    
    
    return sumB2;
}

// 根据坐标得到可以炸死的敌人
int getNum4(int i, int j)
{
    int sum4,x4,y4;
    sum4 = 0; // sum用来计数（可以消灭的敌人数量），需要初始化为0
    // 将坐标i j 赋值给 xB2  yB2 这两个变量，以便zhih上下左右四个方向统计可以消灭的敌人
    
    // 向上统计可以消灭的敌人
    x4 = i; y4 = j;
    while (a4[x4][y4] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (a4[x4][y4] == 'G') {
            // 如果是敌人开始计数
            sum4 ++;
        }
        x4 -- ; // 继续向上统计
    }
    // 向下统计可以消灭的敌人
    x4 = i; y4 = j;
    while (a4[x4][y4] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (a4[x4][y4] == 'G') {
            // 如果是敌人开始计数
            sum4 ++;
        }
        x4 ++ ; // 继续向下统计
    }
    // 向左统计可以消灭的敌人
    x4 = i; y4 = j;
    while (a4[x4][y4] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (a4[x4][y4] == 'G') {
            // 如果是敌人开始计数
            sum4 ++;
        }
        y4 -- ; // 继续向左统计
    }
    // 向右统计可以消灭的敌人
    x4 = i; y4 = j;
    while (a4[x4][y4] != '#') {// 判断是不是墙壁   墙壁: #  敌人: G  空地: .
        //如果不是墙壁，进入则开始计数
        if (a4[x4][y4] == 'G') {
            // 如果是敌人开始计数
            sum4 ++;
        }
        y4 ++ ; // 继续向右统计
    }
    
    
    return sum4;
}

char* getDateTime()
{
    static char nowtime[20];
    time_t rawtime;
    struct tm* ltime;
    time(&rawtime);
    ltime = localtime(&rawtime);
    strftime(nowtime, 20, "%Y-%m-%d %H:%M:%S", ltime);
    return nowtime;
}
