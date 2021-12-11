#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#define MAX_NUM 100
#define TESTCASE_NUM 7
using namespace std;

int n = 0;
int w[MAX_NUM];
bool x[MAX_NUM];
int dp_table[100][10000];
int c;
int sum = 0;

void dp(){
    int i, j;
    for(i = 1; i <= n; i++)
        dp_table[i][0] = 0;
    for(j = 0; j <= c; j++){
        if(j >= w[n])
            dp_table[n][j] = w[n];
        else
            dp_table[n][j] = 0;
    }
    for(j = 1; j <= c; j++){
        for(i = n - 1; i >= 1; i--){
            if(j < w[i])
                dp_table[i][j] = dp_table[i + 1][j];
            else
                dp_table[i][j] = max(dp_table[i + 1][j], dp_table[i + 1][j - w[i]] + w[i]);
        }
    }
}

void traceback(int i, int j){
    if(i == n){
        if(j >= w[n])
            x[n] = 1;
        else
            x[n] = 0;
        for(int k = 1; k <= n; k++)
            cout << x[k] << " ";
        cout << endl;
    }
    else{
        if(j - w[i] >= 0){
            if(dp_table[i + 1][j] > dp_table[i + 1][j - w[i]] + w[i]){
                x[i] = 0;
                traceback(i + 1, j);
            }
            else if(dp_table[i + 1][j] < dp_table[i + 1][j - w[i]] + w[i]){
                x[i] = 1;
                traceback(i + 1, j - w[i]);
            }
            else{
                x[i] = 0;
                traceback(i + 1, j);
                x[i] = 1;
                traceback(i + 1, j - w[i]);
            }
        }
        else{
            x[i] = 0;
            traceback(i + 1, j);
        }
    }
}

void testcase_read(string file_num){
    ifstream fileread;
    string prefix = "./data/subsetsum-";
    string suffix_c = "-1.data";
    string suffix_w = "-2.data";
    fileread.open(prefix + file_num + suffix_c);
    fileread >> c;
    fileread.close();
    fileread.open(prefix + file_num + suffix_w);
    n = 0;
    while(true){
        int num;
        n++;
        fileread >> num;
        if(num != 0)
            w[n] = num;
        else{
            n--;
            break;
        }
    }
    fileread.close();
}

void dp_test(string testcase){
    cout << "Testing case " << testcase << ":" << endl;
    testcase_read(testcase);
    long time1 = clock();
    for(int i = 1; i <= n; i++)
        x[i] = 0;
    dp();
    traceback(1, c);
    cout << "Time cost: " << clock() - time1 << endl;
}

int main(){
    int i;
    cout << "=====Dyanamic Programming Algorithm=====" << endl;
    for(i = 1; i <= TESTCASE_NUM; i++)
        dp_test(to_string(i));
    cout << "========================================" << endl;

    return 0;
}