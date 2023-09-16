# TrackLight
This project presents an innovative automotive spotlight system utilizing ultra-wideband (UWB) technology to track and follow the user's movements. The aim of this system is to provide enhanced visibility and illumination for occupants, enabling a seamless and personalized lighting experience. By integrating UWB technology, the spotlight can accurately detect the user's position and movements in real-time, allowing the light beam to dynamically adjust its direction and focus accordingly. This tracking capability is achieved through a combination of UWB transceivers strategically positioned in the vehicle and a wearable UWB tag worn by the user. The spotlight system leverages the UWB signals exchanged between the transceivers and the tag to calculate the user's precise location, enabling the spotlight to continuously track and illuminate the user's surroundings. This innovative solution enhances user comfort, safety, and convenience within the vehicle, eliminating the need for manual adjustment of the spotlight and ensuring optimal illumination is always provided.




Components for Automotive Spotlight:

1- ESP32 UWB Microcontrollers (4x): These microcontrollers, such as the ESP32 UWB module, serve as the core processing units for the spotlight system. They integrate the necessary UWB functionality, enabling precise positioning and tracking of the user within the vehicle. The ESP32 microcontrollers handle UWB signal processing, communication with UWB transceivers, and coordinate the spotlight's movement and rotation.


![unnamed](https://github.com/Ahmedaltu/TrackLight/assets/76178825/82e186de-1d09-43df-8c4e-96163715ab02)



2- HLS8L-DC3V-S-C Relay: This relay serves as the interface between the ESP32 microcontrollers and the RF remote control system of the spotlight. The relay allows the microcontrollers to control the on/off and rotation functionality of the spotlight, based on the user's position and commands received from the RF remote control.
3- RF Remote Control: The RF remote control device enables manual control over the spotlight's on/off functionality and rotation. It communicates wirelessly with the ESP32 microcontrollers via the relay, providing a convenient means for users to override the automated tracking system and adjust the spotlight as desired.

4- Rotating Spotlight: The spotlight itself consists of a high-quality lighting module capable of rotating and adjusting its direction. The ESP32 microcontrollers control the spotlight's rotation based on the user's position and movement tracked by the UWB system. The rotating spotlight ensures that the user is illuminated effectively, regardless of their location within the vehicle.


Overall, this component framework integrates the ESP32 UWB microcontrollers, UWB transceivers, HLS8L-DC3V-S-C relay, RF remote control, and rotating spotlight to create an advanced automotive spotlight system. The system combines UWB tracking technology with manual control options, enhancing the user experience by providing personalized and dynamic lighting within the vehicle.


![Screenshot 2023-09-16 220714](https://github.com/Ahmedaltu/TrackLight/assets/76178825/b007925a-ab18-48df-9e02-31b8c7060736)

