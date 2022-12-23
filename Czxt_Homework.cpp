#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Free 0 //����״̬
#define Busy 1 //����״̬
#define OK 1    //���
#define ERROR 0 //����
#define MAX_length 1024 //�ڴ��С
#define MIN_QUICK_FIT 30 //������Ӧ�����㷨��С���ɷֵĿռ��С

typedef int Status;
int flag;

typedef struct freearea { //����һ��������˵����ṹ
    long size;   //������С
    long address; //������ַ
    int state;   //״̬
} ElemType;

// ���Ա��˫������洢�ṹ
typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;  //ǰ��ָ��
    struct DuLNode *next;   //���ָ��
} DuLNode,*DuLinkList;

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
Status insert(int request , DuLinkList area);
Status insert1(int request , DuLinkList area);
Status free5(int);

int Quick_fit(int request);

Status Initblock() { //������ͷ�����ڴ�ռ�����
    block_first=(DuLinkList)malloc(sizeof(DuLNode));
    block_last=(DuLinkList)malloc(sizeof(DuLNode));
    block_first->prior=NULL;
    block_first->data.size=0;
    block_first->next=block_last;
    block_last->prior=block_first;
    block_last->next=NULL;
    block_last->data.address=0;
    block_last->data.size=MAX_length;
    block_last->data.state=Free;
    return OK;
}

//��������
Status alloc(int ch) {
    int request;
    printf("��������Ҫ����������С(��λ:KB)��");
    scanf("%d", &request);
    if(request <= 0) {
        printf("�����С�����ʣ������ԣ�\n");
        return ERROR;
    }

    switch (ch) {
        case 1: //ѡ���״���Ӧ�㷨
            if(First_fit(request)==OK) printf("����ɹ���\n");
            printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
        case 2: //ѡ���´���Ӧ�㷨
            if(Next_fit(request)==OK) printf("����ɹ���");
            else {
                lastfind=block_first->next;
                if(Next_fit(request)==OK) printf("����ɹ���");
                else printf("�ڴ治�����ʧ�ܣ�");
            }
            return OK;
        case 3: //ѡ�������Ӧ�㷨
            if(Best_fit(request)==OK) printf("����ɹ���\n");
            else printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
        case 4: //ѡ�������Ӧ�㷨
            if(Worst_fit(request)==OK) printf("����ɹ���\n");
            else printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
        case 5: //ѡ�������Ӧ�㷨
            if(Quick_fit(request)==OK) printf("����ɹ���\n");
            else printf("�ڴ治�㣬����ʧ�ܣ�\n");
            return OK;
    }
}

//�״���Ӧ�㷨
Status First_fit(int request) {
    //Ϊ������ҵ�����¿ռ��ҳ�ʼ��
    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size=request;
    temp->data.state=Busy;

    DuLNode *p=block_first->next;
    while(p) {
        if(p->data.state==Free && p->data.size==request) {
            //�д�Сǡ�ú��ʵĿ��п�
            p->data.state=Busy;
            return OK;
            break;
        }
        if(p->data.state==Free && p->data.size>request) {
            //�п��п���������������ʣ��
            temp->prior=p->prior;
            temp->next=p;
            temp->data.address=p->data.address;
            p->prior->next=temp;
            p->prior=temp;
            p->data.address=temp->data.address+temp->data.size;
            p->data.size-=request;
            return OK;
            break;
        }
        p=p->next;
    }
    return ERROR;
}
//�´���Ӧ�㷨
Status Next_fit(int request) {
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size=request;
    temp->data.state=Busy;

    if(lastfind!=NULL) {
        while(lastfind) {
            if(lastfind->data.state==Free&&lastfind->data.size==request) {
                lastfind->data.state=Busy;
                lastfind=lastfind->next;
                return OK;
                break;
            }
            if(lastfind->data.state==Free&&lastfind->data.size>request) {
                temp->prior=lastfind->prior;
                temp->next=lastfind;
                temp->data.address=lastfind->data.address;
                lastfind->prior->next=temp;
                lastfind->prior=temp;
                lastfind->data.address=temp->data.address+temp->data.size;
                lastfind->data.size=lastfind->data.size-request;
                return OK;
                break;
            }
            lastfind=lastfind->next;
        }
    } else {
        DuLNode *p = block_first->next;
        while(p) {
            if(p->data.state==Free&&p->data.size==request) {
                p->data.state=Busy;
                lastfind=p->next;
                return OK;
            }
            if(p->data.state==Free&&p->data.size>request) {
                temp->prior=p->prior;
                temp->next=p;
                temp->data.address=p->data.address;
                p->prior->next=temp;
                p->prior=temp;
                p->data.address=temp->data.address+temp->data.size;
                p->data.size=p->data.size-request;
                lastfind=p;
                return OK;
            }
            p=p->next;
        }
    }
}

//�����Ӧ�㷨
Status Best_fit(int request) {
    int ch; //��¼��Сʣ��ռ�
    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size=request;
    temp->data.state=Busy;
    DuLNode *p=block_first->next;
    DuLNode *q=NULL; //��¼��Ѳ���λ��

    while(p) { //��ʼ����С�ռ�����λ��
        if(p->data.state==Free && (p->data.size>=request) ) {
            if(q==NULL) {
                q=p;
                ch=p->data.size-request;
            } else if(q->data.size > p->data.size) {
                q=p;
                ch=p->data.size-request;
            }
        }
        p=p->next;
    }

    if(q==NULL) return ERROR;//û���ҵ����п�
    else if(q->data.size==request) {
        q->data.state=Busy;
        return OK;
    } else {
        temp->prior=q->prior;
        temp->next=q;
        temp->data.address=q->data.address;
        q->prior->next=temp;
        q->prior=temp;
        q->data.address+=request;
        q->data.size=ch;
        return OK;
    }
}

//�����Ӧ�㷨
Status Worst_fit(int request) {
    int ch; //��¼���ʣ��ռ�
    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));
    temp->data.size=request;
    temp->data.state=Busy;
    DuLNode *p=block_first->next;
    DuLNode *q=NULL; //��¼��Ѳ���λ��

    while(p) { //��ʼ�����ռ�����λ��
        if(p->data.state==Free && (p->data.size>=request) ) {
            if(q==NULL) {
                q=p;
                ch=p->data.size-request;
            } else if(q->data.size < p->data.size) {
                q=p;
                ch=p->data.size-request;
            }
        }
        p=p->next;
    }

    if(q==NULL) return ERROR;//û���ҵ����п�
    else if(q->data.size==request) {
        q->data.state=Busy;
        return OK;
    } else {
        temp->prior=q->prior;
        temp->next=q;
        temp->data.address=q->data.address;
        q->prior->next=temp;
        q->prior=temp;
        q->data.address+=request;
        q->data.size=ch;
        return OK;
    }
}

//���������㷨
Status Quick_fit(int request) {
//    printf("��Ҫ�Ŀռ�%d\n",request);
//    return 0;
    DuLinkList temp = block_first->next;
    DuLinkList p=block_first->next;
    DuLinkList temp_node = NULL;
    int min=1024;
    while(p != NULL){
        if(p->data.size>=request && p->data.state == Free && (p->data.size-request)< min){
            temp_node = p;
            min = p->data.size-request;
            continue;
        } else{
            p=p->next;
        }
    }
    if(temp_node!=NULL){
        insert(request,temp_node);
        return OK;
    }

    while(temp!=NULL){
        if(temp->data.size>=request && temp->data.state == Free){

            insert(request,temp);
            return OK;
        }
        temp = temp->next;
    }
    return !OK;
}

Status insert1(int request , DuLinkList area){
    int temp_size = area->data.size;
    //printf("�ܵ��ڴ� �� %d\n",temp_size);
    while(temp_size/2 >= request && temp_size>MIN_QUICK_FIT){
        //printf("�ܵ��ڴ� �� %d\n",temp_size);
        DuLinkList temp_node = (DuLinkList)malloc(sizeof(DuLNode));
        temp_node->data.size = temp_size/2;
        area->data.size/=2;
        temp_node->data.address = area->data.size+area->data.address;
        temp_node->data.state = Free;
//        printf("������ڴ� �� %d\n",area->data.size);
//        printf("�ܵ��ڴ� �� %d\n",temp_size);

        temp_node->next = area->next;
        if(area->next != NULL)
            area->next->prior = temp_node;
        area->next = temp_node;
        temp_node->prior = area;

        temp_size = temp_size / 2;
//        printf("�ܵ��ڴ� �� %d\n",temp_size);
    }
    area->data.state = Busy;
    DuLNode *p = block_first->next;

    while (p->next != NULL ) {
        if (p->data.state == Free && p->next->data.state == Free ) {
            p->data.size += p->next->data.size;
            if(p->next->next != NULL){
                p->next->next->prior = p;
                p->next = p->next->next;
                p = block_first->next;
                continue;
            } else{
                p->next=NULL;
                p=block_first->next;
                //printf("p�Ĵ�С��%d\n",p->data.size);
                continue;
            }


        } else {
            p = p->next;
        }
    }
//    printf("βָ����е��ڴ�: %d\n", block_last->next->data.size);
    return OK;
}
int max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}
//request��ʾ��Ҫ�Ĵ�С��area��ʾ�ҵ��ĵ�һ������������request����
Status insert(int request , DuLinkList area){
    //int temp_size = area->data.size;
    if(area->next != NULL){
        area->data.state=Busy;
    } else{
        //DuLinkList temp_node = (DuLinkList)malloc(sizeof(DuLNode));
        if(area->data.size-request >= MIN_QUICK_FIT){
            DuLinkList temp_node = (DuLinkList)malloc(sizeof(DuLNode));
            temp_node->data.size = area->data.size-max(request,MIN_QUICK_FIT);
            temp_node->data.state = Free;

            area->data.size = max(request,MIN_QUICK_FIT);
            area->data.state = Busy;

            temp_node->data.address = area->data.size + area->data.address;

            temp_node->next = NULL;
            temp_node->prior = area;
            area->next = temp_node;

        } else{
            area->data.state=Busy;
        }
    }
    //printf("�ܵ��ڴ� �� %d\n",temp_size);
//    while(temp_size/2 >= request && temp_size>MIN_QUICK_FIT){
//        //printf("�ܵ��ڴ� �� %d\n",temp_size);
//        DuLinkList temp_node = (DuLinkList)malloc(sizeof(DuLNode));
//        temp_node->data.size = temp_size/2;
//        area->data.size/=2;
//        temp_node->data.address = area->data.size+area->data.address;
//        temp_node->data.state = Free;
//        printf("������ڴ� �� %d\n",area->data.size);
//        printf("�ܵ��ڴ� �� %d\n",temp_size);
//
//        temp_node->next = area->next;
//        if(area->next != NULL)
//            area->next->prior = temp_node;
//        area->next = temp_node;
//        temp_node->prior = area;
//
//        temp_size = temp_size / 2;
//        printf("�ܵ��ڴ� �� %d\n",temp_size);
//    }
//    area->data.state = Busy;
//    DuLNode *p = block_first->next;
//
//    while (p->next != NULL ) {
//        if (p->data.state == Free && p->next->data.state == Free ) {
//            p->data.size += p->next->data.size;
//            if(p->next->next != NULL){
//                p->next->next->prior = p;
//                p->next = p->next->next;
//                p = block_first->next;
//                continue;
//            } else{
//                p->next=NULL;
//                p=block_first->next;
//                //printf("p�Ĵ�С��%d\n",p->data.size);
//                continue;
//            }
//
//
//        } else {
//            p = p->next;
//        }
//    }
//    printf("βָ����е��ڴ�: %d\n", block_last->next->data.size);
    return OK;
}

//�������
Status free1(int flag) {
    DuLNode *p=block_first;
    for(int i= 0; i <= flag; i++)
        if(p!=NULL)
            p=p->next;
        else
            return ERROR;

    p->data.state=Free;
    if(p->prior!=block_first && p->prior->data.state==Free) { //��ǰ��Ŀ��п�����
        p->prior->data.size+=p->data.size;
        p->prior->next=p->next;
        p->next->prior=p->prior;
        p=p->prior;
    }
    if(p->next!=block_last && p->next->data.state==Free) { //�����Ŀ��п�����
        p->data.size+=p->next->data.size;
        p->next->next->prior=p;
        p->next=p->next->next;
    }
    if(p->next==block_last && p->next->data.state==Free) { //�����Ŀ��п�����
        p->data.size+=p->next->data.size;
        p->next=NULL;
    }
    return OK;
}

Status free5(int flag) {
    DuLNode *p = block_first;
    for (int i = 0; i <= flag; i++)
        if (p != NULL)
            p = p->next;
        else
            return ERROR;

    p->data.state = Free;
    //show();
    p = block_first->next;

    while (p->next != NULL ) {
        if (p->data.state == Free && p->next->data.state == Free ) {
            p->data.size += p->next->data.size;
            if(p->next->next != NULL){
                p->next->next->prior = p;
                p->next = p->next->next;
                p = block_first->next;
                continue;
            } else{
                p->next=NULL;
                p=block_first->next;
                //printf("p�Ĵ�С��%d\n",p->data.size);
                continue;
            }
        } else {
            p = p->next;
        }
    }


    return OK;
}

//��ʾ����������
void show() {
    int flag = 0;
    printf("\n����������:\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    DuLNode *p=block_first->next;
    printf("������\t��ʼ��ַ\t������С\t״̬\n\n");
    while(p) {
        printf("  %d\t", flag++);
        printf("  %ld\t\t", p->data.address);
        printf("  %dKB\t\t", p->data.size);
        if(p->data.state==Free) printf("����\n\n");
        else printf("�ѷ���\n\n");
        p=p->next;
    }
    printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
}

//������
int main() {
    int ch;//�㷨ѡ����
    printf("��������ʹ�õ��ڴ�����㷨��\n");
    printf("(1)�״���Ӧ�㷨\n(2)�´���Ӧ�㷨\n(3)�����Ӧ�㷨\n(4)�����Ӧ�㷨\n(5)���������㷨\n");
    scanf("%d", &ch);
    while (ch<1 || ch>5) {
        printf("�������������������ʹ�õ��ڴ�����㷨��\n");
        scanf("%d", &ch);
    }
    Initblock(); //�����ռ��
    int choice;  //����ѡ����
    while(1) {
        show();
        printf("���������Ĳ�����");
        printf("\n1: �����ڴ�\n2: �����ڴ�\n0: �˳�\n");

        scanf("%d", &choice);
        int flag;
        switch (choice) {
            case 1:
                alloc(ch); // �����ڴ�
                break;
            case 2:
                printf("��������Ҫ�ͷŵķ����ţ�");
                scanf("%d", &flag);
                if(ch!=5)
                    free1(flag);
                else
                    free5(flag);
                break;
            case 0:
                return 0;
            default:
                printf("�������������ԣ�\n");
                continue;
        }
    }
}


