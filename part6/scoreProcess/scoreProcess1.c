#include <stdio.h>

void scoreProcess(char *line) 
{
printf("Processing: %s", line);
}

int main(void) 
{
FILE *fp = fopen("input.txt", "r");
char buffer[256];

if (fp == NULL) {
printf("파일 열기 실패\n");
return 1;
}

while (fgets(buffer, sizeof(buffer), fp) != NULL) {
scoreProcess(buffer);
}

fclose(fp);
return 0;
}