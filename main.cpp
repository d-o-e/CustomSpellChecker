/**
 *  Deniz Erisgen ©
 */
#include "MyDict.cpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	MyHash<MyString, 50000> Dictionary;
	MyString buffer;
	const string DictionaryFileName = "../words";
	const string DocumentFileName = "../ihaveadream.txt";
	ifstream fin(DictionaryFileName.c_str());
	if (!fin) {
		cerr << "Can't find " << DictionaryFileName << endl;
		exit(-1);
	}

	while (getline(fin, buffer)) {
		// remove \r if present (this for Mac/Linux)
		if (buffer[buffer.size() - 1] == '\r') buffer.resize(buffer.size() - 1);
		buffer.lower();
		try {
			Dictionary.insert(buffer);
		} catch (const DuplicateError<MyString> &error) { cout << error.what() << " is already in the list" << endl; }
	}
	putchar('\n');
	cout << "Number of words in the dictionary = " << Dictionary.size() << endl;
	cout << "Percent of hash table buckets used = " << setprecision(2) << fixed
	     << 100 * Dictionary.percentOfBucketsUsed() << '%' << endl;
	cout << "Average non-empty bucket size = " << Dictionary.averageNonEmptyBucketSize() << endl;
	cout << "Largest bucket size = " << Dictionary.largestBucketSize() << endl;
	fin.close();
	fin.clear();
	// Spellcheck
	vector<string> wrongSpelling;

	fin.open(DocumentFileName.c_str());
	if (!fin) {
		cerr << "Can't find " << DocumentFileName << endl;
		exit(-1);
	}
	while (fin >> buffer) {
		if (fin.eof()) { break; }
		buffer.lower();
		buffer.removePunctuation();
		if (buffer.empty()) continue;
		if (!Dictionary.find(buffer)) {
			wrongSpelling.push_back(buffer);
		}
	}
	cout << "Total misspelled words = " << wrongSpelling.size() << endl;
	cout << "" << endl;
	cout << "Misspelled words \n" ;
	for (const auto& item : wrongSpelling) { cout << item << endl; }
	wrongSpelling.clear();
	//	cout << "Total misspelled words = " << misspelledWords << endl;
	return 0;
}
