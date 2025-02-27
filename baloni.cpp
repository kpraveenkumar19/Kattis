#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> counts;//counts the number of arrows flowing at height h
    counts.resize(1000001, 0);

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(counts[temp] == 0) {//no arrow flowing in that height
            counts[temp-1]++;//creating a new arrow at this height it hits that and moves in a height less than that 
        }
        else {//an arrow flowing in that height
            counts[temp-1]++;//arrow hits and flows in aheight below that
            counts[temp]--;
        }
    }

    int throws = 0;
    for(int i = 0; i < 1000000; i++) {
        throws += counts[i];
    }
    cout << throws << endl;
}
// check wethear an arrow is flowing in that height if yes then dont create arrow just flow that arrow at height H-1 else create an arrow which at that H
// and later flows at height H-1 and count array maintains the details of all the arrow flowing at present!
