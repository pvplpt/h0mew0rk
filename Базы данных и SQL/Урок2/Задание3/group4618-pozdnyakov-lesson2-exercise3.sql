-- При написании запросов указывайте не только имя таблицы, но и схему.
-- Название вашей схемы - itresume76171
-- Например, itresume76171.tablename

-- Вы работаете с PostgreSQL
-- Введите свой код ниже

CREATE TABLE IF NOT EXISTS itresume76171.orders (
  employee_id TEXT,
  amount TEXT,
  order_status TEXT
);

INSERT INTO itresume76171.orders (employee_id, amount, order_status)
VALUES ('e03', '15.00', 'OPEN'),
       ('e01', '25.50', 'OPEN'),
       ('e05', '100.70', 'CLOSED'),
       ('e02', '22.18', 'OPEN'),
       ('e04', '9.50', 'CANCELLED')
;

SELECT * 
FROM itresume76171.orders;
