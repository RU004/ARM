//
// Created by mry on 23-7-6.
//

#ifndef RM_CLASSIFIER_H
#define RM_CLASSIFIER_H

// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

// STD
#include <algorithm>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <map>
#include <string>

#include"detector.h"

class NumberClassifier
{
public:
    NumberClassifier(
            const std::string & model_path, const std::string & label_path, const double threshold,
            const std::vector<std::string> & ignore_classes = {});

    void extractNumbers(const cv::Mat & src, std::vector<Armor> & armors);
    void classify(std::vector<Armor> & armors);

    double threshold;

private:
    cv::dnn::Net net_;
    std::vector<std::string> class_names_;

    std::vector<std::string> ignore_classes_;
};

#endif //RM_CLASSIFIER_H
