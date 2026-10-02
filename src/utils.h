#pragma once
#include <functional>

// TypeDefs
using vecInt = std::vector<int>;

// Structs
struct EnumHash {
	template <typename T>
	std::size_t operator()(T e) const {
		return std::hash<std::underlying_type_t<T>>{}(
			static_cast<std::underlying_type_t<T>>(e)
		);
	}
};