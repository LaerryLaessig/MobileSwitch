# MobileSwitch

This program uses an ESP8266 WiFi module to control a remote switch. The switch is controlled by sending a GET request to an API endpoint. When the program receives a successful response from the API, it toggles the switch and then goes into deep sleep.

## To use the program, you will need to:

Install the PlattformIO and the ESP8266 board package.
Connect the ESP8266 to your computer using a USB cable.
Open the program in PlattformIO and compile and upload it to the ESP8266.
Connect the ESP8266 to your WiFi network.
Configure the API_ENDPOINT constant in the program to point to the API endpoint that will control the switch.
To control the switch, you can send a GET request to the API endpoint. If the request is successful, the switch will be toggled.

Here is an example of how to control the switch using a curl command:

curl -X GET http://<api-endpoint>
You can also use a web browser to control the switch by sending a GET request to the API endpoint.

## Deep sleep

When the program is in deep sleep, it consumes very little power. This makes it ideal for battery-powered applications.

To wake up the program from deep sleep, you can send a wake-up signal to the ESP8266. You can do this by connecting a pin to the ESP8266 and then pulsing the pin low for a few milliseconds.

### Troubleshooting

If you are having trouble controlling the switch, you can check the following:

Make sure that the ESP8266 is connected to your WiFi network.
Make sure that the API_ENDPOINT constant is configured correctly.
Make sure that the API endpoint is returning a successful response.
Make sure that you are sending the correct wake-up signal to the ESP8266.
