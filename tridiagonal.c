#include <stdlib.h>

void TridiagonalSolve(double defaultVal, double *D, double *R, double *L, int n){
    int i;
    double *c = (double *) calloc(n, sizeof(double));
    double id;

    /* Set the off diagonal elements */
    for (i=0;i<n;i++)
    {
        c[i] = defaultVal;
    }
    
    /*forward bit */
    c[0] /= D[0]; /*if /0 rearrange equations */
    R[0] /= D[0]; //a/=b -> a=a/b

    for (i=1;i<n;i++)
    {
        id = D[i] - c[i-1] * defaultVal;
        c[i] /= id; /* Last value calculated is redundant. */
        R[i] = (R[i] - R[i-1] * defaultVal) / id;
    }

    /* Now back substitute. */
    L[n-1] = R[n-1];
    for (i=n-2;i>=0;i--)
    {
        L[i] = R[i] - c[i] * L[i + 1];
    }
}

#include <stdio.h>
int main(){
    double a[4] = {1.0,3.0,5.0,6.0};
    double b[4] = {3.0,5.0,2.0,6.0};
    double c[4] = {9.0,7.0,3.0,1.0};
    TridiagonalSolve(3.0,a,b,c,5);
    printf("%d,%d,%d,%d\n",a[1],a[2],a[3],a[4]);
    printf("%d,%d,%d,%d\n",b[1],b[2],b[3],b[4]);
    printf("%d,%d,%d,%d\n",c[1],c[2],c[3],c[4]);
}
