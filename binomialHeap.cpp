#include "std.h"
/*
	//std.h
	#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
	*/

using namespace std;
typedef long long ll;

struct node{
	int data;
	int degree;
	struct node *sibling;
	struct node *parent;
	struct node *child;
};

struct node *Union(struct node *h1, struct node *h2){
	struct node *head = NULL;


	//Merging.   
	if (h1 == NULL && h2 == NULL){
		return h1;

	}
	else if (h1 == NULL && h2 != NULL){
		return h2;

	}
	else if (h1 != NULL && h2 == NULL){
		return h1;

	}
	else{
		struct node *t1 = h1;
		struct node *t2 = h2;
		struct node *temp2;
		struct node *temp = head;
		while (t1 != NULL && t2 != NULL){


			if (t1->degree <= t2->degree){
				temp2 = t1;
				t1 = t1->sibling;
			}
			else{
				temp2 = t2;
				t2 = t2->sibling;
			}
			if (head == NULL){
				head = temp2;
				temp = temp2;
			}
			else{

				temp->sibling = temp2;
				temp = temp2;
			}
		}
		while (t1 != NULL){

			temp2 = t1;
			t1 = t1->sibling;

			temp->sibling = temp2;
			temp = temp2;
		}
		while (t2 != NULL){

			temp2 = t2;
			t2 = t2->sibling;

			temp->sibling = temp2;
			temp = temp2;
		}

		// adjusting the heap for making correct binomialHeap.
		struct node *t3 = head;

		while (t3->sibling != NULL){
			struct node *t4 = t3->sibling;
			struct node *t5 = t4->sibling;
			if (t3->degree != t4->degree){

				t3 = t3->sibling;
			}
			else{
				if (t5 != NULL){
					if (t4->degree != t5->degree){

						if (t3->data <= t4->data){
							t3->sibling = t5;
							t4->sibling = t3->child;
							t3->child = t4;
							t3->degree++;

						}
						else{

							struct node *t6 = head;
							if (t3 == head){
								t3->sibling = t4->child;
								t4->child = t3;
								t4->degree++;
								head = t4;
								t3 = t4;

							}
							else{
								while (t6->sibling != t3){
									t6 = t6->sibling;
								}
								t6->sibling = t4;
								t3->sibling = t4->child;
								t4->child = t3;
								t3 = t4;
								t3->degree++;
							}

						}
					}
					else{
						t3 = t3->sibling;
					}
				}
				else{

					if (t3->data <= t4->data){
						t3->sibling = NULL;
						t4->sibling = t3->child;
						t3->child = t4;
						t3->degree++;

					}
					else{
						struct node *t6 = head;
						if (t3 == head){
							t3->sibling = t4->child;
							t4->child = t3;
							t4->degree++;
							head = t4;
							t3 = t4;
						}
						else{
							while (t6->sibling != t3){
								t6 = t6->sibling;
							}
							t6->sibling = t4;
							t3->sibling = t4->child;
							t4->child = t3;
							t4->degree++;
							t3 = t4;
						}

					}
				}
			}
		}

		return head;
	}
}

struct node *Insert(int x, struct node *head){
	struct node *temp = (node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->parent = temp->sibling = temp->child = NULL;
	temp->degree = 0;
	struct node *headNew = Union(temp, head);

	return headNew;

}

struct node *ExtractMin(struct node *head, ll Sign){

	if (head == NULL){
		cout << "Cannot delete from empty heap" << endl;
		return head;
	}
	else{

		ll Min = head->data;
		struct node *temp = head;
		struct node *MinNode = head;
		while (temp != NULL){
			if (temp->data < Min){
				Min = temp->data;
				MinNode = temp;
			}

			temp = temp->sibling;
		}

		if (Sign == 1){
			cout << "Minimum Extracted : " << MinNode->data << endl;
		}



		if (MinNode == head){
			struct node *p1 = head->sibling;
			struct node *p2 = head->child;
			if (p2 == NULL){
				return p1;
			}
			else if (p2->sibling == NULL){
				return Union(p2, p1);
			}
			else{
				struct node *q1 = p2;
				struct node *q2 = p2;
				while (q1->sibling != NULL){
					q1 = q1->sibling;
				}
				while (q2->sibling != q1){
					q2 = q2->sibling;
				}
				struct node *ExtractHead = q1;
				while (q1 != p2){
					q2 = p2;
					while (q2->sibling != q1){
						q2 = q2->sibling;
					}
					q1->sibling = q2;
					q1 = q2;

				}
				q1->sibling = NULL;
				return Union(ExtractHead, p1);
			}
		}
		else{
			struct node *p1 = head;
			struct node *p3 = head;
			struct node *p2 = MinNode->child;
			while (p3->sibling != MinNode){
				p3 = p3->sibling;
			}
			struct node *p4 = MinNode->sibling;
			p3->sibling = p4;
			if (p2 == NULL){
				return p1;
			}
			else if (p2->sibling == NULL){
				return Union(p2, p1);
			}
			else{
				struct node *q1 = p2;
				struct node *q2 = p2;
				while (q1->sibling != NULL){
					q1 = q1->sibling;
				}
				while (q2->sibling != q1){
					q2 = q2->sibling;
				}
				struct node *ExtractHead = q1;
				while (q1 != p2){
					q2 = p2;
					while (q2->sibling != q1){
						q2 = q2->sibling;
					}
					q1->sibling = q2;
					q1 = q2;

				}
				q1->sibling = NULL;


				return Union(ExtractHead, p1);
			}



		}

	}
}

void showHeap(struct node *x, int depth){
	if (x->sibling != NULL)
		showHeap(x->sibling, depth);
	cout << endl;
	if ((x->child != NULL) || (x->parent == NULL)){
		for (int i = 0; i < depth; i++) cout << "    ";
		cout << x->data;
		if (x->child == NULL) cout << endl;
	}
	else{
		for (int i = 0; i < depth; i++) cout << "    ";
		cout << x->data << endl;
	}
	if (x->child != NULL){
		showHeap(x->child, depth + 1);
	}
}

void showBinomialHeap(struct node *head){
	cout << "Stucture of binomial heap " << endl;
	if (head == NULL) cout << "Empty heap" << endl;
	else showHeap(head, 0);
}

int main(){
	struct node *headMain = NULL;
	ll Sign = 1; 
	for (ll i = 0; i < 128; ++i)
	{
		headMain = Insert(rand()%100, headMain);
		
	}
	showBinomialHeap(headMain);
	cin >> Sign;
	
}
