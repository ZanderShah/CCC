class Node {
public:
Node(int pp);
virtual ~Node();
int getPar();
void setPar(int pp);
int getSize();
void addSize(int xsz);
private:
int p, sz;
};

Node::Node(int pp) : p(pp), r(0) {
}
Node::~Node() {
}
int Node::getPar() {
	return p;
}
void Node::setPar(int pp) {
	p = pp;
}
int Node::getSize() {
	return sz;
}
void Node::addSize(int xsz) {
	sz += xsz;
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

	if (v[x].getSize() > v[y].getSize()) {
		v[x].addSize(v[y].getSize());
		v[y].setPar(x);
	} else {
		v[y].addSize(v[x].getSize());
		v[x].setPar(y);
	}
}
