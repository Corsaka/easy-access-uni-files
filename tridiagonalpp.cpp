#include <iostream>
//#include <algorithm> //why?
#include <vector>
#include <random>
using namespace std;

vector<double> TridiagonalSolve(double,vector<double>,vector<double>,vector<double>,int);

int main()
{
    return 0;
}

vector<double> TridiagonalSolve(double E,vector<double> D,vector<double> R,vector<double> L,int n)
{
    int i;
    vector<double> c;
    double id;

    for(i=0;i<n;i++)
        c.push_back(E);
    
    c[0] /= D[0];
    R[0] /= D[0];
    
    for(i=1;i<n;i++)
    {
        id = D[i] - c[i-1] * E;
        c[i] /= id;
        R[i] = (R[i] - R[i-1] * E) / id;
    }

    L[n-1] = R[n-1];
    for(i=n-2;i>=0;i--)
        L[i] = R[i] - c[i] * L[i+1];
    
    return L;
}
