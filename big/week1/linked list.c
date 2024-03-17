#include <stdio.h>
#include <stdlib.h>


// 单链表节点结构
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// 单链表结构
typedef struct {
    ListNode* head;
} SinglyLinkedList;

// 初始化单链表
SinglyLinkedList* initializeSinglyLinkedList() {
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (list) {
        list->head = NULL;
    }
    return list;
}

// 插入数据到单链表
void insertSinglyLinkedList(SinglyLinkedList* list, int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode) {
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;
    } else {
        printf("Memory allocation failed!\n");
    }
}

// 打印单链表
void printSinglyLinkedList(SinglyLinkedList* list) {
    ListNode* current = list->head;
    printf("Singly Linked List: ");
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放单链表内存
void freeSinglyLinkedList(SinglyLinkedList* list) {
    ListNode* current = list->head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

// 双向链表节点结构
typedef struct DoubleListNode {
    int data;
    struct DoubleListNode* prev;
    struct DoubleListNode* next;
} DoubleListNode;

// 双向链表结构
typedef struct {
    DoubleListNode* head;
} DoublyLinkedList;

// 初始化双向链表
DoublyLinkedList* initializeDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list) {
        list->head = NULL;
    }
    return list;
}

// 插入数据到双向链表头部
void insertDoublyLinkedList(DoublyLinkedList* list, int data) {
    DoubleListNode* newNode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
    if (newNode) {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = list->head;
        if (list->head) {
            list->head->prev = newNode;
        }
        list->head = newNode;
    } else {
        printf("Memory allocation failed!\n");
    }
}

// 打印双向链表
void printDoublyLinkedList(DoublyLinkedList* list) {
    DoubleListNode* current = list->head;
    printf("Doubly Linked List: ");
    while (current) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放双向链表内存
void freeDoublyLinkedList(DoublyLinkedList* list) {
    DoubleListNode* current = list->head;
    while (current) {
        DoubleListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    SinglyLinkedList* sList = initializeSinglyLinkedList();
    insertSinglyLinkedList(sList, 1);
    insertSinglyLinkedList(sList, 2);
    insertSinglyLinkedList(sList, 3);
    printSinglyLinkedList(sList);
    freeSinglyLinkedList(sList);

    DoublyLinkedList* dList = initializeDoublyLinkedList();
    insertDoublyLinkedList(dList, 1);
    insertDoublyLinkedList(dList, 2);
    insertDoublyLinkedList(dList, 3);
    printDoublyLinkedList(dList);
    freeDoublyLinkedList(dList);

    return 0;
}
