#pragma once
#include "root.cpp"

// the graph here is a 2D vector
// if graph[i] contains j, then edge (i, j) exists.

enum class State { init, entered = 1, children_entered, exited };
// you can choose to keep only one of children_entered and exited
// I just didn't want the identifiers to lose their denotation

namespace Iterative {
    // the function callstack will thank you
    
    void bfs(vector<set<int>> &graph, int root) {
        int n = graph.size();
        queue<int> q; 
        vector<State> state(n, State(0));

        q.push(root); state[root] = State::entered;

        while (!q.empty()) {
            auto node = q.front(); 

            q.pop(); state[node] = State::exited;
            // process the node
            
            for (auto i : graph[node])
                if (state[i] == State::init) 
                    { q.push(i); state[i] = State::entered; }
        }
    }

    void dfs(vector<set<int>> &graph, int root) { // preorder traversal
        int n = graph.size();
        stack<int> s; 
        vector<State> state(n, State(0));

        s.push(root); state[root] = State::entered;

        while (!s.empty()) {
            auto node = s.top(); 
            
            s.pop(); state[node] = State::exited;
            // process the node
            
            for (auto i : graph[node])
                if (state[i] == State::init)
                    { s.push(i); state[i] = State::entered; }
        }
    }

    void postdfs(vector<set<int>> &graph, int root) { // postorder traversal
        int n = graph.size();
        stack<int> s;
        vector<State> state(n, State(0));

        s.push(root); state[root] = State::entered;

        while (!s.empty()) {
            auto node = s.top();
            
            if (state[node] == State::entered) { // traverse through the children
                for (auto i : graph[node])
                    if (state[i] == State::init)
                        { s.push(i); state[i] = State::entered; }
                
                state[node] = State::children_entered;

            } else { // state[node] == State::children_entered
                s.pop(); state[node] = State::exited;
                // process the node
            }
        }
    }
}

namespace StateRecursive {
    void dfs(vector<set<int>> &graph, int root, vector<State> &state) {
        state[root] = State::entered;
        // process the node (preorder)

        for (auto i : graph[root])
            if (state[i] == State::init) // making sure it's the children and not the parent
                dfs(graph, i, state);

        state[root] = State::exited;
        // process the node (postorder)
    }
}

namespace Recursive { // declarative, no state maintained
    void dfs(vector<set<int>> &graph, int root, int parent = -1) {
        // process the node (preorder)

        for (auto i : graph[root])
            if (i != parent)
                dfs(graph, i, root);

        // process the node (postorder)
    }
}