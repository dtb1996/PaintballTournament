# PaintballTournament
A first-person paintball game that is won by fending off the opposing team and stealing their flag.

****************************************************************************************

Attributions

Paintball gun:
MG13 PaintBall Gun by SDHARDWARE
https://www.turbosquid.com/FullPreview/Index.cfm/ID/587446

Flag:
Flag with Pole by samdb_
https://www.turbosquid.com/FullPreview/Index.cfm/ID/1274583

Paint splat particle system:
Based on "Unreal Engine | Blood Material and Particle Tutorial" by CGHOW
https://www.youtube.com/watch?v=hhcUDejc-E4

HUD icons:
Taken from Some HUD Elements, Icons, and Crosshairs by sbed
https://opengameart.org/content/some-hud-elements-icons-and-crosshairs

Player character and animations:
Ninja from mixamo.com
https://www.mixamo.com/#/?page=2&type=Character

Enemy character and animations:
David from mixamo.com
https://www.mixamo.com/#/?page=2&type=Character

****************************************************************************************

Description

This artifact is a first-person paintball tournament simulator, originally created as part of the Game 
Programming and Development coursework at Southern New Hampshire University. This version, refined in the final capstone course, includes AI opponents and additional game mechanics based on the first-person shooter genre. The goal of this game is to capture the other team's flag while avoiding their offensive attacks.

Tools Used

- Unreal Engine 4
- Visual Studio
- Adobe Photoshop
- GIMP

Reflection

How would you describe the process of creating and polishing the artifact?

The original version of this game was created in a class that was focused on graphical programming using C++. Most of those elements have been removed, but the barricades remain and the custom shapes and materials were added through code rather than the Unreal Engine editor. Refining the game involved switching the firing mechanics from a projectile-based method to a line-trace. A paint splatter particle system was added to represent the hit location and the explosion for the paint grenade. Next, the AI characters were added with basic sight, chase, and fire capabilities. A flag actor and capture point were introduced to give the player a main goal during play. Each has an option to specify which team it belongs to, and the material colors change at runtime based on the selection. Finally, various meshes were imported and a game HUD was added to show the player's health, ammo, and the aiming crosshair.

What did you learn as you were creating it and improving it?

When I created the original version of Paintball Tournament, I had very little experience with creating materials and custom 3-D models. Having to make custom objects in C++ helped me get a better understanding of how the program handles 3-D graphics. While refining the game, I focused on turning the project into a first-person shooter that had most of the components that are standard in the genre, such as regenerating health, grenades, and ammo/reload functionality. I also learned how to setup line traces for both the player and enemy guns that would register a hit and damage an opposing player. Finally, I made alterations to a particle system that I created following the attributed tutorial to make it fit the paintball theme.

What challenges did you face?

During the process of creating the initial paintball game, I had to figure how to create custom C++-based geometry and use dynamic materials to create varied graphical elements. This was a very time-consuming process, and the features I had planned for the gameplay had to be left out. While refining the project, I struggled with scope creep, as I wanted to include more first-person shooter mechanics and a more advanced AI system.

How did you incorporate feedback as you made changes to the artifact?

As I made changes to this artifact, I kept in mind what was missing from the original game and what others had suggested I add to improve it. Most of the custom graphical elements did not add to the overall gameplay, so I dropped those to focus on the base game.

How was the artifact improved?

- Created AI characters that engage the player
- Added a flag capture goal
- Added physics-based paint grenades
- Added an ammo counting system for the gun and grenades
- Added a reload function for the player gun
- Imported models and textures for the characters, weapons, and flags
