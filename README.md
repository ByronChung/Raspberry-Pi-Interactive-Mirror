# Raspberry Pi Interactive Mirror #

Interactive mirror created using Qt in C++ that is able to songs played through Spotify, Weather, Time, and Tweets. Utilized the Spotify API by regenerating refresh tokens upon GET request to retrieve recently played songs. Weather data was fetched from an open-source API. Time was accurately displayed and fetched from OS. Tweets were retrieved using Twitter API integration. Additonal features includes smart power-saving mode enabled by polling motion detection readings from a Passive Infrared (PIR) sensor that sends data over a serial connection from an Arduino to the Raspberry Pi that the software runs on.

![UML-CLASS-DIAGRAM](https://user-images.githubusercontent.com/60553787/192053613-8dc0bcdc-1f12-497b-82df-c9b4a3fb8395.png)

