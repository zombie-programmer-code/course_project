#include "company_details.h"
#include "linkedl.h"
#include "student_details.h"

Company::Company()
{
    for(int i = 0; i < COMPANY_COUNT; i++)
    {
        head[i] = nullptr;
    }
    companies[0].name_company = "Microsoft";
    companies[0].year_founded = 1975;
    companies[0].type = "Tech";
    companies[1].name_company = "Google";
    companies[1].year_founded = 1998;
    companies[1].type = "Tech";
    companies[2].name_company = "Amazon";
    companies[2].year_founded = 1994;
    companies[2].type = "Tech";
    companies[3].name_company = "Meta";
    companies[3].year_founded = 2004;
    companies[3].type = "Tech";
    companies[4].name_company = "Goldman Sachs";
    companies[4].year_founded = 1869;
    companies[4].type = "Finance";
    companies[5].name_company = "JP Morgan";
    companies[5].year_founded = 1871;
    companies[5].type = "Finance";
    companies[6].name_company = "Jane Street";
    companies[6].year_founded = 1999;
    companies[6].type = "Finance";
    companies[7].name_company = "Larsen & Toubro";
    companies[7].year_founded = 1946;
    companies[7].type = "Core";
    companies[7].tier = 'B';
    companies[8].name_company = "Reliance Industries";
    companies[8].year_founded = 1966;
    companies[8].type = "Core";
    companies[8].tier = 'C';
    companies[9].name_company = "Mercedes";
    companies[9].year_founded = 1926;
    companies[9].type = "Core";
    companies[9].tier = 'B';
    companies[10].name_company = "Texas Instruments";
    companies[10].year_founded = 1930;
    companies[10].type = "Core";
    companies[10].tier = 'C';
    companies[11].name_company = "Samsung";
    companies[11].year_founded = 1938;
    companies[11].tier = 'B';
    companies[11].type = "Core";
    companies[12].name_company = "Lupin Ltd";
    companies[12].year_founded = 1968;
    companies[12].type = "Core";
    companies[12].tier = 'C';
    companies[13].name_company = "Boston Consulting Group";
    companies[13].year_founded = 1963;
    companies[13].type = "Consulting";
    companies[13].tier = 'A';
    companies[14].name_company = "McKinsey & Company";
    companies[14].year_founded = 1926;
    companies[14].type = "Consulting";
    companies[14].tier = 'A';
    
    for(int i = 0; i < COMPANY_COUNT; i++)
    { 
        if(companies[i].type == "Tech")
        {
            companies[i].tier = 'A';
            companies[i].njobs = 3;
            companies[i].jobs[0].title = "Software Developer";
            companies[i].jobs[1].title = "Software Engineer";
            companies[i].jobs[2].title = "R&D";
            for(int j = 0; j < JOB_COUNT; j++)
            {
                companies[i].accepted[j] = "False";
            }
            if(companies[i].name_company == "Microsoft")
            {
                companies[i].jobs[0].ctc = 3900000.0;
                companies[i].jobs[1].ctc = 4900000.0;
                companies[i].jobs[2].ctc = 6500000.0;
            }
            if(companies[i].name_company == "Amazon")
            {
                companies[i].jobs[0].ctc = 4700000.0;
                companies[i].jobs[1].ctc = 3800000.0;
                companies[i].jobs[2].ctc = 7300000.0;
            }
            if(companies[i].name_company == "Meta")
            {
                companies[i].jobs[0].ctc = 4200000.0;
                companies[i].jobs[1].ctc = 4600000.0;
                companies[i].jobs[2].ctc = 6000000.0;
            }
            if(companies[i].name_company == "Google")
            {
                companies[i].jobs[0].ctc = 4500000.0;
                companies[i].jobs[1].ctc = 5100000.0;
                companies[i].jobs[2].ctc = 7000000.0;
            }
            companies[i].eligible_branches[0] = "CSE";
            companies[i].eligible_branches[1] = "DSAI";
            companies[i].eligible_branches[2] = "MnC";
            if(companies[i].name_company != "Google")
            {
                companies[i].eligible_branches[3] = "ECE";
            }
            if(companies[i].name_company == "Google" || companies[i].name_company =="Amazon")
            {
                companies[i].eligible_branches[3] = "EEE";
                companies[i].eligible_branches[4] = "ME";
                companies[i].eligible_branches[5] = "EP";
            }
            if(companies[i].name_company == "Amazon")
            {
                companies[i].eligible_branches[6] = "EnE";
                companies[i].eligible_branches[7] = "CL";
                companies[i].eligible_branches[8] = "CE";
                companies[i].eligible_branches[9] = "CST";
                companies[i].eligible_branches[10] = "BSBE";
            }
            
            
        }
        if(companies[i].type == "Finance")
        {
            companies[i].tier = 'A';
            companies[i].njobs = 2;
            companies[i].jobs[0].title = "Quant";
            companies[i].jobs[1].title = "Algorithmic Trader";
            for(int j = 0; j < JOB_COUNT; j++)
            {
                companies[i].accepted[j] = "False";
                
            }
            if(companies[i].name_company == "Jane Street")
            {
                companies[i].jobs[0].ctc = 6300000.0;
                companies[i].jobs[1].ctc = 7100000.0;
            }
            if(companies[i].name_company == "JP Morgan")
            {
                companies[i].jobs[0].ctc = 5500000.0;
                companies[i].jobs[1].ctc = 8000000.0;
            }
            if(companies[i].name_company == "Goldman Sachs")
            {
                companies[i].jobs[0].ctc = 9300000.0;
                companies[i].jobs[1].ctc = 10100000.0;
            }
            companies[i].eligible_branches[0] = "CSE";
            companies[i].eligible_branches[1] = "DSAI";
            companies[i].eligible_branches[2] = "MnC";
            if(companies[i].name_company != "Jane Street")
            {
                companies[i].eligible_branches[3] = "ECE";
            }
            if(companies[i].name_company == "Goldman Sachs")
            {
                companies[i].eligible_branches[3] = "EEE";
                companies[i].eligible_branches[3] = "ME";
                companies[i].eligible_branches[3] = "EP";
            }
        }
        if(companies[i].type == "Core")
        {
            companies[i].njobs = 1;
            companies[i].jobs[0].title = "Graduate Engineer Trainee";
            for(int j = 0; j < JOB_COUNT; j++)
            {
                companies[i].accepted[j] = "False";
                
            }
            if(companies[i].name_company == "Larsen & Toubro")
            {
                companies[i].jobs[0].ctc = 1500000.0;
            }
            if(companies[i].name_company == "Reliance Industries")
            {
                companies[i].jobs[0].ctc = 1600000.0;
            }
            if(companies[i].name_company == "Lupin Ltd")
            {
                companies[i].jobs[0].ctc = 1550000.0;
            }
            if(companies[i].name_company == "Mercedes")
            {
                companies[i].jobs[0].ctc = 1750000.0;
            }
            if(companies[i].name_company == "Samsung")
            {
                companies[i].jobs[0].ctc = 2550000.0;
            }
            if(companies[i].name_company == "Texas Instruments")
            {
                companies[i].jobs[0].ctc = 2350000.0;
            }
            if(companies[i].name_company == "Larsen & Toubro" || companies[i].name_company == "Reliance Industries" || companies[i].name_company == "Lupin Ltd")
            {
                companies[i].eligible_branches[0] = "ECE";
                companies[i].eligible_branches[1] = "EEE";
                companies[i].eligible_branches[2] = "ME";
                companies[i].eligible_branches[3] = "EP";
                companies[i].eligible_branches[4] = "EnE";
                companies[i].eligible_branches[5] = "CL";
                companies[i].eligible_branches[6] = "CE";
            }
            if(companies[i].name_company == "Reliance Industries" || companies[i].name_company == "Lupin Ltd")
            {
                companies[i].eligible_branches[7] = "CST";
                companies[i].eligible_branches[8] = "BSBE";
            }
            if(companies[i].name_company == "Mercedes" || companies[i].name_company == "Texas Instruments")
            {
                companies[i].eligible_branches[0] = "EEE";
                companies[i].eligible_branches[1] = "ME";
                companies[i].eligible_branches[2] = "EP";
                companies[i].eligible_branches[3] = "CST";
                companies[i].eligible_branches[4] = "BSBE";
            }
            if(companies[i].name_company == "Samsung")
            {
                companies[i].eligible_branches[0] = "ECE";
                companies[i].eligible_branches[1] = "EEE";
                companies[i].eligible_branches[2] = "ME";
                companies[i].eligible_branches[3] = "EP";
            }
        }
        if(companies[i].type == "Consulting")
        {
            companies[i].njobs = 2;
            companies[i].jobs[0].title = "Business Analsyt";
            companies[i].jobs[1].title = "Marketing Manager";
            for(int j = 0; j < JOB_COUNT; j++)
            {
                companies[i].accepted[j] = "False";
                
            }
            if(companies[i].name_company == "Boston Consulting Group")
            {
                companies[i].jobs[0].ctc = 4850000.0;
                companies[i].jobs[1].ctc = 6400000.0;
            }
            if(companies[i].name_company == "McKinsey & Company")
            {
                companies[i].jobs[0].ctc = 5600000.0;
                companies[i].jobs[1].ctc = 5800000.0;	
            }
            companies[i].eligible_branches[0] = "CSE";
            companies[i].eligible_branches[1] = "DSAI";
            companies[i].eligible_branches[2] = "MnC";
            if(companies[i].name_company == "Boston Consulting Group")
            {
                companies[i].eligible_branches[3] = "ECE";
            }
            if(companies[i].name_company == "McKinsey & Company")
            {
                companies[i].eligible_branches[3] = "ECE";
                companies[i].eligible_branches[4] = "ME";
                companies[i].eligible_branches[5] = "EP";
                companies[i].eligible_branches[6] = "EnE";
                companies[i].eligible_branches[7] = "CL";
                companies[i].eligible_branches[8] = "CE";
                
            }
        }
    }

}
void Company :: display_company_details()
{
	string name_company;
	int year_founded;
	int njobs;
	string type;
	char tier;
	bool accepted[JOB_COUNT]; 
	job jobs[JOB_COUNT];
	string eligible_branches[BRANCH_COUNT];
	for(int i = 0; i < COMPANY_COUNT; i++)
	{
		cout << "Name: " << companies[i].name_company <<endl;
		cout << "Year of founding: " << companies[i].year_founded <<endl;
		cout << "Number of jobs available: " << companies[i].njobs <<endl;
		cout << "Type: " << companies[i].type <<endl;
		cout << "Company Tier: " << companies[i].tier <<endl;
		for(int j = 0; j < companies[i].njobs; j++)
		{
			cout << "Job Title: " << companies[i].jobs[j].title <<endl;
			cout << "CTC: " << companies[i].jobs[j].ctc <<endl;
		}
		cout << "Branches eligible for the job:\n";
		for(int k = 0; k < BRANCH_COUNT; k++)
		{
			if(companies[i].eligible_branches[k] != "")
			{
				cout << k+1 << "." << companies[i].eligible_branches[k] <<endl;
			}
			
		}
		cout << "\n";
	}
}