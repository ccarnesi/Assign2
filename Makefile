thread: searchtest.c multitest_thread.o
	gcc searchtest.c multitest_thread.o -lm -lpthread -o searchtest
proc: searchtest.c multitest_proc.o
	gcc searchtest.c multitest_proc.o -lm -o searchtest

multitest_thread.o:
	gcc -c multitest_thread.c

multitest_proc.o:
	gcc -c multitest_proc.c

cleanThread:
	rm multitest_thread.o
	rm searchtest
cleanProc:
	rm multitest_proc.o
	rm searchtest
