[![download](https://img.shields.io/badge/current-download-brightgreen.svg)](https://github.com/jbanaszczyk/dht/archive/master.zip)
[![Version](https://img.shields.io/badge/release-2.0-brightgreen.svg)](https://github.com/jbanaszczyk/dht/releases)
[![status](https://img.shields.io/badge/status-alpha-red.svg)](https://github.com/jbanaszczyk/dht/releases)
[![Platform](https://img.shields.io/badge/platform-arduino-blue.svg)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-11/14-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-BSD-blue.svg)](https://github.com/jbanaszczyk/dht/blob/master/LICENSE)


# Yet another DHT library

An Arduino library for reading the DHT family of temperature and humidity sensors.

## License

dht library is distributed under [BSD 3-Clause "New" License](https://github.com/jbanaszczyk/dht/blob/master/LICENSE)

## Status

### Current revision: 2.0

Status of current revision is: "development started"

## Platforms

The library is tested as well on Arduino-Uno

## Features

- Support for DHT11 and DHT22, AM2302, RHT03
- Auto detect sensor model
- Determine heat index
- Determine dewpoint
- Determine thermal comfort:
  * Empiric comfort function based on comfort profiles (parametric lines)
  * Multiple comfort profiles possible
  * Determine if it's too cold, hot, humid, dry, based on current comfort profile
- Determine human perception based on humidity, temperature and dew point 

## API

[dht API description](API.md) is available as a separate document.

## References

* [Determining Thermal Comfort Using a Humidity and Temperature Sensor](https://www.azosensors.com/article.aspx?ArticleID=487)
* [Relative Humidity....Relative to What? The Dew Point Temperature...a better approach, Horstmeyer, Steve (2006-08-15)](http://www.shorstmeyer.com/wxfaqs/humidity/humidity.html)

## Contributors

Original written by Mark Ruys

Forked from [beegee-tokyo/DHTesp](https://github.com/beegee-tokyo/DHTesp)

Added code and ideas from many developers:
- [Mark Ruys](https://github.com/markruys/arduino-DHT)
- [Bernd Giesecke](https://github.com/beegee-tokyo/DHTesp)
- [Rob Tillaart](https://github.com/RobTillaart/libDHT)
- [github/ADiea](https://github.com/ADiea/libDHT)
- ...


## Preparation

### IDE & OS

dht library is developed using:
* Visual Studio Community 2017 (Windows)
* [Arduino IDE for Visual Studio](http://www.visualmicro.com)

dht library was successfully checked using:
* Arduino 1.8.5 (Windows)

### Dependencies

dht library does not depend on additional libraries.

# Applications

## Hello. The Basic scenario.<a name="dhtTest"></a>

Use the code:  [Examples\dhtTest\dhtTest.ino](https://github.com/jbanaszczyk/dht/blob/master/Examples/dhtTest/dhtTest.ino)
