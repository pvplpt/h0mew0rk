DROP FUNCTION IF EXISTS num_of_day;

DELIMITER $$
CREATE FUNCTION num_of_day(number BIGINT)
RETURNS TEXT
DETERMINISTIC
BEGIN
    DECLARE num_days BIGINT DEFAULT 0;
	DECLARE num_hours BIGINT DEFAULT 0;
	DECLARE num_minutes BIGINT DEFAULT 0;
	DECLARE num_seconds BIGINT DEFAULT 0;
    DECLARE result_str TEXT DEFAULT "";

	-- 1 minute = 60 sec
	-- 1 hour = 60 minutes = 60*60 = 3600 sec
	-- 1 day = 24 hours = 24*3600 = 86400 sec

	SET num_days = number DIV 86400;
	SET number = number % 86400;

	SET num_hours = number DIV 3600;
	SET number = number % 3600; 

	SET num_minutes = number DIV 60;

	SET num_seconds = number % 60;

	-- 1 days 10 hours 17 minutes 36 seconds
    SET result_str = CONCAT(num_days, " days ");
	SET result_str = CONCAT(result_str, num_hours, " hours ");
	SET result_str = CONCAT(result_str, num_minutes, " minutes ");
	SET result_str = CONCAT(result_str, num_seconds, " seconds");

    RETURN result_str;

END$$
DELIMITER ;

