#ifndef STUDENT_DETAILS_H
#define STUDENT_DETAILS_H

#include <iostream>
#include <cstdlib> 
#include <string>
#include <queue>
#include <array>
using namespace std;
const int STUDENT_COUNT = 28; 
const int BRANCH_COUNT = 12;
const int COMPANY_COUNT = 15;
const int CORE = 6;
const int TECH = 4;
const int FINANCE = 3;
const int CONSULTING = 2;
const int JOB_COUNT = 3;

struct student
{
	int branch_code;
	string branch;
	int rollno;
	float CPI;
	int num_projects;
	bool placed;
	bool core[CORE];
	float w_test[CORE];
	float interview_core[CORE];
	float fs_core[CORE];
	bool tech[TECH];
	float coding_rd1[TECH][3];
	float interview_coding[TECH][3];
	float fs_tech[TECH][3];
	bool finance[FINANCE];
	float math_written[FINANCE][2];
	float interview_finance[FINANCE][2];
	float fs_finance[FINANCE][2];
	bool consulting[CONSULTING];
	float a_rd[CONSULTING][2];
	float interview_consulting[CONSULTING][2];
	float fs_consulting[CONSULTING][2];
	string company_name;
	string job_title;
	float ctc;

};

class student_list
{
	public:
		student s[STUDENT_COUNT]; // Static array of 'student' with fixed size
		student_list();
		void student_eligibility();
		void sort_student_CPI();
		void sort_by_branch_and_CPI();
		void display_studentlist();
};

#endif