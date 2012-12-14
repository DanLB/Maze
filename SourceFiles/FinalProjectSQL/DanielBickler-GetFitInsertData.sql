USE GetFit
GO

INSERT INTO Coach
(
	FName,
	MInitial,
	LName
)
SELECT 'Zach','Z','Zeb'
GO

INSERT INTO Coach
(
FName,
MInitial,
LName
)
SELECT 'Annie','A','Abrams'
GO

INSERT INTO Trainee
(
	TraineeNo,
	FName,
	MInitial,
	LName,
	CoachId
)
SELECT 1245643, 'Samantha', 'S', 'Smith', C.CoachId
FROM Coach AS C
WHERE C.FName = 'Zach'
GO

INSERT INTO Trainee
(
	TraineeNo,
	FName,
	MInitial,
	LName,
	CoachId
)
SELECT 1245655, 'Jane', 'J', 'Jones', C.CoachId
FROM Coach AS C
WHERE C.FName = 'Zach'
GO

INSERT INTO Trainee
(
	TraineeNo,
	FName,
	MInitial,
	LName,
	CoachId
)
SELECT 1245622, 'Michelle', 'M', 'Mitchel', C.CoachId
FROM Coach AS C
WHERE C.FName = 'Annie'
GO

INSERT INTO DayInWeek
(
	DayType
)
SELECT 'Sunday'
GO

INSERT INTO DayInWeek
(
	DayType
)
SELECT 'Monday'
GO

INSERT INTO DayInWeek
(
	DayType
)
SELECT 'Tuesday'
GO

INSERT INTO DayInWeek
(
	DayType
)
SELECT 'Wednesday'
GO

INSERT INTO DayInWeek
(
	DayType
)
SELECT 'Thursday'
GO

INSERT INTO DayInWeek
(
	DayType
)
SELECT 'Friday'
GO

INSERT INTO DayInWeek
(
	DayType
)
SELECT 'Saturday'
GO

INSERT INTO Workout
(
	WorkoutName
)
SELECT 'Strength'
GO

INSERT INTO Workout
(
	WorkoutName
)
SELECT 'Interval'
GO

INSERT INTO Workout
(
	WorkoutName
)
SELECT 'Abs'
GO

INSERT INTO Workout
(
	WorkoutName
)
SELECT 'Cardio'
GO

--Samantha's Schedule

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Sunday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Tuesday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Thursday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Monday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Wednesday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Friday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Wednesday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Saturday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Sunday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Tuesday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Thursday' And T.FName = 'Samantha'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Saturday' And T.FName = 'Samantha'
GO

--Jane's Schedule

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Sunday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Sunday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Sunday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Monday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Monday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Tuesday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Tuesday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Wednesday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Wednesday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Wednesday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Thursday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Thursday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Friday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Friday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Saturday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Saturday' And T.FName = 'Jane'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Saturday' And T.FName = 'Jane'
GO

--Michelle's Schedule

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Sunday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Sunday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Sunday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Tuesday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Tuesday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Tuesday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Wednesday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Wednesday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Thursday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Cardio' And D.DayType = 'Thursday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Strength' And D.DayType = 'Friday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Abs' And D.DayType = 'Saturday' And T.FName = 'Michelle'
GO

INSERT INTO TrainingSchedule
(
	WorkoutId,
	DayInWeekId,
	TraineeId
)
SELECT W.WorkoutId, D.DayInWeekId, T.TraineeId
FROM Workout AS W, DayInWeek AS D, Trainee AS T
WHERE W.WorkoutName = 'Interval' And D.DayType = 'Saturday' And T.FName = 'Michelle'
GO