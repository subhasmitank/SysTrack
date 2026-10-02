#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>
#include <filesystem>
#include <cctype>
#include <iomanip>
#include <sys/utsname.h>

double getCpuUsage()
{
    std::ifstream file("/proc/stat");

    std::string cpu;
    long long user, nice, system, idle, iowait, irq, softirq, steal;

    file >> cpu >> user >> nice >> system >> idle
         >> iowait >> irq >> softirq >> steal;

    long long idleTime = idle + iowait;

    long long totalTime = user + nice + system + idle +
                          iowait + irq + softirq + steal;

    static long long previousIdle = 0;
    static long long previousTotal = 0;

    if (previousTotal == 0)
    {
        previousIdle = idleTime;
        previousTotal = totalTime;
        return 0.0;
    }

    long long idleDelta = idleTime - previousIdle;
    long long totalDelta = totalTime - previousTotal;

    previousIdle = idleTime;
    previousTotal = totalTime;

    if (totalDelta <= 0)
        return 0.0;

    double usage = 100.0 *
        (1.0 - static_cast<double>(idleDelta) / totalDelta);

    return std::clamp(usage, 0.0, 100.0);
}

double getMemoryUsage()
{
    std::ifstream file("/proc/meminfo");
    std::string label;
    long long total = 0;
    long long available = 0;
    long long value;
    std::string unit;

    while (file >> label >> value >> unit)
    {
        if (label == "MemTotal:")
            total = value;

        if (label == "MemAvailable:")
            available = value;
    }

    if (total == 0)
        return 0.0;

    double used = total - available;
    return (static_cast<double>(used) / total) * 100.0;
}

double getUptime()
{
    std::ifstream file("/proc/uptime");
    double uptime;
    file >> uptime;

    return uptime;
}
void getProcessInfo()
{

	std::cout << "\nPROCESS INFORMATION\n";
	std::cout << "-----------------------------\n";
	std::cout << "PID\tNAME\tSTATE\n";
	std::cout << "-----------------------------\n";


    for (const auto& entry : std::filesystem::directory_iterator("/proc"))
    {
        std::string name = entry.path().filename().string();
	if (!name.empty() &&
            std::all_of(name.begin(), name.end(), ::isdigit))
        {
		std::string commPath = "/proc/" + name + "/comm";
		std::ifstream commFile(commPath);
                std::string processName;
                commFile >> processName;

                std::cout << std::left << std::setw(8) << name;
            std::cout << std::setw(20) << processName;
		std::string statusPath = "/proc/" + name + "/status";
		std::ifstream statusFile(statusPath);
		std::string line;
                while (std::getline(statusFile, line))
		{
			if (line.rfind("State:", 0) == 0)
                {
				std::cout << line[7] << '\n';
                    break;
                }
		}
        }

    }
}

void getSystemInfo()
{
    struct utsname info;

    if (uname(&info) == 0)
    {
        std::cout << "\nSYSTEM INFORMATION\n";
        std::cout << "-----------------------------\n";
        std::cout << "System: " << info.sysname << '\n';
        std::cout << "Kernel: " << info.release << '\n';
        std::cout << "Machine: " << info.machine << '\n';
    }
}



int main()
{

    while (true)
    {
	std::cout << "\033[2J\033[H";

	std::cout << "SysTrack\n";
	std::cout << "===============================================\n";

	getSystemInfo();
        double cpu = getCpuUsage();
	double memory = getMemoryUsage();
	double uptime = getUptime();
        getProcessInfo();

	std::cout << "\nCPU Usage: "
	          << cpu << "% | Memory Usage: "
                  << memory << "% "
		  << " | Uptime: " << uptime << " seconds"
                  << std::flush;


        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
