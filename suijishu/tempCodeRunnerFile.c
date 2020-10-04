#include<stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int smallest = a[0];
    for (int i = 1; i < 10;i++)
    {
        if(a[i]<smallest)
        {
            smallest = a[i];
            for (int j = 0; j < i;j++)
            {
                a[j] = 0;
            }
        }
        else if(a[i]>smallest)
        {
            a[i] = 0;
        }
    }

    int sum = 0;
    for (int k = 0; k < 10;k++)
    {
        sum = +a[k];
    }

    int n = sum / smallest;
    int s = rand();
    s = s % n+1;
    int q = 0;
    for (int k = 0; k < 10;k++)
    {
        if(a[k]==smallest)
        {
            q = q + 1;
        }

        if(q==s)
        {
            printf("%d %d", k, smallest);
            break;
        }

    }
    return 0;
}