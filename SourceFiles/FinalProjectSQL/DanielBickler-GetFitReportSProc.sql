Use GetFit
GO

--spTrainingReport
if exists (select 1 from sysobjects
           where  type = 'P' 
           and    name = 'spTrainingReport')
   BEGIN
   PRINT 'Dropping procedure spTrainingReport'
   DROP PROCEDURE spTrainingReport
   END
GO
PRINT 'Creating procedure spTrainingReport'
GO

create procedure spTrainingReport
-------------------------------------------------------
-- Procedure:	spTrainingReport
--
-- Description:	This proc returns the training schedule
--				report for the desired trainee
--
-- Parameter: Trainee No, the non-system-generated
--			7-digit Identification No
--
-- Modification Log
-- Date:      Who: Purpose:
-- ---------- ---- ---------------------------------
-- 12/12/2012 dlb  Initial Version
---------------------------------------------------
@TrainNo INT

AS
BEGIN

/* ********************************
     VARIABLE DECLARATION SECTION
   ******************************** */

   DECLARE
    @vErrorMsg VARCHAR(255),  -- Error message for error log
    @vProgName VARCHAR(75),   -- Name of stored procedure
    @vComplete VARCHAR (8),
    @dtTodaysDate DATETIME,
    @iSQLError INT,           -- SQL error number
    
    @TraineeNo INT
	
/* ***********************************
     VARIABLE INITIALIZATION SECTION
   *********************************** */
	
SELECT @TraineeNo = @TrainNo,
	@dtTodaysDate=GETDATE();
	
/* ********************************
           PROGRAM SECTION
   ******************************** */
   
INSERT INTO ProcessLog
	(dtProcessDate,
    vProcessName,
    vProcessMsg,
    vMsgType )
VALUES
   (@dtTodaysDate,
    @vProgName,
    'Processing Data from UpdateHeader ',
    'INFO')

SELECT @iSQLError = @@error
     
IF @iSQLError <> 0 
	BEGIN
    SELECT @vErrorMsg = 'SQL Error occurred when inserting Processing Data record '
                             + 'into ProcessLog. Error: '
                             + SUBSTRING (CONVERT (varchar, @iSQLError), 1, 5)
    GOTO ERROR
    END

SELECT T.TraineeId,
	T.TraineeNo,
	@dtTodaysDate AS ReportDate,
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
WHERE T.TraineeNo = @TraineeNo

SELECT @iSQLError = @@error
      IF @iSQLError <> 0 
      BEGIN
         SELECT @vErrorMsg = 'SQL Error occurred when deleting records from prior batch. '
                             + 'Error: '
                             + SUBSTRING (CONVERT (varchar, @iSQLError), 1, 5)
         GOTO ERROR
      END

ERROR:
   INSERT INTO ProcessLog
      (dtProcessDate,
       vProcessName,
       vProcessMsg,
       vMsgType)
   VALUES
      (@dtTodaysDate,
       @vProgName, 
       @vErrorMsg,
       'ERROR')

   RETURN
   
END
GO

--Test Procedure using Id # for Samantha

spTrainingReport 1245643
GO


(1 row(s) affected)
TraineeId   TraineeNo   ReportDate              FName                MInitial LName                     FName                MInitial LName                     DayType    WorkoutName
----------- ----------- ----------------------- -------------------- -------- ------------------------- -------------------- -------- ------------------------- ---------- -----------
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Sunday     Cardio
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Tuesday    Cardio
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Thursday   Cardio
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Monday     Strength
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Wednesday  Strength
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Friday     Strength
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Wednesday  Interval
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Saturday   Interval
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Sunday     Abs
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Tuesday    Abs
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Thursday   Abs
1           1245643     2012-12-12 11:33:24.167 Samantha             S        Smith                     Zach                 Z        Zeb                       Saturday   Abs

(12 row(s) affected)

(1 row(s) affected)

