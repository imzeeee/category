#include <stdio.h>
#include <stdlib.h>


// ������ڵ�ṹ
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// ������ṹ
typedef struct {
    ListNode* head;
} SinglyLinkedList;

// ��ʼ��������
SinglyLinkedList* initializeSinglyLinkedList() {
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (list) {
        list->head = NULL;
    }
    return list;
}

// �������ݵ�������
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

// ��ӡ������
void printSinglyLinkedList(SinglyLinkedList* list) {
    ListNode* current = list->head;
    printf("Singly Linked List: ");
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �ͷŵ������ڴ�
void freeSinglyLinkedList(SinglyLinkedList* list) {
    ListNode* current = list->head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

// ˫������ڵ�ṹ
typedef struct DoubleListNode {
    int data;
    struct DoubleListNode* prev;
    struct DoubleListNode* next;
} DoubleListNode;

// ˫������ṹ
typedef struct {
    DoubleListNode* head;
} DoublyLinkedList;

// ��ʼ��˫������
DoublyLinkedList* initializeDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list) {
        list->head = NULL;
    }
    return list;
}

// �������ݵ�˫������ͷ��
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

// ��ӡ˫������
void printDoublyLinkedList(DoublyLinkedList* list) {
    DoubleListNode* current = list->head;
    printf("Doubly Linked List: ");
    while (current) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �ͷ�˫�������ڴ�
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
