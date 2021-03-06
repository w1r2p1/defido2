#include <stdlib.h>

#include <docopt/docopt.h>

#include "util.h"


namespace defido2 {



static const char USAGE[] =
R"( 
    Usage:
      add-priv

    Options:
      -h --help             Show this screen.
      --version             Show version.

NOTE: The PRIVKEY environment variable should be set.
)";



void cmd_add_priv(const std::vector<std::string> &subArgs) {
    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, subArgs, true, "");

    auto config = loadConfig();

    config["privKey"] = std::string(::getenv("PRIVKEY"));

    saveConfig(config);
}


}
