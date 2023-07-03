
// BUG (MSVC):
//
// Exclude `stdafx.hxx` reprocessing when "__build2_preprocess" is defined. This
// is necessary to prevent the linker from spinning infinitely and leaking
// increasingly large amounts of memory—around 1GB every few seconds—in such
// scenarios.
//
// Moreover, interrupting the process may sometimes result in the linker
// continuing to run in the background, which can be quite horrifying when it
// goes unnoticed.
//

# pragma   once
# ifndef __build2_preprocess

// Make the standard library widely accessible by pre-compiling all its headers.
//
// Note that since not every part of the standard library is used in the source
// code, there's a chance that we can still compile successfully even if a
// specific header implementation is missing from, say, GCC.
//
// This is because if the missing header wasn't utilized in the first place, it
// won't affect the compilation process. To anticipate and prevent any potential
// issues with #include directives, we rely on the __has_include expression.
//

// Concepts library
# if __has_include (<concepts>)
# include <concepts>             // Fundamental library concepts (C++20)
# endif

// Coroutines library
# if __has_include (<coroutine>)
# include <coroutine>            // Coroutine support library (C++20)
# endif

// Utilities library
# if __has_include (<any>)
# include <any>                  // std::any class (C++17)
# endif
# if __has_include (<bitset>)
# include <bitset>               // std::bitset class template
# endif
# if __has_include (<chrono>)
# include <chrono>               // C++ time utilites (C++11)
# endif
# if __has_include (<compare>)
# include <compare>              // Three-way comparison operator support (C++20)
# endif
# if __has_include (<csetjmp>)
# include <csetjmp>              // Macro (and function) that saves (and jumps) to an execution context
# endif
# if __has_include (<csignal>)
# include <csignal>              // Functions and macro constants for signal management
# endif
# if __has_include (<cstdarg>)
# include <cstdarg>              // Handling of variable length argument lists
# endif
# if __has_include (<cstddef>)
# include <cstddef>              // Standard macros and typedefs
# endif
# if __has_include (<cstdlib>)
# include <cstdlib>              // General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search
# endif
# if __has_include (<ctime>)
# include <ctime>                // C-style time/date utilites
# endif
# if __has_include (<expected>)
# include <expected>             // std::expected class template (C++23)
# endif
# if __has_include (<functional>)
# include <functional>           // Function objects, Function invocations, Bind operations and Reference wrappers
# endif
# if __has_include (<initializer_list>)
# include <initializer_list>     // std::initializer_list class template (C++11)
# endif
# if __has_include (<optional>)
# include <optional>             // std::optional class template (C++17)
# endif
# if __has_include (<source_location>)
# include <source_location>      // Supplies means to obtain source code location (C++20)
# endif
# if __has_include (<tuple>)
# include <tuple>                // std::tuple class template (C++11)
# endif
# if __has_include (<type_traits>)
# include <type_traits>          // Compile-time type information (C++11)
# endif
# if __has_include (<typeindex>)
# include <typeindex>            // std::type_index (C++11)
# endif
# if __has_include (<typeinfo>)
# include <typeinfo>             // Runtime type information utilities
# endif
# if __has_include (<utility>)
# include <utility>              // Various utility components
# endif
# if __has_include (<variant>)
# include <variant>              // std::variant class template (C++17)
# endif
# if __has_include (<version>)
# include <version>              // Supplies implementation-dependent library information (C++20)
# endif

// Dynamic memory management
# if __has_include (<memory>)
# include <memory>               // High-level memory management utilities
# endif
# if __has_include (<memory_resource>)
# include <memory_resource>      // Polymorphic allocators and memory resources (C++17)
# endif
# if __has_include (<new>)
# include <new>                  // Low-level memory management utilities
# endif
# if __has_include (<scoped_allocator>)
# include <scoped_allocator>     // Nested allocator class (C++11)
# endif

// Numeric limits
# if __has_include (<cfloat>)
# include <cfloat>               // Limits of floating-point types
# endif
# if __has_include (<cinttypes>)
# include <cinttypes>            // Formatting macros, intmax_t and uintmax_t math and conversions (C++11)
# endif
# if __has_include (<climits>)
# include <climits>              // Limits of integral types
# endif
# if __has_include (<cstdint>)
# include <cstdint>              // Fixed-width integer types and limits of other types (C++11)
# endif
# if __has_include (<limits>)
# include <limits>               // Uniform way to query properties of arithmetic types
# endif

// Error handling
# if __has_include (<cassert>)
# include <cassert>              // Conditionally compiled macro that compares its argument to zero
# endif
# if __has_include (<cerrno>)
# include <cerrno>               // Macro containing the last error number
# endif
# if __has_include (<exception>)
# include <exception>            // Exception handling utilities
# endif
# if __has_include (<stdexcept>)
# include <stdexcept>            // Standard exception objects
# endif
# if __has_include (<system_error>)
# include <system_error>         // Defines std::error_code, a platform-dependent error code (C++11)
# endif
# if __has_include (<stacktrace>)
# include <stacktrace>           // Stacktrace library (C++23)
# endif

// Strings library
# if __has_include (<cctype>)
# include <cctype>               // Functions to determine the category of narrow characters
# endif
# if __has_include (<charconv>)
# include <charconv>             // std::to_chars and std::from_chars (C++17)
# endif
# if __has_include (<cstring>)
# include <cstring>              // Various narrow character string handling functions
# endif
# if __has_include (<cuchar>)
# include <cuchar>               // C-style Unicode character conversion functions (C++11)
# endif
# if __has_include (<cwchar>)
# include <cwchar>               // Various wide and multibyte string handling functions
# endif
# if __has_include (<cwctype>)
# include <cwctype>              // Functions to determine the catagory of wide characters
# endif
# if __has_include (<format>)
# include <format>               // Formatting library including std::format (C++20)
# endif
# if __has_include (<string>)
# include <string>               // std::basic_string class template
# endif
# if __has_include (<string_view>)
# include <string_view>          // std::basic_string_view class template (C++17)
# endif

// Containers library
# if __has_include (<array>)
# include <array>                // std::array container (C++11)
# endif
# if __has_include (<deque>)
# include <deque>                // std::deque container
# endif
# if __has_include (<forward_list>)
# include <forward_list>         // std::forward_list container (C++11)
# endif
# if __has_include (<list>)
# include <list>                 // std::list container
# endif
# if __has_include (<map>)
# include <map>                  // std::map and std::multimap associative containers
# endif
# if __has_include (<queue>)
# include <queue>                // std::queue and std::priority_queue container adaptors
# endif
# if __has_include (<set>)
# include <set>                  // std::set and std::multiset associative containers
# endif
# if __has_include (<span>)
# include <span>                 // std::span view (C++20)
# endif
# if __has_include (<stack>)
# include <stack>                // std::stack container adaptor
# endif
# if __has_include (<unordered_map>)
# include <unordered_map>        // std::unordered_map and std::unordered_multimap unordered associative containers (C++11)
# endif
# if __has_include (<unordered_set>)
# include <unordered_set>        // std::unordered_set and std::unordered_multiset unordered associative containers (C++11)
# endif
# if __has_include (<vector>)
# include <vector>               // std::vector container
# endif

// Iterators library
# if __has_include (<iterator>)
# include <iterator>             // Range iterators
# endif

// Ranges library
# if __has_include (<ranges>)
# include <ranges>               // Range access, primitives, requirements, utilities and adaptors (C++20)
# endif

// Algorithms library
# if __has_include (<algorithm>)
# include <algorithm>            // Algorithms that operate on ranges
# endif
# if __has_include (<execution>)
# include <execution>            // Predefined execution policies for parallel versions of the algorithms (C++17)
# endif

// Numerics library
# if __has_include (<bit>)
# include <bit>                  // Bit manipulation functions (C++20)
# endif
# if __has_include (<cfenv>)
# include <cfenv>                // Floating-point environment access functions (C++11)
# endif
# if __has_include (<cmath>)
# include <cmath>                // Common mathematics functions
# endif
# if __has_include (<complex>)
# include <complex>              // Complex number type
# endif
# if __has_include (<numbers>)
# include <numbers>              // Math constants (C++20)
# endif
# if __has_include (<numeric>)
# include <numeric>              // Numeric operations on values in ranges
# endif
# if __has_include (<random>)
# include <random>               // Random number generators and distributions (C++11)
# endif
# if __has_include (<ratio>)
# include <ratio>                // Compile-time rational arithmetic (C++11)
# endif
# if __has_include (<valarray>)
# include <valarray>             // Class for representing and manipulating arrays of values
# endif

// Localization library
# if __has_include (<clocale>)
# include <clocale>              // C localization utilities
# endif
# if __has_include (<codecvt>)
# include <codecvt>              // Unicode conversion facilities (C++11) (deprecated in C++17)
# endif
# if __has_include (<locale>)
# include <locale>               // Localization utilities
# endif

// Input/output library
# if __has_include (<cstdio>)
# include <cstdio>               // C-style input-output functions
# endif
# if __has_include (<fstream>)
# include <fstream>              // std::basic_fstream, std::basic_ifstream, std::basic_ofstream class templates and several typedefs
# endif
# if __has_include (<iomanip>)
# include <iomanip>              // Helper functions to control the format of input and output
# endif
# if __has_include (<ios>)
# include <ios>                  // std::ios_base class, std::basic_ios class template and several typedefs
# endif
# if __has_include (<iosfwd>)
# include <iosfwd>               // Forward declarations of all classes in the input/output library
# endif
# if __has_include (<iostream>)
# include <iostream>             // Several standard stream objects
# endif
# if __has_include (<istream>)
# include <istream>              // std::basic_istream class template and several typedefs
# endif
# if __has_include (<ostream>)
# include <ostream>              // std::basic_ostream, std::basic_iostream class templates and several typedefs
# endif
# if __has_include (<spanstream>)
# include <spanstream>           // std::basic_spanstream, std::basic_ispanstream, std::basic_ospanstream class templates and typedefs (C++23)
# endif
# if __has_include (<sstream>)
# include <sstream>              // std::basic_stringstream, std::basic_istringstream, std::basic_ostringstream class templates and several typedefs
# endif
# if __has_include (<streambuf>)
# include <streambuf>            // std::basic_streambuf class template
# endif
# if __has_include (<strstream>)
# include <strstream>            // std::strstream, std::istrstream, std::ostrstream (deprecated in C++98)
# endif
# if __has_include (<syncstream>)
# include <syncstream>           // std::basic_osyncstream, std::basic_syncbuf, and typedefs (C++20)
# endif

// Filesystem library
# if __has_include (<filesystem>)
# include <filesystem>           // std::path class and supporting functions (C++17)
# endif

// Regular Expressions library
# if __has_include (<regex>)
# include <regex>                // Classes, algorithms and iterators to support regular expression processing (C++11)
# endif

// Atomic Operations library
# if __has_include (<atomic>)
# include <atomic>               // Atomic operations library (C++11)
# endif

// Thread support library
# if __has_include (<barrier>)
# include <barrier>              // Barriers (C++20)
# endif
# if __has_include (<condition_variable>)
# include <condition_variable>   // Thread waiting conditions (C++11)
# endif
# if __has_include (<future>)
# include <future>               // Primitives for asynchronous computations (C++11)
# endif
# if __has_include (<latch>)
# include <latch>                // Latches (C++20)
# endif
# if __has_include (<mutex>)
# include <mutex>                // Mutual exclusion primitives (C++11)
# endif
# if __has_include (<semaphore>)
# include <semaphore>            // Semaphores (C++20)
# endif
# if __has_include (<shared_mutex>)
# include <shared_mutex>         // Shared mutual exclusion primitives (C++14)
# endif
# if __has_include (<stop_token>)
# include <stop_token>           // Stop tokens for std::jthread (C++20)
# endif
# if __has_include (<thread>)
# include <thread>               // std::thread class and supporting functions (C++11)
# endif

namespace hello
{
  // The standard library is used pervasively so requiring std:: everywhere
  // could be distracting.
  //
  // While this leaves us open to a name clash with the standard library, it is
  // not particularly likely to lead to a resolution that is not an error
  // and—obviously—we are aware of the standard library and the associated risk.
  //
  using namespace std;
}

# endif
