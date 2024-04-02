#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include"LQueue.h"

// 定义队列结构体
typedef struct {
    Node* front;
    Node* rear;
    size_t size; // 记录队列元素个数
} Queue;

// 初始化队列
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// 入队操作
void enqueue(Queue* queue, void* data) {
    // 创建新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    // 如果队列为空，更新队列头尾指针
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        // 否则将新节点链接到队尾
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// 出队操作
void* dequeue(Queue* queue) {
    // 检查队列是否为空
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    // 保存队首节点
    Node* temp = queue->front;
    // 更新队首指针
    queue->front = queue->front->next;
    // 如果队列只有一个节点，更新队尾指针
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    void* data = temp->data;
    // 释放队首节点内存
    free(temp);
    queue->size--;
    return data;
}

// 获取队列大小
size_t queueSize(Queue* queue) {
    return queue->size;
}

int main() {
    Queue queue;
    initQueue(&queue);

    // 示例：入队整型数据
    int num1 = 10;
    int num2 = 20;
    enqueue(&queue, &num1);
    enqueue(&queue, &num2);

    // 示例：出队并打印数据
    printf("Dequeued item: %d\n", *(int*)dequeue(&queue));
    printf("Dequeued item: %d\n", *(int*)dequeue(&queue));

    return 0;
}