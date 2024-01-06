#include "AudacityPipe.h"
#include <filesystem>

std::unique_ptr<AudacityPipe> AudacityPipe::_instance;

AudacityPipe& AudacityPipe::GetInstance()
{
   if(!_instance)
   { _instance.reset(new AudacityPipe()); }
   return *_instance;
}

void AudacityPipe::write(const std::string& cmd)
{
   if(!_ofstream)
   {
      std::filesystem::path f(PIPE_PATH);
      if(std::filesystem::exists(f))
      {
         _ofstream = std::make_unique<std::ofstream>(PIPE_PATH.data(), std::fstream::app);
      }
   }

   if(_ofstream && !_ofstream->good())
   { _ofstream.reset(); }

   if(_ofstream)
   {  (*_ofstream) << cmd << std::flush; }
}

AudacityPipe::AudacityPipe()
{}
