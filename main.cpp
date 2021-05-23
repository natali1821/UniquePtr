#include "templates.cpp"

int main()
{
	int* data = new int[256];
	UniquePtr<int> ptr(data);
	UniquePtr<int> ptr1;
	ptr1 = std::move(ptr1);
	UniquePtr<int> ptr2;
	char* s = new char[20];
	UniquePtr<char> ptr3(s);
	std::cout << ptr.get() << std::endl;
	std::cout << "ptr is " << (static_cast<bool>(ptr) ? "not nullptr" : "nullptr") << std::endl;
	std::cout << "ptr1 is " << (static_cast<bool>(ptr1) ? "not nullptr" : "nullptr") << std::endl;
	std::cout << "ptr3 is " << (static_cast<bool>(ptr3) ? "not nullptrn" : "nullptr") << std::endl;
}
