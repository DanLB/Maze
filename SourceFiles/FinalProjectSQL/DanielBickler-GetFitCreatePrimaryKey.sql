--===========================================================
--CreatePrimaryKeysGetFit.sql
--Purpose:		This script is used to create
--				the primary keys for the GetFit
--				database.
--Created By:	Daniel Bickler
--Created Date: December 12, 2012
--Modification Log: 
--===========================================================
-- modifications go here
-- 
--===========================================================
USE GetFit
GO

ALTER TABLE dbo.Trainee
ADD CONSTRAINT PK_TraineeId PRIMARY KEY (TraineeId)
GO

ALTER TABLE dbo.Coach
ADD CONSTRAINT PK_CoachId PRIMARY KEY (CoachId)
GO

ALTER TABLE dbo.TrainingSchedule
ADD CONSTRAINT PK_TrainingScheduleId PRIMARY KEY (TrainingScheduleId)
GO

ALTER TABLE dbo.Workout
ADD CONSTRAINT PK_WorkoutId PRIMARY KEY (WorkoutId)
GO

ALTER TABLE dbo.DayInWeek
ADD CONSTRAINT PK_DayInWeekId PRIMARY KEY (DayInWeekId)
GO

ALTER TABLE dbo.ProcessLog
ADD CONSTRAINT PK_ProcessLogId PRIMARY KEY (ProcessLogId)
GO