# SysTrack: Linux Resource and Process Monitoring System

## Description

SysTrack is a C++17 based Linux terminal application for monitoring basic system resources, processes, and system information.

The project demonstrates how a Linux application can obtain system information through Linux system interfaces such as the `/proc` filesystem and the `uname()` system call.

## Features

- CPU usage monitoring using `/proc/stat`
- Memory usage monitoring using `/proc/meminfo`
- System uptime monitoring using `/proc/uptime`
- Process information using `/proc`
- Process PID, name, and state display
- Operating system, kernel, and machine information
- Continuously refreshing terminal dashboard

## Technologies Used

- C++17
- Linux
- `/proc` filesystem
- `uname()` system call
- GCC/G++
- Git and GitHub

## Requirements

- Linux operating system
- GCC/G++ compiler with C++17 support
- Terminal

The project was developed and tested in Ubuntu running under WSL2.

## Build

From the project directory, run:

