//
//  main.c
//  Algorithm_3
//
//  Created by sdx on 2018/5/25.
//  Copyright © 2018年 sdx. All rights reserved.
//  // 枚举算法

#include <stdio.h>
#include <time.h>
#include <string.h>



char* getDateTime();
int fun (int x);
// 数的全排列
char string[9]="12345678";
int used[9]={0};
char output[9];
int length;
void arrangement(int d);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
#pragma mark -- 枚举算法
    // 枚举算法的基本思想是有序的尝试每一种可能
    /**
     题一、 _3 * 6528 = 3_ * 8256 ,在空格里面填入两个相同的数字保持等式成立,
     这是最简单的枚举算法
     */
    
    /**
    for (int i = 0; i < 10; i ++) {
        if ((i * 10 + 3)*6528 == (3*10+i)*8256) {
            printf("空格填入的数值是: %d \n",i);
        }
    }
     */
    
    /**
     题二、_ _ _ + _ _ _ = _ _ _ ,将1-9 分别填入空格，，每一个数字只可以使用一次，
     例如 173 + 286 = 459； ，还有 286 + 173 = 459 和之前的算一种可能，有多少种可能
     **/
    
    /**
    int a [10], i,total = 0 ,book[10], sum;  // a[i] 用来存储 9个数 ，使用book[10] 来存储数字出现的次数
    // 因为是 1- 9 ，所以，重1开始计算
    char * time = getDateTime();
    printf("时间 ====%s \n",time);
    // 时间复杂度 O(a^n)  时间复杂度太高
    for (a[1] = 1; a[1] < 10 ; a[1]++) {
        for (a[2] = 1; a[2] < 10 ; a[2]++) {
            for (a[3] = 1; a[3] < 10 ; a[3]++) {
                for (a[4] = 1; a[4] < 10 ; a[4]++) {
                    for (a[5] = 1; a[5] < 10 ; a[5]++) {
                        for (a[6] = 1; a[6] < 10 ; a[6]++) {
                            for (a[7] = 1; a[7] < 10 ; a[7]++) {
                                for (a[8] = 1; a[8] < 10 ; a[8]++) {
                                    for (a[9] = 1; a[9] < 10 ; a[9]++) {
                                        
                                        for (i = 1; i < 10; i ++) {  // 初始化book数组
                                            book[i] = 0;
                                        }
                                        
                                        for (i = 1; i < 10; i ++) {
                                            book[a[i]] = 1;
                                        }
                                        
                                        // 统计出现了多少个不同得数
                                        sum = 0;
                                        for (i = 1; i < 10; i ++) {
                                            sum += book[i];
                                        }
                                        
                                        // 如果出现了 9个数，并且满足等式 条件，这输出
                                        if (sum == 9 && (a[1]* 100 + a[2] * 10 + a[3]) + (a[4]* 100 + a[5] * 10 + a[6]) ==
                                            (a[7]* 100 + a[8] * 10 + a[9])) {
                                            
                                            printf("%d%d%d + %d%d%d = %d%d%d \n" ,a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
                                            total ++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("total === %d \n",total/2);
    time = getDateTime();
    printf("时间 ====%s \n",time);
    getchar();
     **/
    
#pragma mark -- 炸弹人
    
    /***
     题一、 假如你只有一个炸弹，这颗炸弹威力超强，可以炸死范围里面的所有敌人，放在那里，可以炸死更多的敌人
     
     地图模型化
     
     墙有两种，一种可以炸，一种不可以炸，当前只有一颗炸弹，
     所以
     成墙用    #   表示，炸弹不能穿墙，
     敌人用    G   表示，
     空地用    .   表示，炸弹只能放在空地上
     
     具体地图模型如下
     13 * 13

     #############
     #GG.GGG#GGG.#
     ###.#G#G#G#G#
     #.......#..G#
     #G#.###.#G#G#
     #GG.GGG.#.GG#
     #G#.#G#.#.###
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
    
    
    /***
    char a[20][20]; // 假设地图大小不超过20*20
    int i ,j, sum ,map = 0,p = 0,q = 0,x,y,n,m;
    
    printf("输入,n， m, 代表行和列:");
    scanf("%d %d",&n, &m); //  n 代表多少行， m代表多少列
    printf("n = %d , m = %d \n",n,m);
    
    // 读入n行字符
    for (i = 0; i < n; i ++) {
        printf("输入该行参数 %d",i);
        scanf("%s",a[i]);
    }
    
    // 利用两重循环便利枚举里面的每一个点
    for (i = 0; i < n; i ++) {
        
        for (j = 0; j < m ; j ++) {
            
            // 首先判断这个点是不是平底，是平底才可以防止炸弹
            
            if (a[i][j] == '.') {
                
                sum = 0; // sum 用来计数（可以消灭的敌人数），所以初始化需要为0
                
                // 将当期坐标 i , j 复制到两个新变量 x , y 中， 以便上下左右四个方向统计可以消灭的敌人数
                
                // 向上统计可以消灭的敌人数
                x = i ; y = j;   // 这里的坐标不是x,y 代表的意思是 第x行， 第y列
                while (a[x][y] != '#') {
                    
                    if (a[x][y] == 'G') {
                        sum ++;
                    }
                    x --; // x --继续向上统计可以消灭的敌人数
                    
                }
                
                // 向下统计可以消灭的敌人数
                x = i ; y = j;   // 这里的坐标不是x,y 代表的意思是 第x行， 第y列
                while (a[x][y] != '#') {
                    
                    if (a[x][y] == 'G') {
                        sum ++;
                    }
                    x ++; // x ++继续向下统计可以消灭的敌人数
                    
                }
                
                // 向左统计可以消灭的敌人数
                x = i ; y = j;   // 这里的坐标不是x,y 代表的意思是 第x行， 第y列
                while (a[x][y] != '#') {
                    
                    if (a[x][y] == 'G') {
                        sum ++;
                    }
                    y --; //
                    
                }
                // 向右统计可以消灭的敌人数
                x = i ; y = j;   // 这里的坐标不是x,y 代表的意思是 第x行， 第y列
                while (a[x][y] != '#') {
                    
                    if (a[x][y] == 'G') {
                        sum ++;
                    }
                    y ++;
                    
                }
                
                
                // 更新map 的值
                if (sum > map) {
                    map = sum;
                    
                    p = i; // 记录行
                    q = j; // 记录列
                }
                
            }
        }
    }
    
    printf("炸弹坐标为(%d ,%d)，可以炸死最多的敌人%d \n",p,q,map); // 结果 (9,9) 消灭8 个
    getchar();
     **/
    
#pragma mark -- 火柴棍等式
    
    /**
       题一、 有n根火柴棍，希望拼出 a + b = c 的相关等式， 其中等式 中的a b c都是用火柴拼出来的

     0为6根
     1为2根 ，
     2为5根
     3为5根
     4为4根
     5为5根
     6位6根
     7位3根
     8为7根
     9位6根
     
     注意：
     1、其中 ，加号 与等号 个需要2根火柴
     2、如果 a!= b 则 a + b = c 与 b + a = c视为不同的等式 （a,b,c 都大于0）
     3、所有火柴棍必须用上
     
     假如现在有 m <= 24 根火柴，那么可以拼出多少a + b  = c 的等式
     
     分析, 火柴最多有 24 根， 减去 + = 的四根 ，还有 20 根， 20根火柴最多可以组成 10 个 1 要满足 a + b = c ，那么 a b c 这三个数都不会大于 11111
     
     **/
    
    /**
    int a, b,c,m,sum = 0; // sum用来计数，所以sum初始化需要为0
    printf("请输入火柴棍的个数：");
    scanf("%d",&m);
    
    char * time = getDateTime();
    printf("时间 ====%s \n",time);

    
    // 开始枚举a 和 b
    for (a = 0; a < 11112; a ++)
    {
        for (b = 0; b < 11112; b++)
        {
            c = a + b;
            
            // 计算一个数需要的火柴个数 这里使用 fun 这个自定义方法
            // a 的火柴根数 + b 的火柴根数  + c 的火柴根数 = m - 4
            if (fun(a) + fun(b) + fun(c) == m - 4) {
                
                printf("%d + %d = %d \n",a,b,c);
                sum ++;
            }
            
        }
    }
    printf("一共可以拼出%d个等式\n",sum);
    
    time = getDateTime();
    printf("时间 ====%s \n",time);
     **/
    
    
#pragma  mark -- 数的全排列
    /**
     123 的全排列是 123 132  213 231 312 321
     **/
    /**
    for (int i =1; i < 4; i ++) {
        for (int j = 1; j < 4; j ++) {
            for (int k = 1; k < 4; k ++) {
                if (i != j && i != k && j != k) {
                    printf("%d%d%d \n",i,j,k);
                }
            }
        }
    }
     **/

    
    return 0;
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

int fun (int x)
{
    int num = 0;
    int f[10] = {6,2,5,5,4,5,6,3,7,6}; // 用一个数组来记录0 -9 每个数需要多少根火柴
    
    while (x/10 != 0) { // x/10 != 0 说明至少 x > 9
       // 获取x末尾的数字，并将说需要用到的火柴棍累加到num
        num += f[x%10];
        
        x = x/10; // 去掉末尾的数 ， 列如 123 变成12
    }
    
    // 最后在加上此时 x 所需要用到的火柴 （x此时一定是一位数）
    num += f[x];
    return num;
}


