#ifndef _H_jSON_CONFIG_
#define _H_jSON_CONFIG_

#include <iostream>
//#include <variant>
#include <vector>
#include <map>
#include <fstream>
#include "json.hpp"

/* NOTE ::
   only use number as data type.  
   get data as double and cast when use it.
*/

/*{
     "category1":{
         "param1":1.3,
         "param3": -5,
      },
      "category2":{
         "param1":{
            "options":[
                1,
                2,
                3,
                4
              ],
            "value": 3
         },
         "param2":{
            "options":[
                3,
                4
              ],
            "value": 4
         }
    }
  }
*/


namespace jsonConfig {
  const int JSON_ERROR = -33;

  using json = nlohmann::json;
  using std::string;
  using std::map;
  using std::vector;
//  typedef std::variant<string,bool,int,double> T;


  class jsonConfig {
  protected:
    map <string, double> data;
    string file_path;
    string category;
    bool is_open;
    json j;
  public:
    inline jsonConfig(string file_path,string category);
    inline ~jsonConfig();

    inline void Load();
    inline void Print();

    /* Config["KEY"] -> return Value */
    double& operator[](string key);

    bool IsOpen() { return is_open; }
  };

  inline jsonConfig::jsonConfig(string file_path_,string category_){
    is_open = false;
    file_path = file_path_;
    category = category_;
    Load();
  }
  inline jsonConfig::~jsonConfig() {

  }

  inline void jsonConfig::Load() {
    std::ifstream ifs(file_path);

#ifndef NDEBUG
    std::cout << "jsonConfig::Load(" << file_path << ")\n";
#endif
    if (ifs)
      is_open = true;
    else {
      std::cout << "ERROR::failed to open : " << file_path << std::endl;
      exit(JSON_ERROR);
    }
   

    try {
      j = json::parse(ifs);
    }
    catch (json::parse_error) {
      printf("ERROR::Json parse error, check json file.\n");
      exit(JSON_ERROR);
    }

    j = j[category];
    if (j == nullptr) {
      printf("ERROR::there is no '%s' in jsonfile.\n",category.c_str());
      exit(JSON_ERROR);
    }
/*
  json.type()
  1 : json object
  2 : array
  3 : std::string
  4 : bool
  6 : int
  7 : double
*/
    json tmp;
    for(json::iterator it = j.begin(); it != j.end(); it++){
      switch (static_cast<int>(it.value().type())) {
      // json object
      case 1:
        tmp = it.value()["value"];
        if (tmp == nullptr) {
          printf("ERROR::there is no value in '%s'.\n",it.key().c_str());
          exit(JSON_ERROR);
        }
        data[it.key()] = it.value()["value"].get<double>();
        break;
      // bool
      case 4:
        data[it.key()] = it.value().get<bool>();
        break;
      // integer
      case 6 :
        data[it.key()] = it.value().get<int>();
        break;
      // double
      case 7 :
        data[it.key()] = it.value().get<double>();
        break;
      default :
        printf("ERROR::invalid json data type : %d.\n",it.value().type());
        exit(JSON_ERROR);
      }

      printf("type %s %s %d\n", it.key().c_str(), it.value().type_name(), it.value().type());
      if (static_cast<int>(it.value().type()) == 1) {
        for (json::iterator it2 = it.value().begin(); it2 != it.value().end(); it2++) {
          printf("--type %s %s %d\n", it2.key().c_str(), it2.value().type_name(), it2.value().type());
        }
      }
    }
    ifs.close();
  }

  /* Config["KEY"] -> return Value */
  double& jsonConfig::operator[](string key) {
    return data[key];
  }

  inline void jsonConfig::Print() {
    for (auto const& it : data)
      std::cout << it.first << " : " << it.second << "\n";
  }
}

#endif
