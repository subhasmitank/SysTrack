
# Stage 3: System Design & Architecture

## 1. System Design Overview

The Linux System Performance Monitor Using C++ will use a modular architecture.

The application will collect system information from Linux system interfaces, process the collected information using C++, and display the results through the terminal.

The main components of the system are:

- Linux system interfaces
- CPU Monitoring Module
- Memory Monitoring Module
- Uptime Monitoring Module
- Process Monitoring Module
- System Information Module
- Terminal Display Module

The modular design will make the project easier to understand, test, maintain, and extend.
## 2. Components and Responsibilities

### Linux System Interface
Provides access to system information exposed by Linux.

### CPU Monitoring Module
Reads CPU-related information and calculates CPU usage.

### Memory Monitoring Module
Reads memory information and calculates the memory usage.

### Uptime Monitoring Module
Reads and displays the amount of time the system has been running.

### Process Monitoring Module
Obtains basic information about running processes.

### System Information Module
Collects basic Linux and system information.

### Terminal Display Module
Formats and displays the collected information to the user.



## 3. System Architecture

The system follows a modular architecture in which each monitoring component has a specific responsibility.

```text
+---------------------------+
|       Linux System        |
+-------------+-------------+
              |
              v
+---------------------------+
| Linux System Interfaces   |
|          /proc            |
+-------------+-------------+
              |
              v
+---------------------------+
|   C++ Monitor Application |
+-------------+-------------+
              |
      +-------+-------+
      |       |       |
      v       v       v
    CPU    Memory   Processes
  Monitor  Monitor   Monitor
      |       |       |
      +-------+-------+
              |
              v
+---------------------------+
|      Terminal Display     |
+---------------------------+


## 7. UML Design

### 7.1 Class Diagram

The main software components can be represented as separate classes/modules.

```text
+----------------------+
|   SystemMonitor      |
+----------------------+
| - cpuUsage           |
| - memoryUsage        |
| - uptime             |
+----------------------+
| +update()            |
| +display()           |
+----------+-----------+
           |
     +-----+-----+----------------+
     |           |                |
     v           v                v
+---------+ +-----------+ +---------------+
|  CPU    | |  Memory   | |   Process     |
| Monitor | |  Monitor  | |   Monitor     |
+---------+ +-----------+ +---------------+









