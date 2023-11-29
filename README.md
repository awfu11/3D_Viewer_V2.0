# 3DViewer v2.0

Implementation of 3DViewer v2.0

![](materials/animation.gif)

## Installation
      make install

## Uninstallation
      make uninstall

## Introduction

This project implements an application for viewing 3D wireframe models in C++ in the object-oriented programming paradigm.


### Design patterns

**Design pattern** describes a frequently repeated application design problem and its way of solving, which is universal to that problem.
In other words, a design pattern for a programmer is nothing but a building block, an elementary unit that is implemented when a typical subtask occurs within a project.

Design patterns are usually divided into three groups: creational, structural and behavioral patterns. See materials for more information about design patterns. \
Just as a reminder, MVC in some form or another is one of the most common solutions in terms of code structuring during UI application development.
The user interface and the business logic with its controller are usually split into two different global domains: the interface domain and the business logic domain.

The interface domain is only responsible for displaying the interface and passing commands to the business logic domain. Data loaded from a file should not be stored in the interface domain.

The business logic domain is responsible for the main functionality of the system. This is where the loaded data is stored and all the operations with it are performed. This domain is also where the rendering is done.


## Facade pattern (facade)

#### Purpose of the Facade pattern

- The Facade pattern provides a unified interface instead of a set of interfaces of some subsystem. Facade defines a higher-level interface that simplifies the use of the subsystem.
- The Facade pattern "wraps" a complex subsystem with a simpler interface.

## Strategy pattern (strategy)

#### Purpose of the Strategy pattern

There are systems whose behavior can be determined according to one algorithm from a certain family. All algorithms of this family are related: they are designed to solve common problems, have the same interface for use and differ only in implementation (behavior). The user, having pre-configured the program for the desired algorithm (by choosing a strategy), receives the expected result.

## Command pattern (command)

#### Assignment of the Command pattern

Use the Command pattern if

- The system is managed by events. If such an event (request) occurs, you must perform a certain sequence of actions.
- It is necessary to parameterize objects by the action being performed, queue requests or support undo and redo operations.
- You need an object-oriented analogue of the callback function in procedural programming.

## Implementation of the 3DViewer v2.0

Develop a program to visualise the 3D wireframe models.

- The program must be developed in C++ language of C++17 standard
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- The program should be developed according to the principles of object-oriented programming; the structured programming approach is not allowed
- Prepare full coverage of modules related to model loading and affine transformations with unit-tests
- There should be only one model on the screen at a time
- The program must provide the ability to:
    - Load a wireframe model from an obj file (vertices and surfaces list support only).
    - Translate the model by a given distance in relation to the X, Y, Z axes.
    - Rotate the model by a given angle in relation to its X, Y, Z axes.
    - Scale the model by a given value.
- GUI implementation, based on any GUI library with API for C++: Qt.
- The graphical user interface must contain:
    - A button to select the model file and a field to output its name.
    - A visualisation area for the wireframe model.
    - Button/buttons and input fields for translating the model.
    - Button/buttons and input fields for rotating the model.
    - Button/buttons and input fields for scaling the model.
    - Information about the uploaded model - file name, number of vertices and edges.
- The program must correctly processes and allows user to view models with details up to 100, 1000, 10,000, 100,000, 1,000,000  vertices without freezing (a freeze is an interface inactivity of more than 0.5 seconds)
- The program must be implemented using the MVC pattern, and also:
    - there should be no business code in the view code
    - there should be no interface code in the controller and the model
    - controllers must be thin
- There should be at least three different design patterns (facade, strategy and command)
- The program must allow customizing the type of projection (parallel and central)
- The program must allow setting up the type (solid, dashed), color and thickness of the edges, display method (none, circle, square), color and size of the vertices
- The program must allow choosing the background color
- Settings must be saved between program restarts
- The program must allow saving the captured (rendered) images as bmp and jpeg files.
- The program must allow recording small screencasts - the current custom affine transformation of the loaded object into gif-animation (640x480, 10fps, 5s) by a special button
