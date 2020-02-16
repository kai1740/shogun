/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Gil Hoben
 */

#ifndef SHOGUNTYPES_H_
#define SHOGUNTYPES_H_

#ifdef USE_NGRAPH
#include <ngraph/ngraph.hpp>
#endif

namespace shogun
{
	namespace graph {
		enum class element_type
		{
			FLOAT32 = 0,
			FLOAT64 = 1
		};

		template <element_type EnumVal>
		struct get_type_from_enum
		{
		};

		template <>
		struct get_type_from_enum<element_type::FLOAT32>
		{
			using type = float32_t;
		};

		template <>
		struct get_type_from_enum<element_type::FLOAT64>
		{
			using type = float64_t;
		};

		inline size_t get_size_from_enum(element_type type)
		{
			switch (type)
			{
			case element_type::FLOAT32:
				return sizeof(get_type_from_enum<element_type::FLOAT32>::type);
			case element_type::FLOAT64:
				return sizeof(get_type_from_enum<element_type::FLOAT64>::type);
			}
		}

		template <typename T>
		struct get_enum_from_type
		{
		};

		template <>
		struct get_enum_from_type<float32_t>
		{
			static constexpr element_type type = element_type::FLOAT32;
		};

		template <>
		struct get_enum_from_type<float64_t>
		{
			static constexpr element_type type = element_type::FLOAT64;
		};

		inline std::ostream& operator<<(std::ostream& os, element_type type)
		{
			switch (type)
			{
			case element_type::FLOAT32:
				return os << "float32";
			case element_type::FLOAT64:
				return os << "float64";
			}
		}

		inline size_t get_byte_size(element_type type)
		{
			switch(type)
			{
				case element_type::FLOAT32:
					return sizeof(float32_t);
				case element_type::FLOAT64:
					return sizeof(float64_t);
			}
		}
	}
} // namespace shogun

#endif