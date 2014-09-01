#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

class Identifiable {
    private:
        static int lastId;
        int id;  
    public:
        Identifiable();
        ~Identifiable();
        int getId();
};

#endif //IDENTIFIABLE_H
