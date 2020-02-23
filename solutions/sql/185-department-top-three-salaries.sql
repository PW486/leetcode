select
  de.name as Department,
  em.name as Employee,
  em.salary
from
  employee em
  inner join department de on de.id = em.departmentid
  inner join (
    select
      departmentid,
      ifnull(
        ifnull(
          (
            select
              ee.salary
            from
              employee ee
            where
              e.departmentid = ee.departmentid
            group by
              ee.salary
            order by
              ee.salary desc
            limit
              2, 1
          ), (
            select
              ee.salary
            from
              employee ee
            where
              e.departmentid = ee.departmentid
            group by
              ee.salary
            order by
              ee.salary desc
            limit
              1, 1
          )
        ), max(salary)
      ) as threeSalary
    from
      employee e
    group by
      departmentid
  ) threeble on threeble.departmentid = em.departmentid
where
  threeble.threeSalary <= em.salary
