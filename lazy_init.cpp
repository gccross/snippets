#include <asio.hpp>
#include <iostream>
#include <memory>

template <typename T>
class lazyinit
{
public:
	template <typename Stream> 
	void  get(Stream& os) const
	{
		if (!static_cast<const T&>(*this).connected) 
		{
			static_cast<const T*>(this)->connect();
			os <<  static_cast<const T*>(this)->stream.rdbuf();
		}
	}
};

class webpull : public lazyinit<webpull>
{
	std::string hostname;
public:
	mutable bool connected;
	mutable boost::asio::ip::tcp::iostream stream;
	webpull(const std::string& hostname_): lazyinit(*this),hostname(hostname_), connected(false)
	{
		std::cout << "Construcor call" << '\n';
	}
	void connect() const
	{
		stream.connect(hostname,"http");
		stream << "GET /LICENSE_1_0.txt HTTP/1.0\r\n";
		stream << "Host: " << hostname << "\r\n";
		stream << "Accept: */*\r\n";
		stream << "Connection: close\r\n\r\n";
		stream.flush();
		connected = true;
	}

};

template <typename OS, typename T>
OS& operator<< (OS& os, const lazyinit<T>& wp)
{
	wp.get(os);	
	return os;
}

int main (const int argc, const char* argv[])
{
	if (argc < 2) 
	{
		std::cout << "usage: " << argv[0] << " <hostname>\n" ;
		return 1;
	}
	webpull wp(argv[1]);
	std::cout << wp << '\n';
	return 0;
}

	
