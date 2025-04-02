SHOW DATABASES;
CREATE DATABASE TEST;
USE TEST;

CREATE USER 'Admin'@'localhost' IDENTIFIED BY 'Admin@123';
GRANT ALL PRIVILEGES ON TEST.* TO 'Admin'@'localhost';

CREATE USER 'Moderator'@'localhost' IDENTIFIED BY 'Moderator@123';
GRANT INSERT, UPDATE, DELETE ON test.* TO 'Moderator'@'localhost';

CREATE USER 'User'@'localhost' IDENTIFIED BY 'User@123';
GRANT SELECT ON test.* TO 'User'@'localhost';
FLUSH PRIVILEGES;



CREATE TABLE Branch
(
        branchNo INT PRIMARY KEY,
        street VARCHAR(50),
        city VARCHAR(50),
        postcode VARCHAR(50)
)

ALTER Table Branch MODIFY branchNo VARCHAR(50);

INSERT INTO Branch (branchNo,street,city,postcode) VALUES
    (),(_),();




