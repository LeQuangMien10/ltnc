#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int countN = 0, countP = 0, countZ = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0) countP++;
        else if (a[i] < 0) countN++;
        else countZ++;
    }
    cout << fixed << setprecision(6) << 1.0 * countP/n << endl <<
    fixed << setprecision(6) << 1.0 * countN/n << endl <<
    fixed << setprecision(6) << 1.0* countZ/n;
}
