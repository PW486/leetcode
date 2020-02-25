SELECT
  t.request_at AS "Day",
  ROUND(AVG(CASE t.status WHEN 'completed' THEN 0 ELSE 1 END), 2) AS "Cancellation Rate"
FROM trips t
  LEFT JOIN users c ON t.client_id = c.users_id
  LEFT JOIN users d ON t.driver_id = d.users_id
WHERE c.banned = 'No'
  AND d.banned = 'No'
  AND t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;
