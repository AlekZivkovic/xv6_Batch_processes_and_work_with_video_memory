#  <p align="center"> Operative Systems H3 </p>

<p align="center"> Batch processes and work with video memory </p>

The goal of the homework is to modify the xv6 system to support the following functionalities:

- Start a batch of jobs, with a limit on access.
- Access video memory directly from user space.

The following system calls and user programs need to be implemented:

- System calls:
  - int start\_batch(job \*jobs, int n);
- User programs:
  - print\_str
  - batch\_test
  - video\_test

For all user programs, all parameters are optional and can be listed in any order.

## Batch jobs with precedence

It is necessary to introduce support for starting a process group using the new system call start\_batch (). One batch at a time will be active throughout the system. Batch can have a maximum of 64 jobs. The system call start\_batch () will accept as an argument a series of job structures that describe one process to be started, as well as the length of that string. Each job has the following attributes:

- Unique ID (int id)
- Predecessor ID (int pred\_id)
- Program name (char prog[32])
- Command line arguments (char argv[8][32])

Jobs within the batch should be described using a job structure that will be part of the kernel, but can also be included using the include directive in the user program that wants to start the batch.

Jobs within the batch are organized into a forest of precedence. Each batch job can have zero or more followers, as well as zero or one predecessor. When starting the batch, the system automatically starts all jobs that have no predecessors (pred\_id == -1). After the completion of each of these tasks, all his followers should start. It is expected that the forerunner forest will be organized meaningfully by the user program (there will certainly be at least one job without a predecessor, there will be no jobs with predecessors that do not exist, etc.).

The process that triggered the batch should be the parent of all processes within the batch. He is expected to do as much of this process wait()alls how many jobs there are in the batch. System call wait() it should be changed so that when the process that is part of a batch is completed, it should be checked whether there are any follower jobs in that batch, and if there are, then they should be started. Use the same to start all these jobs fork() / exec() logic as when starting ordinary processes, with the proviso that it is allowed to write new functions that perform the necessary task. There is no need to report errors when starting these processes.

##


## Batch system testing

To test the execution of the batch system, it is necessary to write two user programs - one that will be part of the batch (print\_str), and others who will start the batch (batch\_test).

## print\_str

User program print\_str takes two arguments on the command line: the time specified in the operating system ticks, and the string to be printed. The default values are 100 ticks and a string &quot;test&quot;. The program works by first blocking the specified time, and then printing the specified string on the console. The options for this program are as follows:

- --help (-h) prints the help menu.
- --ticks (-t) sets the time to block.
- --str (-s) sets the print string.

## batch\_test

User program batch\_test should not take any arguments on the command line. This program needs to perform two batch, to show that the system is properly implemented. The following two tables list what the two batch to run should look like:

 <p align="center"> Batch 1 </p>
 <p>| id | pred\_id |  prog      |     argv </p>                                      
 <p>| 0  | -1       |  print_str | print_str -t 100 -s first </p>                
 <p>| 1  | -1       |  print_str | print_str -t 200 -s second </p>               
 <p>| 2  |  1       |  print_str | print_str -t 100 -s third </p>                

<p align="center"> Batch 2 </p>

| id | pred\_id | prog        | argv                                    |
| 0  | -1       | print\_str | print\_str -s first                      |
| 1  |  0       | print\_str | print\_str -s second                     |
| 2  |  0       | print\_str | print\_str -s third -t 200               |
| 3  | 2         | print\_str | print\_str -s fourth                    |

## Video memory in user space

It is necessary to enable direct work with video memory in the user space. All user processes should have video memory mapped to their zero page, ie. video memory will start in the user space from the virtual address 0x0. Once the task is done correctly, it should be possible to write a user program video\_test, which will illustrate that this part of the task was done correctly.

## video\_test

This program displays the specified string in the specified color at the specified position on the screen, using mapped video memory in the user space. The default values are the text &quot;hello world&quot;, with yellow letters on a blue background, in the upper left corner of the screen. The options for this program are:

- --help (-h) prints the help menu.
- --str (-s) sets the text to be printed.
- --row (-r) sets the order in which the text should be printed.
- --col (-c) sets the column in which the text should be printed.
- --fg sets the font color for text as a one-digit hex number.
- --bg sets the background color for text as a one-digit hex number.

##

