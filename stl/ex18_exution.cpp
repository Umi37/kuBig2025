#include <algorithm>
#include <chrono>
#include <cmath>
#include <execution>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
using namespace std;

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    double mean = accumulate(data.begin(), data.end(), 0.0) / data.size();
    double sq_sum = accumulate(data.begin(), data.end(), 0.0, [mean](double acc, int val)
}