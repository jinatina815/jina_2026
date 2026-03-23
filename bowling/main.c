#include <stdio.h>
#include <string.h>

#define MAX_ROLLS 21

void printBoard(char name[], int rolls[], int rollCount, int scores[]) {
    printf("\nPlayer name: %s\n", name);
    printf("-------------------------------------------\n");
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  |\n");
    printf("-------------------------------------------\n");

    // 투구 표시
    printf("|");
    int rollIndex = 0;

    for (int frame = 0; frame < 10; frame++) {
        if (rolls[rollIndex] == 10) {
            printf("X| ");
            rollIndex++;
        } else {
            // 첫 번째
            if (rollIndex < rollCount) {
                if (rolls[rollIndex] == 10)
                    printf("X");
                else
                    printf("%d", rolls[rollIndex]);
            }

            // 두 번째
            if (rollIndex + 1 < rollCount) {
                if (rolls[rollIndex] + rolls[rollIndex + 1] == 10)
                    printf("|/");
                else
                    printf("|%d", rolls[rollIndex + 1]);
            } else {
                printf("| ");
            }

            printf("|");
            rollIndex += 2;
        }
    }
    printf("\n-------------------------------------------\n");

    // 점수 출력
    printf("|");
    for (int i = 0; i < 10; i++) {
        if (scores[i] != -1)
            printf("%3d|", scores[i]);
        else
            printf("   |");
    }
    printf("\n-------------------------------------------\n");
}

int calculateScores(int rolls[], int rollCount, int scores[]) {
    int score = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; frame++) {
        if (rollIndex >= rollCount) {
            scores[frame] = -1;
            continue;
        }

        // 스트라이크
        if (rolls[rollIndex] == 10) {
            if (rollIndex + 2 < rollCount) {
                score += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                scores[frame] = score;
            } else {
                scores[frame] = -1;
            }
            rollIndex++;
        }
        // 스페어
        else if (rollIndex + 1 < rollCount &&
                 rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
            if (rollIndex + 2 < rollCount) {
                score += 10 + rolls[rollIndex + 2];
                scores[frame] = score;
            } else {
                scores[frame] = -1;
            }
            rollIndex += 2;
        }
        // 일반
        else {
            if (rollIndex + 1 < rollCount) {
                score += rolls[rollIndex] + rolls[rollIndex + 1];
                scores[frame] = score;
            } else {
                scores[frame] = -1;
            }
            rollIndex += 2;
        }
    }

    return score;
}

int main() {
    char name[10];
    int rolls[MAX_ROLLS] = {0};
    int scores[10];
    int rollCount = 0;

    for (int i = 0; i < 10; i++) scores[i] = -1;

    printf("볼링 게임을 시작합니다!\n");
    printf("플레이어 이름을 입력하세요 (최대 9글자): ");
    scanf("%9s", name);

    int frame = 1;

    while (frame <= 10) {
        printBoard(name, rolls, rollCount, scores);

        printf("Player : %s\n", name);
        printf("%d frame 1 cast : ", frame);

        int first;
        scanf("%d", &first);

        if (first < 0 || first > 10) {
            printf("유효한 점수를 입력하세요 (0-10)\n");
            continue;
        }

        rolls[rollCount++] = first;

        if (first == 10 && frame != 10) {
            calculateScores(rolls, rollCount, scores);
            frame++;
            continue;
        }

        printBoard(name, rolls, rollCount, scores);

        printf("Player : %s\n", name);
        printf("%d frame 2 cast : ", frame);

        int second;
        scanf("%d", &second);

        if (second < 0 || second > (10 - first)) {
            printf("유효한 점수를 입력하세요 (0-%d)\n", 10 - first);
            rollCount--; // 되돌림
            continue;
        }

        rolls[rollCount++] = second;

        calculateScores(rolls, rollCount, scores);

        frame++;
    }

    int finalScore = calculateScores(rolls, rollCount, scores);

    printBoard(name, rolls, rollCount, scores);

    printf("\n게임이 종료되었습니다!\n");
    printf("최종 점수: %d\n", finalScore);

    return 0;
}