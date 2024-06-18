Placement Simulation System
Overview
This system leverages data structures such as stacks, queues, linked lists, and arrays to simulate the student placement process.

Key Components
Student Details
Structure: Each student is characterized by attributes such as branch, roll number, CPI, and project count.
Performance Tracking: Arrays store each student's performance across various placement rounds for different companies.
Functional Methods: Includes capabilities like display_studentlist and sort_by_branch_and_CPI.
Company Details
Structure: Attributes include the company's name, founding year, type, and tier.
Roles: Specific roles are defined for tech companies, such as Software Developer, Software Engineer, and R&D.
Total Companies: 15 companies are initialized with detailed attributes and roles.
Sorting and Eligibility
Sorting Algorithms
CPI Sorting: Utilizes a modified Bubble sort algorithm that terminates if no swaps occur in the last iteration.
Branch and CPI Sorting: A two-step sorting process first categorizes students by branch, then sorts them by CPI within each branch.
Eligibility Criteria
Branch-Based: Defines eligibility for different company types based on the student's academic branch, with specific exclusions (e.g., CSE students are ineligible for core companies).
Simulation of Placement Rounds
Initial Scoring
Random Assignment: First round scores are randomly assigned to eligible students using the rand function.
Score Viewing: Method available to view the first round scores for all eligible companies per student.
Interview Round
Top Scorers: Functionality to view the top 5 scorers in round 1 for each job type.
Queue Management: Uses queues of students for each job to facilitate the interview process efficiently.
Interview and Final Scoring
Scoring Assignment
Interview Scores: Random values are assigned to students in the top 5 for each job, with the queue ensuring that scoring starts with the highest first-round scorer.
Total Score Calculation
Weighted Scoring: Combines scores from the first round, interview round, and CPI, with different weightages applied according to job type.
Final Results and Placement Process
Result Viewing
Detailed Scores: Before declaring final results, options are available to view detailed scores for each student.
Job Assignment
Sorting and Selection: Students are sorted by total score, and the top 5 for each job are identified and stored in a 2D array and a queue.
Placement Iterations: Runs 10 iterations of the placement process, handling already placed students by removing them from the list of the top 5 highest scorers of all jobs, and assigning jobs based on highest scores.
Additional Functionalities
Company Employees
Linked List Traversal: Allows viewing all employees of a particular company by traversing its linked list.
Placement Statistics
Statistical Analysis: Calculates average CTC, max CTC, and placement percentage by branch.
System Operation
Driver Function: Manages user inputs and calls necessary functions for the smooth operation of the system.
