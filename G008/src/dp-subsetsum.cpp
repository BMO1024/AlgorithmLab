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
int sum = 0;



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
    for(int i = 1; i <= n; i++)
        x[i] = 0;
	// TODO
}

int main(){
    int i;
    for(i = 1; i <= TESTCASE_NUM; i++)
        dp_test(to_string(i));

    return 0;
}