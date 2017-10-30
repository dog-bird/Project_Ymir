## Scene
1. Intro  
Scene is a set of the images. Moreover, this is the controller of the objects. Scenes are contained by SceneMgr. Scene can be transited to
other Scene.
2. Scene  
Scene is also a object. Scene can be controlled by controller.  
3. Scene Attribute  
Scene is defined as a set of objects.  
4. Object  
Object has a position, controller. Some might have addtional properties.  
5. UI controller  
There are typical UI components. Buttons, images(logo), text.  
6. Callback design  
It is hard to write code on objects or controllers, because there must be in some contexts. So, contexts(scene) decide what to do.
So, one scene has one controller. I'm not sure, I use composition or inheritence.  
