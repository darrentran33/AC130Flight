# AC130Flight
This  project focuses on building an arcade style flight simulator of an AC-130J. It is controlled primarily through rigid body physics so the 3 DOF of pitch, roll, and yaw are present in the game mechanics making it straightforward an easy to handle. 

If the plane's position changes: pitch up/down or roll left/right, serial communication will be established to an arduino which will control 3 servo motors to mirror the AC-130J's position in the simulation representing 3 DOFs. 

![](https://github.com/darrentran33/AC130Flight/blob/master/Screenshots/legoplane.gif)

![](https://github.com/darrentran33/AC130Flight/blob/master/Screenshots/unityplane.gif)

## Unity Simulation

### Download Assets

You can either clone the repository or [download the asset package](https://github.com/darrentran33/AC130Flight/tree/master/Assets) located in the root.

### Software

 * CAD designs of the AC130J, flaps, and propellors was done in Autodesk Maya
 * Unity Script was dones in Visual Studio
 * Script, Animations, and Gameobjects put together in **Unity 2019.2**

### Controls

The default game controls function around the arrows on a keyboard. The game is being developed to be compatible with an Oculus Quest.
When the game package is downloaded and installed, the default controls will be used to control pitch and roll. Yaw can be controlled through a combination of the pitch and roll commands.

  * Up arrow - Pitch up
  * Down arrow -Pitch down
  * Left arrow - Roll left
  * Right arrow - Roll right
  
### Unity Communication with the Arduino

You will need to establish what port the Arduino is in as well as the Baud rate in which the computer will communicate with the Arduino.

``` C#
sp = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);
```

When the game is started, the serial port will be opened.

``` C#
sp.open;
```

When the plane's position in respect to the pitch and roll axis is changed during the simulation, Unity will send a message.

``` C#
sp.write(" Message ");
```

When Unity is closed, the serial port will be closed.

``` C#
sp.close;
```

## Arduino Simulation

### Hardware

* Arduino Uno
* 3 x MG996R Servo Motors
* 4 AA Battery Holder
* PCA9685 Motor Driver Board

### Wiring The Motion Platform

<img src="https://github.com/darrentran33/AC130Flight/blob/master/Screenshots/Circuit%20Schmatic.JPG" width="400" height="300">

The lone front servo motor will allow mimicing the nose while the back two servo motors will mimic the horizontal stabilizers. The PCA9685 motor dirver board communicates to the Arduino via an I2C connection.


### Arduino Communication with Unity

When Unity sends a message to the Arduino it is read and the respective motor configuration will be performed.

```C++
if (Serial.available()){
 sig = Serial.read();
 }
```



