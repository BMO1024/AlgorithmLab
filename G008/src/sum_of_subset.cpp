#include <iostream>
#include <fstream>
#include <string>
#include "backtrack.h"
#define MAX_NUM 100
using namespace std;

int n = 0;
int w[MAX_NUM];
bool x[MAX_NUM];
int c;
int sum = 0;

void print(){
    for(int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

int bound(int j){
	int remain = 0;
	for(int k = j; k <= n; k++)
		remain += w[k];
	return remain;
}

void backtrack(int level){
	if(level > n)
        return;
    else{
        if(sum + w[level] <= c){
            x[level] = 1;
            sum += w[level];
            if(sum == c)
                print();
            else
                backtrack(level + 1);
            sum -= w[level];
            x[level] = 0;
        }
        if(sum + bound(level + 1) >= c)
            backtrack(level + 1);
    }
}

void testcase_read(string file_num){
    ifstream fileread;
    string prefix = "./testcases/";
    string suffix_c = "_c.txt";
    string suffix_w = "_w.txt";
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

void test(string testcase){
    cout << "Testing case " << testcase << ":" << endl;
    testcase_read(testcase);
	backtrack(1);
}

int main(){
    test("p01");
    test("p02");
    test("p03");
    test("p04");
    test("p05");
    test("p06");
    test("p07");
}