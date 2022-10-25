-- 코드를 입력하세요
SELECT
    I.REST_ID,
    I.REST_NAME,
    I.FOOD_TYPE,
    I.FAVORITES,
    I.ADDRESS,
    R.SCORE
FROM
    REST_INFO I
    INNER JOIN (
        SELECT
            REST_ID,
            ROUND(AVG(REVIEW_SCORE), 2) SCORE
        FROM
            REST_REVIEW
        GROUP BY
            REST_ID) R
    ON
        I.REST_ID = R.REST_ID
WHERE
    ADDRESS LIKE "서울%"
ORDER BY
    SCORE DESC, FAVORITES DESC
# SELECT
#     ri.rest_id
#     , ri.rest_name
#     , ri.food_type
#     , ri.favorites
#     , ri.address
#     , ROUND(AVG(rr.review_score), 2) AS score
# FROM
#     rest_info AS ri
# LEFT JOIN
#     rest_review AS rr
# ON
#     ri.rest_id = rr.rest_id
# WHERE
#     ri.address LIKE '서울%'
#     AND rr.rest_id IS NOT NULL
# GROUP BY
#     ri.rest_id
# ORDER BY
#     score DESC
#     , ri.favorites DESC
# ;