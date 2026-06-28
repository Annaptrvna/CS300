## CS 300 Journal

### 1. What was the problem you were solving in the projects for this course?

In the two projects, my goal was to create a course planning tool that could read course details from a CSV file, organize the data so it could be quickly accessed by course number, list all Computer Science courses in alphanumeric order, and provide complete details about an individual course, including its prerequisites. The program also needed to verify that prerequisite course numbers existed in the course catalog. Additionally, if there was an error in a record for any reason, the program needed to continue running without crashing.

For Project One, I researched multiple data structures (vectors, binary search trees, hash tables, etc.) to determine which one would best meet these requirements. For Project Two, I chose a hash table because it allowed efficient course lookups by course number. I then copied the course data into a vector and used `std::sort()` before displaying the courses to the user. This project taught me that selecting a data structure depends on the application's requirements rather than simply choosing the fastest or simplest option. To build software that is both efficient and scalable, it is important to understand the different ways data can be stored and accessed.

### 2. What steps did you use when approaching this problem? Consider why understanding data structures is essential.

First, I reviewed the advantages and disadvantages of vectors, binary search trees, and hash tables. Because my program needed to rapidly locate courses by course number, I selected an `unordered_map` because it provides efficient lookups. However, since hash tables do not maintain any specific order, I copied the course objects into a vector and used `std::sort()` to print the courses in alphanumeric order. This experience showed me that many factors influence the choice of a data structure. Understanding how different data structures store and retrieve information makes it possible to develop software that is both efficient and scalable.

### 3. How did you overcome any roadblocks you encountered while going through the activities or project?

There were several obstacles. First, I needed to correctly read the CSV file and handle records containing different numbers of prerequisites. Second, I had to verify that every prerequisite course number actually existed within the course catalog. Third, I wanted users to be able to search for courses regardless of whether they entered uppercase or lowercase course numbers. I solved this by converting all course numbers to uppercase before storing and searching them. Finally, I broke the larger project into smaller functions such as loading data, printing courses, searching for a course, and converting strings to uppercase. This approach made debugging much easier than trying to solve everything at once.

### 4. How has your work on this project expanded your approach to designing software and developing programs?

Before writing this program, I spent more time planning the overall design than I had in previous assignments. Deciding where the data should be stored and how each function would interact with the others made implementing the solution much easier. I also realized that separating the user interface from the application logic creates a cleaner design that is easier to modify in the future. Overall, this project reinforced my belief that good software design begins long before writing the first line of code.

### 5. How has working on this project influenced how you write software that is maintainable, readable, and flexible?

Working on this project further emphasized the value of writing modular code where each function has a single responsibility. Rather than placing all of my logic inside `main()`, I divided the program into separate functions such as `loadCourses()`, `printCourseList()`, `printCourse()`, and `toUpperCase()`. Organizing the program in this way made it easier to read, test, and maintain. It also makes future enhancements simpler because changes to one part of the program are less likely to affect other functionality. I also learned the importance of validating input and handling errors gracefully rather than assuming that every file and every user input is valid.
