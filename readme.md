### What this is:

- I am learning various algorithms for laying out graph data (vertex and edges) visually.
- Code is based on the papers published about the algorithms and the papers are saved in the various folders containing the code for the algorithm.
- Code will be written to be followed rather than optomised

# Algorithms
#### Graph Drawing by Force-directed Placement -THOMAS M. J. FRUCHTERMAN* AND EDWARD M. REINGOLD 
>- Located in src/FruchtermanReingold

>- **Graph Drawing by Force directed placement** is part of the group of algorithms that lay graphs out by using forces between vertices. Pull (attractive) or push (repulsive) forces is applied to vertices in order to move each vertex closer to their desired locations. These algorithms are known as Force directed algorithms
>- Primarily used on **Undrirected graphs**. Undirected graphs are graphs where edge (connections) between vertices are bi-directional. 
>- The main goal of the algorithm, mentioned in the paper, is speed and simplicity.

>- Princples for the method :
> - Vertices connected by an edge should be drawn near to each other.
>	- Vertices should not be drawn too close to each other.

>- How does the algorithm work:
>	- Two main components (Vertices and Edges) drive the algorithm
>	- Simplistic explanation: Each vertex applies a push (repulsive) force to every other vertex to move them away form each other. **Connected** vertices (edges) apply a pull (attractive) force to each vertex, that is connected, to bring them closer to each other. This is repeated untill the layout stabelises.
>	- there are 3 steps for each iteration of the algorithm:
>	  - Calculate repulsive forces:
>	  - Calculate attractive forces:
>	  - Limit total movement: 
