--===========================================================
--CreatePrimaryKeysGetFit.sql
--Purpose:		This script is used to change the last name
--				of Annie to Anderson
--
--Created By:	Daniel Bickler
--Created Date: December 12, 2012
--Modification Log: 
--===========================================================
-- modifications go here
-- 
--===========================================================
Use GetFit
GO

UPDATE	dbo.Coach
SET		LName='Anderson'
WHERE	FName='Annie'
GO

(1 row(s) affected)

SELECT FName, MInitial, LName
FROM Coach
GO

FName                MInitial LName
-------------------- -------- -------------------------
Zach                 Z        Zeb
Annie                A        Anderson

(2 row(s) affected)