
CREATE DATABASE LearnSQL;
USE LearnSQL;

CREATE TABLE groceries (
    id INTEGER PRIMARY KEY,
    name VARCHAR(50),
    quantity INTEGER
);

INSERT INTO `groceries` VALUES
(1, 'Banana', 4),
(2, 'Peanut Butter', 1),
(3, 'Dark chocolate', 2);

SELECT * FROM groceries;

DROP DATABASE LearnSQL;
