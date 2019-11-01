# Course Management System

To execute the program, run the following commands in terminal:
- g++ -std=c++11 classes/*.cpp -o coursemgmtsystem
- ./coursemgmtsystem

Course Management System is a simplied terminal based system that manages student information such as course enrolment. It allows both the teacher and student to keep track of their enrolled courses.

The application is based on the following assumption:
Every student has a unique student ID.
Every teacher has a unique teacher ID.
Every course will be taught by one teacher.
A student can enroll into any course.

To use this application, one has to sign up to be either a teacher or student. From there, one will be able to log in with his or her id.

A student is able to:
	1) View all courses
	2) Enroll into a course
	3) View enrolled course
	4) Withdraw from course
	5) View personal profile

A teacher is able to:
	1) View courses he or she teaches
	2) Teach a new course
	3) Remove a course he or she teaches
	4) View class lists of the course he or she teaches
	5) View personal profile