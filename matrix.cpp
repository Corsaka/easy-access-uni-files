#include <iostream>
//#include <algorithm> //why?
#include <vector>
#include <random>
using namespace std;

int main()
{
    default_random_engine dre; //randomization
    uniform_real_distribution<double> dr(10,20); //random double between 10 and 20

    int cols,rows;
    cout << "Enter number of columns in the matrix: ";
    cin >> cols;
    cout << "Enter number of rows in the matrix: ";
    cin >> rows;

    vector<vector<double>> matrix(rows);
    for(int i=0;i<rows;i++)
    {
        vector<double> matrixrow(cols);
        for(int j=0;j<cols;j++)
        {
            matrixrow[j] = (dr(dre));
        }
        matrix[i] = matrixrow;
    }

    //print function
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}