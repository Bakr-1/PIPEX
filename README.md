# 💡pipex
This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.


# ❗️REQUIREMENT 

Your project must comply with the following rules:

    • You have to turn in a Makefile which will compile your source files. It must not
    relink.
    
    • You have to handle errors thoroughly. In no way your program should quit unexpectedly 
    (segmentation fault, bus error, double free, and so forth).
    
    • Your program mustn’t have memory leaks.
    
    • If you have any doubt, handle the errors like the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```
# 👨‍💻Usage

The function is written in C language and thus needs the gcc compiler and some standard C libraries to run.

Compiling the project

To compile, clone the repository and run the following inside the folder:
```bash
$make
```

The program will be executed as follows:
```bash
./pipex file1 cmd1 cmd2 file2
```
It must take 4 arguments:
    
    • file1 and file2 are file names.
    
    • cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:
    
```bash
$> < file1 cmd1 | cmd2 > file2
```


Examples:

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
Should behave like:
```bash
< infile ls -l | wc -l > outfile
```

```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```

Should behave like: 
```bash
< infile grep a1 | wc -w > outfile
```
