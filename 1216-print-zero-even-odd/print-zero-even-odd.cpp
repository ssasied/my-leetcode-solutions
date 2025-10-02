class ZeroEvenOdd {
private:
    int n;
    int counter=1;
    bool zeroTurn = true;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }
    std::mutex mtx;
    std::condition_variable cv;
    // printNumber(x) outputs "x", where x is an integer.
      void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return zeroTurn; });

            printNumber(0);

            zeroTurn = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return counter > n || (!zeroTurn && counter % 2 == 0); });

            if (counter > n) return; 

            printNumber(counter++);
            zeroTurn = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return counter > n || (!zeroTurn && counter % 2 == 1); });

            if (counter > n) return; 

            printNumber(counter++);
            zeroTurn = true;
            cv.notify_all();
        }
    }
};
