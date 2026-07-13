#pragma once

/**
 * @file    `Plane.hpp`
 * @author  n-rosenthal
 * @brief   Header for the implementation of the `Plane` class.
 * @details A plane is a geometric object in 3D space that is defined by a normal vector and a point on the plane.
 * @version 0.1
 * @date 2026-07-11
 */

#include <glm/glm.hpp>

namespace Math {
    class Plane {
    public:
        /**
         * @brief Default constructor for the Plane class.
         */
        Plane() = default;

        /**
         * @brief Construct a new Plane object
         * 
         * @param normal    (glm::vec4)
         *                  The normal vector of the plane. It should be a unit vector.
         * @param distance  (float)
         *                  The distance from the origin to the plane along the normal vector.
         */
        Plane(const glm::vec4& normal,
            float distance)
            :   normal_(glm::normalize(normal)),
                distance_(distance)
        {};


        /**
         * @brief Construct a new Plane object
         * 
         * @param point     (glm::vec4)
         *                  A point on the plane.
         * @param normal    (glm::vec4)
         *                  The normal vector of the plane. It should be a unit vector.
         */
        Plane(const glm::vec4& point,
            const glm::vec4& normal)
            : normal_(glm::normalize(normal)) {

            //  d = -n . p
            distance_ = -glm::dot(normal_, point);
        };

        /**
         * @brief   Getter for the normal vector of the plane.
         * 
         * @return const glm::vec4& 
         *          The normal vector of the plane.
         */
        const glm::vec4& normal() const {
            return normal_;
        }


        /**
         * @brief   Getter for the distance from the origin to the plane along the normal vector.
         * 
         * @return float 
         *          The distance from the origin to the plane along the normal vector.
         */
        float distance() const {
            return distance_;
        }

        /**
         * @brief   Computes the signed distance from a point to the plane.
         * 
         * @param p (glm::vec4)
         *          The point from which to compute the signed distance to the plane.
         * @return float
         *          The signed distance from the point to the plane. A positive value indicates that the point is in front of the plane, while a negative value indicates that it is behind the plane.
         */
        float signedDistance(
            const glm::vec4& p
        ) const {
            //  d* = n . p + d
            return glm::dot(normal_, p) + distance_;
        }

    private:
        glm::vec4 normal_{0.f,1.f,0.f,0.f};
        float distance_{0.f};
    };
}