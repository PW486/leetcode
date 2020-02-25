SELECT
  de.name AS Department,
  em.name AS Employee,
  em.salary
FROM
  employee em
  INNER JOIN department de ON de.id = em.departmentid
  INNER JOIN (
    SELECT
      departmentid,
      IFNULL(
        IFNULL(
          (
            SELECT
              ee.salary
            FROM
              employee ee
            WHERE
              e.departmentid = ee.departmentid
            GROUP BY
              ee.salary
            ORDER BY
              ee.salary DESC
            LIMIT
              2, 1
          ), (
            SELECT
              ee.salary
            FROM
              employee ee
            WHERE
              e.departmentid = ee.departmentid
            GROUP BY
              ee.salary
            ORDER BY
              ee.salary DESC
            LIMIT
              1, 1
          )
        ), MAX(salary)
      ) AS threeSalary
    FROM
      employee e
    GROUP BY
      departmentid
  ) threeble ON threeble.departmentid = em.departmentid
WHERE
  threeble.threeSalary <= em.salary
