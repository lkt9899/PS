-- 코드를 입력하세요
SELECT ANIMAL_TYPE, COUNT(*)
FROM ANIMAL_INS
WHERE ANIMAL_TYPE = "DOG" OR ANIMAL_TYPE = "CAT"
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE;