#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//控制DOS界面
#include <conio.h>

#define Free 0 //空闲状态
#define Busy 1 //已用状态
#define OK 1    //完成
#define ERROR 0 //出错
#define MAX_length 1024 //内存大小

typedef int Status;
int flag;

typedef struct Menu {
    char things[20];
    int flag;
}STU;

STU moving[5] = {
        {"首次适应算法",101},
        {"下次适应算法",2},
        {"最佳适应算法",3},
        {"最坏适应算法",4},
        {"快速分配算法",5}
};

STU moving2[3] = {
        {"分配内存",101},
        {"回收内存",2},
        {"重新选择算法",3}
};


typedef struct freearea { //定义一个空闲区说明表结构
    long size;   //分区大小
    long address; //分区地址
    int state;   //状态
} ElemType;

// 线性表的双向链表存储结构
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;  //前趋指针
    struct DuLNode* next;   //后继指针
} DuLNode, * DuLinkList;

DuLinkList lastfind;
DuLinkList block_first; //头结点
DuLinkList block_last;  //尾结点
Status alloc(int);  //内存分配
Status free1(int);  //内存回收
Status First_fit(int);  //首次适应算法
Status Next_fit(int);   //下次适应算法
Status Best_fit(int);   //最佳适应算法
Status Worst_fit(int);  //最差适应算法
void show();//查看分配
Status Initblock();//开创空间表
Status insert(int request, DuLinkList area);
Status free5(int);
int choose_algorithm(int ch);
int choose_actions(int k, int ch);


int Quick_fit(int request);

Status Initblock() { //开创带头结点的内存空间链表
    block_first = (DuLinkList)malloc(sizeof(DuLNode));
    block_last = (DuLinkList)malloc(sizeof(DuLNode));
    block_first->prior = NULL;
    block_first->data.size = 0;
    block_first->next = block_last;
    block_last->prior = block_first;
    block_last->next = NULL;
    block_last->data.address = 0;
    block_last->data.size = MAX_length;
    block_last->data.state = Free;
    return OK;
}

//分配主存
Status alloc(int ch) {
    int request;
    printf("请输入需要分配的主存大小(单位:KB)：");
    scanf_s("%d", &request);
    if (request <= 0) {
        printf("分配大小不合适，请重试！\n");
        return ERROR;
    }

    switch (ch) {
        case 0: //选择首次适应算法
            if (First_fit(request) == OK) printf("分配成功！\n");
            else printf("内存不足，分配失败！\n");
            return OK;
        case 1: //选择下次适应算法
            if (Next_fit(request) == OK) printf("分配成功！");
            else {
                lastfind = block_first->next;
                if (Next_fit(request) == OK) printf("分配成功！");
                else printf("内存不足分配失败！");
            }
            return OK;
        case 2: //选择最佳适应算法
            if (Best_fit(request) == OK) printf("分配成功！\n");
            else printf("内存不足，分配失败！\n");
            return OK;
        case 3: //选择最差适应算法
            if (Worst_fit(request) == OK) printf("分配成功！\n");
            else printf("内存不足，分配失败！\n");
            return OK;
        case 4: //选择快速适应算法
            if (Quick_fit(request) == OK) printf("分配成功！\n");
            else printf("内存不足，分配失败！\n");
            return OK;
    }
}

//首次适应算法
Status First_fit(int request) {
    //为申请作业开辟新空间且初始化
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size = request;
    temp->data.state = Busy;

    DuLNode* p = block_first->next;
    while (p) {
        if (p->data.state == Free && p->data.size == request) {
            //有大小恰好合适的空闲块
            p->data.state = Busy;
            return OK;
            break;
        }
        if (p->data.state == Free && p->data.size > request) {
            //有空闲块能满足需求且有剩余
            temp->prior = p->prior;
            temp->next = p;
            temp->data.address = p->data.address;
            p->prior->next = temp;
            p->prior = temp;
            p->data.address = temp->data.address + temp->data.size;
            p->data.size -= request;
            return OK;
            break;
        }
        p = p->next;
    }
    return ERROR;
}
//下次适应算法
Status Next_fit(int request) {
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size = request;
    temp->data.state = Busy;

    if (lastfind != NULL) {
        while (lastfind) {
            if (lastfind->data.state == Free && lastfind->data.size == request) {
                lastfind->data.state = Busy;
                lastfind = lastfind->next;
                return OK;
                break;
            }
            if (lastfind->data.state == Free && lastfind->data.size > request) {
                temp->prior = lastfind->prior;
                temp->next = lastfind;
                temp->data.address = lastfind->data.address;
                lastfind->prior->next = temp;
                lastfind->prior = temp;
                lastfind->data.address = temp->data.address + temp->data.size;
                lastfind->data.size = lastfind->data.size - request;
                return OK;
                break;
            }
            lastfind = lastfind->next;
        }
    }
    else {
        DuLNode* p = block_first->next;
        while (p) {
            if (p->data.state == Free && p->data.size == request) {
                p->data.state = Busy;
                lastfind = p->next;
                return OK;
            }
            if (p->data.state == Free && p->data.size > request) {
                temp->prior = p->prior;
                temp->next = p;
                temp->data.address = p->data.address;
                p->prior->next = temp;
                p->prior = temp;
                p->data.address = temp->data.address + temp->data.size;
                p->data.size = p->data.size - request;
                lastfind = p;
                return OK;
            }
            p = p->next;
        }
    }
}

//最佳适应算法
Status Best_fit(int request) {
    int ch; //记录最小剩余空间
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size = request;
    temp->data.state = Busy;
    DuLNode* p = block_first->next;
    DuLNode* q = NULL; //记录最佳插入位置

    while (p) { //初始化最小空间和最佳位置
        if (p->data.state == Free && (p->data.size >= request)) {
            if (q == NULL) {
                q = p;
                ch = p->data.size - request;
            }
            else if (q->data.size > p->data.size) {
                q = p;
                ch = p->data.size - request;
            }
        }
        p = p->next;
    }

    if (q == NULL) return ERROR;//没有找到空闲块
    else if (q->data.size == request) {
        q->data.state = Busy;
        return OK;
    }
    else {
        temp->prior = q->prior;
        temp->next = q;
        temp->data.address = q->data.address;
        q->prior->next = temp;
        q->prior = temp;
        q->data.address += request;
        q->data.size = ch;
        return OK;
    }
}

//最差适应算法
Status Worst_fit(int request) {
    int ch; //记录最大剩余空间
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size = request;
    temp->data.state = Busy;
    DuLNode* p = block_first->next;
    DuLNode* q = NULL; //记录最佳插入位置

    while (p) { //初始化最大空间和最佳位置
        if (p->data.state == Free && (p->data.size >= request)) {
            if (q == NULL) {
                q = p;
                ch = p->data.size - request;
            }
            else if (q->data.size < p->data.size) {
                q = p;
                ch = p->data.size - request;
            }
        }
        p = p->next;
    }

    if (q == NULL) return ERROR;//没有找到空闲块
    else if (q->data.size == request) {
        q->data.state = Busy;
        return OK;
    }
    else {
        temp->prior = q->prior;
        temp->next = q;
        temp->data.address = q->data.address;
        q->prior->next = temp;
        q->prior = temp;
        q->data.address += request;
        q->data.size = ch;
        return OK;
    }
}

//快速适配算法
Status Quick_fit(int request) {
    //    printf("需要的空间%d\n",request);
    //    return 0;
    DuLinkList temp = block_first->next;
    DuLinkList p = block_first->next;
    DuLinkList temp_node = NULL;
    int min = 1024;
    while (p != NULL) {
        if (p->data.size >= request && p->data.state == Free && (p->data.size - request) < min) {
            temp_node = p;
            min = p->data.size - request;
            continue;
        }
        else {
            p = p->next;
        }
    }
    if (temp_node != NULL) {
        insert(request, temp_node);
        return OK;
    }

    while (temp != NULL) {
        if (temp->data.size >= request && temp->data.state == Free) {
            insert(request, temp);
            return OK;
        }
        temp = temp->next;
    }
    return !OK;
}

//request表示需要的大小，area表示找到的第一个空闲区大于request的类
Status insert(int request, DuLinkList area) {
    int temp_size = area->data.size;
    //printf("总的内存 ： %d\n",temp_size);
    while (temp_size / 2 >= request) {
        //printf("总的内存 ： %d\n",temp_size);
        DuLinkList temp_node = (DuLinkList)malloc(sizeof(DuLNode));
        temp_node->data.size = temp_size / 2;
        area->data.size /= 2;
        temp_node->data.address = area->data.size + area->data.address;
        temp_node->data.state = Free;
        //        printf("分配的内存 ： %d\n",area->data.size);
        //        printf("总的内存 ： %d\n",temp_size);

        temp_node->next = area->next;
        if (area->next != NULL)
            area->next->prior = temp_node;
        area->next = temp_node;
        temp_node->prior = area;

        temp_size = temp_size / 2;
        //        printf("总的内存 ： %d\n",temp_size);
    }
    area->data.state = Busy;

    //    printf("尾指针空闲的内存: %d\n", block_last->next->data.size);
    return OK;
}

//主存回收
Status free1(int flag) {
    DuLNode* p = block_first;
    for (int i = 0; i <= flag; i++)
        if (p != NULL)
            p = p->next;
        else
            return ERROR;

    p->data.state = Free;
    if (p->prior != block_first && p->prior->data.state == Free) { //与前面的空闲块相连
        p->prior->data.size += p->data.size;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        p = p->prior;
    }
    if (p->next != block_last && p->next->data.state == Free) { //与后面的空闲块相连
        p->data.size += p->next->data.size;
        p->next->next->prior = p;
        p->next = p->next->next;
    }
    if (p->next == block_last && p->next->data.state == Free) { //与最后的空闲块相连
        p->data.size += p->next->data.size;
        p->next = NULL;
    }
    return OK;
}

Status free5(int flag) {
    DuLNode* p = block_first;
    for (int i = 0; i <= flag; i++)
        if (p != NULL)
            p = p->next;
        else
            return ERROR;

    p->data.state = Free;
    //show();
    p = block_first->next;

    while (p->next != NULL) {
        if (p->data.state == Free && p->next->data.state == Free && p->next->data.size == p->data.size) {
            p->data.size *= 2;
            if (p->next->next != NULL) {
                p->next->next->prior = p;
                p->next = p->next->next;
                p = block_first->next;
                continue;
            }
            else {
                p->next = NULL;
                p = block_first->next;
                //printf("p的大小：%d\n",p->data.size);
                continue;
            }
        }
        else {
            p = p->next;
        }
    }
    return OK;
}


void color(int c) //设置字体颜色

{

    if (c >= 0 && c <= 15)

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

    else

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
void Line() {
    color(9);
    printf("-----------------------------------------------\n");
    color(16);
}

void looking() {//选择算法箭头
    int i;
    system("cls");
    printf("\n\n\n");
    for (i = 0; i < 5; i++) {

        if (moving[i].flag > 100) {
            color(14);
            printf("\t\t->");
            color(16);
        }
        else printf("\t\t ");
        printf("%s\n", moving[i].things);
    }
}

void think1(int x) {//上
    int i;
    if (x > 0 && x <= 4) {
        for (i = 0; i < 5; i++) {
            if (moving[i].flag > 100) {
                moving[i].flag -= 100;
                moving[i - 1].flag += 100;
                return;
            }
        }
    }
}

void think2(int x) {//下
    int i;
    if (x >= 0 && x < 4) {
        for (i = 0; i < 5; i++) {
            if (moving[i].flag > 100) {
                moving[i].flag -= 100;
                moving[i + 1].flag += 100;
                return;
            }
        }
    }
}

void looking2(int ch) {//操作内存箭头
    int i;
    system("cls");
    printf("\n\n\n");
    printf("\t\t 您选择了:%s\n\n\n", moving[ch].things);
    show();
    printf("\n\n\n");

    for (i = 0; i < 3; i++) {

        if (moving2[i].flag > 100) {
            color(14);
            printf("\t\t->");
            color(16);
        }
        else printf("\t\t ");
        printf("%s\n", moving2[i].things);
    }
    printf("\n\n\n");

}

void think3(int x) {//上
    int i;
    if (x > 0 && x <= 2) {
        for (i = 0; i < 3; i++) {
            if (moving2[i].flag > 100) {
                moving2[i].flag -= 100;
                moving2[i - 1].flag += 100;
                return;
            }
        }
    }
}

void think4(int x) {//下
    int i;
    if (x >= 0 && x < 2) {
        for (i = 0; i < 3; i++) {
            if (moving2[i].flag > 100) {
                moving2[i].flag -= 100;
                moving2[i + 1].flag += 100;
                return;
            }
        }
    }
}

//显示主存分配情况
void show() {
    int flag = 0;
    printf("\n主存分配情况:\n\n");
    DuLNode* p = block_first->next;
    printf("分区号\t起始地址\t分区大小\t状态\n");
    Line();
    while (p) {
        printf("  %d\t", flag++);
        printf("  %ld\t\t", p->data.address);
        if (p->data.state == Free) {
            color(14);
            printf("  %dKB\t\t", p->data.size);
            printf("空闲\n");
            color(16);
            Line();
        }
        else {
            color(12);
            printf("  %dKB\t\t", p->data.size);
            printf("已分配\n");
            color(16);
            Line();
        }
        p = p->next;
    }
}

int choose_algorithm(int ch) {//选择算法
    Initblock(); //开创空间表
    // int choice;  //操作选择标记
    while (1) {
        show();
        /*printf("请选择您的操作：");

        printf("\n1: 分配内存\n2: 回收内存\n0: 退出\n");*/
        char str;
        int i;
        int k;
        looking2(ch);
        for (;;)
            if (_kbhit()) {
                str = _getch();
                for (i = 0; i < 3; i++)
                    if (moving2[i].flag > 100) k = i;
                switch (str) {
                    case 80:think4(k); looking2(ch); break;
                    case 72:think3(k); looking2(ch); break;
                    case 13:choose_actions(k, ch); if (k == 2) return 0; else {
                    //show();
                    looking2(ch);
                    break;
                }
                }

            }



    }
}

int choose_actions(int k, int ch) {
    //scanf("%d", &choice);
    int flag;
    switch (k) {
        case 0:
            alloc(ch); // 分配内存
            break;
        case 1:
            printf("请输入您要释放的分区号：");
            scanf_s("%d", &flag);
            if (ch != 5)
                free1(flag);
            else
                free5(flag);
            break;
        case 2:
            return 0;
        default:
            break;
    }
}



//主函数
int main() {
    char str;
    int i;
    int k;
    looking();
    for (;;)
        if (_kbhit()) {

            str = _getch();
            for (i = 0; i < 5; i++)
                if (moving[i].flag > 100) k = i;
            switch (str) {
                case 80:think2(k); looking(); break;
                case 72:think1(k); looking(); break;
                case 13:choose_algorithm(k); looking(); break;
            }

        }

}


