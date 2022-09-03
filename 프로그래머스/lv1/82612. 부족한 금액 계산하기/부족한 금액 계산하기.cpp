#include <iostream>
#include <math.h>

using namespace std;

long long solution(int price, int money, int count)
{
    long long req = 1LL * price * count * (count + 1) / 2;

    return req >= money ? req - money : 0;
}