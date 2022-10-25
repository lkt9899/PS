-- 코드를 입력하세요
SELECT
    CATEGORY,
    PRICE MAX_PRICE,
    PRODUCT_NAME
FROM
    FOOD_PRODUCT
WHERE
    PRICE IN (
        SELECT
            MAX(PRICE)
        FROM (
            SELECT
                CATEGORY,
                PRICE,
                PRODUCT_NAME
            FROM
                FOOD_PRODUCT) F
        GROUP BY
            CATEGORY) AND
    CATEGORY IN ("과자", "김치", "국", "식용유")
ORDER BY
    MAX_PRICE DESC
# SELECT
#     CATEGORY,
#     PRICE,
#     PRODUCT_NAME
# FROM 
#     FOOD_PRODUCT
# WHERE
#     CATEGORY IN ("과자", "국", "김치", "식용유")
# ORDER BY CATEGORY, PRICE DESC