#ifndef LL_H
#define LL_H
#include <string>
using namespace std;
class node 
{
	public:
		int rollno;
		string branch;
		int branch_code;
		string job_title;
		float ctc;
		node* next;
        node(int r, string b, int bc, string jt, float f);
};
void sll_insert(node **head, int r, string b, int bc, string jt, float f);
void sll_print(node **head);
void sll_delete(node **head, int r, string b, int bc, string jt, float f);
int sll_search(node **head, int r, string b, int bc, string jt, float f);

#endif