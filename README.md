# ConfigEngine
A library that allows specification of a custom configuration system

## Why is this being created and what is it useful for?
- I have a tendency to need a configuration system for any project I make
    - This is because in theory having a perfect configuration system
    means that you will never have to recompile your program to change something
    - Furthermore, my projects sometimes have very simple demands for configuration
    but having to make a configuration system with no bugs that is different for
    every project I have is very painful
- Perhaps other people can sympathize? In that case this is for you
- Imagine being able to easily specify a configuration for your project whether
    - It's something as simple as a small program you are making for fun
    - It's a large scale project which will run in a distributed system,
    on multiple servers, with multiple users per server, with varying overlaps
    between configuration fields to automatically be determined by priority.
    - Configuration is used as "local storage". In other words, a way to standardize
    the writing of information to files which aren't used for configuration of your system.
- Either way, not needing to be concerned about the correctness, modularity, and
expandability of your configuration system is one less headache to worry about.

## This is not
- A Standalone program
- A configuration system
    - This allows you to make your own but doesn't provide you with
    any configuration out of the box
- A project intended for profit
    - I am just trying to help my and any other developers lives become a bit easier

## Planned features
- Allow Creation of Custom configuration systems through API of this library
which include the customization of
    - Structure/Format of Configurations
    - Administration System Configuration
    - Multiple parameters per field, for example:
        - priority levels
        - Accessibility permissions
    - exportability customization
- This library also provides access to your configuration system
    - Also possible to access the configuration system without the library
    by providing appropriate function pointers to constructors if desired
    - Access includes various kinds of add/remove operations
        - TBD
- Full Documentation

## Ideas undergoing consideration
- Backwards compatibility with C
- A tutorial to make various kinds of configuration systems without needing
to look up and understand a large documentation
- Commit granularity and asynchronous updates (Useful for multi-user/distributed system)
