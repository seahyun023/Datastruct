#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int scores[10]; // 10명의 학생 성적 저장
    int sum = 0;
    double average;

    srand(time(0));

    for (int i = 0; i < 10; i++) { //10번 반복
        scores[i] = rand() % 101; // 0 ~ 100 사이의 난수 생성
        sum = sum + scores[i];
        printf("%d번 학생: %d점\n", i + 1, scores[i]);
    }

    average = (double)sum / 10 ;
    printf("학급 평균 점수: %.2f\n", average);

  
    return 0;
}