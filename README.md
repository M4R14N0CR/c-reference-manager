<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
</head>
<body>
  <h1>Reference Management in Categories</h1>

  <h2>Overview</h2>
  <p>
    This project, developed in C, manages references organized by categories using a hash table combined with doubly linked lists. It allows users to add, delete, search, and print both categories and their associated references, offering an efficient and dynamic way to store and retrieve information.
  </p>

  <h2>Main Features</h2>
  <ul>
    <li>
      <strong>Hash Table:</strong> Implements a hash table for storing categories, using a hash function and linear probing to handle collisions.
    </li>
    <li>
      <strong>Doubly Linked Lists:</strong> Each category holds a doubly linked list containing references that are sorted alphabetically by title, along with their links and summaries.
    </li>
    <li>
      <strong>Automatic Resizing:</strong> The table automatically resizes when it reaches 75% occupancy, using a new size based on the next prime number to enhance distribution.
    </li>
    <li>
      <strong>Management Functions:</strong> The program features functions for inserting and deleting categories, as well as adding, removing, and searching for references both within a specific category and globally.
    </li>
    <li>
      <strong>Interactive Menu:</strong> An interactive console menu allows users to select different operations.
    </li>
  </ul>

  <h2>Project Objective</h2>
  <p>
    The primary goal is to demonstrate the use of dynamic data structures in C by combining a hash table with doubly linked lists for efficient data management. This approach enables rapid insertion, search, and deletion operations, improving the overall data handling efficiency.
  </p>

  <h2>Technologies and Concepts</h2>
  <ul>
    <li>Programming Language: C</li>
    <li>Dynamic Memory Allocation using <code>calloc</code> and <code>free</code></li>
    <li>Data Structures: Hash Table and Doubly Linked Lists</li>
    <li>Algorithms: Hash function, linear probing for collision handling, and calculating the next prime number for resizing</li>
  </ul>

  <h2>Conclusion</h2>
  <p>
    In summary, this project provides a comprehensive solution for managing categorized references. By integrating hash tables and doubly linked lists, it delivers an efficient, scalable system for quick data retrieval and management, demonstrating robust programming techniques and data structure handling in C.
  </p>
</body>
</html>
