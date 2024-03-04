/* 1. Ведомость учёта

Что нужно сделать
Вы уже создавали программу чтения и записи ведомости. Теперь её нужно обобщить и
дополнить использованием структур. Формат ведомости прежний:
• сначала — имя и фамилия получателя денег,
• далее — дата выдачи в формате ДД.ММ.ГГГГ,
• затем — сумма выплаты в рублях. Данные разделяются пробелами.
В конце каждой записи должен быть перевод строки. Структура данных должна
соответствовать этому формату.

При старте программы пользователь отправляет команду: list или add. Команда list
осуществляет чтение из файла ведомости, как и прежде, только уже в структуры
данных, и отображает их на экране. Команда add добавляет новую запись в конец
ведомости.

Советы и рекомендации
• Чтобы определить, где заканчивается файл, используйте функцию file.eof().
• Из-за завершающего переноса строки при чтении данных из файла стоит отдельно
прочитать имя получателя денег. Если после чтения имени получателя денег признак
file.eof() принял значение true, значит, файл закончился.
• Используйте вектор структур. Для выбора команды потребуется подобная
конструкция:

if (command == "list")
{
…
}
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct record {
    std::string name;
    std::string surname;
    std::string dateOfIssue;
    int payout;
};

void loadPaylist(std::string fileName, std::vector<record> &result);
void printPaylist(std::vector<record> &paylist);
void addRecord(std::string fileName);

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 3. Структуры данных\n";
    std::cout << "Задание 1. Ведомость учёта\n\n";

    std::vector<record> paylist;
    std::string command;
    std::cout << "Введите команду list или add: ";
    std::cin >> command;
    if (command == "list") {
        loadPaylist("paylist.txt", paylist);
        printPaylist(paylist);
    } else if (command == "add") {
        addRecord("paylist.txt");
    } else {
        std::cout << "Ошибка ввода команды. Допустимые команды: list или add\n";
        return 1;
    }
    return 0;
}

bool errorsDate(std::string d) {

    if (d.length() == 10 && d[2] == '.' && d[5] == '.') {
        std::string correct_letters = "0123456789.";
        int countPoints = 0;
        for (char letter : d) {
            if (correct_letters.find(letter) == std::string::npos) {
                return true;
            }
            countPoints += (letter == '.');
        }
        // Чтоб лишних точек не наставили
        if (countPoints != 2) {
            return true;
        }
        int day = std::stoi(d.substr(0, 2));
        int month = std::stoi(d.substr(3, 2));
        int year = std::stoi(d.substr(6, 4));

        if (day < 1 || day > 31 || month < 1 || month > 12) {
            return true;
        }
        // Проверим день 29,30,31, т.к. с 1 по 28 есть в любом месяце
        if (day > 28) {
            int days_mouth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (day > days_mouth[month - 1]) {
                return true;
            }
            // Проверить 29 февраля на високосный год
            if (month == 2 &&
                (!(year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)))) {
                return true;
            }
        }
    } else {
        return true;
    }
    return false;
}

void addRecord(std::string fileName) {
    record newRecord;

    std::cout << "Введите фамилию и имя: ";
    std::cin >> newRecord.surname >> newRecord.name;
    bool errorInput; // для вывода сообщения об ошибке
    do {
        std::cout << "Введите дата выдачи в формате ДД.ММ.ГГГГ: ";
        std::cin >> newRecord.dateOfIssue;
        errorInput = errorsDate(newRecord.dateOfIssue);
        if (errorInput) {
            std::cout << "Ошибка ввода даты\n";
        }
    } while (errorInput);
    std::cout << "Введите сумма выплаты в рублях: ";
    std::cin >> newRecord.payout;

    std::ofstream file(fileName, std::ios::app);
    file << newRecord.name << " " << newRecord.surname << " "
         << newRecord.dateOfIssue << " " << newRecord.payout << std::endl;
}

void loadPaylist(std::string fileName, std::vector<record> &result) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        record lineFile;
        file >> lineFile.name;
        while (!file.eof()) {
            file >> lineFile.surname >> lineFile.dateOfIssue >> lineFile.payout;
            result.push_back(lineFile);
            file >> lineFile.name;
        }
    }
}

void printPaylist(std::vector<record> &paylist) {
    std::cout << "\nВедомость учёта:\n";
    for (int i = 0; i < paylist.size(); i++) {
        std::cout << paylist[i].name << " ";
        std::cout << paylist[i].surname << " ";
        std::cout << paylist[i].dateOfIssue << " ";
        std::cout << paylist[i].payout << "\n";
    };
}
