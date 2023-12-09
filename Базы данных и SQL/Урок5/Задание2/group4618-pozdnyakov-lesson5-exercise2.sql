-- ----------------------------------------------------------------------------
-- Получите список сообщений, отсортированных по возрастанию даты отправки.
-- Вычислите разность между соседними значениями дат отправки.
-- Разности выразите в минутах.
-- Выведите идентификатор сообщения, дату отправки, дату отправки
-- следующего сообщения и разницу даты отправки соседних сообщений.
-- ----------------------------------------------------------------------------
-- Вы работаете с MySQL
-- Введите свой код ниже
SELECT id,
created_at,
LEAD(created_at, 1, 'None') OVER(ORDER BY created_at) AS lead_time, 
IF(LEAD(created_at, 1, 'None') OVER(ORDER BY created_at) = 'None', 'None',
   TIMESTAMPDIFF(MINUTE, created_at, (LEAD(created_at, 1, 'None') OVER(ORDER BY created_at)))) AS minute_lead_diff
FROM messages
ORDER BY created_at;


-- Решение
SELECT 
id, 
created_at,
LEAD(created_at) OVER(ORDER BY created_at) AS lead_time,
TIMESTAMPDIFF (MINUTE, created_at, LEAD(created_at) OVER(ORDER BY created_at)) AS minute_lead_diff
FROM messages;

