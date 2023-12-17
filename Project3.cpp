// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Date:12/10/2023
// Name: Saul Torres-Galindo
// Purpose of program: To read inventory for the company Corner Grocer and check the the frequecny of the items 

#include <iostream>
#include <fstream>
#include <map>
#include <string>


using namespace std;

class inventory {

private:
	map<string, 
	int> frequencies;

public:
	inventory() {}   // inveronty class 

	// this reads the input file inverotylist and put them in map
	void readInputFile(const string& fileName) {
		ifstream inputFile(fileName);
		if (!inputFile) {
			cerr << "Error, file does not exist" << endl;
			exit(1);
		}

		// while loop that read the file with inventory and updates the ferqucies of item with the use of maps
		string items;
		while (inputFile >> items) {
			frequencies[items]++;

		}

		inputFile.close();   // closes the file
	}


	// This function is used to print the item that the user selcects
	void printItemTimes(const string& items)const {
		if (frequencies.count(items) > 0) {
			cout << items <<" " << frequencies.at(items) << endl;
		}
		else {
			cout << items <<" not bought" << endl;
		}
	}

	// This function prints all the items at once from the file
	void printAllTimes() const {
		for (const auto& entry : frequencies) {
			cout << entry.first << " " << entry.second << " times " << endl;
		}
	}

	// prints the histogram of every item in terms of frequency
	void printItemHistograms() const {
		for (const auto& entry : frequencies) {
			cout << entry.first << " ";
			for (int i = 0; i < entry.second; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}

	// Makes a backup file to write to the file 
	void writeFrequencyFile(const string& fileName) const {
		ofstream frequencyFile(fileName);
		

		for(const auto& entry : frequencies){
			frequencyFile << entry.first << " " << entry.second << endl;
		}

		frequencyFile.close();
		cout << "file is backup as 'frequency.dat'  "<< endl;
	}

};

int main() {
	inventory invList;

	invList.readInputFile("CS210_Project_Three_Input_File.txt");   // Reads the file that has all the inventory

	int option;  // sets option as an integer


	// Prints out the menu for the user's options
	do {
		cout << "\nMenu Opitions:\n" << endl;
		cout << "Please enter a choice (1-5): " << endl;
		cout << "1-Search for an item in the inventory..." << endl;
		cout << "2-Prints the frequency of all the items in the inventory..." << endl;
		cout << "3-Prints the items in inventory in histogram frequency..." << endl;
		cout << "4-Creates a back up file of inventory..." << endl;
		cout << "5-Exit.." << endl;
		
		cin >> option;
		
		cout << "\nYou choose  opition: " << option << endl;
		cout << "\n";

		// swtich option that calls on the specifc function to do a certain task
		switch (option) {
		case 1: {
			string items;
			cout << "Please enter an item to search:   ";
			cin >> items;
			invList.printItemTimes(items);
			break;
		}

		case 2: {
			invList.printAllTimes();
			break;
		}

		case 3: {
			invList.printItemHistograms();
			break;
		}
		case 4: {
			invList.writeFrequencyFile("frequency.dat");
			break;
		}
		case 5: {
			cout << " Exiting the application........" << endl;
			break;
		}

		default: {
			cout << "PLease choice a valid option" << endl;
			break;
		}
	  }
	} while (option != 5);  // as long as the user doesnt enter option 5 , loop the program
	return 0;
}
