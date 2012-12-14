--===========================================================
--CreatePrimaryKeysGetFit.sql
--Purpose:		This script is used to select the names of
--				the coaches with their trainees.
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

SELECT C.FName, C.MInitial, C.LName, T.FName, T.MInitial, T.LName
FROM Coach AS C, Trainee AS T
WHERE C.CoachId = T.CoachId
GO

FName                MInitial LName                     FName                MInitial LName
-------------------- -------- ------------------------- -------------------- -------- -------------------------
Zach                 Z        Zeb                       Samantha             S        Smith
Zach                 Z        Zeb                       Jane                 J        Jones
Annie                A        Abrams                    Michelle             M        Mitchel

(3 row(s) affected)
