#include <iostream>
#include <cstdio>


using namespace std;
int main() {
    int totalTime, totalHerb;
    scanf("%d %d", &totalTime, &totalHerb);
    int cost[105];
    int prices[105];
    for (int i = 1; i <= totalHerb; i++){
        scanf("%d %d", &cost[i], &prices[i]);
    }
    int F[105][1005];
    for(int z = 0; z < 1005; z++){
        F[0][z] = 0;
    }

    for (int i = 1; i <= totalHerb ; i++){
        for(int v = 0; v < cost[i] ;  v++){
            F[i][v] = F[i-1][v];

        }
        for(int v = cost[i]; v<=totalTime; v++){

            int tmp = F[i-1][v-cost[i]] + prices[i];
            int tmp1 = F[i-1][v];
            F[i][v] = max(tmp,tmp1);
        }

    }

    int i = F[totalHerb][totalTime];
    printf("%d\n", i);


    return 0;
}