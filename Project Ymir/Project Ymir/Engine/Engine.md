## Engine
1. Intro  
This class represents the whole program. This is a wrapper class of instance like Java.
2. What to do  
It will initiate the engine componets and run loop.
3. Initializing  
Initializing is very important part of this class. Unfortunately, each components may have dependancy with other components. So,
it should have order to be initialized. In this version, I set dependancy flag and Engine class initialize with this order. This 
approach is not explicit, but it will be more fun to implement. :)  
Implement is like this. At first, from the first, check whether there is a dependancy or not. If dependant component is not intialized,
goto next component. There is a boolean value for checking deadlock. If there is no new initializing, it means deadlock. Just throw
an exception.
4. Cleanup  
Cleanup should be the reverse way of initializing. To be sure, we have to memorize the order of the components.
