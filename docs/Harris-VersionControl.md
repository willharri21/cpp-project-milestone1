# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## Version Control

- **William Harris**
- **Sunday, September 6, 2026**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- `clear`: Clear the Screen
- `pwd`: Print the "Working Directory"
- `ls`: List files and folders
- `ls -a`: List files and folders, including invisible files
- `ls -lh`: List all files and folders, in human readable form
- `cd [folder name]`: Change directory
- `cd /`: Change directory, go to root directory
- `cd ~`: Change directory and go to user home directory
- `cd ..`: Change directory, go up one folder level
- `cd ../..`: Change directory, go up two folder levels
- `cd ~/Desktop`: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

When I typed `cd ` and then dragged a folder from Finder/File Explorer into the Terminal window, the full file path of that folder was automatically inserted after the command. Pressing Return then changed my working directory straight into that folder, without me having to manually type out the entire path. This is a handy shortcut for navigating to folders with long or complicated paths.

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

- **Local Version Control:** Changes are tracked in a database on the developer's own machine, usually by copying files into another local directory. It's simple, but risky since everything lives in one place and there's no easy way to collaborate with others.
- **Centralized Version Control:** All versioned files are stored on a single central server, and developers check out files from that central point (e.g., SVN, older TFS setups). This makes collaboration easier than local VCS, but the central server is a single point of failure — if it goes down, no one can save versioned changes.
- **Distributed Version Control:** Every developer has a full copy (mirror) of the entire repository, including its complete history, on their own machine (e.g., Git, Mercurial). This means work can continue even without a network connection, and there's no single point of failure since any clone can restore the project.

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- `git clone [repository URL]`: Clone a repository
- `git config --global user.name "Your Name"`: Set-up a global user name
- `git config --global user.email "you@example.com"`: Set-up a global email address (to match my GitHub account email)
- `git status`: Shows the current state of your directory and staging area
- `git add [file name]` (or `git add .` for all files): Add modified files to the next commit
- `git commit -m "commit message"`: Make a commit with a new message
- `git log`: Show my commit history
- `git help`: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

To connect to GitHub over HTTPS from Terminal, I first go to the repository on GitHub, click the green **Code** button, make sure the **HTTPS** tab is selected, and copy the URL shown (it looks like `https://github.com/username/repository.git`). In Terminal, I navigate to the folder where I want the project to live and run `git clone https://github.com/username/repository.git`. The first time I push or pull, GitHub prompts me to authenticate — since GitHub no longer accepts account passwords for this, I sign in through the browser prompt or enter a Personal Access Token (PAT) in place of a password. Once authenticated, Git securely stores those credentials so I don't have to re-enter them every time.

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  A `.gitignore` file tells Git which files and folders it should *not* track or commit. This keeps the repository clean by excluding things like build output, temporary files, and personal editor settings that don't need to be shared or versioned, and it prevents clutter or accidental exposure of files that shouldn't be public.

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  `.DS_Store` is a hidden file that macOS automatically creates in folders to store Finder display settings, like icon positions and view options. It has nothing to do with the actual project code, is specific to one user's machine, and would just create unnecessary noise and merge conflicts if committed, so it's typically added to `.gitignore`.

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  Build artifacts and IDE-specific folders, such as `/bin/`, `/obj/`, `/Debug/`, `/x64/`, and `/.vs/` in a Visual Studio C++ project. These are automatically regenerated every time the project is built, so tracking them just bloats the repository and can cause conflicts between teammates using different machines or configurations — only the source files need to be version controlled.

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

The resource I found most helpful this week was the Pro Git book (git-scm.com) — its "About Version Control" and "Git Basics" chapters gave clear explanations of the differences between local, centralized, and distributed version control, along with plain-language walkthroughs of the core Git commands.

**Terminal Commands**  
[GNU Coreutils Manual](https://www.gnu.org/software/coreutils/manual/coreutils.html)

**Three Types of Version Control**  
[Pro Git Book — About Version Control](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control)

**Git Commands**  
[Pro Git Book — Git Basics](https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository)

**Connecting to GitHub using Terminal**  
[GitHub Docs — Cloning a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)

**Using .gitignore and Why it's Important**  
[GitHub Docs — Ignoring files](https://docs.github.com/en/get-started/getting-started-with-git/ignoring-files)
