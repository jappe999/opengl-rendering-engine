#include <string>

using namespace std;

namespace Ore::Utils
{
  string getPath(string relativePath);

  char *readFile(string path);
} // namespace Ore::Utils
