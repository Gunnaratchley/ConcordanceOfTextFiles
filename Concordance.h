#ifndef CONCORDANCE_H_
#define CONCORDANCE_H_

const int MAX = 8;
typedef char Word[MAX + 1];
struct Node
{
	Word wd;
	int count;
	Node* next;
};

class Concordance {
private:
	Node* first;
public:
	Concordance();
	~Concordance();
	void insert(const char* word);
	int get_count(const char* word);
	int length();
	Node* get_node(const char* word, int count, Node* link);
	void print();
};

#endif