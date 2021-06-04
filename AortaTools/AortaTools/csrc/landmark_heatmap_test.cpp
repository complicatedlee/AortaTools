#include <iostream>

#include "glog/logging.h"
#include "md/utils/csrc/md_logging/md_logging.h"

using namespace medvision::utils;

void LogMessages(){
	
    LOG(INFO)<<"Info message!"<<std::endl;
    LOG(WARNING)<<"Warning message!"<<std::endl;
    LOG(ERROR)<<"Error message!"<<std::endl;
}

int main(int argc, char** argv)
{
    // It's OK to call Init function more than once.
    MDLogging::Init(argv[0]);
    MDLogging::Init(argv[0]);

    {
      // By default, --logtostderr=0, --stderrthreshold=2 (ERROR),
      // --minloglevel=0 (INFO), and all messages will be logged to the file
      // in the specified directory.
      int argc0 = 2;
      char* argv0[] = {(char*)"logging_test", (char*)"--log_dir=/tmp"};
      MDLogging::ParseCommandLineFlags(&argc0, argv0);

      std::cerr << "You should only see error message:" << std::endl;
      LogMessages();
    }

    {
      // If --logtostderr=1, the messages will be logged to the console instead
      // of the file.
      char* argv0[] = {const_cast<char*>("logging_test"), const_cast<char*>("--logtostderr=1")};
      int argc0 = sizeof(argv0)/sizeof(argv0[0]);
      MDLogging::ParseCommandLineFlags(&argc0, argv0);

      std::cerr << "You should see all three messages!" << std::endl;
      LogMessages();
    }

    {
      char* argv0[] = {const_cast<char*>("logging_test"), const_cast<char*>("--logtostderr=0"),
                       const_cast<char*>("--stderrthreshold=1")};
      int argc0 = sizeof(argv0)/sizeof(argv0[0]);
      MDLogging::ParseCommandLineFlags(&argc0, argv0);

      std::cerr << "You should only see both warning and error messages:"
         << std::endl;
      LogMessages();
    }

    {
      char* argv0[] = {const_cast<char*>("logging_test"), const_cast<char*>("--stderrthreshold=0"),
                       const_cast<char*>("--minloglevel=2")};
      int argc0 = sizeof(argv0)/sizeof(argv0[0]);
      MDLogging::ParseCommandLineFlags(&argc0, argv0);

      std::cerr << "You should only see error message!" << std::endl;
      LogMessages();
    }

    // It's OK to call Shutdown function more than once.
    MDLogging::Shutdown();
    MDLogging::Shutdown();

    return 0;
}

