#ADVANCED GAME PROGRAMMING: ASSIGNMENT ONE

To this first assignment of advance programming we have several option to choose and I took to make a minigame
in Unreal so I can learn the basics in this platform and produce a simple game. For that I´ve chosen to follow
the Twin Stick Shooter tutorial in the Unreal webpage and make few twicks to it. The goal of the game basically
is to kill all enemies that are going to be spawn around the level. The steps followed create the 
assignment game were:

 1. Map Generation
 2. Character Class 
 3. Weapon and Projectile
 4. Health and Score
 5. Respawn Enemy and Hero 
 6. Animations
 7. Sounds 
 8. Problems found 
 9. Possible improvements
 10. Greetings 

 [AGB Assignment 1](https://youtu.be/8_KrbfG6R2U)

# 1. MAP GENERATION

The first step in the game is to set the level. The basic one is a square rounded by walls where the action takes 
place inside. I´ve change the design the level to make it more intresting and get with the goal of start in one point
and try to find the another place in the map to pass to the next level killing enemies along the way. In this case
I modified the original design adding some walls with textures.

Include image of tutorial map and created for me

![Alt text](https://github.com/javolo/octet/blob/master/octet/src/examples/AssignmentOne/images/ScreenDifference.gif "Map Level")

# 2. CHARACTER CLASS

The second step was to create a player in Unreal. In this step is where it´s included all the C++ code in this project.
It´s a basic script where there are a couple of variables (Health of the player and a boolean to check if the player 
is dead) and a couple of functions, one to calculate the Health and other one to check if the player is dead or not.

Once we have that the only thing I have to do is attach this script to the Hero Blueprint to access the method and 
variables within. The other part of this section is to include in the Blueprint class the asset and define the
orientation and place where the player is going to be spawn. 

To do this I am going to be create in a specific blueprint class containing all the basic elements of the game, the
player initial position, the way the enemies are spawn and some of the health score treatment. 

Include image of twin stick mode

![Alt text](https://github.com/javolo/octet/blob/master/octet/src/examples/AssignmentOne/images/PlayerBackground.gif "Background Player Image")

# 3. WEAPON AND PROJECTILE

After we have the basic character and hero done I created the weapon and projectile blueprint classes. In the weapon 
blueprint we´ve tried to mimic the fire of a trigger to fire projectiles through some chain of events. In the projectile
class we define the object itself and include some of the logic when the enemy is damaged.

One of the trickiest part about the weapon is to make it fit perfectly with the hand of the player to look as mas realistic 
as possible:

Include pic of fit the weapon

Regarding the projectile what we´ve customized it´s the size of the laser and the color of it. As extra feature we´ve
included some particle associated to make throw sparks when a laser hits an enemy. In there we´ve customized the color,
the way is spawned, the size and direction of it.

Include pic of panel of sparks

# 4. HEALTH AND SCORE

In this section we´ve done two things. The first one is the HUD Canvas to hold at the top of the game screen a slider
with the health of the player in the left hand side and a text with the score in the right side. The score is increased
when an enemy dies awarding 500 points. The health bar decreases when the enemy touch the player.

The second item done is all the health system for either enemy and hero. Including in the hero health behaviour we delay
the respawn player option a couple of second to perform the death animation. We have to make sure that when we create the
player again the gun is attached to it. When the player is dead and the object is destroyed we have to include the gun as
well to avoid leave behind the weapon in the map. For the enemy we made something similar but besides that we include one
step further and where we are playing the death animation we deactivate the collider attached to the enemy so the player
and the other enemies can pass through it and by it.

How the health is treated in both cases is different. When in the Enemy Character we include a logic to call a function
when the enemy overlap the player and substract the damage from the player, to remove health from the enemy is done 
when the projectile collides with the Enemy character.

Include screenshot of Enemy logic and Weapon

# 5. RESPAWN ENEMY AND HERO

The way in which the hero and the enemy are respawn is different. When the hero dies and perform the relevant animation
the character is spawned again in the start position defined at the beginning of the game.

Then enemy is born within a NavMeshBoundVolume that with the logic to respawn the enemies anywhere within this boundaries
through events the enemies keeps appearing while we didn´t reach the maximum number of them and every opponent created
inmediately goes after the player to kill him.

Include screenshot of spawn enemy

# 6. ANIMATIONS

The animation component of the player is formed of two things. The animation itself where we perform element such as
walking, jogging or death, and the blend space where we join all the animation parts together.

Include screenshot of blend

# 7. SOUNDS

One of the extra feature we´ve included is some sounds like for example when you fire the gun. I also include some
background music and some death sound effect that plays when the animation of either the enemy or hero fall to the
floor dead.

# 8. CHALLENGES FOUND

## 8.1 Little script, events logic
One of the things that cost me some time to get used to it, it´s that to customize the behaviours of the player or
enemy everything goes by set of events concatenated each other. Coming from scripts from Unity and have to do this
by events change somehow the way of thinking and make you aware of that there a lot of functions and components that
Unreal provide you to make a game.

## 8.2 Make twicks and make them work
At the beginning of the tutorial advices to not change so much the steps to make the game to work. To make more attractive
and interesting some twick have been included. Some of them took time to make them work, other ones were easy to include.
Due to my lack of experience with Unreal some of the changes introduced were a challenge that finally I get.

# 9. POSSIBLE IMPROVEMENTS

As this is the first kind of game I made with Unreal there is a lot of features and insights that I´ve missed along the way.
Besides that a lot of things can be added to the game:

 * Deep down into the Hero animation and modify its parameters (inlcude shield, gun folder, vest with knife...) 
 * Include design elements to the level such as doors, windows, textures...
 * Create a level with two heights and add some physics (upstairs, downstairs, jump...)
 * Jump between levels when reach specific place in the map
 * Make the enemy to hold a gun and shot the player not only chase him.
 * Randomize the colour of the enemy when spawn.

# 10. GREETINGS

Just a small note to credit http://www.freesfx.co.uk for the sounds