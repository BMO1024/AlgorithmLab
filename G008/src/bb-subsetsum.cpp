#include <iostream>
#include <fstream>
#include <string>


#define MAX_NUM 100
#define TESTCASE_NUM 8
using namespace std;

int n = 0;
int w[MAX_NUM];
bool x[MAX_NUM];
int c;
int sub_sum = 0;
int sum;
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
    print_count++;
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void branchbound(int i, int has, int remain) {
    if (i > n)
        return;
    if (has + w[i] == c) {
        x[i] = 1;
        print();
        x[i] = 0;
        return;
    }
    if ((has + remain >= c) && (has + w[i] <= c)) {
        x[i] = 1;
        branchbound(i + 1, has + w[i], remain - w[i]);
        x[i] = 0;
    }
    if (has + remain - w[i] >= c) {
        x[i] = 0;
        branchbound(i + 1, has, remain - w[i]);
    }
}

void bb_test(string testcase) {
    cout << "Testing case " << testcase << ":" << endl;
    testcase_read(testcase);
    print_count = 0;
    sum = 0;
    for (int i = 1; i <= n; i++)
        sum += w[i];
    while (c > 0) {
        for (int i = 1; i <= n; i++)
            x[i] = 0;
        branchbound(1, 0, sum);
        if (print_count > 0)
            break;
        c--;
    }
}

int main() {
    int i;
    cout << "=====Branch&Bound Algorithm=====" << endl;
    for (i = 1; i <= TESTCASE_NUM; i++)
        bb_test(to_string(i));
    cout << "================================" << endl;
    return 0;
}
