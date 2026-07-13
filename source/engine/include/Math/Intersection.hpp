#pragma once

/**
 * @file    `Intersection.hpp`
 * @author  n-rosenthal
 * @brief   Header for the implementation of the `Intersection` class.
 * @details The `Intersection` class provides methods for checking the intersection between geometric objects and ray objects.
 * @version 0.1
 * @date    2026-07-11
 */

#include <glm/glm.hpp>
#include <vector>

#include "Math/Ray.hpp"
#include "Math/Plane.hpp"
#include "Math/BoundingBox.hpp"

namespace Math::Intersection {
    /**
     * @brief   Verifies the intersection between a ray and a plane.
     * 
     * @param   ray     (const Ray&)
     *                  The ray to check for intersection.
     * @param   plane   (const Plane&)
     *                  The plane to check for intersection.
     * @param   t       (float&)
     *                  The parameter t of the intersection point.
     *                  
     * @return  true,   if the ray intersects the plane.
     * @return  false,  otherwise. 
     */
    bool rayPlane(const Ray& ray,
                const Plane& plane,
                float& t);

    /**
     * @brief   Verifies the intersection between a ray and a bounding box.
     * 
     * @param   ray     (const Ray&)
     *                  The ray to check for intersection.
     * @param   box     (const BoundingBox&)
     *                  The bounding box to check for intersection.
     * @param   t       (float&)
     *                  The parameter t of the intersection point.
     *                  
     * @return  true,   if the ray intersects the bounding box.
     * @return  false,  otherwise. 
     */
    bool rayBox(const Ray& ray,
                const BoundingBox& box,
                float& t);

    /**
     * @brief   Verifies the intersection between a ray and a triangle defined by three points.
     * 
     * @param   ray     (const Ray&)
     *                  The ray to check for intersection.
     * @param   a       (const glm::vec4&)
     *                  the first point of the triangle.
     * @param   b       (const glm::vec4&)
     *                  the second point of the triangle.
     * @param   c       (const glm::vec4&)
     *                  the third point of the triangle.
     * @param   t       (float&)
     *                  The parameter t of the intersection point.
     *                  
     * @return  true,   if the ray intersects the triangle.
     * @return  false,  otherwise. 
     */
    bool rayTriangle(const Ray& ray,
                    const glm::vec4& a,
                    const glm::vec4& b,
                    const glm::vec4& c,
                    float& t);
};