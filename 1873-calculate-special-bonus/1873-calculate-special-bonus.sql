# Write your MySQL query statement below
SELECT employee_id , IF((LOWER(NAME) NOT LIKE 'M%' AND ((employee_id % 2) != 0)) , SALARY , 0) AS bonus FROM EMPLOYEES 
ORDER BY employee_id;