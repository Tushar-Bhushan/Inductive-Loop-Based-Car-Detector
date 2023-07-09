# Smart-Parking
The project aims to develop a smart parking system that utilizes inductive loops and
IoT technology to optimize parking availability and improve user convenience. The
system comprises several components, including an Inductive Loop detector, Colpitts
Oscillator circuit, ESP32 for communication, Arduino Nano for frequency detection,
LM-7808 Voltage Regulator, and Bidirectional I2C Logic Level Converter from 5V to
3.3V.
The system includes a Colpitts oscillator circuit that is designed to detect the presence
of a vehicle by measuring changes in the frequency of oscillation. The electrical
properties of an inductor can be influenced by the presence of a large metallic body,
such as that of a vehicle. By measuring these changes in the properties, we can detect
the presence of a vehicle. Any other non-metallic body would not show up as a vehicle
in this system. Different values of capacitors are used to tune the oscillator circuit for
optimal performance.
The inductive loop detector is embedded beneath the parking lot surface and shows a
deflection of up to 20KHz. The frequency changes are then measured by an Arduino
Nano board, which sends the parking status to an ESP32 board for communication
with the cloud server and updates parking availability in real-time. Overall, our smart
parking system offers a scalable and efficient solution to parking management problems.
