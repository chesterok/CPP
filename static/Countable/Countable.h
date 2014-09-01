#ifndef COUNTABLE_H
#define COUNTABLE_H

class Countable {
    private:
    static int counter;   
    public:
        Countable();
        ~Countable();
        static int getCounter();
};

#endif //COUNTABLE_H
