SELECT
  (
    SELECT
      DISTINCT e.salary
    FROM
      employee e
    ORDER BY
      e.salary DESC
    LIMIT
      1 OFFSET 1
  ) AS "SecondHighestSalary"
