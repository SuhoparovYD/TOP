﻿#include <iostream>
#include <ctime>

/*9*/

char v[]{ 'a','b','c','d','e','f','g','h','i','j' };

void draw(char m[10][10]) {
    for (int i = 0; i < 10; i++) {              // draw
        for (int j = 0; j < 10; j++)
            std::cout << m[i][j] << " ";
        std::cout << v[i] << "\n";
    }
    std::cout << "0 1 2 3 4 5 6 7 8 9\n";

}

void drawTwo(char m1[][10], char m2[][10]) {

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++)            // draw 1
            std::cout << m1[i][j] << " ";

        std::cout << v[i] << "\t\t";

        for (int j = 0; j < 10; j++)            // draw 2
            std::cout << m2[i][j] << " ";

        std::cout << v[i] << "\n";
    }

    std::cout << "0 1 2 3 4 5 6 7 8 9\t\t0 1 2 3 4 5 6 7 8 9\n";

}


void inpos(int& a, int& b, int& c, int& d)
{
    char ch_a, ch_c;
    do {
        std::cin >> ch_a >> b >> ch_c >> d;
        a = ch_a - 'a';
        c = ch_c - 'a';
        if (a > 9 || b > 9 || c > 9 || d > 9) {
            std::cout << "Wrong input\n";
            continue;
        }

    } while (1 == 0);
}

bool chkf(int left, int right, int top, int bott, char m[][10]) {
    for (int i = left; i <= right; i++)
        for (int j = top; j <= bott; j++)
            if (m[i][j] != '.') 
                return true;

    return false;
}

void randpos(char m[10][10], int n)
{
    int a=0, b=0, c=0, d=0;
    bool ready = true;
    do {
        switch (n) {
        case 4:
            if (rand() & 1) {
                a = c = 1 + rand() % 8;
                b = 1 + rand() % 5;
                d = b + 3;
            }
            else {
                b = d = 1 + rand() % 8;
                a = 1 + rand() % 5;
                c = a + 3;
            }

            m[a][b] = '4'; m[c][d] = '4';
            if (a == c) {
                m[a][b + 1] = m[a][b + 2] = '4';
            }
            if (b == d) {
                m[a + 1][b] = m[a + 2][b] = '4';
            }
            break;

        case 3:
            ready = false;
            if (rand() & 1) {
                a = c = 1 + rand() % 8;
                b = 1 + rand() % 6;
                d = b + 2;
                if (chkf(a - 1, a + 1, b - 1, b + 3, m)) continue;
                m[a][b + 1] = '3';
            }
            else {
                b = d = 1 + rand() % 8;
                a = 1 + rand() % 6;
                c = a + 2;
                if (chkf(a - 1, a + 3, b - 1, b + 1, m)) continue;
                m[a + 1][b] = '3';
            }

            m[a][b] = '3'; m[c][d] = '3';

            ready = true;

            break;

        }
    } while (!ready);
}



void position(char m[10][10]) {
    using namespace std;

    int i, a, b, c, d;

    draw(m);

    cout << "1 большой корабль размером в четыре клетки. (b 1 b 4)\n";
    do {
        cout << "1 : ";
        inpos(a, b, c, d);

        if (m[a][b] == '.' || m[c][d] == '.') {
            if (a == c && m[a][b + 1] == '.' && m[a][b + 2] == '.' && d - b == 3) break;
            if (b == d && m[a + 1][b] == '.' && m[a + 2][b] == '.' && c - a == 3) break;
        }

        std::cout << "Occuped\n";

    } while (1);

    m[a][b] = '4'; m[c][d] = '4';
    if (a == c) {
        m[a][b + 1] = '4'; m[a][b + 2] = '4';
    }
    if (b == d) {
        m[a + 1][b] = '4'; m[a + 2][b] = '4';
    }


    cout << "2 средних корабля размером в три клетки (d 4 f 4)\n";

    for (i = 0; i < 2; i++) {
        draw(m);
        do {
            cout << i + 1 << " : ";
            inpos(a, b, c, d);

            if (m[a][b] == '.' || m[c][d] == '.') {
                if (a == c && m[a][b + 1] == '.' && abs(b - d) == 2) break;
                if (b == d && m[a + 1][b] == '.' && abs(a - c) == 2) break;
            }

            std::cout << "Occuped\n";
        } while (1);

        m[a][b] = '3'; m[c][d] = '3';
        if (a == c)   m[a][b + 1] = '3';
        if (b == d)   m[a + 1][b] = '3';
    }

    cout << "3 небольших корабля размером в две клетки (g 1 g 2)\n";

    for (i = 0; i < 3; i++) {
        draw(m);
        do {
            cout << i + 1 << " : ";
            inpos(a, b, c, d);

            if (m[a][b] != '.' || m[c][d] != '.') continue;

            if (a == c && abs(b - d) == 1) break;
            if (b == d && abs(a - c) == 1) break;

        } while (1);

        m[a][b] = '2'; m[c][d] = '2';
    }

    cout << "4 маленьких кораблика размером в одну клетку(1 1)\n";
    for (i = 0; i < 4; i++) {
        draw(m);
        do {
            cout << i + 1 << " : "; cin >> a >> b;
            if (a > 9 || b > 9) continue;
        } while (m[a][b] != '.');

        m[a][b] = '1';
    }
    draw(m);

}

bool check(char m[10][10]) {
    int i, j;

    for (i = 0; i < 10; i++)                 // check
        for (j = 0; j < 10; j++)
            if (m[i][j] != '.' && m[i][j] != ' ') return false;

    return true;

}

int main() {
    using namespace std;
    srand(time(0));
    system("color 7");
    setlocale(LC_ALL, "Russian");

    char m1[10][10];              // 
    char m2[10][10];              // 

    int i, j;

    for (i = 0; i < 10; i++)                 // init
        for (j = 0; j < 10; j++) {
            m1[i][j] = '.';
            m2[i][j] = '.';
        }
    /*  test */
     m2[1][1] = '1';   //  m1[2][3] = '2';     m1[2][4] = '2';

     drawTwo(m1, m2);

     randpos(m1, 4);
     randpos(m1, 3);
     randpos(m1, 3);

    cout << "\nВведем позиции кораблей 1-го игрока. \n\n";
    cout << "(1-я координата - по вертикали,  2-я - по горизонтали)\n";
    position(m1);
    cout << "Введем позиции кораблей 2-го игрока. \n";
    cout << "(1-я координата - по вертикали,  2-я - по горизонтали)\n";
    position(m2);

    bool fl;    // Флаг повторного хода при попадании
    while (1) {
        //1-й игрок
        fl = true;
        while (fl) {
            do {
                cout << "Ход 1-го игрока (верт, гориз.) :";  cin >> i >> j;
            } while ((i > 9 || j > 9));

            if (m2[i][j] != '.' && m2[i][j] != ' ') {
                cout << "Попал!\n";
                m2[i][j] = ' ';

                if (check(m2)) {
                    cout << "Победа 1-го игрока!\n";
                    return 0;
                }
            }
            else {
                fl = false; cout << "Мимо.\n";
            }


        }

        // 2-й игрок
        fl = true;
        while (fl) {
            do {
                cout << "Ход 2-го игрока (верт, гориз.) :";  cin >> i >> j;
            } while ((i > 9 || j > 9));

            if (m1[i][j] != '.' && m1[i][j] != ' ') {
                cout << "Попал!\n";
                m1[i][j] = ' ';

                if (check(m1)) {
                    cout << "Победа 2-го игрока!\n";
                    return 0;
                }
            }
            else { fl = false; cout << "Мимо.\n"; }
        }
    }

    return 0;
}