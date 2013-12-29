//à¯ópå≥ÅFhttp://www.ogis-ri.co.jp/otc/hiroba/technical/boost/part2/index.html

#include <cassert>
#include <fstream>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/nvp.hpp>

class MyClass {
public:
	MyClass() :data1_(0) {}
	void setData1(int val)
	{
		data1_ = val;
	}
	int getData1() const
	{
		return data1_;
	}
private:
	// serialize
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int /* file_version */)
	{
		ar & BOOST_SERIALIZATION_NVP(data1_);
	}
	int data1_;
};

int main()
{
	{
		// serialize
		MyClass m;
		m.setData1(123);
		std::ofstream ofs("output.xml");
		assert(ofs);
		boost::archive::xml_oarchive oa(ofs);
		oa << BOOST_SERIALIZATION_NVP(m);
	}
	{
		// de-serialize
		std::ifstream ifs("output.xml");
		assert(ifs);
		boost::archive::xml_iarchive ia(ifs);
		MyClass m;
		ia >> BOOST_SERIALIZATION_NVP(m);
		// check
		assert(m.getData1() == 123);
	}
}

// End of file
