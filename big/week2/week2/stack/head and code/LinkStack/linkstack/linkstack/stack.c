#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"
#include <stdio.h>
// ³õÊ¼»¯Õ»
Status initLStack(LinkStack* s) {

    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

// ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack* s) {
    if (s->top == NULL)
        return   SUCCESS;
        else return ERROR;
}

// µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack* s, ElemType* e) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

// Çå¿ÕÕ»
Status clearLStack(LinkStack* s) {
    while (s->top != NULL) {
        LinkStackPtr temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;
    return SUCCESS;
}

// Ïú»ÙÕ»
Status destroyLStack(LinkStack* s) {
    clearLStack(s);
    return SUCCESS;
}

// ¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack* s, int* length) {
    *length = s->count;
    return SUCCESS;
}

// ÈëÕ»
Status pushLStack(LinkStack* s, ElemType data) {
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return ERROR; // ÄÚ´æ·ÖÅäÊ§°Ü
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    return SUCCESS;
}

// ³öÕ»
Status popLStack(LinkStack* s, ElemType* data) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR; // Õ»Îª¿Õ
    }
    LinkStackPtr temp = s->top;
    *data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return SUCCESS;
}
