#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "LinkStack.h"
#include <ctype.h>

// �ж��Ƿ�Ϊ�����
int isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

// ��ȡ����������ȼ�
int getPriority(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

// ִ������
int evaluate(int operand1, int operand2, char op) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            printf("Error: Division by zero!\n");
            return 0;
        }
        return operand1 / operand2;
    default:
        return 0; // �����������Ϸ�������0
    }
}

// ��������������ʽ��ֵ
int evaluateExpression(char* expression) {
    LinkStack stack;
    initLStack(&stack);

    int result = 0;
    int operand1, operand2;
    char op;

    while (*expression) {
        if (isdigit(*expression)) {
            int num = 0;
            while (isdigit(*expression)) {
                num = num * 10 + (*expression - '0');
                expression++;
            }
            pushLStack(&stack, num);
        }
        else if (isOperator(*expression)) {
            while (!isEmptyLStack(&stack) && getPriority(*expression) <= getPriority(stack.top->data)) {
                popLStack(&stack, &operand2);
                popLStack(&stack, &operand1);
                op = stack.top->data;
                result = evaluate(operand1, operand2, op);
                pushLStack(&stack, result);
            }
            pushLStack(&stack, *expression);
        }
        else if (*expression == '(') {
            pushLStack(&stack, *expression);
        }
        else if (*expression == ')') {
            while (!isEmptyLStack(&stack) && stack.top->data != '(') {
                popLStack(&stack, &operand2);
                popLStack(&stack, &operand1);
                op = stack.top->data;
                result = evaluate(operand1, operand2, op);
                pushLStack(&stack, result);
            }
            // ���� '('
            popLStack(&stack, &op);
        }
        expression++;
    }

    while (!isEmptyLStack(&stack)) {
        popLStack(&stack, &operand2);
        popLStack(&stack, &operand1);
        op = stack.top->data;
        result = evaluate(operand1, operand2, op);
        pushLStack(&stack, result);
    }

    getTopLStack(&stack, &result);
    destroyLStack(&stack);
    return result;
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, 100, stdin);

    // �Ƴ����з�
    int i = 0;
    while (expression[i] != '\n' && expression[i] != '\0') {
        i++;
    }
    expression[i] = '\0';

    int result = evaluateExpression(expression);
    printf("Result:% d\n", result);
    return 0;
}
