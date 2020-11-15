///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#ifndef _HELPCOMMANDPROCESSOR_H_
#define _HELPCOMMANDPROCESSOR_H_

#include "CommandProcessor.h"

class HelpCommandProcessor : public CommandProcessor {
public:
  bool CanProcess(const std::string &) override;
  bool
  ProcessCommand(const std::vector<std::string> &command_with_args,
                 std::unordered_map<std::string, cv::Mat> &images) override;

private:
  const std::string help_full_command = "help";
  const std::string help_short_command = "h";
};

#endif //_HELPCOMMANDPROCESSOR_H_
