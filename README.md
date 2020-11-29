# Tetris

Implementation of Tetris with SDL2 and C++. Another educational
project created to accumulate proficiency with object oriented design,
template design, and proper C++ programming.

# Intent

The point of this project is to create a space where I can make
(potentially horrendous) software design decisions in pursuit of
software design mastery.  Having not done any professional C++ coding,
I needed an environment in which to stress my understanding of the
language and its design principles through implementation. The
acceptable software born here can move on to become the groundwork for
my next projects; the Allengine uses almost the same Engine
implementation as Tetris.

# Design

## Engine

The `Engine` class orchestrates the Tetris runtime. It is responsible
for creating and maintaining the SDL window, keeping the frame timer,
updating game components, handling input, and calling the
renderer. The `advance` function template is used to advance the game
for a single frame, and is SFINAE'd away if called with a vector of
anything other than `GameComponents`. The instantiation for that type
also includes the instantiation for the private methods
`render_components` and `update_components`; the
`GameRenderer::render` function template only requires that the
template argument "is renderable", ie, has a `get_render_components()`
method. This is the only specialization for this template, so a call
to the renderer with a class that does not meet that requirement will
cause a compilation error. The requirement itself is verified using a
tag dispatch; a struct is created that either extends
`std::false_type` or `std::true_type` based upon whether or not the
required method is present, and the `render` method is SFINAE'd
accordingly. 
* * *
The use of static polymorphism here solves an issue that
appeared in the interaction between the Tetris implementation, the
Engine implementation, and the GameComponents. At first the
`get_render_components()` method was a pure virtual function in
`GameComponent`. The thought was, if the Engine doesn't know what
implementation the Gamecomponent's RenderComponents had, it would be
decoupled from any given game implementation. However, this meant that
the Tetris implementation also couldn't reference the RenderComponent
implementation directly, and had to downcast to the implementation to
get the desired interface. The games running on the engine necessarily
must manipulate the RenderComponents of their GameComponents, and
downcasting for each different RenderComponent implementation was
cumbersome. To solve this problem (after reading much about C++
templates and metaprogramming), the `advance`, `update_components`,
and `render_components` methods in the `Engine` class became function
templates, as well as the `render`, `render_implementation`, and
`render_all` methods in the `GameRenderer`. The `advance` template's
requirements were discussed above; the type percolates down into the
rendering methods. These methods are only all instantiated if the type
being rendered has that `get_render_components()` methods, and also
only if the type returned from that method extends
`RenderComponent`. This way, the `get_render_components()` method
could be moved to implementations of `Gamecomponent` and could return
implementations of `RenderComponent`. Tetris can handle the
implementations directly, without any casting, and the Engine can
handle the abstactions, without any prior knowledge of their actual
implementations.

# Tetris

## Controls

Assuming one is successful in building the project with the newly
minted CMake integration, the controls for playing Tetris are:  
r: rotate  
left arrow key: move piece left  
right arrow key: move piece right  
down arrow key: move piece down  
enter: drop piece to bottom  
As of now, there is no option to save a piece for later. This is a
simple, barebones implementation of Tetris.

## Mathematics

There was some fun mathematics involved in rotating the tetris pieces;
more to come later. 

# Build

I have added CMake compatibility for the Tetris executable, but not
for the tests. Running Tetris requires PThreads, SDL2, SDL2\_Image, and
SDL2\_TTF. The CMakeLists.txt file is under the /build/cmake/
directory. 
