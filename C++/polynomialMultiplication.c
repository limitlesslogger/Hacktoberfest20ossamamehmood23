#include <stdio.h>
typedef struct 
{
    int exp;
    float coeff;
}terms;
void inputPoly(terms a[],int n)
{
    printf("Please enter the input in descending order of degrees as indicated\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient ");
        scanf("%f",&a[i].coeff);
        printf("Enter the exponent ");
        scanf("%d",&a[i].exp);
    }
}
void displayPoly(terms a[],int n)
{
    printf("%fx^%d",a[0].coeff,a[0].exp);
    for(int i=1;i<n;i++)
    {
        if(a[i].coeff!=0)
        printf("+%fx^%d",a[i].coeff,a[i].exp);
    }
}
int polyMultiply(terms a[],terms b[],terms r[],int n1,int n2)
{
    int k=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            r[k].coeff=a[i].coeff*b[j].coeff;
            r[k].exp=a[i].exp+b[j].exp;
            k++;
        }
    }
    return k;
}
void groupPoly(terms r[],int k)
{
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k;j++)
        {
            if(r[i].exp==r[j].exp)
            {
                r[i].coeff+=r[j].coeff;
                r[j].coeff=0;
            }
        }
    }
}
void main()
{
    terms a[10],b[10],r[20];
    int n1,n2;
    printf("Enter number of terms in first polynomial\n");
    scanf("%d",&n1);
    printf("Enter number of terms in second polynomial\n");
    scanf("%d",&n2);
    printf("Enter first polynomial\n");
    inputPoly(a,n1);
    printf("Enter second polynomial\n");
    inputPoly(b,n2);
    printf("first polynomial\n");
    displayPoly(a,n1);
    printf("\n");
    printf("second polynomial\n");
    displayPoly(b,n2);
    printf("\n");
    printf("polynomial\n");
    int k=polyMultiply(a,b,r,n1,n2);
    groupPoly(r,k);
    displayPoly(r,k);
}
