#include <iostream>
#include <vector>
using namespace std;
int median_m5(vector<int> &n, int lc, int rc);
int quickselect(vector<int> &n, int lc, int rc, int k);
void insertionsort(vector<int> &n, int lc, int rc);
void GenerateRandomNumber(vector<int> &container, int n);
int main() {
    vector<int> numbers;
    GenerateRandomNumber(numbers, 12);
    for (auto &num : numbers)
        cout << num << " ";
    cout << endl;
    cout << quickselect(numbers, 0, numbers.size()-1,
            (numbers.size()+1)/2) << endl;

    sort(numbers.begin(), numbers.end(), less<int>());
    for (auto &num : numbers)
        cout << num << " ";
    cout << endl << numbers[(numbers.size()+1)/2 - 1] << endl;

    return 0;
}

