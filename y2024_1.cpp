#include <iostream>

/*
1. Запросить ввод числа элементов массива (11 - 20).
2. Реализовать контроль корректрности ввода.
3. Заполнить массив слю/. числами в диапазоне 100 - 999;

4. Найти среднее, мин и макс значения.
   Использовать функции и динамический массив.

5. Найти золотую середину массива.
   (сортировка пузырьком)
*/

void show_array(int* ar, size_t n) {
    for (int i = 0; i < n; i++)
        std::cout << ar[i] << " ";
    std::cout << "\n";
}


void insertSort(int a[], long size) {
    int x;
    int i, j;
    for (i = 0; i < size; i++) {
        x = a[i];

        for (j = i - 1; j >= 0 && a[j] > x; j--)  
            a[j + 1] = a[j];              // сдвигаем элемент направо,пока не дошли

        a[j + 1] = x;         //  вставить элемент
    }
}

int main() {
    using namespace std;
    setlocale(LC_ALL, "Russian");

    int static_array[30];
    size_t n;

    do {
        cout << "Введите количество элементов массива (11..29) : ";
        cin >> n;
    } while (n < 11 or n > 28);


    for (int i = 0; i < n; i++)
        static_array[i] = 10 + rand() % 90;

    show_array(static_array, n);

    int min = static_array[0];
    int sum = 0;
    for (int i = 1; i < n; i++) {

        sum += static_array[i];

        if (static_array[i] < min)
            min = static_array[i];
    }

    cout << min << "  Среднее значение = " << sum / n << "\n";


  /*  Медианой (золотая серединна) зывается число, стоящее в упорядоченном ряде 
  чисел посередине.  Например в ряду : 1, 2, 3, 7, 9 — тройка является медианой.
  Если количество чисел чётное, то за медиану принимают среднее двух стоящих в центре чисел.
  Т.е. выбирать элемент под номером k / 2, если k чётное и(k + 1) / 2, если нечетное */

    insertSort(static_array, n);
    show_array(static_array, n);

    return 0;
}