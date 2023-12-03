-- ----------------------------------------------------------------------------
-- Кто не отправлял сообщения
-- Выбрать пользователей из таблицы users,
-- которые не отправили ни одного сообщения
-- (не имеют записей в таблице 'messages').
-- ----------------------------------------------------------------------------
-- Вы работаете с MySQL
-- Введите свой код ниже
SELECT id, CONCAT(firstname,' ', lastname) AS user 
FROM users
WHERE NOT EXISTS (SELECT id FROM messages WHERE messages.from_user_id = users.id);


-- Решение
-- SELECT
--  u.id, 
--  CONCAT(u.firstname, ' ', u.lastname) AS "user"
-- FROM users u
-- LEFT JOIN messages m ON u.id = m.from_user_id
-- WHERE m.id IS NULL;
