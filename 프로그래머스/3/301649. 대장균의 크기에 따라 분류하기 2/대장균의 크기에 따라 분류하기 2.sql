SELECT ID, 
    CASE 
        WHEN percent_rank() OVER (ORDER BY size_of_colony DESC) <= 0.25 THEN 'CRITICAL'
        WHEN percent_rank() OVER (ORDER BY size_of_colony DESC) <= 0.50 THEN 'HIGH'
        WHEN percent_rank() OVER (ORDER BY size_of_colony DESC) <= 0.75 THEN 'MEDIUM'
        ELSE 'LOW'
    END AS COLONY_NAME
FROM ECOLI_DATA
ORDER BY id;
