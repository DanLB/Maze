--===========================================
--CreateTableGetFit.sql
--Purpose:		This script is used to select
--		the training schedule report for the
--		trainee named Michelle
--
--Created By:	Daniel Bickler
--Created Date: December 12, 2012
--Modification Log: 
--===========================================
--2012.11.05 - modifications go here
-- 
--============================================

USE GetFit
GO

DECLARE @Date DATETIME;

SELECT @Date = GETDATE();

SELECT T.TraineeNo,
	@Date AS ReportDate,
	T.FName,
	T.MInitial,
	T.LName,
	C.FName,
	C.MInitial,
	C.LName,
	D.DayType,
	W.WorkoutName
	
FROM Trainee AS T
	INNER JOIN Coach as C on T.CoachId = C.CoachId
	INNER JOIN TrainingSchedule AS TS on T.TraineeId = TS.TraineeId
	INNER JOIN DayInWeek AS D on TS.DayInWeekId = D.DayInWeekId
	INNER JOIN Workout AS W on TS.WorkoutId = W.WorkoutId
WHERE T.TraineeNo = 1245622
GO

TraineeNo   ReportDate              FName                MInitial LName                     FName                MInitial LName                     DayType    WorkoutName
----------- ----------------------- -------------------- -------- ------------------------- -------------------- -------- ------------------------- ---------- -----------
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Sunday     Abs
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Sunday     Strength
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Sunday     Cardio
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Tuesday    Abs
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Tuesday    Interval
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Tuesday    Cardio
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Wednesday  Interval
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Wednesday  Strength
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Thursday   Abs
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Thursday   Cardio
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Friday     Strength
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Saturday   Abs
1245622     2012-12-12 11:05:40.330 Michelle             M        Mitchel                   Annie                A        Abrams                    Saturday   Interval

(13 row(s) affected)
