// https://leetcode.com/problems/print-in-order/

class Foo {
    std::mutex _mutex_second;
    std::mutex _mutex_third;
public:
    Foo() {
        _mutex_second.lock();
        _mutex_third.lock();

    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        _mutex_second.unlock();
    }

    void second(function<void()> printSecond) {
        _mutex_second.lock();

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        _mutex_second.unlock();
        _mutex_third.unlock();
    }

    void third(function<void()> printThird) {
        _mutex_third.lock();

        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        _mutex_third.unlock();
    }
};

///////////////////////////////////////////////////////////////////////////////

class Foo {
    std::mutex _mutex_second;
    std::mutex _mutex_third;
public:
    Foo() {
        _mutex_second.lock();
        _mutex_third.lock();
        
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        _mutex_second.unlock();
    }

    void second(function<void()> printSecond) {
        lock_guard<std::mutex> g(_mutex_second);
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        _mutex_third.unlock();
    }

    void third(function<void()> printThird) {
        lock_guard<std::mutex> g(_mutex_third);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};