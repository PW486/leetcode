SELECT
  d.id,
  MAX(CASE d.month WHEN "Jan" THEN d.revenue END) AS Jan_Revenue,
  MAX(CASE d.month WHEN "Feb" THEN d.revenue END) AS Feb_Revenue,
  MAX(CASE d.month WHEN "Mar" THEN d.revenue END) AS Mar_Revenue,
  MAX(CASE d.month WHEN "Apr" THEN d.revenue END) AS Apr_Revenue,
  MAX(CASE d.month WHEN "May" THEN d.revenue END) AS May_Revenue,
  MAX(CASE d.month WHEN "Jun" THEN d.revenue END) AS Jun_Revenue,
  MAX(CASE d.month WHEN "Jul" THEN d.revenue END) AS Jul_Revenue,
  MAX(CASE d.month WHEN "Aug" THEN d.revenue END) AS Aug_Revenue,
  MAX(CASE d.month WHEN "Sep" THEN d.revenue END) AS Sep_Revenue,
  MAX(CASE d.month WHEN "Oct" THEN d.revenue END) AS Oct_Revenue,
  MAX(CASE d.month WHEN "Nov" THEN d.revenue END) AS Nov_Revenue,
  MAX(CASE d.month WHEN "Dec" THEN d.revenue END) AS Dec_Revenue
FROM department d
GROUP BY d.id;
