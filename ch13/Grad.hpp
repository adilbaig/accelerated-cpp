/*
 * Grad.hpp
 *
 *  Created on: 16-Nov-2016
 *      Author: adil
 */

#ifndef CH13_GRAD_HPP_
#define CH13_GRAD_HPP_

#include "Core.hpp"

/**
 * The `public` in `public Core` means Grad inheirts the public interface to Core
 * which becomes part of the public interface to grad.
 *
 * The public members of Core are effectively public members of Grad.
 *
 * pg.228
 */
class Grad : public Core {

public:
	/**
	 * Grad has all public members of core except:
	 * ctors, operator= & dtor
	 */

    Grad();
    Grad(std::istream&);
    double grade() const;
    std::istream& read(std::istream&);
    
protected:
    Grad* clone() const;

private:
    double thesis;
};



#endif /* CH13_GRAD_HPP_ */
