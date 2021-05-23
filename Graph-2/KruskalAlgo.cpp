#include<bits/stdc++.h>
using namespace std;

class edge {
    public:
    
    int src;
    int dest;
    int weight;

    edge(){}
    edge(int src,int dest ,int weight) {

        this->src = src;
        this->dest = dest;
        this->weight = weight;

    }
};

bool compare(edge const & a , edge const & b) {

    return a.weight < b.weight;

}

int findParent(int* parent, int vertex) {

    if(parent[vertex] == vertex) {

        return vertex;

    }

    findParent(parent, parent[vertex]);

}

void kruskalMST(edge *input, int n, int m) {

    sort(input, input + m, compare);

    int* parent = new int[n];

    for(int i = 0; i < n; i++) {

        parent[i] = i;

    }

    edge* output = new edge[n - 1];

    int count = 0;
    int i = 0;

    while(count < n - 1) {

        edge currentVertex = input[i];
        int srcParent = findParent(parent, currentVertex.src);
        int destParent = findParent(parent, currentVertex.dest);

        if(srcParent != destParent) {

            output[count] = currentVertex;
            count++;

            parent[srcParent] = destParent;

        }

        i++;

    }

    for(int i = 0; i < n - 1; i++) {

        if(output[i].src < output[i].dest)
            cout << output[i].src <<" "<< output[i].dest <<" "<< output[i].weight << endl;
        else{
           cout<<output[i].dest <<" " << output[i].src <<" " <<output[i].weight << endl;
        }

    }

    delete[] output;
    delete[] parent;

}

int main() {

    int n, m;
    cin >> n >> m;

    edge *input = new edge[m];

    for(int i = 0; i < m; i++) {

        int s, d, w;
        cin >> s >> d >> w;
        input[i] = edge(s, d, w);

    }

    kruskalMST(input, n, m);

    delete[] input;

}