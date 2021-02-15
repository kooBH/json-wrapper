//#include "jsonConfig.h"

#include <string>
#include <stdio.h>
#include <variant>

#include "jsonConfig.h"

int main() {

 const std::string json_path = "../config.json";

 jsonConfig::jsonConfig data1(json_path.c_str(), "input");
 data1.Print();
 jsonConfig::jsonConfig data2(json_path.c_str(), "param");
 data2.Print();

  return 0;
}