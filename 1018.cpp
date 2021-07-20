#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int n, m;
string board[50];
int white, black;

string W[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string B[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
int white_check(int x, int y){
    int count = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i+x][j+y] != W[i][j]) count++;
        }
    }
    return count;
}

int black_check(int x, int y){
    int count = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i+x][j+y] != B[i][j]) count++;
        }
    }
    return count;
}

int main(){
    cin >> n >> m;
    int minval=100;
    for(int i=0; i<n; i++)
        cin >> board[i];
    for(int i=0; i+8<=n; i++){
        for(int j=0; j+8<=m; j++){
            int tmp = min(white_check(i,j), black_check(i,j));
            if(minval > tmp) minval = tmp;
        }
    }


    cout << minval << endl;
    return 0;

}