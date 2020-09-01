//
// Created by Chang WEI on 2020/9/1.
//
#include <random>
#include <vector>
using std::vector, std::swap;
int insertionsort(vector<int> &n, int lc, int rc)
{
    int i, j;
    for (i = lc+1; i <= rc; ++i) {
        int tmp = n[i];
        for (j = i - 1; j >= lc; --j) {
            if (tmp < n[j])
                n[j+1] = n[j];
            else
                break;
        }
        n[j+1] = tmp;
    }
    return (lc+rc)/2;
}
int median_m5(vector<int> &n, int lc, int rc)
{
    if (rc-lc+1 <= 5)
        return insertionsort(n, lc, rc);

    int mc = lc - 1, tmp;
    for (; rc-lc+1 >= 5; lc += 5)
    {
        tmp = median_m5(n, lc, lc+4);
        swap(n[++mc], n[tmp]);
    }
    if (lc != rc)
    {
        tmp = median_m5(n, lc, rc);
        swap(n[++mc], n[tmp]);
    }
    return median_m5(n, lc, mc);
}
int quickselect(vector<int> &n, int lc, int rc, int k)
{
    int pidx = median_m5(n, lc, rc);
    int pivot = n[pidx];
    swap(n[pidx], n[rc]);
    int i = lc-1, j = rc;
    while (i < j) {
        while (++i <= rc && n[i] < pivot)
            ;
        while (--j >= lc && n[j] > pivot)
            ;
        if (i < j)
            swap(n[i], n[j]);
    }
    swap(n[i], n[rc]);
    if (i == k-1)
        return pivot;
    else if (i < k-1)
        return quickselect(n, i+1, rc, k);
    else
        return quickselect(n, lc, i-1, k);
}
void GenerateRandomNumber(vector<int> &container, int n)
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<int> dist(0, 50);
    for (int i = 0; i < n; ++i)
        container.push_back(dist(rng));
}
