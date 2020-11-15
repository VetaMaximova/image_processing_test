///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#ifndef _RESIZECOMMANDPROCESSOR_H_
#define _RESIZECOMMANDPROCESSOR_H_
#include "CommandProcessor.h"

class ResizeCommandProcessor : public CommandProcessor {
public:
  bool CanProcess(const std::string &) override;
  bool
  ProcessCommand(const std::vector<std::string> &command_with_args,
                 std::unordered_map<std::string, cv::Mat> &images) override;

private:
  const std::string resize_command = "resize";
};

#endif //_RESIZECOMMANDPROCESSOR_H_
