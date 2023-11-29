#include "student_details.h"
#include <iostream>
#include <cstdlib> 
#include <string>
#include <queue>
#include <array>
using namespace std;


student_list :: student_list()
{
    for(int i = 0; i < STUDENT_COUNT; i++)
        {
            s[i].placed = false;
            for(int j1 = 0; j1 < CORE; j1++)
            {
                s[i].core[j1] = false;
                s[i].fs_core[j1] = 0;
            }
            for(int j2 = 0; j2 < TECH; j2++)
            {
                s[i].tech[j2] = false;
                s[i].fs_tech[j2][0] = 0.0;
                s[i].fs_tech[j2][1] = 0.0;
                s[i].fs_tech[j2][2] = 0.0;
            }
            for(int j3 = 0; j3 < FINANCE; j3++)
            {
                s[i].finance[j3] = false;
                s[i].fs_finance[j3][0] = 0.0;
                s[i].fs_finance[j3][1] = 0.0;
            }
            for(int j4 = 0; j4 < CONSULTING; j4++)
            {
                s[i].consulting[j4] = false;
                s[i].fs_consulting[j4][0] = 0.0;
                s[i].fs_consulting[j4][1] = 0.0;
            }
        }
        s[0].branch_code = 1;
        s[0].branch = "CSE";
        s[0].rollno = 2001001;
        s[0].CPI = 8.35;
        s[0].num_projects = 4;
        s[1].branch_code = 1;
        s[1].branch = "CSE";
        s[1].rollno = 2001002;
        s[1].CPI = 9.11;
        s[1].num_projects = 3;
        s[2].branch_code = 1;
        s[2].branch = "CSE";
        s[2].rollno = 2001003;
        s[2].CPI = 9.41;
        s[2].num_projects = 4;
        s[3].branch_code = 2;
        s[3].branch = "DSAI";
        s[3].rollno = 2002001;
        s[3].CPI = 9.37;
        s[3].num_projects = 4;
        s[4].branch_code = 2;
        s[4].branch = "DSAI";
        s[4].rollno = 2002002;
        s[4].CPI = 7.91;
        s[4].num_projects = 5;
        s[5].branch_code = 3;
        s[5].branch = "MnC";
        s[5].rollno = 2003001;
        s[5].CPI = 8.95;
        s[5].num_projects = 4;
        s[6].branch_code = 3;
        s[6].branch = "MnC";
        s[6].rollno = 2003002;
        s[6].CPI = 7.96;
        s[6].num_projects = 4;
        s[7].branch_code = 3;
        s[7].branch = "MnC";
        s[7].rollno = 2003003;
        s[7].CPI = 8.36;
        s[7].num_projects = 3;
        s[8].branch_code = 4;
        s[8].branch = "ECE";
        s[8].rollno = 2004001;
        s[8].CPI = 8.27;
        s[8].num_projects = 3;
        s[9].branch_code = 4;
        s[9].branch = "ECE";
        s[9].rollno = 2004002;
        s[9].CPI = 8.95;
        s[9].num_projects = 4;
        s[10].branch_code = 4;
        s[10].branch = "ECE";
        s[10].rollno = 2004003;
        s[10].CPI = 7.17;
        s[10].num_projects = 4;
        s[11].branch_code = 5;
        s[11].branch = "EEE";
        s[11].rollno = 2005001;
        s[11].CPI = 8.44;
        s[11].num_projects = 3;
        s[12].branch_code = 5;
        s[12].branch = "EEE";
        s[12].rollno = 2005002;
        s[12].CPI = 8.72;
        s[12].num_projects = 4;
        s[13].branch_code = 5;
        s[13].branch = "EEE";
        s[13].rollno = 2005003;
        s[13].CPI = 7.71;
        s[13].num_projects = 4;
        s[14].branch_code = 6;
        s[14].branch = "ME";
        s[14].rollno = 2006001;
        s[14].CPI = 8.35;
        s[14].num_projects = 4;
        s[15].branch_code = 6;
        s[15].branch = "ME";
        s[15].rollno = 2006002;
        s[15].CPI = 8.64;
        s[15].num_projects = 3;
        s[16].branch_code = 7;
        s[16].branch = "EP";
        s[16].rollno = 2007001;
        s[16].CPI = 7.93;
        s[16].num_projects = 4;
        s[17].branch_code = 7;
        s[17].branch = "EP";
        s[17].rollno = 2007002;
        s[17].CPI = 8.26;
        s[17].num_projects = 3;
        s[18].branch_code = 8;
        s[18].branch = "EnE";
        s[18].rollno = 2008001;
        s[18].CPI = 8.11;
        s[18].num_projects = 4;
        s[19].branch_code = 9;
        s[19].branch = "CL";
        s[19].rollno = 2009001;
        s[19].CPI = 8.22;
        s[19].num_projects = 3;
        s[20].branch_code = 9;
        s[20].branch = "CL";
        s[20].rollno = 2009002;
        s[20].CPI = 8.47;
        s[20].num_projects = 4;
        s[21].branch_code = 10;
        s[21].branch = "CE";
        s[21].rollno = 2010001;
        s[21].CPI = 7.36;
        s[21].num_projects = 4;
        s[22].branch_code = 10;
        s[22].branch = "CE";
        s[22].rollno = 2010002;
        s[22].CPI = 8.11;
        s[22].num_projects = 3;
        s[23].branch_code = 10;
        s[23].branch = "CE";
        s[23].rollno = 2010003;
        s[23].CPI = 7.01;
        s[23].num_projects = 4;
        s[24].branch_code = 11;
        s[24].branch = "CST";
        s[24].rollno = 2011001;
        s[24].CPI = 7.59;
        s[24].num_projects = 3;
        s[25].branch_code = 11;
        s[25].branch = "CST";
        s[25].rollno = 2011002;
        s[25].CPI = 8.34;
        s[25].num_projects = 3;
        s[26].branch_code = 12;
        s[26].branch = "BSBE";
        s[26].rollno = 2012001;
        s[26].CPI = 8.33;
        s[27].num_projects = 4;
        s[27].branch_code = 12;
        s[27].branch = "BSBE";
        s[27].rollno = 2012002;
        s[27].CPI = 7.12;
        s[27].num_projects = 3;
	}
void student_list :: student_eligibility()
{
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		if(s[i].branch == "CSE" || s[i].branch == "DSAI" || s[i].branch == "MnC")
		{
			for(int j = 0; j < CORE; j++)
			{
				s[i].core[j] = false;
			}
			for(int j = 0; j < TECH; j++)
			{
				s[i].tech[j] = true;
			}
			for(int j = 0; j < FINANCE; j++)
			{
				s[i].finance[j] = true;
			}
			for(int j = 0; j < CONSULTING; j++)
			{
				s[i].consulting[j] = true;
			}

		}
		if(s[i].branch == "ECE")
		{
			for(int j = 0; j < CORE; j++)
			{
				if(j == 0 || j == 1 || j == 4 || j == 5)
				{
					s[i].core[j] = false;
				}
				else
				{
					s[i].core[j] = true;
				}
				
			}
			for(int j = 0; j < TECH; j++)
			{
				if(j == 1)
				{
					s[i].tech[j] = false;
				}
				else
				{
					s[i].tech[j] = true;
				}
				
			}
			for(int j = 0; j < FINANCE; j++)
			{
				if(j == 2)
				{
					s[i].finance[j] = false;
				}
				else
				{
					s[i].finance[j] = true;
				}
			}
			for(int j = 0; j < CONSULTING; j++)
			{
				if(j == 1)
				{
					s[i].consulting[j] = false;
				}
				else
				{
					s[i].consulting[j] = true;
				}
			}
		}
		if(s[i].branch == "EEE" || s[i].branch == "ME" || s[i].branch == "EP")
		{
			for(int j = 0; j < CORE; j++)
			{
				s[i].core[j] = true;
	
			}
			for(int j = 0; j < TECH; j++)
			{
				if(j == 1 || j == 2)
				{
					s[i].tech[j] = true;
				}
				else
				{
					s[i].tech[j] = false;
				}
				
			}
			for(int j = 0; j < FINANCE; j++)
			{
				if(j == 0)
				{
					s[i].finance[j] = true;
				}
				else
				{
					s[i].finance[j] = false;
				}
			}
			for(int j = 0; j < CONSULTING; j++)
			{
				if(j == 1)
				{
					s[i].consulting[j] = true;
				}
				else
				{
					s[i].consulting[j] = false;
				}
			}
		}
		if(s[i].branch == "EnE" || s[i].branch == "CL" || s[i].branch == "CE")
		{
			for(int j = 0; j < CORE; j++)
			{
				if(j == 0 || j == 1 || j == 5)
				{
					s[i].core[j] = true;
				}
				else
				{
					s[i].core[j] = false;
				}
				
			}
			for(int j = 0; j < TECH; j++)
			{
				if(j == 2)
				{
					s[i].tech[j] = true;
				}
				else
				{
					s[i].tech[j] = false;
				}
				
			}
			for(int j = 0; j < FINANCE; j++)
			{
				
				s[i].finance[j] = false;
				
			}
			for(int j = 0; j < CONSULTING; j++)
			{
				if(j == 1)
				{
					s[i].consulting[j] = true;
				}
				else
				{
					s[i].consulting[j] = false;
				}
			}
		}
		if(s[i].branch == "CST" || s[i].branch == "BSBE" )
		{
			for(int j = 0; j < CORE; j++)
			{
				if(j == 1 || j == 2 || j == 3 || j == 5)
				{
					s[i].core[j] = true;
				}
				else
				{
					s[i].core[j] = false;
				}
				
			}
			for(int j = 0; j < TECH; j++)
			{
				if(j == 2)
				{
					s[i].tech[j] = true;
				}
				else
				{
					s[i].tech[j] = false;
				}
				
			}
			for(int j = 0; j < FINANCE; j++)
			{
				
				s[i].finance[j] = false;
				
			}
			for(int j = 0; j < CONSULTING; j++)
			{
				
				s[i].consulting[j] = false;
				
			}
		}
	}
}
void student_list :: sort_student_CPI()
{
	//Sorting the students by their CPI
	int flag = 0;
	for(int i = 0; i < STUDENT_COUNT-1; i++)
	{
		flag = 0;
		for(int j = 0; j < STUDENT_COUNT-1-i; j++)
		{
			if(s[j].CPI < s[j+1].CPI)
			{
				student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				flag = 1;
			}
			
		}
		if(flag == 0)
		{
			return;
		}
	}
}
void student_list :: sort_by_branch_and_CPI()
{
	//Sorting students by their branch and CPI
	sort_student_CPI();
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		int flag = 0;
		for(int j = 0; j < STUDENT_COUNT-1-i; j++)
		{
			if(s[j].branch_code > s[j+1].branch_code)
			{
				student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0)
		{
			return;
		}
	}
	int students_per_branch[BRANCH_COUNT];
	int cumul_students[BRANCH_COUNT];
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		for(int j = 0; j < BRANCH_COUNT; j++)
		{
			if(s[i].branch_code == j + 1)
			{
				students_per_branch[j] += 1;
			}
		}
	}
	cumul_students[0] = 0;
	for(int i = 1; i < BRANCH_COUNT; i++)
	{
		cumul_students[i] += cumul_students[i-1];
	}
	for(int x  = 0; x < BRANCH_COUNT; x++)
	{
		for(int i = 0; i < students_per_branch[x]; i++)
		{
			for(int j = 0; j < students_per_branch[x]-1-i; j++)
			{
				if(s[cumul_students[x]+j].CPI < s[cumul_students[x]+j+1].CPI)
				{	
					student temp = s[cumul_students[x]+j];
					s[cumul_students[x]+j] =  s[cumul_students[x]+j+1];
					s[cumul_students[x]+j+1] = temp;  
				}
			}
		} 
	}
	
}
void student_list :: display_studentlist()
{
	cout << "List of students:\n";
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << "Branch code: " << s[i].branch_code << endl;
		cout << "Branch: " << s[i].branch << endl;
		cout << "Roll number: " << s[i].rollno << endl;
		cout << "CPI: " << s[i].CPI << endl;
		cout << "Number of projects: " << s[i].num_projects << endl;
		if(s[i].placed != false)
		{
			cout << "Placed: " << s[i].placed << endl;
			cout << "Company: " << s[i].company_name <<endl;
			cout << "Job Title: " << s[i].job_title << endl;
			cout << "CTC: " << s[i].ctc << endl; 
		}
		else
		{
			cout << "Not Placed Yet\n";
		}

	}	
}