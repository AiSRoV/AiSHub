
МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 4<br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы ИВТ-б-о-191(2)  
<br/>Слюсарева Владислава Викторовича  
<br/>направления подготовки 09.03.01 "Информатика и вычислительная техника" 

<br/><br/>
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

#### Цель

1. Научиться работать с текстовыми файлами;
2. Закрепить навыки работы со структурами.

#### Ход работы

1. Программный код
    ```cpp
   #include <fstream>
#include <iostream>
#include <cstring>
#include <string>

int to_int(std::string arr) {
    int res = 0;
    int temp = 0;
    while (isdigit(arr[temp])) {
        res *= 10;
        res += arr[temp] - 48;
        temp++;
    }
    return res;
}

enum pclass {
    NONE1 = 0,
    FIRST,
    SECOND,
    THIRD
};

enum sex {
    NONE2 = 0,
    MALE,
    FEMALE
};

enum state {
    NONE3 = 0,
    C,
    Q,
    S
};

struct people {
    int id = 0;
    int surv = 0;
    pclass people_pclass = NONE1;
    sex people_sex = NONE2;
    int age = 0;
    state people_state = NONE3;
};

void parse(std::ifstream* in, people* man) {
    std::string str;
    for (int i = 0; i < 12; i++) {
        if (getline(*in, str, ','))
            switch (i) {
            case 0:
                if (str.length())
                    man->id = to_int(str);
                break;
            case 1:
                if (str.length())
                    man->surv = to_int(str) + 1;
                break;
            case 2:
                if (str.length())
                    switch (to_int(str)) {
                    case 1:
                        man->people_pclass = FIRST;
                        break;
                    case 2:
                        man->people_pclass = SECOND;
                        break;
                    case 3:
                        man->people_pclass = THIRD;
                        break;
                    }
                break;
            case 5:
                if (str.length())
                    switch (str[0]) {
                    case 'm':
                        man->people_sex = MALE;
                        break;
                    case 'f':
                        man->people_sex = FEMALE;
                        break;
                    }
                break;
            case 6:
                if (str.length())
                    man->age = to_int(str);
                break;
            }

    }
    getline(*in, str, '\r');
    if (str.length())
        switch (str[0]) {
        case 'S':
            man->people_state = S;
            break;
        case 'Q':
            man->people_state = Q;
            break;
        case 'C':
            man->people_state = C;
            break;
        }
}

bool is_zero(people* man) {
    return man->age || man->surv || man->people_state || man->people_sex || man->people_pclass || man->id;
}

int main() {
    std::ifstream in("/home/canned_dead/Документы/CLionProjects/prog/cmake-build-debug/train.csv");
    char buf[250];
    int surv = 0, first = 0, second = 0, third = 0, male = 0, female = 0;
    int age = 0, m_age = 0, w_age = 0, all_m = 0, all_w = 0;
    int q = 0, s = 0, c = 0;

    in.getline(buf, 250, '\r');

    while (true) {
        people ma;
        parse(&in, &ma);
        if (!is_zero(&ma)) break;
        else {
            if (ma.age) {
                if (ma.age <= 18) std::cout << ma.id << " ";
                age += ma.age;
                if (ma.people_sex) {
                    switch (ma.people_sex) {
                    case MALE:
                        m_age += ma.age;
                        all_m++;
                        break;
                    case FEMALE:
                        w_age += ma.age;
                        all_w++;
                        break;
                    }
                }
            }
            if (ma.surv && (ma.surv - 1)) {
                surv++;
                if (ma.people_sex) {
                    switch (ma.people_sex) {
                    case MALE:
                        male++;
                        break;
                    case FEMALE:
                        female++;
                        break;
                    }
                    switch (ma.people_pclass) {
                    case FIRST:
                        first++;
                        break;
                    case SECOND:
                        second++;
                        break;
                    case THIRD:
                        third++;
                        break;
                    }
                }
            }
            if (ma.people_pclass) {
                switch (ma.people_pclass) {
                case Q:
                    q++;
                    break;
                case S:
                    s++;
                    break;
                case C:
                    c++;
                    break;
                }
            }

        }
    }
    in.close();

    std::cout << std::endl << "Всего выживших: " << surv << "   Выживших мужчин " << male << "   Выживших женщин " << female << std::endl;
    std::cout << "Первый класс " << first << "   второй класс " << second << "    третий класс " << third << std::endl;
    std::cout << "Средний возраст " << age / (all_m + all_w) << "   Ср.в.м " << m_age / all_m << "   Ср.в.ж " << w_age / all_w << std::endl;
    if (q == std::max(q, std::max(s, c))) std::cout << "Q";
    else if (c == std::max(q, std::max(s, c))) std::cout << "C";
    else if (s == std::max(q, std::max(s, c))) std::cout << "S";

    return 0;
}
    ```
2. Результат рассчета

    | Характеристика | Результат |
    |---|---|
    | Всего выживших | 342 |
    |  Выживших 1 класса | 136 |
    |  Выживших 2 класса | 87 |
    |  Выживших 3 класса | 119 |
    |  Выживших мужчин | 109 |
    |  Выживших женщин | 233 |
    |  Ср. возраст | 29 |
    |  Ср.в.м | 31 |
    |  Ср.в.ж | 28 |
    |  Штат-рекордсмен | SOUTHAMPTON |
    |  Идентификаторы несовершеннолетних | 8 10 11 15 17 23 25 39 40 44 50 51 59 60 64 69 72 85 87 112 115 120 126 139 145 148 157 164 165 166 172 173 176 183 184 185 194 205 206 209 221 229 234 238 262 267 279 283 298 308 312 330 334 341 349 353 372 375 382 386 387 390 408 418 420 425 434 436 446 447 449 480 481 490 501 505 506 531 533 536 542 543 550 551 575 586 619 635 643 652 655 676 678 684 687 689 690 692 701 703 721 722 732 747 751 752 758 765 776 778 781 782 787 788 789 792 803 808 814 820 825 828 831 835 842 845 851 853 854 856 870 876 |
3. Запись в файл
    ```text
   8, 10, 11, 15, 17, 23, 25, 39, 40, 44, 50, 51, 59, 60, 64, 69, 72, 85, 87, 112, 115, 120, 126, 139, 145, 148, 157, 164, 165, 166, 172, 173, 176, 183, 184, 185, 194, 205, 206, 209, 221, 229, 234, 238, 262, 267, 279, 283, 298, 308, 312, 330, 334, 341, 349, 353, 372, 375, 382, 386, 387, 390, 408, 418, 420, 425, 434, 436, 446, 447, 449, 480, 481, 490, 501, 505, 506, 531, 533, 536, 542, 543, 550, 551, 575, 586, 619, 635, 643, 652, 655, 676, 678, 684, 687, 689, 690, 692, 701, 703, 721, 722, 732, 747, 751, 752, 758, 765, 776, 778, 781, 782, 787, 788, 789, 792, 803, 808, 814, 820, 825, 828, 831, 835, 842, 845, 851, 853, 854, 856, 870, 876, 
   Всего выживших 342   Выживших мужчин 109   Выживших женщин 233
   Первый класс 136   второй класс 87    третий класс 119
   Ср. возраст 29   Ср.в.м 31   Ср.в.ж 28
   SOUTHAMPTON 
    ```
   
**Вывод**: в ходе выполнения лабораторной работы были получены навыки
* работы с CSV файлами;
* чтения и записи файлов.
