#include <DHTesp.h>

DHTesp dht;

void setup() {
	Serial.begin(115200);
	while (!Serial) {}
	Serial.println();
	Serial.println("Status\tHumidity (%)\tTemperature (C)\tHeatIndex (C)");

	dht.setup(2); // Connect DHT sensor to GPIO 2
}

void loop() {
	delay(dht.getMinimumSamplingPeriod());

	const float humidity = dht.getHumidity();
	const float temperature = dht.getTemperature();

	Serial.print(dht.getStatusString());
	Serial.print("\t");
	Serial.print(humidity, 1);
	Serial.print("\t\t");
	Serial.print(temperature, 1);
	Serial.print("\t\t");
	Serial.print(dht.computeHeatIndex(temperature, humidity), 1);
	Serial.println();
}

// initial release
// Program size : 6 286 bytes(used 19 % of a 32 256 byte maximum) (0.44 secs)
// Minimum Memory Usage : 329 bytes(16 % of a 2048 byte maximum)
