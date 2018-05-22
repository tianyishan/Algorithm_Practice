
//
// Created by Tianyi Shan on 5/20/18.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n;
int maze[1001][1001];
int anwser[1001][1001];
int steps[1000001][2];
int linknum;

void solve(  int i , int j ){
    //visited
    if(anwser[i][j]>0){
        return ;
    }
    //safe landing
    anwser[i][j] = 1;
    //next step;

    steps[linknum][0] = i;
    steps[linknum][1] = j;
    linknum ++;

    if (j+1 < n && (maze[i][j] != maze[i][j+1]) ){
             solve (i, j+1);
    }
    if (i+1 < n && (maze[i][j] != maze[i+1][j])){
            solve (i+1, j);
    }
    if (j-1 >= 0 &&(maze[i][j] != maze[i][j - 1])) {
             solve(i, j - 1);
    }
    if (i-1 >=0 &&( maze[i][j] != maze[i-1][j])){
             solve (i-1, j);
    }
    return ;
}

int main() {
    int  m, i, j;
    scanf("%d %d", &n, &m); // read the maze and m request
    int x[m], y[m];
    memset(anwser, -1, sizeof(anwser));

    //read value


    for(int i = 0; i < n; i++){
        char str[1010];
        scanf("%s", &str);
        for(int j = 0; j < n; j++){
            maze[i][j] = str[j] - 48;
        }
    }

    for (int tmp  = 0; tmp < m; tmp++){
        scanf("%d %d", &x[tmp], &y[tmp]);

    }

    for (int tmp  = 0; tmp < m; tmp++){
        linknum =0;
        i = x[tmp];
        j = y[tmp];

        if(anwser[i-1][j-1]>0){
            printf("%d\n", anwser[i-1][j-1]);
            continue;
        }

        solve( i-1, j-1);
        for (int x = 0; x < linknum; x++){
            anwser[steps[x][0]][steps[x][1]] = linknum;
        }

        printf("%d\n", anwser[i-1][j-1]);

    }

    return 0;
}







