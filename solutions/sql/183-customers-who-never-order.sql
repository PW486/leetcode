SELECT
  c.NAME AS Customers
FROM
  customers c
  LEFT JOIN orders o ON o.customerid = c.id
WHERE
  o.customerid IS NULL;
