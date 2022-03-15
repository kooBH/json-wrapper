#include <string>
#include <stdio.h>

#include "jsonConfig.h"

int main() {

   const std::string json_path = "../config.json";
   jsonConfig data1(json_path.c_str(), "input");
   data1.Print();
   jsonConfig data2(json_path.c_str(), "param");
   data2.Print();
   
   printf("==============\n");

   printf("input.device : %lf\n",data1["device"]);
   printf("int(input.device) : %d\n",int(data1["device"]));





  return 0;
}