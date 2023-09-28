#include <bits/stdc++.h>

using namespace std;

int ceildivide(int top, int bot) {
    return ceil(top/(double)bot);// max number of req processing at an unknown milli second / k = max no of req handled by a server in a second
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;//n denotes total req to be coming and m denotes number of reqs handled  by one server per sec
    cin >> n >> m;

     vector<int> seen(100005,0);// seen maps the chronolgical time with the number of reqs at that chronolgical time
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        seen[temp]++;
    }


    int processing = 0;// it stores the total number of req processing or running at present time after each chronological second
    for(int i = 0; i <= 999; i++) {
        processing += seen[i];
    }

    int best = processing;// stores no of req processing in the duration of first second.
    for(int i = 1000; i <= 100000; i++) {//loops for every milisecond and removes the req from total req which are completed and that second and adds the reqs reuested at that second to the total req
        processing += seen[i]; // addition of req at that time to the total req          
        processing -= seen[i-1000];//removal of req from total req which completed at that second
        best = max(best, processing); //records the max no of reqs processing after every milli second
    }

    cout << ceildivide(best, m) << endl;
}
