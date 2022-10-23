-- 코드를 입력하세요
# SELECT DATE_FORMAT(O.SALES_DATE, "%Y") AS YEAR, DATE_FORMAT(O.SALES_DATE, "%c") AS MONTH, GENDER
select YEAR(sales_date) YEAR, MONTH(sales_date) MONTH, GENDER, count(distinct o.user_id)
FROM ONLINE_SALE O
join USER_INFO U
ON O.USER_ID = U.USER_ID
WHERE U.GENDER IS NOT NULL
group by YEAR, MONTH, gender
order by YEAR, MONTH, gender;