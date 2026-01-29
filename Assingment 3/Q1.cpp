#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int length = dp[m][n];
    char lcs[length + 1];
    lcs[length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[length - 1] = s1[i - 1];
            i--;
            j--;
            length--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "Longest Common Subsequence = " << lcs << endl;

    return 0;
}
