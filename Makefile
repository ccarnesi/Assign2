thread: searchtest.c multitest_thread.o
	gcc searchtest.c multitest_thread.o -lm -lpthread -o searchtest

multitest_thread.o:
	gcc -c multitest_thread.c

clean:
	rm multitest_thread.o
	rm searchtest
