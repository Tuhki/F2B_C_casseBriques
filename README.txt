Build Options:
>Linker settings
	>>Link librairies
		C:\SDL2-2.0.5\i686-w64-mingw32\lib\libSDL2main.a
		C:\SDL2-2.0.5\i686-w64-mingw32\lib\libSDL2.dll.a
		C:\SDL2-2.0.5\SDL2_image-2.0.1\i686-w64-mingw32\lib\libSDL2_image.dll.a
		C:\SDL2-2.0.5\SDL2_ttf-2.0.14\i686-w64-mingw32\lib\libSDL2_ttf.dll.a
	>>Other linker options
		-lmingw32

>Search directories
	>>Compiler
		C:\SDL2-2.0.5\i686-w64-mingw32\include
		C:\SDL2-2.0.5\SDL2_image-2.0.1\i686-w64-mingw32\include
		C:\SDL2-2.0.5\SDL2_ttf-2.0.14\i686-w64-mingw32\include
	>>Linker
		C:\SDL2-2.0.5\i686-w64-mingw32\lib
		C:\SDL2-2.0.5\SDL2_image-2.0.1\i686-w64-mingw32\lib
		C:\SDL2-2.0.5\SDL2_ttf-2.0.14\i686-w64-mingw32\lib


INFO JEU :

- Contrôles
 Vous pouvez déplacer la raquette avec les touches Q et D, avec les flèches directionnelles et avec la souris.

- Messages
 Les messages d'information (comme la vie et le score) s'affichent sur la console.

- Gameplay
 L'apparence des niveaux est générée aléatoirement, la vitesse de la balle augmente à chaque niveau (elle va de n à 0 car elle agit sur le delay ; le jeu se termine quand elle atteint 0).

- *CHEAT*
 Si vous souhaitez passer au niveau suivant sans avoir à compléter le niveau en jouant, utilisez le clic droit de la souris (cela permet d'effacer toutes les briques et passer au niveau suivant). 
 Lorsque vous arriverez au dernier niveau, utiliser le clic droit laissera une brique apparente et un message vous indiquera que vous avez atteint le dernier niveau.