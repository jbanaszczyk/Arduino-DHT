
# Warning

dht API is a subject of change

Nothing below can not be assumed as valid


## Functions

_**`void setup(uint8_t pin, DHT_MODEL_t model=AUTO_DETECT);`**_    
- Call to initialize the interface, define the GPIO pin to which the sensor is connected and define the sensor type. Valid sensor types are:     
    - AUTO_DETECT     Try to detect which sensor is connected    
    - DHT11    
    - DHT22    
    - AM2302          Packaged DHT22    
    - RHT03           Equivalent to DHT22    

_**`void resetTimer();`**_    
- Reset last time the sensor was read    

_**`float getTemperature();`**_    
- Get the temperature in degree Centigrade from the sensor    
Either one of  _`getTemperature()`_ or  _`getHumidity()`_ or  _`getTempAndHumidity()`_ initiates reading a value from the sensor if the last reading was older than the minimal refresh time of the sensor.    
See example _`DHT_ESP32.ino`_ or _`DHT_Test.ino`_    

_**`float getHumidity();`**_    
- Get the humidity from the sensor     
Either one of  _`getTemperature()`_ or  _`getHumidity()`_ or  _`getTempAndHumidity()`_ initiates reading a value from the sensor if the last reading was older than the minimal refresh time of the sensor.    
See example _`DHT_ESP32.ino`_ or _`DHT_Test.ino`_    

_**`TempAndHumidity getTempAndHumidity();`**_    
- Get the temperature and humidity from the sensor     
Either one of _`getTemperature()`_ or  _`getHumidity()`_ or  _`getTempAndHumidity()`_ initiates reading a value from the sensor if the last reading was older than the minimal refresh time of the sensor.    
Return value is a struct of type _`TempAndHumidity`_ with temperature and humidity as float values.
See example _`DHT_Multi.ino`_    

_**`DHT_ERROR_t getStatus();`**_    
- Get last error if reading from the sensor failed. Possible values are:    
  - ERROR_NONE      no error occured
  - ERROR_TIMEOUT   timeout reading from the sensor    
  - ERROR_CHECKSUM  checksum of received values doesn't match

_**`const char* getStatusString();`**_    
- Get last error as a char *    

_**`DHT_MODEL_t getModel()`**_    
- Get detected (or defined) sensor type    

_**`int getMinimumSamplingPeriod();`**_    
- Get minimmum possible sampling period. For DHT11 this is 1000ms, for other sensors it is 2000ms    

_**`int8_t getNumberOfDecimalsTemperature();`**_    
- Get number of decimals in the temperature value. For DHT11 this is 0, for other sensors it is 1    

_**`int8_t getLowerBoundTemperature();`**_    
- Get lower temperature range of the sensor. For DHT11 this is 0 degree Centigrade, for other sensors this is -40 degree Centrigrade    

_**`int8_t getUpperBoundTemperature();`**_    
- Get upper temperature range of the sensor. For DHT11 this is 50 degree Centigrade, for other sensors this is 125 degree Centrigrade    

_**`int8_t getNumberOfDecimalsHumidity();`**_    
- Get number of decimals in the humidity value. This is always 0.    

_**`int8_t getLowerBoundHumidity();`**_    
- Get lower humidity range of the sensor. For DHT11 this is 20 percent, for other sensors this is 0 percent    

_**`int8_t getUpperBoundHumidity();`**_    
- Get upper temperature range of the sensor. For DHT11 this is 90 percent, for other sensors this is 100 percent    

_**`static float toFahrenheit(float fromCelcius);`**_    
- Convert Centrigrade value to Fahrenheit value    

_**`static float toCelsius(float fromFahrenheit) { return (fromFahrenheit - 32.0) / 1.8; };`**_    
- Convert Fahrenheit value to Centigrade value    

_**`float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit=false);`**_    
- Compute the heat index. Default temperature is in Centrigrade.    

_**`float computeDewPoint(float temperature, float percentHumidity, bool isFahrenheit=false);`**_    
- Compute the dew point. Default temperature is in Centrigrade.    

_**`float getComfortRatio(ComfortState& destComfStatus, float temperature, float percentHumidity, bool isFahrenheit=false);`**_    
- Compute the comfort ratio. Default temperature is in Centrigrade. Return values:    
0 -> OK    
1 -> Too Hot    
2 -> Too cold    
4 -> Too dry    
8 -> Too humid    
9 -> Hot and humid    
5 -> Hot and dry    
10 -> Cold and humid    
6 -> Cold and dry    

_**`byte computePerception(float temperature, float percentHumidity, bool isFahrenheit=false);`**_    
- Compute the human perception. Default temperature is in Centrigrade. Return values:    
0 -> Dry    
1 -> Very comfortable    
2 -> Comfortable    
3 -> Ok    
4 -> Uncomfortable    
5 -> Quite uncomfortable    
6 -> Very uncomfortable    
7 -> Severe uncomfortable    
