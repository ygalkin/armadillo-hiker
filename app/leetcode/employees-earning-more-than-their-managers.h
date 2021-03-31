//https://leetcode.com/problems/employees-earning-more-than-their-managers/

# Write your MySQL query statement below
SELECT Name as Employee FROM Employee a WHERE Salary > (SELECT Salary FROM Employee b WHERE a.ManagerId = b.Id)