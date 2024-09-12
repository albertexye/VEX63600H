# Contributing to This Project

This is a guideline on how to contribute to the project. 

# Table of Contents
1. [Workflow](#workflow)
2. [Naming Conventions](#naming-conventions)
3. [Design Guidelines](#design-guidelines)
5. [Documentation Guidelines](#documentation-guidelines)

## Workflow

### Branch Structure
- `main`: Latest stable version of the project
- `develop`: Active development branch

### Contributing

1. Clone the repository:
   ```
   git clone https://github.com/albertexye/VEX63600H.git
   cd VEX63600H
   ```

2. Create a new branch for your contribution:
   ```
   git checkout develop
   git checkout -b contributor-some-issue
   ```
   Relpace "contributor" with your name and "some-issue" with the purpose of the branch. 

3. Make your changes and commit them:
   ```
   git add .
   git commit -m "[type]: Something is done"
   ```

4. Push your branch to GitHub:
   ```
   git push origin contributor-some-issue
   ```

5. Open a Pull Request (PR) on GitHub to merge your branch into `develop`.

6. Wait for the project owner to review and merge your PR.

7. After merging, the temporary branch will be deleted.

### Commit Message Format
Follow this format for commit messages:
```
[type]: Something is done
```
### Common Git Commit Types

- **feat**: A new feature for the project
  - Example: `feat: add login functionality`

- **fix**: A bug fix
  - Example: `fix: resolve issue with user profile image loading`

- **chore**: Routine tasks or maintenance (e.g., dependency updates)
  - Example: `chore: update dependencies`

- **docs**: Documentation changes
  - Example: `docs: update README with API usage instructions`

- **style**: Code style changes (formatting, missing semi-colons, etc.)
  - Example: `style: format code using prettier`

- **refactor**: A code change that neither fixes a bug nor adds a feature
  - Example: `refactor: reorganize auth logic into separate module`

- **test**: Adding missing tests or correcting existing tests
  - Example: `test: add unit tests for login component`

- **perf**: A code change that improves performance
  - Example: `perf: optimize image loading with lazy loading`

- **ci**: Continuous integration configuration changes
  - Example: `ci: update GitHub Actions to run tests on all branches`

- **build**: Changes that affect the build system or external dependencies
  - Example: `build: update webpack configuration`

- **revert**: Reverts a previous commit
  - Example: `revert: undo previous commit of adding login feature`

- **init**: Initial project setup or scaffolding
  - Example: `init: initialize project with boilerplate code`

- **merge**: Merging branches
  - Example: `merge: merge feature branch into main`

- **release**: A new release or version bump
  - Example: `release: version 1.0.0`

- **hotfix**: A critical fix for a bug in production
  - Example: `hotfix: fix crash on startup due to missing config`

### Release Cycle
- The `develop` branch is under constant active development.
- The `main` branch is always stable and tested.
- A new version is released every 2 weeks.
- Released versions are fully tested and production-ready.

### Merging to Main
Only the project owner can merge `develop` into `main`:
```
git checkout main
git merge develop
git push origin main
```

This is done when the `develop` branch reaches a relatively stable state.

### Best Practices
- Always pull the latest changes before creating a new branch:
  ```
  git checkout develop
  git pull origin develop
  ```
- Regularly sync your branch with `develop`:
  ```
  git fetch origin
  git merge origin/develop
  ```
- Use meaningful branch names that describe the feature or fix.
- Keep PRs focused on a single issue or feature for easier review.

Remember, direct pushes to `main` and `develop` branches are not allowed. Always create a new branch and submit a PR for your contributions.

## Naming Conventions

### 1. Global Constants and Macros
Use all uppercase with underscores for global constants and macros.

```cpp
#define MAX_BUFFER_SIZE 1024
const int DAYS_IN_WEEK = 7;
```

### 2. Local Variables, Member Variables, and Enum Values
Use snake_case for local variables, member variables, and enum values.

```cpp
int local_counter = 0;

class ExampleClass {
private:
    int member_variable;
};

enum Color {
    red,
    green,
    blue
};
```

### 3. Functions and Methods
Use camelCase for functions and methods, including getters and setters.

```cpp
void processData() {
    // Function implementation
}

class ExampleClass {
public:
    int getValue() const { return value; }
    void setValue(int new_value) { value = new_value; }
};
```

### 4. Types, Classes, and Enums
Use PascalCase for types, classes, and enums.

```cpp
class UserAccount {
    // Class implementation
};

struct Point {
    int x, y;
};

enum class Direction {
    north,
    south,
    east,
    west
};
```

### 5. Global Variables
Place all global variables in a namespace called `Global` and use snake_case.

```cpp
namespace Global {
    int global_counter = 0;
    std::string app_name = "MyApp";
}
```

### 6. File Names
Use snake_case for file names.

```
user_account.cpp
data_processor.h
main_application.cpp
```

## Design Guidelines

### 1. Singleton Pattern
Classes with only one global instance should follow the singleton pattern and include a static `reset` function.

```cpp
class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    static void reset() {
        getInstance() = Logger();
    }

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
```

### 2. Class Member Access
Classes should not expose members directly. Use getters and setters instead. Structures can expose all members.

```cpp
class User {
private:
    std::string name;
    int age;

public:
    std::string getName() const { return name; }
    void setName(const std::string& new_name) { name = new_name; }
    int getAge() const { return age; }
    void setAge(int new_age) { age = new_age; }
};

struct Point {
    int x;
    int y;
};
```

### 3. Function Placement
Avoid functions in the global namespace. Place functions in classes or namespaces, except for the `main`, `setup`, `autonomous`, and `drivercontrol` function.

```cpp
namespace Utilities {
    void helperFunction() {
        // Function implementation
    }
}

class MathOperations {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main() {
    // Main function implementation
}
```

## Documentation Guidelines

### 1. Use Doxygen
Use Doxygen-style comments for documentation.

### 2. Document All Elements
Provide documentation for all classes, structures, structure members, functions, methods, global variables, constants, macros, and files.

### 3. Inline Documentation
Encourage the use of inline docstrings for clarity.

Example of a well-documented class:

```cpp
/**
 * @file user_account.h
 * @brief Defines the UserAccount class for managing user information.
 */

/**
 * @class UserAccount
 * @brief Represents a user account in the system.
 * 
 * This class manages user information such as username, email, and password.
 */
class UserAccount {
public:
    /**
     * @brief Constructs a new UserAccount object.
     * @param username The user's chosen username.
     * @param email The user's email address.
     */
    UserAccount(const std::string& username, const std::string& email);

    /**
     * @brief Gets the username of the account.
     * @return The username as a string.
     */
    std::string getUsername() const;

    /**
     * @brief Sets a new password for the account.
     * @param new_password The new password to set.
     * @return true if the password was successfully changed, false otherwise.
     */
    bool setPassword(const std::string& new_password);

private:
    std::string username; ///< The user's username
    std::string email;    ///< The user's email address
    std::string password; ///< The user's password (hashed)

    /**
     * @brief Hashes the given password.
     * @param password The password to hash.
     * @return The hashed password as a string.
     */
    std::string hashPassword(const std::string& password);
};

/**
 * @def MAX_USERNAME_LENGTH
 * @brief The maximum allowed length for a username.
 */
#define MAX_USERNAME_LENGTH 50

/**
 * @namespace Global
 * @brief Contains global variables used throughout the application.
 */
namespace Global {
    /**
     * @var active_users
     * @brief The number of currently active users in the system.
     */
    extern int active_users;
}
```
