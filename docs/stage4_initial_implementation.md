# Stage 4: Initial Implementation & Prototype

## 1. Objective

The objective of this stage was to implement the core monitoring features of SysTrack and develop a working terminal-based prototype.

The implementation was developed in C++17 on Linux using Linux system interfaces such as the `/proc` filesystem and the `uname()` system call.

## 2. Implemented Features

The following features were implemented and integrated:

### CPU Monitoring

CPU usage is obtained from `/proc/stat`.

The program reads CPU time values and compares the current values with the previous measurement to calculate CPU utilization.

### Memory Monitoring

Memory information is obtained from `/proc/meminfo`.

The program reads `MemTotal` and `MemAvailable` and calculates memory usage as a percentage.

### Uptime Monitoring

System uptime is obtained from `/proc/uptime`.

The first value from this file represents the number of seconds the system has been running.

### Process Monitoring

Running processes are identified by scanning numeric directories under `/proc`.

For each process, the prototype displays:

* Process ID (PID)
* Process name
* Process state

Process information is read from files such as `/proc/[PID]/comm` and `/proc/[PID]/status`.

### System Information

Basic system information is obtained using the Linux `uname()` system call.

The prototype displays:

* Operating system
* Kernel release
* Machine architecture

### Terminal Dashboard

The monitoring features were integrated into a continuously refreshing terminal dashboard.

The dashboard refreshes approximately once per second and displays the current system information, process information, CPU usage, memory usage, and uptime.

## 3. Development Environment

The prototype was developed and tested in:

* Operating System: Ubuntu 26.04.1 LTS on WSL2
* Language: C++17
* Compiler: GCC/G++
* Build command: `g++ -std=c++17 -Wall -Wextra -g`
* Version control: Git
* Repository: GitHub project repository

## 4. Issues Encountered and Solutions

### Memory Calculation

Initially, the memory calculation used integer division before multiplying by 100. This could produce an incorrect percentage.

The calculation was corrected by converting the used memory value to `double` before division.

### Code Formatting

Git whitespace checks reported trailing whitespace and inconsistent indentation.

The formatting issues were corrected and verified using:

```text
git diff --check
```

The check completed without errors before the implementation was committed.

### Process Names

Some Linux process names appear truncated because the `/proc/[PID]/comm` interface provides a limited process-name field.

This behavior is expected and does not prevent process identification.

## 5. Prototype Verification

The prototype was compiled using:

```text
g++ -std=c++17 -Wall -Wextra -g src/main.cpp -o monitor
```

The compilation completed without errors or warnings.

The program was executed successfully and verified to display:

* System information
* Kernel information
* Machine architecture
* Process list
* Process states
* CPU usage
* Memory usage
* System uptime

The dashboard successfully refreshed continuously until it was stopped using `Ctrl+C`.

## 6. Git Version Control

The Stage 4 implementation was committed to Git with the commit:

```text
dda8d15 Stage 4: implement monitoring features
```

The working tree was clean after the commit.

## 7. Current Prototype Status

The core monitoring prototype is functional.

The next stage will focus on testing, integration verification, debugging, reliability, code quality, and documentation improvements.
