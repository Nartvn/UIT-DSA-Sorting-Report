#include "bits/stdc++.h"

using namespace std;

vector < int > vi;
const int MAXN = 1e9;
const int mottrieu = 1e6;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

void addfile(int i)
{
    string name = "test";
    name = name + (char)(i + '0');
    name = name + ".inp";

    ofstream myfile;
    myfile.open (name); /// open file test to print testcase

    for (int i = 0 ; i < (int)vi.size() ; ++i) /// add data to file
        myfile << vi[i] << '\n';

    myfile.close();
    return;
}

void Maketest(int number)
{
    random_shuffle(vi.begin(), vi.end());
    addfile(number);
    return;
}

int main()
{
    srand(time(NULL));

    /// test 0
    for (int i = 1 ; i <= mottrieu ; ++i)
        vi.push_back(i);
    addfile(0);

    /// test 1
    vi.clear();
    for (int i = mottrieu ; i >= 1 ; --i)
        vi.push_back(i);
    addfile(1);
    /// test 2 - 9
    for (int test = 2 ; test <= 9 ; ++test)
        Maketest(test);

    return 0;
}
