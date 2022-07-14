	#include<iostream>
	#include<cmath>
	using namespace std;
	
	
	class Node {
	private:
	double co;
	int exp;
	Node*next;
	public:
	
	void set(double a, int b) {
	co = a;
	exp = b;
	}
	
	void set_next(Node* x) {
	next = x;
	}
	double get_co() {
	return co;
	}
	int get_exp() {
	return exp;
	}
	Node*get_next() {
	return next;
	}
	Node(double a = 0, int b = 0) { //user defined constructer
	co = a;
	exp = b;
	next = NULL;
	}
	};
	
	Node * create_Node(double x, int y) { // func. to create node with data
	Node *n = new Node;
	n->set(x, y);
	n->set_next(NULL);
	return n;
	}
	
	
	class PolynomialLinkedList {
	private:
	
	Node*head;
	
	public:
	
	PolynomialLinkedList() { //constructer
	head = NULL;
	}
	
	void Add_Node(Node*n) { //member func. to add nodes to the list
	Node*p1, *p2;
	if (head == NULL) //empty list
	{
	head = n;
	return;
	}
	if (n->get_exp() > head->get_exp()) { //first node
	n->set_next(head);
	head = n;
	return;
	}
	p1 = head;
	p2 = head->get_next();
	//general case
	while (p2 != NULL) {
	
	if (n->get_exp() == p2->get_exp()) { //to remove duplication
	p2->set(p2->get_co() + n->get_co(), p2->get_exp());
	return;
	}
	
	if (n->get_exp() > p2->get_exp()) {
	n->set_next(p2);
	p1->set_next(n);
	return;
	}
	else {
	p1 = p2;
	p2 = p2->get_next();
	}
	}
	//last node
	n->set_next(p2);
	p1->set_next(n);
	return;
	
	}
	
	
	void print_polynomial() { //member func.to print polynomial
	Node*p;
	p = head;
	if (head == NULL) {
	cout << "Empty" << endl;
	return;
	}
	while (p != NULL) {
	cout << p->get_co();
	cout << "X^" << p->get_exp();
	p = p->get_next();
	if (p != NULL) cout << " + ";
	}
	cout << endl;
	
	}
	
	PolynomialLinkedList operator +(PolynomialLinkedList poly1)//oevrloading adding operator
	{
	PolynomialLinkedList poly3;
	Node*p1, *p2;
	p1 = poly1.head;
	p2 = head;
	while (p1 != NULL && p2 != NULL) {
	if (p1->get_exp() > p2->get_exp()) //power poly1>power poly 2
	{
	poly3.Add_Node(create_Node(p1->get_co(), p1->get_exp()));
	p1 = p1->get_next();
	}
	else if (p1->get_exp() < p2->get_exp())//power poly2>power poly1
	{
	poly3.Add_Node(create_Node(p2->get_co(), p2->get_exp()));
	p2 = p2->get_next();
	
	}
	else //power poly1=power poly2
	{
	poly3.Add_Node(create_Node(p1->get_co() + p2->get_co(), p1->get_exp()));
	p1 = p1->get_next();
	p2 = p2->get_next();
	
	}
	}
	
	if (p1 == NULL) { // make a copy of p2
	while (p2 != NULL) {
	poly3.Add_Node(create_Node(p2->get_co(), p2->get_exp()));
	p2 = p2->get_next();
	
	}
	
	}
	if (p2 == NULL) { // make a copy of p1  
	while (p1 != NULL) {
	poly3.Add_Node(create_Node(p1->get_co(), p1->get_exp()));
	p1 = p1->get_next();
	}
	}
	return poly3;
	}
	
	
	
	PolynomialLinkedList operator*(const PolynomialLinkedList& poly1) { //member function to overload * operator
	//Multiplication
	PolynomialLinkedList product;
	Node*p1 = head;
	while (p1) {
	Node*p2 = poly1.head;
	while (p2)
	{
	product.Add_Node(create_Node(p1->get_co()*p2->get_co(), p1->get_exp() + p2->get_exp()));
	p2 = p2->get_next();
	}
	p1 = p1->get_next();
	}
	return product;
	}
	
	friend ostream &operator<<(ostream&out, PolynomialLinkedList p) //overloding...cout  
	{
	p.print_polynomial();
	return out;
	}
	
	friend void operator !(PolynomialLinkedList &poly1) { //member function to overload ! operator
	Node*p1 = poly1.head;
	while (p1 != NULL) {
	
	p1->set(-1 * p1->get_co(), p1->get_exp());
	p1 = p1->get_next();
	}
	
	}
	
	int Evaluate(PolynomialLinkedList poly1, int x) //member function to evaluate
	{
	Node*p = poly1.head;
	int result = 0;
	while (p != NULL) {
	result += p->get_co()*pow(x, p->get_exp());
	p = p->get_next();
	}
	return result;
	}
	};
	
	void menu() {
	cout << "0. See the menu \n";
	cout << "1. Create polynomial \n";
	cout << "2. Print polynomial \n";
	cout << "3. Add two polynomilas \n";
	cout << "4. Negate polynomial \n";
	cout << "5. Multiply two polynomials \n";
	cout << "6. Evaluate polynomial \n";
	cout << "7. Add nodes \n";
	cout << "8. Exit \n";
	}
	
	int main() {
	
	cout << "plz pick a choice: " << endl;
	menu();
	int choice;
	int size = 0;
	PolynomialLinkedList *poly = new PolynomialLinkedList[size];
	cout << "___________________________________" << endl;
	while (1) {
	cout << " your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 0) {
	menu();
	cout << "_____________________________________" << endl;
	
	}
	else if (choice == 1) {
	PolynomialLinkedList tmp;
	poly[size]=tmp;
	cout << "polynomial #" << size + 1 << " has been created" << endl;
	size++;
	cout << "_____________________________________" << endl;
	
	}
	else if (choice == 2) {
	int num;
	cout << "enter the num of polynomial you want to print : ";
	cin >> num;
	cout << endl << poly[num - 1];
	cout << endl << "_____________________________________" << endl;
	}
	else if (choice == 3) {
	int num1, num2;
	cout << endl << "enter the numbers of polynomials you want to add " << endl;
	cout << "1st poly: ";
	cin >> num1;
	cout << endl << "2nd poly : ";
	cin >> num2;
	cout << endl << "the result : ";
	cout << poly[num1 - 1] + poly[num2 - 1];
	cout << endl << "_________________________________" << endl;
	}
	else if (choice == 4) {
	cout << endl << "enter the num of polynomial you want to negate: ";
	int num;
	cin >> num;
	cout << endl << "the result: ";
	!poly[num - 1];
	cout << poly[num - 1];
	cout << endl << "_________________________________" << endl;
	
	}
	else if (choice == 5) {
	int num1, num2;
	cout << endl << "enter the numbers of polynomials you want to multiply " << endl;
	cout << " Num of the 1st poly: ";
	cin >> num1;
	cout <<  " Num of the 2nd poly : ";
	cin >> num2;
	cout << endl << "the result : ";
	cout << poly[num1 - 1] * poly[num2 - 1];
	cout << endl << "_________________________________" << endl;
	
	}
	else if (choice == 6) {
	cout << endl << "enter the num of polynomial you want to evaluate: ";
	int num;
	int x;
	cin >> num;
	cout << endl << "enter the value x: ";
	cin >> x;
	cout << endl << "the result: ";
	cout << poly[num - 1].Evaluate(poly[num - 1], x);
	cout << endl << "_________________________________" << endl;
	
	}
	else if (choice == 7) {
	cout << " you want to add nodes to poly num : ";
	int n;
	cin >> n;
	int co;
	int exp;
	cout << endl << "enter coefficient: ";
	cin >> co;
	cout << endl << "enter exponent : ";
	cin >> exp;
	poly[n - 1].Add_Node(create_Node(co, exp));
	cout << endl << "_________________________________" << endl;
	
	}
	else if (choice >= 8) {
	break;
	
	}
	
	}
	
	return 0;
	}


