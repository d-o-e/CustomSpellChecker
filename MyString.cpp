/**
 *  Deniz Erisgen ©
 */
#include "MyDict.hpp"
#include "MyString.hpp"

void MyString::lower() {
	unsigned short i = 0;
	char* clean = const_cast<char*>(this->c_str());
	char c;
	while ((c = clean[i])) {
		clean[i] = isupper(c) ? ::tolower(c) : c;
		i++;
	}
}

MyString::operator unsigned() const {
	unsigned sum = 0, i = 0;
	char* c = const_cast<char*>(this->c_str());
	while (c[i] != '\0') {
		sum += c[i] * c[i];
		i++;
	}
	return sum;
}

void MyString::removePunctuation() {
	string clean;
	char* tok = strtok((const_cast<char*>(this->c_str())), "'\",.!?_-:;\r");
	if (tok == nullptr) {
		clean = "";
		this->swap(clean);
		return;
	}
	clean = string(tok);
	this->swap(clean);
}
