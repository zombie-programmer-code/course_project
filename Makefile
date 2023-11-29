output: main.o student_details.o company_details.o linkedl.o utility.o
	g++  main.o student_details.o company_details.o linkedl.o utility.o -o output

main.o: main.cpp
	g++ -c main.cpp

student_details.o: student_details.cpp student_details.h
			g++ -c student_details.cpp

company_details.o: company_details.cpp company_details.h linkedl.h student_details.h
			g++ -c company_details.cpp 

linkedl.o : linkedl.cpp linkedl.h
	g++ -c linkedl.cpp

utility.o : utility.cpp utility.h
		g++ -c utility.cpp

clean:
	rm *.o output