#include "bits/stdc++.h"

using namespace std;

vector < int > endtime;
vector < int > vi;
void Get(int number)
{
    string name = "test";
    name = name + (char)(number + '0');
    name = name + ".inp";

    vi.clear();

    

    return;
}

void GetTime()
{
    for (int i = 0 ; i <= 9 ; ++i)
        Get(i);
    return;
}

void PrintfTime()
{
    ofstream myfile;
    myfile.open ("Report.txt");
    for (int i = 0 ; i <= 9 ; ++i)
        cout << "Time to run test " << i << " is: " << endtime[i] << '\n';
    myfile.close();
    return;
    
}
int main()
{
    //GetTime();
    //PrintfTime();
    return 0;
}