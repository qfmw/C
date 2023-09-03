#ifndef _LIST_H_
#define _LIST_H_
typedef struct myNode{
    void *data;
    int dataSize;
    struct myNode *next;
} Node;

typedef struct 
{
    Node *head; /* 空的头节点，占位用到 */
    Node *end;
    int count;
    int (*equal)(const void *a, const void *b);
} List;

typedef Node *Position;
typedef int (*Equal)(const  void *a, const void * b);

List *CreateList();
List *CreateListWithEqual(Equal equal);
void FreeList(List *list);
int IsEmpty(List *list);
int IsLast(Position p);
Position Find(const void* data, List *list);
Position FindPrevious(const void* data, List *list);
void PushBack(const void* data, int dataSize, List *list);
void PushFront(const void* data, int dataSize, List *list);
Position Front(List *list);
Position Back(List *list);
void RemoveFront(List *list);
void RemoveBack(List *list);
#endif