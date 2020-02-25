UPDATE salary
SET salary.sex = CASE WHEN salary.sex = 'm' THEN 'f' ELSE 'm' END;
