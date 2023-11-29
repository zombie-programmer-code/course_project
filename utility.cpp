#include "utility.h"
#include "student_details.h"
#include "linkedl.h"
#include "company_details.h"

void prelim_1(Company c, student_list &sl)
{
	srand(time(NULL));
	for(int i = 0; i < COMPANY_COUNT; i++)
	{
		for(int k = 0; k < STUDENT_COUNT; k++)
		{
			if(c.companies[i].type == "Tech")
			{
				for(int j = 0; j < TECH; j++)
				{
					if(sl.s[k].tech[j] == true)
					{
						sl.s[k].coding_rd1[j][0] = rand() % 100;
						sl.s[k].coding_rd1[j][1] = rand() % 100;
						sl.s[k].coding_rd1[j][2] = rand() % 100;
					}
					else
					{
						sl.s[k].coding_rd1[j][0] = -1;
						sl.s[k].coding_rd1[j][1] = -1;
						sl.s[k].coding_rd1[j][2] = -1;
					}
				}
				
			}
			if(c.companies[i].type == "Core")
			{
				for(int j = 0; j < CORE; j++)
				{
					if(sl.s[k].core[j] == true)
					{
						sl.s[k].w_test[j] = rand() % 100;
					}
					else
					{
						sl.s[k].w_test[j] = -1;
					}
				}
				
			}
			if(c.companies[i].type == "Finance")
			{
				for(int j = 0; j < FINANCE; j++)
				{
					if(sl.s[k].finance[j] == true)
					{
						sl.s[k].math_written[j][0] = rand() % 100;
						sl.s[k].math_written[j][1] = rand() % 100;
					}
					else
					{
						sl.s[k].math_written[j][0] = -1;
						sl.s[k].math_written[j][1] = -1;
					}
				}
				
			}
			if(c.companies[i].type == "Consulting")
			{
				for(int j = 0; j < CONSULTING; j++)
				{
					if(sl.s[k].consulting[j] == true)
					{
						sl.s[k].a_rd[j][0] = rand() % 100;
						sl.s[k].a_rd[j][1] = rand() % 100;
					}
					else
					{
						sl.s[k].a_rd[j][0] = -1;
						sl.s[k].a_rd[j][1] = -1;
					}
				}
				
			}
		}
		
	}

}
void view_rd1_results(Company c, student_list sl)
{
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << "First round results for: " << sl.s[i].rollno <<endl;
		cout << "Tech companies:\n";
		for(int j = 0; j < TECH; j++)
		{
			if(sl.s[i].tech[j] == true)
			{
				cout << "Company name: " << c.companies[j].name_company << "\n" << c.companies[j].jobs[0].title << ": " << sl.s[i].coding_rd1[j][0] <<endl;
				cout << "Company name: " << c.companies[j].name_company << "\n" << c.companies[j].jobs[1].title << ": " << sl.s[i].coding_rd1[j][1] <<endl;
				cout << "Company name: " << c.companies[j].name_company << "\n" << c.companies[j].jobs[2].title << ": " << sl.s[i].coding_rd1[j][2] <<endl;
			}
		}
		cout << "Core companies:\n";
		for(int j = 0; j < CORE; j++)
		{
			if(sl.s[i].core[j] == true)
			{
				cout << "Company name: " << c.companies[j+7].name_company << "\n" << c.companies[j+7].jobs[0].title << ": " << sl.s[i].w_test[j] <<endl;
			}
		}
		cout << "Finance companies:\n";
		for(int j = 0; j < FINANCE; j++)
		{
			if(sl.s[i].finance[j] == true)
			{
				cout << "Company name: " << c.companies[j+4].name_company << "\n" << c.companies[j+4].jobs[0].title << ": " << sl.s[i].math_written[j][0] <<endl;
				cout << "Company name: " << c.companies[j+4].name_company << "\n" << c.companies[j+4].jobs[1].title << ": " << sl.s[i].math_written[j][1] <<endl;
			}
		}
		cout << "Consulting companies:\n";
		for(int j = 0; j < CONSULTING; j++)
		{
			if(sl.s[i].consulting[j] == true)
			{
				cout << "Company name: " << c.companies[j+13].name_company << "\n" << c.companies[j+13].jobs[0].title << ": " << sl.s[i].a_rd[j][0] <<endl;
				cout << "Company name: " << c.companies[j+13].name_company << "\n" << c.companies[j+13].jobs[1].title << ": " << sl.s[i].a_rd[j][1] <<endl;
			}
		}
	}
}
void interview(Company c, student_list &sl)
{
	std::array<std::queue<student>, STUDENT_COUNT> qjobs;
	int count = -1;
	for(int i = 0; i < COMPANY_COUNT; i++)
	{
		for(int j = 0; j < c.companies[i].njobs; j++)
		{
			count++;
			cout << "Top five scorers for " << c.companies[i].jobs[j].title << " in " << c.companies[i].name_company << " are:\n";
			for(int k = 0; k < STUDENT_COUNT; k++)
			{
				for(int l = 0; l < STUDENT_COUNT-1-k; l++)
				{
					if(c.companies[i].type == "Tech")
					{
						if(sl.s[l].coding_rd1[i][j] < sl.s[l+1].coding_rd1[i][j])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
					if(c.companies[i].type == "Finance")
					{
						if(sl.s[l].math_written[i-4][j] < sl.s[l+1].math_written[i-4][j])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
					if(c.companies[i].type == "Core")
					{
						if(sl.s[l].w_test[i-7] < sl.s[l+1].w_test[i-7])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
					if(c.companies[i].type == "Consulting")
					{
						if(sl.s[l].a_rd[i-13][j] < sl.s[l+1].a_rd[i-13][j])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
				}
			}
			for(int a = 0; a < STUDENT_COUNT; a++)
			{
				if(a < 5)
				{
					if(c.companies[i].type == "Tech")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Score: " << sl.s[a].coding_rd1[i][j] <<endl;
					}
					if(c.companies[i].type == "Finance")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Score: " << sl.s[a].math_written[i-4][j] <<endl;
					}
					if(c.companies[i].type == "Core")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Score: " << sl.s[a].w_test[i-7] <<endl;
					}
					if(c.companies[i].type == "Consulting")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Score: " << sl.s[a].a_rd[i-13][j] <<endl;
					}
					qjobs[count].push(sl.s[a]);
				}
				else
				{
					if(c.companies[i].type == "Tech")
					{
						sl.s[a].interview_coding[i][j] = 0;
					}
					if(c.companies[i].type == "Finance")
					{
						sl.s[a].interview_finance[i-4][j] = 0;
					}
					if(c.companies[i].type == "Core")
					{
						sl.s[a].interview_core[i-7] = 0;
					}
					if(c.companies[i].type == "Consulting")
					{
						sl.s[a].interview_consulting[i-13][j] = 0;
					}
				}
			}
			
		}
	}
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			student temp = qjobs[i].front();
			if(i < 12)
			{
				for(int k = 0; k < STUDENT_COUNT; k++)
				{
					if(temp.rollno == sl.s[k].rollno)
					{
						sl.s[k].interview_coding[i/3][i%3] = rand() % 100;
					}
				}
			}
			if(i >= 12 && i <= 17)
			{
				for(int k = 0; k < STUDENT_COUNT; k++)
				{
					if(temp.rollno == sl.s[k].rollno)
					{
						sl.s[k].interview_finance[(i/2)-6][i%2] = rand() % 100;
					}
				}
			}
			if(i >= 18 && i <= 23)
			{
				for(int k = 0; k < STUDENT_COUNT; k++)
				{
					if(temp.rollno == sl.s[k].rollno)
					{
						sl.s[k].interview_core[i-18] = rand() % 100;
					}
				}
			}
			if(i >= 24 && i <= 27)
			{
				for(int k = 0; k < STUDENT_COUNT; k++)
				{
					if(temp.rollno == sl.s[k].rollno)
					{
						sl.s[k].interview_consulting[(i/2)-12][i % 2] = rand() % 100;
					}
				}
			}
			qjobs[i].pop();
		}
		
	}
}
void total_score_calculation(Company c, student_list &sl)
{
	for(int a = 0; a < STUDENT_COUNT; a++)
	{
		for(int i = 0; i < COMPANY_COUNT; i++)
	{
		if(c.companies[i].type == "Tech")
		{
			for(int j = 0; j < TECH; j++)
			{
				for(int k = 0; k < c.companies[i].njobs; k++)
				{
					sl.s[a].fs_tech[j][k] = 0.045*sl.s[a].coding_rd1[j][k]+0.045*sl.s[a].interview_coding[j][k]+0.1*sl.s[a].CPI;
				}
				
			}
		}
		if(c.companies[i].type == "Finance")
		{
			for(int j = 0; j < FINANCE; j++)
			{
				for(int k = 0; k < c.companies[i].njobs; k++)
				{
					sl.s[a].fs_finance[j][k] = 0.04*sl.s[a].math_written[j][k]+0.04*sl.s[a].interview_finance[j][k]+0.2*sl.s[a].CPI;
				}
				
			}
		}
		if(c.companies[i].type == "Core")
		{
			for(int j = 0; j < CORE; j++)
			{
				
				sl.s[a].fs_core[j] = 0.05*sl.s[a].w_test[j]+0.04*sl.s[a].interview_core[j]+0.1*sl.s[a].CPI;
				
			}
		}
		if(c.companies[i].type == "Consulting")
		{
			for(int j = 0; j < CONSULTING; j++)
			{
				for(int k = 0; k < c.companies[i].njobs; k++)
				{
					sl.s[a].fs_consulting[j][k] = 0.035*sl.s[a].a_rd[j][k]+0.05*sl.s[a].interview_consulting[j][k]+0.15*sl.s[a].CPI;
				}
				
			}
		}
		
		
	}
	}
	
	
}
void view_total_score(Company c, student_list &sl)
{
	for(int i = 0; i < COMPANY_COUNT; i++)
	{
		for(int j = 0; j < c.companies[i].njobs; j++)
		{
			for(int k = 0; k < STUDENT_COUNT; k++)
			{
				if(c.companies[i].type == "Tech")
				{
					cout << "Roll no: " << sl.s[k].rollno <<endl;
					cout << "CPI: " << sl.s[k].CPI <<endl;
					cout << "Coding Rd1 Score(out of 100) :" << sl.s[k].coding_rd1[i][j] <<endl;
					cout << "Interview Score(out of 100): " << sl.s[k].interview_coding[i][j] <<endl;
					cout << "Total Score(out of 10): " << sl.s[k].fs_tech[i][j] << endl;
				}
				if(c.companies[i].type == "Finance")
				{
					cout << "Roll no: " << sl.s[k].rollno <<endl;
					cout << "CPI: " << sl.s[k].CPI <<endl;
					cout << "Written Math Test Score(out of 100) :" << sl.s[k].math_written[i-4][j] <<endl;
					cout << "Interview Score(out of 100): " << sl.s[k].interview_finance[i-4][j] <<endl;
					cout << "Total Score(out of 10): " << sl.s[k].fs_finance[i-4][j] << endl;
				}
				if(c.companies[i].type == "Core")
				{
					cout << "Roll no: " << sl.s[k].rollno <<endl;
					cout << "CPI: " << sl.s[k].CPI <<endl;
					cout << "Wriiten Test Score(out of 100) :" << sl.s[k].w_test[i-7] <<endl;
					cout << "Interview Score(out of 100): " << sl.s[k].interview_core[i-7] <<endl;
					cout << "Total Score(out of 10): " << sl.s[k].fs_core[i-7] << endl;
				}
				if(c.companies[i].type == "Consulting")
				{
					cout << "Roll no: " << sl.s[k].rollno <<endl;
					cout << "CPI: " << sl.s[k].CPI <<endl;
					cout << "Written Analytics Test Score(out of 100) :" << sl.s[k].a_rd[i-13][j] <<endl;
					cout << "Interview Score(out of 100): " << sl.s[k].interview_consulting[i-13][j] <<endl;
					cout << "Total Score(out of 10): " << sl.s[k].fs_consulting[i-13][j] << endl;
				}
				
			}
		}
	}
}
void view_final_results(Company c, student_list &sl)
{
	int count = -1;
	std::array<std::queue<student>, STUDENT_COUNT> fjobs;
	student top5_fs[STUDENT_COUNT][5];
	for(int i = 0; i < COMPANY_COUNT; i++)
	{
		for(int j = 0; j < c.companies[i].njobs; j++)
		{
			count++;
			cout << "Top 5 scorers for " << c.companies[i].jobs[j].title << " in " << c.companies[i].name_company << " are:\n";
			for(int k = 0; k < STUDENT_COUNT; k++)
			{
				for(int l = 0; l < STUDENT_COUNT-1-k; l++)
				{
					if(c.companies[i].type == "Tech")
					{
						if(sl.s[l].fs_tech[i][j] < sl.s[l+1].fs_tech[i][j])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
					if(c.companies[i].type == "Finance")
					{
						if(sl.s[l].fs_finance[i-4][j] < sl.s[l+1].fs_finance[i-4][j])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
					if(c.companies[i].type == "Core")
					{
						if(sl.s[l].fs_core[i-7] < sl.s[l+1].fs_core[i-7])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
					if(c.companies[i].type == "Consulting")
					{
						if(sl.s[l].fs_consulting[i-13][j] < sl.s[l+1].fs_consulting[i-13][j])
						{
							student temp = sl.s[l];
							sl.s[l] = sl.s[l+1];
							sl.s[l+1] = temp;
						}
					}
				}
			}
			for(int a = 0; a < STUDENT_COUNT; a++)
			{
				if(a < 5)
				{
					if(c.companies[i].type == "Tech")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Final Score: " << sl.s[a].fs_tech[i][j] <<endl;
					}
					if(c.companies[i].type == "Finance")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Final Score: " << sl.s[a].fs_finance[i-4][j] <<endl;
					}
					if(c.companies[i].type == "Core")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Final Score: " << sl.s[a].fs_core[i-7] <<endl;
					}
					if(c.companies[i].type == "Consulting")
					{
						cout << (a+1) << "." << " Roll no: " << sl.s[a].rollno << " Final Score: " << sl.s[a].fs_consulting[i-13][j] <<endl;
					}
					fjobs[count].push(sl.s[a]);
					top5_fs[count][a] = sl.s[a];
				}
				else
				{
					if(c.companies[i].type == "Tech")
					{
						sl.s[a].fs_tech[i][j] = 0;
					}
					if(c.companies[i].type == "Finance")
					{
						sl.s[a].fs_finance[i-4][j] = 0;
					}
					if(c.companies[i].type == "Core")
					{
					    sl.s[a].fs_core[i-7] = 0;
					}
					if(c.companies[i].type == "Consulting")
					{
						sl.s[a].fs_consulting[i-13][j] = 0;
					}
				}
			}
			
		}
	}
	
	float max = 0.0;
	int com = 0;
	int nj = 0;
	float ctc_o = 0.0;
	float m = 0.0;
	int iterations = 10;
	int co = 0;
	int temp = 0;
	sl.sort_student_CPI();
	int count1 = 0;
	int d = 0;
	int changed = 0;
	while(d < iterations)
	{
		changed = 0;
		for(int i = 0; i < STUDENT_COUNT; i++)
		{
			if(sl.s[i].placed == true)
			{
				continue;
			}
			count1 = 0;
			com = -1;
			nj = -1;
			max = 0;
			for(int j = 0; j < STUDENT_COUNT; j++)
			{
				if(sl.s[i].rollno == top5_fs[j][0].rollno && count1 == 0)
				{
					if(j <= 11)
					{
						max = c.companies[j/3].jobs[j%3].ctc;
						m = c.companies[j/3].jobs[j%3].ctc;
						com = j/3;
						nj = j%3;
						temp = j;
					}
					else if(j >= 12 && j <= 17)
					{
						max = c.companies[(j-4)/2].jobs[j%2].ctc;
						m = c.companies[(j-4)/2].jobs[j%2].ctc;
						com = (j-4)/2;
						nj = j % 2;
						temp = j;
					}
					else if(j >= 18 && j <= 23)
					{
						max = c.companies[j-11].jobs[0].ctc;
						m = c.companies[j-11].jobs[0].ctc;
						com = j-11;
						nj = 0;
						temp = j;
					}
					else
					{
						max = c.companies[(j+2)/2].jobs[j%2].ctc;
						m = c.companies[(j+2)/2].jobs[j%2].ctc;
						com = (j+2)/2;
						nj = j % 2;
						temp = j;
					}
					count1++;
				}
				else if(sl.s[i].rollno == top5_fs[j][0].rollno && count1 != 0)
				{
					if(j <= 11)
					{
						ctc_o = c.companies[j/3].jobs[j%3].ctc;
						if(ctc_o > max)
						{
							max = ctc_o;
							com = j/3;
							nj = j%3;
							temp = j;
						}
					}
					else if(j >= 12 && j <= 17)
					{
						ctc_o = c.companies[(j-4)/2].jobs[j%2].ctc;
						if(ctc_o > max)
						{
							max = ctc_o;
							com = (j-4)/2;
							nj = j % 2;
							temp = j;
						}
					}
					else if(j >= 18 && j <= 23)
					{
						ctc_o = c.companies[j-11].jobs[0].ctc;
						if(ctc_o > max)
						{
							max = ctc_o;
							com = j-11;
							nj = 0;
							temp = j;
						}
					}
					else
					{
						ctc_o = c.companies[(j+2)/2].jobs[j%2].ctc;
						if(ctc_o > max)
						{
							max = ctc_o;
							com = (j+2)/2;
							nj = j % 2;
							temp = j;
						}
					}
					count1++;
				}
			}
			
			if(com != -1)
			{
				changed++;
				sl.s[i].placed = true;
				sl.s[i].company_name = c.companies[com].name_company;
				sl.s[i].ctc = c.companies[com].jobs[nj].ctc;
				sl.s[i].job_title = c.companies[com].jobs[nj].title;
				for(int a = 0; a < STUDENT_COUNT; a++)
				{
					for(int b = 0; b < 5; b++)
					{
						if(a != temp && top5_fs[a][b].rollno == sl.s[i].rollno)
						{
							for(int x = b; x < 4; x++)
							{
								top5_fs[a][x] = top5_fs[a][x+1];
							}
							top5_fs[a][4].rollno = -1;
						}
					}
				}
				
				
			}
			else
			{
				sl.s[i].company_name = "Not placed yet";
			}

			
		}
		
		d++;
		if(changed == 0)
		{
			break;
		}
	}
	
	
}
void final_results(Company &c, student_list &sl)
{
	int p = 0;
	cout << "Final Placement results:\n";
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		if(sl.s[i].company_name != "Not placed yet")
		{
			cout << sl.s[i].rollno <<endl;
			cout << sl.s[i].CPI <<endl;
			cout << sl.s[i].placed <<endl;
			cout << sl.s[i].company_name <<endl;
			cout << sl.s[i].job_title <<endl;
			cout << sl.s[i].ctc <<endl;
			if(sl.s[i].company_name == "Microsoft")
			{
				sll_insert(&c.head[0], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Google")
			{
				sll_insert(&c.head[1], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Amazon")
			{
				sll_insert(&c.head[2], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Meta")
			{
				sll_insert(&c.head[3], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Goldman Sachs")
			{
				sll_insert(&c.head[4], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "JP Morgan")
			{
				sll_insert(&c.head[5], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Jane Street")
			{
				sll_insert(&c.head[6], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Larsen & Toubro")
			{
				sll_insert(&c.head[7], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Reliance Industries")
			{
				sll_insert(&c.head[8], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Mercedes")
			{
				sll_insert(&c.head[9], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Texas Instruments")
			{
				sll_insert(&c.head[10], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Samsung")
			{
				sll_insert(&c.head[11], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Lupin Ltd")
			{
				sll_insert(&c.head[12], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "Boston Consulting Group")
			{
				sll_insert(&c.head[13], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
			if(sl.s[i].company_name == "McKinsey & Company")
			{
				sll_insert(&c.head[14], sl.s[i].rollno, sl.s[i].branch, sl.s[i].branch_code, sl.s[i].job_title, sl.s[i].ctc);
			}
		}
		else
		{
			p++;
		}

	}
	cout << "No of people not placed yet:" << p <<endl;
}
void company_employees(Company c, student_list &sl)
{
	int sum = 0;
	for(int i = 0; i < COMPANY_COUNT; i++)
	{
		if(c.head[i] != nullptr)
		{
			
			cout << c.companies[i].name_company <<endl;
			node *curr = c.head[i];
			int t = 1;
			while(curr != nullptr)
			{
				cout << "Job " << t <<endl;
				cout << "Roll no: " << curr -> rollno <<endl;
				cout << "Branch: " << curr -> branch <<endl;
				cout << "Branch code: " << curr -> branch_code <<endl;
				cout << "Job Title: " << curr->job_title <<endl;
				cout << "CTC: " << curr-> ctc <<endl;
				curr = curr -> next;
				t++;
			}
			sum = sum + t-1;
		}
	}
	cout << "Total number of jobs offered: " << sum << endl;
}
void final_placement_statistics(Company c, student_list &sl)
{
	sl.sort_by_branch_and_CPI();
	float avg_ctc[12];
	int num_students[12];
	float num_students_total[12];
	float max_ctc[12];
	string branches[12];
	float placement_rate[12];
	branches[0] = "CSE";
	branches[1] = "DSAI";
	branches[2] = "MnC";
	branches[3] = "ECE";
	branches[4] = "EEE";
	branches[5] = "ME";
	branches[6] = "EP";
	branches[7] = "EnE";
	branches[8] = "CL";
	branches[9] = "CE";
	branches[10] = "CST";
	branches[11] = "BSBE";

	for(int i = 0; i < 12; i++)
	{
		avg_ctc[i] = 0.0;
		num_students[i] = 0;
		max_ctc[i] = 0.0;

	}
	for(int i = 0; i < STUDENT_COUNT; i++)
	{
		if(sl.s[i].placed == true)
		{
			if(sl.s[i].branch=="CSE")
			{
				avg_ctc[0] += sl.s[i].ctc;
				if(max_ctc[0] < sl.s[i].ctc)
				{
					max_ctc[0] = sl.s[i].ctc;
				}
				num_students[0] += 1;
				num_students_total[0] = 3;
			}
			else if(sl.s[i].branch == "DSAI")
			{
				avg_ctc[1] += sl.s[i].ctc;
				if(max_ctc[1] < sl.s[i].ctc)
				{
					max_ctc[1] = sl.s[i].ctc;
				}
				num_students[1] += 1;
				num_students_total[1] = 2;
			}
			else if(sl.s[i].branch == "MnC")
			{
				avg_ctc[2] += sl.s[i].ctc;
				if(max_ctc[2] < sl.s[i].ctc)
				{
					max_ctc[2] = sl.s[i].ctc;
				}
				num_students[2] += 1;
				num_students_total[2] = 3;
			}	
			else if(sl.s[i].branch == "ECE")
			{
				avg_ctc[3] += sl.s[i].ctc;
				if(max_ctc[3] < sl.s[i].ctc)
				{
					max_ctc[3] = sl.s[i].ctc;
				}
				num_students[3] += 1;
				num_students_total[3] = 3;
			}
			else if(sl.s[i].branch == "EEE")
			{
				avg_ctc[4] += sl.s[i].ctc;
				if(max_ctc[4] < sl.s[i].ctc)
				{
					max_ctc[4] = sl.s[i].ctc;
				}
				num_students[4] += 1;
				num_students_total[4] = 3;
			}
			else if(sl.s[i].branch == "ME")
			{
				avg_ctc[5] += sl.s[i].ctc;
				if(max_ctc[5] < sl.s[i].ctc)
				{
					max_ctc[5] = sl.s[i].ctc;
				}
				num_students[5] += 1;
				num_students_total[5] = 2;
			}
			else if(sl.s[i].branch == "EP")
			{
				avg_ctc[6] += sl.s[i].ctc;
				if(max_ctc[6] < sl.s[i].ctc)
				{
					max_ctc[6] = sl.s[i].ctc;
				}
				num_students[6] += 1;
				num_students_total[6] = 2;
			}
			else if(sl.s[i].branch == "EnE")
			{
				avg_ctc[7] += sl.s[i].ctc;
				if(max_ctc[7] < sl.s[i].ctc)
				{
					max_ctc[7] = sl.s[i].ctc;
				}
				num_students[7] += 1;
				num_students_total[7] = 1;
			}
			else if(sl.s[i].branch == "CL")
			{
				avg_ctc[8] += sl.s[i].ctc;
				if(max_ctc[8] < sl.s[i].ctc)
				{
					max_ctc[8] = sl.s[i].ctc;
				}
				num_students[8] += 1;
				num_students_total[8] = 2;
			}
			else if(sl.s[i].branch == "CE")
			{
				avg_ctc[9] += sl.s[i].ctc;
				if(max_ctc[9] < sl.s[i].ctc)
				{
					max_ctc[9] = sl.s[i].ctc;
				}
				num_students[9] += 1;
				num_students_total[9] = 3;
			}
			else if(sl.s[i].branch == "CST")
			{
				avg_ctc[10] += sl.s[i].ctc;
				if(max_ctc[10] < sl.s[i].ctc)
				{
					max_ctc[10] = sl.s[i].ctc;
				}
				num_students[10] += 1;
				num_students_total[10] = 2;
			}
			else
			{
				avg_ctc[11] += sl.s[i].ctc;
				if(max_ctc[11] < sl.s[i].ctc)
				{
					max_ctc[11] = sl.s[i].ctc;
				}
				num_students[11] += 1;
				num_students_total[11] = 2;
			}

		}
	}
	for(int i = 0; i < 12; i++)
	{
		if(num_students[i] != 0)
		{
			avg_ctc[i] /= num_students[i];
		}
		else
		{
			avg_ctc[i] = 0.0;
		}
		
	}
	cout << "Branch-wise statistics:\n";
	for(int i = 0; i < 12; i++)
	{
		cout << "Average CTC for " << branches[i] <<  " is : " << avg_ctc[i] <<endl;
		cout << "Maximum CTC for " << branches[i] <<  " is : " << max_ctc[i] <<endl;
		cout << "Placement Rate for " << branches[i] << " is : " << (num_students[i]/num_students_total[i])*100 << "%" << endl;
	}
}
void driver_function(Company c, student_list &sl)
{
	sl.student_eligibility();
	char choice = 'Y';
	while(choice == 'Y')
	{
		cout << "Enter 1 to view the list of students sorted by CPI:\n";
		cout << "Enter 2 to view the list of students sorted by branch and CPI\n";
		cout << "Enter 3 to view company details:\n";
		cout << "Enter 4 to carry out round 1 of the placement process:\n";
		cout << "Enter 5 to carry out round 2 of the placement process:\n";
		cout << "Enter 6 to view results after round 2:\n";
		cout << "Enter 7 to view final results of the placement process(top 5 scorers for each)\n";
		cout << "Enter 8 to view employees for each company:\n";
		cout << "Enter 9 to view final placement statistics:\n";
		int x;
		cin >> x;
		switch(x)
		{
			case 1:
			{
				cout << "List of students sorted by CPI:\n";
				sl.sort_student_CPI();
				sl.display_studentlist();
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 2:
			{
				cout << "List of students sorted by branch and CPI:\n";
				sl.sort_by_branch_and_CPI();
				sl.display_studentlist();
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 3:
			{
				c.display_company_details();
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 4:
			{
				prelim_1(c, sl);
				view_rd1_results(c, sl);
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 5:
			{
				interview(c, sl);
				total_score_calculation(c, sl);
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 6:
			{
				view_total_score(c, sl);
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 7:
			{
				view_final_results(c, sl);
				final_results(c, sl);
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 8:
			{
				company_employees(c, sl);
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			case 9:
			{
				final_placement_statistics(c, sl);
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
				break;
			}
			default:
			{
				cout << "Wrong input!\n";
				cout << "Enter N to stop the process, Y to continue:\n";
				cin >> choice;
			}
			
		} 
	
	}
}
	