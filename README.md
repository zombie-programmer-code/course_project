A Simulation of the placement procedure using Data Structures like stacks, queues, linked lists, arrays

A list of students has been pre-declared in the file student_details.cpp, along with their branch, roll number, CPI(Cumulative Performance Index) and the number of projects made by each student.
A student has been declared using a student struct, each several attributes like the ones mentioned above and some arrays to store the student's performance in the various rounds of placement for each company.
There are several class methods associated with this student struct, like display_studentlist, sort_by_branch_and_CPI etc.
Each student's eligibility for each type of company(core, tech, finance or consulting) is then declared. For example, a CSE student is eligible for all companies apart from the core companies.
A total of 15 companies have been declared in this system, with each having details like name, year of founding, type and tier mentioned. Jobs for each company type have also been initialized.
A company struct is declared for this purpose, and some class methods have also been declared.
For example: Tech companies have 3 roles: Software Developer, Software Engineer and R&D. 

The list of students can then be sorted by CPI(for which a separate method has been written, using a modified Bubble sort algorithm- the algorithm terminates if no swaps took place in the last iteration).
Another method has been written to sort the students first by their branch and then, within eah branch, by their CPI. It uses a similar logic: A modified bubble sort is used to sort the students according to their branch.
Then, the number of students for each branch is calculated and then sorting is carried out for each branch separately, where students are listed in descending order of CPI within a branch.

Next, in order to start the simulation of the process, we assign random values to each students' first(written/coding round) score if they are eligible for tha role. 
We use the rand function for this. Random initialization is done so that the process is more fair. There is a method to view the results of the first round of placement as well. In this method, 
we print out each student's first round score for all the comapnies he/she was eligible.

For the interview round, first there is an option to view the top 5 scorers in round 1 for each job type. An array of queues of type student is then defined. For each job, the top 5 scorer in the first round are pushed into the queue of students for that particular job.
This queue will make processing during the interview much easier, as interviews will be conducted only for the top 5 scorers in first round.

To simulate the interview round, we iterate over the list of jobs, then for each job, we assign a random value to the interview score of each student who was in the top 5 of the first round for that particular job(the queue here ensures that the score is assigned first for the candidate who scored the highest in the first round
Finally, for each job, the total score(based on the first round, interview round and CPI) is calculated. Different types of jobs place different weightage on each parameter, just like companies do in real life.
The weighatge has been hard-coded but in a real system, we can always take the weights as input. 

Before the final results are declared, there is an option to view the score each student has received in both the rounds and the total score, for each job type.

For the declaration of final results- that is, the assignment of jobs to students based on whether they are in the top 5 scorers, students are first sorted based on their total score.
Then the top 5 students for each job are stored in a 2D array and a queue. Finally, we carry out the placement process over 10 iterations.
Description of the placement process:
1. If the student has already been placed, we skip that student.
2. If the student has not been placed, we check if the student has the highest total score for some job. If there are multiple jobs where the student has the highest score, we assign the job with the highest CTC(among the ones the student is first in)
   to the student.
3. If the student got placed in this iteration, we remove the student from the list of the top 5 highest scorers for all the jobs where the student has got the highest score.
4. We also keep track of whether any student got placed in the current iteration- if nobody got placed in the current iteration, we stop the process immediately, as it means that no further changes in the placement can occur.

There are functions to view each company's employees and also the final placement results.
The company class has a linked list, the details of each employee of the company are stored in this list. The user can choose to view all the employees of a particular company-this is implemented
by traversing the linked list for each company, starting at the head node.
There is a function to calculate the placement statistics by branch- calculating statistics like average CTC, max CTC and placement percentage.
The driver function is the function taking user input and calling the required functions to ensure smooth working of the application.
