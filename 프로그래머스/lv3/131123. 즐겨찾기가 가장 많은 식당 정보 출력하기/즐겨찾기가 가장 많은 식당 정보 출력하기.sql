-- 코드를 입력하세요
SELECT
    R.FOOD_TYPE,
    R.REST_ID,
    R.REST_NAME,
    R.FAVORITES
FROM
    REST_INFO R
    INNER JOIN (
        SELECT
            FOOD_TYPE,
            MAX(FAVORITES) MAX_FAV
        FROM
            REST_INFO
        GROUP BY
            FOOD_TYPE) M
    ON
        M.FOOD_TYPE = R.FOOD_TYPE AND
        M.MAX_FAV = R.FAVORITES
ORDER BY
    FOOD_TYPE DESC