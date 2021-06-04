#ifndef MD_UTILITY_CSRC_MD_LOGGING_H
#define MD_UTILITY_CSRC_MD_LOGGING_H

#include <memory>

namespace medvision {

namespace utils {

// NOTE: THis logger is a wrapper of google logger. if you want to compile this
// module with VS compiler, it should be compiled into an unique DLL once and
// other excutable or DLL links against it.

class MDLogging
{
private:
    static std::unique_ptr<MDLogging> pInstance;
    MDLogging(char* argv0);

public:
    /*! \brief Init md_logging
     *
     *  This function to init md_logging, and you will see argv0 in log outputs.
     * if Init is called more than once, only the first argv0 is valid.
     *
     *  Example 01(see the program name in log outputs):
     *  int main(int argc, char** argv){
     *      MDLogging::Init(argv[0]);
     *      .....
     *
     *      return 0;
     *  }
     *
     *  Example 02(see the specified name in log outputs):
     *      char* argv0 = const_cast<cahr*>("UAI_Alg");
     *      MDLogging::Init(argv0);
     *      .....
     *
     *  \param argv0           the specified name
     */
    static void Init(char* argv0);

    /*! \brief Looks for flags in argv and parses them.
     *
     *  You can set Flags such as:
     *  --logtostderr(bool, default=false)
     *  --stderrthreshold(int, default=2, which is ERROR)
     *  --minloglevel(int, default=2, which is ERROR)
     *  --log_dir(string, default="")
     *
     *  The numbers of severity levels INFO,WARNING,ERROR and FATAL are 0,1,2 and 3.
     *
     *  More guidance on links:http://rpg.ifi.uzh.ch/docs/glog.html
     *
     *  Example 01(set params by command line):
     *  int main(int argc, char** argv){
     *      MDLogging::ParseCommandLineFlags(&argc, argv);
     *      .....
     *
     *      return 0;
     *  }
     *
     *  Example 02(set params by codes):
     *      char* argv0[] = {const_cast<char*>("UAI_Alg"), const_cast<char*>("--minloglevel=0")}
     *      int argc0 = sizeof(argv0)/sizeof(argv0[0])
     *      MDLogging::ParseCommandLineFlags(&argc0, argv0);
     *      .....
     *
     *  \param argc           the length of argv0 array
     *  \param argv           the array include Flags
     */
    static void ParseCommandLineFlags(int* argc, char** argv);

    /*! \brief Shutdown the md_logging*/
    static void Shutdown();
};

} // namespace utils
} // namespace medvision

#endif // MD_UTILITY_CSRC_MD_LOGGING_H
