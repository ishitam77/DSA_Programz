#include <bits/stdc++.h>
using namespace std;

//iterative binary search
int binary_search_iterative(vector<string> arr, string key)
{
    int left = 0, right = arr.size();

    while (left <= right) {

        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

//recursive binary search
int binary_search_recursive(vector<string> arr, string key, int left, int right)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binary_search_recursive(arr, key, mid + 1, right);
    return binary_search_recursive(arr, key, left, mid - 1);
}

//to print
void print(vector<string>& a)
{
    for (auto it : a)
        cout << it << " ";
    cout << endl;
}

int main()
{
    cout << "Enter number of words you want to enter for the word list\n";
    int n;
    cin >> n;

    vector<string> arr(n);
    cout << "Enter the words\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter searching key\n";
    //key there
    string key;
    cin >> key;

    cout << "Sorting the input list to ensure binary search works\n";
    sort(arr.begin(), arr.end());

    cout << "Printing the sorted word list\n";

    print(arr);

    clock_t tStart1 = clock();
    int index = binary_search_iterative(arr, key);
    if (index == -1)
        cout << key << " not found\n";
    else
        cout << key << " found at index(0 based): " << index << endl;

    clock_t tend1 = clock();
    printf("Time taken in iterative binary search: %.6fs\n", (double)(tend1 - tStart1) / CLOCKS_PER_SEC);

    clock_t tStart2 = clock();
    index = binary_search_recursive(arr, key, 0, n - 1);
    if (index == -1)
        cout << key << " not found\n";
    else
        cout << key << " found at index(0 based): " << index << endl;
    clock_t tend2 = clock();
    printf("Time taken in recursive binary search: %.6fs\n", (double)(tend2 - tStart2) / CLOCKS_PER_SEC);

    return 0;
}
