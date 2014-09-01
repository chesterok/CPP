#ifndef MOHICAN_H
#define MOHICAN_H

#include <iostream>

class Mohican {
    private:
        Mohican* prev;
        Mohican* next;
        std::string name;  
        static Mohican* lastMohican;
        
    public:
        Mohican(std::string name);
        ~Mohican();
        static Mohican& getLastMohican();
        const std::string& getName() const;
};

#endif // MOHICAN_H
