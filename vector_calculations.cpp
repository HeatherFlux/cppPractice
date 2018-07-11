/*
Given an array of integers, calculate the fractions of its elements that
are positive, negative, and are zeros. Print the decimal value of each
fraction on a new line.
*/

void plusMinus(vector<int> arr) {
    int n = arr.size();
    float r[3]{0,0,0};

    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       r[(arr[arr_i]>0?0:(arr[arr_i]<0?1:2))]+=1.0/n;
    }
    printf("%.6f\n%.6f\n%.6f",r[0],r[1],r[2]);

    return ;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}
