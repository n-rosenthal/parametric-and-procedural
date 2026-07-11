/**
 * @file    `Ellipse.cpp`
 * @author  n-rosenthal
 * @brief   Implementation of the `Ellipse` class.
 * @details An ellipse is a curve defined by its semi-major and semi-minor axes,
 *          as well as its center point. It is a subclass of the `Curve` class
 *          and implements the `point`, `tangent`, and `boundingBox` methods.
 * @version 0.1
 * @date    2026-07-10
 */

#include "Geometry/Ellipse.hpp"


/**
 * @brief   Constructs an `Ellipse` object with the given semi-major axis, semi-minor axis, and center point.
 *
 *  @param a (float)
 *          The semi-major axis of the ellipse.
 *  @param b (float)
 *          The semi-minor axis of the ellipse.
 *  @param center (glm::vec4)
 *          The center of the ellipse. Defaults to (0, 0, 0, 1).
 * 
 * @return  Ellipse
 *          An `Ellipse` object with the specified parameters. 
 */
Ellipse::Ellipse(float a, float b, glm::vec4 center) : Curve() {
    this->a = a;
    this->b = b;
    this->center = center;
};


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
glm::vec4 Ellipse::point(float t) const {
    return glm::vec4(
        (a * cos(2 * M_PI * t)) + center.x,
        (b * sin(2 * M_PI * t)) + center.y,
        0.0f,
        1.0f
    );
};


/**
 * @brief   Returns the tangent vector at parameter t.
 * @details The tangent vector is the derivative of the curve at parameter t.
 *
 * @param t (float)
 *          The parameter t in the range [0, 1].
 * @return  glm::vec4
 *          The tangent vector at parameter t.
 */
glm::vec4 Ellipse::tangent(float t) const {
    return glm::vec4(
        -2 * M_PI * a * sin(2 * M_PI * t),
        2 * M_PI * b * cos(2 * M_PI * t),
        0.0f,
        0.0f
    );
};


/**
 * @brief   Returns the major-axis, or width-axe of the ellipse.
 * @return  std::pair<glm::vec4, glm::vec4>
 *          The major-axis, or width-axe of the ellipse.
 */
std::pair<glm::vec4, glm::vec4> Ellipse::majorAxis() const {
    return std::make_pair(
        glm::vec4(center.x - a, center.y, 0.0f, 1.0f),
        glm::vec4(center.x + a, center.y, 0.0f, 1.0f)
    );
};

/**
 * @brief   Returns the minor-axis, or height-axe of the ellipse.
 * @return  std::pair<glm::vec4, glm::vec4>
 *          The minor-axis, or height-axe of the ellipse.
 */
std::pair<glm::vec4, glm::vec4> Ellipse::minorAxis() const {
    return std::make_pair(
        glm::vec4(center.x, center.y - b, 0.0f, 1.0f),
        glm::vec4(center.x, center.y + b, 0.0f, 1.0f)
    );
};

/**
 * @brief   Returns the foci of the ellipse.
 * @return  std::pair<glm::vec4, glm::vec4>
 *          The foci of the ellipse.
 */
std::pair<glm::vec4, glm::vec4> Ellipse::foci() const {
    float c = sqrt(a * a - b * b);
    return std::make_pair(
        glm::vec4(center.x - c, center.y, 0.0f, 1.0f),
        glm::vec4(center.x + c, center.y, 0.0f, 1.0f)
    );
};


/**
 * @brief   Returns the bounding box of the ellipse.
 * @details The bounding box is defined by the minimum and maximum points of the ellipse.
 *
 * @return  BoundingBox
 *          The bounding box of the ellipse.
 */
BoundingBox Ellipse::boundingBox() const {
    return BoundingBox(
        glm::vec4(center.x - a, center.y - b, 0.0f, 1.0f),
        glm::vec4(center.x + a, center.y + b, 0.0f, 1.0f)
    );
};


/**
 * @brief   Returns a vector of points sampled from the ellipse.
 * 
 * @return  std::vector<glm::vec4>
 *          A vector of points sampled from the ellipse.
 */
std::vector<glm::vec4> Ellipse::sample(std::size_t n) const {
    std::vector<glm::vec4> vertices;

    for (std::size_t i = 0; i < n; ++i)
    {
        float t = static_cast<float>(i)
                / (n - 1);

        vertices.push_back(point(t));
    }

    return vertices;
}