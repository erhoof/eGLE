//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_SHADERTOOLS_H
#define EGLE_SHADERTOOLS_H

#include <string>

/* File Extensions Note
 *  .vert - a vertex shader
    .tesc - a tessellation control shader
    .tese - a tessellation evaluation shader
    .geom - a geometry shader
    .frag - a fragment shader
    .comp - a compute shader
 * */

namespace eGLE
{
    void checkError(int shader, int flag, const char *msg);
    std::string loadShaderFile(const char *filename);
}

#endif //EGLE_SHADERTOOLS_H
