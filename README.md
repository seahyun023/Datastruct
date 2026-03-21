#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �Լ� ����
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printfScore(int scores[], int size, double average, int option);

int main(){
    int scores[30]; // 30���� �л� ���� ����
    int studentNumber;
    double average;

    // ���� ���� �ʱ�ȭ
    srand(time(0));

    // ���� ������ �ʱ�ȭ
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 ������ ���� ����
    }

    // ��� ���
    average = calculateAverage(scores, 30);
    printf("�б� ��� ����: %.2f\n", average);

    // Ư�� �л� ���� �˻�
    printf("�л� ��ȣ�� �Է��ϼ��� (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d�� �л��� ����: %d\n", studentNumber, score);
    }
    else {
        printf("��ȿ���� ���� �л� ��ȣ�Դϴ�.\n");
    }
    
    printfScore(scores, 30, average, 0);
    printfScore(scores, 30, average, 1);
    printfScore(scores, 30, average, 2);
    return 0;
}

// ��� ��� �Լ�
double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

// Ư�� �л� ���� �˻� �Լ�
int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1; // ��ȿ���� ���� �л� ��ȣ
    }
}

void printfScore(int scores[], int size, double average, int option) {
    switch (option) {
    case 0:
        for (int i = 0; i < size; i++) {
            printf("�л���ȣ : %d , ���� %d\n", i + 1, scores[i]);
        }
        break;
    case 1:
        for (int i = 0; i < size; i++) {
            printf("����̻� �л�\n");
            if(scores[i] >= average)
            printf("�л���ȣ : %d , ���� %d\n", i + 1, scores[i]);
        }
        break;
    case 2:
        printf("��չ̸� �л�\n");
        for (int i = 0; i < size; i++) {
            if (scores[i] < average)
                printf("�л���ȣ : %d, ���� %d\n", i + 1, scores[i]);
        }
        break;
    default: //error
        printf("��ȿ���� ���� �ɼ��Դϴ�.\n");
        break;
    }
}
