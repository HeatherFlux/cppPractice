#include <bits/stdc++.h>
#include <sstream>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    int hr,mn,sc;
    string ampm;
    stringstream ss;
    char delim;
    char time [9];
    int a;

    cin >> s;
    ss << s;
    ss >> hr >> delim >> mn >> delim >> sc >> ampm;
    if ((ampm=="PM" && hr!=12) || (ampm=="AM" && hr==12)){
        hr = (hr+12)%24;
    }
    a = sprintf (time, "%02d:%02d:%02d", hr, mn, sc);
    return time;
}

int main()
{

    string s = "01:26:56AM";
    timeConversion(s);
    return 0;
}
