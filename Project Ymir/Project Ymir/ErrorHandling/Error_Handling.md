## ErrorHandling
1. Intro  
ErrorHandling has two parts. The first one is an exception. This occurs when serious error happens. The second one is an logger. This can be used to record minor error or log information for debugging.
2. Exception  
As I said, an exception is used in serious error that means program cannot run further. This case occurs when the basic engine component failed to initialize, corrupted resources are found, etc. Be aware that, only in serious situation, exception is used. In minor error, program should go on, for instance, missing files.  
2.1. Exception handling  
An exception will be handled outside of the run loop. So, be careful of releasing resources.  In this version, error will be shown in message box and logged.  
2.2 Logging exception
Logger will log the file name and line number of error with time. Output file name is "log.error.txt"
3. Logger  
Logger can be used for minor error or log information for debugging. It does not support concurrent access. Output file name is "log.error.txt" with time.
