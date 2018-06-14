//
//  main.c
//  algonrithm_2
//
//  Created by sdx on 2018/5/11.
//  Copyright © 2018年 sdx. All rights reserved.
//  栈，队列，链表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 队列结构体
struct queue {
    int data[1000]; // 队列主体，用于存储数据
    int head;      // 队列头
    int tail;      // 队列尾
};
/**
      其中 top 用来存储栈顶，数组 data 用来存储栈中的元素，大小设置为 10。因为只有 9 种不同的牌面，所以桌上最多可能有 9 张牌，因此数组大小设置为 10 就够了。
 */
struct stack {
    int data[10];
    int top;
};

/***
 每一个结点都由两个部分组成。左边的部分用来存放具体的数值，那么用一个整型变量 就可以;右边的部分需要存储下一个结点的地址，可以用指针来实现(也称为后继指针)。 这里我们定义一个结构体类型来存储这个结点，如下。
 ***/
struct node {
    int data;
    struct node *next;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
#pragma mark --- 队列的使用 先进先出 FIFO (first in first out)
    /**
     新学期开始了，小哈是小哼的新同桌(小哈是个小美女哦~)，小哼向小哈询问 QQ 号， 小哈当然不会直接告诉小哼啦，原因嘛你懂的。所以小哈给了小哼一串加密过的数字，同时 小哈也告诉了小哼解密规则。规则是这样的:首先将第 1 个数删除，紧接着将第 2 个数放到 这串数的末尾，再将第 3 个数删除并将第 4 个数放到这串数的末尾，再将第 5 个数删除...... 直到剩下最后一个数，将最后一个数也删除。按照刚才删除的顺序，把这些删除的数连在一 起就是小哈的 QQ 啦。现在你来帮帮小哼吧。小哈给小哼加密过的一串数是“6 3 1 7 5 8 9 2 4”。
     
     解释： 正确qq号 ： 615947283
     现在有 9 个数，9 个数全部放入队列之后 head=1;tail=10;此时 head 和 tail 之间的数就是
     目前队列中“有效”的数。如果要删除一个数的话，就将 head++就 OK 了，这样仍然可以保 持 head 和 tail 之间的数为目前队列中“有效”的数。这样做虽然浪费了一个空间，却节省了 大量的时间，这是非常划算的。新增加一个数也很简单，把需要增加的数放到队尾即 q[tail] 之后再 tail++就 OK 啦。

     **/
    
    /*
    int q[102] = {6,3,1,7,5,8,9,2,4} ,head,tail; // 头下标，尾下
    head = 0; // head指向第一个元素
    tail = 9; // 队列里面有九个元素，tail 指向最后一个
    
    while (head < tail) { // 当队列不为空的时候执行该方法
        
        // 打印队首，并将队首移除队列
        printf("%d",q[head]);
        head ++;
        
        // 将新的队首移动到队列末尾
        q[tail] = q[head];
        tail ++;
        // 再将队首移除队列
        head ++;
        
    }
    getchar();
     */
    
    
    // 结构体的队列操作
    /**
    struct queue q;
    int i;
    
    // 初始化队列
    q.head = 1;
    q.tail = 1;
    
    for (i = 0; i < 9;i++) {
        printf("输入一个数："); // 分别输入 6,3,1,7,5,8,9,2,4
        scanf("%d",&q.data[q.tail]);
        q.tail++;
    }
    
    while (q.head < q.tail) {
        
        printf("%d",q.data[q.head]);
        q.head ++;
        
        q.data[q.tail] = q.data[q.head]; // 新队首 移动到队尾
        q.tail ++;
        
        q.head ++ ;
    }
    
    // 打印得到的值是 615947283
    getchar();
     **/
    
#pragma mark -- 解密回文-- 栈 后进先出 LIFO (last in first out)
    
    /**
     栈究竟有哪些作用呢?我们来看一个例子。“xyzyx”是一个回文字符串，所谓回文字符 串就是指正读反读均相同的字符序列，如“席主席”、“记书记”、“aha”和“ahaha”均是回 文，但“ahah”不是回文。通过栈这个数据结构我们将很容易判断一个字符串是否为回文。
     首先我们需要读取这行字符串，并求出这个字符串的长度。
     
     需要导入下列库
     #include <string.h>
     **/
    /***
    char a[101], s[101];
    int i ,len ,mid,next,top;
    printf("请输入一行字符串：");
    gets(a); // 读入一行的字符串
    len = (int)strlen(a); // 求字符串的长度

    printf("len ===%d   a == %s\n",len,a);
    mid = len/2 - 1; // 求字符串的中点
    printf("mid ===%d \n",mid);
    
    
    top = 0 ; // 初始化栈
    
    // 将mid前的字符串依次入栈
    for (i = 0; i <= mid; i++) {
        top ++;
        s[top] = a[i];
        //        s[++top]  = a[i];  // 这个是上面的简写
    }
    
    // 判断是奇数还是偶数
    if (len%2 == 0) {
        // 偶数
        next = mid + 1;  // next mid右边的数的下标 abccba  （mid = 6/2 - 1 = 2）  （next = 2 + 1 = 3） ,下标为3就是第二个c
    }else{
        // 奇数
        next  = mid + 2; // next mid右边的数的下标 abcba  （mid = 5/2 - 1 = 1）  （next = 1 + 1 = 2） ,下标为2就是c
    }
    
    // 开始匹配
    for (i = next; i <= len-1; i ++) {
        if (a[i] != s[top]) {
            break;
        }
        top--;
    }
    
    // 如果top值 等于 0 ，说明所有字符都被一一匹配了
        
    if (top == 0) printf("YES");
    else printf("NO");
    getchar();
    ***/
    #pragma mark -- 纸牌游戏 小猫钓鱼
    
    /***
     
     星期天小哼和小哈约在一起玩桌游，他们正在玩一个非常古怪的扑克游戏——“小猫钓 鱼”。游戏的规则是这样的:将一副扑克牌平均分成两份，每人拿一份。小哼先拿出手中的 第一张扑克牌放在桌上，然后小哈也拿出手中的第一张扑克牌，并放在小哼刚打出的扑克牌 的上面，就像这样两人交替出牌。出牌时，如果某人打出的牌与桌上某张牌的牌面相同，即
     啊哈!算法
     可将两张相同的牌及其中间所夹的牌全部取走，并依次放到自己手中牌的末尾。当任意一人 手中的牌全部出完时，游戏结束，对手获胜。
     假如游戏开始时，小哼手中有 6 张牌，顺序为 2 4 1 2 5 6，小哈手中也有 6 张牌，顺序 为 3 1 3 5 6 4，最终谁会获胜呢?现在你可以拿出纸牌来试一试。接下来请你写一个程序来 自动判断谁将获胜。这里我们做一个约定，小哼和小哈手中牌的牌面只有 1~9。
     
     分析：
     小哼有两种操作，分别是出牌和赢牌。这恰 好对应队列的两个操作，出牌就是出队，赢牌就是入队。小哈的操作和小哼是一样的。而桌 子就是一个栈，每打出一张牌放到桌上就相当于入栈。当有人赢牌的时候，依次将牌从桌上 拿走，这就相当于出栈。
     

     
     所以，两个人对应两个队列，桌面上的牌对应一个栈
     **/

    /****
    struct queue  q1, q2;
    struct stack s;
    int i, t;
    int book[10];
    
    // 初始化 队列 为空 ，两个人手中都没有牌
    q1.head = 0; q1.tail = 0;
    q2.head = 0; q2.tail = 0;
    
    // 初始化栈为空，桌面上也没有牌
    s.top = 0;
    
    //初始化用来标记的数组，用来标记那些牌已经在桌子上
    for (i = 0;i < 9 ; i ++) {
        book[i] = 0;
    }
    
    // 分别读入 两个人初始化的牌，每个人6张
    // 小恒的六张牌
    for (i = 0;  i < 6; i++) {
        printf("小恒请输入一张牌，0-10：");
        scanf("%d",&q1.data[q1.tail]);
        q1.tail ++;
    }
    printf("\n\n");
    // 小哈的六张牌
    for (i = 0; i < 6; i ++) {
        printf("小哈请输入一张牌，0-10：");
        scanf("%d",&q2.data[q2.tail]);
        q2.tail ++;
    }
    
    while (q1.head < q1.tail && q2.head < q2.tail) // 当队列不为空的时候执行循环
    {
        t = q1.data[q1.head]; // 小恒出一张牌
        printf("\n小恒出一张牌：%d ",t);
        
        // 判断小恒是否赢牌
        if (book[t] == 0) {  // 有桶（桌面）里面是否有为t的牌
            
            // 小恒此轮没有赢牌
            q1.head ++ ; // 小恒打出一张牌， 说以这张牌要出队列
            s.top ++;
            s.data[s.top] = t;  // 刚刚打出的牌入栈
            //book[t] ++;   // 两个方法的意义一样，因为游戏规则，桌子只可能有一张一样的牌，所以使用等于1
            book[t] = 1; //标记桌面上有的牌
        }
        else
        {
            printf("小恒夹到了牌 \n");
            // 小恒此轮可以赢牌
            q1.head ++ ; // 小恒打出一张牌， 说以这张牌要出队列
            q1.data[q1.tail] = t;  // 吧打出的牌放在末尾
            q1.tail ++;
            
            while (s.data[s.top] != t) {
                book[s.data[s.top]] = 0; // 取消标记
                q1.data[q1.tail] = s.data[s.top];  //依次放入队尾
                printf("%d ",s.data[s.top]);
                q1.tail ++;
                s.top --;  // 栈中少了牌，所以要减一
            }
            // 作者源代码有问题 需要加入下列demo
            book[s.data[s.top]] = 0; // 取消标记
            q1.data[q1.tail] = s.data[s.top];  //依次放入队尾
            printf("%d ",s.data[s.top]);
            q1.tail ++;
            s.top --;  // 栈中少了牌，所以要减一
            
        }
        
        t = q2.data[q2.head]; // 小哈出一张牌
        printf("\n小哈出一张牌：%d ",t);
        
        // 判断小哈是否赢牌
        if (book[t] == 0) {
            
            // 小哈此轮没有赢牌
            q2.head ++;
            s.top ++;
            s.data[s.top] = t;
            book[t] = 1;
        }
        else
        {
             printf("小哈夹到了牌 \n");
            // 小哈此轮可以赢牌
            q2.head ++;
            q2.data[q2.tail] = t;
            q2.tail ++;
            
            while (s.data[s.top] != t) {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                printf("%d ",s.data[s.top]);
                q2.tail ++;
                s.top --;
            }
            // 作者源代码有问题 需要加入下列demo
            book[s.data[s.top]] = 0;
            q2.data[q2.tail] = s.data[s.top];
            printf("%d ",s.data[s.top]);
            q2.tail ++;
            s.top --;
        }
    }
    
    if (q2.head == q2.tail) {
        printf("小恒 win \n");
        printf("小恒手上的牌是:");
        for (i = q1.head; i < q1.tail; i ++) {
            printf("%d ",q1.data[i]);
        }
        
        if (s.top > 0) {  // 如果桌上有牌，依次输出桌上的牌
            printf("\n桌上的牌是:");
            for (i = 1; i < s.top + 1 ; i ++) {
                printf("%d ",s.data[i]);
            }
        }
        else
        {
            printf("\n桌面上没有牌");
        }
    }
    else
    {
        printf("小哈 win \n");
        printf("小哈手上的牌是:");
        for (i = q2.head; i < q2.tail; i ++) {
            printf("%d ",q2.data[i]);
        }
        if (s.top > 0) {  // 如果桌上有牌，依次输出桌上的牌
            printf("\n桌上的牌是:");
            for (i = 1; i < s.top + 1; i ++) {
                printf("%d ",s.data[i]);
            }
        }
        else
        {
            printf("\n桌面上没有牌");
        } //365432 145322  小恒win  4 3 桌面 3
    }
     getchar();
     
     
     ***/
    
    
#pragma -- mark 指针 链表
   // 使用 malloc方法需要导入 #include <stdlib.h>
    /**
    int * p; // 定义一个指针p
    p = (int *)malloc(sizeof(int));  // 指针p动态获取分配内存地址(动态申请空间)
    *p = 10; // 向指针p指向的内存空间 输入10
    printf("%d",*p); // 打印指针指向内存的值
    
    getchar();
     **/
    
    
    /***
     每一个结点都由两个部分组成。左边的部分用来存放具体的数值，那么用一个整型变量 就可以;右边的部分需要存储下一个结点的地址，可以用指针来实现(也称为后继指针)。 这里我们定义一个结构体类型来存储这个结点，如下。
     
     如何建立链表呢?首先我们需要一个头指针 head 指向链表的最开始。当链表还没有建 立的时候头指针 head 为空(也可以理解为指向空结点)。
     ***/
    
    /***
    int a,i,n;
    struct node *head,*p = NULL,*q = NULL,*t = NULL;
    head = NULL; // 头指针初始为空
    printf("输入数字n，代表之后需要输入n个数：");
    scanf("%d",&n);
    for (i = 0; i < n; i ++) {  // 循环读入n个数
        printf("输入一个链表节点数据:");
        scanf("%d",&a);
        // 动态申请空间，用来存放一个节点，并用临时指针p指向这个节点
        p = (struct node*)malloc(sizeof(struct node));

        p->data = a;  // 将数据存储到当前的·data域里面
        p->next = NULL; // 设置当前的后继指针指向空，也就是当前节点的下一个节点为空
        if (head == NULL) {
            head = p;  // 如果是第一个节点，将头指针指向这个节点
        }
        else
        {
            q->next = p; // 如果不是第一次创建的节点，则将上一个的后继指针指向当前节点
        }
        q = p; // 指针q也指向当前节点

    }

    t = head;
    printf("插入一个数：");
    scanf("%d",&a);
    while (t != NULL) {  // 当没有达到链表尾部得时候循环
        if (t->next->data > a) {   // 如果当前节点的下一个节点值大于待插入得数，将插入到中间存放新增节点
            p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
            p->next = t->next;  // 新增节点的后继指针指向当前节点的后继指针指向的节点
            t->next = p; // 当前节点的后继指针指向新增节点
            break;  // 插入完毕，退出循环
        }
        t = t->next;  // 继续下一个节点
    }
    
    // 输出链表里面的所有数
    t = head;
    while (t != NULL) {
        printf("%d ",t->data);
        t = t->next;  // 继续下一个节点
    }
    free(p);
    //   初始9个数 1 4 6 7 8 9 12 33 45 ，插入 11  得到 1 4 6 7 8 9 11 12 33 45
    getchar();
    ***/
    
#pragma mark --- 模拟链表
    
    /*
     第一个整型数组 data 是用来存放序列中具体数字的，另外一个整型 数组 right 是用来存放当前序列中每一个元素右边的元素在数组 data 中位置的
     **/
    
    int data [101], right[101];
    int i,n,t,len;   // t 为下一个节点 len 为长度
    // 读入已有得数
    printf("输入要读的个数：");
    scanf("%d",&n);
    for (i = 1; i < n+1; i++) {
        printf("输入一个链表节点数据:");
        scanf("%d",&data[i]);
    }
    len = n;
    
    // 初始化数组right
    for (i = 1; i < n+1; i ++) {
        if (i != n) {
            right[i]  = i +1;
        }
        else
        {
            right[i] = 0;
        }
    }
    
    /// 直接在数组末尾添加一个数
    len ++; // 长度加一
    printf("插入一个数：");
    scanf("%d",&data[len]);
    
    // 重链表头部开始便利
    t = 1;
    while (t != 0) {
        
        if (data[right[t]] > data[len]) {  //如果当前节点的下一个节点值大于待插入得数，将插入到中间存放新增节点
            right[len] = right[t]; // 新插入的下一个节点 等于 当前节点的下一个节点编号
            right[t] = len;   // 当前节点的下一个编号，就是新插入的编号
            break;
        }
        t = right[t];
    }
    
    // 输出链表所有得数
    t = 1;
    while (t != 0) {
        printf("%d ",data[t]);
        t=right[t];
    }
    
    return 0;
}
