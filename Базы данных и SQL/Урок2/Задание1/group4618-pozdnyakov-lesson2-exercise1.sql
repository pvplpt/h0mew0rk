-- При написании запросов указывайте не только имя таблицы, но и схему.
-- Название вашей схемы - itresume76171
-- Например, itresume76171.tablename

-- Вы работаете с PostgreSQL
-- Введите свой код ниже

CREATE TABLE IF NOT EXISTS itresume76171.sales (
  id SERIAL PRIMARY KEY,
  order_date date,
  count_product int
);

INSERT INTO itresume76171.sales (order_date, count_product)
VALUES ('2022-01-01', 156),
       ('2022-01-02', 180),
       ('2022-01-03', 21),
       ('2022-01-04', 124),
       ('2022-01-05', 341)
;

SELECT * 
FROM itresume76171.sales;
