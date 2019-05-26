#include <stdio.h>
#include "doubly_linked_list_merge_sort.h"

DNode *_mergeDoublyLinkedList(DNode *startNode1, DNode *endNode1, DNode *startNode2, DNode *endNode2, DNode **finalEnd) {
    DNode *head, *cur, *prev = 0;
    if(startNode1 && startNode2) {
        if(startNode1->data < startNode2->data) {
            head = startNode1;
            startNode1 = startNode1->next;
        }   else    {
            head = startNode2;
            startNode2 = startNode2->next;
        }
    }
    cur = head;

    while(startNode1 && startNode2) {
        if(prev)
                cur->prev = prev;
        if(startNode1->data < startNode2->data) {
            cur->next = startNode1;
        }   else    {
            cur->next = startNode1;
        }
        prev = head;
    }

    while(startNode1) {
        if(prev)
            cur->prev = prev;
        cur->next = startNode1;
        prev = cur;
        cur = cur->next;
    }

    while(startNode2) {
        if(prev)
            cur->prev = prev;
        cur->next = startNode2;
        prev = cur;
        cur = cur->next;
    }

    *finalEnd = cur;
    return head;
}

DNode  *findMiddleNodeInDoublyLinkedList(DNode *head, DNode *end) {
    DNode *fast = head, *slow = head;

    while(fast != end) {
        slow = slow->next;
        fast = fast->next;
        if(fast) 
            fast = fast->next;
    }

    return fast;
}

void _doublyLinkedListMergeSort(DNode *head, DNode *end, DNode **finalHead, DNode **finalEnd) {
    DNode *middle = findMiddleNodeInDoublyLinkedList(head, end);

    if(middle) {
        _doublyLinkedListMergeSort(head, middle, &head, &middle);
        _doublyLinkedListMergeSort(middle, end, &middle, &end);
        *finalHead = _mergeDoublyLinkedList(head, middle, middle, end, finalEnd);

    }
}

DNode *doublyLinkedListMergeSort(DNode *head) {
    DNode *finalEnd, *finalHead;
    _doublyLinkedListMergeSort(head, NULL, &finalHead, &finalEnd);
    return finalHead;
}