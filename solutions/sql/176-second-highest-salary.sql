SELECT (
  SELECT DISTINCT e.salary
  FROM employee e
  ORDER BY e.salary DESC
  LIMIT 1, 1
) AS "SecondHighestSalary";
