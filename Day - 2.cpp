#include <iostream>
using namespace std;

int find(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    return 1;
                    //return 1 if at least 1 triplet found
                }
            }
        }
    }
    // if no triplet found so return 0
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    cout<<find(array, n)<<endl;
    return 0;
}
