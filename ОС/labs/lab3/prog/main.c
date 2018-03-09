#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

const unsigned char FILE_NAME_MAX_SIZE = 256;

void Interface();
void CheckOpen(FILE * fileName);
char *SearchLongestWord(FILE * fileName);


int main() {
    Interface();


    system("pause");
    return 0;
}

void Interface(){
    char outFileName[FILE_NAME_MAX_SIZE];
    char inFileName[FILE_NAME_MAX_SIZE];

    //READ FILE
    printf("ENTER READ FILE NAME: ");
    gets(outFileName);

    FILE *outFile = fopen(outFileName, "r");
    CheckOpen(outFile);
    putchar('\n');
    //WRITE TO FILE
    printf("ENTER WRITE FILE NAME: ");
    gets(inFileName);

    FILE *inFile = fopen(inFileName, "w");
    CheckOpen(inFile);

    char *longestWord = SearchLongestWord(outFile);

    fputs(longestWord,inFile);


    printf("%d - %s \n",strlen(longestWord), longestWord);

    free(longestWord);
    fclose(outFile);
    fclose(inFile);

}

void CheckOpen(FILE * file){
    if (!file){
        printf("OPEN FILE ERROR\n");
        system("pause");
        exit(1);
    } else {
        printf("FILE WAS OPENED\n");
    }
}

char *SearchLongestWord(FILE * file){
    rewind(file);

    char tempChar = 0;
    size_t charCounter = 0;
    size_t maxLength = 0;
    size_t begWordPosition = 0;
    size_t longestWordPos = 0;


    while ( fscanf(file, "%c", &tempChar)!= EOF){

        if (!ispunct(tempChar) && !isspace(tempChar)) {
            if (!charCounter){
                begWordPosition = ftell(file);
            }
            charCounter++;
        } else {
            if (charCounter > maxLength) {
                maxLength = charCounter;
                longestWordPos = begWordPosition - 1;
            }
            charCounter = 0;
        }
    }

    char *word = (char*) calloc (maxLength + 1,sizeof(char));

    fseek(file, longestWordPos, SEEK_SET);
    fgets(word, maxLength+1, file);
    

    return word;
}
