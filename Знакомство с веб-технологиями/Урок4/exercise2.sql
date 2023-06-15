-- create
CREATE TABLE classmates (
  id INTEGER PRIMARY KEY,
  name TEXT NOT NULL,
  age INTEGER NOT NULL,
  address TEXT NOT NULL
);

-- insert
INSERT INTO classmates VALUES (1, 'Маша', 25, 'Тут');
INSERT INTO classmates VALUES (2, 'Саша', 18, 'Там');
INSERT INTO classmates VALUES (3, 'Паша', 20, 'Здесь');
INSERT INTO classmates VALUES (4, 'Даша', 40, 'Рядом');

-- select
SELECT * FROM classmates;