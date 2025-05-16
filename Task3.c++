#include <iostream>
#include <vector>
#include <string>
using namespace std;

int WeightedEditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        dp[0][i] = i*Cd;
    }

    for (int j = 0; j <= n; j++) {
        dp[i][0] = j * Ci;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            if (s1[i - 1] == s2[j - 1]) {
                cost = 0;
            } else {
                cost = Cs;
            }

            int deleteCost = dp[i - 1][j] + Cd;
            int insertCost = dp[i][j - 1] + Ci;
            int substituteCost = dp[i - 1][j - 1] + cost;

            dp[i][j] = min(deleteCost, min(insertCost, substituteCost));
        }
    }

    return dp[m][n];
}

vector<string> findClosestWords(string dict[], string input, int Ci, int Cd, int Cs) {
    vector<string> closestWords;
    int minDistance = 999999; 

    for (int i = 0; i < dict.length(); i++) {
        string word = dict[i];
        int distance = WeightedEditDistance(input, word, Ci, Cd, Cs);

        if (distance < minDistance) {
            closestWords.clear();
            closestWords.push_back(word);
            minDistance= distance;
        } else if (distance == minDistance){
            closestWords.push_back(word);
        }
    }
    return closestWords;
}

int main() {
    vector<string> dict;
    int n;

    cout << "Enter the number of words in the dict: ";
    cin >> n;

    cout << "Enter the words in the dict:" << endl;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        dict.push_back(word);
    }

    string input;
    int Ci, Cd, Cs;
    cout<<"Enter Ci= ";
    cin>>Ci;
    cout<<"Enter Cd= ";
    cin>>Cd;
    cout<<"Enter Cs= ";
    cin>>Cs;

    cout << "Enter a word: ";
    cin >> input;

    vector<string> suggest = findClosestWords(dict, input, Ci, Cd, Cs);

    cout << "suggest: ";
    for (int i = 0; i < suggest.size(); i++) {
        cout << suggest[i] << " ";
    }
    cout << endl;

    return 0;
}
