#include <stdlib.h>
#include <stdio.h>

typedef struct binTree
{
    int value;
    struct binTree *left;
    struct binTree *right;
} bTree;

int compareTrees(bTree* a, bTree* b);
void insertBT(bTree **tree, int *a, int index, int n);
void printBT(bTree *tree, int level);

int main(void)
{
    char* fileName1 = "R.txt";
    char* fileName2 = "S.txt";
    FILE *fp1 = fopen(fileName1, "r");
    FILE *fp2 = fopen(fileName2, "r");

    if (fp1 == NULL){ printf("File1 can not be opened.\n");}
    if (fp2 == NULL){ printf("File2 can not be opened.\n");}

    int s1=0, s2=0, count=0, count2=0, numRead1, numRead2;
    //First line of the file is the number of elements in the array-> array size.
    fscanf(fp1, "%d", &s1);
    fscanf(fp2, "%d", &s2);
    // declare the array
    int tree1Arr[s1];
    int tree2Arr[s2];

    // read from the second line to get each element of the array
    while (count < s1 && fscanf(fp1, "%d", &numRead1) == 1)
        {tree1Arr[count++] = numRead1;}

    while (count2 < s2 && fscanf(fp2, "%d", &numRead2) == 1)
        {tree2Arr[count2++] = numRead2;}

    fclose(fp1);
    fclose(fp2);

    //int tree1Arr[] = {3,5,7,1,54,61,10,33,20};
    //int tree2Arr[] = {3,5,7,1,54,61,10,30,20};
    bTree *t1;
    bTree *t2;
    //size_t s1 = sizeof(tree1Arr)/sizeof(*tree1Arr);
    //size_t s2 = sizeof(tree2Arr)/sizeof(*tree2Arr);

    printf("************** Tree1 *************\n");
    insertBT(&t1, tree1Arr, 0, s1);
    printBT(t1, 0);
    printf("\n************** Tree2 *************\n");
    insertBT(&t2, tree2Arr, 0, s2);
    printBT(t2, 0);
    printf("\n Comparing two Binary trees\n");
    printf("--------------------------------\n");
    if(compareTrees(t1, t2)){
         printf("Trees are Equal.\n");
    }
    else
    {
        printf("Trees are not Same.\n");
    }
//getchar();
    return 0;
}

int compareTrees(bTree* a, bTree* b)
{
    if (a==NULL && b==NULL)
         return 1;

    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->value == b->value && compareTrees(a->left, b->left) && compareTrees(a->right, b->right)
        );
    }


    return 0;
}

void insertBT(bTree **tree, int *arr, int index, int n)
{

    if (index < n) {
        *tree = malloc(sizeof(**tree));
        (*tree)->value = arr[index];
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        insertBT(&(*tree)->left, arr, 2 * index + 1, n);
        insertBT(&(*tree)->right, arr, 2 * index + 2, n);
    }
}

void printBT(bTree *tree, int level)
{
    if (tree) {
        printBT(tree->left, level + 1);
        printf("%*s->%d\n", 5*level, "", tree->value);
        printBT(tree->right, level + 1);
    }
}

