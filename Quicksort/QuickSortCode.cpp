#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector < int > endtime;
vector < int > vi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

int SNC(string x)
{
    bool ok = 0;
    if (x[0] == '-') ok = 1;
    else x = ' ' + x;
    int num = 0;
    for (int i = 1 ; i < (int)x.size() ; ++i)
        num = num * 10 + (int)(x[i] - '0');
    if (ok) num = -num;
    return num;
}

int partition(int low, int high) {

    int rnd = rand(low, high);
    swap(vi[rnd], vi[high]);

    int pivot = vi[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (vi[j] < pivot) {
            i++;
            swap(vi[i], vi[j]);
        }
    }
    swap(vi[i + 1], vi[high]);
    return i + 1;
}

void quickSort(int low, int high) {

    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}


void Get(int number)
{
    cerr << number << '\n';
    string name = "test";
    name = name + (char)(number + '0');
    name = name + ".inp";

    vi.clear();
    vi.push_back(0);
    ifstream nowfile(name);

    string num;
    while (getline(nowfile, num))
    {
        vi.push_back(SNC(num));
    }
    vi.push_back(0);
    nowfile.close();
    auto start = high_resolution_clock::now(); /// get starting timepoint
    ///----sorting here-----
    quickSort(1, (int)vi.size() - 2);
    //----------------------
    auto stop = high_resolution_clock::now(); /// end timepoint

    auto duration = duration_cast<milliseconds>(stop - start);
    int end = duration.count();

    endtime.push_back(end);
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
        myfile << "Time to run test " << i << " is: " << endtime[i] << '\n';

    int average = 0;
    for (int i = 0 ; i <= 9 ; ++i)
        average +=  endtime[i];
    average /= 9;
    myfile << "average is: " << average;

    myfile.close();
    return;

}
int main()
{
    srand(time(NULL));
    GetTime();
    PrintfTime();
    return 0;
}
