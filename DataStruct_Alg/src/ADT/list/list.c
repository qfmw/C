#include "list.h"
#include <string.h>
#include <stdlib.h>
void memset_s(void * dest, int size1, int value, int size2)
{
    if(size2 > size1) {
        return;
    }
    memset(dest, value, size2);
}
List *CreateList()
{
    List *list = (List *)malloc(sizeof(List));
    memset_s(list, sizeof(List), 0, sizeof(List));
    list->head = (Node *)malloc(sizeof(Node));
    memset_s(list->head, sizeof(Node), 0, sizeof(Node));
    return list;
}

List *CreateListWithEqual(Equal equal)
{
    List *list = (List *)malloc(sizeof(List));
    memset_s(list, sizeof(List), 0, sizeof(List));
    list->head = (Node *)malloc(sizeof(Node));
    list->equal = equal;
    memset_s(list->head, sizeof(Node), 0, sizeof(Node));
    return list;
}

void FreeList(List *list)
{
    Node *p = list->head;
    while(p != NULL)
    {
        Node *node = p->next;
        free(p->data);
        free(p);
        p = node;
    }
    free(list);
}

int IsEmpty(List *list)
{
    return list->head->next == NULL;
}

int IsLast(Position p)
{
    return  p->next == NULL;
}

Position Find(const void *data, List *list)
{
     Node *p = list->head->next;
     if(list->equal == NULL) {
        while(p) {
            if(p->data == data) {
                return p;
            }
            p = p->next;
        }
     }
     else{
        while(p) {
            if((*list->equal)(p->data, data)) {
                return p;
            }
            p = p->next;
        }
     }
     return NULL;
}

Position FindPrevious(const void *data, List *list)
{
    Node *p = list->head->next;
    Node *pre = list->head;
    if(list->equal == NULL) {
        while(p) {
            if(p->data == data) {
                return pre;
            }
            p = p->next;
            pre = pre->next;
        }
     }
     else{
        while(p) {
            if((*list->equal)(p->data, data)) {
                return p;
            }
            p = p->next;
            pre = pre->next;
        }
    }
    return NULL;
}

void PushBack(const void *data, int dataSize, List *list)
{
    Node *p = list->count == 0 ? list->head:list->end;
    Node *node = (Node*)malloc(sizeof(Node));
    memset_s(node, sizeof(Node), 0, sizeof(Node));
    node->data = malloc(dataSize);
    memcpy_s(node->data, dataSize, data, dataSize);
    p->next = node;
    list->end = node;
    ++list->count;
}

void PushFront(const void *data, int dataSize, List *list)
{
    Node *p = list->head;
    Node *node = (Node*)malloc(sizeof(Node));
    memset_s(node, sizeof(Node), 0, sizeof(Node));
    node->data = malloc(dataSize);
    memcpy_s(node->data, dataSize, data, dataSize);
    node->next = p->next;
    p->next = node;
    if(list->count == 0)
    {
        list->end = node;
    }
    ++list->count;
}

Position Front(List *list)
{
    return list->head->next;
}

Position Back(List *list)
{
    return list->end;
}

void RemoveFront(List *list)
{
    Node *p = Front(list);
    if(p == NULL)
    {
        return;
    }
    list->head->next = p->next;
    free(p->data);
    free(p);
    --list->count;
}

void RemoveBack(List *list)
{
    Node *p = Back(list);
    if(p == NULL)
    {
        return;
    }
    Node* node = list->head;
    while(node->next != p)
    {
        node = node->next;
    }
    node->next = p->next;
    free(p->data);
    free(p);
    --list->count;
}


