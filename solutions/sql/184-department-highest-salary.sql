select
  d.name as Department,
  e.name as Employee,
  e.salary
from
  employee e
  left join department d on d.id = e.departmentid
  left join (
    select
      departmentid,
      max(salary) as max
    from
      employee
    group by
      departmentid
  ) mx on mx.departmentid = e.departmentid
where
  mx.max = e.salary
  and d.name is not null;
