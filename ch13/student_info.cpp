/*
 * student_info.cpp
 *
 *  Created on: 16-Nov-2016
 *      Author: adil
 */

class Student_info {

public:
    Student_info(): cp(0) {}
    Student_info(std::istream& is): cp(0) { read(is); }
    Student_info(const Student_info& s): cp(0) {
        if(s.cp) cp = s.cp->clone();
    }
    Student_info& operator=(const Student_info& s) {
        // Protect against assigning to oneself
        if(&s != this) {
            delete cp;
            if(s.cp)
                cp = s.cp->clone();
            else
                cp = 0;
        }
        
        return *this;
    }
    
    ~Student_info() { delete cp; }
    
    //operations
    std::istream& read(std::istream& is) {
    	delete cp;

    	char ch;
    	is >> ch;

		cp = (ch == 'U') ? new Core(is) : new Grad(is);

    	return is;
    }
    
    std::string name() const {
        if(cp) 
            return cp->name();
        else
            throw std::runtime_error("Uninitialized Student");
    }
    
    double grade() const {
        if(cp) 
            return cp->grade();
        else
            throw std::runtime_error("Uninitialized Student");
    }
    
    static bool compare(const Student_info& c1, const Student_info& c2) {
        return c1.name() < c2.name();
    }
    
private:
    	Core* cp;
};


