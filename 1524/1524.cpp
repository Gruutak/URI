//Using DP. Based on the Wedding Shopping problem.

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main(){
    int n, k, grupos[1000][1000], somas[1000][1000], temp;

    somas[1][1] = 0;
    grupos[1][1] = 0;

    while(cin >> n >> k){
        for(int i = 2; i <= n; i++){
            cin >> temp;

            for(int j = 0; j <= i; j++){
                somas[i][j] = INT_MAX;

                somas[i][j] = min(somas[i][j], somas[i-1][j] + (temp - grupos[i-1][j]));

                if(j > 1)
                    somas[i][j] = min(somas[i][j], somas[i-1][j-1]);

                grupos[i][j] = temp;
            }
        }

        cout << somas[n][k] << endl;
    }

    return 0;
}
