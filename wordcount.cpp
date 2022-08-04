#include <iostream>
using namespace std;

int main()
{
    string str = "";
    int ch = 1;
    int frames;
    cout << "Enter the number of frames : ";
    cin >> frames;
    for (int i = 0; i < frames; i++)
    {
        cout << "Enter frame " << i + 1 << " : ";
        string s;
        cin >> s;
        char l = (s.length() + 1) + '0';
        str += l;
        str += s;
    }
    cout << "Frame sent : " << str;
    cout << endl;

    int i = 0;
    int z = 0;
    while (str[i] != '\0')
    {
        int s = str[i] - '0';
        int j = i;
        cout << "Frame--->" << ++z << "   ";
        for (i = i + 1; i < s + j; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }
}