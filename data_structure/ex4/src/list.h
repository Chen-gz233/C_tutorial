#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {      //节点
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {       //链表
    int count;
    ListNode *first;
    ListNode *last;
} List;



List *List_create();
void List_destroy(List *list);
void List_clear(List *list);
void List_clear_destroy(List *list);


//返回链表的结点数
#define List_count(A) ((A)->count)
//返回头指针的值
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
//返回尾指针的值
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void List_push(List *list, void *value);
void *List_pop(List *list);

void List_unshift(List *list, void *value);
void *List_shift(List *list);

void *List_remove(List *list, ListNode *node);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif