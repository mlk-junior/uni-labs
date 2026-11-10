#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LINES_COUNT 1
#define MAX_LINES_COUNT 10
#define MIN_LINE_LENGTH 1
#define MAX_LINE_LENGTH 10
#define ASCII_BOTTOM 9
#define ASCII_TOP 126

int ValueValidation(void);
int IsInvalidByLimit(int value, int bottomLimit, int topLimit, char lastSymbol);

void CleanBuffer(void);
void GenerateString(char *string, int length);
void Sort(char **addresses,int num);

int main(void) {
    char cont,fillingOption,nextSymbol;
    char err = 0;
    srand(time(NULL));

    int linesCount;
    int symbCount;

    do{
        printf("Program for sorting lines of symbols\n");
        do {
            printf("Enter number of lines --> (%d to %d)\n", MIN_LINES_COUNT, MAX_LINES_COUNT);
            linesCount = ValueValidation();
        }while(linesCount == 0);

        do {
            printf("Enter number of symbols in each line --> (%d to %d)\n", MIN_LINE_LENGTH, MAX_LINE_LENGTH);
            symbCount = ValueValidation();
        }while(symbCount == 0);

        char list[linesCount][symbCount+1];
        char *addr[linesCount];

        do {
            err = 0;
            printf("Input 1 to fill lines by random, input 2 to fill manually\n");
            if (!scanf("%c%c",&fillingOption, &nextSymbol) || nextSymbol != '\n' || (fillingOption != '1' && fillingOption != '2')) {
                printf("Inputted input, try again\n");
                err = 1;
                CleanBuffer();
            }
        }while (err !=0);

        switch (fillingOption) {
            case '1':
                for (int i = 0; i < linesCount; i++) {
                    GenerateString(list[i], symbCount);
                }
            break;

            case '2':
                for (int i = 0; i < linesCount; i++) {
                    printf("Input %d line -->\n", i+1);

                    if (!scanf("%[^\n]%c",list[i],&nextSymbol) || nextSymbol != '\n') {
                        printf("Invalid input. Please input a valid string\n");
                        CleanBuffer();
                        i--;
                        continue;
                    }
                    if (strlen(list[i]) != symbCount) {
                        printf("Invalid input. Word must be exactly %d symbols long\n", symbCount);
                        i--;
                        continue;
                    }
                    for (int j = 0; j < symbCount; j++) {
                        if (list[i][j] < ASCII_BOTTOM || list[i][j] > ASCII_TOP) {
                            printf("Invalid symbol --> %c\n", list[i][j]);
                            i--;
                            break;
                        }
                    }
                }
            break;

            default:
            break;
        }

        for (int i = 0; i < linesCount; i++) {
            addr[i] = list[i];
        }

        if (linesCount == MIN_LINES_COUNT) {
            printf("%s\n", addr[0]);
            printf("Only one line in array, nothing to sort\n");
        }
        else {

            for (int i = 0; i < linesCount; i++) {
                printf("%s\n",addr[i]);
            }
            printf("\n");

            Sort(addr,linesCount);
            printf("Sorted lines\n");

            printf("\n");

            for (int i = 0; i < linesCount; i++) {
                printf("%s\n",addr[i]);
            }
        }

        printf("\n");

        printf("Do you want to continue? (Press ENTER to continue or ANY OTHER KEY + ENTER to stop)\n");
        cont = getchar();
        if (cont != '\n') {
            CleanBuffer();
        }
    }while(cont == '\n');
    return 0;
}
int ValueValidation(void) {
    char end;
    int value;

    if (!scanf("%d%c",&value, &end) || end != '\n') {
        printf("Inputted value must be an integer\n");
        printf("\n");
        CleanBuffer();
        return 0;
    }

    if (IsInvalidByLimit(value, MIN_LINE_LENGTH, MAX_LINE_LENGTH, end) == 1) {
        printf("The value is out of bounds\n");
        printf("\n");
        if (end != '\n') CleanBuffer();
        return 0;
    }
    return value;
}
int IsInvalidByLimit(int value, int bottomLimit, int topLimit, char lastSymbol) {
    if (value < bottomLimit) return 1;
    if (value > topLimit) return 1;
    if (lastSymbol != '\n') {
        CleanBuffer();
        return 1;
    }
    return 0;
}
void CleanBuffer(void) {
    while (getchar() != '\n');
}
void GenerateString(char *string, int length) {
    if (string) {
        for (int i = 0; i < length; i++) {
            int key = rand() % (ASCII_TOP - ASCII_BOTTOM + 1);
            string[i] =  ASCII_BOTTOM + (char)key;
        }
        string[length] = '\0';
    }
}
void Sort(char **addresses,int num) {
    int i,j;
    for (i = 0; i < num; i++ ) {
        for (j = i+1; j < num; j++) {
            if (strcmp(addresses[i],addresses[j]) > 0) {
                char* temp;
                temp = addresses[i];
                addresses[i] = addresses[j];
                addresses[j] = temp;
            }
        }
    }
}
