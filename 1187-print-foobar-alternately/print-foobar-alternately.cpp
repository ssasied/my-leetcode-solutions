class FooBar {
private:
    int n;
    int count;

    std::mutex mtx;
    std::condition_variable cv;

public:
    FooBar(int n) : count(0) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]() { return count % 2 == 0; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            count++;
            cv.notify_one();
            lock.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]() { return count % 2 != 0; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            count++;
            cv.notify_one();
            lock.unlock();
        }
    }
};