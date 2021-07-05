#include <iostream>

int calculate(int n1, int n2, char oper)
{
    switch (oper)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    case '%':
        return n1 % n2;
    default:
        std::cout << "Invalid operator: " << oper;
        return 0;
    }
}

int main()
{
    std::cout << "Enter a number: ";
    int n1{ };
    std::cin >> n1;

    std::cout << "Enter another number: ";
    int n2{ };
    std::cin >> n2;

    std::cout << "Enter one of the following operators: + - * / %: ";
    char oper{ };
    std::cin >> oper;

    std::cout << "\nResult is: " << calculate(n1, n2, oper);

    return 0;
}

