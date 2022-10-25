-- 코드를 입력하세요
SELECT
    L.ID,
    L.NAME,
    L.HOST_ID
FROM
    PLACES L
    JOIN (
        SELECT
            HOST_ID,
            COUNT(*) CNT
        FROM
            PLACES
        GROUP BY
            HOST_ID) R
    ON
        L.HOST_ID = R.HOST_ID
WHERE
    R.CNT > 1
ORDER BY
    L.ID