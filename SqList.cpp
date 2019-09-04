#include <bits/stdc++.h>
using namespace std;
/**
 * @author  alva
 * @date    2019-9-4 21:02:36
*/
#define INCREASECOUT 10
#define LISTLENGTH 10
#define OK true
#define ERROR false
#define ElemType int
typedef bool Status;

struct SqList {
    ElemType *elem; //基质
    int length; // 当前存储数据个数
    int capacity; //list容量
};

Status InitList(SqList &L); // 初始化list
Status DestoryList(SqList &L); //清空内存
Status ClearList(SqList &L);
Status DelElement(SqList &L, int pos, ElemType &val);
Status InsertElement(SqList &L, int pos, ElemType val);
Status TravelList(SqList &L);
int main() {
    SqList L;
    InitList(L);
    InsertElement(L, 1, 5);
    InsertElement(L, 2, 6);
    InsertElement(L, 1, 7);
    InsertElement(L, 1, 8);
    InsertElement(L, 1, 9);
    TravelList(L);
    return 0;
}
Status TravelList(SqList &L) {
    /**
     * @功能：输出所有元素
     */
    for(int i = 0; i < L.length; ++i)
        printf("%d\n", L.elem[i]);
    return OK;
}
Status InsertElement(SqList &L, int pos, ElemType val) {
    /**
     * @功能：插入元素val到第pos个元素之前
     * @合法范围：1 <= pos <= length+1
     * @前置条件：剩余容量足够，否则扩大容量（realloc）
     * L.length < L.capacity
     * 1. 将位于pos ~ L.length 往后移一位
     * 2. 赋值L.elem[pos-1] = val
     * 3. ++L.length
     * 4. 若分配内存，更新容量L.capacity 
     * 
    */
   if(L.length >= L.capacity) { 
       // 扩容，申请失败得到null值，所以不能直接赋值给L.elem
       ElemType *newBaseAddr = (ElemType*)realloc(L.elem, \
                               (L.capacity+INCREASECOUT)*sizeof(ElemType));
       if(NULL == newBaseAddr) return ERROR;
       L.elem = newBaseAddr;
       L.capacity += INCREASECOUT;
   }
    for(ElemType *point = L.elem+L.length; point>L.elem+pos-1; --point)/*偏移到最后一个元素之后*/
      point[0] = point[-1]; // 当前位置等于前一个的值
    L.elem[pos-1] = val; // 下标pos-1为第pos个
    ++(L.length);
    return OK;
}

Status InitList(SqList &L) {
    /**
     * @功能：初始化顺序表
     * 1. 给元素分配内存
     * 2. 设置容量
     * 3. 元素个数初始化为0
     */
    L.length = 0;
    L.elem = (ElemType *)malloc(LISTLENGTH * sizeof(ElemType));
    L.capacity = LISTLENGTH;
    return OK;
}
Status DelElement(SqList &L, int pos, ElemType &val) {
    /**
     * @功能：删除第pos个元素，用val返回
     * @pos范围：1 <= pos <= L.length
     * 1. 删除
     * 2. --L.length
     */
    if(NULL != L.elem) {
        if(pos<1 || pos>L.length) {
            return ERROR;
        }
        val = L.elem[pos-1];
        int i;
        for(i = pos - 1; i < L.length; i++) {
            L.elem[i] = L.elem[i+1];
        }
        --(L.length);
        return OK;
    }
    return ERROR;
}