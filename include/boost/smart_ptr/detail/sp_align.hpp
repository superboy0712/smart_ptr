/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_SMART_PTR_DETAIL_SP_ALIGN_HPP
#define BOOST_SMART_PTR_DETAIL_SP_ALIGN_HPP

#include <boost/config.hpp>
#if !defined(BOOST_NO_CXX11_STD_ALIGN)
#include <memory>
#endif

namespace boost {
    namespace detail {
#if !defined(BOOST_NO_CXX11_STD_ALIGN)
        inline void* sp_align(std::size_t alignment, void* ptr) {
            std::size_t n1 = alignment - 1;
            std::align(alignment, 0, ptr, n1);
            return ptr;
        }
#else
        inline void* sp_align(std::size_t alignment, void* ptr) {
            std::size_t n1 = (std::size_t)ptr % alignment;
            if (n1 != 0) {
                ptr = (char*)ptr + alignment - n1;
            }
            return ptr;
        }
#endif
    }
}

#endif
