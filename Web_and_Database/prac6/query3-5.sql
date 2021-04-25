SELECT Students.name,Enrolments.mark FROM Students INNER JOIN Enrolments ON Students.student_id = Enrolments.student_id WHERE mark<'50' AND Enrolments.subject_code='COMP SCI 2000';

