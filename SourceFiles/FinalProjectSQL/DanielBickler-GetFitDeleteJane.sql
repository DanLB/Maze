--===========================================================
--CreatePrimaryKeysGetFit.sql
--Purpose:		This script is used to delete the trainee
--				named Jane. Ran after Bob was inserted and
--				given Jane's schedule.
--
--Created By:	Daniel Bickler
--Created Date: December 12, 2012
--Modification Log: 
--===========================================================
-- modifications go here
-- 
--===========================================================
USE GetFit
GO

DELETE FROM Trainee
WHERE Trainee.FName = 'Jane'
GO

(1 row(s) affected)

SELECT * FROM Trainee GO

TraineeId   TraineeNo   FName                MInitial LName                     CoachId
----------- ----------- -------------------- -------- ------------------------- -----------
1           1245643     Samantha             S        Smith                     3
3           1245622     Michelle             M        Mitchel                   4
4           1245677     Bob                  B        Beck                      4

(3 row(s) affected)