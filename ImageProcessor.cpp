///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///

#include "ImageProcessor.h"

#include <fstream>
#include <iostream>

bool ImageProcessor::IsCommandCorrect(std::string command) {
  for (auto &processor : command_processors) {
    if (processor->CanProcess(command))
      return true;
  }
  return finish_commands.find(command) != finish_commands.end();
}

bool ImageProcessor::IsFinishCommand(std::string command) {
  return finish_commands.find(command) != finish_commands.end();
}

bool ImageProcessor::ProcessCommand(
    const std::vector<std::string> &command_with_args) {
  auto &command = command_with_args[0];

  for (auto &processor : command_processors) {
    if (processor->CanProcess(command))
      return processor->ProcessCommand(command_with_args, images);
  }

  return false;
}
