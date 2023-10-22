# Arduino Robot Project

The Arduino Robot Project, a versatile set of Arduino code and hardware configurations for creating autonomous, remote-controlled, line-following, and obstacle-avoidance robots. This comprehensive project includes multiple code files, each tailored to specific robot functionalities. Whether you're a beginner or an experienced maker, you'll find valuable insights into robotics and Arduino programming.

## Table of Contents
- [Introduction](#introduction)
- [Components and Materials](#components-and-materials)
- [Code Files](#code-files)
- [Getting Started](#getting-started)
- [Contributions](#contributions)
- [License](#license)

## Introduction
This project is a collection of Arduino code and hardware configurations for building various types of robots, including:

- **Autonomous Robot (AUTO_GO.ino):** An autonomous robot capable of moving forward, backward, left, and right. It's ideal for testing motors and creating the foundation for autonomous navigation.

- **Bluetooth-Controlled Robot (bluetooth_car.ino):** A robot that can be remotely controlled using a Bluetooth connection. You can send commands via a Bluetooth remote control app to make the robot move in different directions.

- **Line-Following Robot (Line_tracking_car.ino):** A robot designed to follow a black line on the ground. It uses sensors to stay on the line and make turns as needed.

- **Obstacle Avoidance Robot (obstacle.ino):** An obstacle-avoidance robot equipped with ultrasonic sensors and a servo motor. It can autonomously navigate its environment, detect obstacles, and choose safe paths to avoid collisions.

## Components and Materials
Before starting this project, you will need the following components and materials based on the specific robot you want to build:

- Arduino board (e.g., Arduino Uno)
- Motor driver (e.g., L298N) for motor control
- Ultrasonic sensors (HC-SR04) for obstacle detection
- Servo motor for scanning and obstacle avoidance
- Line tracking sensors (if building a line-following robot)
- LEDs and a buzzer for indicating car status (if building an obstacle-avoidance robot)
- Chassis, wheels, and power sources specific to your robot design
- Jumper wires for connecting components
- A breadboard (optional)

## Code Files
This project includes several code files, each tailored to a specific type of robot:

- **AUTO_GO.ino:** This code is for building an autonomous robot that can move forward, backward, left, and right. It's an essential starting point for autonomous navigation.

- **bluetooth_car.ino:** Use this code to create a robot that can be controlled remotely via Bluetooth. It interprets commands sent via a Bluetooth remote control app.

- **Line_tracking_car.ino:** This code is designed for building a line-following robot. It follows a black line on the ground using line tracking sensors.

- **obstacle.ino:** For building an obstacle-avoidance robot, this code employs ultrasonic sensors and a servo motor to navigate autonomously, detect obstacles, and choose safe paths.

Each code file includes detailed comments and documentation to assist you in understanding and customizing the code for your specific robot project.

## Getting Started
To get started with your robot project, follow these general steps:

1. Assemble the hardware components based on the specific robot design you're building.

2. Upload the corresponding code to your Arduino board using the Arduino IDE.

3. Power up the robot and observe its behavior. Be sure to customize the code as needed for your particular project goals.

Refer to the individual code files for specific setup and usage instructions for each robot type.

## License
This project is open-source and distributed under the MIT License. 
