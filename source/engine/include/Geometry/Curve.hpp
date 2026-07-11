#pragma once
/**
 * @author  n-rosenthal
 * @brief   Header for the implementation of the `Curve` class.
 * @details A curve defines its points, tangent vector and a `BoundingBox` that contains all of its points.
 * @version 0.1
 * @date    2026-07-10
 */

#include <glm/glm.hpp>
#include <vector>

#include "Definitions/Geometry.hpp"
#include "Definitions/BoundingBox.hpp"


class Curve : public Geometry {
public:
    virtual ~Curve() = default;
    virtual glm::vec4 point(float t) const = 0;
    virtual glm::vec4 tangent(float t) const = 0;
    virtual BoundingBox boundingBox() const = 0;
    virtual std::vector<glm::vec4> sample(std::size_t n) const = 0;
};