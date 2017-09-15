#include "feature.h"

namespace ncv {

  namespace imgproc {

    void FeatureInit(Local<Object> &target) {
      // line segment detector modes
      DEFINE_CONST_ENUM(LSD_REFINE_NONE);
      DEFINE_CONST_ENUM(LSD_REFINE_STD);
      DEFINE_CONST_ENUM(LSD_REFINE_ADV);

      Nan::SetMethod(target, "canny", Canny);
      Nan::SetMethod(target, "cornerEigenValsAndVecs", CornerEigenValsAndVecs);
      Nan::SetMethod(target, "cornerHarris", CornerHarris);
      Nan::SetMethod(target, "cornerMinEigenVal", CornerMinEigenVal);
      Nan::SetMethod(target, "cornerSubPix", CornerSubPix);
      Nan::SetMethod(target, "createLineSegmentDetector", CreateLineSegmentDetector);
      Nan::SetMethod(target, "goodFeaturesToTrack", GoodFeaturesToTrack);
      Nan::SetMethod(target, "houghCircles", HoughCircles);
      Nan::SetMethod(target, "houghLines", HoughLines);
      Nan::SetMethod(target, "houghLinesP", HoughLinesP);
      Nan::SetMethod(target, "preCornerDetect", PreCornerDetect);
    }

    NAN_METHOD(Canny) {
      FUNCTION_REQUIRE_ARGUMENTS_RANGE(4, 6);
      Nan::HandleScope scope;
      ASSERT_INPUTARRAY_FROM_ARGS(m1, 0);
      unsigned argumentOffset = 0;
      cv::_InputArray m2;
      cv::_OutputArray out;
      try {
        out = ReadOutputArray(info[2]);
        try {
          ASSERT_INPUTARRAY_FROM_ARGS(dy, 1);
          m2 = dy;
        } catch (char const*) {
          return Nan::ThrowError(ERROR_INVALID_ARGUMENTS);
        }
        argumentOffset = 1;
      } catch (char const*) {
        ASSERT_OUTPUTARRAY_FROM_ARGS(dst, 1);
        dst = out;
      }
      ASSERT_DOUBLE_FROM_ARGS(threshold1, 2 + argumentOffset);
      ASSERT_DOUBLE_FROM_ARGS(threshold2, 3 + argumentOffset);
      DEFAULT_BOOLEAN_FROM_ARGS(L2gradient, 5, false);

      if (argumentOffset == 0) {
        DEFAULT_INT_FROM_ARGS(apertureSize, 4, 3);
        cv::Canny(m1, out, threshold1, threshold2, apertureSize, L2gradient);
      } else {
        cv::Canny(m1, m2, out, threshold1, threshold2, L2gradient);
      }
    }

    NAN_METHOD(CornerEigenValsAndVecs) {
      NotImplemented(info);
    }

    NAN_METHOD(CornerHarris) {
      NotImplemented(info);
    }

    NAN_METHOD(CornerMinEigenVal) {
      NotImplemented(info);
    }

    NAN_METHOD(CornerSubPix) {
      NotImplemented(info);
    }

    NAN_METHOD(CreateLineSegmentDetector) {
      NotImplemented(info);
    }

    NAN_METHOD(GoodFeaturesToTrack) {
      NotImplemented(info);
    }

    NAN_METHOD(HoughCircles) {
      NotImplemented(info);
    }

    NAN_METHOD(HoughLines) {
      NotImplemented(info);
    }

    NAN_METHOD(HoughLinesP) {
      NotImplemented(info);
    }

    NAN_METHOD(PreCornerDetect) {
      NotImplemented(info);
    }

  }

}