#-*-Makefile-*

main: main.o add_student.o Entry.o Exit.o Student_status.o stu_info.o Student_history.o Student_list.o check.o warnings.o display.o
	gcc main.o add_student.o Entry.o Exit.o Student_status.o stu_info.o  Student_history.o Student_list.o check.o warnings.o display.o -o main
main.o: main.c add_student.h Entry.h Exit.h Student_status.h stu_info.h Student_history.h Student_list.h check.h warnings.h display.h
	gcc -c main.c
add_student.o: add_student.c
	gcc -c add_student.c
Entry.o: Entry.c
	gcc -c Entry.c
Exit.o: Exit.c
	gcc -c Exit.c
Student_status.o: Student_status.c
	gcc -c Student_status.c
stu_info.o: stu_info.c
	gcc -c stu_info.c
Student_list.o: Student_list.c
	gcc -c Student_list.c
Student_history.o: Student_history.c
	gcc -c Student_history.c
check.o: check.c
	gcc -c check.c
warnings.o: warnings.c
	gcc -c warnings.c
display.o: display.c
	gcc -c display.c
clean:
	rm *.o main
