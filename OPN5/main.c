#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LINES_COUNT 1
#define MAX_LINES_COUNT 10
#define MIN_WORD_LENGTH 1
#define MAX_WORD_LENGTH 10


#define ASCII_BOTTOM 65
#define ASCII_TOP 126

int IsInvalidByLimit(int value, int bottomLimit, int topLimit, char lastSymbol);
void CleanBuffer(void);
void GenerateString(char *string, int length);
void Sort(char **addresses,int num);

int main(void) {
    char cont,end;
    srand(time(NULL));
    char err = 0;

    int linesCount;
    int symbCount = 4;

    do{
        do{
            printf("Program for sorting lines of symbols\n");
            do {
                    err = 0;
                printf("Enter number of lines --> (%d to %d)\n", MIN_LINES_COUNT, MAX_LINES_COUNT);
                if (!scanf("%d%c",&linesCount, &end) || end != '\n') {
                    err = 1;
                    printf("Inputted value must be an integer\n");
                    printf("\n");
                    CleanBuffer();
                    continue;
                }

                if (IsInvalidByLimit(linesCount, MIN_WORD_LENGTH, MAX_WORD_LENGTH, end) == 1) {
                    err = 1;
                    printf("The value is out of bounds\n");
                    printf("\n");
                    if (end != '\n') CleanBuffer();
                }

            }while(err != 0);

            char list[linesCount][symbCount+1];
            char *addr[linesCount];

            for (int i = 0; i < linesCount; i++) {
                GenerateString(list[i], symbCount);
                addr[i] = list[i];
            }
            
            for (int i = 0; i < linesCount; i++) {
                for (int j = 0; j < symbCount; j++) {
                    printf("%c",list[i][j]);
                }
                printf("\n");
            }
            Sort(addr,linesCount);
            printf("\n");
            for (int i = 0; i < linesCount; i++) {
                printf("%s",addr[i]);
                printf("\n");
            }



            printf("Do you want to continue? (Press ENTER to continue or press 'e' to exit)\n");
            cont = getchar();
            if (cont != '\n') {
                CleanBuffer();
            }
        }while (cont != '\n' && cont != 'e');
    }while(cont != 'e');
    return 0;
}
int IsInvalidByLimit(int value, int bottomLimit, int topLimit, char lastSymbol) {
    if (value < bottomLimit) return 1;
    if (value > topLimit) return 1;
    if (lastSymbol != '\n') {
        CleanBuffer();
        return 1;
    }
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

// int ValidateValue(int valuesCount, int valueBottomBorder, int valueTopBorder) {
//     char err = 0;
//     do{
//         if (!scanf("%d",&valuesCount) || valuesCount < valueBottomBorder || valuesCount > valueTopBorder){
//             err = 1;
//             printf("Incorrect input. Please try again\n");
//         }
//         else err = 0;
//         CleanBuffer();
//     }while (err != 0);
//     return value;
// }
