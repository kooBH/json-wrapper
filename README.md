# jsonConfig  
wrapper class of [JSON for Modern C++](https://github.com/nlohmann/json) for my configuration file.  
  
# NOTE   
This class get only number(bool,int,double) as double. Cast to other type when use data. Don't use string type of data.    


## Available shape of json
```json

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
```
