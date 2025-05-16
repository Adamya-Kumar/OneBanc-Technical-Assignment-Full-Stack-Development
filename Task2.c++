#include <iostream>
#include <vector>
#include <string>
using namespace std;

int weighted_edit_distance(string s1, string s2,int Ci, int Cd, int Cs){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        dp[0][i] = i * Cd;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j * Ci;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
if(s1[i - 1] == s2[j - 1]){
cost = 0;
}else{
cost = Cs;
}
int deleteCost = dp[i -1][j]+Cd;
int insertCost = dp[i][j-1] + Ci;
int subCost = cost+dp[i-1][j-1];
dp[i][j] = min(min(deleteCost, insertCost), subCost);
    }
}

return min(dp[m][n]);

int main(){
string s1,s2;
int Ci, Cd, Cs;
cout<<"Enter s1= ";
cin >> s1;
cout<<"Enter s2= ";
cin >> s2;
cout<<"Enter Ci= ";
cin >> Ci;
cout<<"Enter Cd= ";
cin >> Cd;
cout<<"Enter Cs= ";
cin >> Cs;

cout <<Weightededitdistance(s1, s2, Ci, Cd, Cs) << endl;

return 0;
} 
