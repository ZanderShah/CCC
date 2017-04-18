class Node {
public:
Node(int pp);
virtual ~Node();
int getPar();
int getRank();
void setPar(int pp);
void rankUp();
private:
int p, r;
};

Node::Node(int pp) : p(pp), r(0) {
}
Node::~Node() {
}
int Node::getPar() {
	return p;
}
int Node::getRank() {
	return r;
}
void Node::rankUp() {
	r++;
}
void Node::setPar(int pp) {
	p = pp;
}

class DisjointSet {
public:
DisjointSet(int N);
virtual ~DisjointSet();
int find(int x);
void merge(int x, int y);
private:
int N;
vector<Node> v;
};

DisjointSet::DisjointSet(int N) : N(N) {
	for (int i = 0; i <= N; i++) {
		v.push_back(Node(i));
	}
}
DisjointSet::~DisjointSet() {
}
int DisjointSet::find(int x) {
	if (v[x].getPar() != x) {
		v[x].setPar(find(v[x].getPar()));
	}
	return v[x].getPar();
}
void DisjointSet::merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) {
		return;
	}

	if (v[x].getRank() < v[y].getRank()) {
		v[x].setPar(y);
	} else if (v[x].getRank() > v[y].getRank()) {
		v[y].setPar(x);
	} else {
		v[y].setPar(x);
		v[x].rankUp();
	}
}
