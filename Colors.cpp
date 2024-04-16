#include <iostream>
#include <string>
#include <iomanip>

struct student {
    int id;
    std::string name;
    int curs;
    std::string group;
    int year;

    std::string* pn = &name;
    std::string* pg = &group;
};

bool exist(int ind, int* index, int len) {
    for (int i = 0; i < len; i++) {
        if (index[i] == -1) return false;
        if (index[i] == ind) return true;
    }
    //return false;
}

void indexing(student st[], int slen, int indexSt[], long long dp) {

    using namespace std;

    int i, j, n;

    for (i = 0; i < slen; i++) indexSt[i] = -1;

    string min = "";
    int indexMin = -1;


    for (i = 0; i < slen; i++) {    // indexing
        for (n = 0; exist(n, indexSt, slen); n++);
        min = *(std::string*)((long long)st[n].pn + dp); // st[n].name;
        indexMin = n;

        for (j = 0; j < slen; j++) {
            if (exist(j, indexSt, slen)) continue;

            std::string sx = *(std::string*)((long long)st[j].pn + dp); //st[j].name

            if (sx.compare(min) == -1) {
                min = sx; indexMin = j;
            }
        }
        indexSt[i] = indexMin;
    }

}




int main() {
    using namespace std;
    setlocale(LC_ALL, "Russian");

    student st[10] = {
        {1, "Петров Иван", 3, "111",  2018},
        {2, "Серов Сергей", 2, "112",  2018 },
        {3, "Кирилов Александр", 1, "112",  2020},
        {4, "Климова Наталья", 3, "112",  2019},
        {5, "Орлов Сергей", 2, "110",  2018},
        {6, "Борисов Александр", 1, "110",  2020},
        {7, "Семенова Наталья", 2, "114",  2018},
        {8, "Анисимова Мария ", 1,"110",  2020 }
    };

    int i, j, n;
    int slen = sizeof(st) / sizeof(st[0]);

    slen = 8;

    int indexSt[10];

    long long dp = (long long)st[0].pg - (long long)st[0].pn;

    dp = 0;

    indexing(st, slen, indexSt, dp);

    cout << "---------------------------------------------\n";
    cout << "| Id | Фамилия Имя          | Группа | Курс |\n";
    cout << "---------------------------------------------\n";

    for (j = 0; j < slen; j++) {
        i = indexSt[j];
        if (st[i].group > "") {
            cout << "|" << setw(3) << right << st[i].id << " | " << setw(20) << left << st[i].name << " | "
                << setw(6) << right << st[i].group << " | " << setw(4) << st[i].curs << " | " << "\n";
            cout << "---------------------------------------------\n";
        }
    }

    cout << "\n\n";
    cout << "---------------------------------------------\n";
    cout << "| Id | Фамилия Имя          | Группа | Курс |\n";
    cout << "---------------------------------------------\n";

    int found;
    for (j = 0; j < slen; j++) {
        i = indexSt[j];
        found = st[i].name.find("К");
        if (found != string::npos) {
            cout << "|" << setw(3) << right << st[i].id << " | " << setw(20) << left << st[i].name << " | "
                << setw(6) << right << st[i].group << " | " << setw(4) << st[i].curs << " | " << "\n";
            cout << "---------------------------------------------\n";
        }
    }

    for (int k = 0; k < slen; k++)  cout << indexSt[k];

    return(0);
}


//#include <iostream>
//#include <windows.h>
//
//#include <string>
//
//struct s1 {
//    std::string name;
//    int m;
//    std::string group;
//    std::string* pn = &name;
//    std::string* pg = &group;
//};
//
//int main() {
//
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    SetConsoleTextAttribute(hConsole, 6);
//
//    s1 s[]{ { "Ivanov ",2, " P34 "}, { " Petrov ",3, " P35"} };
//;
//
//    auto dp = (long long)s[0].pg - (long long)s[0].pn;
//
//    std::string* p3 = (std::string *) ((long long)s[0].pn + dp);
//
//
//    std::cout << *s[0].pn << "  " << *s[0].pg << " " <<dp << " " << *(std::string*)((long long)s[0].pn + dp) <<"\n";
//    std::cout << *s[1].pn << "  " << *s[1].pg << " " << dp << " " << *(std::string*)((long long)s[1].pn + dp) << "\n";
//
//}
//
//
