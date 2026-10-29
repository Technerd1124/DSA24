
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
using namespace std;

class SocialNetwork {
    int n;
    vector<string> people;
    vector<vector<int>> graph;

public:
    SocialNetwork(int size) {
        n = size;
        people.resize(n);
        graph.resize(n);
    }

    void addPeople() {
        cout << "Enter names of " << n << " people:\n";

        for (int i = 0; i < n; i++) {
            cout << "Person " << i << ": ";
            getline(cin, people[i]);
        }
    }

    void addConnection(int u, int v) {
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid person numbers!\n";
            return;
        }

        if (u == v) {
            cout << "A person cannot connect to themselves.\n";
            return;
        }

        for (int person : graph[u]) {
            if (person == v) {
                cout << "Connection already exists.\n";
                return;
            }
        }

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void displayGraph() {
        cout << "\nSocial Network:\n";

        for (int i = 0; i < n; i++) {
            cout << people[i] << " -> ";

            for (int j : graph[i]) {
                cout << people[j] << " ";
            }

            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << people[current] << " ";

            for (int next : graph[current]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        cout << endl;
    }

    void DFSUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << people[current] << " ";

        for (int next : graph[current]) {
            if (!visited[next]) {
                DFSUtil(next, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(n, false);

        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    int findPerson(const string& name) {
        for (int i = 0; i < n; i++) {
            if (people[i] == name) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    int n, connections;

    cout << "Enter number of people: ";
    cin >> n;

    if (cin.fail() || n <= 0) {
        cout << "Invalid number of people.\n";
        return 0;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SocialNetwork network(n);
    network.addPeople();

    cout << "\nEnter number of connections: ";
    cin >> connections;

    if (cin.fail() || connections < 0) {
        cout << "Invalid number of connections.\n";
        return 0;
    }

    cout << "Enter connections using person numbers (0 to "
         << n - 1 << "):\n";

    for (int i = 0; i < connections; i++) {
        int u, v;

        cout << "Connection " << i + 1 << ": ";
        cin >> u >> v;

        if (cin.fail()) {
            cout << "Invalid connection input.\n";
            return 0;
        }

        network.addConnection(u, v);
    }

    network.displayGraph();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string startName;
    cout << "\nEnter person to start traversal: ";
    getline(cin, startName);

    int start = network.findPerson(startName);

    if (start == -1) {
        cout << "Person not found!\n";
        return 0;
    }

    network.BFS(start);
    network.DFS(start);

    return 0;
}
