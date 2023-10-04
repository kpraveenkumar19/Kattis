#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string code, guess;
    cin >> code >> guess;

    int codeR[26];guessR[26];

    int r = 0, s = 0;
    for(int i = 0; i < n; i++) {
        if(code[i] == guess[i]) {
            r++;
        }
        else {
            codeR[code[i]-65]++;guessR[guess[i]-65]++;
        }
    }

    for(int i=0;i<26;i++) s+=min(codeR[i],guessR[i]);

    cout << r << " " << s << endl;
}
