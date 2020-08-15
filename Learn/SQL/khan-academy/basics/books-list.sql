
CREATE DATABASE LearnSQL;
USE LearnSQL;
-- START HERE

CREATE TABLE Books (
    id INTEGER PRIMARY KEY,
    name VARCHAR(255),
    rating FLOAT DEFAULT 0.0
);

INSERT INTO Books VALUES
(1, 'Cracking the coding interview', 4.5),
(2, 'Designing data intensive applications', 4.8),
(3, 'The art of not giving a fuck.', 4.5);

SELECT * from Books ORDER BY rating DESC, name DESC;

-- DROPPING the database after experiment.
DROP DATABASE LearnSQL;

