/* Задание 3. Реализация программы таймера

Что нужно сделать
Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут и секунд, которые
требуется засечь на таймере, и нажимает «Ввод». После этого начинается обратный
отсчёт времени, о чём незамедлительно и последовательно сообщается пользователю.
Формат вывода такой же, как и при вводе интервала: минуты и секунды. Как только
отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль
специального сообщения. Сообщение вместо аудиосигнала может выглядеть так: DING!
DING! DING!

Советы и рекомендации
Для ввода значения для засекания времени используйте std::get_time, но в
качестве формата запросите только минуты и секунды. Целевое время для остановки
таймера вычислите сами с помощью манипуляции над текущим std::time. Количество
оставшегося времени выводите в цикле и вычислите его самостоятельно с помощью
обращения с типом std::time_t как с секундами.

Что оценивается
Корректность работы программы при разных заданных дефинициях макросов.
*/

#include <ctime>
#include <iomanip>
#include <iostream>

int main(int argc, char const *argv[]) {
    // Приветствие
    std::cout << "Продвинутые темы и техники C++\n";
    std::cout << "Урок 6. Работа с датами\n";
    std::cout << "Задание 3. Реализация программы таймера\n\n";

    std::time_t currentTime = std::time(nullptr);
    std::tm local = *std::localtime(&currentTime);
    std::cout << "Введите количество минут и секунд в формате мни:сек ";
    std::cin >> std::get_time(&local, "%M:%S");

    // текущее время в секундах, поэтому введенное время переводим в секунды
    int timerInSecundes = local.tm_min * 60 + local.tm_sec;

    std::cout << "Старт таймера ";
    std::cout << std::put_time(&local, "%M:%S") << std::endl;
    std::time_t timerStart = std::time(nullptr);
    std::time_t timePrintTimer = timerStart;
    currentTime = timerStart;

    while (currentTime - timerStart < timerInSecundes) {
        if (currentTime - timePrintTimer == 1) {
            // int secondsLeft = timerInSecundes - (currentTime - timerStart);
            // int minutes = secondsLeft / 60;
            // int seconds = secondsLeft % 60;
            // std::cout << secondsLeft << std::endl;
            // std::string chM = minutes < 10 ? "0" : "";
            // std::string chS = seconds < 10 ? "0" : "";
            // std::cout << chM << minutes << ":" << chS << seconds <<
            // std::endl;

            // нужны секунды, чтоб отнимать по одной
            // т.к. local.tm_sec -= 1; не работает
            timePrintTimer = std::mktime(&local);
            --timePrintTimer;
            local = *std::localtime(&timePrintTimer);
            std::cout << std::put_time(&local, "%M:%S") << std::endl;
            timePrintTimer = std::time(nullptr);
        }
        currentTime = std::time(nullptr);
    }
    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
