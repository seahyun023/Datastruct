#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>  // isdigit(), isalpha() 사용
#include <string.h>
#include <stdlib.h>
#define MAX 100


typedef struct {
	int data[MAX];
	int top;
}Stack;

void initStack(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

void push(Stack* s, int value) {
	s->data[++(s->top)] = value;
}

int pop(Stack* s) {
	if (isEmpty(s)) return '\0';
	return s->data[(s->top)--];
}

int peek(Stack* s) {
	if (isEmpty(s)) return '\0';
	return s->data[(s->top)];
}

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}

int infixToPostfix(char* infix, char* postfix) {
	Stack s;
	initStack(&s); //스택 주소값 
    int j = 0;
	
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // 1. 피연산자 (알파벳 또는 숫자)
        if (isalpha(ch) || isdigit(ch)) {
            postfix[j++] = ch;
        }
        // 2. 여는 괄호 '('
        else if (ch == '(') {
            push(&s, ch);
        }
        // 3. 닫는 괄호 ')'
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);  // 여는 괄호 '(' 전까지 pop
            }
            pop(&s);  // 여는 괄호 '(' 제거
        }
        // 4. 연산자
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);  // 우선순위가 높은 연산자들을 pop
            }
            push(&s, ch);  // 현재 연산자 push
        }
    }

    // 스택에 남은 연산자를 후위표기식에 추가
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    return evaluatePostfix(postfix);
    printf("후위표기식: %s\n", postfix);
}

int evaluatePostfix(char* postfix) {
    Stack s;
    initStack(&s);  // 계산용 스택 초기화

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // 1. 피연산자 (숫자)
        if (isdigit(ch)) {
            // 문자열로 된 숫자를 정수로 변환하여 push
            push(&s, ch - '0');
        }
        // 2. 연산자
        else {
            int b = pop(&s);  // 두 번째 피연산자 (스택의 최상단)
            int a = pop(&s);  // 첫 번째 피연산자
            int result;

            // 연산 수행
            switch (ch) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default:
                printf("Invalid operator encountered.\n");
                exit(1);
            }

            // 연산 결과를 스택에 push
            push(&s, result);
        }
    }

    // 스택에 남은 최종 결과를 반환
    return pop(&s);
}
int main(void) {
    char infix[MAX];
    char postfix[MAX];
    int result;
    printf(":중위표기식 입력 : ");
    scanf("%s", infix);
    result = infixToPostfix(infix, postfix);
    printf("후위표기식 : %s\n", postfix);
    printf("후위표기식 계산 결과 : %d\n", result);
    return 0;
}
