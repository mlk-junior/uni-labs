#include <stdio.h>
void cleanBuffer(void) {
    while (getchar() != '\n');
}

int main(void) {
    char cont,end;
    char err = 0;

    char linesBottomBorder = 1;
    char linesTopBorder = 10;
    int linesValue;

    char lettersBottomValue = 1;
    char lettersTopValue = 10;
    int lettersValue;

    do
    {
        do
        {
            printf("Input desired value of lines (1 to 10)-->\n");
            do
            {
                if (!scanf("%d",&linesValue) || linesValue < linesBottomBorder || linesValue > linesTopBorder)
                {
                    err = 1;
                    printf("Incorrect input. Please try again\n");
                }
                else err = 0;
                cleanBuffer();
            }while (err != 0);

            printf("Input desired value of letters in each line (1 to 10)-->\n");
            do
            {
                if (!scanf("%d",&lettersValue) || lettersValue < lettersBottomValue || lettersValue > lettersTopValue)
                {
                    err = 1;
                    printf("Incorrect input. Please try again\n");
                }
                else err = 0;
                cleanBuffer();
            }while (err != 0);

            char matrix[linesValue][lettersValue];







            printf("Do you want to continue? (Press ENTER to continue or press 'e' to exit)\n");
            cont = getchar();
            if (cont != '\n') {
                cleanBuffer();
            }
        }while (cont != '\n' || cont != 'e');
    }while(cont != 'e');
    return 0;
}
