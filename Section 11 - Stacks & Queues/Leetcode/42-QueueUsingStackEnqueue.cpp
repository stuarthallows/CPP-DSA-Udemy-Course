#include <stack>
#include <climits>
#include <iostream>

using namespace std;

class QueueUsingTwoStacks {
private:
    // stack1 will primarily be used to handle enqueue operations, 
    stack<int> stack1;
    // stack2 will be used to handle dequeue and front operations.
    stack<int> stack2;

public:
    int front() {
        // if s2 is empty move all items from s1 to s2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    void enqueue(int value) {
        stack1.push(value);
    }
};


static void test() {
    cout << "\n----- Test: Enqueue to Empty Queue -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Initial state: empty queue\n";
        cout << "Enqueuing value of 5 to an empty queue:\n";
        queue.enqueue(5);
        cout << "Front result: " << queue.front() << " - EXPECTED: 5\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == 5 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Multiple Enqueues -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing values of 1, 2, and 3 to the queue:\n";
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        cout << "Front result: " << queue.front() << " - EXPECTED: 1\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == 1 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Enqueue Large Numbers -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing maximum integer value:\n";
        queue.enqueue(INT_MAX);
        cout << "Front result: " << queue.front() << " - EXPECTED: " << INT_MAX << "\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == INT_MAX ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Enqueue Negative Numbers -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing values of -5 and -10 to the queue:\n";
        queue.enqueue(-5);
        queue.enqueue(-10);
        cout << "Front result: " << queue.front() << " - EXPECTED: -5\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == -5 ? "PASS\n" : "FAIL\n");
    }
    
}

int main() {
    test();
}

