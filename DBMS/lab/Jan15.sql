-- To login as admin run at terminal
mysql -u root -p 
;

-- Create a new database
CREATE DATABASE IF NOT EXISTS my_database;

-- Use the newly created database
USE my_database;

-- Create a new table called 'users' with columns: id, name, email, and password
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL
)
insert into users (id, name, email) values (
    (1, 'John Doe', 'johndoe@example.com'),
    (2, 'Jane Doe', 'janedoe@example.com'),
    (3, 'Alice Doe', 'alice@example.com'),
    (4, 'Bob Doe', 'bob@example.com'),
    (5, 'Charlie Doe', 'charlie@example.com'));

-- to create an usr
CREATE USER 'Ar'@'localhost' IDENTIFIED BY 'Ar12345';
CREATE USER 'Br'@'localhost' IDENTIFIED BY 'Br12345';
CREATE USER 'Cr'@'localhost' IDENTIFIED BY 'Cr12345';

-- 2. Grant Privileges to Roles
GRANT ALL PRIVILEGES ON *.* TO 'Ar'@'localhost';


-- 3. Grant Permissions

 Grant SELECT privileges to 'Br'@'localhost' on 'users' table;
 Grant SELECT privileges to 'Cr'@'localhost' on 'users' table;


-- to login run on bash
mysql -u <username> -p

to show grants
SHOW GRANTS FOR '<username>'@'localhost';

