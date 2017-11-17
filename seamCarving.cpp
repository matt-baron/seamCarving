#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

void seamCarve(std::string, int, int);

int main(int argc, char* argv[]){
	//Parse user input
	if(argc != 4){
		std::cout << "Invalid number of arguements! Please check README.txt" << std::endl;
		return 1;
	}
	
	std::string fileName = argv[1];
	int xSeams = atoi(argv[2]);
	int ySeams = atoi(argv[3]);

	seamCarve(fileName, xSeams, ySeams);

	std::cout << "Program successfully ran!" << std::endl;
	std::cin.get();
	return 0;
}

void seamCarve(std::string fileName, int xSeams, int ySeams){
	std::ifstream file;
	file.open(fileName);

	int row = 0, col = 0, numrows = 0, numcols = 0;

 	std::stringstream ss;
 	std::string inputLine = "";

 	// First line : version
 	std::getline(file,inputLine);
 	if(inputLine.compare("P2") != 0) std::cerr << "Version error" << std::endl;
 	else std::cout << "Version : " << inputLine << std::endl;

 	// Second line : comment
 	getline(file,inputLine);
 	std::cout << "Comment : " << inputLine << std::endl;

 	// Continue with a stringstream
 	ss << file.rdbuf();
 	// Third line : size
 	ss >> numcols >> numrows;
 	std::cout << numcols << " columns and " << numrows << " rows" << std::endl;

 	int array[numrows][numcols];

 	// Following lines : data
 	for(row = 0; row < numrows; ++row)
   		for (col = 0; col < numcols; ++col) 
			ss >> array[row][col];

 	// Now print the array to see the result
 	for(row = 0; row < numrows; ++row) {
   		for(col = 0; col < numcols; ++col) 
			std::cout << array[row][col] << " ";
	std::cout << std::endl;
	}	

	file.close();
}

