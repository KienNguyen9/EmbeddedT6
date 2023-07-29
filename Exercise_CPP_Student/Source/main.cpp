/*
* File: student.cpp
* Author: Nguyen Trung Kien
* Date: 28/07/2023
* Description: This is an example about create a program to manage students
*/

#include "students.h"

int main() {
	menu sv;
	sv.addStudent();
	sv.addStudent();
	sv.addStudent();
	sv.sortByAvg();
	sv.sortByName();
	sv.showList();
	
    return 0;
}
