#include <iostream>
#include <vector>
using namespace std;
vector<long long> result;

void Weird( long long  n)
{
    result.push_back(n);
    if (n == 1)
    {
        return;
    }
    if (n % 2 == 0)
    {
        Weird(n / 2);
    }
    else
    {
        Weird((n * 3) + 1);
    }
}

int main()
{
    long long n;
    cin >> n;
    Weird(n);

    for (int i = 0; i < (int)result.size(); i++) {

        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
