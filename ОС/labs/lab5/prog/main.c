#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


struct fileDescription_t{
    char name[9];
    char type[4];
    struct tm creatDate;
    size_t useAmount;
    size_t fileSize;
    struct tm lastModification;
};

void filesDataRandomFill(struct fileDescription_t array[], size_t arrSize){
    for(size_t i = 0; i < arrSize; ++i){

        char temp[] = "File_";
        char buff[5];
        itoa(i+1,buff,10);
        strcat(temp,buff);
        strcat(array[i].name, temp);

        if (i%2 == 0){
            strcpy(array[i].type, "txt");
        } else {
            strcpy(array[i].type, "bin");
        }


        time_t tempTime = time(NULL);
        struct tm *tempTimeStruct  = localtime(&tempTime);
        tempTimeStruct->tm_mday = rand() % 31 ;
        tempTimeStruct->tm_mon = rand() % 11;
        tempTimeStruct->tm_year = 110 + (rand() % (120-110));
        array[i].creatDate = *tempTimeStruct;

        array[i].useAmount = (size_t)rand() % 200;

        array[i].fileSize = (size_t)rand() % 11111;

        array[i].lastModification.tm_hour = tempTimeStruct->tm_hour + i;
        array[i].lastModification.tm_min = tempTimeStruct->tm_min + i;
    }
}

//printf("FILE NAME | EXTENSION | CREATE DATA | USES AMOUNT | SIZE | LAST MODF\n");

void fileDataPrint(struct fileDescription_t temp){
    printf("%9s | %7s   | %2.2d.%2.2d.%4.4d  | %8d    | %4d | %2.2d:%2.2d \n",temp.name, temp.type,
           temp.creatDate.tm_mday,(temp.creatDate.tm_mon + 1),(1900 + temp.creatDate.tm_year), temp.useAmount, temp.fileSize,
           temp.lastModification.tm_hour, temp.lastModification.tm_min);
}

void printArr(struct fileDescription_t *arr, size_t arrSize){
    printf("\nFILE NAME | EXTENSION | CREATE DATA | USES AMOUNT | SIZE | LAST MODF\n");
    printf("-----------------------------------------------------------------------\n");
    for (size_t i = 0; i < arrSize; ++i){
        fileDataPrint(arr[i]);
    }
}
short int compareDate(struct tm date1, struct tm date2){
    if ((date1.tm_year == date2.tm_year) && (date1.tm_mon == date2.tm_mon) && (date1.tm_mday > date2.tm_mday)){
        return 1;
    } else if((date1.tm_year == date2.tm_year) && (date1.tm_mon > date2.tm_mon)) {
        return 1;
    } else if (date1.tm_year > date2.tm_year){
        return 1;
    } else{
        return 0;
    }
}

struct fileDescription_t *sortTheArr(struct fileDescription_t *arr, size_t arrSize){

    struct fileDescription_t temp;

    for (size_t i = 1; i < arrSize; ++i){
        temp = arr[i];
        size_t j;
        for (j = i; ((compareDate(arr[j-1].creatDate,temp.creatDate)) && (j>=1)); --j){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }

    return arr;
}

int main() {

    printf("ENTER NUMBER OF FILES: ");
    size_t filesAmount = 0;
    scanf("%d",&filesAmount);

    struct fileDescription_t *mainArr = (struct fileDescription_t*) calloc(filesAmount,sizeof(struct fileDescription_t));

    filesDataRandomFill(mainArr, filesAmount);
    printArr(mainArr,filesAmount);
    sortTheArr(mainArr,filesAmount);
    printArr(mainArr,filesAmount);
    free(mainArr);

    system("pause");
    return 0;
}