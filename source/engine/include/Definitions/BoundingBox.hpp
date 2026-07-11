#pragma once
/**
 * @brief   Header for the implementation of the `BoundingBox` class.
 * @details A bounding box defines the minimum and maximum points of the object contained within it. It is used for collision detection and spatial partitioning.
 * @author  n-rosenthal
 * @version 0.1
 * @date    2026-07-10
 */

#include <glm/glm.hpp>

class   BoundingBox {
public:
    BoundingBox(glm::vec4 min, glm::vec4 max);

    glm::vec4 getMin() const { return min; }
    glm::vec4 getMax() const { return max; }
private:
    glm::vec4 min;
    glm::vec4 max;
};