#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
    clock_t tStart = clock();
    ifstream fin ("in.in");
    cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}