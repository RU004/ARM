//
// Created by mry on 23-7-6.
//
#ifndef RM_PNP_H
#define RM_PNP_H

// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>

// STD
#include <cmath>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <map>

#include"detector.h"
class PnPSolver
{
public:
    PnPSolver(
            const std::array<double, 9> & camera_matrix,
            const std::vector<double> & distortion_coefficients);

    // Get 3d position
    bool solvePnP(const Armor & armor, cv::Mat & rvec, cv::Mat & tvec);


private:
    cv::Mat camera_matrix_;
    cv::Mat dist_coeffs_;

    // Unit: mm
    static constexpr float SMALL_ARMOR_WIDTH = 135;
    static constexpr float SMALL_ARMOR_HEIGHT = 55;
    static constexpr float LARGE_ARMOR_WIDTH = 225;
    static constexpr float LARGE_ARMOR_HEIGHT = 55;

    // Four vertices of armor in 3d
    std::vector<cv::Point3f> small_armor_points_ ;
    std::vector<cv::Point3f> large_armor_points_ ;
};
#endif //RM_PNP_H
