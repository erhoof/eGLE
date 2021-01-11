//
// Created by erhoof on 11.01.2021.
//

#ifndef EGLE_DEBUG_H
#define EGLE_DEBUG_H

#include <iostream>

namespace eGLE
{
    class Debug {
    public:
        static void halt(const char *line)
        {
            std::cout << "[eGLE] Halt! msg: " << line << std::endl;
        }

        template <typename Arg, typename... Args>
        static void msg(Arg&& arg, Args&&... args)
        {
            std::cout << "[eGLE] msgs: " << std::forward<Arg>(arg);
            using expander = int[];
            (void)expander{0, (void(std::cout << "," << std::forward<Args>(args)), 0)...};
            std::cout << std::endl;
        }
    };
}

#endif //EGLE_DEBUG_H
