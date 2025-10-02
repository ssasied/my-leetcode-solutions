class FooBar {
private:
    int n;

public:

    condition_variable cv1, cv2;
    
     mutex m;
     bool fooTurn = true;
    FooBar(int n) {
        this->n = n;
    }
    void foo(function<void()> printFoo) {        
        for (int i = 0; i < n; i++) {            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(m);
            cv1.wait(lock, [&]{ return fooTurn; });
        	printFoo();
            fooTurn=false;
            cv2.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv2.wait(lock, [&]{ return !fooTurn; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooTurn=true;           
            cv1.notify_one();
        }
    }
};