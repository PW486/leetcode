DELETE FROM Person
WHERE Id NOT IN (
  SELECT * FROM (
    SELECT min(p.id)
    FROM Person p
    GROUP BY p.email
  ) as pp
);