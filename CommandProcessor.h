///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#ifndef _COMMANDPROCESSOR_H_
#define _COMMANDPROCESSOR_H_
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <unordered_map>
#include <vector>

class CommandProcessor {
public:
  virtual bool CanProcess(const std::string &command) = 0;
  virtual bool
  ProcessCommand(const std::vector<std::string> &command_with_args,
                 std::unordered_map<std::string, cv::Mat> &images) = 0;
};

#endif //_COMMANDPROCESSOR_H_
