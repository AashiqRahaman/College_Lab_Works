#Extras

#1.Find Out staff Details who work for Same Branch which Have more than 1 Employee.
SELECT * FROM Staff WHERE branchNo IN (SELECT s.branchNo FROM Staff s
Group BY branchNo HAVING COUNT(staffNo) > 1);

#2.Create a View Which Display BranchNo,StaffNo.Position & ClientNo
CREATE VIEW custom AS Select s.branchNo,s.staffNo,s.position,c.clientNo
From Staff s JOIN Registration c ON s.staffNo = c.staffNo;
Select * FROM custom;

#3.SHOW all details from Cross Product of Staff,Registration
SELECT * FROM Staff,Registration;

#4.Find the Street & city of the Branch for ALL Clients whose Max Rent > 400
SELECT c.clientNo,c.fName,c.lName,b.branchNo, b.street,b.city FROM Client c
JOIN Registration r ON c.clientNo = r.clientNo AND maxRent > 400
JOIN Branch b ON r.branchNo = b.branchNo;