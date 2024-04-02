#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"
#include <stdio.h>
// ��ʼ��ջ
Status initLStack(LinkStack* s) {

    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

// �ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
    if (s->top == NULL)
        return   SUCCESS;
        else return ERROR;
}

// �õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

// ���ջ
Status clearLStack(LinkStack* s) {
    while (s->top != NULL) {
        LinkStackPtr temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;
    return SUCCESS;
}

// ����ջ
Status destroyLStack(LinkStack* s) {
    clearLStack(s);
    return SUCCESS;
}

// ���ջ����
Status LStackLength(LinkStack* s, int* length) {
    *length = s->count;
    return SUCCESS;
}

// ��ջ
Status pushLStack(LinkStack* s, ElemType data) {
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return ERROR; // �ڴ����ʧ��
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    return SUCCESS;
}

// ��ջ
Status popLStack(LinkStack* s, ElemType* data) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR; // ջΪ��
    }
    LinkStackPtr temp = s->top;
    *data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return SUCCESS;
}
