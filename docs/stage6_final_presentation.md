# Stage 6: Final Implementation & Presentation

## 1. Project Title

# SysTrack: Linux Resource and Process Monitoring System

**Subtitle:** A C++-based Linux application for monitoring system resources, processes, and system information.

## 2. Final Project Objective

The objective of SysTrack is to provide a simple terminal-based Linux monitoring application that displays important system information, resource usage and running process information.

The project demonstrates how a C++ application can interact with Linux system interfaces to obtain operating system information and runtime system data.

## 3. Final Implemented Features

The final prototype includes the following features:

### CPU Monitoring

CPU usage is calculated using information obtained from `/proc/stat`.

### Memory Monitoring

Memory usage is calculated using information from `/proc/meminfo`.

### Uptime Monitoring

System uptime is obtained from `/proc/uptime`.

### Process Monitoring

The application scans the `/proc` filesystem and displays:

* Process ID (PID)
* Process name
* Process state

### System Information

The Linux `uname()` interface is used to display:

* Operating system
* Kernel version
* Machine architecture

### Terminal Dashboard

The monitoring information is displayed in a continuously refreshing terminal dashboard.

## 4. System Architecture

The application follows a simple layered architecture:

```text
                    Linux Operating System
                             |
              +--------------+--------------+
              |              |              |
          /proc/stat    /proc/meminfo   /proc/uptime
              |              |              |
              +--------------+--------------+
                             |
                    Linux Interface Layer
                             |
        +--------------------+--------------------+
        |                    |                    |
   CPU Monitor         Memory Monitor        Uptime Monitor
        |                    |                    |
        +--------------------+--------------------+
                             |
                     Process Monitor
                             |
                     System Info Module
                             |
                       Display Manager
                             |
                       Terminal UI
```

The Linux `/proc` filesystem provides runtime system information to the application, while the `uname()` system interface provides system information.

## 5. Implementation Summary

The application was implemented in C++17 and compiled using GCC/G++.

Important Linux interfaces used include:

* `/proc/stat`
* `/proc/meminfo`
* `/proc/uptime`
* `/proc/<PID>/comm`
* `/proc/<PID>/status`
* `uname()`

The application uses C++ standard library features such as file streams, strings, filesystem directory iteration, formatting and thread sleep functionality.

## 6. Testing Summary

Eight test cases were completed during Stage 5.

| Test                          | Result |
| ----------------------------- | ------ |
| CPU monitoring                | PASS   |
| Memory monitoring             | PASS   |
| Uptime monitoring             | PASS   |
| Process monitoring            | PASS   |
| System information            | PASS   |
| Dashboard refresh             | PASS   |
| Compilation and warning check | PASS   |
| Integrated execution          | PASS   |

The application compiled successfully using:

```bash
g++ -std=c++17 -Wall -Wextra -g src/main.cpp -o monitor
```

The integrated application was executed successfully in the Linux environment without crashing during testing.

## 7. Git and Version Control

Git was used throughout the development process to maintain project history.

Major development commits include:

* Stage 1: Project introduction
* Stage 2: Project requirements and development plan
* Stage 3: System design and architecture
* Initial CPU monitoring prototype
* Memory monitoring implementation
* Monitoring feature integration
* Stage 4 implementation documentation
* Stage 5 testing and integration results

The final repository was verified with:

```bash
git status
```

The working tree was clean after the Stage 5 commit.

## 8. Achievements

The project successfully demonstrates:

* C++ programming on Linux
* Linux `/proc` filesystem usage
* CPU resource monitoring
* Memory resource monitoring
* System uptime monitoring
* Process enumeration
* Process state detection
* Linux system information retrieval
* Terminal-based monitoring
* Incremental development using Git
* Testing and integration of multiple monitoring features

## 9. Current Limitations

The current prototype has some limitations:

1. The application is terminal-based and does not provide a graphical interface.
2. Some long process names may be truncated when displayed.
3. The application currently displays basic process information rather than detailed per-process resource statistics.
4. The current implementation is focused on monitoring rather than anomaly detection.
5. The project was developed and tested in WSL2, so it does not currently include a custom Linux kernel module or hardware device driver.

## 10. Future Improvements

Possible future improvements include:

* Separating the implementation into multiple source and header files.
* Adding detailed per-process CPU and memory usage.
* Adding process sorting and filtering.
* Improving terminal dashboard formatting.
* Adding configurable refresh intervals.
* Adding logging of monitoring data.
* Adding more Linux system information.
* Exploring a Linux kernel module or device-driver component in a suitable native Linux or virtual-machine environment.

## 11. Final Outcome

SysTrack provides a working C++ Linux monitoring prototype that collects system information from Linux interfaces and presents it through a continuously refreshing terminal dashboard.

The project demonstrates the practical use of C++ with Linux system interfaces, filesystem information and process monitoring.

## 12. Presentation Flow

The final demonstration can be presented in the following order:

### 1. Introduction

Briefly explain the problem and objective of SysTrack.

### 2. Architecture

Explain how the application obtains information from Linux `/proc` interfaces and displays it through the terminal dashboard.

### 3. Implementation

Show the important monitoring components:

* CPU
* Memory
* Uptime
* Processes
* System information

### 4. Live Demonstration

Run:

```bash
./monitor
```

Show the system information, process list, CPU usage, memory usage and uptime.

### 5. Testing

Explain that eight test cases were completed and passed.

### 6. Git History

Show the Git commit history to demonstrate incremental development.

### 7. Limitations and Future Work

Briefly explain the current limitations and possible future improvements.

## 13. Conclusion

The SysTrack project achieved its primary objective of creating a functional C++-based Linux resource and process monitoring application.

The final prototype demonstrates Linux system interaction, resource monitoring, process information retrieval, terminal dashboard development, testing and Git-based version control.
