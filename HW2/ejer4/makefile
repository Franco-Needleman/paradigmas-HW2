make:
	g++ main.cpp -Wall -g -o main
	
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main 
	rm main