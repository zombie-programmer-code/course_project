#ifndef UTILITY_H
#define UTILITY_H
#include "company_details.h"
#include "linkedl.h"
#include "student_details.h"
void prelim_1(Company c, student_list &sl);
void view_rd1_results(Company c, student_list sl);
void interview(Company c, student_list &sl);
void total_score_calculation(Company c, student_list &sl);
void view_total_score(Company c, student_list &sl);
void final_results(Company &c, student_list &sl);
void view_final_results(Company c, student_list &sl);
void company_employees(Company c, student_list &sl);
void final_placement_statistics(Company c, student_list &sl);
void driver_function(Company c, student_list &sl);

#endif