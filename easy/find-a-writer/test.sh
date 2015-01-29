g++ -std=c++11 -o main *.cpp
if [ -f main ]; then
	./main input.txt
	rm main
fi
