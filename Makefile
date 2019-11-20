all:
	$(error Please specify thread or proc)

thread: searchtest.c multitest_thread.o
	gcc searchtest.c multitest_thread.o -lm -lpthread -o searchtest
proc: searchtest.c multitest_proc.o
	gcc searchtest.c multitest_proc.o -lm -o searchtest

multitest_thread.o:
	gcc -c multitest_thread.c

multitest_proc.o:
	gcc -c multitest_proc.c

clean:
	rm multitest_*.o
	rm searchtest
