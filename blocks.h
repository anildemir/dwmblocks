//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {" Mem: ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
    {"Load: ", "cat /proc/loadavg | awk -F ' ' -v OFS='   ' '{ print $1, $2, $3 }'a", 5, 0},
    {"Temp: ", "sensors | awk '/Core 0/ {print $3}'", 30, 0},
    {"Battery: ", "echo $(cat /sys/class/power_supply/BAT0/capacity)%", 30, 0},
    {"Disk: ", "printf \"%s %s\n\" \"$(df -h / | awk ' /[0-9]/ {print $3 \"/\" $2}')\"", 30, 0},

    {"", "date '+%b %d (%a) %R'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
