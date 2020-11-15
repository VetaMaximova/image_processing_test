///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#ifndef _BLURCOMMANDPROCESSOR_H_
#define _BLURCOMMANDPROCESSOR_H_
#include "CommandProcessor.h"

class BlurCommandProcessor : public CommandProcessor {
public:
  bool CanProcess(const std::string &) override;
  bool
  ProcessCommand(const std::vector<std::string> &command_with_args,
                 std::unordered_map<std::string, cv::Mat> &images) override;

private:
  const std::string blur_command = "blur";
};
#endif //_BLURCOMMANDPROCESSOR_H_
