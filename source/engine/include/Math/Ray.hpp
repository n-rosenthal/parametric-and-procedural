/**
 * @file    `Ray.hpp`
 * @author  n-rosenthal
 * @brief   Header for the implementation of the `Ray` class.
 * @details A ray is a geometric object that has an origin and a direction. It is defined by the equation:
 *              P(t) = O + t * D
 *          where P(t) is a point on the ray, O is the origin, D is the direction, and t is a scalar parameter. The ray extends infinitely in the direction of D.
 *          The `Ray` class provides methods to compute points along the ray, as well as methods to compute intersections with other geometric objects.
 * @version 0.1
 * @date    2026-07-11
 */

#pragma once

#include <glm/glm.hpp>
#include <stdexcept>

namespace Math {
    class Ray {
    public:
        /**
         * @brief Default constructor for the `Ray` class.
         */
        Ray() = default;

        /**
         * @brief   Constructs a `Ray` object with the given origin and direction.
         * @param   origin (glm::vec3)
         *          The origin point of the ray.
         * @param   direction (glm::vec3)
         *          The direction vector of the ray.
         */
        Ray(const glm::vec4& origin,
            const glm::vec4& direction)
            :   origin(origin),
                direction(glm::normalize(direction)) {};

        /**
         * @brief   Returns a point along the ray at parameter t.
         * @param   t (float)
         *          The parameter t >= 0.
         * @return  glm::vec4
         *          The point along the ray at parameter t.
         * 
         * @throws std::invalid_argument if t < 0.
         */
        glm::vec4 point(float t) const {
            if (t < 0.0f) {
                throw std::invalid_argument("[ERROR::Math::Ray::point()] Parameter `t` must be non-negative, got `" + 
                                            std::to_string(t) + "` instead.");
            }

            //  P(t) = O + t * D
            return origin + t * direction;
        };


        /**
         * @brief   Getter for the origin of the ray.
         * @return  glm::vec4
         *          The origin of the ray.
         */
        glm::vec4 getOrigin() const { return origin; }

        /**
         * @brief   Getter for the direction of the ray.
         * @return  glm::vec4
         *          The direction of the ray.
         */
        glm::vec4 getDirection() const { return direction; }
    private:
        glm::vec4 origin;
        glm::vec4 direction;
    };
};