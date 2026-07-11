/**
 * @file    `BoundingBox.cpp`
 * @author  n-rosenthal
 * @brief   Implementation of the `BoundingBox` class.
 * @details A bounding box defines the minimum and maximum points of the object contained within it.
 * @version 0.1
 * @date 2026-07-10
 */

#include "Definitions/BoundingBox.hpp"

BoundingBox::BoundingBox(glm::vec4 min, glm::vec4 max) : min(min), max(max) {};