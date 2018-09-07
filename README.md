Configuration Engine
A library that allows the user to specify a custom configuration system for his/her project.

What is it useful for?
Running ConfigEngine saves the user from having to recompile his/her programs for general fixes.
Config Engine is used as “local storage”. This means it standardizes the writing of information to files which aren’t used for configuration of your system.
Can be used for all sorts of programs from a small scale program to a large scale project.
User doesn’t need to be worried about correctness, modularity, and expandability of their configuration system.

Planned Features

Multiple Configuration Profiles
   Nested profiles
API of the ConfigEngine Library includes:
   Structure/Format of Configurations
   Administration System Configuration
   Multiple parameters per field i.e. priority levels
   Exportability customization

Accessibility
   Possible to access the configuration system w/o library by providing appropriate function pointers to constructors
   Includes various kinds of add/remove operations
   Full Documentation

Possible Considerations
   Backwards compatible with C
   Tutorial on how to make custom configuration system
      Saves the user from reading large documentations.
   Commit granularity and asynchronous updates
      Multi-user/distributed systems.

Notice
   Not a Standalone program
   Not a configuration system in that it provides the user with one but the user must provide the specifications.
   Not intended for profit.

