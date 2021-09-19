
#include <iostream>
using namespace std;
#include <ctime>

//ранд число в диапазоне
int random(int a, int b) {
    srand(time(NULL));
    if (a > 0)
        return a + rand() % (b - a);
    else
        return a + rand() % (abs(a) + b);
}

int check(int n, int min, int max) {
    int x;
    cout << "Угадай число\n";
    cin >> x;
    if (x < min || x > max) {
        cout << "!!! Число выходит за границы диапазона !!!\n";
        return 0;
    }
    if (x < n) {
        cout << "Загаданное число больше\n";
        return 0;
    }
    if (x > n) {
        cout << "Загаданное число меньше\n";
        return 0;
    }
    else if (x == n)
    {
        cout << "ТЫ УГАДАЛ ЧИСЛО !!!\n";
        return 1;
    }
}

int main()
{
    int lvl, num, att, i = 0, min, max;
    char start = '0';
    cout << "Начать игру? (y / n) ";
    cin >> start;
    if (start == 'n')
        return 0;
    if (start == 'y')
    {
        do
        {
            cout << "Выбери уровень сложности: 1 - диапазон от 0 до 100, 2 - диапазон от 0 до 1000, 3 - диапазон от 0 до 5000\n";
            cin >> lvl;
        } while (lvl != 1 && lvl != 2 && lvl != 3);
        switch (lvl)
        {
        case 1:
            num = random(0, 100);
            att = 6;
            min = 0;
            max = 100;
            break;
        case 2:
            num = random(0, 1000);
            att = 10;
            min = 0;
            max = 1000;
            break;
        case 3:
            num = random(0, 5000);
            att = 13;
            min = 0;
            max = 5000;
            break;
        }
        while (check(num, min, max) != 1 && att > i++)
        {
            cout << "Осталось " << att - i << " попыток\n";
        }
    }
    return 0;
}
