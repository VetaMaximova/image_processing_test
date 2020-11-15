///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#ifndef _STORECOMMANDPROCESSOR_H_
#define _STORECOMMANDPROCESSOR_H_

#include "CommandProcessor.h"

class StoreCommandProcessor : public CommandProcessor {
public:
  bool CanProcess(const std::string &) override;
  bool
  ProcessCommand(const std::vector<std::string> &command_with_args,
                 std::unordered_map<std::string, cv::Mat> &images) override;

private:
  const std::string store_full_command = "store";
  const std::string store_short_command = "s";
};

#endif //_STORECOMMANDPROCESSOR_H_
