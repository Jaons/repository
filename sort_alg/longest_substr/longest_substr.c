#include <stdio.h>
#include <malloc.h>
#include <string.h>
   
typedef enum Direction
{ same, left, up } Direction;
   
typedef struct Node
{
    int value;
    Direction d;
} Node;

   
void getLCS (char *a, char *b)
{
    if (a==NULL || b==NULL)
    {
        printf ("param error\n");
        return;
    }
    int i, j;
    Node **narray = (Node*)malloc(sizeof(Node*)*(strlen(a)+1)*(strlen(b)+1));
    for (i=0; i<=strlen(a); ++i)
        for (j=0; j<=strlen(b); ++j)
        {
            Node *n = (Node *)malloc(sizeof(Node));
            if (i==0 || j==0)
                n->value = 0;
            else if (a[i-1] == b[j-1])
            {
                n->value = narray[(i-1)*(strlen(b)+1)+j-1]->value + 1;
                n->d = same;
            }
            else if (narray[(i-1)*(strlen(b)+1)+j]->value >= narray[i*(strlen(b)+1)+j-1]->value)
            {
                n->d = up;
                n->value = narray[(i-1)*(strlen(b)+1)+j]->value;
            }
            else
            {
                n->d = left;
                n->value = narray[i*(strlen(b)+1)+j-1]->value;
            }
            narray[i*(strlen(b)+1)+j] = n;
        }
    i = strlen(a);
    j = strlen(b);
    printf ("The length of LCS is: %d\n", narray[i*(strlen(b)+1)+j]->value);
    char *res = (char *)malloc(sizeof(char)*narray[i*(strlen(b)+1)+j]->value);
    int k = narray[i*(strlen(b)+1)+j] -> value-1;
    while (1)
    {
        switch (narray[i*(strlen(b)+1)+j]->d)
        {
        case same:
            --i;
            --j;
            res[k] = a[i];
            --k;
            break;
        case up:
            --i;
            break;
        case left:
            --j;
            break;
        }
        if (i<=0 || j<=0)
            break;
    }
    printf ("%s\n", res);
    for (i=strlen(a); i>=0; --i)
        for (j=strlen(b); j>=0; --j)
            free(narray[i*(strlen(b)+1)+j]);
    free(narray);
    free(res);
}
   
int main ()
{
    char a[20], b[20];
    printf ("Please input the string A:\n");
    scanf ("%s", a);
    printf ("Please input the string B:\n");
    scanf ("%s", b);
    getLCS (a, b);
    return 0;
}
