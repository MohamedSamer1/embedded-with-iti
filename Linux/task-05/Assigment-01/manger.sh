#!/bin/bash

echo "Linux User and Group Management Script"
echo "Date: $(date)"
echo "Welcome!"
echo "========================================"

USER_NAME="student"
GROUP_NAME="ITI"

if id "$USER_NAME" &>/dev/null; then
    echo "Removing existing user: $USER_NAME"
    userdel -r "$USER_NAME" 2>/dev/null
fi

if getent group "$GROUP_NAME" > /dev/null; then
    echo "Removing existing group: $GROUP_NAME"
    groupdel "$GROUP_NAME"
fi

useradd -m "$USER_NAME"
if [ $? -eq 0 ]; then
    echo "User '$USER_NAME' created successfully."
else
    echo "Failed to create user."
fi

groupadd "$GROUP_NAME"
if [ $? -eq 0 ]; then
    echo "Group '$GROUP_NAME' created successfully."
else
    echo "Failed to create group."
fi

usermod -aG "$GROUP_NAME" "$USER_NAME"
echo
echo "User '$USER_NAME' added to group '$GROUP_NAME'."

echo
echo "Checking /etc/passwd for user..."
grep "^$USER_NAME:" /etc/passwd

echo
echo "Checking /etc/group for group..."
grep "^$GROUP_NAME:" /etc/group

echo
echo "Members of group '$GROUP_NAME':"
getent group "$GROUP_NAME"