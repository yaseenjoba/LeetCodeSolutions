# Write your MySQL query statement below
SELECT name as Customers  FROM CUSTOMERS WHERE CUSTOMERS.ID NOT IN (SELECT CustomerId  FROM ORDERS); 