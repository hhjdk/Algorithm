//
//  main.c
//  algorithm_1
//
//  Created by sdx on 2018/5/10.
//  Copyright © 2018年 sdx. All rights reserved.
//
//  ----------算法第一章（排序）----------------（桶排序， 冒泡排序， 快速排序）

#include <stdio.h>
// 用于冒泡排序 这里创建了一个结构体用来存储姓名和分数
struct student
{
    char name[21];
    char score;
};

int a[101];//定义全局变量，这两个变量需要在子函数中使用(用于快速排序)
void quickSort (int left, int right);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    #pragma -- 最简单的桶排序
/*
    // 桶排序  排序 0 - 10
    int a[11];
    int i,j,t = 0;
    for (i = 0;  i < 11; i ++) {
        a[i] = 0;
    }
    
    for (i = 1; i < 6; i ++) {  // 循环读入5个数
        printf("请输入分数：");
        scanf("%d",&t);  // 把每一个数读入到t里面
        printf("t ======%d\n",t);
     
        a[t]++; //  开始计数
        getchar();
    }
    
    for (i = 0; i < 11; i ++) {
        for (j = 0; j < a[i]; j ++) {
            printf("%d  ,",i);
        }
    }
*/
    
    /*
    // 桶排序 0 - 1000；
    
    int book[1001];
    int i,j,t,n;
    
    for (i = 0; i < 1001; i ++) {
        book[i] = 0;
    }
    printf("输入一个数n，表示之后将要输入n个数:");
    scanf("%d",&n);
    for (i = 0; i < n + 1 ; i ++) {
        // 循环读入n个数，并进行桶排序
        printf("请输入分数：");
        scanf("%d",&t);
        book[t]++;
    }
    
    for (i = 1000; i >= 0; i --) {
        for (j = 1; j <= book[i]; j ++) {
            printf("%d  ",i);
        }
    }
     */
    
    /*
    最后来说下时间复杂度的问题。代码中第 47 行的循环一共循环了 m 次(m 为桶的个数)， 第 52 行的代码循环了 n 次(n 为待排序数的个数)，第 59 行和第 60 行一共循环了 m+n 次。 所以整个排序算法一共执行了 m+n+m+n 次。我们用大写字母 O 来表示时间复杂度，因此该

    第 1 章 一大波数正在靠近——排序
    算法的时间复杂度是 O(m+n+m+n)即 O(2*(m+n))。我们在说时间复杂度的时候可以忽略较小 的常数，最终桶排序的时间复杂度为 O(m+n)。还有一点，在表示时间复杂度的时候，n 和 m 通常用大写字母即 O(M+N)。
     */
    
    
#pragma mark -- 比较简单的冒泡排序
    // (邻居好说话) 冒泡排序的基本思想是:每次比较两个相邻的元素，如果它们的顺序错误就把它们交换 过来。  时间复杂度 O(N 2)
    /**
    int a[100], i ,j,n,t;
    printf("请输入一个数n，代表之后还要输入n个数:");
    scanf("%d",&n);
    for (i = 0; i < n; i ++) {
        printf("请输入一个数：");
        scanf("%d",&a[i]); // 把数字n写入到a[i]里面
    }
    
    // 冒泡核心算法
    for (i = 0; i < n ; i ++) {  // n个数排序只需要 进行 n - 1 次
        for (j = 0; j < n - i; j ++) { // j < n - i 是应为 j 是在i后面的一个数，
            if(a[j]<a[j+1]) //比较大小并交换   （<） 为从大到小排序   (>) 为从小到大排序
            {
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
        }
    }
    printf("\n");
    for (i = 0; i < n; i ++) {
        printf("%d ",a[i]);
    }
     
     **/
    
    
    // 冒泡排序，结构体可以得到分数和分数对应的人
    /***
    struct student a[100], t; // a[100] 和 t 都是结构体对象
    int i,j,n;
    
    printf("输入一个数n，代表之后要排序的个数为n个:");
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        printf("请输入一个数");
        scanf("%s %d",a[i].name , &a[i].score);
        
    }
    
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n - i; j ++) {
            if (a[j].score < a[j+1].score) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("%s, %d ",a[i].name,a[i].score);
    }
    
     ***/
    
    #pragma mark -- 最常用的排序——快速排序
    /****
     快速排序之所以比较快，是因为相比冒泡排序，每次交换是跳跃式的。每次排序的时候 设置一个基准点，将小于等于基准点的数全部放到基准点的左边，将大于等于基准点的数全 部放到基准点的右边。这样在每次交换的时候就不会像冒泡排序一样只能在相邻的数之间进 行交换，交换的距离就大得多了。因此总的比较和交换次数就少了，速度自然就提高了。当 然在最坏的情况下，仍可能是相邻的两个数进行了交换。因此快速排序的最差时间复杂度和 冒泡排序是一样的，都是 O(N2)，它的平均时间复杂度为 O (NlogN)。其实快速排序是基于一 种叫做“二分”的思想
     ***/
    /**
    int i,n;
    // 读入数据
    printf("请输入一个数n，代表之后会有n个数来排序：");
    scanf("%d",&n);
    for (i = 0; i < n; i ++) {
        printf("请输入一个数：");
        scanf("%d",&a[i]);
    }
    
    quickSort(0, n - 1);
    
    // 输出排序结果
    for (i = 0; i < n; i ++) {
        printf("%d ",a[i]);
    }
    getchar(); // 永远只向缓存中输入一个字符。
     
     */
    
    #pragma mark -- 排序测试，小哼买书，
    
    // 桶排序 时间复杂度O(M + N); 先去重，在排序
    /**
    int a[1000],n,i,t;
    for (i= 1; i < 1000;i++) {
        a[i] = 0;
    }
    printf("输入一个数n,代表之后有n个数：");
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        printf("输入书的isbn号：");
        scanf("%d",&t);
        a[t] = 1;   // 标记过出现的isbn书号
    }
    
    for (i = 0; i < 1000; i++) {
        
        if (a[i] == 1) {
            printf("%d ",i);
        }
    }

    getchar();
          ***/
    
    // 冒泡排序，或者快速排序， 先排序，在去重

    int i,n ;
    printf("输入一个书号n,代表之后会有n本书：");
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        printf("输入一个书号：");
        scanf("%d",&a[i]);
    }
    
    quickSort(0, n - 1);
    
    for (i = 0; i < n; i ++) {   // 冒泡排序，和快速排序都是使用该方法去重
        if (a[i] != a[i + 1]) { // 去重
            printf("%d ",a[i]);
        }
    }
     getchar();

    
    
    return 0;
}


/**
 快速排序

 @param left 左边的哨兵下标
 @param right 右边的哨兵下标
 */
void quickSort (int left, int right)
{
    int i ,j ,t ,temp;
    if (left > right) {
        return;
    }
    
    temp = a[left]; // temp 中存的就是基准数
    
    i = left;
    j = right;
    
    while (i != j) {  // 左右两个哨兵没有相遇的时候
        
        // 顺序很重要，首先right哨兵从右往左开始移动
        while (a[j] >= temp && i < j) {
            j --;
        }
        //  然后left哨兵从左往右开始移动
        while (a[i] <= temp && i < j) {
            i ++;
        }
        
        // 两个哨兵都结束的时候，交换位置
        if (i < j) { // 两个哨兵没有相遇得时候
            t = a[i];
            a[i] = a[j];
            a[j] = t;
         }
    }
    //最终将基准数归位
    
    a[left] = a[i]; // 重新定义新的left哨兵
    a[i] = temp;
    
    quickSort(left, i - 1);  // 继续处理左边的，这是一个递归的过程
    quickSort(i + 1, right); // 继续处理右边的，只是一个递归的过程
    
}
