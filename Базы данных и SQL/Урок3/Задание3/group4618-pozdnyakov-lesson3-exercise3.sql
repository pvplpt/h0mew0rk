-- ----------------------------------------------------------------------------
-- Максимальная заработная плата
-- Выбрать пять самых высокооплачиваемых сотрудников из таблицы staff и
-- вывести их зарплаты в убывающем порядке (начиная с самой высокой зарплаты).
-- ----------------------------------------------------------------------------
-- Вы работаете с MySQL
-- Введите свой код ниже
SELECT salary
FROM staff
ORDER BY salary DESC
LIMIT 5;


