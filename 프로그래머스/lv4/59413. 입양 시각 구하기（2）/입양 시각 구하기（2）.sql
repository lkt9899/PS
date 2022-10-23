-- 코드를 입력하세요
WITH RECURSIVE TIME AS(
    SELECT 0 AS HOUR
    UNION ALL
    SELECT HOUR + 1 FROM TIME WHERE HOUR < 23)
    
SELECT TIME.HOUR AS HOUR, COUNT(A.DATETIME) AS COUNT
FROM TIME
LEFT JOIN ANIMAL_OUTS A
ON TIME.HOUR = HOUR(A.DATETIME)
GROUP BY HOUR;