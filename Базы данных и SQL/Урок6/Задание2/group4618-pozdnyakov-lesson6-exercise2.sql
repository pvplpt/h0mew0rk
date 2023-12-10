DROP FUNCTION IF EXISTS even_num;

DELIMITER $$
CREATE FUNCTION even_num()
RETURNS TEXT
DETERMINISTIC
BEGIN
    DECLARE result_str TEXT DEFAULT 2;
    DECLARE i INT DEFAULT 2;

    WHILE i < 10 DO
        SET i = i + 2;
        SET result_str = CONCAT(result_str, ", ", i);
    END WHILE;

    RETURN result_str;

END$$
DELIMITER ;

SELECT even_num() AS 'Четные числа';
