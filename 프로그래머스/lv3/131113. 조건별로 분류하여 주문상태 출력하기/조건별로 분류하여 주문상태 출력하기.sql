-- 코드를 입력하세요
SELECT
    F.ORDER_ID,
    F.PRODUCT_ID,
    DATE_FORMAT(F.OUT_DATE, "%Y-%m-%d") OUT_DATE,
    CASE
        WHEN (F.OUT_DATE IS NULL) THEN "출고미정"
        WHEN (OUT_DATE <= "2022-05-01") THEN "출고완료"
        ELSE "출고대기"
    END AS 출고여부
FROM
    FOOD_ORDER F
ORDER BY
    ORDER_ID;