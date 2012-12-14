--===========================================================
--CreatePrimaryKeysGetFit.sql
--Purpose:		This script is used to select the names of
--				all the trainees
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

SELECT T.FName, T.MInitial, T.LName
FROM Trainee AS T
GO

FName                MInitial LName
-------------------- -------- -------------------------
Samantha             S        Smith
Jane                 J        Jones
Michelle             M        Mitchel

(3 row(s) affected)
