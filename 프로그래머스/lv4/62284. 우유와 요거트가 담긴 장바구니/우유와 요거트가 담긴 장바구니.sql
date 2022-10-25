-- 코드를 입력하세요
SELECT
    Y.CART_ID
FROM
    (SELECT DISTINCT
        CART_ID
    FROM
        CART_PRODUCTS
    WHERE
        NAME = "Yogurt") Y
    INNER JOIN
    (SELECT DISTINCT
        CART_ID
    FROM
        CART_PRODUCTS
    WHERE
        NAME = "Milk") M
ON
    Y.CART_ID = M.CART_ID
ORDER BY
    Y.CART_ID