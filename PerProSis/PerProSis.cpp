#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

int ten_in(string num, int in_base);
int ten_out(int ten, int out_base);

int main()
{
    int out_base, in_base, ten;
    string num;
    std::cout << "Enter the number and base\n";
    std::cin >> num >> in_base;
    std::cout << "Enter the base you want to translate\n";
    std::cin >> out_base;

    transform(num.begin(), num.end(), num.begin(), ::toupper);

    ten = ten_in(num, in_base);
    ten_out(ten, out_base);

    return 0;
}

int ten_in(string num, int in_base)
{
    int ten = 0, a = 0, line_lenght;
    line_lenght = num.size();

    for (int i = 0; i < line_lenght; i++)
    {
        if (isdigit(num[i]))
        {
            a = num[i] - '0';
        }
        if (isalpha(num[i]))
        {
            a = num[i] - 'A' + 10;
        }
        ten += a * pow(in_base, line_lenght - 1 - i );
    }

    return ten;
}

int ten_out(int ten, int out_base)
{
    int max_power = 0, m = ten, k, ost;

    while (m >= out_base)
    {
        m /= out_base;
        max_power++;
    }

    while (max_power >= 0)
    {
        k = pow(out_base, max_power);
        ost = ten / k;
        ten = ten % k;
        max_power--;
        if (ost >= 10)
        {
            char z = ost - 'A' + 10;
            std::cout << z;
        }
        else
            std::cout << ost;
    }

    return 0;
}