// debugger.h
#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <bits/stdc++.h>
using namespace std;

// Utility function to repeat a string multiple times (for indentation)
inline string repeatString(const string &str, int count)
{
    string result;
    for (int i = 0; i < count; ++i)
    {
        result += str;
    }
    return result;
}

// Base printer for single elements
template <typename T>
void printer(const T &x, int indent = 0)
{
    cerr << x;
}

// Printer for 2D Array
template <typename T>
void printer(const T &x, int rows, int cols, int indent = 0)
{
    cerr << "[\n";
    for (int i = 0; i < rows; ++i)
    {
        cerr << repeatString("    ", indent + 1);
        for (int j = 0; j < cols; ++j)
        {
            printer(x[i][j], indent + 1);
            if (j != cols - 1)
                cerr << ", ";
        }
        cerr << "\n";
    }
    cerr << repeatString("    ", indent) << "]";
}

// Printer for pairs
template <typename T, typename V>
void printer(const pair<T, V> &x, int indent = 0)
{
    cerr << "{";
    printer(x.first, indent);
    cerr << ", ";
    printer(x.second, indent);
    cerr << "}";
}

// Printer for vectors (1D)
template <typename T>
void printer(const vector<T> &vec, int indent = 0)
{
    cerr << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        printer(vec[i], indent);
        if (i != vec.size() - 1)
            cerr << ", ";
    }
    cerr << "]";
}

// Overloaded printer for 2D vectors (e.g., matrices)
template <typename T>
void printer(const vector<vector<T>> &matrix, int indent = 0)
{
    cerr << "[\n";
    for (size_t row = 0; row < matrix.size(); ++row)
    {
        cerr << repeatString("    ", indent + 1) << "Row " << row << ": ";
        printer(matrix[row], indent + 1);
        if (row != matrix.size() - 1)
            cerr << ",";
        cerr << "\n";
    }
    cerr << repeatString("    ", indent) << "]";
}

// Printer for sets
template <typename T>
void printer(const set<T> &s, int indent = 0)
{
    cerr << "{";
    size_t count = 0;
    for (auto it = s.begin(); it != s.end(); ++it, ++count)
    {
        printer(*it, indent);
        if (count != s.size() - 1)
            cerr << ", ";
    }
    cerr << "}";
}

// Printer for multiset
template <typename T>
void printer(const multiset<T> &s, int indent = 0)
{
    cerr << "{";
    size_t count = 0;
    for (auto it = s.begin(); it != s.end(); ++it, ++count)
    {
        printer(*it, indent);
        if (count != s.size() - 1)
            cerr << ", ";
    }
    cerr << "}";
}

// Printer for unordered_sets
template <typename T>
void printer(const unordered_set<T> &s, int indent = 0)
{
    cerr << "{";
    size_t count = 0;
    for (auto it = s.begin(); it != s.end(); ++it, ++count)
    {
        printer(*it, indent);
        if (count != s.size() - 1)
            cerr << ", ";
    }
    cerr << "}";
}

// Printer for maps
template <typename K, typename V>
void printer(const map<K, V> &m, int indent = 0)
{
    cerr << "{\n";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cerr << repeatString("    ", indent + 1) << it->first << ": ";
        printer(it->second, indent + 1);
        if (next(it) != m.end())
            cerr << ",";
        cerr << "\n";
    }
    cerr << repeatString("    ", indent) << "}";
}

// Printer for unordered_maps
template <typename K, typename V>
void printer(const unordered_map<K, V> &m, int indent = 0)
{
    cerr << "{\n";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cerr << repeatString("    ", indent + 1) << it->first << ": ";
        printer(it->second, indent + 1);
        if (next(it) != m.end())
            cerr << ",";
        cerr << "\n";
    }
    cerr << repeatString("    ", indent) << "}";
}

// Printer for stacks
template <typename T>
void printer(stack<T> stk, int indent = 0)
{
    vector<T> elems;
    while (!stk.empty())
    {
        elems.push_back(stk.top());
        stk.pop();
    }
    cerr << "[";
    for (size_t i = 0; i < elems.size(); ++i)
    {
        printer(elems[i], indent);
        if (i != elems.size() - 1)
            cerr << ", ";
    }
    cerr << "]";
}

// Printer for queues
template <typename T>
void printer(queue<T> q, int indent = 0)
{
    vector<T> elems;
    while (!q.empty())
    {
        elems.push_back(q.front());
        q.pop();
    }
    cerr << "[";
    for (size_t i = 0; i < elems.size(); ++i)
    {
        printer(elems[i], indent);
        if (i != elems.size() - 1)
            cerr << ", ";
    }
    cerr << "]";
}

// Printer for priority queues
template <typename T>
void printer(priority_queue<T> pq, int indent = 0)
{
    vector<T> elems;
    while (!pq.empty())
    {
        elems.push_back(pq.top());
        pq.pop();
    }
    cerr << "[";
    for (size_t i = 0; i < elems.size(); ++i)
    {
        printer(elems[i], indent);
        if (i != elems.size() - 1)
            cerr << ", ";
    }
    cerr << "]";
}

// Printer for vector of pairs (Edge List)
template <typename T, typename V>
void printer(const vector<pair<T, V>> &edgeList, int indent = 0)
{
    cerr << "[";
    for (size_t i = 0; i < edgeList.size(); ++i)
    {
        printer(edgeList[i], indent);
        if (i != edgeList.size() - 1)
            cerr << ", ";
    }
    cerr << "]";
}

// Printer for graphs represented as adjacency lists
template <typename T>
void printGraph(const vector<vector<T>> &adjList, int indent = 0)
{
    cerr << "{\n";
    for (size_t node = 0; node < adjList.size(); ++node)
    {
        cerr << repeatString("    ", indent + 1) << "Node " << node << ": [";
        for (size_t i = 0; i < adjList[node].size(); ++i)
        {
            printer(adjList[node][i], indent + 1);
            if (i != adjList[node].size() - 1)
                cerr << ", ";
        }
        cerr << "]";
        if (node != adjList.size() - 1)
            cerr << ",";
        cerr << "\n";
    }
    cerr << repeatString("    ", indent) << "}";
}

// Printer for segment trees represented as vectors
template <typename T>
void printSegmentTree(const vector<T> &segTree, int indent = 0)
{
    cerr << "[\n";
    for (size_t i = 0; i < segTree.size(); ++i)
    {
        cerr << repeatString("    ", indent + 1) << "Index " << i << ": " << segTree[i];
        if (i != segTree.size() - 1)
            cerr << ",";
        cerr << "\n";
    }
    cerr << repeatString("    ", indent) << "]";
}

// Printer for map with pair as key
template <typename K1, typename K2, typename V>
void printer(const map<pair<K1, K2>, V> &m, int indent = 0)
{
    cerr << "{\n";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cerr << repeatString("    ", indent + 1);
        cerr << "{";
        printer(it->first.first, indent + 1);
        cerr << ", ";
        printer(it->first.second, indent + 1);
        cerr << "}: ";
        printer(it->second, indent + 1);
        if (next(it) != m.end())
            cerr << ",";
        cerr << "\n";
    }
    cerr << repeatString("    ", indent) << "}";
}

// Conditional Debug Macros
#ifndef ONLINE_JUDGE
#define dbg(x)                                          \
    cerr << "DBG[" << __LINE__ << "]: " << #x << " = "; \
    printer(x);                                         \
    cerr << "\n";
#define DBG_ROW(x)                                       \
    cerr << "DBG[" << __LINE__ << "]: " << #x << " =\n"; \
    printer(x);                                          \
    cerr << "\n";
#define DBG_GRAPH(x)                                    \
    cerr << "DBG[" << __LINE__ << "]: " << #x << " = "; \
    printGraph(x);                                      \
    cerr << "\n";
#define DBG_SEGMENTTREE(x)                              \
    cerr << "DBG[" << __LINE__ << "]: " << #x << " = "; \
    printSegmentTree(x);                                \
    cerr << "\n";
#define dbgLine() cerr << repeatString("-", 10) << "\n";
#else
#define dbg(x)
#define DBG_ROW(x)
#define DBG_GRAPH(x)
#define DBG_SEGMENTTREE(x)
#define dbgLine()
#endif

#endif // DEBUGGER_H
