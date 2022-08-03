#include <iostream>
using namespace std;

int main()
{
    int bs, rate, p[10] = {0};
    cout << "Enter Bucket SIze : ";
    cin >> bs;
    cout << "Enter Rate : ";
    cin >> rate;
    int ch = 1, nop = 0;
    while (ch)
    {
        cout << "Enter packet size to enter : ";
        cin >> p[nop];
        if (p[nop] > bs)
        {
            cout << "Overflow";
            exit(0);
        }
        cout << "ENter 1 to enter more else 0";
        cin >> ch;
        nop++;
    }
    cout << "sec rec sent remained dropped" << endl;
    int sent = 0, remained = 0, dropped = 0;
    for (int i = 0; i < nop || remained > 0; i++)
    {
        cout << i + 1 << "     " << p[i] << "    ";
        sent = min((p[i] + remained), rate);
        cout << sent << "      ";
        int x = p[i] + remained - rate;
        if (x <= 0)
        {
            remained = 0;
            dropped = 0;
        }
        else
        {
            if (x > bs)
            {
                remained = bs;
                dropped = x - bs;
            }
            else
            {
                remained = x;
                dropped = 0;
            }
        }
        cout << remained << "     " << dropped << endl;
    }
}