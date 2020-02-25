SELECT c.class
FROM (
  SELECT cc.class, COUNT(cc.class) AS count
  FROM (
    SELECT student, class
    FROM courses
    GROUP BY student, class
  ) cc
  GROUP BY cc.class
) c
WHERE c.count >= 5;
