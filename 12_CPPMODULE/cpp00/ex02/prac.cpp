#include <iostream>

class cat {
	private:
		int age;
		int weight;
	public:
		void meow(void) {
			std::cout << "Meow ~~~" << std::endl;
		}
		void out_meow(void);
		void set_age(void) {
			age = 1;
		}
		void set_weight(void) {
			weight = 5;
		}
		int get_age(void) {
			return (age);
		}
		int get_weight(void) {
			return (weight);
		}
};

void cat::out_meow(void) {
	std::cout << "Meeeowwww~ ~ ~" << std::endl;
}

int main(void)
{
	cat a, b;

	std::cout << "Hello CPP!";
	std::cout << std::endl;
	std::cout << a.get_age() << std::endl;
	std::cout << b.get_weight() << std::endl;
	a.set_age();
	b.set_weight();
	std::cout << a.get_age() << std::endl;
	std::cout << b.get_weight() << std::endl;
	a.meow();
	b.out_meow();
}
