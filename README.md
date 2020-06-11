# AC130Flight
This project focuses on building an arcade style flight simulator of an AC-130J. It is controlled primarily through rigid body physics so the 3 DOF of pitch, roll, and yaw are present in the game mechanics making it straightforward an easy to handle. 

If the plane's position changes: pitch up/down or roll left/right, serial communication will be established to an arduino which will control 3 servo motors to mirror the AC-130J's position in the simulation representing 3 DOFs. 

**Made in Unity 2019.2**

![](https://github.com/darrentran33/AC130Flight/blob/master/Screenshots/legoplane.gif)

![](https://github.com/darrentran33/AC130Flight/blob/master/Screenshots/unityplane.gif)

## Download 

You can either clone the repository or [download the asset package](https://github.com/darrentran33/AC130Flight/tree/master/Assets) located in the root.

## Controls

The default game controls function around the arrows on a keyboard. The game is being developed to be compatible with an Oculus Quest.
When the game package is downloaded and installed, the default controls will be used to control pitch and roll. Yaw can be controlled through a combination of the pitch and roll commands.

  * Up arrow - Pitch up
  * Down arrow -Pitch down
  * Left arrow - Roll left
  * Right arrow - Roll right


