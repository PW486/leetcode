SELECT s1.id, IFNULL(s2.student, s1.student) AS student
FROM seat s1
  LEFT JOIN seat s2 ON
    CASE WHEN s2.id % 2 = 1 THEN s2.id = s1.id-1 ELSE s2.id = s1.id+1 END
ORDER BY s1.id;
