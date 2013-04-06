//  exception.hpp -- extensions to the std::exception hierarchy
//  Copyright (C) 2013  SEIKO EPSON CORPORATION
//
//  License: GPL-3.0+
//  Author : AVASYS CORPORATION
//
//  This file is part of the 'Utsushi' package.
//  This package is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License or, at
//  your option, any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//  You ought to have received a copy of the GNU General Public License
//  along with this package.  If not, see <http://www.gnu.org/licenses/>.

#ifndef utsushi_exception_hpp_
#define utsushi_exception_hpp_

#include <stdexcept>

namespace utsushi {

//! Device related error conditions
/*! Inspired by C++11's std::system_error but the interface has got
 *  the std::error_code objects and error code values (such as those
 *  in std::errc) confused and misses out on std::error_category.
 *
 *  \todo Align with C++11's std::system_error and "friends"
 */
class system_error
  : public std::runtime_error
{
public:
  enum error_code {
    unknown_error,
    cover_open,
    media_out,
    media_jam,
  };

  system_error (error_code ec, const std::string& message);
  system_error (error_code ec, const char *message);

  const error_code& code () const;

private:
  error_code ec_;
};

}       // namespace utsushi

#endif  /* utsushi_exception_hpp_ */