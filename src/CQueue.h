#ifndef CQUEUE_H
#define CQUEUE_H

template <class T> class CQueue {
    private:
        T *array;
        int capacity;
        int front, rear;

    public:
        CQueue(int cap) {
            array = new T[cap]; // create a new continuous array space
            capacity = cap;
            front = 0;
            rear = cap - 1;
        }

        bool IsEmpty() {
            return (front == (rear + 1) % capacity);
        }

        bool IsFull() {
            return (front == (rear + 2) % capacity);
        }

        const T& Front() {
            assert(!IsEmpty());
            return array[front];
        }

        void DeQueue() {
            assert(!IsEmpty());
            front = (front + 1) % capacity;
        }

        void EnQueue(const T& newItem) {
            assert(!IsFull());
            rear = (rear + 1) % capacity;
            array[rear] = newItem;
        }

};

#endif
