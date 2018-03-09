#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct list{
    int info;
    struct list *next;
} *beg = NULL, *end = NULL;

static size_t recCounter = 0;


struct list *addNodeToEnd(struct list **beg, struct list **end, int nodeInfo){
    struct list *temp = calloc(1,sizeof(struct list));
    //temp->info = nodeInfo;
    temp->info = recCounter+1;
    temp->next = NULL;

    if (*beg == NULL){

        *beg = temp;
        *end = *beg;

    } else {

        (*end)->next = temp;
        *end = temp;
    }

    ++recCounter;
    return *beg;
}

struct list *deleteNodeFromBeg(struct list **beg){

    if (beg != NULL){
        struct list *temp = *beg;
        *beg = temp->next;
        free(temp);
        --recCounter;
    }
    return *beg;

}

int viewlist(struct list *beg){
    if (beg == NULL){
        return 0 ;
    }

    printf("\n# | Info \n");
    struct list *temp = beg;

    size_t counter = 1;

    while (temp != NULL){
        printf("%d. %d \n", counter, temp->info);

        temp = temp->next;
        ++counter;
    }
    return 1;
}

struct list *swapNodes(struct list **beg, struct list **end, size_t swapedNode){

    if ((*beg == NULL) || (!swapedNode) || (swapedNode >= recCounter)){
        return *beg;
    }

    struct list *temp1 = *beg, *temp2;
    size_t i = 1;

    if (swapedNode == 1){
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp1;
        *beg = temp2;

    } else {
        while(i < (swapedNode - 1)){
            temp1 = temp1->next;
            ++i;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp2->next->next;
        temp1->next->next = temp2;
        if(temp2->next == NULL){
            *end = temp2;
        }
    }

    return *beg;
}

int main() {

    while (1){
        system("cls");
        printf("1-Add node to end\n");
        printf("2-Delete first node\n");
        printf("3-Move k to k+1 node\n");
        printf("4-View list\n");
        printf("0-Exit\n");
        char key;

        key = getch();

        switch(key){

            case '1':{
                int tempInfo = 0;
                //printf("Enter info: ");
                //scanf("%d",&tempInfo);
                if (addNodeToEnd(&beg,&end,tempInfo) != NULL){
                    printf("Node added to end of list\n");
                }else{
                    printf("ERROR\n");
                }

                if (beg != NULL){
                    viewlist(beg);
                }

                break;
            }
            case '2':{
                if (beg != NULL) {
                    deleteNodeFromBeg(&beg);
                    printf("First node deleted\n");
                } else{
                    printf("ERROR\n");
                }

                if (beg != NULL){
                    viewlist(beg);
                } else {
                    printf("EMPTY\n");
                }
                break;
            }

            case '3':{
                if(beg != NULL){
                    size_t nodeNum = 0;
                    printf("Enter k-number of node: ");
                    scanf("%d",&nodeNum);
                    if ((nodeNum < recCounter) && (nodeNum > 0)){
                        swapNodes(&beg, &end, nodeNum);
                        viewlist(beg);
                    } else {
                        printf("ERROR\n");
                    }
                }



                break;
            }
            case '4':{

                if (beg != NULL){
                    viewlist(beg);
                } else {
                    printf("ERROR\n");
                }
                break;
            }
            case '0':{
                return 0;
            }
        }

        getch();

    }

    system("pause");
}