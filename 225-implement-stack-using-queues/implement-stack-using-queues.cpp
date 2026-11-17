#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        
        // Rotate previous elements
        int n = q.size();
        for(int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
