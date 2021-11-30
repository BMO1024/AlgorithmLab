#include <iostream>
#include <fstream>
#include <string>
#define MAX_NUM 100
#define TESTCASE_NUM 7
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

void backtrack_test(string testcase){
    cout << "Testing case " << testcase << ":" << endl;
    testcase_read(testcase);
    for(int i = 1; i <= n; i++)
        x[i] = 0;
	backtrack(1);
}

int main(){
    int i;
    for(i = 1; i <= TESTCASE_NUM; i++)
        backtrack_test(to_string(i));

    return 0;
}