
-- При написании запросов указывайте не только имя таблицы, но и схему.
-- Название вашей схемы - itresume76171
-- Например, itresume76171.tablename

-- Вы работаете с PostgreSQL
-- Введите свой код ниже

CREATE TABLE IF NOT EXISTS itresume76171.mobile_phones (product_name VARCHAR(45) NOT NULL , manufacturer VARCHAR(45) NOT NULL , product_count INT NOT NULL , price INT NOT NULL );

INSERT INTO itresume76171.mobile_phones (product_name, manufacturer, product_count, price) 
VALUES ('iPhone X', ' Apple', '3', '76000'),
('iPhone 8', 'Apple', 2, 51000),
('Galaxy S9', 'Samsung', 2, 56000),
('Galaxy S8', 'Samsung', 1, 41000),
('P20 Pro', 'Huawei', 5, 36000);

SELECT *
FROM itresume76171.mobile_phones;