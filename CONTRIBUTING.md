# Contributing to This Project

This is a guideline on how to contribute to the project. 

## Branches and Workflow

- **Main Branch**:  
  The `main` branch is always stable and represents the latest production-ready release. Code in this branch has passed all tests and is considered ready for production use. No direct commits should be made to the `main` branch.
  
- **Develop Branch**:  
  The `develop` branch is where ongoing work happens. All feature branches and bug fixes should be based off this branch. Once your feature or bug fix is ready, please create a pull request (PR) to merge your changes into `develop`. After a review and approval, your changes will be merged.

- **Releases**:  
  Every 2 weeks, the project owner will review and fully test the code on the `develop` branch. If everything is stable, a PR will be created to merge `develop` into `main` for the next release. In case of critical fixes, emergency patches may be made, and a new release will be created sooner.

- **Versioning and Production**:  
  The latest release version will be tagged and considered the production version in use. All new changes should be merged into `develop`, ensuring they don't affect the stability of `main`.

## Contribution Guidelines

1. **Fork the Repository**:  
   Start by forking the repository and creating a new branch based on `develop` for your feature or bug fix.

2. **Write Tests**:  
   All code changes should include appropriate tests to ensure that the feature or fix works as expected. We use an automated testing suite, so please make sure your changes pass all existing and new tests.

3. **Code Style**:  
   Please follow the coding standards and conventions used throughout the project. Ensure your code is clean, readable, and well-documented.

4. **Commit Messages**:  
   Write clear and concise commit messages. Commit messages should follow this format:
   
   ```
   [Type] Short description of the change
   ```

   Common commit types:
   - `feat`: A new feature
   - `fix`: A bug fix
   - `docs`: Documentation changes
   - `test`: Adding or modifying tests
   - `refactor`: Code refactoring

5. **Pull Requests**:  
   Once your changes are ready, submit a PR to the `develop` branch. A project maintainer will review your changes. Please ensure the following before submitting a PR:
   - All tests pass.
   - Code is properly formatted and documented.
   - The PR description clearly explains the changes made.
