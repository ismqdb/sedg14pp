/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>
#include <vector>
#include <functional>
#include <atomic>
#include <cassert>

/* ******************************************************************************** */

#include "Snippets/23. sort/23. qsort.hpp"

/* ******************************************************************************** */

i32 main(){
	class Foo {};

	Foo someArray[5];

	std::atomic<Foo*> p(someArray);

	Foo* x = p.fetch_add(2);
	assert(x == someArray);
	assert(p.load() == &someArray[2]);

	x = (p -= 1);

	assert(x == &someArray[1]);
	assert(p.load() == &someArray[1]);
}

/* ******************************************************************************** */