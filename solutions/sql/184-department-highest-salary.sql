SELECT
  d.name AS Department,
  e.name AS Employee,
  e.salary
FROM
  employee e
  LEFT JOIN department d ON d.id = e.departmentid
  LEFT JOIN (
    SELECT
      departmentid,
      MAX(salary) AS max
    FROM
      employee
    GROUP BY
      departmentid
  ) mx ON mx.departmentid = e.departmentid
WHERE mx.max = e.salary
  AND d.name IS NOT NULL;
