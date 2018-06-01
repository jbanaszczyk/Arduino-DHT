#ifndef _45E0222197934BD98C87BA94BB7E9CB3_
#define _45E0222197934BD98C87BA94BB7E9CB3_

#if ARDUINO < 100
  #include <WProgram.h>
#else
  #include <Arduino.h>
#endif

// Reference: http://epb.apogee.net/res/refcomf.asp (References invalid)
enum ComfortState {
  Comfort_OK = 0,
  Comfort_TooHot = 1,
  Comfort_TooCold = 2,
  Comfort_TooDry = 4,
  Comfort_TooHumid = 8,
  Comfort_HotAndHumid = 9,
  Comfort_HotAndDry = 5,
  Comfort_ColdAndHumid = 10,
  Comfort_ColdAndDry = 6
};

// References https://en.wikipedia.org/wiki/Dew_point ==> Relationship to human comfort
enum PerceptionState {
  Perception_Dry = 0,
  Perception_VeryComfy = 1,
  Perception_Comfy = 2,
  Perception_Ok = 3,
  Perception_UnComfy = 4,
  Perception_QuiteUnComfy = 5,
  Perception_VeryUnComfy = 6,
  Perception_SevereUncomfy = 7
};

struct TempAndHumidity {
  float temperature;
  float humidity;
};

struct ComfortProfile
{
  //Represent the 4 line equations:
  //dry, humid, hot, cold, using the y = mx + b formula
  float m_tooHot_m, m_tooHot_b;
  float m_tooCold_m, m_tooHCold_b;
  float m_tooDry_m, m_tooDry_b;
  float m_tooHumid_m, m_tooHumid_b;

  inline bool isTooHot(float temp, float humidity) {return (temp > (humidity * m_tooHot_m + m_tooHot_b));}
  inline bool isTooHumid(float temp, float humidity) {return (temp > (humidity * m_tooHumid_m + m_tooHumid_b));}
  inline bool isTooCold(float temp, float humidity) {return (temp < (humidity * m_tooCold_m + m_tooHCold_b));}
  inline bool isTooDry(float temp, float humidity) {return (temp < (humidity * m_tooDry_m + m_tooDry_b));}

  inline float distanceTooHot(float temp, float humidity) {return temp - (humidity * m_tooHot_m + m_tooHot_b);}
  inline float distanceTooHumid(float temp, float humidity) {return temp - (humidity * m_tooHumid_m + m_tooHumid_b);}
  inline float distanceTooCold(float temp, float humidity) {return (humidity * m_tooCold_m + m_tooHCold_b) - temp;}
  inline float distanceTooDry(float temp, float humidity) {return (humidity * m_tooDry_m + m_tooDry_b) - temp;}
};

class DHTesp
{
public:

  typedef enum {
    AUTO_DETECT,
    DHT11,
    DHT22,
    AM2302,  // Packaged DHT22
    RHT03    // Equivalent to DHT22
  }
  DHT_MODEL_t;

  typedef enum {
    ERROR_NONE = 0,
    ERROR_TIMEOUT,
    ERROR_CHECKSUM
  }
  DHT_ERROR_t;

  TempAndHumidity values;

  void setup(uint8_t pin, DHT_MODEL_t model=AUTO_DETECT);
  void resetTimer();

  float getTemperature();
  float getHumidity();
  TempAndHumidity getTempAndHumidity();

  DHT_ERROR_t getStatus() { return error; };
  const char* getStatusString();

  DHT_MODEL_t getModel() { return model; }

  int getMinimumSamplingPeriod() { return model == DHT11 ? 1000 : 2000; }

  int8_t getNumberOfDecimalsTemperature() { return model == DHT11 ? 0 : 1; };
  int8_t getLowerBoundTemperature() { return model == DHT11 ? 0 : -40; };
  int8_t getUpperBoundTemperature() { return model == DHT11 ? 50 : 125; };

  int8_t getNumberOfDecimalsHumidity() { return 0; };
  int8_t getLowerBoundHumidity() { return model == DHT11 ? 20 : 0; };
  int8_t getUpperBoundHumidity() { return model == DHT11 ? 90 : 100; };

  static float toFahrenheit(float fromCelcius) { return 1.8 * fromCelcius + 32.0; };
  static float toCelsius(float fromFahrenheit) { return (fromFahrenheit - 32.0) / 1.8; };

  float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit=false);
  float computeDewPoint(float temperature, float percentHumidity, bool isFahrenheit=false);
  float getComfortRatio(ComfortState& destComfStatus, float temperature, float percentHumidity, bool isFahrenheit=false);
  ComfortProfile getComfortProfile() {return m_comfort;}
  void setComfortProfile(ComfortProfile& c) {m_comfort = c;}
  inline bool isTooHot(float temp, float humidity) {return m_comfort.isTooHot(temp, humidity);}
	inline bool isTooHumid(float temp, float humidity) {return m_comfort.isTooHumid(temp, humidity);}
	inline bool isTooCold(float temp, float humidity) {return m_comfort.isTooCold(temp, humidity);}
	inline bool isTooDry(float temp, float humidity) {return m_comfort.isTooDry(temp, humidity);}
  byte computePerception(float temperature, float percentHumidity, bool isFahrenheit=false);
protected:
  void readSensor();

  float temperature;
  float humidity;

  uint8_t pin;

private:
  DHT_MODEL_t model;
  DHT_ERROR_t error;
  unsigned long lastReadTime;
  ComfortProfile m_comfort;
};

#endif /*dhtesp_h*/
