CC = g++ --std=c++11 -pthread

output.o: main.o threadPool.o task.o printTask.o concurrentTaskQueue.o logger.o
	${CC} main.o threadPool.o task.o printTask.o concurrentTaskQueue.o logger.o -o main.out

main.o: main.cpp
	${CC} -c main.cpp -o main.o

threadPool.o: ThreadPool.cpp ThreadPool.hpp Logger.o
	${CC} -c ThreadPool.cpp -o threadPool.o

task.o: Task.cpp Task.hpp
	${CC} -c Task.cpp -o task.o

printTask.o: PrintTask.cpp PrintTask.hpp
	${CC} -c PrintTask.cpp -o printTask.o

concurrentTaskQueue.o: ConcurrentTaskQueue.hpp
	${CC} -c ConcurrentTaskQueue.cpp -o concurrentTaskQueue.o

logger.o: Logger.hpp
	${CC} -c Logger.cpp -o logger.o

.PHONY: clean
clean:
	rm *.o 
	rm main.out