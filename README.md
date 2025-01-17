# SIMPLE SHELL
## Plan
#### 1 - Description
#### 2 - Compilation
#### 3 - Requirements
#### 4 - Examples
#### 5 - Flowchart

## **Description**
For this project we have to recreate a simple UNIX command interpreter,

We also have a man page at the root of the repo.
## **Compilation command**
The program will be compiled with this command line :
```c
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## **Requirements**
* Allowed editors: vi, vim, emacs
* All the files will be compiled on Ubuntu 20.04 LTS using gcc
* All your files should end with a new line
* The code should use the Betty style.
* The shell should not have any memory leaks.
* No more than 5 functions per file.
* All your header files should be include guarded.
* Use system calls only when you need to

## **Examples**

In this example there is a very simple implementation of the ls command :

```c
linux@arthur:~/holbertonschool-simple_shell$ ./shell
#cisfun$ /bin/ls
AUTHORS README.md exercise man_1_simple_shell shell shell.h simple_shell_01.c
#cisfun$ ^C
linux@arthur:~/holbertonschool-simple_shell$
```
Here is an example of the non-interactive mode :

```c
linux@arthur:~/holbertonschool-simple_shell$ echo "/bin/ls" | ./hsh
AUTHORS README.md exercise man_1_simple_shell shell shell.h simple_shell_01.c
linux@arthur:~/holbertonschool-simple_shell$
```

## **Flowchart**
![simple_shell_flowchart](https://github.com/user-attachments/assets/92aa6ecb-30a6-4bad-b59d-769807ebca0d)
#### *Authors*
Ilmi Veliu - Arthur Urbano
