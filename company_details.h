#ifndef COMPANY_DETAILS_H
#define COMPANY_DETAILS_H

#include "student_details.h"
#include "linkedl.h"
struct job
{
	string title;
	float ctc;
};
struct com
{
	string name_company;
	int year_founded;
	int njobs;
	string type;
	char tier;
	bool accepted[JOB_COUNT]; 
	job jobs[JOB_COUNT];
	string eligible_branches[BRANCH_COUNT];
};
class Company
{
	public:
		com companies[COMPANY_COUNT];
		node *head[COMPANY_COUNT];
		void display_company_details();
		Company();
		
	
};

#endif