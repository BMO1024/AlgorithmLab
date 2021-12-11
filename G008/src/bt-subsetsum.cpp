#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#define MAX_NUM 100
#define TESTCASE_NUM 7
using namespace std;

int n = 0;
int w[MAX_NUM];
bool x[MAX_NUM];
int c;
int sub_sum = 0;
int remain_sum;
int print_count = 0;

void print(){
    print_count++;
    for(int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void backtrack(int level){
	if(level > n)
        return;
    else{
        if(sub_sum + w[level] <= c && sub_sum + remain_sum >= c){
            x[level] = 1;
            sub_sum += w[level];
            remain_sum -= w[level];
            if(sub_sum == c)
                print();
            else
                backtrack(level + 1);
            remain_sum += w[level];
            sub_sum -= w[level];
            x[level] = 0;
        }
        if(sub_sum + remain_sum - w[level] >= c)
            backtrack(level + 1);
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

void bt_test(string testcase){
    cout << "Testing case " << testcase << ":" << endl;
    testcase_read(testcase);
    long time1 = clock();
    print_count = 0;
    remain_sum = 0;
    for(int i = 1; i <= n; i++)
        remain_sum += w[i];
    while(c > 0){
        for(int i = 1; i <= n; i++)
            x[i] = 0;
	    backtrack(1);
        if(print_count > 0)
            break;
        c--;
    }
    cout << "Time cost: " << clock() - time1 << endl;
}

int main(){
    int i;
    cout << "==========Backtrack  Algorithm==========" << endl;
    for(i = 1; i <= TESTCASE_NUM; i++)
        bt_test(to_string(i));
    cout << "========================================" << endl;

    return 0;
}