//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_SHADERTOOLS_H
#define EGLE_SHADERTOOLS_H

#include <string>

namespace eGLE
{
    void checkError(int shader, int flag, const char *msg);
    std::string loadShaderFile(const char *filename);
}

#endif //EGLE_SHADERTOOLS_H
