--===========================================================
--CreatePrimaryKeysGetFit.sql
--Purpose:		This script is used to create the foreign
--				keys for the GetFit Database.
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

ALTER TABLE dbo.Trainee
ADD CONSTRAINT FK_CoachId FOREIGN KEY (CoachId)
	REFERENCES Coach (CoachId)
GO

ALTER TABLE dbo.TrainingSchedule
ADD CONSTRAINT FK_WorkoutId FOREIGN KEY (WorkoutId)
	REFERENCES Workout (WorkoutId)
GO

ALTER TABLE dbo.TrainingSchedule
ADD CONSTRAINT FK_DayInWeekId FOREIGN KEY (DayInWeekId)
	REFERENCES DayInWeek (DayInWeekId)
GO

ALTER TABLE dbo.TrainingSchedule
ADD CONSTRAINT FK_TraineeId FOREIGN KEY (TraineeId)
	REFERENCES Trainee (TraineeId)
GO