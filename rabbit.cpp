﻿// rabbit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


void Jump(int number_1, int number_2, int length, int number_massiv, int* massiv, int* variants) {
    using namespace std;
    for (int i = 1; i <= number_2 && i + length <= number_1; i++) {
        /*
        i - ЭТО ТЕКУЩЕЕ ЧИСЛО, РАВНАЯ ЧИСЛУ СТУПЕНЕК, НА КОТОРОЕ ПРЫГНЕТ ЗАЯЦ
        Условие "i <= number_2" означает, что цикл прервётся, если текущее число ступенек (i), на которое прыгнет заяц будет больше максимальному числу ступенек (k)
        Условие "i + length <= number_1", где length - это общий пройденный путь, означает, что цикл прервётся, если
              текущее число ступенек (i) + общий пройденный путь (length) будет больше общего количества ступенек, которое нужно пройти зайцу (a)
        */
        massiv[number_massiv] = i; //В массиве появляется текущее число ступенек (i), на которое прыгнет заяц. 
        if (length + i == number_1) { //Условие таково "Длина пройденного пути(length) + прыжок зайца(i) = общее количество ступенек, которое нужно пройти зайцу"
            *variants += 1; //Без комментариев...
            for (int j = 0; j <= number_massiv; j++) {
                /*
                j - ЭТО НОМЕР МАССИВА. ПРИ ВЫВОДЕ ЗНАЧЕНИЯ МАССИВА БУДЕТ ИСПОЛЬЗОВАТЬСЯ ИМЕННО j
                Условие "j <= number_massiv" означает, что цикл прервётся, если Номер Массива(j) будет больше Номера Массива(number_massiv)
                P.S Номер массива (j) отличается от Номера массива (number_massiv) тем, что "j" мы будем использовать только при выводе нужных нам значений.
                */
                cout << massiv[j]; // Вывод значения массива
                if (j < number_massiv) { //Для красоты. Либо "+" при условии, что дальше числа будут выводится, либо "\n" при условии, что больше выводится чисел в выражении не будет
                    cout << "+";
                }
                else {
                    cout << "\n";
                }
            }
            return; //Прерывает цикл
        }
        Jump(number_1, number_2, length + i, number_massiv + 1, massiv, variants);
        /*
        Вызов функции, только теперь условия в функции другие.
        */

    }
}

int main()
{
    using namespace std; //Чтобы не писать "std::"

    system("chcp 1251"); //Русификация

    cout << "Кролик, прыгающий на ступеньки\n"; //Кролик, прыгающий на ступеньки

    const int a = 4; //общее количество ступенек, которое нужно пройти зайцу.

    int variants = 0; // Число допустимых вариантов прохождения этого пути(a)

    const int k = 3;//Максимальное число ступенек, на которые может прыгнуть заяц

    int* mas = new int[a]; //Резервируется в массиве место для действий зайца (в каждом значении массива будет число, на которое прыгнул заяц(в ступеньках))

    Jump(a, k, 0, 0, mas, &variants); //Объявление функции

    /*
    Jump(a, k, 0, 0, mas, &variants)

    Первый нуль означает первоначальную длину выражения. В функции она будет с каждым разом прибавлятся. По умолчанию length = 0
    Второй нуль означает Номер Массива, к которому мы будем обращатся и вставлять туда значения
    */

    cout << "Всего вариантов: " << variants; // Выводит количество доступных вариантов



    return 0;
}