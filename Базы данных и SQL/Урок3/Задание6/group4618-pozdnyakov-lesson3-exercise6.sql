-- ----------------------------------------------------------------------------
-- Количество специальностей
-- Определить количество уникальных специальностей (должностей)
-- среди сотрудников в таблице 'staff'.
-- *В данном контексте, уникальная специальность означает,
-- что каждая специальность (должность) встречается только один раз
-- среди сотрудников в таблице staff.
-- То есть, если у нескольких сотрудников одинаковая специальность,
-- она всё равно считается уникальной, поскольку она представлена
-- в таблице только один раз.
-- ----------------------------------------------------------------------------
-- Вы работаете с MySQL
-- Введите свой код ниже

SELECT COUNT(DISTINCT post) AS 'Количество специальностей'
FROM staff;
