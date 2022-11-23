-- 코드를 입력하세요
# SET @IC = (
#     SELECT
#         COUNT(USER_ID)
#     FROM
#         USER_INFO
#     WHERE
#         JOINED LIKE "2021%");

# SELECT 
#     YEAR,
#     MONTH,
#     COUNT(*) PURCHASED_USERS,
#     ROUND(COUNT(*) / @IC, 1) PURCHASED_RATIO
# FROM (
#     SELECT DISTINCT
#         YEAR(S.SALES_DATE) AS YEAR,
#         MONTH(S.SALES_DATE) AS MONTH,
#         U.USER_ID
#     FROM
#         ONLINE_SALE S
#     INNER JOIN
#         USER_INFO U
#     ON
#         S.USER_ID = U.USER_ID AND
#         YEAR(JOINED) = 2021) J
# GROUP BY YEAR, MONTH
# ORDER BY YEAR, MONTH;

SELECT
    YEAR(S.SALES_DATE) YEAR,
    MONTH(S.SALES_DATE) MONTH,
    COUNT(DISTINCT S.USER_iD) PURCHASED_USERS,
    ROUND(
        COUNT(DISTINCT S.USER_ID) / (
            SELECT 
                COUNT(*)
            FROM
                USER_INFO
            WHERE
                JOINED LIKE "2021%"), 1) PURCHASED_RATIO
FROM
    ONLINE_SALE S
    JOIN (
        SELECT
            USER_ID
        FROM
            USER_INFO
        WHERE
            JOINED LIKE "2021%") U
    ON S.USER_ID = U.USER_ID
GROUP BY
    YEAR, MONTH
ORDER BY 
    YEAR, MONTH;