
CREATE DATABASE LearnSQL;
USE LearnSQL;
-- START HERE

CREATE TABLE Bike (
    id INTEGER PRIMARY KEY,
    name TEXT,
    price INTEGER
);

INSERT INTO Bike VALUES
(1, 'Bike1', 10),
(2, 'Bike2', 20),
(3, 'Bike3', 30),
(4, 'Bike4', 10),
(5, 'Bike5', 20),
(6, 'Bike6', 30),
(7, 'Bike7', 10),
(8, 'Bike8', 20),
(9, 'Bike9', 30),
(10, 'Bike10', 10),
(11, 'Bike11', 20),
(12, 'Bike12', 30),
(13, 'Bike13', 10),
(14, 'Bike14', 20),
(15, 'Bike15', 30);

SELECT * from Bike ORDER BY price;

SELECT count(*) as "price < 10" from Bike where price <= 10;
SELECT count(*) as "10 < price <= 20"from Bike where price > 10 and price <= 20;
SELECT count(*) as "20 < price <= 30" from Bike where price > 20 and price <= 30;

-- DROPPING the database after experiment.
DROP DATABASE LearnSQL;

