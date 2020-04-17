Development of an IoT System for a Green Campus

   In this project, the main goal is to measure environmental data such as air pressure, air
temperature consistently with appropriate sensors and serve this measured data to network of
physical devices. This IoT network includes mobile phones, computers and any other mobile
devices. For this purpose ESP32 microcontroller get used as a centre of this process which has
integrated Wi-Fi feature that provides wireless communication with the server on local campus
internet. Also, digital environment sensors connected to ESP32 and the task of this device is to
read the sensor data and send them periodically to a central point in the campus with using
wireless network. For this purpose appropriate type of sensors has been used.

   The software part of the project included an embedded software programme, setting up
of a MQTT broker, a MQTT subscriber Python client programme and PHP coded webpage.
Embedded software programme has written for ESP32 in Arduino IDE to control all the
processes in microcontroller. MQTT is a type of communication protocol which has been used to
distribute received data from ESP32 to other devices in network with a MQTT broker so, broker
also established on a desktop computer. A MQTT subscriber client programmed with using
Python and Paho-MQTT library which subscribes a topic in broker and saves incoming data
from ESP32 to a text file. This text file used as a database and updated by Python client as new
data incomes. Data in the text file used for plotting a graph on webpage.

   On the other hand, since the ESP32 device is not suitable to use campus electric network,
devices use solar energy. For this purpose, a solar energy circuit built and solar panels generate
energy for devices. As a result, the entire system is more mobile and environment friendly.

References
[1] http://mqtt.org/faq
[2] http://phplot.org/
