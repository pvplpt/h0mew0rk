## Урок 3. Ввод данных пользователя. Строки

### Практическая работа

#### **В практической работе есть:**

• обязательные задачи, они помогут проверить, как вы усвоили материал модуля; их нужно сдать на проверку куратору;  
• дополнительные задачи, они подойдут тем, кто хочет ещё немного потренироваться в программировании; вы также можете отправить их на проверку и получить обратную связь от куратора, хотя это необязательно.

#### **Цели практической работы:**

• Закрепить навыки работы с целыми числами и арифметическими операциями над ними.  
• Научиться использовать оператор ввода std::cin.  
• Научиться работать со строковыми переменными.

### **Что входит в практическую работу**

#### **Обязательные задачи:**

1. Симулятор маршрутки.
2. Обмен местами.
3. Злостные вредители.

#### **Дополнительная задача:**

4. Повышаем градус сложности\*.

### Задача 1. Симулятор маршрутки

#### **Что нужно сделать:**

Напишите программу, которая симулирует работу маршрутки. Она умеет объявлять остановки и узнавать у пользователя, сколько человек вышло и зашло на остановке. Пассажиры оплачивают проезд при входе. Работать она должна примерно так:

```
Прибываем на остановку «Улица программистов». В салоне пассажиров: 0
Сколько пассажиров вышло на остановке? 0
Сколько пассажиров зашло на остановке? 3
Отправляемся с остановки «Улица программистов». В салоне пассажиров: 3
-----------Едем---------
Прибываем на остановку «Проспект алгоритмов». В салоне пассажиров: 3
…
…
```

Маршрут состоит из четырёх остановок. Напишите программу так, чтобы в конце она выводила, сколько денег мы заработали при условии, что билет стоит 20 руб., а расходы следующие:  
• четверть — на зарплату водителю;  
• пятая часть — на топливо;  
• пятая часть — на налоги;  
• пятая часть — на ремонт машины.

```
Формат вывода (после прибытия на последнюю остановку):
Всего заработали: 100 руб.
Зарплата водителя: 25 руб.
Расходы на топливо: 20 руб.
Налоги: 20 руб.
Расходы на ремонт машины: 20 руб.
Итого доход: 15 руб.
```

#### **Рекомендации по выполнению:**

• В одной программе должен быть как ввод количества вошедших и вышедших пассажиров, так и расчёты доходов и расходов.  
• Стоит вынести названия остановок в переменные.  
• Постарайтесь написать программу так, чтобы в неё без особых изменений можно было добавить ещё несколько остановок.

#### **Что оценивается:**

• Правильность подсчёта текущего количества пассажиров.  
• Правильность подсчёта доходов и расходов.  
• Отсутствие лишних переменных.

### Задача 2. Обмен местами

#### **Что нужно сделать:**

Есть код программы с двумя переменными типа int и выводом этих переменных на экран. Напишите программу, которая меняет значения переменных местами, то есть нужно добиться того, чтобы в переменной a лежит значение b, а в b — значение a.

**Пример программы**

```
int main() {
int a = 42;
int b = 153;
std::cout << "a: " << a << "\n"; /* На экран будет выведено 42 /
std::cout << "b: " << b << "\n"; / На экран будет выведено 153 */

/* Меняем значения */

std::cout << "a: " << a << "\n"; /* На экран будет выведено 153 /
std::cout << "b: " << b << "\n"; / На экран будет выведено 42 /
}
```

#### **Советы и рекомендации:**

Самый простой способ взаимно менять значения переменных — использовать swap (a, b). Тем не менее важно понимать, как работает операция по обмену значений двух переменных.
Для начала посмотрим неправильную реализацию и выясним, что в ней не так.

#### **Ошибочная реализация**

a = b;
b = a;
Если вы попытаетесь выполнить обмен значений этим способом, то увидите, что теперь в обеих переменных хранится значение переменной b. Происходит это из-за построчного выполнения кода. Первая операция присваивания сохраняет значение переменной b в переменную a. Затем вторая — новое значение a в b, иными словами, значение b в b. Таким образом, мы полностью теряем содержание контейнера a. В решении необходимо придумать способ, при котором содержимое переменных теряться не будет, а значения переменных поменяются местами.

#### **Что оценивается:**

По окончании работы алгоритма обмена в переменной a должно лежать значение, которое изначально лежало в переменной b, и наоборот.

### Задача 3. Злостные вредители

#### **Что нужно сделать:**

На бамбуковой плантации завелись гусеницы. Они спят днём и едят бамбук ночью. Бамбук генно-модифицированный, растёт только при свете дня, зато очень быстро — по 50 сантиметров ежедневно! Гусеницы съедают 20 сантиметров бамбука каждую ночь. Бамбуковые саженцы при посадке утром имеют высоту один метр.
Напишите программу, которая считает, какой высоты будет бамбук в середине третьего дня. Усложнение — посчитайте это не за несколько подходов, а одной формулой.

#### **Советы и рекомендации:**

• Допускается погрешность в один сантиметр.  
• Все расчёты проводите в сантиметрах.

#### **Что оценивается:**

• Правильность подсчёта высоты бамбука к третьему дню.  
• Допускается, если в решении используется пользовательский ввод для задания значения переменных.

#### **Подсказка:**

Высоту бамбука к середине третьего дня можно посчитать с помощью формулы:

```
beginHeight + (dailyGrowth - nightFade) _ 2 + dailyGrowth / 2;
В ней:
• dailyGrowth — ежедневный рост;
• nightFade — размер съедаемого гусеницами бамбука за одну ночь;
• beginHeight — начальная высота бамбука.
```

### Задача 4 (дополнительная). Повышаем градус сложности\*

#### **Что нужно сделать**

Вернитесь к задаче про обмен местами значений переменных и попробуйте решить её без использования третьей переменной (упс, спойлер, но ничего страшного!). Догадайтесь, в каких случаях новый способ может не работать и какие у него преимущества.

#### **Советы и рекомендации:**

• Используйте только две исходные переменные.  
• Используйте арифметические операции для обмена.

#### **Что оценивается:**

• По окончании работы алгоритма обмена в переменной a должно лежать значение, которое изначально лежало в переменной b, и наоборот.  
• В программе используются только две переменные.

#### **Критерии оценки работы:**

1. Программы запускаются и корректно работают, нет синтаксических ошибок.
2. Имена переменных корректные (отражают суть хранимых данных, соответствуют стилю именования переменных в C++).
3. Создан текстовый интерфейс для всех программ:
   описание программы (приветствие или что она делает);
   при вводе данных;
   при выводе данных.
4. Выполнено три или более задач.

### Как отправить работу на проверку

В форме ниже прикрепите ссылки на ваши проекты в repl.it — по одной на каждую задачу.
