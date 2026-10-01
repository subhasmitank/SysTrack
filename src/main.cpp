#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>

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

int main()
{
    std::cout << "Linux System Monitor\n";
    std::cout << "====================\n";

    while (true)
    {
        double cpu = getCpuUsage();

        std::cout << "\033[2K\rCPU Usage: "
                  << cpu << "% " << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

