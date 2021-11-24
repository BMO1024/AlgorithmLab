#include <iostream>
using namespace std;
int n = 10;
int w[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool x[11];
int M = 20;
int sum;

void print(int level){
    for(int i = 1; i <= level; i++)
        if(x[i] == 1)
            cout << w[i] << " ";
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
        if(sum + w[level] <= M){
            x[level] = 1;
            sum += w[level];
            if(sum == M)
                print(level);
            else if(sum + w[level + 1] <= M)
                backtrack(level + 1);
            sum -= w[level];

        }
        if(sum + bound(level + 1) >= M){
            x[level] = 0;
            backtrack(level + 1);
        }
    }
}

int main(){
	int sum = 0;
	backtrack(1);
}

