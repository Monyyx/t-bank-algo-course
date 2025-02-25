#include <bits/stdc++.h>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;// добавлять и удалять
    stack<int> minStack, maxStack; // хранить мин и макс знач и назодить их за O(1)
    int sum;

    void transfer() {//перемещать эл-ты из одного стека в другой
        while (!s1.empty()) {
            int val = s1.top();
            s1.pop();
            s2.push(val);
            // одновим максимум
            if (maxStack.empty() || val >= maxStack.top()) {
                maxStack.push(val);
            } else {
                maxStack.push(maxStack.top());
            }
            if (minStack.empty() || val <= minStack.top()) {
                minStack.push(val);
            } else {
                minStack.push(minStack.top());
            }
        }
    }

public:
    QueueUsingStacks() : sum(0) {}

    void addToQueue(int val) {
        s1.push(val);
        sum += val;
    }

    void delFromQueue() {
        if (s2.empty()) {
            transfer();
        }
        if (s2.empty()) {
            cout << "empty" << '\n';
            return;
        }
        int val = s2.top();
        s2.pop();
        sum -= val;
        maxStack.pop();
        minStack.pop();
    }

    int getMin() const {
        if (s2.empty() && minStack.empty()) {
            cout << "empty" << '\n';
        }
        return minStack.top();
    }

    int getMax() const {
        if (s2.empty() && maxStack.empty()) {
            cout << "empty" << '\n';
        }
        return maxStack.top();
    }

    int getSum() const {
        return sum;
    }
};

int main() {
    QueueUsingStacks q;
    q.addToQueue(3);
    q.addToQueue(1);
    q.addToQueue(5);
    q.addToQueue(2);

    cout << "Min: " << q.getMin() << '\n';
    cout << "Max: " << q.getMax() << '\n';
    cout << "Sum: " << q.getSum() << '\n';

    q.delFromQueue();
    cout << "After deleting..." << '\n';
    cout << "Min: " << q.getMin() << '\n';
    cout << "Max: " << q.getMax() << '\n';
    cout << "Sum: " << q.getSum() << '\n';

    return 0;
  }
