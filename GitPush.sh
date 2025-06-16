#!/bin/bash

# Stop the script if any command fails
set -e

# Text formatting for standout messages
BOLD='\033[1m'
UNDERLINE='\033[4m'
CYAN='\033[36m'
YELLOW='\033[33m'
RED='\033[31m'
GREEN='\033[32m'
RESET='\033[0m'

# Move to the Learning Java directory
echo -e "${BOLD}${CYAN}Venturing into the Java dojo... 🏯${RESET}"
cd /home/surya/codes/

# Confirm Git repository status
if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo -e "${BOLD}${RED}Error: Not inside a valid Git repository! Retreat! 🚨${RESET}"
  exit 1
fi

# Show Git status before changes
echo -e "${BOLD}${YELLOW}Analyzing the previous commit battlefield... 🔍${RESET}"
git status --short

# Add untracked and tracked files
echo -e "${BOLD}${GREEN}Gathering the Java scrolls... 📜${RESE/////T}"
git add -A

# Check for changes to be committed
if git diff --cached --quiet; then
  echo -e "${BOLD}${CYAN}No new wisdom to impart upon the GitHub archives. 🛌${RESET}"
  exit 0
fi

# Commit the changes
commit_message="Practice: $(date +"%Y-%m-%d %H:%M:%S")"
echo -e "${BOLD}${CYAN}Chronicling your code with: '${commit_message}' 🔐${RESET}"
git commit -m "$commit_message"

# Push changes to the repository
echo -e "${BOLD}${GREEN}Unleashing your use less code to the world to laugh at 🚀...${RESET}"
git push origin main

echo -e "${BOLD}${YELLOW}Bravo! Your codes are now safely in the GitHub dojo 🏯✨${RESET}"
