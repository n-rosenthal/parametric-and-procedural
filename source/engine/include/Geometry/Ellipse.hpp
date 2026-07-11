#pragma once

/**
 * @file    `Ellipse.hpp`
 * @author  n-rosenthal
 * @brief   Header for the implementation of the `Ellipse` class.
 * @version 0.1
 * @date    2026-07-10
 */

#include <glm/glm.hpp>
#include "Curve.hpp"
#include "Definitions/BoundingBox.hpp"

class Ellipse : public Curve {
public:
    /**
     * @brief Default constructor for the `Ellipse` class.
     * 
     * @param a (float)
     *          The semi-major axis of the ellipse.
     * @param b (float)
     *          The semi-minor axis of the ellipse.
     * @param center (glm::vec4)
     *         The center of the ellipse. Defaults to (0, 0, 0, 1).
     */
    Ellipse(
        float a,
        float b,
        glm::vec4 center = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)
    );

    /**
     * @brief   Returns a point on the ellipse at parameter t.
     * @details The parameter t is in the range [0, 1], where
     *              t = 0 returns the first point on the ellipse,
     *              t = 1 returns the last point on the ellipse.
     *
     * @param t (float)
     *          The parameter t in the range [0, 1].
     * @return  glm::vec4
     *          The point on the ellipse at parameter t.
     */
    glm::vec4 point(float t) const override;

    /**
     * @brief   Returns the tangent vector of the ellipse at parameter t.
     * @details The parameter t is in the range [0, 1], where
     *              t = 0 returns the first point on the ellipse,
     *              t = 1 returns the last point on the ellipse.
     *
     * @param t (float)
     *          The parameter t in the range [0, 1].
     * @return  glm::vec4
     *          The tangent vector of the ellipse at parameter t.
     */
    glm::vec4 tangent(float t) const override;

    /**
     * @brief   Returns the pair of points that define the major axis of the ellipse.
     * @details The major axis is the longest axis (its WIDTH) of the ellipse.
     * 
     * @return std::pair<glm::vec4, glm::vec4> 
     */
    std::pair<glm::vec4, glm::vec4> majorAxis() const;

    /**
     * @brief   Returns the pair of points that define the minor axis of the ellipse.
     * @details The minor axis is the shortest axis (its HEIGHT) of the ellipse.
     * 
     * @return std::pair<glm::vec4, glm::vec4> 
     */
    std::pair<glm::vec4, glm::vec4> minorAxis() const;

    /**
     * @brief   Returns the pair of points that define the foci of the ellipse.
     * @return std::pair<glm::vec4, glm::vec4> 
     */
    std::pair<glm::vec4, glm::vec4> foci() const;

    /**
     * @brief   Returns the `BoundingBox` that contains the ellipse.
     * @return  BoundingBox
     *          The `BoundingBox` that contains the ellipse.
     */
    BoundingBox boundingBox() const override;

    /**
     * @brief   Returns a vector of points that sample the ellipse.
     * @param n (std::size_t)
     *          The number of points to sample.
     * @return  std::vector<glm::vec4>
     *          A vector of points that sample the ellipse.
     */
    std::vector<glm::vec4> sample(std::size_t n) const override;

private:
    float a;
    float b;
    glm::vec4 center;
};
