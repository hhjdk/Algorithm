//
//  main.c
//  Algorithm_4_2
//
//  Created by sdx on 2018/5/29.
//  Copyright © 2018年 sdx. All rights reserved.
//  万能的搜索

#include <stdio.h>

struct note
{
    int x; // 横坐标
    int y; // 纵坐标
};
// 小岛地图
int b[10][10] = {
    {1,2,1,0,0,0,0,0,2,3},
    {3,0,2,0,1,2,1,0,1,2},
    {4,0,1,0,1,2,3,2,0,1},
    {3,2,0,0,0,1,2,4,0,0},
    {0,0,0,0,0,0,1,5,3,0},
    {0,1,2,1,0,1,5,4,3,0},
    {0,1,2,2,1,3,6,2,1,0},
    {0,0,3,4,8,9,7,5,0,0},
    {0,0,0,3,7,8,6,0,1,2},
    {0,0,0,0,0,0,0,0,1,0},
};
// 深度优先搜索 小岛地图
int aB[51][51];
int bookB[51][51],nB,mB,sumB;
void dfs(int x, int y ,int color);


//深度优先搜索，水管工
int aD[51][51];
int bookD[51][51],nD,mD,flafD = 0;
struct noteD
{
    int x;
    int y;
}s[100];
int topD = 0;
void dfsTwo (int x ,int y, int front);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
#pragma mark -- 万能的搜索 宝岛探险
#pragma mark -- 广度优先搜索
    /****
     在一个 10*10 的地图里面 ，其中 0 表示海洋， 1- 9 表示不同海拔高度的陆地
     飞机将会降落在（6，8）处，现在算出降落到的面积 坐标从 0开始 实际坐标（5，7）
     10 10 5 7
     
     1210000023
     3020121012
     4010123201
     3200012400
     0000001530
     0121015430
     0122136210
     0034897500
     0003786012
     0000000010
     
     
     
     **/
    /***
    struct note que [2501];
    int head ,tail;
    int a [51][51];
    int book[51][51] = {0};
    int i , j ,k,sum,n,m,startX,startY,tx,ty;
    
    // 定义一个方向数组
    int next[4][2] = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    // 读入n行m列，及小恒降落的目标的坐标
    printf("读入相关的行 和列，及相关坐标：");
    scanf("%d %d %d %d",&n,&m,&startX,&startY);
    
    for (i = 0; i < n; i ++) {
        printf("输入该行的相关数据 \n");
        for (j = 0; j < m; j ++) {
            //scanf("%d",&a[i][j]);
            a[i][j] = b[i][j];
        }
    }
    
    // 队列初始化
    head = 0;
    tail = 0;
    
    // 往队列里面插入降落的起始坐标
    que[tail].x = startX;
    que[tail].y = startY;
    tail ++;
    
    book[startX][startY] = 1;
    a[startX][startY] = -1; //给地图标记
    sum = 1;
    
    
    // 当队列不为空的时候循环
    while (head < tail) {
        
        // 枚举四个方向
        for (k = 0; k < 4; k ++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
             printf("====================\n");
            // 判断是否越界
            if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) {
                continue;
            }
            
            // 判断是否是陆地 或者曾经走过
            if (a[tx][ty] > 0 && book[tx][ty] == 0) {
                printf("sum ++ ............\n");
                // 是陆地并且没有走过
                sum ++;
                a[tx][ty] = -1; // 标记地图
                book[tx][ty] = 1;
                // 将新扩展的点加入队列
                que[tail].x = tx;
                que[tail].y = ty;
                tail ++;
            }
        }
        head ++;
        
    }
    
    // 输出岛屿的大小
    printf("\n岛屿的大小是%d\n",sum);
    // 打印染色之后的地图
    for (i = 0; i < n; i ++) {
        for (j = 0; j < m; j ++) {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    getchar();
     **/


    
    
    
#pragma mark -- 深度优先搜索
    /****
     在一个 10*10 的地图里面 ，其中 0 表示海洋， 1- 9 表示不同海拔高度的陆地
     飞机将会降落在（6，8）处，现在算出降落到的面积 坐标从 0开始 实际坐标（5，7）
     10 10 5 7
     
     1210000023
     3020121012
     4010123201
     3200012400
     0000001530
     0121015430
     0122136210
     0034897500
     0003786012
     0000000010
     
     
     
     **/

    /***
   int i , j ,startX, startY;
    // 读入n行m列，及小恒降落的目标的坐标
    printf("读入相关的行 和列，及相关坐标：");
    scanf("%d %d %d %d",&nB,&mB,&startX,&startY);
    
    for (i = 0; i < nB; i ++) {
        printf("输入该行的相关数据\n");
        for (j = 0; j < mB; j ++) {
            //scanf("%d",&a[i][j]);
            aB[i][j] = b[i][j];
        }
        bookB[startX][startY] = 1;
    }
    sumB = 1;
    // 从降落的位置开始
    dfs(startX, startY, -1);
    
    // 打印染色之后的地图
    for (i = 0; i < nB; i ++) {
        for (j = 0; j < mB; j ++) {
            printf("%3d",aB[i][j]);
        }
        printf("\n");
    }
    getchar();
     **/
    
#pragma 深度优化搜索，所有岛屿
    /***
    // 对地图里面的所有岛屿进行不同的染色
    int i , j ,numB = 0;
    // 读入n行m列，及小恒降落的目标的坐标
    printf("读入相关的行 和列");
    scanf("%d %d",&nB,&mB);
    
    for (i = 0; i < nB; i ++) {
        printf("输入该行的相关数据\n");
        for (j = 0; j < mB; j ++) {
            //scanf("%d",&a[i][j]);
            aB[i][j] = b[i][j];
        }

    }
    // 对每一个大于0的点尝试染色
    for (i = 0; i < nB; i ++) {
        for (j = 0; j < mB; j ++) {
            if (aB[i][j] > 0) {
                
                numB --;// 小岛需要染色的编号
                // 每发现一个岛屿染不同的颜色 每次都要减一
                bookB[i][j] = 1;
                dfs(i, j, numB);
                
            }
        }
        
    }
    
    // 打印染色之后的地图
    for (i = 0; i < nB; i ++) {
        for (j = 0; j < mB; j ++) {
            printf("%3d",aB[i][j]);
        }
        printf("\n");
    }
    
    printf("小岛的个数   %d\n",-numB);
    getchar();
     
     **/
    
#pragma mark --深度优先搜索 水管工游戏
    
    int i, j, num = 0;
    int c[5][4] = {
        {5,3,5,3},
        {1,5,3,0},
        {2,3,5,1},
        {6,1,1,5},
        {1,5,5,4}
    };
    printf("输入地图的行 和列:"); // 这里需要输入 4，3
    scanf("%d %d",&nD,&mD);
    // 读入游戏地图
    for (i = 1; i <= nD; i ++) {
        for (j = 1; j <= mD; j++) {
            //scanf("%d",&aD[i][j]);
            aD[i][j] = c[i - 1][j - 1];
        }
    }
    
    // 开始搜索，从0，0点开始，进水方向也是1
    dfsTwo(1, 1, 1);
    // 判断是否找到铺设方案
    if (flafD == 0)
    {
        printf("没有合适的铺设方案");
    }
    getchar();
    
    
    

    return 0;
}

// 深度优化搜索
void dfs (int x, int y, int color)
{
    // 定义一个方向数组
    int nextB[4][2] = {
        {0,1},  // 向右
        {1,0}, // 向下
        {0,-1}, // 向左
        {-1,0}  // 向上
    };
    int k ,tx, ty;
    aB[x][y] = color;
    
    // 枚举四个方向
    for (k = 0; k < 4; k ++) {
        tx = x + nextB[k][0];
        ty = y + nextB[k][1];
        
        // 判断是否越界
        if (tx < 0 || tx > nB - 1 || ty < 0 || ty > mB - 1) {
            continue;
        }
        
        // 判断是否是陆地 或者曾经走过
        if (aB[tx][ty] > 0 && bookB[tx][ty] == 0) {
            // 是陆地并且没有走过
            sumB ++;
            bookB[tx][ty] = 1;
            // 开始尝试下一个点
            dfs(tx, ty, color);

        }
    }
    return;
}

void dfsTwo (int x ,int y, int front)
{
    
    /**
        水管有两种，一种是直管，一种是弯管
     直管有两种形态    --:5    |:6
     弯管有四种形态    |_:1    |-:2    -|:3    _|:4
     
     ***/
    int i;
    // 判断是否达到终点·
    printf("( %d,%d) \n",x,y);
    if (x == nD  && y == mD + 1 ) {
        flafD = 1; // 找到铺设方案
        printf("铺设方案如下\n");
        for (i = 1; i <= topD ; i++) {
            printf("(%d,%d) ",s[i].x, s[i].y);
        }
        return;
    }
    
    // 判断是否越界
    if (x < 1 || x > nD  || y < 1 || y > mD  ) {
        return;
    }
    // 判断这个管道是否在路径中已经使用过
    if (bookD[x][y] == 1) {
        return;
    }
    
    bookD[x][y] = 1; // 标记当前这个管道
    // 将当前尝试的坐标入栈
    topD ++;
    s[topD].x = x;
    s[topD].y = y;
    printf("----------------------top =%d\n",topD);
    
    // 当前水管是直管的时候 直管有两种形态    --:5    |:6
    if (aD[x][y] >= 5 && aD[x][y] <=6) {
        
        // 判断进水口的位置
        if(front == 1){ //  进水口在左边的时候
            dfsTwo(x, y + 1, 1);    // 只能使用5号水管的摆放方式
        }
        
        if(front == 2){ //  进水口在上边的时候
            dfsTwo(x + 1, y, 2);     // 只能使用6号水管的摆放方式
        }
        
        if(front == 3){ //  进水口在右边的时候
            dfsTwo(x, y - 1, 3);    // 只能使用5号水管的摆放方式
        }
        
        if(front == 4){ //  进水口在下边的时候
            dfsTwo(x - 1, y, 4);    // 只能使用6号水管的摆放方式
        }
        
    }
    
    
    
    // 判断当前是弯管的时候 弯管有四种形态    |_:1    |-:2    -|:3    _|:4
    if (aD[x][y] > 0 && aD[x][y] < 5){
        
        // 判断进水口的位置
        if(front == 1){ //  进水口在左边的时候
            dfsTwo(x + 1, y, 2);    // 3号水管
            dfsTwo(x - 1, y, 4);    // 4号水管
        }
        
        if(front == 2){ //  进水口在上边的时候
            dfsTwo(x, y + 1, 1);    // 1号水管
            dfsTwo(x, y - 1, 3);    // 4号水管
        }
        
        if(front == 3){ //  进水口在右边的时候
            dfsTwo(x - 1, y, 4);    // 1号水管
            dfsTwo(x + 1, y, 2);    // 2号水管
        }
        
        if(front == 4){ //  进水口在下边的时候
            dfsTwo(x, y + 1, 1);    // 2号水管
            dfsTwo(x, y - 1, 3);    // 3号水管
        }
    }
    bookD[x][y] = 0 ;// 取消标记
    topD --;   // 将当前尝试的的坐标出栈
    return;

}
