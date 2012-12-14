--===========================================
--CreateTableGetFit.sql
--Purpose:		This script creates the tables
--				for the GetFit database.
--
--Created By:	Daniel Bickler
--Created Date: December 12, 2012
--
--Modification Log: 
--===========================================
--2012.11.05 - modifications go here
-- 
--============================================

USE GetFit
GO

CREATE TABLE Trainee
(
TraineeId INTEGER IDENTITY NOT NULL,
TraineeNo INTEGER NOT NULL,
FName VARCHAR(20) NOT NULL,
MInitial CHAR (1) NULL,
LName VARCHAR (25) NOT NULL,
CoachId INTEGER NOT NULL
)

CREATE TABLE Coach
(
	CoachId INTEGER IDENTITY NOT NULL,
	FName VARCHAR (20) NOT NULL,
	MInitial CHAR (1) NULL,
	LName VARCHAR (25) NOT NULL
)

CREATE TABLE TrainingSchedule
(
	TrainingScheduleId INTEGER IDENTITY NOT NULL,
	WorkoutId INTEGER NOT NULL,
	DayInWeekId INTEGER NOT NULL,
	TraineeId INTEGER NOT NULL,
)

CREATE TABLE Workout
(
	WorkoutId INTEGER IDENTITY NOT NULL,
	WorkoutName VARCHAR (10) NOT NULL
)

CREATE TABLE DayInWeek
(
	DayInWeekId INTEGER IDENTITY NOT NULL,
	DayType VARCHAR (10) NOT NULL
)

CREATE TABLE ProcessLog
(
	ProcessLogId INTEGER IDENTITY,
	dtProcessDate DATETIME NOT NULL,
    vProcessName VARCHAR (50),
    vProcessMsg VARCHAR (100),
    vMsgType VARCHAR (20)
)
GO