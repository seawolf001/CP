
CREATE DATABASE LearnSQL;
USE LearnSQL;
-- START HERE

CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    first_name TEXT,
    last_name TEXT,
    email TEXT,
    phone TEXT,
    birthdate TEXT);

INSERT INTO students (first_name, last_name, email, phone, birthdate)
    VALUES ("Peter", "Rabbit", "peter@rabbit.com", "555-6666", "2002-06-24");
INSERT INTO students (first_name, last_name, email, phone, birthdate)
    VALUES ("Alice", "Wonderland", "alice@wonderland.com", "555-4444", "2002-07-04");

CREATE TABLE student_grades (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    student_id INTEGER,
    test TEXT,
    grade INTEGER);

INSERT INTO student_grades (student_id, test, grade)
    VALUES (1, "Nutrition", 95);
INSERT INTO student_grades (student_id, test, grade)
    VALUES (2, "Nutrition", 92);
INSERT INTO student_grades (student_id, test, grade)
    VALUES (1, "Chemistry", 85);
INSERT INTO student_grades (student_id, test, grade)
    VALUES (2, "Chemistry", 95);

CREATE TABLE student_projects (
    id INTEGER PRIMARY KEY AUTO_INCREMENT,
    student_id INTEGER DEFAULT NULL,
    title TEXT);

INSERT INTO student_projects (student_id, title)
    VALUES (1, "Carrotapault");

INSERT INTO student_projects (title) VALUES ('NASA Moon Project.');


/* INNER JOIN: Retains only matching rows based on condition.*/
SELECT students.first_name, students.last_name, student_projects.title
    FROM students
    INNER JOIN student_projects
    ON students.id = student_projects.student_id;

/* LEFT outer join: Retain the columns from LEFT even if it does not match any row in RIGHT*/
SELECT students.first_name, students.last_name, student_projects.title
    FROM students
    LEFT OUTER JOIN student_projects
    ON students.id = student_projects.student_id;

/* RIGHT OUTER JOIN: Retain the columns from RIGHT even if it does not match any row in LEFT*/
SELECT students.first_name, students.last_name, student_projects.title
    FROM students
    RIGHT OUTER JOIN student_projects
    ON students.id = student_projects.student_id;

/* FULL OUTER JOIN: Combination of LEFT OUTER JOIN and RIGHT OUTER JOIN */
/* MYSQL does not support FULL OUTER JOIN, This same can be achieved by UNION of LEFT and RIGHT joins*/
/* FOR more than 2 tables, this can be a bit complex than for 2 tables.*/

SELECT students.first_name, students.last_name, student_projects.title
    FROM students
    LEFT OUTER JOIN student_projects
    ON students.id = student_projects.student_id
UNION
SELECT students.first_name, students.last_name, student_projects.title
    FROM students
    RIGHT OUTER JOIN student_projects
    ON students.id = student_projects.student_id;

-- DROPPING the database after experiment.
DROP DATABASE LearnSQL;
