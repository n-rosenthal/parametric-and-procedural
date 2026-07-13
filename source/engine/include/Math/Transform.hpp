/**
 * @file    `Transform.hpp`
 * @author  n-rosenthal
 * @brief   Header for the implementation of the `Transform` class.
 * @details The `Transform` class encapsulates geometric transformations (linear or affine) that can be applied to geometric objects.
 * @version 0.1
 * @date    2026-07-11
 */

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Math {
    /**
     * @brief   Currently, the `Transform` class is a simple implementation that allows for the creation of a general *modeling matrix* applicable to all objects in a virtual scene. It encapsulates translation, rotation (using Euler angles), and scaling transformations.
     */
    class Transform {
    public:
        glm::vec3 position{0.f};
        glm::vec3 rotation{0.f};      // Euler angles (radians)
        glm::vec3 scale{1.f};


        /**
            * @brief   Computes the modeling matrix for the transform.
            * 
            * @return glm::mat4
            *          The modeling matrix for the transform.
            */
        glm::mat4 ModelMatrix() const{
            //  Initializes the matrix as all-ones
            glm::mat4 M(1.f);

            //  The translation matrix for a given position 
            //  M = T
            M = glm::translate(M, position);

            //  The rotation matrices for given rotations
            //  M = Rz * Ry * Rx * T
            M = glm::rotate(M, rotation.x,
                            glm::vec3(1,0,0));

            M = glm::rotate(M, rotation.y,
                            glm::vec3(0,1,0));

            M = glm::rotate(M, rotation.z,
                            glm::vec3(0,0,1));

            //  The scaling matrix for a given scale
            //  M = S * (Rz * Ry * Rx) * T
            M = glm::scale(M, scale);

            return M;
        }
    };
}