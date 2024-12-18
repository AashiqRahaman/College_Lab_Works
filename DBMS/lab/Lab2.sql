-- Branch Table
CREATE TABLE Branch (
    branchNo CHAR(4) PRIMARY KEY,
    street VARCHAR(50),
    city VARCHAR(50),
    postcode CHAR(8)
);

INSERT INTO Branch (branchNo, street, city, postcode) VALUES 
('B005', '22 Deer Rd', 'London', 'SW1 4EH'),
('B007', '16 Argyll St', 'Aberdeen', 'AB2 3SU'),
('B003', '163 Main St', 'Glasgow', 'G11 9QX'),
('B004', '32 Manse Rd', 'Bristol', 'BS99 1NZ'),
('B002', '56 Clover Dr', 'London', 'NW10 6EU');

SELECT * FROM Branch;

-- Staff Table
CREATE TABLE Staff (
    staffNo VARCHAR(5) PRIMARY KEY,
    fName VARCHAR(20),
    lName VARCHAR(20),
    position VARCHAR(20),
    sex CHAR(1) CHECK (sex IN ('M', 'F')),
    DOB DATE,
    salary INT,
    branchNo CHAR(4),
    FOREIGN KEY (branchNo) REFERENCES Branch(branchNo)
);


INSERT INTO Staff (staffNo, fName, lName, position, sex, DOB, salary, branchNo) VALUES 
('SL21', 'John', 'White', 'Manager', 'M', '1945-10-01', 30000, 'B005'), 
('SG37', 'Ann', 'Beech', 'Assistant', 'F', '1960-11-10', 12000, 'B003'),
('SG14', 'David', 'Ford', 'Supervisor', 'M', '1958-03-24', 18000, 'B003'), 
('SA9', 'Mary', 'Howe', 'Assistant', 'F', '1970-02-19', 9000, 'B007'),
('SG5', 'Susan', 'Brand', 'Manager', 'F', '1940-06-03', 24000, 'B003'), 
('SL41', 'Julie', 'Lee', 'Assistant', 'F', '1965-06-13', 9000, 'B005');


SELECT * FROM Staff;

-- Registration Table
CREATE TABLE Registration (
    clientNo VARCHAR(5),
    branchNo CHAR(4),
    staffNo VARCHAR(5),
    dateJoined DATE,
    PRIMARY KEY (clientNo, branchNo),
    FOREIGN KEY (clientNo) REFERENCES Client(clientNo),
    FOREIGN KEY (branchNo) REFERENCES Branch(branchNo),
    FOREIGN KEY (staffNo) REFERENCES Staff(staffNo)
);


INSERT INTO Registration (clientNo,branchNo,staffNo,dateJoined) VALUES 
('CR76', 'B005', 'SL41', '2004-01-02'), 
('CR56', 'B003', 'SG37', '2003-04-11'), 
('CR74', 'B003', 'SG37', '2002-11-16'), 
('CR62', 'B007', 'SA9', '2003-03-07');


SELECT * FROM Registration;

-- PropertyForRent Table
CREATE TABLE PropertyForRent (
    propertyNo VARCHAR(5) PRIMARY KEY,
    street VARCHAR(50),
    city VARCHAR(20),
    postcode VARCHAR(10),
    type VARCHAR(10),
    rooms INT,
    rent DECIMAL(6, 2),
    ownerNo VARCHAR(5),
    staffNo VARCHAR(5),
    branchNo CHAR(4),
    FOREIGN KEY (staffNo) REFERENCES Staff(staffNo),
    FOREIGN KEY (branchNo) REFERENCES Branch(branchNo)
);

INSERT INTO PropertyForRent (propertyNo, street, city, postcode, type, rooms, rent, ownerNo, staffNo, branchNo) VALUES
('PA14', '16 Holhead', 'Aberdeen', 'AB7 5SU', 'House', 6, 650, 'CO46', 'SA9', 'B007'),
('PL94', '6 Argyll St', 'London', 'NW2', 'Flat', 3, 400, 'CO87', 'SL41', 'B005'),
('PG4', '6 Lawrence St', 'Glasgow', 'G11 9QX', 'Flat', 3, 350, 'CO40', 'SG37', 'B003'),
('PG36', '2 Manor Rd', 'Glasgow', 'G32 4QX', 'Flat', 3, 375, 'CO40', 'SG37', 'B003'),
('PG21', '18 Dale Rd', 'Glasgow', 'G12', 'House', 5, 600, 'CO87', 'SG37', 'B003'),
('PG16', '5 Novar Dr', 'Glasgow', 'G12 9AX', 'Flat', 4, 450, 'CO93', 'SG14', 'B003');

SELECT * FROM PropertyForRent;


-- Client Table
CREATE TABLE Client (
    clientNo VARCHAR(5) PRIMARY KEY,
    fName VARCHAR(20),
    lName VARCHAR(20),
    telNo VARCHAR(15),
    prefType VARCHAR(10),
    maxRent DECIMAL(6, 2)
);

INSERT INTO Client (clientNo, fName, lName, telNo, prefType, maxRent) VALUES
('CR76', 'John', 'Kay', '0207-774-5632', 'Flat', 425),
('CR56', 'Aline', 'Stewart', '0141-848-1825', 'Flat', 350),
('CR74', 'Mike', 'Ritchie', '01475-392178', 'House', 750),
('CR62', 'Mary', 'Tregear', '01224-196720', 'Flat', 600);

SELECT * FROM Client;

-- PrivateOwner Table
CREATE TABLE PrivateOwner (
    ownerNo VARCHAR(5) PRIMARY KEY,
    fName VARCHAR(20),
    lName VARCHAR(20),
    address VARCHAR(50),
    telNo VARCHAR(15)
);

INSERT INTO PrivateOwner (ownerNo, fName, lName, address, telNo) VALUES
('CO46', 'Joe', 'Keogh', '2 Fergus Dr, Aberdeen AB2 7SX', '01224-861212'),
('CO87', 'Carol', 'Farrel', '6 Achray St, Glasgow G32 9DX', '0141-357-7419'),
('CO40', 'Tina', 'Murphy', '63 Well St, Glasgow G42', '0141-943-1728'),
('CO93', 'Tony', 'Shaw', '12 Park Pl, Glasgow G4 0QR', '0141-225-7025');

SELECT * FROM PrivateOwner;

-- Viewing Table
CREATE TABLE Viewing (
    viewingID INT PRIMARY KEY AUTO_INCREMENT,
    clientNo VARCHAR(5),
    propertyNo VARCHAR(5),
    viewDate DATE,
    comment VARCHAR(50),
    FOREIGN KEY (clientNo) REFERENCES Client(clientNo),
    FOREIGN KEY (propertyNo) REFERENCES PropertyForRent(propertyNo)
);

INSERT INTO Viewing (clientNo, propertyNo, viewDate, comment) VALUES
('CR56', 'PA14', '2004-05-24', 'too small'),
('CR76', 'PG4', '2004-04-20', 'too remote'),
('CR56', 'PG4', '2004-05-26', NULL),
('CR62', 'PA14', '2004-05-14', 'no dining room'),
('CR56', 'PG36', '2004-04-28', NULL);


DROP TABLE viewing;
SELECT * FROM Viewing;

SELECT COUNT(*)
FROM viewing;

show tables;
DESC viewing;



--List full details of all staff.
--1.list full details of Staff

SELECT * FROM staff;

--2.Produce a list of salaries for all staff, showing only the staff number, the first and last names, and the salary details.
SELECT staffNo, FName, LName, salary FROM staff;

--3.Produce a list of monthly salaries for all staff, showing the staff number, the first and last names, and the salary details.
SELECT StaffNo, FName, LName, salary / 12 AS monthly_salary FROM Staff;

--4.List all staff with a salary greater than £10,000.
SELECT * FROM Staff WHERE salary > 10000;

--5.List all staff with a salary between £20,000 and £30,000.
SELECT * FROM Staff WHERE salary BETWEEN 20000 AND 30000;

--6.Produce a list of salaries for all staff, showing only the staff number, name, and salary details.
SELECT StaffNo, CONCAT(fName, ' ', lName) AS Name, salary FROM Staff;

--7.List all managers and supervisors.
SELECT * FROM Staff WHERE position IN ('Manager', 'Supervisor');

--8.List all cities where there is either a branch office or a property for rent.
SELECT DISTINCT city FROM Branch
UNION
SELECT DISTINCT city FROM PropertyForRent;

--9.List all cities where there is a branch office but no properties for rent.
SELECT city FROM Branch
WHERE city NOT IN (SELECT city FROM PropertyForRent);

--10.List all cities where there is both a branch office and at least one property for rent.
SELECT city FROM Branch
WHERE city IN (SELECT city FROM PropertyForRent);



--Day 2
--11,List the names and comments of all clients who have viewed a property for rent.
SELECT Client.fName, Client.lName, Viewing.comment
FROM Viewing
JOIN Client ON Viewing.clientNo = Client.clientNo;

-- --12.Produce a status report on property Viewings.
-- SELECT 
--     V.clientNo, CONCAT(C.fName, ' ', C.lName) AS clientName, 
--     V.propertyNo, P.street, P.city, 
--     V.viewDate, V.comment
-- FROM Viewing V
-- JOIN Client C ON V.clientNo = C.clientNo
-- JOIN PropertyForRent P ON V.propertyNo = P.propertyNo;

--13.List complete details of all staff who work at the branch in Glasgow.
SELECT Staff.* FROM Staff
JOIN Branch ON Staff.branchNo = Branch.branchNo
WHERE Branch.city = 'Glasgow';

--14.Find all owners with the string 'Glasgow' in their address.
SELECT * FROM PrivateOwner WHERE address LIKE '%Glasgow%';

--15,How many properties cost more than £350 per month to rent?
SELECT COUNT(*) FROM PropertyForRent WHERE rent > 350;

#16 Find the minimum, maximum, and average staff salary.
SELECT 
    MIN(salary), 
    MAX(salary), 
    AVG(salary)
FROM Staff;

#17 Find the number of staff working in each branch and the sum of their salaries.
SELECT 
    branchNo, 
    COUNT(*) AS NumberOfStaff, 
    SUM(salary) AS TotalSalary
FROM Staff
GROUP BY branchNo;

#18 List the details of all viewings on property PG4 where a comment has not been supplied.
SELECT * FROM Viewing
WHERE propertyNo = 'PG4' AND comment IS NULL;

#19 Produce a list of salaries for all staff
SELECT CONCAT(fName,' ', lName) AS StaffName, salary 
FROM Staff
ORDER BY salary DESC;

#20 Produce a list of properties arranged in order of property type. 
SELECT * FROM PropertyForRent
ORDER BY type;

#21 How many different properties were viewed in May 2004?
SELECT COUNT(DISTINCT propertyNo) AS Prop_Visited_InMay2004 FROM Viewing
WHERE MONTH(viewDate) = 05 AND YEAR(viewDate) = 2004;

#22 Find the total number of Managers and the sum of their salaries
SELECT 
    COUNT(*) AS TotalManagers, 
    SUM(salary) AS ManagerSalariesSum
FROM Staff
WHERE position = 'Manager';

#23 For each branch office with more than one member of staff, find the number of staff working in each branch and the sum of their salaries.
SELECT 
    branchNo,
    Count(*) AS StaffCount, 
    SUM(salary) AS TotalSalary
FROM Staff
GROUP BY branchNo
HAVING COUNT(*) = 1;

#OTHER SOL
-- SELECT 
--     branchNo,
--     Count(*) AS StaffCount, 
--     SUM(salary) AS TotalSalary
-- FROM Staff
-- WHERE StaffCount > 1
-- GROUP BY branchNo;


#24 List the staff who work in the branch at 163 Main St.
SELECT * FROM Staff
WHERE branchNo IN (SELECT branchNo FROM Branch WHERE street = '163 Main St');

#25 List all staff whose salary is greater than the average salary, and show by how much their salary is greater
SELECT 
    fName, lName, salary, staffNo,
    salary - (SELECT AVG(salary) FROM Staff) AS Extra_Ammount
FROM Staff
WHERE salary > (SELECT AVG(salary) FROM Staff);

-- alternative
-- SELECT 
--     fName, lName, salary, staffNo,
--     salary - AVG(salary) AS Extra_Ammount
--     FROM Staff
-- WHERE salary > AVG(salary);


-


#26 List the properties that are handled by staff who work in the branch at 163 Main St.
SELECT * FROM PropertyForRent
WHERE staffNo IN (SELECT staffNo FROM Staff 
                  WHERE branchNo IN (SELECT branchNo FROM Branch 
                                    WHERE street = '163 Main St')
);

-- alternative 
SELECT 
    PropertyForRent.propertyNo,
    PropertyForRent.street AS PropertyStreet,
    PropertyForRent.city AS PropertyCity,
    PropertyForRent.rent AS Rent
FROM PropertyForRent
JOIN Staff ON PropertyForRent.staffNo = Staff.staffNo
JOIN Branch ON Staff.branchNo = Branch.branchNo
WHERE Branch.street = '163 Main St';

-- Alternative
SELECT *
FROM PropertyForRent
JOIN Branch ON PropertyForRent.branchNo = Branch.branchNo
WHERE Branch.street = '163 Main St';

#27 Find all staff whose salary is larger than the salary of at least one member of staff at branch B003.
SELECT * 
FROM Staff
WHERE salary > (
    SELECT MIN(salary) 
    FROM Staff 
    WHERE branchNo = 'B003'
);

#27(another Way)
SELECT * 
FROM Staff
WHERE salary > ANY (
    SELECT salary 
    FROM Staff 
    WHERE branchNo = 'B003'
);

#28 Find all staff whose salary is larger than the salary of every member of staff at branch B003.
SELECT * 
FROM Staff
WHERE salary > ALL (
    SELECT salary 
    FROM Staff 
    WHERE branchNo = 'B003'
);

#29
#Same as Q.11
SELECT * FROM Staff;

#30,31 For each branch, list the numbers and names of staff who manage properties, including the city in which the branch is located and the properties that the staff manage. 
SELECT 
    Branch.branchNo, Branch.city, Staff.staffNo, CONCAT(Staff.fName, ' ', Staff.lName) AS StaffName, PropertyForRent.propertyNo
FROM Branch
JOIN Staff ON Branch.branchNo = Staff.branchNo
JOIN PropertyForRent ON Staff.staffNo = PropertyForRent.staffNo;


-- Alternative
SELECT 
    Staff.branchNo, CONCAT(Staff.fName, ' ', Staff.lName) AS StaffName, GROUP_CONCAT(DISTINCT PropertyForRent.propertyNo ORDER BY PropertyForRent.propertyNo SEPARATOR ',')
FROM Staff 
JOIN PropertyForRent ON Staff.staffNo = PropertyForRent.staffNo GROUP BY Staff.branchNo,fName,lName ;
-- Alternatively
SELECT 
    GROUP_CONCAT(DISTINCT Staff.branchNo SEPARATOR ','), CONCAT(Staff.fName, ' ', Staff.lName) AS StaffName, GROUP_CONCAT(DISTINCT PropertyForRent.propertyNo ORDER BY PropertyForRent.propertyNo SEPARATOR ',')
FROM Staff 
JOIN PropertyForRent ON Staff.staffNo = PropertyForRent.staffNo GROUP BY fName,lName ;



#32 Find the number of properties handled by each staff member.
SELECT staffNo, COUNT(propertyNo) AS HandledPropNo FROM PropertyForRent
GROUP BY staffNo
HAVING staffNo IS NOT NULL;

#33 List all branch offices and any properties that are in the same city.
SELECT  
    Branch.city,
    GROUP_CONCAT(DISTINCT Branch.branchNo ORDER BY Branch.branchNo SEPARATOR ',') 
    AS Branches, PropertyForRent.city AS PropertyCity,
    GROUP_CONCAT(DISTINCT PropertyForRent.propertyNo ORDER BY PropertyForRent.propertyNo SEPARATOR ',') 
    AS Properties FROM Branch
LEFT JOIN PropertyForRent ON Branch.city = PropertyForRent.city
GROUP BY Branch.city ORDER BY Branch.city;
SELECT  
    b.city,GROUP_CONCAT(DISTINCT b.branchNo SEPARATOR ',') AS Branches,
     p.city AS pCity,GROUP_CONCAT(DISTINCT p.propertyNo SEPARATOR ',') AS Properties
FROM Branch b LEFT JOIN PropertyForRent p ON b.city = p.city
GROUP BY b.city ORDER BY b.city;

#ALTERNATIVE
SELECT 
    b.city AS bCity,b.branchNo,
    p.city AS pCity , p.propertyNo
FROM Branch b LEFT JOIN PropertyForRent p ON b.city = p.city;


#34 List the branch offices and properties that are in the same city along with any unmatched branches or properties. 
SELECT 
    Branch.city AS bCity,Branch.branchNo,
    PropertyForRent.city AS pCity , PropertyForRent.propertyNo
FROM Branch LEFT JOIN PropertyForRent  ON Branch.city = PropertyForRent.city
UNION SELECT 
    Branch.city AS bCity,Branch.branchNo,
    PropertyForRent.city AS pCity , PropertyForRent.propertyNo
FROM Branch RIGHT JOIN PropertyForRent ON Branch.city = PropertyForRent.city;
#alternative
SELECT b.city AS bCity,b.branchNo, p.city AS pCity , p.propertyNo
FROM Branch b LEFT JOIN PropertyForRent p ON b.city = p.city
UNION SELECT b.city AS bCity,b.branchNo, p.city AS pCity , p.propertyNo
FROM Branch b RIGHT JOIN PropertyForRent p ON b.city = p.city;
#ALTERNATIVE
SELECT  
    Branch.city,
    GROUP_CONCAT(DISTINCT Branch.branchNo ORDER BY Branch.branchNo SEPARATOR ',') 
    AS Branches, PropertyForRent.city AS PropertyCity,
    GROUP_CONCAT(DISTINCT PropertyForRent.propertyNo ORDER BY PropertyForRent.propertyNo SEPARATOR ',') 
    AS Properties FROM Branch
LEFT JOIN PropertyForRent ON Branch.city = PropertyForRent.city
GROUP BY Branch.city ORDER BY Branch.city;




#35.Write query to create a table OwnersPropertyCount (ownerNo, fName, lName,noOfProperty) and populate from the existing tables.
CREATE TABLE OwnersPropertyCount(
    ownerNo VARCHAR(5) PRIMARY KEY, fName VARCHAR(20) NOT NULL,lName VARCHAR(20) NOT NULL, noOfProperty INT,
    FOREIGN KEY (ownerNo) REFERENCES PrivateOwner(ownerNo) );

-- INSERT INTO OwnersPropertyCount (ownerNo, fName, lName, noOfProperty)
-- SELECT 
--     PrivateOwner.ownerNo, PrivateOwner.fName, PrivateOwner.lName, 
--     COUNT(PropertyForRent.propertyNo) AS noOfProperty
-- FROM PrivateOwner
-- LEFT JOIN PropertyForRent ON PrivateOwner.ownerNo = PropertyForRent.ownerNo
-- GROUP BY PrivateOwner.ownerNo, PrivateOwner.fName, PrivateOwner.lName;
INSERT INTO OwnersPropertyCount (ownerNo, fName, lName, noOfProperty)
SELECT 
    PrivateOwner.ownerNo,fName,lName, 
    COUNT(PropertyForRent.propertyNo) AS PropertyNumber
FROM PrivateOwner
LEFT JOIN PropertyForRent ON PrivateOwner.ownerNo = PropertyForRent.ownerNo
GROUP BY PrivateOwner.ownerNo, PrivateOwner.fName, PrivateOwner.lName;

select * from OwnersPropertyCount;

#36.Give all staff a 3% pay increase.
-- UPDATE Staff
-- SET salary=(salary*1.03);
ALTER TABLE Staff
ADD newSalary INT;

-- ALTER TABLE Staff
-- DROP COLUMN newSalary;

UPDATE Staff
SET newSalary=(salary*1.03);
SELECT CONCAT(fName," ",lName) AS staffName,salary,newSalary FROM Staff ORDER BY salary;


#37.Give all Managers a 5% pay increase.
UPDATE Staff
SET newSalary=(salary*1.05)
WHERE position = "Manager";
SELECT CONCAT(fName," ",lName) AS staffName,salary,newSalary FROM Staff WHERE position = "Manager" ORDER BY salary;

#38.Promote David Ford (staffNo 'SG14') to Manager and change his salary to £18,000
UPDATE Staff
SET newSalary=18000,position = "Manager"
WHERE staffNo = "SG14";
SELECT * FROM Staff WHERE position = "Manager";
SELECT CONCAT(fName," ",lName) AS staffName,salary,newSalary FROM Staff WHERE position = "Manager" ORDER BY salary;


#39 Delete all viewings that relate to property PG4
DELETE FROM viewing
WHERE propertyNo = "PG4";

SELECT * FROM viewing;

#40.Delete all rows from the Viewing table
DELETE FROM viewing
WHERE propertyNo IS NOT NULL;
SELECT * FROM viewing;


-- 41. Find Out staff Details who work for Same Branch which Have more than 1 Employee.
SELECT branchNo,GROUP_CONCAT(DISTINCT staffNo SEPARATOR ',') AS Staffs_Number,COUNT(staffNo) AS staffnum FROM Staff  GROUP BY branchNo  HAVING (COUNT(staffNo)>1) ;

-- Alternative
SELECT *
FROM Staff
WHERE branchNo IN (SELECT branchNo
FROM Staff Group BY branchNo
HAVING COUNT(staffNo) > 1);


-- 42.Create a View Which Display BranchNo,StaffNo.Position & ClientNo

CREATE VIEW StaffDetails AS
SELECT s.branchNo, s.staffNo, s.position, r.clientNo
FROM Staff s join registration r ON s.staffNo=r.staffNo;
SELECT * FROM staffdetails;
-- 43.SHOW all details from Cross Product of Staff,Registration

SELECT* FROM Staff CROSS JOIN Registration;
-- Alternatively
SELECT* FROM Staff JOIN Registration;

-- 44.Find the Street & city of the Branch for ALL Clients whose Max Rent > 400
SELECT * FROM propertyforrent WHERE rent>400;

-- 45.Find the Max Salary For Each BranchNo
SELECT branchNo, MAX(salary) AS maxsalary FROM Staff GROUP BY branchNo ;

-- 46. find the second heighest salary of staff with designation.
SELECT * FROM staff ORDER BY salary DESC LIMIT 1 OFFSET 1;
-- 47. Find the date of joining for the heigest salary holder staff.
SELECT dateJoined FROM Staff s JOIN Registration r ON r.staffNo=s.staffNo ORDER BY salary DESC LIMIT 1 OFFSET 0;
-- 48. Find the propertyNo, staffNo,branchNo and comment from the appropriate tabls.
SELECT p.propertyNo,s.staffNo,p.branchNo,v.comment FROM staff s JOIN propertyforrent p ON p.staffNo=s.staffNo JOIN viewing v on v.propertyNo = p.propertyNo;
-- 49. count the staff numbers working in each branch.
SELECT branchNo , COUNT(staffNo) FROM staff GROUP BY branchNo; 





-- 49. Find the staff who have been with the company for the longest period.
SELECT * FROM staff s JOIN registration r ON s.staffNo = r.staffNo ORDER BY dateJoined ASC LIMIT 1 OFFSET 0 ;



-- test-----------------------------------------------------------------------------------------------------------------------------------




SELECT staffNo,city FROM Staff
JOIN Branch ON Staff.branchNo = Branch.branchNo;

SELECT Branch.city, Branch.branchNo, PropertyForRent.propertyNo
FROM Branch
LEFT JOIN PropertyForRent ON Branch.city = PropertyForRent.city

UNION

SELECT PropertyForRent.city, Branch.branchNo, PropertyForRent.propertyNo
FROM PropertyForRent
RIGHT JOIN Branch ON Branch.city = PropertyForRent.city;