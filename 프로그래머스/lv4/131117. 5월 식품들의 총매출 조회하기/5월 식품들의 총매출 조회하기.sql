-- 코드를 입력하세요
SELECT
    P.PRODUCT_ID,
    P.PRODUCT_NAME,
    (P.PRICE * O.AMOUNT) AS TOTAL_SALES
FROM
    FOOD_PRODUCT P
    INNER JOIN (
        SELECT
            PRODUCT_ID,
            SUM(AMOUNT) AS AMOUNT
        FROM
            FOOD_ORDER
        WHERE
            PRODUCE_DATE LIKE "2022-05%"
        GROUP BY
            PRODUCT_ID
        ORDER BY
            PRODUCT_ID) O
ON P.PRODUCT_ID = O.PRODUCT_ID
ORDER BY
    TOTAL_SALES DESC,
    PRODUCT_ID
    
    