# Placement Simulation System Overview

Various data structures like linked lists, queues and arrays as well as different types of sorting algorithms are used in this project, including an algorithm to handle the assignment of jobs to students.

## Student and Company Structure

### Student Details
- Defined in `student_details.cpp`
- Attributes include branch, roll number, CPI, and number of projects
- Arrays to store performance in various placement rounds for each company
- Class methods for operations like `display_studentlist` and `sort_by_branch_and_CPI`

### Company Details
- Attributes include name, year of founding, type, and tier
- Specific roles for tech companies such as Software Developer, Software Engineer, and R&D
- Total of 15 companies initialized with specific job roles based on company type

## Sorting and Eligibility

### Sorting Methods
- Modified Bubble sort for sorting by CPI
- Multi-level sorting first by branch, then by CPI within each branch

### Eligibility Declaration
- Based on student’s branch, e.g., CSE students are eligible for all but core companies

## Simulation of Placement Rounds

### Initial Score Assignment
- Random values assigned to students' first round scores based on eligibility using the `rand` function

### Viewing Results
- Method available to view first round scores for all eligible companies per student

### Interview Round Preparation
- Viewing top 5 scorers in round 1 for each job type
- Queues of students set up for each job to facilitate interview process efficiently

## Interview and Final Scoring

### Scoring Assignment
- Random values are assigned to students in the top 5 for each job, with the queue ensuring that scoring starts with the highest first-round scorer

### Total Score Calculation
- Combines first round, interview round, and CPI with predetermined weightage for each

## Final Results and Placement Process

### Result Viewing
- Options to view scores from both rounds and total scores before final results

### Job Assignment
- Sort students by total score and select top 5 for each job
- Stored in a 2D array and a queue for job assignment
- 10 iterations of the placement process with conditions for already placed students and highest scoring unplaced students. If a student is already placed, them the student is removed from the list of top 5 scorers of all jobs.

## Additional Functionalities

### Company Employee Viewer
- Traverses a linked list to view all employees of a company

### Placement Statistics
- Calculates statistics like average CTC, max CTC, and placement percentage by branch

### System Operation
- Driver function manages user inputs and calls required functions for system operation
