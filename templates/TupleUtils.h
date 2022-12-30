#ifndef TEMPLATES_TUPLEUTILS_H
#define TEMPLATES_TUPLEUTILS_H

#include <tuple>
#include <iostream>
#include <sstream>
#include <vector>

namespace tupleUtils {
    template<int index, typename CallElement, typename... Args>
    struct iterate {
        static void next(std::tuple<Args...> &t, CallElement call, std::vector<std::string>::iterator &it) {
            iterate<index - 1, CallElement, Args...>::next(t, call, it);
            call(std::get<index>(t), it);
        }
    };

    template<typename CallElement, typename... Args>
    struct iterate<0, CallElement, Args...> {
        static void next(std::tuple<Args...> &t, CallElement call, std::vector<std::string>::iterator &it) {
            call(std::get<0>(t), it);
        }
    };

    template<typename CallElement, typename ...Args>
    void ForAll(std::tuple<Args...> &t, CallElement call, std::vector<std::string>::iterator &it) {
        int const t_size = std::tuple_size<std::tuple<Args...>>::value;
        iterate<t_size - 1, CallElement, Args...>::next(t, call, it);
    }

    struct call {
        template<typename Type>
        void operator()(Type &t, std::vector<std::string>::iterator &it) {
            std::stringstream ss;
            ss << *it;
            ss >> t;
            ++it;
        }
    };

    template<typename ...Args>
    void parse(std::tuple<Args...> &t, std::vector<std::string>::iterator &it) {
        ForAll(t, call(), it);
    }
}
#endif //TEMPLATES_TUPLEUTILS_H
