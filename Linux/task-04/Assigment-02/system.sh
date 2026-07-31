#!/bin/bash

showDate() {
    currentDate=$(date)
    echo "Current Date: $currentDate"
}
showUptime() {
    uptimeInfo=$(uptime)
    echo "Uptime: $uptimeInfo"
}
showUsers() {
    usersLogged=$(w)
    echo "Logged Users:"
    echo "$usersLogged"
}
showDirectory() {
    currentDir=$(pwd)
    echo "Current Directory: $currentDir"
}
showDiskUsage() {
    diskUsage=$(df -h)
    echo "$diskUsage"
}
showMemoryUsage() {
    memoryUsage=$(free -h)
    echo "$memoryUsage"
}
listFiles() {
    files=$(ls)
    echo "$files"
}

while true
do
    echo "Linux Toolkit"
    echo "====================="
    echo "1) Show Date"
    echo "2) Show Uptime"
    echo "3) Show Logged Users"
    echo "4) Show Current Directory"
    echo "5) Show Disk Usage"
    echo "6) Show Memory Usage"
    echo "7) List Files"
    echo "8) Exit"

    read -p "Enter your choice: " choice

    if [ "$choice" -eq 1 ]; then
        showDate
    elif [ "$choice" -eq 2 ]; then
        showUptime
    elif [ "$choice" -eq 3 ]; then
        showUsers
    elif [ "$choice" -eq 4 ]; then
        showDirectory
    elif [ "$choice" -eq 5 ]; then
        showDiskUsage
    elif [ "$choice" -eq 6 ]; then
        showMemoryUsage
    elif [ "$choice" -eq 7 ]; then
        listFiles
    elif [ "$choice" -eq 8 ]; then
        echo "Exiting..."
        break
    else
        echo "Invalid choice."
    fi

    echo
done