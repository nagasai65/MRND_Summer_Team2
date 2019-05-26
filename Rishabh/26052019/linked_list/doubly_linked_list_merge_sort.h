#ifndef doubly_linked_list_merge_sort
#define doubly_linked_list_merge_sort

typedef struct _DNode {
    int data;
    struct _DNode *next, *prev;
} DNode;

DNode *doublyLinkedListMergeSort(DNode *);

#endif