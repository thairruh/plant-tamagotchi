# Working together

1. Clone the repo (or download the ZIP for initial exploration).
2. Tell the team what you plan to work on in Discord.
3. Make a branch, e.g. `feature/moisture-sensor` or `feature/display-test`.
4. Test your sketch on hardware if possible.
5. Commit changes with a short description, push, and open a pull request to `main`.
6. Add a photo, Serial Monitor output, or explanation of what you tested. If blocked, say what happened.

Example commands (after cloning):
```bash
git switch -c feature/moisture-sensor
git add .
git commit -m "Test moisture readings"
git push -u origin feature/moisture-sensor
```

**Beginner option:** Use GitHub Desktop for branches, commits, and pull requests.

**Please don't edit `main` directly.** One person can review and merge PRs. If you cannot upload from your computer, you can still contribute code, art, documentation, and troubleshooting notes. Avoid simultaneous edits to the same `.ino` file.

Keep experiments separate until they're working. Only then move tested functions into the main firmware.
