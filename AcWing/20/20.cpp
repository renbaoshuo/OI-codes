class MyQueue {
  private:
    queue<int> q;

  public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        return q.front();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
