/*
 * picture.hpp
 *
 *  Created on: 08-Dec-2016
 *      Author: adil
 */

#ifndef CH15_PICTURE_HPP_
#define CH15_PICTURE_HPP_

class Pic_base {

	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	/*
	 * `= 0` indicates that there will be no other definition of this virtual function.
	 *
	 * This is pure virtual function. (In effect, an abstract function)
	 *
	 * By giving a class even a sinle pure virtual function we are also implicitly specifying that there
	 * will never be objects of that class. (So, this is now an `abstract class`)
	 */
	virtual wd_sz width() const = 0;
	virtual wd_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;

public:
	virtual ~Pic_base() {}

};

class String_pic : public Pic_base {};
class Frame_pic : public Pic_base {};
class VCat_pic : public Pic_base {};
class HCat_pic : public Pic_base {};

//public interface class and operations

class Picture {
public:
	Picture(const std::vector<std::string>& = std::vector<std::string>());

private:
	Ptr<Pic_base> p;
};


Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

#endif /* CH15_PICTURE_HPP_ */
