#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//����DOS����
#include <conio.h>

#define Free 0 //����״̬
#define Busy 1 //����״̬
#define OK 1    //���
#define ERROR 0 //����
#define MAX_length 1024 //�ڴ��С

typedef int Status;
int flag;

typedef struct Menu {
    char things[20];
    int flag;
}STU;

STU moving[5] = {
        {"�״���Ӧ�㷨",101},
        {"�´���Ӧ�㷨",2},
        {"�����Ӧ�㷨",3},
        {"���Ӧ�㷨",4},
        {"���ٷ����㷨",5}
};

STU moving2[3] = {
        {"�����ڴ�",101},
        {"�����ڴ�",2},
        {"����ѡ���㷨",3}
};


typedef struct freearea { //����һ��������˵����ṹ
    long size;   //������С
    long address; //������ַ
    int state;   //״̬
} ElemType;

// ���Ա��˫������洢�ṹ
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;  //ǰ��ָ��
    struct DuLNode* next;   //���ָ��
} DuLNode, * DuLinkList;

DuLinkList lastfind;
DuLinkList block_first; //ͷ���
DuLinkList block_last;  //β���
Status alloc(int);  //�ڴ����
Status free1(int);  //�ڴ����
Status First_fit(int);  //�״���Ӧ�㷨
Status Next_fit(int);   //�´���Ӧ�㷨
Status Best_fit(int);   //�����Ӧ�㷨
Status Worst_fit(int);  //�����Ӧ�㷨
void show();//�鿴����
Status Initblock();//�����ռ��
Status insert(int request, DuLinkList area);
Status free5(int);
int choose_algorithm(int ch);
int choose_actions(int k, int ch);


int Quick_fit(int request);

Status Initblock() { //������ͷ�����ڴ�ռ�����
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

//��������
Status alloc(int ch) {
    int request;
    printf("��������Ҫ����������С(��λ:KB)��");
    scanf_s("%d", &request);
    if (request <= 0) {
        printf("�����С�����ʣ������ԣ�\n");
        return ERROR;
    }

    switch (ch) {
        case 0: //ѡ���״���Ӧ�㷨
            if (First_fit(request) == OK) printf("����ɹ���\n");
            else printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
        case 1: //ѡ���´���Ӧ�㷨
            if (Next_fit(request) == OK) printf("����ɹ���");
            else {
                lastfind = block_first->next;
                if (Next_fit(request) == OK) printf("����ɹ���");
                else printf("�ڴ治�����ʧ�ܣ�");
            }
            return OK;
        case 2: //ѡ�������Ӧ�㷨
            if (Best_fit(request) == OK) printf("����ɹ���\n");
            else printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
        case 3: //ѡ�������Ӧ�㷨
            if (Worst_fit(request) == OK) printf("����ɹ���\n");
            else printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
        case 4: //ѡ�������Ӧ�㷨
            if (Quick_fit(request) == OK) printf("����ɹ���\n");
            else printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
    }
}

//�״���Ӧ�㷨
Status First_fit(int request) {
    //Ϊ������ҵ�����¿ռ��ҳ�ʼ��
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size = request;
    temp->data.state = Busy;

    DuLNode* p = block_first->next;
    while (p) {
        if (p->data.state == Free && p->data.size == request) {
            //�д�Сǡ�ú��ʵĿ��п�
            p->data.state = Busy;
            return OK;
            break;
        }
        if (p->data.state == Free && p->data.size > request) {
            //�п��п���������������ʣ��
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
//�´���Ӧ�㷨
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

//�����Ӧ�㷨
Status Best_fit(int request) {
    int ch; //��¼��Сʣ��ռ�
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size = request;
    temp->data.state = Busy;
    DuLNode* p = block_first->next;
    DuLNode* q = NULL; //��¼��Ѳ���λ��

    while (p) { //��ʼ����С�ռ�����λ��
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

    if (q == NULL) return ERROR;//û���ҵ����п�
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

//�����Ӧ�㷨
Status Worst_fit(int request) {
    int ch; //��¼���ʣ��ռ�
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size = request;
    temp->data.state = Busy;
    DuLNode* p = block_first->next;
    DuLNode* q = NULL; //��¼��Ѳ���λ��

    while (p) { //��ʼ�����ռ�����λ��
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

    if (q == NULL) return ERROR;//û���ҵ����п�
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

//���������㷨
Status Quick_fit(int request) {
    //    printf("��Ҫ�Ŀռ�%d\n",request);
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

//request��ʾ��Ҫ�Ĵ�С��area��ʾ�ҵ��ĵ�һ������������request����
Status insert(int request, DuLinkList area) {
    int temp_size = area->data.size;
    //printf("�ܵ��ڴ� �� %d\n",temp_size);
    while (temp_size / 2 >= request) {
        //printf("�ܵ��ڴ� �� %d\n",temp_size);
        DuLinkList temp_node = (DuLinkList)malloc(sizeof(DuLNode));
        temp_node->data.size = temp_size / 2;
        area->data.size /= 2;
        temp_node->data.address = area->data.size + area->data.address;
        temp_node->data.state = Free;
        //        printf("������ڴ� �� %d\n",area->data.size);
        //        printf("�ܵ��ڴ� �� %d\n",temp_size);

        temp_node->next = area->next;
        if (area->next != NULL)
            area->next->prior = temp_node;
        area->next = temp_node;
        temp_node->prior = area;

        temp_size = temp_size / 2;
        //        printf("�ܵ��ڴ� �� %d\n",temp_size);
    }
    area->data.state = Busy;

    //    printf("βָ����е��ڴ�: %d\n", block_last->next->data.size);
    return OK;
}

//�������
Status free1(int flag) {
    DuLNode* p = block_first;
    for (int i = 0; i <= flag; i++)
        if (p != NULL)
            p = p->next;
        else
            return ERROR;

    p->data.state = Free;
    if (p->prior != block_first && p->prior->data.state == Free) { //��ǰ��Ŀ��п�����
        p->prior->data.size += p->data.size;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        p = p->prior;
    }
    if (p->next != block_last && p->next->data.state == Free) { //�����Ŀ��п�����
        p->data.size += p->next->data.size;
        p->next->next->prior = p;
        p->next = p->next->next;
    }
    if (p->next == block_last && p->next->data.state == Free) { //�����Ŀ��п�����
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
                //printf("p�Ĵ�С��%d\n",p->data.size);
                continue;
            }
        }
        else {
            p = p->next;
        }
    }
    return OK;
}


void color(int c) //����������ɫ

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

void looking() {//ѡ���㷨��ͷ
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

void think1(int x) {//��
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

void think2(int x) {//��
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

void looking2(int ch) {//�����ڴ��ͷ
    int i;
    system("cls");
    printf("\n\n\n");
    printf("\t\t ��ѡ����:%s\n\n\n", moving[ch].things);
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

void think3(int x) {//��
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

void think4(int x) {//��
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

//��ʾ����������
void show() {
    int flag = 0;
    printf("\n����������:\n\n");
    DuLNode* p = block_first->next;
    printf("������\t��ʼ��ַ\t������С\t״̬\n");
    Line();
    while (p) {
        printf("  %d\t", flag++);
        printf("  %ld\t\t", p->data.address);
        if (p->data.state == Free) {
            color(14);
            printf("  %dKB\t\t", p->data.size);
            printf("����\n");
            color(16);
            Line();
        }
        else {
            color(12);
            printf("  %dKB\t\t", p->data.size);
            printf("�ѷ���\n");
            color(16);
            Line();
        }
        p = p->next;
    }
}

int choose_algorithm(int ch) {//ѡ���㷨
    Initblock(); //�����ռ��
    // int choice;  //����ѡ����
    while (1) {
        show();
        /*printf("��ѡ�����Ĳ�����");

        printf("\n1: �����ڴ�\n2: �����ڴ�\n0: �˳�\n");*/
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
            alloc(ch); // �����ڴ�
            break;
        case 1:
            printf("��������Ҫ�ͷŵķ����ţ�");
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



//������
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


