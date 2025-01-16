#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int x, p, n;
    cin >> x >> p >> n;

    /*
        // int -> bit
        bitset<sizeof(int) * 8> bit;
        bit = bitset<sizeof(int) * 8>(x);

        // flip
        for (int start = p - n + 1; start <= p; start++)
        {
            bit.flip(start);
        }

        // bit -> int
        x = 0;
        for (int i = 0; i < 32; i++)
        {
            x += bit[i] << i;
        }
    */

    for (int start = p - n + 1; start <= p; start++)
    {
        x ^= (1 << (start));
    }

    cout << x << endl;
    return 0;
}