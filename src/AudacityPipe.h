#pragma once

#include <memory>
#include <fstream>
#include <string_view>

struct AudacityPipe
{
   static AudacityPipe& GetInstance();
   AudacityPipe(const AudacityPipe&) = delete;
   AudacityPipe& operator= (const AudacityPipe&) = delete;
   void write(const std::string& cmd);

private:
   explicit AudacityPipe();

   static constexpr std::string_view PIPE_PATH = "/tmp/audacity.pipe";

   static std::unique_ptr<AudacityPipe> _instance;
   std::unique_ptr<std::ofstream> _ofstream;
};
