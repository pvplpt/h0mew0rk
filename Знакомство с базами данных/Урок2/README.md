## Урок 2. Работа с данными из разных таблиц

### **Чему будет равна выборка:**
```
    SELECT ФИО, Д/р, Адрес FROM Общий список
    SELECT ФИО, Статус FROM Общий список WHERE Адрес = «Можга»
    SELECT ФИО FROM Общий список WHERE Адрес = «Москва» AND Группа = «Работа»
    SELECT Д/р FROM Общий список WHERE Адрес = «Москва» OR Группа = «Работа»
```
### **Что будет результатом следующих JOIN’ов:**
```
    INNER JOIN Люди, Адреса ON id = Чей адрес
    LEFT JOIN Люди, Адреса ON id = Чей адрес
    RIGHT JOIN Люди, Адреса ON id = Чей адрес
    FULL JOIN Люди, Адреса ON id = Чей адрес
```
### **Дополнительное задание. Что будет результатом выборки:**
```
SELECT ФИО, Адрес, Комментарий FROM Люди RIGHT JOIN Адреса ON id = Чей
Адрес
```
> После загрузки задания, вы можете проверить себя самостоятельно с помощью [эталонного решения](https://gbcdn.mrgcdn.ru/uploads/asset/4961464/attachment/e265f556785e16a3f134ca528c8a91ef.xlsx)


[Домашная работа](https://docs.google.com/spreadsheets/d/1Dxm4q1kmlNZSje7pnOPXEfrYbu9vic7owgnDaUB66Io/edit?usp=sharing)