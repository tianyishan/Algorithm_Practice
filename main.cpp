#include <iostream>
#include <cstdio>

using namespace std;

int timecost[105], prices[105], F[1005] = {0};
int maxnum = 0;
int main() {
    int totalTime, totalHerb;
    scanf("%d %d", &totalTime, &totalHerb);

    for (int i = 1; i <= totalHerb; i++){
        scanf("%d %d", &timecost[i], &prices[i]);
    }

    /*for(int z = 0; z < 1005; z++){
        F[0][z] = 0;
    }*/

    for (int i = 1; i <= totalHerb ; i++){

        for(int v = totalTime; v >= timecost[i]; v--) {
            F[v] = max(F[v],F[v-timecost[i]] + prices[i]);
        }
//        for(int v = timecost[i]; v<=totalTime; v++){
//            int tmp = F[i-1][v-timecost[i]] + prices[i];
//            int tmp1 = F[i-1][v];
//            F[i][v] = max(tmp,tmp1);
//        }

    }

    int i = F[totalTime];
    printf("%d\n", i);


    return 0;
}