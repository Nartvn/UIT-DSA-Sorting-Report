#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector < int > endtime;
vector < int > vi;

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

void merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = vi[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vi[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vi[k] = L[i];
            i++;
        }
        else {
            vi[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vi[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vi[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void Get(int number)
{
    string name = "test";
    name = name + (char)(number + '0');
    name = name + ".inp";

    vi.clear();

    ifstream nowfile(name);

    string num;
    while (getline(nowfile, num))
    {
        vi.push_back(SNC(num));
    }

    nowfile.close();

    auto start = high_resolution_clock::now(); /// get starting timepoint
    ///----sorting here-----
    mergeSort(0, (int)vi.size() - 1);
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
    GetTime();
    PrintfTime();
    return 0;
}
