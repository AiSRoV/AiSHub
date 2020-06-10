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