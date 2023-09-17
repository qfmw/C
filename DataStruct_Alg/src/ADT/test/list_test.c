#include  "stdio.h"
#include "string.h"
#include "..\list\list.h"

int EqualInt(const void *a, const void * b)
{
    return *(int *)a - *(int *)b;
}

void testInt()
{
    List *list = CreateListWithEqual(EqualInt);
    int temp = 1;
    PushBack(&temp, sizeof(temp), list);
    printf(" list size = %d\n", list->count);
    temp = 2;
    PushFront(&temp, sizeof(temp), list);
    temp = 3;
    PushBack(&temp, sizeof(temp), list);
    temp = 4;
    PushBack(&temp, sizeof(temp), list);
    temp = 5;
    PushBack(&temp, sizeof(temp), list);
    temp = 6;
    PushFront(&temp, sizeof(temp), list);
    printf(" list size = %d\n", list->count);
    Node * node = Front(list);
    printf(" list value: \t");
    while(node != NULL)
    {
        printf("%d --> ", *(int *)node->data);
        node = node->next;
    }
    FreeList(list);
}

int EqualStr(const void *a, const void * b)
{
    return strcmp((char *)a, (char *)b);
}

void testStr()
{
    List *list = CreateListWithEqual(EqualInt);
    const char * strTemp = "str1";
    PushBack(strTemp, strlen(strTemp) + 1, list);
    printf(" list size = %d\n", list->count);
    strTemp = "1 2str2";
    PushFront(strTemp, strlen(strTemp) + 1, list);
    strTemp = "str3";
    PushBack(strTemp, strlen(strTemp) + 1, list);
    strTemp = "str4";
    PushBack(strTemp, strlen(strTemp) + 1, list);
    strTemp = "str5";
    PushBack(strTemp, strlen(strTemp) + 1,list);
    strTemp = "str6";
    PushFront(strTemp, strlen(strTemp) + 1,list);
    printf(" list size = %d\n", list->count);
    Node * node = Front(list);
    printf(" list value: \t");
    while(node != NULL)
    {
        printf("%s --> ", (char *)node->data);
        node = node->next;
    }
    FreeList(list);
}

int main(int argc, char **argv)
{
    testStr();
}