#include "iostream"
#include "stdlib.h"
#include "string.h"

using namespace std;

struct Stu {
    char sno[8];
    char name[20];
    int sex;
    char tel[12];
    char QQ[11];
};

typedef struct LinkNode {
    Stu stu;
    LinkNode *next;
} *LinkList;

LinkList CreateLinkNode() {
    LinkList head = (LinkList) malloc(sizeof(LinkNode));
    if (head) {
        head->next = NULL;
    } else {
        printf("无法分配内存");
    }
    return head;
}

void InsertStu(LinkList head, Stu stu) {
    LinkList temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    LinkList newNode = CreateLinkNode();
    if (newNode) {
        newNode->stu = stu;
        temp->next = newNode;
    }
}
void DeleteStu(LinkList list, char sno[]) {
    while (list->next) {
        LinkList temp = list->next;
        if(strcmp(temp->stu.sno, sno) == 0) {
            list->next = temp->next;
            free(temp);
        }
        list = list->next;
    }
}
void TraverseList(LinkList head) {
    if (head) {
        Stu stu = head->stu;
        printf("%7s %6s %4s %11s %10s\n",
               stu.sno, stu.name,
               stu.sex ? "男" : "女",
               stu.tel, stu.QQ);
        TraverseList(head->next);
    }
}

void SearchList(LinkList list, char sno[]) {
    if (list) {
        Stu stu = list->stu;
        if (strcmp(sno, stu.sno) == 0) {
            printf("%7s %6s %4s %11s %10s\n",
                   stu.sno, stu.name,
                   stu.sex ? "男" : "女",
                   stu.tel, stu.QQ);
        }
        SearchList(list->next, sno);
    }
}

int main() {
    Stu table1[] = {
            {"2013001", "张珊", 0, "13800001919", "34578"},
            {"2013002", "李思", 0, "1391012978",  "8796532"}
    };
    Stu table2[] = {
            {"2013003", "陈琦", 0, "13789450012", "6514124"},
            {"2013004", "王强", 1, "13634567856", "654378"},
            {"2013005", "赵括", 1, "13534408976", "5679"},
            {"2013006", "刘刚", 1, "13386543211", "986354"}
    };
    LinkList head = CreateLinkNode();
    InsertStu(head, table1[0]);
    InsertStu(head, table1[1]);
    for(int i = 0; i < 4; ++i) {
        InsertStu(head, table2[i]);
    }
    printf("插入后-输出所有数据\n");
    TraverseList(head->next);
    printf("删除2013005后\n");
    DeleteStu(head->next, "2013005");
    TraverseList(head->next);
    printf("搜索2013001结果\n");
    SearchList(head->next, "2013001");
    return 0;
}