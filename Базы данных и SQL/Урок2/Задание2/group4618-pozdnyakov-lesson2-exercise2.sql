-- Вы работаете с MySQL
-- Введите свой код ниже

SELECT id AS 'Номер заказа', count_product AS 'Количество продукта',
CASE
WHEN count_product < 100 THEN 'Маленький заказ'
WHEN count_product < 300 THEN 'Средний заказ'
ELSE 'Большой заказ'
END AS 'Тип'
FROM sales;

