class Foo {
public:
    Foo() {}

private:
    mutex m;
    condition_variable cv1, cv2;
    bool ready1 = false, ready2 = false;

public:
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        {
            lock_guard<mutex> lock(m);
            ready1 = true;
        }
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv1.wait(lock, [&]{ return ready1; });
        printSecond();
        ready2 = true;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv2.wait(lock, [&]{ return ready2; });
        printThird();
    }
};