#include <iostream>
//#include <algorithm> //why?
#include <vector>
#include <random>
using namespace std;

int main()
{
    default_random_engine dre; //randomization
    uniform_real_distribution<double> dr(10,20); //random double between 10 and 20
    
    vector<double> vec; //vector using that random double
    vec.push_back(dr(dre)); //adds a new element
    cout << vec[0] << endl;
    return 0;
}