tracing system calls:
```strace``` is a Linux diagnostic and debugging tool that traces system calls made by a program and the signals it receives.  
FlagDescription-Example  
-c  Summarizes call counts, total time spent, and errorsstrace -c ls  
-o file.txtRedirects output to a file instead of stderrstrace -o trace.log ./app  
-e trace=<calls>Filters by specific calls (e.g., network, file, process)strace -e trace=network curl example.com-fTraces child processes created via fork or clonestrace   
-t / -ttPrepends timestamps (or microsecond timestamps)strace -tt ls  

