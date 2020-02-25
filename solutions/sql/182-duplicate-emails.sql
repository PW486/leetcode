SELECT
  Person.email
FROM (
  SELECT
    p.email,
    COUNT(p.email) AS count
  FROM
    person p
  GROUP BY
    p.email
) person
WHERE
  person.count > 1;
