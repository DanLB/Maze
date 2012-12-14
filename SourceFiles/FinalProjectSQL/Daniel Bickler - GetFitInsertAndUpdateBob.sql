--===========================================================
--CreatePrimaryKeysGetFit.sql
--Purpose:		This script is used to add a trainee named
--				Bob B. Beck and assign him to the coach named
--				Annie and give him Jane's schedule.
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

INSERT INTO Trainee
(
	TraineeNo,
	FName,
	MInitial,
	LName,
	CoachId
)
SELECT 1245677, 'Bob', 'B', 'Beck', C.CoachId
FROM Coach AS C
WHERE C.FName = 'Annie'
GO

--Update TrainingSchedule table to give Jane's schedule to Bob

UPDATE TrainingSchedule
SET TraineeId=(SELECT T.TraineeId FROM Trainee as T WHERE T.FName = 'Bob')
WHERE TraineeId=(SELECT T.TraineeId FROM Trainee AS T WHERE T.FName='Jane')
GO

(1 row(s) affected)

(17 row(s) affected)

--Check it

SELECT * FROM Trainee
GO

TraineeId   TraineeNo   FName                MInitial LName                     CoachId
----------- ----------- -------------------- -------- ------------------------- -----------
1           1245643     Samantha             S        Smith                     3
2           1245655     Jane                 J        Jones                     3
3           1245622     Michelle             M        Mitchel                   4
4           1245677     Bob                  B        Beck                      4

(4 row(s) affected)


SELECT * FROM TrainingSchedule
GO

TrainingScheduleId WorkoutId   DayInWeekId TraineeId
------------------ ----------- ----------- -----------
1                  4           1           1
2                  4           3           1
3                  4           5           1
4                  1           2           1
5                  1           4           1
6                  1           6           1
7                  2           4           1
8                  2           7           1
9                  3           1           1
10                 3           3           1
11                 3           5           1
12                 3           7           1
13                 4           1           4
14                 2           1           4
15                 3           1           4
16                 3           2           4
17                 1           2           4
18                 3           3           4
19                 4           3           4
20                 3           4           4
21                 2           4           4
22                 1           4           4
23                 3           5           4
24                 4           5           4
25                 3           6           4
26                 1           6           4
27                 3           7           4
28                 2           7           4
29                 4           7           4
30                 3           1           3
31                 1           1           3
32                 4           1           3
33                 3           3           3
34                 2           3           3
35                 4           3           3
36                 2           4           3
37                 1           4           3
38                 3           5           3
39                 4           5           3
40                 1           6           3
41                 3           7           3
42                 2           7           3

(42 row(s) affected)

