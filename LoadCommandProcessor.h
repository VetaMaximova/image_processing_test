///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#ifndef CMAKEFILES_LOADCOMMANDPROCESSOR_H_
#define CMAKEFILES_LOADCOMMANDPROCESSOR_H_
#include "CommandProcessor.h"

class LoadCommandProcessor : public CommandProcessor {
public:
  bool CanProcess(const std::string &) override;
  bool
  ProcessCommand(const std::vector<std::string> &command_with_args,
                 std::unordered_map<std::string, cv::Mat> &images) override;

private:
  const std::string load_full_command = "load";
  const std::string load_short_command = "ld";
};

#endif // CMAKEFILES_LOADCOMMANDPROCESSOR_H_
