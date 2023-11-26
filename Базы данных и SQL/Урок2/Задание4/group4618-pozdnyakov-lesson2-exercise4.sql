-- Вы работаете с MySQL
-- Введите свой код ниже

SELECT *,
CASE order_status
  WHEN "OPEN" THEN "Order is in open state"
  WHEN "CLOSED" THEN "Order is closed"
  WHEN "CANCELLED" THEN "Order is cancelled"
  ELSE "Not mentioned"
END AS "full_order_status"
FROM orders;