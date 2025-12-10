/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:54:59 by omizin            #+#    #+#             */
/*   Updated: 2025/12/10 12:43:29 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void printPointer(const std::string& ptr_name, Data* ptr) {
	std::cout << ptr_name << " pointer: " << ptr << std::endl;
	if (ptr)
		std::cout << ptr_name << " -> number: " << ptr->number << ", str: " << ptr->str << std::endl;
	std::cout << "---------------------------\n";
}

int main()
{
	std::cout << "=== Test 1: Basic serialization/deserialization ===\n";
	Data d1;
	d1.number = 42;
	d1.str = "hello";

	printPointer("Original", &d1);

	uintptr_t raw = Serializer::serialize(&d1);
	Data* result = Serializer::deserialize(raw);

	printPointer("Deserialized", result);

	if (result == &d1)
		std::cout << "Test 1 OK: pointers match\n\n";
	else
		std::cout << "Test 1 FAILED: pointers do not match\n\n";


	std::cout << "=== Test 2: Multiple objects ===\n";
	Data d2;
	d2.number = -10;
	d2.str = "another";

	Data d3;
	d3.number = 9999;
	d3.str = "third";

	uintptr_t raw2 = Serializer::serialize(&d2);
	uintptr_t raw3 = Serializer::serialize(&d3);

	Data* r2 = Serializer::deserialize(raw2);
	Data* r3 = Serializer::deserialize(raw3);

	printPointer("d2 deserialized", r2);
	printPointer("d3 deserialized", r3);

	if (r2 == &d2 && r3 == &d3)
		std::cout << "Test 2 OK: both pointers correct\n\n";
	else
		std::cout << "Test 2 FAILED\n\n";

	std::cout << "=== Test 3: Serialization of nullptr ===\n";
	Data* nullPtr = NULL;

	uintptr_t nullRaw = Serializer::serialize(nullPtr);
	Data* restoredNull = Serializer::deserialize(nullRaw);

	printPointer("Restored nullptr", restoredNull);

	if (restoredNull == NULL)
		std::cout << "Test 3 OK: nullptr handled correctly\n\n";
	else
		std::cout << "Test 3 FAILED\n\n";

	std::cout << "\n=== Test 4: Dynamically allocated Data ===\n";
	Data* dyn = new Data();
	dyn->number = 321;
	dyn->str = "dynamic";

	printPointer("Original dynamic", dyn);

	uintptr_t dynRaw = Serializer::serialize(dyn);
	Data* dynRestored = Serializer::deserialize(dynRaw);

	printPointer("Deserialized dynamic", dynRestored);

	if (dynRestored == dyn)
		std::cout << "Test 4 OK: dynamic pointer matches\n";
	else
		std::cout << "Test 4 FAILED\n";

	delete dyn;

	return 0;
}
