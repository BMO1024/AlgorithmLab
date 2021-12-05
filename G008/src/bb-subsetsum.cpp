#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#define MAX_NUM 100
#define TESTCASE_NUM 8
using namespace std;

int n = 0;
int w[MAX_NUM];
bool x[MAX_NUM];
int c;
int sub_sum = 0;
int remain_sum;
int print_count = 0;


void testcase_read(string file_num) {
    ifstream fileread;
    string prefix = "./data/subsetsum-";
    string suffix_c = "-1.data";
    string suffix_w = "-2.data";
    fileread.open(prefix + file_num + suffix_c);
    fileread >> c;
    fileread.close();
    fileread.open(prefix + file_num + suffix_w);
    n = 0;
    while (true) {
        int num;
        n++;
        fileread >> num;
        if (num != 0)
            w[n] = num;
        else {
            n--;
            break;
        }
    }
    fileread.close();
}

void print() {
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

int bound(int j) {
    int remain = 0;
    for (int k = j; k <= n; k++)
        remain += w[k];
    return remain;
}

void branchbound(bool x[], int i, int has) {
    if (i > n)
        return;
    if (has + w[i] == c) {
        x[i] = 1;
        print();

        x[i] = 0;
        return;
    }
    if ((has + bound(i) >= c) && (has + w[i] <= c)) {
        x[i] = 1;
        branchbound(x, i + 1, has + w[i]);
        x[i] = 0;
    }
    if (has + bound(i) - w[i] >= c) {
        x[i] = 0;
        branchbound(x, i + 1, has);
    }
}

void bb_test(string testcase) {
    cout << "Testing case " << testcase << ":" << endl;
    testcase_read(testcase);
    print_count = 0;
    remain_sum = 0;
    for (int i = 1; i <= n; i++)
        remain_sum += w[i];
    while (c > 0) {
        for (int i = 1; i <= n; i++)
            x[i] = 0;
        branchbound(x, 0, sub_sum);
        if (print_count > 0)
            break;
        c--;
    }
}

int main() {
    int i;
    cout << "=====Branch&bound Algorithm=====" << endl;
    for (i = 1; i <= TESTCASE_NUM; i++)
        bb_test(to_string(i));
    cout << "=============================" << endl;
    return 0;
}