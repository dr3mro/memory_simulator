# Computer Science 305 - Assignment 1: Solving Memory Management Problems

## Overview
This project asks you to emulate how an operating system manages memory paging, allocation, deallocation, and replacement. The assignment focuses on comparing allocation strategies and analyzing how memory state changes over time.

## Goals
- Describe how operating systems manage memory.
- Use code to emulate basic operating system memory behavior.
- Compare different memory allocation scenarios.
- Determine which strategy is most effective for the provided jobs.

## Project Requirements
1. Show the memory state for the different scenarios in the tables below and analyze which choice is the best.
2. Discuss the impact that Linux versus Windows might have on the ending memory state.
3. Run the job list using the specified memory settings.
4. Test three allocation scenarios:
   - Best-Fit
   - First-Fit
   - Worst-Fit

## Memory Settings
- Total memory size: 20 KB
- Page size: 1 KB
- An interval is measured in seconds

## Job List 1
| Job ID | Start Time | Job Required Size | Execution Interval | Job State at End |
| --- | --- | --- | --- | --- |
| 1 | 1 | 2 | 7 | End |
| 2 | 2 | 3 | 8 | Sleep |
| 3 | 3 | 4 | 6 | End |
| 4 | 4 | 3 | 6 | Sleep |
| 5 | 5 | 2 | 9 | Sleep |
| 6 | 6 | 3 | 6 | Sleep |
| 7 | 7 | 2 | 6 | Sleep |

## Job List 2
These jobs are used for the three allocation scenarios.

| Job ID | Start Time | Job Required Size | Execution Interval | Job State at End |
| --- | --- | --- | --- | --- |
| 8 | 8 | 3 | 4 | Sleep |
| 9 | 9 | 5 | 5 | Sleep |
| 10 | 10 | 2 | 8 | Sleep |
| 11 | 11 | 4 | 6 | End |
| 12 | 12 | 6 | 5 | Sleep |
| 2 | 13 | 3 | 6 | End |
| 4 | 13 | 3 | 4 | Sleep |
| 13 | 13 | 5 | 3 | End |
| 7 | 13 | 2 | 3 | End |
| 9 | 17 | 4 | 4 | Sleep |
| 10 | 19 | 2 | 11 | End |
| 6 | 19 | 3 | 6 | End |
| 5 | 20 | 2 | 10 | Sleep |
| 4 | 21 | 3 | 12 | Sleep |
| 12 | 22 | 6 | 13 | End |
| 8 | 22 | 3 | 9 | End |
| 9 | 28 | 5 | 11 | End |
| 5 | 33 | 2 | 3 | Sleep |
| 4 | 34 | 3 | 10 | End |
| 5 | 38 | 2 | 10 | End |

## Tips From the Assignment
- Write a program that simulates how an operating system cycles jobs to complete them quickly.
- Copy the two tables into a text file if you want to use them as program input.
- Use a language such as Java, C++, Python, or another language you prefer.
- Include a function that queues each job with:
  - start time
  - job size
  - execution interval
  - state at the end of the interval
- Continue the simulation until all jobs are complete.
- Use allocation, deallocation, and replacement concepts in the implementation.

## Submission Format
Submit one of the following:
- A `.txt` file
- A link to cloud storage containing the work

If using a cloud link, make sure the sharing settings allow anyone with the link to view it.

## Grading Summary
The rubric evaluates:
- Efficiency of solutions
- Testing three different scenarios
- Use of allocation, deallocation, and replacement functions
- Matching the chosen scenario with the correct functions
- Completeness and correctness of the test case

## Notes
- The assignment states that AI may be used to support your process with proper documentation, but it may not create or write any part of the project for you.
- Projects that violate the AI policy may receive an academic integrity violation.
