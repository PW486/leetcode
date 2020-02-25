SELECT *
FROM stadium s1
WHERE s1.people >= 100 AND
((
  (SELECT s2.id FROM stadium s2 WHERE s2.id = s1.id + 1 AND s2.people >= 100) IS NOT NULL
  AND
  (SELECT s3.id FROM stadium s3 WHERE s3.id = s1.id + 2 AND s3.people >= 100) IS NOT NULL
) OR (
  (SELECT s2.id FROM stadium s2 WHERE s2.id = s1.id - 1 AND s2.people >= 100) IS NOT NULL
  AND
  (SELECT s3.id FROM stadium s3 WHERE s3.id = s1.id + 1 AND s3.people >= 100) IS NOT NULL
) OR (
  (SELECT s2.id FROM stadium s2 WHERE s2.id = s1.id - 2 AND s2.people >= 100) IS NOT NULL
  AND
  (SELECT s3.id FROM stadium s3 WHERE s3.id = s1.id - 1 AND s3.people >= 100) IS NOT NULL
));
