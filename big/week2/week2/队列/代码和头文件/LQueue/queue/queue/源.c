#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include"LQueue.h"

// ������нṹ��
typedef struct {
    Node* front;
    Node* rear;
    size_t size; // ��¼����Ԫ�ظ���
} Queue;

// ��ʼ������
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// ��Ӳ���
void enqueue(Queue* queue, void* data) {
    // �����½ڵ�
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    // �������Ϊ�գ����¶���ͷβָ��
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        // �����½ڵ����ӵ���β
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// ���Ӳ���
void* dequeue(Queue* queue) {
    // �������Ƿ�Ϊ��
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    // ������׽ڵ�
    Node* temp = queue->front;
    // ���¶���ָ��
    queue->front = queue->front->next;
    // �������ֻ��һ���ڵ㣬���¶�βָ��
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    void* data = temp->data;
    // �ͷŶ��׽ڵ��ڴ�
    free(temp);
    queue->size--;
    return data;
}

// ��ȡ���д�С
size_t queueSize(Queue* queue) {
    return queue->size;
}

int main() {
    Queue queue;
    initQueue(&queue);

    // ʾ���������������
    int num1 = 10;
    int num2 = 20;
    enqueue(&queue, &num1);
    enqueue(&queue, &num2);

    // ʾ�������Ӳ���ӡ����
    printf("Dequeued item: %d\n", *(int*)dequeue(&queue));
    printf("Dequeued item: %d\n", *(int*)dequeue(&queue));

    return 0;
}