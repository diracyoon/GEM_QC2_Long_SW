#include <cstdlib>
#include <iostream>

#include "Preparation_QC_Long.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc!=7)
    {
      cout << "Wrong number of argc." << endl;
      cout << "argv[1]: foil name, argv[2]: trial_number, argv[3]: channel number, argv[4]: relative humidity, argv[5]: temperature, argv[6]: tester" << endl;
      exit(1);
    }

  string foil_name = argv[1];
  int trial_number = atoi(argv[2]);
  int channel = atoi(argv[3]);
  float rh = atof(argv[4]);
  float temp = atof(argv[5]);
  string tester = argv[6];
  
  char* path = getenv("QC_SW_PATH");
  if(path==NULL)
    {
      cout << "Enviromental variables aren't set. Source Env.sh first." << endl;
      return -1;
    }
  
  try
    {
      Preparation_QC_Long preparation_qc_long(foil_name, trial_number, channel, rh, temp, tester, path);
      preparation_qc_long.Run();
    }
  catch(const string& error)
    {
      cout << error << endl;
    }
  catch(const char* error)
    {
      cout << error << endl;
    }
  
  return 0;
}
