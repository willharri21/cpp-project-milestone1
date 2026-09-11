# C++ Task Manager

A command-line task manager built in C++ as a continuous project for Project & Portfolio I. Users can add tasks and view their current task list from a simple menu.

## How to Run

1. Open `dev/main.cpp` in Visual Studio (or compile directly with `g++ dev/main.cpp dev/TaskManager.cpp -o app`)
2. Build and run
3. Follow the on-screen menu to add or list tasks

## Project Structure

- `dev/Task.h` — Task struct definition
- `dev/TaskManager.h` / `dev/TaskManager.cpp` — TaskManager class (add/list logic)
- `dev/main.cpp` — Program entry point and menu loop
- `docs/` — Course documentation and assignment write-ups

<br>

## 📢 Weekly Stand Up

### Week 1

⚙️ **Overview** – Set up my GitHub repository and Visual Studio project, then built a command-line task manager in C++. Split the code from a single file into a proper class structure (a `Task` struct plus a `TaskManager` class) with add-task and list-task functionality, organized into a `dev` folder as required.

🌵 **Challenges** – Git and GitHub Desktop gave me more trouble than the C++ itself. I ran into a `.gitignore` file that got saved without its leading period so it wasn't actually being recognized, committed straight to `main` before realizing I needed a `dev` branch, and at one point my new source files got swept into a stash when switching branches and didn't show up right away. I also hit a "can't find repository" error from GitHub Desktop after OneDrive lost track of the folder's location. Working through each of these taught me a lot about how Git actually tracks changes versus what's just sitting in my file system.

🏆 **Accomplishments** – Leveled up on organizing C++ code into separate header/implementation files instead of dumping everything into one file, and got much more comfortable with Git branches, stashes, and diagnosing why GitHub Desktop wasn't showing what I expected. Also learned to always double check my commit history before assuming something was saved.

🔮 **Next Steps** – Add functionality to mark tasks complete and delete tasks, and start looking into saving/loading the task list from a file so data persists between runs. Going forward I want to commit more incrementally as I code, rather than in one batch at the end.
bash

cat << 'EOF'
### Week 2

⚙️ **Overview** – Built on the Task Manager from Milestone 1 by adding mark-complete and delete functionality to the `TaskManager` class, along with input validation on the main menu so non-numeric input no longer crashes the program. Updated my documentation with a Milestone 2 changelog and kept my GitHub Issues and Project Board in sync with the actual work as I did it.

🌵 **Challenges** – Ran into a couple of Git snags again this week — Visual Studio showed my project files as locked/read-only after some file operations, which blocked me from saving changes until I cleared the read-only attribute on the whole folder. I also had a change get swept into a stash again during a branch operation, so I'm getting more careful about checking for stashes before assuming something wasn't saved.

🏆 **Accomplishments** – Got real practice using `std::find_if` from the `<algorithm>` library to locate a task by ID instead of writing a manual loop, and leveled up on handling `std::cin` failure states properly for input validation instead of just hoping the user types the right thing.

🔮 **Next Steps** – Apply the same input validation pattern to task ID entry (right now only the main menu choice is protected), and start looking at task editing and file-based save/load so tasks persist between runs.
EOF
Output

### Week 2

⚙️ **Overview** – Built on the Task Manager from Milestone 1 by adding mark-complete and delete functionality to the `TaskManager` class, along with input validation on the main menu so non-numeric input no longer crashes the program. Updated my documentation with a Milestone 2 changelog and kept my GitHub Issues and Project Board in sync with the actual work as I did it.

🌵 **Challenges** – Ran into a couple of Git snags again this week — Visual Studio showed my project files as locked/read-only after some file operations, which blocked me from saving changes until I cleared the read-only attribute on the whole folder. I also had a change get swept into a stash again during a branch operation, so I'm getting more careful about checking for stashes before assuming something wasn't saved.

🏆 **Accomplishments** – Got real practice using `std::find_if` from the `<algorithm>` library to locate a task by ID instead of writing a manual loop, and leveled up on handling `std::cin` failure states properly for input validation instead of just hoping the user types the right thing.

🔮 **Next Steps** – Apply the same input validation pattern to task ID entry (right now only the main menu choice is protected), and start looking at task editing and file-based save/load so tasks persist between runs.