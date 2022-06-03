#include <iostream>
#include <cstring>
#include "Concordance.h"

using namespace std;

Concordance::Concordance() {
	first = NULL;
}

Concordance::~Concordance() {
	// destructor
}

int Concordance::length() {
	Node* temp = first;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

Node* Concordance::get_node(const char* word, int count, Node* link) {
	Node* newnode = new Node;
	strcpy_s(newnode->wd, word);
	newnode->count = count;
	newnode->next = link;
	return newnode;
}

int Concordance::get_count(const char* word) {
	Node* temp = first;
	int count = 0;
	while (temp != NULL) {
		bool flag = true;
		for (int i = 0; i < strlen(word); ++i) {
			if (tolower(temp->wd[i]) != tolower(word[i])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return temp->count;
		}
		temp = temp->next;
	}
	return 0;
}

void Concordance::insert(const char* word) {
	Node* temp = first;
	while (temp != NULL) {
		bool flag = true;
		for (int i = 0; i < strlen(word); ++i) {
			if (tolower(temp->wd[i]) != tolower(word[i])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			temp->count++;
			return;
		}
		temp = temp->next;
	}
	first = get_node(word, 1, first);
}

void Concordance::print() {
	Node* temp = first;
	while (temp != NULL) {
		cout << temp->wd << "\t" << temp->count << endl;
		temp = temp->next;
	}
}


