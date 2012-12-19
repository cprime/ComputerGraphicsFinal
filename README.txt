Goals:
- Create Draw a 3D figure
- Animate that figure moving throughout a space
- Add keyboard control of the camera and of the figure

Inspiration:
Cocos2d 
- an open source 2d animation engine for iOS development
- Used in game development

Challenges:
Drawing the figure
- created a node (with an XYZ position, XYZ scale, and an XYZ rotation)
- Nodes have sub nodes with their own position/scale/rotation relative to their parent
- all have their own draw function
- We setup as we draw each node, we successively apply transformations of parents and then to their children
- This way if my figure moves, his chest moves, and his arms move, if my figure gets larger, this chest and arms get larger, etc

Animating the Figure
- Encapsulate actions as objects (move action, scale action, rotate action, etc.)
- Encapsulate groupings of actions (sequences action, spawn action)
- provide framework for running these actions on Nodes
- Every time the openGL makes an idle call, keep track of the change in time, and pass this time on to the actions
- Actions update the nodes based on what needs to be done based on the time change

Moving the figure through the space:
- Set up a system to let various classes subscribe to different keyboard presses
- Scene subscribe to keys for moving the figure (turn left/right and move forward/backwards)
- decided to keep the camera looking at the same place and keeping the figure in the same place but moving the land under him as he "moved"
- keystrokes would would update his "position/rotate" in the scene, use 2d matrix math to reposition the ground


