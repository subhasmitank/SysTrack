# Stage 5: Testing, Integration & Improvement

## 1. Testing Objective

The objective of this stage is to verify that the SysTrack monitoring features work correctly individually and together as an integrated Linux monitoring application.

## 2. Test Environment

* Operating System: Ubuntu 26.04.1 LTS on WSL2
* Language: C++17
* Compiler: GCC/G++
* Build flags: `-Wall -Wextra -g`
* Execution environment: Linux terminal

## 3. Test Cases

| Test ID | Feature            | Test Description                          | Expected Result                                     | Actual Result                                                                      | Status |
| ------- | ------------------ | ----------------------------------------- | --------------------------------------------------- | ---------------------------------------------------------------------------------- | ------ |
| T01     | CPU                | Run the monitor and observe CPU usage     | Value should remain between 0% and 100%             | CPU usage was displayed successfully and remained within the expected range        | PASS   |
| T02     | Memory             | Run the monitor and observe memory usage  | Value should remain between 0% and 100%             | Memory usage was displayed successfully at approximately 6.94%–6.99%               | PASS   |
| T03     | Uptime             | Observe uptime during dashboard refreshes | Uptime should increase with time                    | Uptime increased from 28320.9 to 28322 and 28323 seconds                           | PASS   |
| T04     | Processes          | Observe the process list                  | PID, name and state should be displayed             | Process PIDs, names and states such as S and R were displayed                      | PASS   |
| T05     | System Information | Run the monitor                           | OS, kernel and architecture should be displayed     | Linux, WSL2 kernel version and x86_64 architecture were displayed                  | PASS   |
| T06     | Dashboard          | Run the application continuously          | Dashboard should refresh approximately every second | Dashboard refreshed continuously and displayed updated monitoring information      | PASS   |
| T07     | Compilation        | Compile with warning flags                | Compilation should complete without warnings/errors | Compilation completed successfully with no warnings or errors                      | PASS   |
| T08     | Integration        | Run all monitoring features together      | All features should operate without crashing        | CPU, memory, uptime, process and system information operated together successfully | PASS   |

## 4. Issues Found

### Issue 1: Memory Usage Calculation

During implementation, memory usage initially produced an incorrect percentage because integer division was being used.

**Solution:** The calculation was changed to use floating-point division before multiplying by 100.

### Issue 2: Process Name Length

Some process names displayed in the terminal were truncated.

**Reason:** Linux process names obtained from `/proc/<PID>/comm` have a limited length.

**Status:** The process information is still correctly displayed and is sufficient for the current prototype.

### Issue 3: Terminal Dashboard Output

The dashboard produces repeated output when the terminal output is captured as text.

**Reason:** The application clears and redraws the terminal approximately once per second.

**Status:** This is expected behaviour for the live terminal dashboard.

## 5. Testing Results

All eight planned test cases were completed successfully.

The testing confirmed that:

* CPU usage monitoring works.
* Memory usage monitoring works.
* System uptime is updated correctly.
* Process information is displayed.
* System information is displayed.
* The terminal dashboard refreshes continuously.
* The application compiles successfully with warning flags.
* All monitoring features operate together without crashing.

## 6. Improvements

The following improvements were made during testing and integration:

* Corrected the memory usage calculation.
* Verified CPU usage remains within the expected 0–100% range.
* Verified increasing uptime values during dashboard refresh.
* Verified process information and process states.
* Verified system information using the Linux `uname()` interface.
* Verified compilation with `-Wall -Wextra`.
* Checked source formatting and whitespace using `git diff --check`.

## 7. Conclusion

Testing and integration of the SysTrack prototype were completed successfully.

The results show that the implemented monitoring features operate correctly in the Linux environment. The prototype is ready for final documentation, presentation preparation and final integration.
