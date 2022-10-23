-- 코드를 입력하세요
# SELECT R.MEMBER_ID, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, "%Y-%m-%d")
# FROM REST_REVIEW R
# RIGHT JOIN
# (SELECT MEMBER_ID, COUNT(*) CNT
# FROM REST_REVIEW
# GROUP BY MEMBER_ID
# HAVING CNT = (SELECT MAX(C) FROM (SELECT COUNT(*) C
# FROM REST_REVIEW
# GROUP BY MEMBER_ID) A)) MAX_ID
# ON R.MEMBER_ID = MAX_ID.MEMBER_ID
SELECT MID.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, "%Y-%m-%d") DATE
FROM REST_REVIEW R
RIGHT JOIN
(SELECT M.MEMBER_NAME, MAX_ID.MEMBER_ID
FROM MEMBER_PROFILE M
RIGHT JOIN (SELECT MEMBER_ID, COUNT(*) CNT
FROM REST_REVIEW
GROUP BY MEMBER_ID
HAVING CNT = (SELECT MAX(C) FROM (SELECT COUNT(*) C
FROM REST_REVIEW
GROUP BY MEMBER_ID) A)) MAX_ID
ON M.MEMBER_ID = MAX_ID.MEMBER_ID) MID
ON R.MEMBER_ID = MID.MEMBER_ID
ORDER BY DATE, R.REVIEW_TEXT

