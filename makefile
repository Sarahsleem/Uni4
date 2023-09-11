mainSrc= ./main.cpp
universitySrc= ./src/university.cpp
courseSrc= ./src/course.cpp
departmentSrc= ./src/department.cpp
professorSrc= ./src/professor.cpp
studentSrc= ./src/student.cpp

university.exe: $(mainSrc) $(universitySrc) $(courseSrc) $(departmentSrc) $(professorSrc) $(studentSrc)
	g++ $(mainSrc) $(universitySrc) $(couseSrc) $(departmentSrc) $(professorSrc) $(studentSrc) -o university.exe