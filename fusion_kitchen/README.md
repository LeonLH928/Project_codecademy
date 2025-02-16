# Project Title: 
- Fusion Kitchen.

# Description: 
This project:
- is implemented in C++.
- model relationships: Imagine that you’re designing a system to manage different types of restaurants. You notice that all restaurants share some basic features - they all have a name, an address, and they all serve some kind of food. However, each type of restaurant also has its unique characteristics. A Mexican restaurant might have a spice level rating, while a Japanese restaurant might have a traditional seating style.
- contains: The Restaurant class is the parent, containing all the basic features.
Specific restaurant types (Mexican, Japanese) are children, inheriting these basic features while adding their own unique traits.
The fusion restaurant is like a child of both Mexican and Japanese restaurants, combining features from both cuisines!
- uses the knowledge of Inheritance in OOP programming. Specifically, this project use multiple inheritance, virtual (to avoid the diamond problem), inheritance access specifiers, etc.

# Features:
- This project can create objects of JapaneseRestaurant, MexicanRestaurant, and MexicanJapaneseFusion.

# How to use:
- Here in main.cpp, we have had some simulations of these relationships, try out if you want to. 
- How to run: Open the terminal, type the following command to compile: g++ *.cpp; and then run ./a.exe to see the output.

# Collaborators: 
This project is developved by myself based on the instructions given on Codecademy.

# License: 
MIT license.