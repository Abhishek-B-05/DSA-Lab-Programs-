#include <stdio.h>

typedef struct{
    int row,col,val;
} sparse;

void main()
{
    int m,n,nz,k=1;
    printf("Enter the dimensions of the sparse matrix: \n");
    scanf("%d%d",&m,&n);
    printf("Enter the number of non-zero elements: \n");
    scanf("%d",&nz);
    sparse s[nz+1];
    sparse transpose[nz+1];
    s[0].row=m;
    s[0].col=n;
    s[0].val=nz;
    for(int i=1; i<=nz; i++)
    {
        printf("Enter the elements of %d: ",i);
        scanf("%d%d%d",&s[i].row,&s[i].col,&s[i].val);
    }
    transpose[0].row = n;
    transpose[0].col = m;
    transpose[0].val = nz;
    for (int i = 1;i<=nz; i++)
    {
        transpose[i].row = s[i].col;
        transpose[i].col = s[i].row;
        transpose[i].val = s[i].val;
    }
    for (int i = 1; i < nz; i++)
    {
        for (int j = i + 1; j <= nz; j++)
        {
            if (transpose[i].row > transpose[j].row ||
                (transpose[i].row == transpose[j].row && transpose[i].col > transpose[j].col))
            {
                sparse temp = transpose[i];
                transpose[i] = transpose[j];
                transpose[j] = temp;
            }
        }
    }
    printf("Transpose :\n");
    for(int i = 0; i<=nz; i++)
        printf("%d  %d  %d\n",transpose[i].row,transpose[i].col,transpose[i].val);
}
