#pragma once
/**
 * @brief   Header for the implementation of the `BoundingBox` class.
 * @details A bounding box defines the minimum and maximum points of the object contained within it. It is used for collision detection and spatial partitioning.
 * @author  n-rosenthal
 * @version 0.1
 * @date    2026-07-10
 */

#include <glm/glm.hpp>

namespace Math {

    /**
     * @brief   Defines a bounding box in 3D space, using homogeneous coordinates (glm::vec4).
     * @details The bounding box is defined by its minimum and maximum points, which are represented as `glm::vec4` objects.
     *          The minimum point represents the corner of the box with the lowest x, y, and z coordinates,
     *          and the maximum point represents the corner with the highest x, y, and z coordinates.
     * 
     *          The `center` of the bounding box can be computed as the average of the minimum and maximum points,
     *          and the `size` of the bounding box can be computed as the difference between the minimum and maximum points.
     */
    class   BoundingBox {
    public:
        /**
         * @brief Default constructor for the `BoundingBox` class.
         * 
         * @param min   (glm::vec4)
         *         The minimum point of the bounding box.
         * @param max   (glm::vec4)
         *         The maximum point of the bounding box.
         */
        BoundingBox(glm::vec4 min,
                    glm::vec4 max)
            : min(min), max(max) {};

        /**
         * @brief   Returns the center point of the bounding box.
         * @details The center point is computed as the average of the minimum and maximum points.
         * 
         * @return glm::vec4 
         */
        glm::vec4 center() const { return (min + max) * 0.5f; }

        /**
         * @brief   Returns the size of the bounding box.
         * @details The size is computed as the difference between the maximum and minimum points.
         * 
         * @return glm::vec4 
         */
        glm::vec4 size() const { return max - min; }

        /**
         * @brief   Getter for the minimum point of the bounding box.
         * 
         * @return glm::vec4 
         */
        glm::vec4 getMin() const { return min; }

        /**
         * @brief   Getter for the maximum point of the bounding box.
         * 
         * @return glm::vec4 
         */
        glm::vec4 getMax() const { return max; }

    private:
        glm::vec4 min;
        glm::vec4 max;
    };

};