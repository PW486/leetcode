select
  d.id,
  max(case d.month when "Jan" then d.revenue end) as Jan_Revenue,
  max(case d.month when "Feb" then d.revenue end) as Feb_Revenue,
  max(case d.month when "Mar" then d.revenue end) as Mar_Revenue,
  max(case d.month when "Apr" then d.revenue end) as Apr_Revenue,
  max(case d.month when "May" then d.revenue end) as May_Revenue,
  max(case d.month when "Jun" then d.revenue end) as Jun_Revenue,
  max(case d.month when "Jul" then d.revenue end) as Jul_Revenue,
  max(case d.month when "Aug" then d.revenue end) as Aug_Revenue,
  max(case d.month when "Sep" then d.revenue end) as Sep_Revenue,
  max(case d.month when "Oct" then d.revenue end) as Oct_Revenue,
  max(case d.month when "Nov" then d.revenue end) as Nov_Revenue,
  max(case d.month when "Dec" then d.revenue end) as Dec_Revenue
from department d
group by d.id;
