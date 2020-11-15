///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#ifndef _IMAGEPROCESSOR_H_
#define _IMAGEPROCESSOR_H_
#include "BlurCommandProcessor.h"
#include "HelpCommandProcessor.h"
#include "LoadCommandProcessor.h"
#include "ResizeCommandProcessor.h"
#include "StoreCommandProcessor.h"

#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class ImageProcessor {
public:
  bool IsCommandCorrect(std::string command);
  bool IsFinishCommand(std::string command);
  bool ProcessCommand(const std::vector<std::string> &command_with_args);

private:
  bool LoadImage(const std::vector<std::string> &command_with_args);
  bool StoreImage(const std::vector<std::string> &command_with_args);
  bool BlurImage(const std::vector<std::string> &command_with_args);
  bool ResizeImage(const std::vector<std::string> &command_with_args);

  std::unordered_map<std::string, cv::Mat> images;

  const std::set<std::string> finish_commands = {"exit", "quit", "q"};
  const std::vector<std::shared_ptr<CommandProcessor>> command_processors = {
      std::make_shared<HelpCommandProcessor>(),
      std::make_shared<LoadCommandProcessor>(),
      std::make_shared<StoreCommandProcessor>(),
      std::make_shared<BlurCommandProcessor>(),
      std::make_shared<ResizeCommandProcessor>()};
};

#endif //_IMAGEPROCESSOR_H_
